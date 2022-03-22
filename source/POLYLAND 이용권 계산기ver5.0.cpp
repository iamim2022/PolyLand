#include <stdio.h>
#include <time.h>
//POLYLAND 이용권 계산기 ver5.0

int main(){
	//<변수, 배열  선언> 
	//time.h 헤더에서 tm함수 사용위한 세팅 
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int totalPrice = 0;		//누적주문 총액
	int totalVolume = 0; 	//누적 주문매수 
	
	//티켓 변수(권종, 시간별, 매수) 
	int ticketType, ticketTime, ticketVolume;
		
	//권종별 가격 : 종합이용권 1day, After4
	const int ADULT_1DAY_PRICE = 59000, ADULT_A4_PRICE = 48000, YOUTH_1DAY_PRICE = 52000, YOUTH_A4_PRICE = 42000,
			CHILD_1DAY_PRICE = 47000, CHILD_A4_PRICE = 36000, BABY_1DAY_PRICE = 15000, BABY_A4_PRICE = 15000;
				
	//권종별 가격 : 뮤지엄이용권 1day, After4
	const int ADULT_1DAY_MPRICE = 56000, ADULT_A4_MPRICE = 45000, YOUTH_1DAY_MPRICE = 50000, YOUTH_A4_MPRICE = 40000,
			CHILD_1DAY_MPRICE = 46000, CHILD_A4_MPRICE = 35000, BABY_1DAY_MPRICE = 15000, BABY_A4_MPRICE = 15000;	 	
	
	//주민등록번호 분석
	int id, birthYear, birthMonth, birthDay, year, man, age, gap, gender;
	int idMinNum = 000101;  //90708
	int idMaxNum = 991231;
	int genderMin = 1;
	int genderMax = 4;  

	//주민등록번호 관련 변수(현재나이 계산) 
	int century, birthYearFull;

	//우대혜택 관련변수 
	int benefit;
	int discounted; //할인적용된 티켓 1장 가격 
	int lastPrice; // 할인가 * 매수 
	int benefitMax = 6;
	int benefitMin = 1;
	
	//기타변수	 
	int exitAnswer, ageGroup, regularPrice;
	char gender_print;
	
	//계산변수 초기화 
	ticketType =0, ticketTime=0, ticketVolume=0, id=0, gender=0;

	//배열탐색용 
	int row = 0;	//배열_행 이동 변수 
	int orderList[100][7] = {0};	// 배열: 구매내역 
	 
	//<입력부>		
	//폴리랜드 초기출력
	printf("==================================================================================================\n");
	printf("\n******************************************** Welcome *********************************************\n\n");	
	printf("%62s\n\n","Many computers, Many people");
	printf("%58s","~~~ POLY LAND ~~~\n\n");
	printf("==================================================================================================\n\n");
	printf("%78s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
		do{
			do{
				//이용권 종류 선택 
				printf("<이용권 종류를 선택하세요.>\n"); 
				printf("1. 종합이용권 (폴리랜드+ 폴리박물관)\n"); 
				printf("2. 뮤지엄이용권 (폴리박물관)\n\n"); 	
				printf("종류 입력: ");
				scanf("%d", &ticketType); 
				printf("\n--------------------------------------------------------------------------------------------------\n");
				if(!(ticketType == 1 || ticketType == 2)){
					printf("<<<!!이용권 종류를 다시 선택하세요!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n");								
					continue;										
				}			
			}while( !(ticketType == 1 || ticketType == 2));
	
			do{	
				//이용 시간 선택 
				printf("<이용권 시간을 선택하세요.>\n"); 
				printf("1. 종일권\n"); 
				printf("2. After4\n\n"); 	
				printf("종류 입력: ");
				scanf("%d", &ticketTime); 	
				printf("\n--------------------------------------------------------------------------------------------------\n");
				//이용권 시간 선택 결과
				if(!(ticketTime == 1 || ticketTime == 2)){					
					printf("<<<!!이용권 시간을 다시 선택하세요!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");					
					continue;											
				}		
			}while( !(ticketTime == 1 || ticketTime == 2));
	
			//티켓 매수 확인 (티켓은 10매까지만 구매가능)
			do{		 						
				printf("<구매하려는 매수를 입력하세요.>\n"); 
				printf("티켓은 최대 10매까지 구매할 수 있습니다.\n");	
				printf("\n입력예시 : 2\n\n"); 
				printf("매수 입력: ");
				scanf("%d", &ticketVolume);
				printf("\n--------------------------------------------------------------------------------------------------\n");						
				if(ticketVolume > 10){
					printf("<<<!!티켓은 최대 10장까지만 구매가능합니다!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");	
					continue;				
				}
			} while(ticketVolume > 10); 
							
			//주민등록번호 입력부 
			do{
				printf("<주민등록번호를 입력하세요.>\n"); 	
				printf("\n입력예시 : 980315-2\n\n"); 
				printf("주민번호 앞자리 입력: ");
				scanf("%6d-%1d", &id, &gender);
				printf("\n--------------------------------------------------------------------------------------------------\n");								
				if(!((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))){	
					printf("<<<!!주민번호를 확인하세요!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");	
					continue;				
				}				
			} while(!((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))); 
						
			//우대혜택 입력부 
			do{		
				printf("\n");			
				printf("==================================================================================================\n\n");
				printf("<우대사항을 선택하세요.>\n"); 
				printf("◎ 나이에 따른 우대는 자동적용됩니다.\n"); 
				printf("◎ 종합이용권/뮤지엄이용권 우대대상 : 장애인, 국가유공자, 휴가장병 \n");
				printf("◎ 종합이용권 우대대상 : 임산부, 다둥이 행복카드 소유자 \n");
				printf("--------------------------------------------------------------------------------------------------\n");
				printf("<우대 유형>");
				printf("\n1.장애인 우대\n2.국가유공자 우대\n3.휴가장병우대\n4.임산부우대\n5.다둥이행복카드 우대\n6.해당없음");	
				printf("\n\n입력예시 : 3\n\n"); 
				printf("우대 사항 번호: ");
				scanf("%d", &benefit);
				//printf("\n--------------------------------------------------------------------------------------------------\n");				
				if(benefit > benefitMax || benefit < benefitMin){
					printf("<<<!!우대혜택을 확인하세요!!>>>");
					printf("\n----------------------------------------------------------------------------------------------------");	
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
			if(birthMonth >= (tm.tm_mon+1) && birthDay >= (tm.tm_mday)){
				man = gap;
			} 
			else{
				man = gap -1;
			}
			
			//세는 나이, 우리가 아는 나이 
			age = gap + 1 ;	
		
			//성별
			if(gender == 1 && 3){			
				gender_print = 'M';
			} 
			if(gender == 2 && 4){
				gender_print = 'W';
			} 			 	
			
			//나이그룹
			if(man >= 19 && man <= 64){
				ageGroup = 1; //adult
			}
			if(man >= 13 && man <= 18){
				ageGroup = 2;	//youth		
			}
			if(man >= 3 && man <= 12){
				ageGroup = 3;	//child				
			}
			if(man >= 1 && man <= 2){
				ageGroup = 4;	//baby				
			}	
			if(man < 1 || man >= 65){
				ageGroup = 5;	//others				
			}
					
			//요금 계산										
			//성인요금 : 만 19세이상 ~ 만64세이하
			if(ageGroup == 1){ 
				if(ticketType == 1 && ticketTime == 1){
					regularPrice = ADULT_1DAY_PRICE;
				}
				
				if(ticketType == 1 && ticketTime == 2){
					regularPrice = ADULT_A4_PRICE;
				}
				if(ticketType == 2 && ticketTime == 1){
					regularPrice = ADULT_1DAY_MPRICE;
				}
				if(ticketType == 2 && ticketTime == 2){
					regularPrice = ADULT_A4_MPRICE;
				}	
			}	
			//청소년요금 : 만 13세 이상 ~ 만 18세 이하
			else if(ageGroup == 2){ 
				if(ticketType == 1 && ticketTime == 1){
					regularPrice = YOUTH_1DAY_PRICE;
				}
				if(ticketType == 1 && ticketTime == 2){
					regularPrice = YOUTH_A4_PRICE;
				}
				if(ticketType == 2 && ticketTime == 1){
					regularPrice = YOUTH_1DAY_MPRICE;
				}
				if(ticketType == 2 && ticketTime == 2){
					regularPrice = YOUTH_A4_MPRICE;
				}	
			}		
			 //어린이요금 : 만 3세 이상 ~ 만 12세 이하
			else if(ageGroup == 3){ 		 
				if(ticketType == 1 && ticketTime == 1){
					regularPrice = CHILD_1DAY_PRICE;
				}	
				if(ticketType == 1 && ticketTime == 2){
					regularPrice = CHILD_A4_PRICE;
				}				
				if(ticketType == 2 && ticketTime == 1){
					regularPrice = CHILD_1DAY_MPRICE;
				}
				if(ticketType == 2 && ticketTime == 2){
					regularPrice = CHILD_A4_MPRICE;
				}	 		 
			}
			 //아기 요금 : 만 1세 이상 ~ 만2세 이하	 
			else if(ageGroup == 4){ 		 
				if(ticketType == 1 && ticketTime == 1){
					regularPrice = BABY_1DAY_PRICE;
				}
				if(ticketType == 1 && ticketTime == 2){
					regularPrice = BABY_A4_PRICE;
				}
				if(ticketType == 2 && ticketTime == 1){
					regularPrice = BABY_1DAY_MPRICE;
				}
				if(ticketType == 2 && ticketTime == 2){
					regularPrice = BABY_A4_MPRICE;
				}			 	 	 		 
			}
			//기타: 만 1세 미만, 만65세 이상은 무료 
			else if(ageGroup == 5) {
				lastPrice = 0;
			}	  	
		
			//티켓 가격 계산부				 	
			//티켓 최종가격 : 우대가, 매수 적용 
			//장애인, 국가유공자, 휴가장병: 동반 1인 까지 우대	
			for(int i = 1; i <= ticketVolume; i++){
				//장애인, 국가유공자 :[종합, 뮤지엄] 티켓 우대 50%적용한 티켓 최종가
				if(benefit == 1 || benefit == 2){
					switch(ticketVolume)	{
						case 1:
							lastPrice = regularPrice * 0.5;
							break;					
						case 2:
							lastPrice = (regularPrice * 0.5)*2;
							break;																	
						case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.5)*2 + (regularPrice * (i - 2));						
							break;										
					}
				}			
				//휴가장병 :종합이용권, 동반 1인 까지 우대 49% 적용한 티켓 최종가
				//티켓 가격은 1000원 단위 
				if(benefit == 3 && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = ((regularPrice * 51) / 10000) *100;	//1000원미만 절삭 
							break;					
						case 2:
							lastPrice = (((regularPrice * 51) / 10000) *100) * 2;
							break;																	
						case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (((regularPrice * 51) / 10000) *100) * 2 + (regularPrice * (i - 2));						
							break;										
					}
				}		
				//임산부: 종합이용권, 본인 우대 50% 적용한 티켓 최종가
				if(benefit == 4 && gender_print == 'W' && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = regularPrice * 0.5;
							break;																						
						case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.5) + (regularPrice * (i - 1));						
							break;										
					}
				}					
				//다둥이카드 :종합이용권, 본인 우대 30% 적용한 티켓 최종가 
				if(benefit == 5 && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = regularPrice * 0.7;
							break;																						
						case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.7) + (regularPrice * (i - 1));						
							break;										
					}
				}				
				 //우대 미적용할 경우 티켓 최종가		
				if(benefit == 6 || benefit == 3 && ticketType == 2 || benefit == 4 && ticketType == 2 || benefit == 5 && ticketType == 2){
					lastPrice = regularPrice * i;
				}
			 }
	
	//<출력부>	
	//단일 티켓수, 가격 출력	
	printf("\n\n");			
	printf("==================================================================================================\n\n");
	printf("%s\n\n","<주문내역>");
	if(lastPrice == 0){
		printf("\n무료 입장입니다.\n");
	}
	else
	{
	printf("선택하신 매수는 %d 매, 결제 가격은 %d원 입니다.\n\n", ticketVolume, lastPrice);
	}	
	
	//배열에 위 구매내역 정보 저장
	orderList[row][0] = ticketType;
	orderList[row][1] = ticketTime;
	orderList[row][2] = ageGroup;
	orderList[row][3] = benefit;
	orderList[row][4] = ticketVolume;
	orderList[row][5] = regularPrice;
	orderList[row][6] = lastPrice;	
	row++;	//초기값0

	totalPrice += lastPrice;	//누적주문내역 총액	
	totalVolume += ticketVolume;	//누적 티켓매수 총합	
		
		do{
			printf("\n추가 발권하시겠습니까?\n\n1.추가발권\n2.발권종료\n\n");
			printf("선택 입력 : ");
			scanf("%1d",&exitAnswer);
			if(exitAnswer>2 || exitAnswer<1)
			{
				printf("<<<!!입력번호를 확인하세요!!>>>");
				continue;
			}
		} while(exitAnswer>2 || exitAnswer<1);
		
		printf("==================================================================================================\n\n");//
			
	} while (exitAnswer==1);	//추가구매 반복 _구매프로세스 종료됨. 
		
	//<마지막 출력부>계산서 출력 
	printf("==========================================<최종구매내역>==========================================\n");	 
	printf("%7s %14s %10s %15s %13s %16s %16s\n","Type","Time","Age","benefit","Volume","Regular Price","Discount Price");
	printf("--------------------------------------------------------------------------------------------------");
	for (int j=0; j < row; j++)	//행 1씩 증가_인덱스0부터라서 배열 row보다 1작게 돌아야한다. 
	{	
		switch(orderList[j][0])	//ticketType
		{
			case 1:
				printf("\n종 합 이용권");
				break;
			case 2:
				printf("\n뮤지엄이용권");	 
				break;					
		}
		switch(orderList[j][1])	// ticketTime
		{
			case 1:
				printf("%11s","종일권");
				break;
			case 2:
				printf("%11s","After4");	 
				break;					
		}
		switch(orderList[j][2])	//ageGroup
		{
			case 1:
				printf("%11s","Adult");
				break;
			case 2:
				printf("%11s","Youth");
				break;				
			case 3:
				printf("%11s","Child");
				break;				
			case 4:
				printf("%11s","Baby");
				break;				
			case 5:
				printf("%11s","Others");
				break;																	
		 }
		switch(orderList[j][3])	//benefit
		{
			case 1:
				printf("%19s","장 애 인 우 대");
				break;
			case 2:
				printf("%19s","국 가 유 공 자");
				break;				
			case 3:
				printf("%19s","휴  가  장  병");
				break;				
			case 4:
				printf("%19s","임 산 부 우 대");
				break;				
			case 5:
				printf("%19s","다 둥 이 우 대");
				break;
			case 6:
				printf("%19s","해  당  없  음");
				break;																					
		 } 
		printf("%6d 매",orderList[j][4]);	//ticketVolume
		printf("%12d 원",orderList[j][5]);	//regularPrice		
		printf("%14d 원",orderList[j][6]);	//lastPrice
	 }  //for (int j=0; j < row; j++) close		
	printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("총 매수: %d 매\n", totalVolume);		
	printf("주문 총액: %d 원\n", totalPrice);
	
	//마무리 
	printf("\n==================================================================================================\n");	
	printf("******************************************** Thank you *******************************************\n\n");
	printf("\n==================================================================================================\n");	
	printf("%78s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);	
				
	return 0;
} 
