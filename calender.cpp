#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<conio.h>
void chgcld(int *pyear,int *pmonth,int *pday,unsigned char command);// ͨ���������ı����ڵĺ��������������Ϊ ��ǰ��ʾ���ڵ�ָ��Ͳ������롣 
void cheekcld(int *pyear,int *pmonth,int *pday);//����ָ�����ڲ�ѯ�����ĺ���,������ǵ�ǰ��ʾ���ڵ�ָ�� �� 
int leapyear(int year);//�����ж��Ƿ�Ϊ���ꡣ 
void prtcalender(int year,int mon,int date);//��ָ�����ڴ�ӡ�ĺ��� ������Ϊ���ڡ�

void chgcld(int *pyear,int *pmonth,int *pday,unsigned char command){
		switch(command){
			case 75:	
				/*��֤�·ݺϷ���*/ 
				system("cls");
				if(*pmonth==1){
					*pmonth=12;
					(*pyear)--;
				}
				else (*pmonth)--;
				if(*pyear==1899){
					printf("\n\t��֧��1900�꼰�Ժ�"); 
					(*pyear)++;
					*pmonth=1;
				}
				prtcalender(*pyear,*pmonth,0);
				break;
			case 77:
				if(*pmonth==12){
					*pmonth=1;
					(*pyear)++;
				}
				else (*pmonth)++;
				system("cls");
				prtcalender(*pyear,*pmonth,0);
				break;
			case 72:
				system("cls");
				if(*pyear==1900){
					printf("\n\t��֧��1900�꼰�Ժ�"); 
				}
				else (*pyear)--;
				prtcalender(*pyear,*pmonth,0);
				break;
			case 80:
				(*pyear)++;
				system("cls");
				prtcalender(*pyear,*pmonth,0);
				break;
		}
}
void prtcalender(int year,int mon,int date){/*��ӡָ�����ڵĺ���*/
	int alldays=0,yeardays,/*��ʾһ�������*/
		monthdays,/*��ʾһ���µ�����*/
		weekdays,/*��ʾ���µ�һ�������*/
		days;/*��ʾ���µ�����*/
	for(int i=1900;i<year;i++){
		if(leapyear(i))  yeardays=366;
		else  yeardays=365;
		alldays+=yeardays;
	}  /*����ǰһ�������*/
	/*�����µ�ǰһ���µ�����*/ 
	for(int i=1;i<mon;i++){
		switch(i){
			case 1:monthdays=31;break;
			case 3:monthdays=31;break;
			case 5:monthdays=31;break;
			case 7:monthdays=31;break;
			case 8:monthdays=31;break;
			case 10:monthdays=31;break;
			case 12: monthdays=31;break;
			case 2: if(leapyear(year)) monthdays=29;
					else monthdays=28;
					break;
			default: monthdays=30;break;
		}/*�����ж��·ݵ����� */
		alldays+=monthdays;	
	}
	weekdays=(alldays)%7+1;/*���㵱��һ�������ڼ��� ��Ϊ1900��1��1��������1��ģ��7����1���ǵ�ǰ�����ں�*/
	switch(mon){
			case 1:days=31;break;
			case 3:days=31;break;
			case 5:days=31;break;
			case 7:days=31;break;
			case 8:days=31;break;
			case 10:days=31;break;
			case 12: days=31;break;
			case 2: if(leapyear(year)) days=29;
					else days=28;
					break;
			default: days=30;break;
	}//������µ������� 
	printf("\n\n");
	printf("\t\t\t %d �� %d �� \n\n\n\n",year,mon);	
	
	printf("\t����\t��һ\t�ܶ�\t����\t����\t����\t����\n\n");
	for(int i=1;i<=weekdays;i++){
		printf("\t");
	}/*��ӡǰ����Ŀո�����n��Ҫ��ӡ����n-1���ո�*/ 
	for(int i=1,j=weekdays;i<=days;i++,j++){
		if(j%7==0&&j!=0) printf("\n\n");
		if(i==date) printf("\t%d *",i);
		else printf("\t%d",i);
	}
	if(leapyear(year)) {
			printf("\n\n\t\t\t     ����"); 
		}
	else
		printf("\n\n\t\t\t     ƽ��"); 
	printf("\n");
	//printf("**********************************************************************\n");
	printf("\n\t\t������ı���ݼ��·�\n"); 
	printf("\t\t��� a ��ѯ����") ;
	printf("\n\t\t��� n �˳�����\n") ;
}

