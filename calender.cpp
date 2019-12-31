#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<conio.h>
void chgcld(int *pyear,int *pmonth,int *pday,unsigned char command);// 通过键盘来改变日期的函数，传入的数据为 当前显示日期的指针和操作输入。 
void cheekcld(int *pyear,int *pmonth,int *pday);//用来指定日期查询日历的函数,传入的是当前显示日期的指针 。 
int leapyear(int year);//用来判断是否为闰年。 
void prtcalender(int year,int mon,int date);//将指定日期打印的函数 ，参数为日期。

void chgcld(int *pyear,int *pmonth,int *pday,unsigned char command){
		switch(command){
			case 75:	
				/*保证月份合法。*/ 
				system("cls");
				if(*pmonth==1){
					*pmonth=12;
					(*pyear)--;
				}
				else (*pmonth)--;
				if(*pyear==1899){
					printf("\n\t仅支持1900年及以后"); 
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
					printf("\n\t仅支持1900年及以后"); 
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
void prtcalender(int year,int mon,int date){/*打印指定日期的函数*/
	int alldays=0,yeardays,/*表示一年的天数*/
		monthdays,/*表示一个月的天数*/
		weekdays,/*表示该月第一天的星期*/
		days;/*表示该月的天数*/
	for(int i=1900;i<year;i++){
		if(leapyear(i))  yeardays=366;
		else  yeardays=365;
		alldays+=yeardays;
	}  /*到当前一年的天数*/
	/*到当月的前一个月的天数*/ 
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
		}/*用于判断月份的天数 */
		alldays+=monthdays;	
	}
	weekdays=(alldays)%7+1;/*计算当月一号是星期几。 因为1900年1月1日是星期1，模除7加上1就是当前的星期号*/
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
	}//计算该月的天数。 
	printf("\n\n");
	printf("\t\t\t %d 年 %d 月 \n\n\n\n",year,mon);	
	
	printf("\t周日\t周一\t周二\t周三\t周四\t周五\t周六\n\n");
	for(int i=1;i<=weekdays;i++){
		printf("\t");
	}/*打印前几天的空格，星期n就要打印星期n-1个空格*/ 
	for(int i=1,j=weekdays;i<=days;i++,j++){
		if(j%7==0&&j!=0) printf("\n\n");
		if(i==date) printf("\t%d *",i);
		else printf("\t%d",i);
	}
	if(leapyear(year)) {
			printf("\n\n\t\t\t     闰年"); 
		}
	else
		printf("\n\n\t\t\t     平年"); 
	printf("\n");
	//printf("**********************************************************************\n");
	printf("\n\t\t方向键改变年份及月份\n"); 
	printf("\t\t点击 a 查询日期") ;
	printf("\n\t\t点击 n 退出日历\n") ;
}

int leapyear(int year){/*判断某年是否是闰年*/
	if((year%4==0&&year%100!=0)||year%400==0){
		return 1;
	}
	else return 0;
}
void cheekcld(int *pyear,int *pmonth,int *pday){
	int year,month,day,
	flag=1;//用于记录输入是否有误。 
	printf("\n\t输入您要查找的日期(2023 5 4)：");
	scanf("%d%d%d",&year,&month,&day);
	fflush(stdin);
	do{
		while(year<1900){
			printf("\n\t只能查看1900年以后的日历,请重新输入日期：");
			scanf("%d%d%d",&year,&month,&day);
			fflush(stdin);
		}
		//检测日期的合法性，不合法则flag=0。 
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
		/*如果输入有误，则重输。*/ 
		if(!flag){
			printf("\n\t日期不合法，请重输：");
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
	unsigned char command;/*用来表示输入的操作*/
	time_t timenow;/*定义当前的时间戳*/
	struct tm *tmcamp;
	time(&timenow);/*获取当前的时间戳*/
	tmcamp=localtime(&timenow);/*将时间戳换算为本地时间，tmcamp为指向现在北京时间的指针*/ 
	int curdate=tmcamp->tm_mday;//获取日期 
	int curmon=tmcamp->tm_mon+1;//获取月份 
	int curyear=tmcamp->tm_year+1900;/*获取当前的年份*/ 
	int *pyear=&curyear,*pmonth=&curmon,*pday=&curdate;//建立日期指针，并初始化为当前日期。 
	prtcalender(curyear,curmon,curdate);//打印日历  
	do{
		fflush(stdin);
		command=getch();//获取操作码 
		if(command == 224/*判断是否有箭头操作*/ ){
			command = getch();/*如果是方向键则需在接受一次*/ 
			switch(command){
				case 72:/*向上箭头*/ chgcld(pyear,pmonth,pday,command); break;
				case 80:/*向下箭头*/ chgcld(pyear,pmonth,pday,command); break;
				case 75:/*向左键头*/ chgcld(pyear,pmonth,pday,command); break;
				case 77: /*向右箭头*/chgcld(pyear,pmonth,pday,command); break;		  
				default: printf("\n输入不合法请重新输入\n"); break;
			}
		}
		else{
			switch(command){
				case 'a':
				case 'A': cheekcld(pyear,pmonth,pday);/*跳转到指定日期的函数， 传入当前显示日期的指针，用于改变当前显示的日期。*/
						  break;
				case 'n':
				case 'N':exit(1);
				default: printf("\n\t输入有误请重新输入\n"); break;
			}
		}
	} while(1);//进行操作的循环结构。
	
	return 0;
}
