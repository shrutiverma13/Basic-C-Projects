#include <stdio.h>
#include <stdlib.h>

int yearnum;
int leapyr(yr){
  if (yr%400 == 0 || (yr%100 !=0 && yr%4 == 0)) return 1;
  else return 0;
}
int mnlen(int m,int yr){
 if (m == 1 || m==3 || m==5 || m== 7 || m==8 || m==10 || m==12) return 31;
else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
else if (m == 2){
if (leapyr(yr)){ return 29;
}
else return 28;}
else return 0;
}
void daynum(int val){
char *days[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
printf("%s",days[val]);
}
int dayitis(int date,int mn,int year){
  int y1,y2,cd;
int r[13]={0,1,4,4,0,2,5,0,3,6,1,4,6};
int w[4]={4,2,0,6};
y1=year/100; y2=year%100; cd=y1-17;
 yearnum=(y2/4)+date+r[mn];
 if (leapyr(year) && mn<3) yearnum-=1;
yearnum+=w[cd]+y2;
yearnum%=7; 
return yearnum;
}

void printcal(m,year){
   int dn,x,cnt,y;
   dn=dayitis(01,m,year);
   int m_num;//= mnlen(m,year);
   if (m == 1 || m==3 || m==5 || m== 7 || m==8 || m==10 || m==12) m_num = 31;
else if (m == 4 || m == 6 || m == 9 || m == 11) m_num = 30;
else if (m == 2){
if (leapyr(year)){ m_num = 29;
}
else m_num = 28;}
char *months[12] ={"January","Feburary","March","April","May","June","July","August","September","October","November","December"};
  printf("\n\n");
  printf("   -------------------------\n");
  printf("           %s,%d\n",months[m-1],year);
  printf("   --------------------------\n");
 printf("   S   M   T   W   T   F   S\n");
switch(dn){ //locates the starting day in calender
        case 1 :
            printf("");
            cnt=1;
            break;
        case 2 :
           printf("    ");
            cnt=2;
            break;
        case 3 :
            printf("        ");
            cnt=3;
            break;
        case 4:
            printf("            ");
            cnt=4;
            break;
        case 5:
            printf("                ");
            cnt=5;
            break;
        case 6 :
            printf("                    ");
            cnt=6;
            break;
        case 0 :
             printf("                        ");
            cnt=7;
            break;
        default :
            printf("INVALID DATA ");
    } 
for(int i=1;i<=m_num;i++){
  if( cnt == 7){
    printf("  %02d\n",i++); cnt++;
   
  }
  else if (cnt%7 == 0){
   printf("  %02d\n",i++); cnt++;
   
  }
  if (i <= m_num) 
   {printf("  %02d",i);
  cnt++;}
}
}
int incmonth(int *m,int *yr){
  if (*m == 12) {*yr+=1; return 1;}
  else return *m+1;
}
int decmonth(int *m,int *yr){
  if (*m == 1){ *yr-=1; return 12;}
  else return *m-1;
}
void printmenu(){
 printf("For finding what day it is    1\n");
 printf("For going to the calendar     2\n");
 printf("To exit                       3\n");
 
}
int getnum(void)
{
 int x;

  printf("Enter choice: ");
  scanf("%d", &x);
  return x;
}

int main(void) {
  int d,m,yr,chc,c1;
  char c;
printmenu();
 chc=getnum();

 if(chc == 1) {
   printf("enter the date in DD MM YYYY format: \n");
   scanf("%d %d %d",&d,&m,&yr);
    int r=dayitis(d,m,yr);
    printf("\n\nThe day is "); daynum(r) ;
 }
 else if (chc == 2){
   printf("Enter the month and the year in MM YYYY format ");
   scanf("%d %d",&m,&yr); 
   printcal(m,yr);
 
 do{printf("\n\n\nPress 1 for next calendar, 2 for previous and 3 for exit\n");
scanf("%d",&c1);
 if (c1 == 1){
m=incmonth(&m,&yr);
printcal(m,yr);}
 
 else if(c1==2){
   m=decmonth(&m,&yr);
   printcal(m,yr);}
}while (c1 != 3);
 }
return 0;
}