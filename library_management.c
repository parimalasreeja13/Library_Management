#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void addbooks(void);
void viewbooks(void);
void searchbooks(void);
void deletebooks(void);
void adregister(void);
struct book
{
 char bookid[10];
 char bookname[100];
 char author[100];
 char price[50];
}b;
struct admin
{ char adname[100];
  char username[100];
  char password[100];
}a;
void registration(void);
void login(void);
void retnbook(void);
int valid_date(int d,int m,int y);
void ex(void);
struct student
{
char stname[100];
char stlname[100];
int strollno;
char username[100];
char password[100];
}s1;
struct date{
char book[100];
char auther[100];
float cost;
char bookid[100];
int d1;
int m1;
int y1;
}d;
void main()
{
 int ch;
 system("CLS");
 printf("\n ***************************************************** ");
 printf("\n **          WELCOME TO LIBRARY MANAGEMENT          ** ");
 printf("\n **                     PROJECT                     ** ");
 printf("\n ***************************************************** \n");
 printf("\n **              PLEASE ENTER YOUR CHOICE           ** \n");
 printf("\n *                    1.Add books                    *   ");
 printf("\n *                    2.View books                   *   ");
 printf("\n *                    3.searchbook                   *   ");
 printf("\n *                    4.deletebooks                  *   ");
 printf("\n *                    5.student registration         *   ");
 printf("\n *                    6.student login and book taken *   ");
 printf("\n *                    7.return book                  *   ");
 printf("\n *                    8.admin registration           *   ");
 printf("\n *                    9.exit                         *   ");
 printf("\n ***************************************************** ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 system("CLS");
 addbooks();
 break;
 case 2:
 system("CLS");
 viewbooks();
 break;
 case 3:
 system("CLS");
 searchbooks();
 break;
 case 4:
 system("CLS");
 deletebooks();
 break;
 case 5:
 system("CLS");
 registration();
 break;
 case 6:
 system("CLS");
 login();
 break;
 case 7:
 system("CLS");
 retnbook();
 break;
 case 8:
 system("CLS");
 adregister();
 break;
 case 9: ex();
 default:
	 printf("wrong choice entered");
 }
 printf("\n press any key to continue");
 getch();
}

void addbooks()
{  int key=0;
char username[100];
char password[100];
 FILE *fp,*t;
 t=fopen("register.txt","a+");
 if(t==NULL)
 {printf("error");
  exit(1);
  }
  printf("\nEnetr your login credentials");
  printf("\nEnter user name:");
  scanf("%s",&username);
  printf("\n enter password:");
  scanf("%s",&password);
 while(fread(&a,sizeof(struct admin),1,t)>0 && key==0)
 if(strcmp(username,a.username)==0 &&strcmp(password,a.password)==0)
 { key=1;
 char ch='y';

 fp=fopen("book2.txt","ab+");
 if(fp==NULL)
 {
 printf("cannot open file");
 return;
 }
 printf("\n\n PREVIOUS STORED DATA ");
 viewbooks();
 while(ch=='y'){
 printf("\n\n\n Enter new book data");
 printf("\n\n Enter book id: ");
 scanf("%s",&b.bookid);
 fflush(stdin);
 printf("\n Enter book name: ");
 gets(b.bookname);
 printf("\n Enter author name: ");
 gets(b.author);
 printf("\n Enter price: ");
 gets(b.price);
 fwrite(&b,sizeof(struct book),1,fp);
 {
 printf("\n\n Data stored successfully ");
 }
 printf("\nDo you add another record(y/n)");
 ch=getch();
 }
}
if(key==0)
{ printf("\n incorrect login details");}
 fclose(fp);
 fclose(t);
 viewbooks();
}
void viewbooks()
{
 FILE *fp;
 fp=fopen("book2.txt","rb");
 if(fp==NULL)
 {
 printf("Cannot open file");
 return;
 }
 printf("\nBook id \t   Book Name \t     Author \t    Price\n\n");
 while(fread(&b,sizeof(struct book),1,fp)==1)
 {

printf("\n%s\t\t%s\t\t%s\t\t%s\n\n",b.bookid,b.bookname,b.author,b.price);
 }
 fclose(fp);

}

