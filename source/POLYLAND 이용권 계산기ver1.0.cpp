#include <stdio.h>
#include <time.h>
 
//POLYLAND�̿�� ���� 
 
int main(){
	//time.h ������� tm�Լ� ������� ���� 
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	//�̿�� ���� ����(������, �ð���) 
	int ticket_type;
	int ticket_time;	
	 		
		//������ ���� : �����̿�� 1day, After4 (��������+�����ڹ���) 
		const int ADULT_1DAY_PRICE = 59000, ADULT_A4_PRICE = 48000, 
				YOUTH_1DAY_PRICE = 52000, YOUTH_A4_PRICE = 42000,
				CHILD_1DAY_PRICE = 47000, CHILD_A4_PRICE = 36000,
				BABY_1DAY_PRICE = 15000, BABY_A4_PRICE = 15000;
				
		
		//������ ���� : �������̿�� 1day, After4 (��������) 
		const int ADULT_1DAY_MPRICE = 56000, ADULT_A4_MPRICE = 45000, 
				YOUTH_1DAY_MPRICE = 50000, YOUTH_A4_MPRICE = 40000,
				CHILD_1DAY_MPRICE = 46000, CHILD_A4_MPRICE = 35000,
				BABY_1DAY_MPRICE = 15000, BABY_A4_MPRICE = 15000;	 
	
	
	//�ֹε�Ϲ�ȣ �м�
	int id;	//�ֹι�ȣ �� 6�ڸ� 
	int birthYear, birthMonth, birthDay; //�������� 	birthYear�� ����⵵ ��2�ڸ� 
	int year;		//����⵵ 	
	int man;	//������
	int age;	//���� ���� 
	int gap;	//����⵵ - ����⵵	
	int gender;	//�ֹι�ȣ 7��° �ڸ� : 1,2 �Ǵ� 3,4 
		
	//�������� �ʱ����
	printf("********************* Welcome! **********************\n\n");	
	printf("%39s\n\n","Many computers, Many people");
	printf("%36s","~~~ POLY LAND ~~~\n\n");
	printf("=====================================================\n\n");
	printf("%34s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	//�̿�� ���� ���� ���� 
	printf("<�̿�� ������ �����ϼ���.>\n"); 
	printf("1. �����̿�� (��������+ �����ڹ���)\n"); 
	printf("2. �������̿�� (�����ڹ���)\n\n"); 	
	printf("���� �Է�: ");
	scanf("%d", &ticket_type); 
	
	//�̿�� ���� ���� ���� ��� 
	if(ticket_type == 1)
	{
		printf("\n");
		printf("%s","�����̿���� �����ϼ̽��ϴ�.");
		printf("\n------------------------------------------------\n\n");				
	}
	else if(ticket_type == 2)
	{
		printf("\n");
		printf("%s","�������̿���� �����ϼ̽��ϴ�.");
		printf("\n\n");
	}
	else
	 {
		printf("�߸��� �Է��Դϴ�.");
		printf("\n�ȳ������ʽÿ�.\n");			
	}				
	//�̿� �ð� ���� 
	printf("<�̿�� �ð��� �����ϼ���.>\n"); 
	printf("3. ���ϱ�\n"); 
	printf("4. ���� 4�� ���� �̿��\n\n"); 	
	printf("���� �Է�: ");
	scanf("%d", &ticket_time); 	
	
	//�̿�� �ð� ���� ���
		if(ticket_time == 3)
	{
		printf("\n");
		printf("%s\n","���ϱ��� �����ϼ̽��ϴ�.");			
	}
	else if(ticket_time == 4)
	{
		printf("\n");
		printf("%s","���� 4�� ���� �̿���� �����ϼ̽��ϴ�.");
		printf("\n\n");
	}
	else
	 {
		printf("�߸��� �Է��Դϴ�.");
		printf("\n�ȳ������ʽÿ�.");
	}			

	
	//�ֹε�Ϲ�ȣ �Է�
	printf("\n=====================================================\n\n");
	printf("<�ֹε�Ϲ�ȣ�� �Է��ϼ���.>\n"); 	
	printf("\n�Է¿��� : 980315-2\n\n"); 
	printf("�ֹι�ȣ ���ڸ� �Է�: ");
	scanf("%d-%d", &id, &gender);
		
	//�ֹε�Ϲ�ȣ�� ���糪�� ����� ���� ������ 
	int century;	// 1900, 2000��� 
	int birthYearFull; //����⵵ 4�ڸ�
	
		//�ֹι�ȣ�� ��, ��, �Ϸ� ����
		birthYear = id / 10000;		// �ڷ����� int�� ��)950525 => 95.525 => 95 
		birthMonth = (id % 10000) / 100;	// ��)950525 => 525 /100 => 5.25 => 5 
		birthDay = id % 100;		//��)950525 => 9505.25 => 25 
	
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
		gap = (tm.tm_year+1900) - birthYearFull;
	
		//�� ����: birthMonth >= month �� ������ ������.
		if(birthMonth >= (tm.tm_mon+1) && birthDay >= (tm.tm_mday)){
			man = gap;
		} 
		else{
			man = gap -1;
		}
		
		//���� ����, �츮�� �ƴ� ���� 
		age = gap + 1 ;	
	

		//����
		char gender_print;
		
		if(gender == 1 && 3){			
			gender_print = 'M';
		} 
		if(gender == 2 && 4){
			gender_print = 'W';
		} 
			 
	//���̿� ���� �׷� ����
	const int ADULT = 1, YOUTH = 2, CHILD = 3, BABY = 4;
	
	//��� ����� ���� ������
	int regular_price;
	 
	/*
	� : �� 19���̻� ~ ��64������
	û�ҳ� : �� 13�� �̻� ~ �� 18�� ����
	��� : �� 3�� �̻� ~ �� 12�� ����
	�Ʊ� : �� 1�� �̻� ~ ��2�� ����
	��Ÿ : �� 1�� �̸��� ����
	*/

		//���ο�� : �� 19���̻� ~ ��64������
		if((ticket_type == 1 && ticket_time == 3 && man >= 19) && (ticket_type == 1 && ticket_time == 3) && man <= 64)
		{
			regular_price = ADULT_1DAY_PRICE;
		}
		
		if((ticket_type == 1 && ticket_time == 4 && man >= 19) && (ticket_type == 1 && ticket_time == 4) && man <= 64)
		{
			regular_price = ADULT_A4_PRICE;
		}
		
		if((ticket_type == 2 && ticket_time == 3 && man >= 19) && (ticket_type == 2 && ticket_time == 3) && man <= 64)
		{
			regular_price = ADULT_1DAY_MPRICE;
		}
	
		if((ticket_type == 2 && ticket_time == 4 && man >= 19) && (ticket_type == 2 && ticket_time == 4) && man <= 64)
		{
			regular_price = ADULT_A4_MPRICE;
		}	
	
		//û�ҳ��� : �� 13�� �̻� ~ �� 18�� ����
		if((ticket_type == 1 && ticket_time == 3 && man >= 13) && (ticket_type == 1 && ticket_time == 3 && man <= 18))
		{
			regular_price = YOUTH_1DAY_PRICE;
		}
		
		if((ticket_type == 1 && ticket_time == 4 && man >= 13) && (ticket_type == 1 && ticket_time == 4 && man <= 18))
		{
			regular_price = YOUTH_A4_PRICE;
		}
		
		if((ticket_type == 2 && ticket_time == 3 && man >= 13) && (ticket_type == 2 && ticket_time == 3 && man <= 18))
		{
			regular_price = YOUTH_1DAY_MPRICE;
		}
	
		if((ticket_type == 2 && ticket_time == 4 && man >= 13) && (ticket_type == 2 && ticket_time == 4 && man <= 18))
		{
			regular_price = YOUTH_A4_MPRICE;
		}	
					 		 
		 //��̿�� : �� 3�� �̻� ~ �� 12�� ����
		if((ticket_type == 1 && ticket_time == 3 && man >= 3) && (ticket_type == 1 && ticket_time == 3 && man <= 12))
		{
			regular_price = CHILD_1DAY_PRICE;
		}
		
		if((ticket_type == 1 && ticket_time == 4 && man >= 3) && (ticket_type == 1 && ticket_time == 4 && man <= 12))
		{
			regular_price = CHILD_A4_PRICE;
		}
		
		if((ticket_type == 2 && ticket_time == 3 && man >= 3) && (ticket_type == 2 && ticket_time == 3 && man <= 12))
		{
			regular_price = CHILD_1DAY_MPRICE;
		}
	
		if((ticket_type == 2 && ticket_time == 4 && man >= 3) && (ticket_type == 2 && ticket_time == 4 && man <= 12))
		{
			regular_price = CHILD_A4_MPRICE;
		}	 		 
		 
		 //�Ʊ� ��� : �� 1�� �̻� ~ ��2�� ����	 
		if((ticket_type == 1 && ticket_time == 3 && man >= 1) && (ticket_type == 1 && ticket_time == 3 && man <= 2))
		{
			regular_price = BABY_1DAY_PRICE;
		}
		
		if((ticket_type == 1 && ticket_time == 4 && man >= 1) && (ticket_type == 1 && ticket_time == 4 && man <= 2))
		{
			regular_price = BABY_A4_PRICE;
		}
		
		if((ticket_type == 2 && ticket_time == 3 && man >= 1) && (ticket_type == 2 && ticket_time == 3 && man <= 2))
		{
			regular_price = BABY_1DAY_MPRICE;
		}
	
		if((ticket_type == 2 && ticket_time == 4 && man >= 1) && (ticket_type == 2 && ticket_time == 4 && man <= 2))
		{
			regular_price = BABY_A4_MPRICE;
		}			 	 	 		 

		//��Ÿ: �� 1�� �̸��� ���� 
		if(man < 1) 
		{
			regular_price = 0;
		}	  	
					
	//Ƽ�� �ż� Ȯ�� (Ƽ���� 10�ű����� ���Ű���) 
	int ticket_volume;
	 
	printf("\n\n");			
	printf("=====================================================\n\n");
	printf("<�����Ϸ��� �ż��� �Է��ϼ���.>\n"); 
	printf("Ƽ���� �ִ� 10�ű��� ������ �� �ֽ��ϴ�.\n");	
	printf("\n�Է¿��� : 2��\n\n"); 
	printf("�ż� �Է�: ");
	scanf("%d", &ticket_volume);			
	
	for(int i = 1; i <= 10; i++)
	{
		if(ticket_volume<=10)
		{
			printf("%d�Ÿ� �Է��߽��ϴ�.", ticket_volume);
			break;	
		}
		else
		{
			printf("<!>Ƽ���� �ִ� 10������� ���Ű����մϴ�.\n");
			break;
		}
	 } 
	
	//������� Ȯ�� �� ������� 
	int benefit;
	int discounted; //��������� Ƽ�� ���� _ ������. 
	int last_price; // ���ΰ� * �ż� 
	
	printf("\n\n");			
	printf("=====================================================\n\n");
	printf("<�������� �����ϼ���.>\n"); 
	printf("*���̿� ���� ���� �ڵ�����˴ϴ�.\n"); 
	printf("*�����̿��/�������̿�� ����� \n");
	printf("\t=> �����, ����������, �ް��庴\n");
	printf("*�����̿�� ����� \n");
	printf("\t=> �ӻ��, �ٵ��� �ູī�� ������\n\n");
	printf("\n---------------------------------------------------\n\n");
	printf("<��� ����>");
	printf("\n1.����� ���\n2.���������� ���\n3.�ް��庴���\n4.�ӻ�ο��\n5.�ٵ����ູī�� ���\n6.�ش����");	
	printf("\n\n�Է¿��� : 3\n\n"); 
	printf("��� ���� ��ȣ: ");
	scanf("%d", &benefit);	 
	
			 	
	//Ƽ�� �������� : ��밡, �ż� ���� 
	//�����, ����������, �ް��庴�� ���� 1�� ���� ���	
	for(int i = 1; i <= ticket_volume; i++)
	{
		//�����, ���������� [����, ������] Ƽ�� ��� 50%������ Ƽ�� ������
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
		
		//�ް��庴 �����̿�Ǹ� ���� 1�� ���� ��� 49% ������ Ƽ�� ������
		//Ƽ�� ������ 1000�� ���� 
		if(benefit == 3 && ticket_type == 1)
		{
			//discounted = regular_price * 0.51;
			switch(ticket_volume)	
			{
				case 1:
					last_price = ((regular_price * 51) / 10000) *100;	//1000���̸� ���� 
					break;					
				case 2:
					last_price = (((regular_price * 51) / 10000) *100) * 2;
					break;																	
				case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
					last_price = (((regular_price * 51) / 10000) *100) * 2 + (regular_price * (i - 2));						
					break;										
			}
		}
	
		//�ӻ�� �����̿�Ǹ� ���� ��� 50% ������ Ƽ�� ������
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
		
		//�ٵ���ī�� ��ϵ� ���θ� �����̿�Ǹ� ��� 30% ������ Ƽ�� ������ 
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
				
		 //��� �������� ��� Ƽ�� ������		
		if(benefit == 6 || benefit == 3 && ticket_type == 2 || benefit == 4 && ticket_type == 2 || benefit == 5 && ticket_type == 2)
		{
			last_price = regular_price * i;
		}		
	 } 

	printf("\n\n");			
	printf("=====================================================\n\n");
	printf("%s\n\n","<��������>");
	printf("���� ���� ������ %d�� �Դϴ�.\n\n", last_price);
	
	//������ 
	printf("=====================================================\n\n");	
	printf("********************* Thank you **********************\n\n");	
	printf("%34s %d-%d-%d %d:%d:%d\n\n", "Now :",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);	
				
	return 0;
} 	
