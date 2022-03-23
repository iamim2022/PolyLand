#include <stdio.h>
#include <time.h>
//POLYLAND �̿�� ���� ver5.3

int main(){
	//<����, �迭  ����> 
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int totalPrice = 0;		//�����ֹ� �Ѿ�
	int totalVolume = 0; 	//���� �ֹ��ż� 
	
	//Ƽ�� ����(����, �ð���, �ż�) 
	int ticketType, ticketTime, ticketVolume;
		
	//������ ���� : �����̿�� 1day, After4 (��������+�����ڹ���) 
	const int ADULT_1DAY_PRICE = 59000, ADULT_A4_PRICE = 48000, YOUTH_1DAY_PRICE = 52000, YOUTH_A4_PRICE = 42000,
			CHILD_1DAY_PRICE = 47000, CHILD_A4_PRICE = 36000, BABY_1DAY_PRICE = 15000, BABY_A4_PRICE = 15000;
				
	//������ ���� : �������̿�� 1day, After4 (��������) 
	const int ADULT_1DAY_MPRICE = 56000, ADULT_A4_MPRICE = 45000, YOUTH_1DAY_MPRICE = 50000, YOUTH_A4_MPRICE = 40000,
			CHILD_1DAY_MPRICE = 46000, CHILD_A4_MPRICE = 35000, BABY_1DAY_MPRICE = 15000, BABY_A4_MPRICE = 15000;	 	
	
	//�ֹε�Ϲ�ȣ �м�
	int id, birthYear, birthMonth, birthDay, year, AmericanAge, KoreanAge, YearGap, gender;
	int idMinNum = 000101;  //90708
	int idMaxNum = 991231;
	int genderMin = 1;
	int genderMax = 4;  

	//�ֹε�Ϲ�ȣ ���� ����(���糪�� ���) 
	int century, birthYearFull;

	//������� ���ú��� 
	int benefit;
	int discounted; //��������� Ƽ�� 1�� ���� 
	int lastPrice; // ���ΰ� * �ż� 
	int benefitMax = 6;
	int benefitMin = 1;
	
	//��Ÿ����	 
	int exitAnswer, ageGroup, regularPrice, currentTime, regularPriceSum;
	char genderPrint;

	//��꺯�� �ʱ�ȭ 
	ticketType=0, ticketTime=0, ticketVolume=0, lastPrice=0, discounted=0, benefit=0, century=0, birthYearFull=0, currentTime=0;
	id=0, birthYear=0, birthMonth=0, birthDay=0, year=0, AmericanAge=0, KoreanAge=0, YearGap=0, gender=0;
	exitAnswer=0, ageGroup=0, regularPrice=0, regularPriceSum=0;

	//�迭Ž���� 
	int row = 0;	//�迭_�� �̵� ���� 
	int orderList[100][10] = {0}; 
	 
	//<�Էº�>		
	printf("==================================================================================================\n");
	printf("\n******************************************** Welcome *********************************************\n\n");	
	printf("%62s\n\n","Many computers, Many people");
	printf("%58s","~~~ POLY LAND ~~~\n\n");
	printf("==================================================================================================\n\n");
	printf("%78s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
		do{
			do{
				printf("<�̿�� ������ �����ϼ���.>\n"); 
				printf("1. �����̿�� (��������+ �����ڹ���)\n"); 
				printf("2. �������̿�� (�����ڹ���)\n\n"); 	
				printf("���� �Է�: ");
				scanf("%d", &ticketType); 
				printf("\n--------------------------------------------------------------------------------------------------\n");
				if(!(ticketType == 1 || ticketType == 2)){
					printf("<<<!!�̿�� ������ �ٽ� �����ϼ���!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n");								
					continue;										
				}			
			}while( !(ticketType == 1 || ticketType == 2));
	
			do{	
				printf("<�̿�� �ð��� �����ϼ���.>\n"); 
				printf("1. ���ϱ�\n"); 
				printf("2. After4\n\n"); 	
				printf("���� �Է�: ");
				scanf("%d", &ticketTime); 	
				printf("\n--------------------------------------------------------------------------------------------------\n");
				if(!(ticketTime == 1 || ticketTime == 2)){					
					printf("<<<!!�̿�� �ð��� �ٽ� �����ϼ���!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");					
					continue;											
				}		
			}while( !(ticketTime == 1 || ticketTime == 2));
	
			//Ƽ�� �ż� Ȯ�� (Ƽ���� 10�ű����� ���Ű���)
			do{		 						
				printf("<�����Ϸ��� �ż��� �Է��ϼ���.>\n"); 
				printf("Ƽ���� �ִ� 10�ű��� ������ �� �ֽ��ϴ�.\n");	
				printf("\n�Է¿��� : 2\n\n"); 
				printf("�ż� �Է�: ");
				scanf("%d", &ticketVolume);
				printf("\n--------------------------------------------------------------------------------------------------\n");						
				if(ticketVolume > 10){
					printf("<<<!!Ƽ���� �ִ� 10������� ���Ű����մϴ�!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");	
					continue;				
				}
			} while(ticketVolume > 10); 
							
			//�ֹε�Ϲ�ȣ �Էº� 
			do{
				printf("<�ֹε�Ϲ�ȣ�� �Է��ϼ���.>\n"); 	
				printf("\n�Է¿��� : 980315-2\n\n"); 
				printf("�ֹι�ȣ ���ڸ� �Է�: ");
				scanf("%6d-%1d", &id, &gender);
				printf("\n--------------------------------------------------------------------------------------------------\n");								
				if(!((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))){	
					printf("<<<!!�ֹι�ȣ�� Ȯ���ϼ���!!>>>");
					printf("\n--------------------------------------------------------------------------------------------------\n\n");	
					continue;				
				}				
			} while(!((id <= idMaxNum) && (id >= idMinNum) && (gender >= genderMin) && (gender <= genderMax))); 
						
			//������� �Էº� 
			do{		
				printf("\n");			
				printf("==================================================================================================\n\n");
				printf("<�������� �����ϼ���.>\n"); 
				printf("�� ���̿� ���� ���� �ڵ�����˴ϴ�.\n"); 
				printf("�� �����̿��/�������̿�� ����� : �����, ����������, �ް��庴 \n");
				printf("�� �����̿�� ����� : �ӻ��, �ٵ��� �ູī�� ������ \n");
				printf("--------------------------------------------------------------------------------------------------\n");
				printf("<��� ����>");
				printf("\n1.����� ���\n2.���������� ���\n3.�ް��庴���\n4.�ӻ�ο��\n5.�ٵ����ູī�� ���\n6.�ش����");	
				printf("\n\n�Է¿��� : 3\n\n"); 
				printf("��� ���� ��ȣ: ");
				scanf("%d", &benefit);
				//printf("\n--------------------------------------------------------------------------------------------------\n");				
				if(benefit > benefitMax || benefit < benefitMin){
					printf("<<<!!��������� Ȯ���ϼ���!!>>>");
					printf("\n----------------------------------------------------------------------------------------------------");	
					continue;		
				}
			} while(benefit > benefitMax || benefit < benefitMin); 	
	
			//<����> 
			birthYear = id / 10000;		
			birthMonth = (id % 10000) / 100;
			birthDay = id % 100;
		
			//������ ���� 1900���, 2000��� �����ϱ� [4�ڸ� ����] 
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
			
			//����⵵ - ����⵵	 
			YearGap = (tm.tm_year+1900) - birthYearFull;
		
			//�� ����: birthMonth >= month �� ������ ������.
			if(birthMonth >= (tm.tm_mon+1) && birthDay >= (tm.tm_mday)){
				AmericanAge = YearGap;
			} 
			else{
				AmericanAge = YearGap -1;
			}
			
			//���� ����, �츮�� �ƴ� ���� 
			KoreanAge = YearGap + 1 ;	
		
			//����
			if(gender == 1 && 3){			
				genderPrint = 'M';
			} 
			if(gender == 2 && 4){
				genderPrint = 'W';
			} 			 	
			
			//���̱׷�
			if(AmericanAge >= 19 && AmericanAge <= 64){
				ageGroup = 1; //adult
			}
			if(AmericanAge >= 13 && AmericanAge <= 18){
				ageGroup = 2;	//youth		
			}
			if(AmericanAge >= 3 && AmericanAge <= 12){
				ageGroup = 3;	//child				
			}
			if(AmericanAge >= 1 && AmericanAge <= 2){
				ageGroup = 4;	//baby				
			}	
			if(AmericanAge < 1 || AmericanAge >= 65){
				ageGroup = 5;	//others				
			}
					
			//��� ���										
			//���ο�� : �� 19���̻� ~ ��64������
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
			//û�ҳ��� : �� 13�� �̻� ~ �� 18�� ����
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
			 //��̿�� : �� 3�� �̻� ~ �� 12�� ����
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
			 //�Ʊ� ��� : �� 1�� �̻� ~ ��2�� ����	 
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
			//��Ÿ: �� 1�� �̸�, ��65�� �̻��� ���� 
			else if(ageGroup == 5) {
				lastPrice = 0;
			}	  	
		
			//Ƽ�� ���� ����				 	
			//Ƽ�� �������� : ��밡, �ż� ���� 
			for(int i = 1; i <= ticketVolume; i++){
				//�����, ���������� :[����, ������] Ƽ�� ���� 1�α��� ��� 50%������ Ƽ�� ������
				if(benefit == 1 || benefit == 2){
					switch(ticketVolume)	{
						case 1:
							lastPrice = regularPrice * 0.5;
							regularPriceSum = regularPrice*i;
							break;					
						case 2:
							lastPrice = (regularPrice * 0.5)*2;
							regularPriceSum = regularPrice*i;							
							break;																	
						case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.5)*2 + (regularPrice * (i - 2));
							regularPriceSum = regularPrice*i;												
							break;										
					}
				}			
				//�ް��庴 :�����̿��, ���� 1�� ���� ��� 49% ������ Ƽ�� ������
				//Ƽ�� ������ 1000�� ���� 
				if(benefit == 3 && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = ((regularPrice * 51) / 10000) *100;	//1000���̸� ���� 
							regularPriceSum = regularPrice*i;							
							break;					
						case 2:
							lastPrice = (((regularPrice * 51) / 10000) *100) * 2;
							regularPriceSum = regularPrice*i;							
							break;																	
						case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (((regularPrice * 51) / 10000) *100) * 2 + (regularPrice * (i - 2));
							regularPriceSum = regularPrice*i;													
							break;										
					}
				}		
				//�ӻ��: �����̿��, ���� ��� 50% ������ Ƽ�� ������
				if(benefit == 4 && genderPrint == 'W' && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = regularPrice * 0.5;
							regularPriceSum = regularPrice*i;							
							break;																						
						case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.5) + (regularPrice * (i - 1));
							regularPriceSum = regularPrice*i;												
							break;										
					}
				}					
				//�ٵ���ī�� :�����̿��, ���� ��� 30% ������ Ƽ�� ������ 
				if(benefit == 5 && ticketType == 1){
					switch(ticketVolume){
						case 1:
							lastPrice = regularPrice * 0.7;
							regularPriceSum = regularPrice*i;							
							break;																						
						case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
							lastPrice = (regularPrice * 0.7) + (regularPrice * (i - 1));
							regularPriceSum = regularPrice*i;													
							break;										
					}
				}				
				 //��� �������� ��� Ƽ�� ������		
				if(benefit == 6 || benefit == 3 && ticketType == 2 || benefit == 4 && ticketType == 2 || benefit == 5 && ticketType == 2){
					lastPrice = regularPrice * i;
					regularPriceSum = regularPrice*i;					
				}
			 }
	
	//<��º�>	
	//���� Ƽ�ϼ�, ���� ���	
	printf("\n\n");			
	printf("==================================================================================================\n\n");
	printf("%s\n\n","<�ֹ�����>");
	if(lastPrice == 0){
		printf("\n���� �����Դϴ�.\n");
	}
	else{
	printf("�����Ͻ� �ż��� %d ��, ���� ������ %d�� �Դϴ�.\n\n", ticketVolume, lastPrice);
	}	
	
	//�迭�� �� ���ų��� ���� ����
	orderList[row][0] = ticketType;
	orderList[row][1] = ticketTime;
	orderList[row][2] = ageGroup;
	orderList[row][3] = benefit;
	orderList[row][4] = ticketVolume;
	orderList[row][5] = regularPriceSum;	//��꼭�� ��µǴ� ����*�ż� �� �Ѱ��� 
	orderList[row][6] = lastPrice;
	orderList[row][7] = tm.tm_year+1900;
	orderList[row][8] = tm.tm_mon+1;	
	orderList[row][9] = tm.tm_mday;			
	row++;	//�ʱⰪ0

	totalPrice += lastPrice;	//�����ֹ����� �Ѿ�	
	totalVolume += ticketVolume;	//���� Ƽ�ϸż� ����	
		
		do{
			printf("\n�߰� �߱��Ͻðڽ��ϱ�?\n\n1.�߰��߱�\n2.�߱�����\n\n");
			printf("���� �Է� : ");
			scanf("%1d",&exitAnswer);
			if(exitAnswer>2 || exitAnswer<1){
				printf("<<<!!�Է¹�ȣ�� Ȯ���ϼ���!!>>>");
				continue;
			}
		} while(exitAnswer>2 || exitAnswer<1);		
		printf("==================================================================================================\n\n");	
	} while (exitAnswer==1);	//�߰����� �ݺ� _�������μ��� �����. 
	
	FILE *fp = fopen("report.csv","a");
	fprintf(fp, "PurchaseDate, Type, Time, Age, benefit, Volume, RegularPrice,DiscountPrice\n");	

	//<������ ��º�>��꼭 ��� 
	printf("==========================================<�������ų���>==========================================\n");	 
	printf("%7s %18s %6s %15s %13s %16s %16s\n","Type","Ticket Time","Age","benefit","Volume","Regular Price","Discount Price");
	printf("--------------------------------------------------------------------------------------------------");
	for (int j=0; j < row; j++)
	{	
		switch(orderList[j][0]){	//ticketType
			case 1:
				printf("\n�� �� �̿��");
				break;
			case 2:
				printf("\n�������̿��");	 
				break;					
		}
		switch(orderList[j][1]){	// ticketTime
			case 1:
				printf("%11s","���ϱ�");
				break;
			case 2:
				printf("%11s","After4");	 
				break;					
		}
		switch(orderList[j][2]){	//ageGroup
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
		switch(orderList[j][3]){	//benefit
			case 1:
				printf("%19s","�� �� �� �� ��");
				break;
			case 2:
				printf("%19s","�� �� �� �� ��");
				break;				
			case 3:
				printf("%19s","��  ��  ��  ��");
				break;				
			case 4:
				printf("%19s","�� �� �� �� ��");
				break;				
			case 5:
				printf("%19s","�� �� �� �� ��");
				break;
			case 6:
				printf("%19s","��  ��  ��  ��");
				break;																					
		 } 
		printf("%6d ��",orderList[j][4]);	//ticketVolume
		printf("%12d ��",orderList[j][5]);	//regularPrice		
		printf("%14d ��",orderList[j][6]);	//lastPrice
	 }  //for (int j=0; j < row; j++) close		
	 
	for (int j=0; j < row; j++)	{	
		fprintf(fp, "%d%02d%02d,%d,%d,%d,%d,%d,%d,%d\n", orderList[j][7],orderList[j][8],orderList[j][9],
														orderList[j][0],orderList[j][1],orderList[j][2],orderList[j][3],	//���⼭ ������ �����̶� ���������͸� ���⿡ ���� 
														orderList[j][4],orderList[j][5],orderList[j][6]); //csv�������屸���ڴ� �޸�		 	 
	}	 
	printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("�� �ż�: %d ��\n", totalVolume);		
	printf("�ֹ� �Ѿ�: %d ��\n", totalPrice);
	fclose(fp);	//fliePointer close 	
	
	//������ 
	printf("\n==================================================================================================\n");	
	printf("******************************************** Thank you *******************************************\n\n");
	printf("\n==================================================================================================\n");	
	printf("%78s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);	
				
	return 0;
} 
