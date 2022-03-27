#include<stdio.h>
//POLYLAND_REPORTver2.0

//변수선언// 
const int MAX = 100;
int row = 0, n = 0; 
int year[MAX], month[MAX], day[MAX], ticketType[MAX], ticketTime[MAX], ageGroup[MAX], benefit[MAX], ticketVolume[MAX],
	regularPriceSum[MAX], lastPriceSum[MAX], ageTicketList[MAX][MAX]={0}, benefitList[MAX]={0}, dailyData[MAX][4];

//계산변수 초기화
int typeAllSum = 0, typeMuseumSum = 0, typeAllPrice = 0, typeMuseumPrice = 0,
	typeAllAllSum = 0, typeAllAf4Sum = 0, typeMuseumAllSum = 0, typeMuseumAf4Sum = 0,
	timeAllSum = 0, timeA4Sum = 0, timeAllPriceSum = 0, timeA4PriceSum = 0; 

//함수구간// 
void fileScan(){
	FILE *fp = fopen("report.csv","r");
	
	while( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &year[row], &month[row], &day[row], &ticketType[row], &ticketTime[row],
														&ageGroup[row], &benefit[row], &ticketVolume[row], &regularPriceSum[row], &lastPriceSum[row]) != -1) {
		row++;
	}
	
	if (row == 0){
		printf("불러올 내역 파일이 없습니다!");
	} 
	fclose(fp);	
}

void dataPrint(){
	printf("\n============================================report.csv=============================================\n\n");	
	printf("%s \t%s \t%11s \t%s \t%s \t%s %10s\n","발권일자","권종","이용시간","연령그룹","우대혜택","구매매수","가격");		
	printf("---------------------------------------------------------------------------------------------------\n");
	
	for(int i =0; i < row; i++){
		printf("%d%d%d  %9d %13d %12d %15d %14d %14d\n", year[i], month[i], day[i], ticketType[i], ticketTime[i],
														ageGroup[i], benefit[i], ticketVolume[i], lastPriceSum[i]);
	}
}

