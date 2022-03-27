#include<stdio.h>
//POLYLAND_REPORTver2.0

//��������// 
const int MAX = 100;
int row = 0, n = 0; 
int year[MAX], month[MAX], day[MAX], ticketType[MAX], ticketTime[MAX], ageGroup[MAX], benefit[MAX], ticketVolume[MAX],
	regularPriceSum[MAX], lastPriceSum[MAX], ageTicketList[MAX][MAX]={0}, benefitList[MAX]={0}, dailyData[MAX][4];

//��꺯�� �ʱ�ȭ
int typeAllSum = 0, typeMuseumSum = 0, typeAllPrice = 0, typeMuseumPrice = 0,
	typeAllAllSum = 0, typeAllAf4Sum = 0, typeMuseumAllSum = 0, typeMuseumAf4Sum = 0,
	timeAllSum = 0, timeA4Sum = 0, timeAllPriceSum = 0, timeA4PriceSum = 0; 

//�Լ�����// 
void fileScan(){
	FILE *fp = fopen("report.csv","r");
	
	while( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &year[row], &month[row], &day[row], &ticketType[row], &ticketTime[row],
														&ageGroup[row], &benefit[row], &ticketVolume[row], &regularPriceSum[row], &lastPriceSum[row]) != -1) {
		row++;
	}
	
	if (row == 0){
		printf("�ҷ��� ���� ������ �����ϴ�!");
	} 
	fclose(fp);	
}

void dataPrint(){
	printf("\n============================================report.csv=============================================\n\n");	
	printf("%s \t%s \t%11s \t%s \t%s \t%s %10s\n","�߱�����","����","�̿�ð�","���ɱ׷�","�������","���Ÿż�","����");		
	printf("---------------------------------------------------------------------------------------------------\n");
	
	for(int i =0; i < row; i++){
		printf("%d%d%d  %9d %13d %12d %15d %14d %14d\n", year[i], month[i], day[i], ticketType[i], ticketTime[i],
														ageGroup[i], benefit[i], ticketVolume[i], lastPriceSum[i]);
	}
}

