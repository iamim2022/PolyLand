#include<stdio.h>

int main(){
	
	//file open 
	FILE *fp=fopen("sample.csv","r");
	const int MAX = 100;	//�˳��ϰ� ����. 
	int count=0;
	int year[MAX], month[MAX], day[MAX],
		ticketType[MAX], ticketTime[MAX], ageGroup[MAX], benefit[MAX], ticketVolume[MAX], regularPriceSum[MAX], lastPriceSum[MAX],
		ageGoup[MAX][MAX]={0};	
		
	//��°��ú����� �ʱ�ȭ 
	int benefit1=0, benefit2=0, benefit3=0, benefit4=0, benefit5=0, benefit6=0,	//������� 
		amusementTicketPrice=0, museumTicketPrice=0, alldayPrice=0, after4Price=0,
		dayPriceSum=0, ticketNumSum=0, amusementNumSum=0, museumNumSum=0, alldayNumSum=0, after4NumSum=0; 
			
	while( fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count], &ticketType[count], &ticketTime[count], &ageGroup[count], &benefit[count], &ticketVolume[count], &regularPriceSum[count], &lastPriceSum[count]) != -1)
	{
		count++;
	}
	fclose(fp);	
		 
	//file print : ������ fscanf�� �Է¹��� �ֵ� ����Ʈ. 
	printf("\n==================================================report.csv====================================================\n\n");	
	printf("%s \t%s \t%11s \t%s \t%s \t%s %10s \t%s\n","�߱ǽð�","����","�̿�ð�","���ɱ׷�","�������","���Ÿż�","����","�������밡");		
	printf("----------------------------------------------------------------------------------------------------------------\n");	

	for(int i = 0; i < count; i++)
	{
		printf("%d%d%d %9d %13d %12d %15d %14d %14d \t%10d\n",year[i], month[i], day[i], ticketType[i], ticketTime[i], ageGroup[i], benefit[i], ticketVolume[i], regularPriceSum[i], lastPriceSum[i]);
	}//������� �ٿ��� ���� 
	
	//����, ���̱׷� ���źм� 
	for(int i = 0;  i<count; i++)
	{
		switch(ticketType[i]){
			case 1: //����+����
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
				amusementTicketPrice += lastPriceSum[i];	//switch�� �ݺ����� ���ձ� ���ݱ���
				alldayPrice += lastPriceSum[i]; // ���ϱ� ��������
				break;	//�ٱ� case1 ����
			case 2: //����+after4
				switch(ageGroup[i]){
					case 1 : //Adult
						ageGoup[0][0] += ticketVolume[i];	//00�� ��������
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
				after4Price += lastPriceSum[i]; // after4�̿�� ��������
				break;
			case 3: //������+����
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
			case 4: //������+after4
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
	
		
	//Ƽ�� ���Ǹŷ�, ������ú� Ƽ���Ǹŷ� ���
	//���� ���� Ƽ�� ����
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
	 		benefit6 += ticketVolume[i];	//���:�ش���� 
	 		break;	
		default:	//���� 6������ ���� 
			break;			 		 			 				 		 		
	 }		
	} 	//���� 36 for�� close 

	//������ �� Ƽ��	
	amusementNumSum = ageGoup[0][3]+ageGoup[0][2]+ageGoup[0][1]+ageGoup[0][0]+ageGoup[0][4];
	museumNumSum = ageGoup[1][3]+ageGoup[1][2]+ageGoup[1][1]+ageGoup[1][0]+ageGoup[1][4];
	alldayNumSum = ageGoup[2][3]+ageGoup[2][2]+ageGoup[2][1]+ageGoup[2][0]+ageGoup[2][4];
	after4NumSum = ageGoup[3][3]+ageGoup[3][2]+ageGoup[3][1]+ageGoup[3][0]+ageGoup[3][4];	
	
	//��Ƽ�ϼ�= ������� �޴� Ƽ�� ����(������ÿ� �ش����������) 
	ticketNumSum = benefit1+benefit2+benefit3+benefit4+benefit5+benefit6;
	
	//���Ϸ� ���
	FILE *fp1, *fp2;	//���ں� ���� �߰��� �� 
	fp = fopen("ticketReport.csv","a"); 
	fp2 = fopen("benefitReport.csv","a");
	
	//��º�	
	printf("\n=================================================������ ����=================================================\n\n");
	printf("�����̿�� �� %d ��\n", amusementNumSum);
	printf("Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageGoup[0][0], ageGoup[0][1], ageGoup[0][2], ageGoup[0][3], ageGoup[0][4]);	 
	printf("�����̿�� �Ǹ��Ѿ�: %d ��\n\n", amusementTicketPrice);	
	
	printf("�������̿�� �� %d ��\n", museumNumSum);
	printf("Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageGoup[1][0], ageGoup[1][1], ageGoup[1][2], ageGoup[1][3], ageGoup[1][4]);	 
	printf("�������̿�� �Ǹ��Ѿ�: %d ��\n\n", museumTicketPrice);		
	
	printf("���ϱ� �� %d ��\n", alldayNumSum);
	printf("Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageGoup[0][0], ageGoup[0][1], ageGoup[0][2], ageGoup[0][3], ageGoup[0][4]);	 
	printf("�����̿�� �Ǹ��Ѿ�: %d ��\n\n", alldayPrice);	
	
	printf("After4�̿�� �� %d ��\n", after4NumSum);
	printf("Adult: %d ��, Youth: %d ��, Child: %d ��, Baby: %d ��, Others: %d ��\n", ageGoup[1][0], ageGoup[1][1], ageGoup[1][2], ageGoup[1][3], ageGoup[1][4]);	 
	printf("�������̿�� �Ǹ��Ѿ�: %d ��\n\n", after4Price);		
	printf("\n============================================================================================================\n\n");	
	
	//�� Ƽ���Ǹŷ� �� ������ú� Ƽ�ϼ�
	printf("\n================================================��뺰 �Ǹŷ�================================================\n\n");	 
	printf("�� Ƽ�� �Ǹ� ��		: %d ��\n", ticketNumSum);
	printf("�� �� �� �� ��		: %d ��\n", benefit1);	
	printf("�� �� �� �� ��		: %d ��\n", benefit2);
	printf("�� �� �� �� 		: %d ��\n", benefit3);	
	printf("�� �� �� �� ��		: %d ��\n", benefit4);	
	printf("�� �� �� �� ��		: %d ��\n", benefit5);	
	printf("�� �� �� �� 		: %d ��\n", benefit6);		
	printf("\n===========================================================================================================\n\n");	 	

	fclose(fp);
	return 0;
}	