//권종별 판매수량 
void typeCal(){
	for(int i = 0; i <row; i++){
		if(ticketType[i] == 1 && ticketTime[i] == 1){	//종합,종일권 
			switch(ageGroup[i]){
				case 1 :	//성인,종합,종일 
					ageTicketList[0][0] += ticketVolume[i];
					ageTicketList[0][2] += lastPriceSum[i];
					break;
				case 2 :	//청소년
					ageTicketList[2][0] += ticketVolume[i];
					ageTicketList[2][2] += lastPriceSum[i];
					break;
				case 3 :	//어린이
					ageTicketList[4][0] += ticketVolume[i];
					ageTicketList[4][2] += lastPriceSum[i];
					break;
				case 4 :	//아기
					ageTicketList[6][0] += ticketVolume[i];
					ageTicketList[6][2] += lastPriceSum[i];
					break;
				case 5 :	//그외
					ageTicketList[8][0] += ticketVolume[i];
					ageTicketList[8][2] += lastPriceSum[i];
					break;
				default:
					break;
			}			 
		}		
		if(ticketType[i] == 1 && ticketTime[i] == 2){	//종합,after4 
			switch(ageGroup[i]){
				case 1 :	//성인,종합,after4 
					ageTicketList[1][0] += ticketVolume[i];
					ageTicketList[1][2] += lastPriceSum[i];
					break;
				case 2 :	//청소년
					ageTicketList[3][0] += ticketVolume[i];
					ageTicketList[3][2] += lastPriceSum[i];
					break;
				case 3 :	//어린이
					ageTicketList[5][0] += ticketVolume[i];
					ageTicketList[5][2] += lastPriceSum[i];
					break;
				case 4 :	//아기
					ageTicketList[7][0] += ticketVolume[i];
					ageTicketList[7][2] += lastPriceSum[i];
					break;
				case 5 :	//그외
					ageTicketList[9][0] += ticketVolume[i];
					ageTicketList[9][2] += lastPriceSum[i];
					break;
				default:
					break;																						
			}
		}		
		if(ticketType[i] == 2 && ticketTime[i] == 1){	//뮤지엄,종일권 
			switch(ageGroup[i]){
				case 1 :	//성인,뮤지엄,종일 
					ageTicketList[0][1] += ticketVolume[i];
					ageTicketList[0][3] += lastPriceSum[i];
					break;
				case 2 :	//청소년
					ageTicketList[2][1] += ticketVolume[i];
					ageTicketList[2][3] += lastPriceSum[i];
					break;
				case 3 :	//어린이
					ageTicketList[4][1] += ticketVolume[i];
					ageTicketList[4][3] += lastPriceSum[i];
					break;
				case 4 :	//아기
					ageTicketList[6][1] += ticketVolume[i];
					ageTicketList[6][3] += lastPriceSum[i];
					break;
				case 5 :	//그외
					ageTicketList[8][1] += ticketVolume[i];
					ageTicketList[8][3] += lastPriceSum[i];
					break;
				default:
					break;
			}
		}
		if(ticketType[i] == 2 && ticketTime[i] == 2){	//뮤지엄,after4 
			switch(ageGroup[i]){
				case 1 :	//성인,뮤지엄,after4 
					ageTicketList[1][1] += ticketVolume[i];
					ageTicketList[1][3] += lastPriceSum[i];
					break;
				case 2 :	//청소년
					ageTicketList[3][1] += ticketVolume[i];
					ageTicketList[3][3] += lastPriceSum[i];
					break;
				case 3 :	//어린이
					ageTicketList[5][1] += ticketVolume[i];
					ageTicketList[5][3] += lastPriceSum[i];
					break;
				case 4 :	//아기
					ageTicketList[7][1] += ticketVolume[i];
					ageTicketList[7][3] += lastPriceSum[i];
					break;
				case 5 :	//그외
					ageTicketList[9][1] += ticketVolume[i];
					ageTicketList[9][3] += lastPriceSum[i];
					break;
				default:
					break;																					
			}
		}		
	}
	//권종별 총판매량, 총판매액 
	for(int k=0; k<10; k++){
		if(ageTicketList[k][0]){
			typeAllSum += ageTicketList[k][0];
		}
		if(ageTicketList[k][1]){
			typeMuseumSum += ageTicketList[k][1];
		}
		if(ageTicketList[k][2]){
			typeAllPrice += ageTicketList[k][2];
		}		
		if(ageTicketList[k][3]){
			typeMuseumPrice += ageTicketList[k][3];
		}		
	}
	
	//티켓시간별 총판매량
	for(int i=0; i<9; i+=2){
		for(int j=0; j<2; j++){
			timeAllSum += ageTicketList[i][j];
		}
	}
	for(int i=1; i<=9; i+=2){
		for(int j=0; j<2; j++){
			timeA4Sum += ageTicketList[i][j];
		}
	}

	for(int i=0; i<9; i+=2){
		for(int j=2; j<4; j++){
			timeAllPriceSum += ageTicketList[i][j];
		}
	}
	for(int i=1; i<=9; i+=2){
		for(int j=2; j<4; j++){
			timeA4PriceSum += ageTicketList[i][j];
		}
	}
}
void benefitCal(){	//우대혜택별 티켓판매량
	for(int i=0; i<row; i++){
		switch(benefit[i]){
		case 1 :	//장애인우대 
			benefitList[1] += ticketVolume[i];
			break;
		case 2 :	//국가유공자우대 
			benefitList[2] += ticketVolume[i];
			break;			
		case 3 :	//휴가장병우대 
			benefitList[3] += ticketVolume[i];
			break;
		case 4 :	//임산부우대 
			benefitList[4] += ticketVolume[i];
			break;
		case 5 :	//다둥이카드 우대 
			benefitList[5] += ticketVolume[i];
			break;
		case 6 :	//해당없음 
			benefitList[6] += ticketVolume[i];
			break;
		default:
			break;														
		}
	}
	for (int i=1; i<=5; i++){
		benefitList[0] += benefitList[i];	//우대혜택 티켓 총 판매량(해당없음제외) 
	}
}

//일자별 매출입력
void dailySalesCal(){
	dailyData[0][0]=year[0], dailyData[0][1]=month[0], dailyData[0][2]=day[0], dailyData[0][3]=lastPriceSum[0];
	for(int j=1; j<row; j++){
		if(dailyData[n][0] == year[j] && dailyData[n][1] == month[j] && dailyData[n][2] == day[j]){	//일자가 같으면 매출 그대로 입력 
			dailyData[n][3] += lastPriceSum[j];
		}
		else{
			n++;
			dailyData[n][0] = year[j], dailyData[n][1] = month[j], dailyData[n][2]= day[j], dailyData[n][3] = lastPriceSum[j];	//다르면, 다음행에 일자, 가격입력 
		}
	}	
}