void searchbooks()
{
 char num[100];
 FILE *fp;
 fp=fopen("book2.txt","a+");
 if(fp==NULL)
 {
 printf("Cannot open file");
 return;
}
 printf("Enter id of the book to be searched: ");
 scanf("%s",&num);
 int flag=0;
 while(fread(&b,sizeof(struct book),1,fp)>0 && flag==0){
 if(strcmp(b.bookid,num)==0)
 {
 flag=1;
 printf("Search successful and search data is as follows");
 printf("\nBook id\tBook Name\tAuthor\tPrice\n");
printf("n%s\t\t%s\t\t%s\t\t%s\n\n",b.bookid,b.bookname,b.author,b.price);
 } }
 if(flag==0)
 {
 printf("\n\n No such record found ");
 }
 fclose(fp);

 }
void deletebooks()
{ int k=0;
char username[100];
char password[100];
FILE *t;
t=fopen("register.txt","a+");
if(t==NULL)
{printf("Error");
exit(1);
}
printf("\nEnter your login credentls");
printf("\nEnetr user name:");
scanf("%s",&username);
printf("\nEnter password:");
scanf("%s",&password);
while(fread(&a,sizeof(struct admin),1,t)>0 && k==0)
if(strcmp(username,a.username)==0 && strcmp(password,a.password)==0)
{ k=1;

 char id[10];
 int flag=0;
 FILE *fp ,*ft;
 fp=fopen("book2.txt","r");
 ft=fopen("book3.txt","a+");
 if(fp==NULL)
 {
 printf("Cannot open file");
 return; }
 printf("\n\n PREVIOUS ATORED DATA ");
 viewbooks();
 printf("\n\n Enter id of the book which is to be deleted ");
 scanf("%s",&id);
 while(fread(&b,sizeof(b),1,fp)==1)
 {
 if(strcmp(id,b.bookid)!=0)
 {
 printf("\n\n\t\t Record deleted successfully");
 fwrite(&b,sizeof(b),1,ft);
 }
 else
 {   flag=1;

 }
 }
 if(flag==0)
 {
 printf("\n\n No such record found");
 }
 fclose(fp);
 fclose(ft);
 remove("book2.txt");
 rename("book3.txt","book2.txt");
 printf("\n\n\t\t Updated record");
 viewbooks();
 }
 if(k==0)
 {printf("\n incorrect login details");
 }
 fclose(t);
 }
 void adregister()
 { FILE *t;
 t=fopen("register.txt","a+");
 if(t==NULL)
 {printf("ERROR");
  exit(1);
  }
  printf("\nEnter admin name:");
  fflush(stdin);
  scanf("%s",&a.adname);
  printf("\nenter user name:");
  scanf("%s",&a.username);
  printf("\nEnter password:");
  scanf("%s",&a.password);
  fwrite(&a,sizeof(struct admin),1,t);
  fclose(t);
  getch();
  }

