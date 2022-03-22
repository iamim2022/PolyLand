#include <stdio.h>
#include <time.h>
 
//POLYLAND이용권 계산기 ver4.5
//입력부, 계산부, 출력부 분리 
//benefitMax, benefitMin, idMinNum, idMaxNum, genderMin, genderMax 추가
//우대혜택 오류시 재입력 
//주민번호 오류시 재입력
//코드정렬 조정 
 
int index = 0;
int main(){
	//<변수, 배열  선언> 
	//time.h 헤더에서 tm함수 사용위한 세팅 
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	//이용권 권종 선언(구성별, 시간별) 
	int ticket_type;
	int ticket_time;
	 		
		//권종별 가격 : 종합이용권 1day, After4 (폴리랜드+폴리박물관) 
		const int ADULT_1DAY_PRICE = 59000, ADULT_A4_PRICE = 48000, 
				YOUTH_1DAY_PRICE = 52000, YOUTH_A4_PRICE = 42000,
				CHILD_1DAY_PRICE = 47000, CHILD_A4_PRICE = 36000,
				BABY_1DAY_PRICE = 15000, BABY_A4_PRICE = 15000;
				
		
		//권종별 가격 : 뮤지엄이용권 1day, After4 (폴리랜드) 
		const int ADULT_1DAY_MPRICE = 56000, ADULT_A4_MPRICE = 45000, 
				YOUTH_1DAY_MPRICE = 50000, YOUTH_A4_MPRICE = 40000,
				CHILD_1DAY_MPRICE = 46000, CHILD_A4_MPRICE = 35000,
				BABY_1DAY_MPRICE = 15000, BABY_A4_MPRICE = 15000;	 	
	
	//주민등록번호 분석
	int id;	//주민번호 앞 6자리 
	int birthYear, birthMonth, birthDay; //출생년월일 	birthYear는 출생년도 끝2자리 
	int year;		//현재년도 	
	int man;	//만나이
	int age;	//세는 나이 
	int gap;	//현재년도 - 출생년도	
	int gender;	//주민번호 7번째 자리 : 1,2 또는 3,4 
	int idMinNum = 000101;  //90708
	int idMaxNum = 991231;
	int genderMin = 1;
	int genderMax = 4;  

	//주민등록번호로 현재나이 계산을 위한 변수들 
	int century;	// 1900, 2000년대 
	int birthYearFull; //출생년도 4자리
	 
	int exit; 	//발권종료

	//요금 계산을 위한 변수
	int regular_price;

	//우대혜택 관련변수 
	int benefit;
	int discounted; //할인적용된 티켓 가격 _ 정수다. 
	int last_price; // 할인가 * 매수 
	int benefitMax = 6;
	int benefitMin = 1;

	 
	//<입력부>		 
	//폴리랜드 초기출력 
	printf("********************* Welcome! **********************\n\n");	
	printf("%39s\n\n","Many computers, Many people");
	printf("%36s","~~~ POLY LAND ~~~\n\n");
	printf("=====================================================\n\n");
	printf("%34s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		
	do
	{
		do{
			//이용권 종류 선택 
			printf("<이용권 종류를 선택하세요.>\n"); 
			printf("1. 종합이용권 (폴리랜드+ 폴리박물관)\n"); 
			printf("2. 뮤지엄이용권 (폴리박물관)\n\n"); 	
			printf("종류 입력: ");
			scanf("%d", &ticket_type); 
		
			//이용권 종류 선택 결과
			if(ticket_type == 1)
			{
				printf("\n");
				printf("%s","종합이용권을 선택하셨습니다.");
				printf("\n-----------------------------------------------------\n\n");											
			}
			else if(ticket_type == 2)
			{
				printf("\n");
				printf("%s","뮤지엄이용권을 선택하셨습니다.");
				printf("\n-----------------------------------------------------\n\n");								
			}
			else
			 {
			 	printf("\n-----------------------------------------------------\n");	
				printf("<<<!!이용권 종류를 다시 선택하세요!!>>>");
				printf("\n-----------------------------------------------------\n\n");				
				continue;	//다음 코드를 건너뛰고 다시 처음으로간다. 
			}			
		}while( !(ticket_type == 1 || ticket_type == 2));

		do{	
			//이용 시간 선택 
			printf("<이용권 시간을 선택하세요.>\n"); 
			printf("1. 종일권\n"); 
			printf("2. 오후 4시 이후 이용권\n\n"); 	
			printf("종류 입력: ");
			scanf("%d", &ticket_time); 	
			
			//이용권 시간 선택 결과
			if(ticket_time == 1)
			{
				printf("\n");
				printf("%s\n","종일권을 선택하셨습니다.");	
				printf("\n-----------------------------------------------------\n\n");						
					
			}
			else if(ticket_time == 2)
			{
				printf("\n");
				printf("%s","오후 4시 이후 이용권을 선택하셨습니다.");
				printf("\n-----------------------------------------------------\n\n");											
			}
			else
			{
				printf("\n-----------------------------------------------------\n");					
				printf("<<<!!이용권 시간을 다시 선택하세요!!>>>");
				printf("\n-----------------------------------------------------\n\n");					
				continue;
			}			
		}while( !(ticket_time == 1 || ticket_time == 2));

		//티켓 매수 확인 (티켓은 10매까지만 구매가능)
		int ticket_volume;
		do
		{		 						
			printf("<구매하려는 매수를 입력하세요.>\n"); 
			printf("티켓은 최대 10매까지 구매할 수 있습니다.\n");	
			printf("\n입력예시 : 2\n\n"); 
			printf("매수 입력: ");
			scanf("%d", &ticket_volume);
									
			if(ticket_volume <= 10)
			{
				printf("%d매를 입력했습니다.", ticket_volume);
				printf("\n-----------------------------------------------------\n\n");				
			}
			else
			{
			 	printf("\n-----------------------------------------------------\n");	
				printf("<<<!!티켓은 최대 10장까지만 구매가능합니다!!>>>");
				printf("\n-----------------------------------------------------\n\n");	
				continue;
			}
		} while(ticket_volume > 10); 

					
		//주민등록번호 입력부 
		do
		{
			printf("<주민등록번호를 입력하세요.>\n"); 	
			printf("\n입력예시 : 980315-2\n\n"); 
			printf("주민번호 앞자리 입력: ");
			scanf("%6d-%1d", &id, &gender);
			
			if((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))
			{
				//printf("입력하신 주민번호는 %06d-%d입니다.", id, gender);
				//printf("\n-----------------------------------------------------\n\n");				
			}
			else
			{
			 	printf("\n-----------------------------------------------------\n");	
				printf("<<<!!주민번호를 확인하세요!!>>>");
				printf("\n-----------------------------------------------------\n\n");	
				continue;
			}			
			
		} while(!((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))); 
					

		//우대혜택 입력부 
		do
		{		
			printf("\n\n");			
			printf("=====================================================\n\n");
			printf("<우대사항을 선택하세요.>\n"); 
			printf("*나이에 따른 우대는 자동적용됩니다.\n"); 
			printf("*종합이용권/뮤지엄이용권 우대대상 \n");
			printf("\t=> 장애인, 국가유공자, 휴가장병\n");
			printf("*종합이용권 우대대상 \n");
			printf("\t=> 임산부, 다둥이 행복카드 소유자\n");
			printf("\n---------------------------------------------------\n");
			printf("<우대 유형>");
			printf("\n1.장애인 우대\n2.국가유공자 우대\n3.휴가장병우대\n4.임산부우대\n5.다둥이행복카드 우대\n6.해당없음");	
			printf("\n\n입력예시 : 3\n\n"); 
			printf("우대 사항 번호: ");
			scanf("%d", &benefit);
			
			if(benefit > benefitMax || benefit < benefitMin)
			{
			 	printf("\n-----------------------------------------------------\n");	
				printf("<<<!!우대혜택을 확인하세요!!>>>");
				printf("\n-----------------------------------------------------");	
				continue;		
			}
		
		} while(benefit > benefitMax || benefit < benefitMin); 	




		//<계산부> 
		//주민번호를 년, 월, 일로 끊기
		birthYear = id / 10000;		// 자료형이 int라서 예)950525 => 95.525 => 95 
		birthMonth = (id % 10000) / 100;	// 예)950525 => 525 /100 => 5.25 => 5 
		birthDay = id % 100;		//예)950525 => 9505.25 => 25 
	
		//성별로 나이 1900년대, 2000년대 유추하기 [4자리 생년] 
		switch(gender){
			case 1: case 2:
				century = 1900;
				birthYearFull = 1900+birthYear;
				break;
			
			case 3: case 4:
				century = 2000;
				birthYearFull = 2000+birthYear;
				break;	
		}		
		
		//현재년도 - 출생년도	 
		gap = (tm.tm_year+1900) - birthYearFull;
	
		//만 나이: birthMonth >= month 면 생월이 지났음.
		if(birthMonth >= (tm.tm_mon+1) && birthDay >= (tm.tm_mday))
		{
			man = gap;
		} 
		else
		{
			man = gap -1;
		}
		
		//세는 나이, 우리가 아는 나이 
		age = gap + 1 ;	
	
		//성별
		char gender_print;
		
		if(gender == 1 && 3){			
			gender_print = 'M';
		} 
		if(gender == 2 && 4){
			gender_print = 'W';
		} 			 	
		
		
		//요금 계산										
		//성인요금 : 만 19세이상 ~ 만64세이하
		if(man >= 19 && man <= 64)
		{ 
			if(ticket_type == 1 && ticket_time == 1)
			{
				regular_price = ADULT_1DAY_PRICE;
			}
			
			if(ticket_type == 1 && ticket_time == 2)
			{
				regular_price = ADULT_A4_PRICE;
			}
			
			if(ticket_type == 2 && ticket_time == 1)
			{
				regular_price = ADULT_1DAY_MPRICE;
			}
		
			if(ticket_type == 2 && ticket_time == 2)
			{
				regular_price = ADULT_A4_MPRICE;
			}	
		}	
		//청소년요금 : 만 13세 이상 ~ 만 18세 이하
		else if(man >= 13 && man <= 18)
		{ 
			if(ticket_type == 1 && ticket_time == 1)
			{
				regular_price = YOUTH_1DAY_PRICE;
			}
			
			if(ticket_type == 1 && ticket_time == 2)
			{
				regular_price = YOUTH_A4_PRICE;
			}
			
			if(ticket_type == 2 && ticket_time == 1)
			{
				regular_price = YOUTH_1DAY_MPRICE;
			}
		
			if(ticket_type == 2 && ticket_time == 2)
			{
				regular_price = YOUTH_A4_MPRICE;
			}	
		}		
		 //어린이요금 : 만 3세 이상 ~ 만 12세 이하
		else if(man >= 3 && man <= 12)
		{ 		 
			if(ticket_type == 1 && ticket_time == 1)
			{
				regular_price = CHILD_1DAY_PRICE;
			}
			
			if(ticket_type == 1 && ticket_time == 2)
			{
				regular_price = CHILD_A4_PRICE;
			}
			
			if(ticket_type == 2 && ticket_time == 1)
			{
				regular_price = CHILD_1DAY_MPRICE;
			}
		
			if(ticket_type == 2 && ticket_time == 2)
			{
				regular_price = CHILD_A4_MPRICE;
			}	 		 
		}
		 //아기 요금 : 만 1세 이상 ~ 만2세 이하	 
		else if(man >= 1 && man <= 2)
		{ 		 
			if(ticket_type == 1 && ticket_time == 1)
			{
				regular_price = BABY_1DAY_PRICE;
			}
			
			if(ticket_type == 1 && ticket_time == 2)
			{
				regular_price = BABY_A4_PRICE;
			}
			
			if(ticket_type == 2 && ticket_time == 1)
			{
				regular_price = BABY_1DAY_MPRICE;
			}
		
			if(ticket_type == 2 && ticket_time == 2)
			{
				regular_price = BABY_A4_MPRICE;
			}			 	 	 		 
		}
	
		//기타: 만 1세 미만, 만65세 이상은 무료 
		else if(man < 1 || man >= 65) 
		{
			regular_price = 0;
		}	  	

			
		//티켓 가격 계산부				 	
		//티켓 최종가격 : 우대가, 매수 적용 
		//장애인, 국가유공자, 휴가장병은 동반 1인 까지 우대	
		for(int i = 1; i <= ticket_volume; i++)
		{
			//장애인, 국가유공자 [종합, 뮤지엄] 티켓 우대 50%적용한 티켓 최종가
			if(benefit == 1 || benefit == 2)
			{
				//discounted = regular_price * 0.5;
				switch(ticket_volume)	
				{
					case 1:
						last_price = regular_price * 0.5;
						break;					
					case 2:
						last_price = (regular_price * 0.5)*2;
						break;																	
					case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
						last_price = (regular_price * 0.5)*2 + (regular_price * (i - 2));						
						break;										
				}
			}			
			//휴가장병 종합이용권만 동반 1인 포함 우대 49% 적용한 티켓 최종가
			//티켓 가격은 1000원 단위 
			if(benefit == 3 && ticket_type == 1)
			{
				//discounted = regular_price * 0.51;
				switch(ticket_volume)	
				{
					case 1:
						last_price = ((regular_price * 51) / 10000) *100;	//1000원미만 절삭 
						break;					
					case 2:
						last_price = (((regular_price * 51) / 10000) *100) * 2;
						break;																	
					case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
						last_price = (((regular_price * 51) / 10000) *100) * 2 + (regular_price * (i - 2));						
						break;										
				}
			}		
			//임산부 종합이용권만 본인 우대 50% 적용한 티켓 최종가
			if(benefit == 4 && gender_print == 'W' && ticket_type == 1)
			{
				//discounted = regular_price * 0.51;
				switch(ticket_volume)	
				{
					case 1:
						last_price = regular_price * 0.5;
						break;																						
					case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
						last_price = (regular_price * 0.5) + (regular_price * (i - 1));						
						break;										
				}
			}					
			//다둥이카드 등록된 본인만 종합이용권만 우대 30% 적용한 티켓 최종가 
			if(benefit == 5 && ticket_type == 1)
			{
				//discounted = regular_price * 0.51;
				switch(ticket_volume)	
				{
					case 1:
						last_price = regular_price * 0.7;
						break;																						
					case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
						last_price = (regular_price * 0.7) + (regular_price * (i - 1));						
						break;										
				}
			}		
					
			 //우대 미적용할 경우 티켓 최종가		
			if(benefit == 6 || benefit == 3 && ticket_type == 2 || benefit == 4 && ticket_type == 2 || benefit == 5 && ticket_type == 2)
			{
				last_price = regular_price * i;
			}
		 }


	//<출력부>	
	//단일 티켓수, 가격 출력	
		printf("\n\n");			
		printf("=====================================================\n\n");
		printf("%s\n\n","<최종내역>");
		printf("최종 결제 가격은 %d원 입니다.\n\n", last_price);
		do
		{
			printf("\n추가 발권하시겠습니까?\n\n1.추가발권\n2.발권종료\n\n");
			printf("선택 입력 : ");
			scanf("%1d",&exit);
			if(exit>2 || exit<1)
			{
			 	printf("\n-----------------------------------------------------\n");	
				printf("<<<!!입력번호를 확인하세요!!>>>");
				printf("\n-----------------------------------------------------");	
				continue;		
			}
		} while(exit>2 || exit<1);
		
		printf("=====================================================\n\n");
			
	} while (exit==1);
	
	//마무리 
	printf("\n\n=====================================================\n\n");	
	printf("********************* Thank you **********************\n\n");	
	printf("%34s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);	
				
	return 0;
} 