//판매현황출력
void typeCalPrint(){
	printf("\n---------------------------------------------------------------------------------------------------\n");
	printf("판매총량 : %d 매	판매총액 : %d 원\n", benefitList[0]+benefitList[6], typeAllPrice+typeMuseumPrice);		
	printf("\n==========================================권종별 매출==============================================\n\n");	
	printf("<종합이용권>\n[총 매 수] %d 매\n", typeAllSum);
	printf("[연 령 별] Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageTicketList[0][0]+ageTicketList[1][0], ageTicketList[2][0]+ageTicketList[3][0], ageTicketList[4][0]+ageTicketList[5][0], ageTicketList[6][0]+ageTicketList[7][0], ageTicketList[8][0]+ageTicketList[9][0]);	 
	printf("[판매총액] %d 원\n\n", typeAllPrice);	
	
	printf("<뮤지엄이용권>\n[총 매 수] %d 매\n", typeMuseumSum);
	printf("[연 령 별] Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageTicketList[0][1]+ageTicketList[1][1], ageTicketList[2][1]+ageTicketList[3][1], ageTicketList[4][1]+ageTicketList[5][1], ageTicketList[6][1]+ageTicketList[7][1], ageTicketList[8][1]+ageTicketList[9][1]);	 
	printf("[판매총액] %d 원\n\n", typeMuseumPrice);		
	
	printf("<종일권>\n[총 매 수] %d 매\n", timeAllSum);
	printf("[연 령 별] Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageTicketList[0][0]+ageTicketList[0][1], ageTicketList[2][0]+ageTicketList[2][1], ageTicketList[4][0]+ageTicketList[4][1], ageTicketList[6][0]+ageTicketList[6][1], ageTicketList[8][0]+ageTicketList[8][1]);	 
	printf("[판매총액] %d 원\n\n", timeAllPriceSum);
	
	printf("<After4이용권>\n[총 매 수] %d 매\n", timeA4Sum);
	printf("[연 령 별] Adult: %d 매, Youth: %d 매, Child: %d 매, Baby: %d 매, Others: %d 매\n", ageTicketList[1][0]+ageTicketList[1][1], ageTicketList[3][0]+ageTicketList[3][1], ageTicketList[5][0]+ageTicketList[5][1], ageTicketList[7][0]+ageTicketList[7][1], ageTicketList[9][0]+ageTicketList[9][1]); 
	printf("[판매총액] %d 원\n\n", timeA4PriceSum);			
}

//우대혜택별 티켓수
void benefitCalPrint(){
	printf("\n\n==========================================우대별 판매량============================================\n\n");
	printf("※총 티켓 판매 수는 \"6.해당없음\"을 제외한 판매량\n\n");		 
	printf("총 티켓 판매 수		: %d 매\n", benefitList[0]);
	printf("장 애 인 우 대		: %d 매\n", benefitList[1]);	
	printf("국 가 유 공 자		: %d 매\n", benefitList[2]);
	printf("휴 가 장 병 		: %d 매\n", benefitList[3]);	
	printf("임 산 부 우 대		: %d 매\n", benefitList[4]);	
	printf("다 둥 이 우 대		: %d 매\n", benefitList[5]);
	printf("---------------------------------------------------------------------------------------------------\n");		
	printf("해 당 없 음 		: %d 매\n", benefitList[6]);			 	
}

//일자별 매출 
void dailySalesCalPrint(){
	printf("\n\n==========================================일자별 판매액============================================\n\n");
	for (int i=0;i<=n;i++) {
		printf("%d년 %02d월 %02d일 : %d원\n", dailyData[i][0],dailyData[i][1],dailyData[i][2],dailyData[i][3]);		
	}
}

//보고서 생성//
//판매현황 
void typeCalReport(){
	FILE *fp2 = fopen("ticketSalesReport.csv","w");
	fprintf(fp2, "%d,%d,%d,%d,%d,%d,%d,%d\n",typeAllSum, typeMuseumSum, timeAllSum, timeA4Sum,typeAllPrice,typeMuseumPrice,timeAllPriceSum,timeA4PriceSum);
	fclose(fp2);
}

//우대혜택
void benefitCalReport(){
	FILE *fp3 = fopen("benefitSalesReport.csv","w");
	for (int i =0; i<=6; i++){
		fprintf(fp3, "%d\n", benefitList[i]);	//가독성위해 i로 인덱스표시 
	}
	fclose(fp3);
}

//일자별 매출
void dailySalesCalReport(){
	FILE *fp4 = fopen("dailySalesReport.csv","w");
	for (int i =0; i<=n; i++){
		fprintf(fp4, "%d,%d,%d,%d\n", dailyData[i][0],dailyData[i][1],dailyData[i][2],dailyData[i][3]);
	}
	fclose(fp4); 
}

//메인구간// 
int main(){
	fileScan();
	dataPrint();
	
	//계산부
	typeCal();
	benefitCal();
	dailySalesCal();
	
	//출력부
	typeCalPrint();
	benefitCalPrint();
	dailySalesCalPrint();
	
	//보고서
	typeCalReport();
	benefitCalReport();		
	dailySalesCalReport();
	
	return 0;
}
