#include<stdio.h>

int main(){
	
	//file open 
	FILE *fp=fopen("sample.csv","r");
	const int MAX = 100;	//넉넉하게 잡음. 
	int count=0;
	int year[MAX], month[MAX], day[MAX],
		ticketType[MAX], ticketTime[MAX], ageGroup[MAX], benefit[MAX], ticketVolume[MAX], regularPriceSum[MAX], lastPriceSum[MAX],
		ageGoup[MAX][MAX]={0};	
		
	//출력관련변수들 초기화 
	int benefit1=0, benefit2=0, benefit3=0, benefit4=0, benefit5=0, benefit6=0,	//우대혜택 
		amusementTicketPrice=0, museumTicketPrice=0, alldayPrice=0, after4Price=0,
		dayPriceSum=0, ticketNumSum=0, amusementNumSum=0, museumNumSum=0, alldayNumSum=0, after4NumSum=0; 
			
	while( fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count], &ticketType[count], &ticketTime[count], &ageGroup[count], &benefit[count], &ticketVolume[count], &regularPriceSum[count], &lastPriceSum[count]) != -1)
	{
		count++;
	}
	fclose(fp);	
		 
	//file print : 위에서 fscanf로 입력받은 애들 프린트. 
	printf("\n==================================================report.csv====================================================\n\n");	
	printf("%s \t%s \t%11s \t%s \t%s \t%s %10s \t%s\n","발권시간","권종","이용시간","연령그룹","우대혜택","구매매수","정가","할인적용가");		
	printf("----------------------------------------------------------------------------------------------------------------\n");	

	for(int i = 0; i < count; i++)
	{
		printf("%d%d%d %9d %13d %12d %15d %14d %14d \t%10d\n",year[i], month[i], day[i], ticketType[i], ticketTime[i], ageGroup[i], benefit[i], ticketVolume[i], regularPriceSum[i], lastPriceSum[i]);
	}//년월일을 붙여서 받음 
	
	//권종, 나이그룹 구매분석 
	for(int i = 0;  i<count; i++)
	{
		switch(ticketType[i]){
			case 1: //종합+종일
				switch(ageGroup[i]){
					case 1 : //Adult
						ageGoup[0][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;
					case 2 : //Youth
						ageGoup[0][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;					
					case 3 : //Child
						ageGoup[0][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;					
					case 4 : //Baby
						ageGoup[0][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;					
					case 5 : //others
						ageGoup[0][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;
					default:
						break;										
				}
				amusementTicketPrice += lastPriceSum[i];	//switch문 반복으로 종합권 가격구함
				alldayPrice += lastPriceSum[i]; // 종일권 가격저장
				break;	//바깥 case1 종료
			case 2: //종합+after4
				switch(ageGroup[i]){
					case 1 : //Adult
						ageGoup[0][0] += ticketVolume[i];	//00은 같은정보
						ageGoup[3][0] += ticketVolume[i];				
						break;
					case 2 : //Youth
						ageGoup[0][1] += ticketVolume[i];
						ageGoup[3][1] += ticketVolume[i];				
						break;					
					case 3 : //Child
						ageGoup[0][2] += ticketVolume[i];
						ageGoup[3][2] += ticketVolume[i];				
						break;					
					case 4 : //Baby
						ageGoup[0][3] += ticketVolume[i];
						ageGoup[3][3] += ticketVolume[i];				
						break;					
					case 5 : //others
						ageGoup[0][4] += ticketVolume[i];
						ageGoup[3][4] += ticketVolume[i];				
						break;
					default:
						break;										
				}
				amusementTicketPrice += lastPriceSum[i];	
				after4Price += lastPriceSum[i]; // after4이용권 가격저장
				break;
			case 3: //뮤지엄+종일
				switch(ageGroup[i]){
					case 1 : //Adult
						ageGoup[1][0] += ticketVolume[i];
						ageGoup[2][0] += ticketVolume[i];				
						break;
					case 2 : //Youth
						ageGoup[1][1] += ticketVolume[i];
						ageGoup[2][1] += ticketVolume[i];				
						break;					
					case 3 : //Child
						ageGoup[1][2] += ticketVolume[i];
						ageGoup[2][2] += ticketVolume[i];				
						break;					
					case 4 : //Baby
						ageGoup[1][3] += ticketVolume[i];
						ageGoup[2][3] += ticketVolume[i];				
						break;					
					case 5 : //others
						ageGoup[1][4] += ticketVolume[i];
						ageGoup[2][4] += ticketVolume[i];				
						break;
					default:
						break;										
				}
				museumTicketPrice += lastPriceSum[i];
				alldayPrice += lastPriceSum[i]; 
				break;
			case 4: //뮤지엄+after4
				switch(ageGroup[i]){
					case 1 : //Adult
						ageGoup[1][0] += ticketVolume[i];
						ageGoup[3][0] += ticketVolume[i];				
						break;
					case 2 : //Youth
						ageGoup[1][1] += ticketVolume[i];
						ageGoup[3][1] += ticketVolume[i];				
						break;					
					case 3 : //Child
						ageGoup[1][2] += ticketVolume[i];
						ageGoup[3][2] += ticketVolume[i];				
						break;					
					case 4 : //Baby
						ageGoup[1][3] += ticketVolume[i];
						ageGoup[3][3] += ticketVolume[i];				
						break;					
					case 5 : //others
						ageGoup[1][4] += ticketVolume[i];
						ageGoup[3][4] += ticketVolume[i];				
						break;
					default:
						break;										
				}
				museumTicketPrice += lastPriceSum[i];
				after4Price += lastPriceSum[i];
				break;
			default:
				break;									
		}	//switch(ticketType[i]) close
	
		
	//티켓 총판매량, 우대혜택별 티켓판매량 계산
	//혜택 따라 티켓 구분
	 switch(benefit[i]){
	 	case 1:
	 		benefit1 += ticketVolume[i];
	 		break;
	 	case 2:
	 		benefit2 += ticketVolume[i];
	 		break;	 		
	 	case 3:
	 		benefit3 += ticketVolume[i];
	 		break;	 		
	 	case 4:
	 		benefit4 += ticketVolume[i];
	 		break;	 		
	 	case 5:
	 		benefit5 += ticketVolume[i];
	 		break;	 		
	 	case 6:
	 		benefit6 += ticketVolume[i];	//우대:해당없음 
	 		break;	
		default:	//우대는 6까지만 있음 
			break;			 		 			 				 		 		
	 }		
	} 	//라인 36 for문 close 

	//권종별 총 티켓	
	amusementNumSum = ageGoup[0][3]+ageGoup[0][2]+ageGoup[0][1]+ageGoup[0][0]+ageGoup[0][4];
	museumNumSum = ageGoup[1][3]+ageGoup[1][2]+ageGoup[1][1]+ageGoup[1][0]+ageGoup[1][4];
	alldayNumSum = ageGoup[2][3]+ageGoup[2][2]+ageGoup[2][1]+ageGoup[2][0]+ageGoup[2][4];
	after4NumSum = ageGoup[3][3]+ageGoup[3][2]+ageGoup[3][1]+ageGoup[3][0]+ageGoup[3][4];	
	
	//총티켓수= 우대혜택 받는 티켓 총합(우대혜택에 해당없음도있음) 
	ticketNumSum = benefit1+benefit2+benefit3+benefit4+benefit5+benefit6;
	
	//파일로 출력
	FILE *fp1, *fp2;	//일자별 매출 추가할 것 
	fp = fopen("ticketReport.csv","a"); 
	fp2 = fopen("benefitReport.csv","a");
	
	//출력부	
	printf("\n=================================================권종별 매출=================================================\n\n");
	printf("종합이용권 총 %d 매\n", amusementNumSum);
	printf("Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageGoup[0][0], ageGoup[0][1], ageGoup[0][2], ageGoup[0][3], ageGoup[0][4]);	 
	printf("종합이용권 판매총액: %d 원\n\n", amusementTicketPrice);	
	
	printf("뮤지엄이용권 총 %d 매\n", museumNumSum);
	printf("Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageGoup[1][0], ageGoup[1][1], ageGoup[1][2], ageGoup[1][3], ageGoup[1][4]);	 
	printf("뮤지엄이용권 판매총액: %d 원\n\n", museumTicketPrice);		
	
	printf("종일권 총 %d 매\n", alldayNumSum);
	printf("Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageGoup[0][0], ageGoup[0][1], ageGoup[0][2], ageGoup[0][3], ageGoup[0][4]);	 
	printf("종합이용권 판매총액: %d 원\n\n", alldayPrice);	
	
	printf("After4이용권 총 %d 매\n", after4NumSum);
	printf("Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageGoup[1][0], ageGoup[1][1], ageGoup[1][2], ageGoup[1][3], ageGoup[1][4]);	 
	printf("뮤지엄이용권 판매총액: %d 원\n\n", after4Price);		
	printf("\n============================================================================================================\n\n");	
	
	//총 티켓판매량 중 우대혜택별 티켓수
	printf("\n================================================우대별 판매량================================================\n\n");	 
	printf("총 티켓 판매 수		: %d 매\n", ticketNumSum);
	printf("장 애 인 우 대		: %d 매\n", benefit1);	
	printf("국 가 유 공 자		: %d 매\n", benefit2);
	printf("휴 가 장 병 		: %d 매\n", benefit3);	
	printf("임 산 부 우 대		: %d 매\n", benefit4);	
	printf("다 둥 이 우 대		: %d 매\n", benefit5);	
	printf("해 당 없 음 		: %d 매\n", benefit6);		
	printf("\n===========================================================================================================\n\n");	 	

	fclose(fp);
	return 0;
}	