int valid_date(int d,int m,int y)
{
int is_valid=1,is_leap=0;
if(y>=1800&&y<=9999)
{
  if((y%4==0 &&y%100!=0)||(y%400==0))
  { is_leap=1;
  }
  if(m>=1&&m<=12)
  {  if(m==2)
    {
     if(is_leap &&d==29)
     {
     is_valid=1;
     }
     else if(d>28)
     { is_valid=0;
     }
    }
    else if(m==4||m==6||m==9||m==11)
    {
     if(d>30)
     { is_valid=0;
     }
    }
    else if(d>31)
    {
     is_valid=0;
    }
  }
  else
  { is_valid=0;
  }
}
else
{ is_valid=0;
}
return is_valid;
}
void retnbook()
{  int flag=0;
 char username[100];
  char password[100];
 // char book[100];
 char boid[100];
  int d2,m2,y2;
  int d_diff,m_diff,y_diff;
  FILE *p,*pf;
  p=fopen("project2.txt","a+");
  if(p==NULL)
  { printf("error");
  exit(1);
  }
  printf("Enter login crediantials");
  printf("\nusername:\n");
  scanf("%s",&username);
  printf("\npassword:\n");
  scanf("%s",&password);
  while(fread(&s1,sizeof(struct student),1,p)>0 && flag==0)
  if(strcmp(username,s1.username)==0&&strcmp(password,s1.password)==0)
  {  flag=1;
  printf("\n successfull login\n");
    FILE *pf;
    pf=fopen("project3.txt","rb");
    if(pf==NULL)
    {printf("RERROR");
    exit(1);
    }
      printf("\nEnter book details of returning book");
      printf("\nEnter book id:");
      scanf("%s",&boid);
      printf("Enter remaining details");
      printf("\nEnter book returning date(DD/MM/YYYY):");
      scanf("%d/%d/%d",&d2,&m2,&y2);
      if(!valid_date(d2,m2,y2))
      { printf("return date is invalid\n");
       exit(0);
      }
	 int found=0;
     while(fread(&d,sizeof(struct date),1,pf)>0 && found==0)
      if(strcmp(boid,d.bookid)==0)
      {  found=1;
      printf("Taken and Given book is same:\n");
 if(d2<d.d1)
{
  if( m2==3)
  {
   if((y2%4==0&&y2%100!=0)||(y2%400==0))
   { d2+=29;
   }
   else
   {d2+=28;
   }
  }
  else if(m2==5||m2==7||m2==10||m2==12)
  { d2+=30;
  }
  else
  {d2+=31;
  }
  m2=m2-1;
}
if(m2<d.m1)
{m2+=12;
y2-=1;
}
d_diff=d2-d.d1;
m_diff=m2-d.m1;
y_diff=y2-d.y1;
printf("\ndifference:%dy %02dm  %02dd",y_diff,m_diff,d_diff);
if((y_diff>0||m_diff>0)|| d_diff>15)
 {
	 printf("\nover date");
	 printf("\npay fine of 20 rupees");


 }
 else
 {printf("book returned in time");}

      }
      if(found==0)
      { printf("not same");
      }

  }
  if(flag==0)
  { printf("\n incorect login details\n");
  }
  fclose(p);
  fclose(pf);
getch();
system("CLS");
  }
void login()
{    int flag=0;
 char username[30];
     char password[20];
     FILE *p,*pf;
     p=fopen("project2.txt","a+");
     if(p==NULL)
     { printf("Error");
       exit(1);
     }
     printf("please enter your login credentials");
     printf("\nusername:\n");
     scanf("%s",&username);
     printf("\npassword:\n ");
     printf("\n");
     scanf("%s",&password);
     while(fread(&s1,sizeof(struct student),1,p)>0 && flag==0)
     if(strcmp(username,s1.username)==0&& strcmp(password,s1.password)==0)
	 {     flag=1;
	 printf("\nsuccessful login\n");
	 FILE *pf;
	 pf=fopen("project3.txt","ab");
	 if(pf==NULL)
	 { printf("ERROR");
	  exit(1);
	  } int z=0;
	  char c='y';
	  while(c=='y'){
	 printf("\nEnters book details:");
	 printf("\nenter book name:");
	 fflush(stdin);
	 scanf("%s",&d.book);
	 printf("\nEnter auther name:");
	 scanf("%s",&d.auther);
	 printf("\nEnter book cost:");
	 scanf( "%d",&d.cost);
	 printf("Enter book id");
	 fflush(stdin);
	 scanf("%s",&d.bookid);
	 //fflush(stdin);
	while(z==0){
	 printf("\nEnter date(DD/MM/YY)\n");
	 scanf("%d/%d/%d",&d.d1,&d.m1,&d.y1);
	 if(!valid_date(d.d1,d.m1,d.y1))
	 { printf("taken date is invalid");
	 }
	 z=z+1;}
	 fwrite(&d,sizeof(struct date),1,pf);
	 printf("do you want to take another book(y/n)");
	 c=getch();
	 }

	}
	 if(flag==0)
	{
	printf("\n Incorrect Login DEtails\n");
	}

     fclose(p);
     fclose(pf);
   //  getch();
     system("CLS");
     }
void registration()
{

FILE *p;
char ch='y';
p=fopen("project2.txt","a+");
if(p==NULL)
{ printf("Error");
  exit(1);
  }
while(ch=='y'){
printf("Enter student first name : \n");
fflush(stdin);
scanf("%s",&s1.stname);
printf("Enter students surname: \n");
scanf("%s",&s1.stlname);
printf("Now please select a user name and password\n");
printf("\nEnter user name:\n");
scanf("%s",&s1.username);
printf("\n");
printf("Enter password:\n");
scanf("%s",&s1.password);
fwrite(&s1,sizeof(struct student),1,p);
printf("Enter another recora(y/n)\n");
ch=getch();
}
fclose(p);
getch();
system("CLS");
}
void ex()
{ exit(1);
}