//������ �Ǹż��� 
void typeCal(){
	for(int i = 0; i <row; i++){
		if(ticketType[i] == 1 && ticketTime[i] == 1){	//����,���ϱ� 
			switch(ageGroup[i]){
				case 1 :	//����,����,���� 
					ageTicketList[0][0] += ticketVolume[i];
					ageTicketList[0][2] += lastPriceSum[i];
					break;
				case 2 :	//û�ҳ�
					ageTicketList[2][0] += ticketVolume[i];
					ageTicketList[2][2] += lastPriceSum[i];
					break;
				case 3 :	//���
					ageTicketList[4][0] += ticketVolume[i];
					ageTicketList[4][2] += lastPriceSum[i];
					break;
				case 4 :	//�Ʊ�
					ageTicketList[6][0] += ticketVolume[i];
					ageTicketList[6][2] += lastPriceSum[i];
					break;
				case 5 :	//�׿�
					ageTicketList[8][0] += ticketVolume[i];
					ageTicketList[8][2] += lastPriceSum[i];
					break;
				default:
					break;
			}			 
		}		
		if(ticketType[i] == 1 && ticketTime[i] == 2){	//����,after4 
			switch(ageGroup[i]){
				case 1 :	//����,����,after4 
					ageTicketList[1][0] += ticketVolume[i];
					ageTicketList[1][2] += lastPriceSum[i];
					break;
				case 2 :	//û�ҳ�
					ageTicketList[3][0] += ticketVolume[i];
					ageTicketList[3][2] += lastPriceSum[i];
					break;
				case 3 :	//���
					ageTicketList[5][0] += ticketVolume[i];
					ageTicketList[5][2] += lastPriceSum[i];
					break;
				case 4 :	//�Ʊ�
					ageTicketList[7][0] += ticketVolume[i];
					ageTicketList[7][2] += lastPriceSum[i];
					break;
				case 5 :	//�׿�
					ageTicketList[9][0] += ticketVolume[i];
					ageTicketList[9][2] += lastPriceSum[i];
					break;
				default:
					break;																						
			}
		}		
		if(ticketType[i] == 2 && ticketTime[i] == 1){	//������,���ϱ� 
			switch(ageGroup[i]){
				case 1 :	//����,������,���� 
					ageTicketList[0][1] += ticketVolume[i];
					ageTicketList[0][3] += lastPriceSum[i];
					break;
				case 2 :	//û�ҳ�
					ageTicketList[2][1] += ticketVolume[i];
					ageTicketList[2][3] += lastPriceSum[i];
					break;
				case 3 :	//���
					ageTicketList[4][1] += ticketVolume[i];
					ageTicketList[4][3] += lastPriceSum[i];
					break;
				case 4 :	//�Ʊ�
					ageTicketList[6][1] += ticketVolume[i];
					ageTicketList[6][3] += lastPriceSum[i];
					break;
				case 5 :	//�׿�
					ageTicketList[8][1] += ticketVolume[i];
					ageTicketList[8][3] += lastPriceSum[i];
					break;
				default:
					break;
			}
		}
		if(ticketType[i] == 2 && ticketTime[i] == 2){	//������,after4 
			switch(ageGroup[i]){
				case 1 :	//����,������,after4 
					ageTicketList[1][1] += ticketVolume[i];
					ageTicketList[1][3] += lastPriceSum[i];
					break;
				case 2 :	//û�ҳ�
					ageTicketList[3][1] += ticketVolume[i];
					ageTicketList[3][3] += lastPriceSum[i];
					break;
				case 3 :	//���
					ageTicketList[5][1] += ticketVolume[i];
					ageTicketList[5][3] += lastPriceSum[i];
					break;
				case 4 :	//�Ʊ�
					ageTicketList[7][1] += ticketVolume[i];
					ageTicketList[7][3] += lastPriceSum[i];
					break;
				case 5 :	//�׿�
					ageTicketList[9][1] += ticketVolume[i];
					ageTicketList[9][3] += lastPriceSum[i];
					break;
				default:
					break;																					
			}
		}		
	}
	//������ ���Ǹŷ�, ���Ǹž� 
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
	
	//Ƽ�Ͻð��� ���Ǹŷ�
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
void benefitCal(){	//������ú� Ƽ���Ǹŷ�
	for(int i=0; i<row; i++){
		switch(benefit[i]){
		case 1 :	//����ο�� 
			benefitList[1] += ticketVolume[i];
			break;
		case 2 :	//���������ڿ�� 
			benefitList[2] += ticketVolume[i];
			break;			
		case 3 :	//�ް��庴��� 
			benefitList[3] += ticketVolume[i];
			break;
		case 4 :	//�ӻ�ο�� 
			benefitList[4] += ticketVolume[i];
			break;
		case 5 :	//�ٵ���ī�� ��� 
			benefitList[5] += ticketVolume[i];
			break;
		case 6 :	//�ش���� 
			benefitList[6] += ticketVolume[i];
			break;
		default:
			break;														
		}
	}
	for (int i=1; i<=5; i++){
		benefitList[0] += benefitList[i];	//������� Ƽ�� �� �Ǹŷ�(�ش��������) 
	}
}

//���ں� �����Է�
void dailySalesCal(){
	dailyData[0][0]=year[0], dailyData[0][1]=month[0], dailyData[0][2]=day[0], dailyData[0][3]=lastPriceSum[0];
	for(int j=1; j<row; j++){
		if(dailyData[n][0] == year[j] && dailyData[n][1] == month[j] && dailyData[n][2] == day[j]){	//���ڰ� ������ ���� �״�� �Է� 
			dailyData[n][3] += lastPriceSum[j];
		}
		else{
			n++;
			dailyData[n][0] = year[j], dailyData[n][1] = month[j], dailyData[n][2]= day[j], dailyData[n][3] = lastPriceSum[j];	//�ٸ���, �����࿡ ����, �����Է� 
		}
	}	
}

//�Ǹ���Ȳ���
void typeCalPrint(){
	printf("\n---------------------------------------------------------------------------------------------------\n");
	printf("�Ǹ��ѷ� : %d ��	�Ǹ��Ѿ� : %d ��\n", benefitList[0]+benefitList[6], typeAllPrice+typeMuseumPrice);		
	printf("\n==========================================������ ����==============================================\n\n");	
	printf("<�����̿��>\n[�� �� ��] %d ��\n", typeAllSum);
	printf("[�� �� ��] Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageTicketList[0][0]+ageTicketList[1][0], ageTicketList[2][0]+ageTicketList[3][0], ageTicketList[4][0]+ageTicketList[5][0], ageTicketList[6][0]+ageTicketList[7][0], ageTicketList[8][0]+ageTicketList[9][0]);	 
	printf("[�Ǹ��Ѿ�] %d ��\n\n", typeAllPrice);	
	
	printf("<�������̿��>\n[�� �� ��] %d ��\n", typeMuseumSum);
	printf("[�� �� ��] Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageTicketList[0][1]+ageTicketList[1][1], ageTicketList[2][1]+ageTicketList[3][1], ageTicketList[4][1]+ageTicketList[5][1], ageTicketList[6][1]+ageTicketList[7][1], ageTicketList[8][1]+ageTicketList[9][1]);	 
	printf("[�Ǹ��Ѿ�] %d ��\n\n", typeMuseumPrice);		
	
	printf("<���ϱ�>\n[�� �� ��] %d ��\n", timeAllSum);
	printf("[�� �� ��] Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageTicketList[0][0]+ageTicketList[0][1], ageTicketList[2][0]+ageTicketList[2][1], ageTicketList[4][0]+ageTicketList[4][1], ageTicketList[6][0]+ageTicketList[6][1], ageTicketList[8][0]+ageTicketList[8][1]);	 
	printf("[�Ǹ��Ѿ�] %d ��\n\n", timeAllPriceSum);
	
	printf("<After4�̿��>\n[�� �� ��] %d ��\n", timeA4Sum);
	printf("[�� �� ��] Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageTicketList[1][0]+ageTicketList[1][1], ageTicketList[3][0]+ageTicketList[3][1], ageTicketList[5][0]+ageTicketList[5][1], ageTicketList[7][0]+ageTicketList[7][1], ageTicketList[9][0]+ageTicketList[9][1]); 
	printf("[�Ǹ��Ѿ�] %d ��\n\n", timeA4PriceSum);			
}

//������ú� Ƽ�ϼ�
void benefitCalPrint(){
	printf("\n\n==========================================��뺰 �Ǹŷ�============================================\n\n");
	printf("���� Ƽ�� �Ǹ� ���� \"6.�ش����\"�� ������ �Ǹŷ�\n\n");		 
	printf("�� Ƽ�� �Ǹ� ��		: %d ��\n", benefitList[0]);
	printf("�� �� �� �� ��		: %d ��\n", benefitList[1]);	
	printf("�� �� �� �� ��		: %d ��\n", benefitList[2]);
	printf("�� �� �� �� 		: %d ��\n", benefitList[3]);	
	printf("�� �� �� �� ��		: %d ��\n", benefitList[4]);	
	printf("�� �� �� �� ��		: %d ��\n", benefitList[5]);
	printf("---------------------------------------------------------------------------------------------------\n");		
	printf("�� �� �� �� 		: %d ��\n", benefitList[6]);			 	
}

//���ں� ���� 
void dailySalesCalPrint(){
	printf("\n\n==========================================���ں� �Ǹž�============================================\n\n");
	for (int i=0;i<=n;i++) {
		printf("%d�� %02d�� %02d�� : %d��\n", dailyData[i][0],dailyData[i][1],dailyData[i][2],dailyData[i][3]);		
	}
}

//���� ����//
//�Ǹ���Ȳ 
void typeCalReport(){
	FILE *fp2 = fopen("ticketSalesReport.csv","w");
	fprintf(fp2, "%d,%d,%d,%d,%d,%d,%d,%d\n",typeAllSum, typeMuseumSum, timeAllSum, timeA4Sum,typeAllPrice,typeMuseumPrice,timeAllPriceSum,timeA4PriceSum);
	fclose(fp2);
}

//�������
void benefitCalReport(){
	FILE *fp3 = fopen("benefitSalesReport.csv","w");
	for (int i =0; i<=6; i++){
		fprintf(fp3, "%d\n", benefitList[i]);	//���������� i�� �ε���ǥ�� 
	}
	fclose(fp3);
}

//���ں� ����
void dailySalesCalReport(){
	FILE *fp4 = fopen("dailySalesReport.csv","w");
	for (int i =0; i<=n; i++){
		fprintf(fp4, "%d,%d,%d,%d\n", dailyData[i][0],dailyData[i][1],dailyData[i][2],dailyData[i][3]);
	}
	fclose(fp4); 
}

//���α���// 
int main(){
	fileScan();
	dataPrint();
	
	//����
	typeCal();
	benefitCal();
	dailySalesCal();
	
	//��º�
	typeCalPrint();
	benefitCalPrint();
	dailySalesCalPrint();
	
	//����
	typeCalReport();
	benefitCalReport();		
	dailySalesCalReport();
	
	return 0;
}