int leapyear(int year){/*�ж�ĳ���Ƿ�������*/
	if((year%4==0&&year%100!=0)||year%400==0){
		return 1;
	}
	else return 0;
}
void cheekcld(int *pyear,int *pmonth,int *pday){
	int year,month,day,
	flag=1;//���ڼ�¼�����Ƿ����� 
	printf("\n\t������Ҫ���ҵ�����(2023 5 4)��");
	scanf("%d%d%d",&year,&month,&day);
	fflush(stdin);
	do{
		while(year<1900){
			printf("\n\tֻ�ܲ鿴1900���Ժ������,�������������ڣ�");
			scanf("%d%d%d",&year,&month,&day);
			fflush(stdin);
		}
		//������ڵĺϷ��ԣ����Ϸ���flag=0�� 
		switch(month){
			case 1:
				 if(day>31||day<1)
				flag=0;
				break;
			case 3:
				 if(day>31||day<1)
				flag=0;
				break;
			case 5:
				 if(day>31||day<1)
				flag=0;
				break;
			case 7:
				 if(day>31||day<1)
				flag=0;
				break;
			case 8:
				 if(day>31||day<1)
				flag=0;
				break;
			case 10:
				 if(day>31||day<1)
				flag=0;
				break;
			case 12: 
				 if(day>31||day<1)
				flag=0;
				break;
			case 2: if(leapyear(year)) {
						if(day>29||day<1)
						flag=0;
					}
					else{
						if(day>28||day<1)
						flag=0;
					}
					break;
			case 4:
				 if(day>30||day<1)
				flag=0;
				break;
			case 6:
				 if(day>30||day<1)
				flag=0;
				break;
			case 9:
				 if(day>30||day<1)
				flag=0;
				break;
			case 11: 
				 if(day>30||day<1)
				flag=0;
				break;
			default: flag=0;break;	
		}
		/*����������������䡣*/ 
		if(!flag){
			printf("\n\t���ڲ��Ϸ��������䣺");
			scanf("%d%d%d",&year,&month,&day);
			fflush(stdin);
			flag=1;
		}
		else
			break;
	}while(1);
	*pyear=year;
	*pmonth=month;
	*pday=day; 
	system("cls");
	prtcalender(year,month,day);
}

int main() {
	unsigned char command;/*������ʾ����Ĳ���*/
	time_t timenow;/*���嵱ǰ��ʱ���*/
	struct tm *tmcamp;
	time(&timenow);/*��ȡ��ǰ��ʱ���*/
	tmcamp=localtime(&timenow);/*��ʱ�������Ϊ����ʱ�䣬tmcampΪָ�����ڱ���ʱ���ָ��*/ 
	int curdate=tmcamp->tm_mday;//��ȡ���� 
	int curmon=tmcamp->tm_mon+1;//��ȡ�·� 
	int curyear=tmcamp->tm_year+1900;/*��ȡ��ǰ�����*/ 
	int *pyear=&curyear,*pmonth=&curmon,*pday=&curdate;//��������ָ�룬����ʼ��Ϊ��ǰ���ڡ� 
	prtcalender(curyear,curmon,curdate);//��ӡ����  
	do{
		fflush(stdin);
		command=getch();//��ȡ������ 
		if(command == 224/*�ж��Ƿ��м�ͷ����*/ ){
			command = getch();/*����Ƿ���������ڽ���һ��*/ 
			switch(command){
				case 72:/*���ϼ�ͷ*/ chgcld(pyear,pmonth,pday,command); break;
				case 80:/*���¼�ͷ*/ chgcld(pyear,pmonth,pday,command); break;
				case 75:/*�����ͷ*/ chgcld(pyear,pmonth,pday,command); break;
				case 77: /*���Ҽ�ͷ*/chgcld(pyear,pmonth,pday,command); break;		  
				default: printf("\n���벻�Ϸ�����������\n"); break;
			}
		}
		else{
			switch(command){
				case 'a':
				case 'A': cheekcld(pyear,pmonth,pday);/*��ת��ָ�����ڵĺ����� ���뵱ǰ��ʾ���ڵ�ָ�룬���ڸı䵱ǰ��ʾ�����ڡ�*/
						  break;
				case 'n':
				case 'N':exit(1);
				default: printf("\n\t������������������\n"); break;
			}
		}
	} while(1);//���в�����ѭ���ṹ��
	
	return 0;
}
