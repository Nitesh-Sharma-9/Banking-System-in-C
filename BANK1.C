#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include"A2.c"
#include"line.c"
void transaction();
void fsave(long,char *,long,char *,char *);
int exist(long);
long actno();
void upbal(long,char *,long,char *,char *,long);
int deposit(long ) ;
int recno(long);
void enquiry(long);

int f,f1,chd,chw,f2=0;
long acid,eamt,eacnt;
long  exbal,updbal,updbal1,dacn,wacn,wamt,eacnt;
long cno;
int ch1,ch2;


char name2[30];
char address2[50];
long phone2;
char date2[20];
long acn2;
long upbal2;

int i=1001;

struct bank
{
   char name[30];
   char address[50];
   long phone;
   char date[20];
   long acn;
  long ubal;
}b;


void main()
{

  FILE *fp;
   int i,j=0,a[5],b1[5],c[5],d[10],e[10],p=0,q=0,s,s1,s2,i1;
   long t,t1;
   long balance,ac;
   char name1[30];
   char dis[]="Welcome to International Bank";
   long amt;
   long phon;
   char cname[30];
   char caddr[50];
   char sdate[20];
   int opt1,opt2,opt3,h,cid;
   gmain();
   textcolor(15);
   textbackground(BLUE);
   clrscr();
   printf("\n\n\n\n\n\n\n\n\n                       ");
     // gotoxy(150,1000);
   for(i=0;i<=strlen(dis);i++)
   {
    printf("%c",dis[i]);
     delay(100);
   }
   delay(2000);
   textcolor(15);
   clrscr();
   fp=fopen("actnof.txt","r");
   if(fp==NULL)
   {
      cno=1001;
   }
   else
   {
       cno=getw(fp);
       cno++;
   }
   fclose(fp);
   do{
   well:
   clrscr();
   lmain();
   outtextxy(140,100,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\n");
   outtextxy(140,120,"           INTERNATIONAL BANK"); printf("\n");
   outtextxy(140,140,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\n");
   outtextxy(140,160,"               WELCOME");printf("\n");
   outtextxy(140,180,"      ----------------------------");printf("\n");
   outtextxy(140,200,"      New Customer...............1");printf("\n");
   outtextxy(140,220,"      Existing Customer..........2");printf("\n");
   outtextxy(140,240,"      Exit.......................3");printf("\n");
   outtextxy(140,260,"      ----------------------------");printf("\n");
   outtextxy(140,280,"      Option:");
    fflush(stdin);
   scanf("%d",&opt1);
   h=opt1;
   if(h<=0)
   {
      printf("\nWrong option");
      getch();
      goto well;
   }
   switch(opt1)
   {
     case 3:
     exit(1);
     case 1:
       DATE:
       clrscr();
       j=0;
       p=0;
       q=0;
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("        INTERNATIONAL BANK\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("           NEW CUSTOMER\n");
       printf("           ~~~~~~~~~~~~\n");
       printf("AC/NO:%ld",cno);
       printf("\nName:");
       fflush(stdin);
       gets(cname);
       printf("Address:");
       gets(caddr);
       fflush(stdin);
       printf("Date(dd/mm/yyyy):");
       gets(sdate);
       for(i=0;i<strlen(sdate);i++)
       {
	 if(sdate[i]<47 || sdate[i]>57)
	 {
	    printf("\nDate format is wrong\n");
	    getch();
	    sdate[0]='\0';
	    goto DATE;
	 }
       }

       for(i=0;i<strlen(sdate);i++)
       {

	    if(sdate[i]==48)
	    a[j]=0;
	    if(sdate[i]==49)
	    a[j]=1;
	    if(sdate[i]==50)
	    a[j]=2;
	    if(sdate[i]==51)
	    a[j]=3;
	    if(sdate[i]==52)
	    a[j]=4;
	    if(sdate[i]==53)
	    a[j]=5;
	    if(sdate[i]==54)
	    a[j]=6;
	    if(sdate[i]==55)
	    a[j]=7;
	    if(sdate[i]==56)
	    a[j]=8;
	    if (sdate[i]==57)
	    a[j]=9;
	    j++;
	    if(j==2)
	    {

	       for(i1=0;i1<2;i1++)
	       {
		 if(i1==0)
		  s=a[i1]*10;
		 else
		 s=s+a[i1];
	       }
	       if(s==0)
		 {
		    printf("\nDate format is wrong\n");
		    getch();
		    sdate[0]='\0';
		    goto DATE;
		 }
	       if(s<0 || s>31)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 sdate[0]='\0';
		 goto DATE;
	       }

	      break;

	    }
       }
       if(j<=1)
       {
	   printf("\nDate format is wrong\n");
	   getch();
	   sdate[0]='\0';
	   goto DATE;
       }

       for(i=j+1;i<strlen(sdate);i++)
       {
	     if(sdate[i]==48)
	    b1[p]=0;
	    if(sdate[i]==49)
	    b1[p]=1;
	    if(sdate[i]==50)
	    b1[p]=2;
	    if(sdate[i]==51)
	    b1[p]=3;
	    if(sdate[i]==52)
	    b1[p]=4;
	    if(sdate[i]==53)
	    b1[p]=5;
	    if(sdate[i]==54)
	    b1[p]=6;
	    if(sdate[i]==55)
	    b1[p]=7;
	    if(sdate[i]==56)
	    b1[p]=8;
	    if (sdate[i]==57)
	    b1[p]=9;
	    p++;
	    if(p==2)
	    {
	       for(i1=0;i1<2;i1++)
	       {
		 if(i1==0)
		  s1=b1[i1]*10;
		 else
		 s1=s1+b1[i1];
	       }
	       if(s1==0)
		 {
		    printf("\nDate format is wrong\n");
		    getch();
		    sdate[0]='\0';
		    goto DATE;
		 }
	       if(s1<0 || s1>12)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 sdate[0]='\0';
		 goto DATE;
	       }

	       if(s1==4 || s1==6 || s1==9 || s1==11 )
	       {
		  if(s>30)
		  {
		    printf("\nDate format is wrong\n");
		    getch();
		    sdate[0]='\0';
		    goto DATE;
		  }

	       }
	      break;
	    }
       }
       if(p<=1)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    sdate[0]='\0';
	    goto DATE;
       }
       for(i=(j+p+2);i<strlen(sdate);i++)
       {
	    if(sdate[i]==48)
	    c[q]=0;
	    if(sdate[i]==49)
	    c[q]=1;
	    if(sdate[i]==50)
	    c[q]=2;
	    if(sdate[i]==51)
	    c[q]=3;
	    if(sdate[i]==52)
	    c[q]=4;
	    if(sdate[i]==53)
	    c[q]=5;
	    if(sdate[i]==54)
	    c[q]=6;
	    if(sdate[i]==55)
	    c[q]=7;
	    if(sdate[i]==56)
	    c[q]=8;
	    if (sdate[i]==57)
	    c[q]=9;
	    q++;
	    if(q==4)
	    {
		 for(i1=0;i1<4;i1++)
	       {
		 if(i1==0)
		 s2=c[i1]*10;
		 if(i1==1)
		 s2=s2*10+c[i1]*10;
		 if(i1==2)
		 s2=s2*10+c[i1]*10;
		 if(i1==3)
		 s2=s2+c[i1];
	       }
	       if(s2<1900 || s2>2100)
	       {
		   printf("\nDate format is wrong\n");
		   getch();
		   sdate[0]='\0';
		   goto DATE;
	       }
	       if((s2%4==0 && s2%100!=0) || s2%400==0)
	       {
		    if(s1==2)
		    {
			if(s>29)
			{
			   printf("\nDate is wrong\n");
			   getch();
			   sdate[0]='\0';
			   goto DATE;
			}
		    }
	       }
	       else
	       {
		   if(s1==2)
		   {
		      if(s>28)
		      {
			 printf("\nDate is wrong\n");
			 getch();
			   sdate[0]='\0';
			   goto DATE;
		      }
		   }
	       }
	      break;
	    }

       }
       if(q<=3)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    sdate[0]='\0';
	    goto DATE;
       }
       if(strlen(sdate)>10)
       {
	    printf("\nDate format is wrong\n");
	    getch();
	    sdate[0]='\0';
	    goto DATE;
       }
       printf("PhoneNo(Must be postive number):");
       fflush(stdin);
       scanf("%ld",&phon);
       t=phon;
       if(t<=0)
       {
	  printf("\nPhoneNo is wrong\n");
	  getch();
	  goto DATE;
       }

       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("  |Save...1|      |Cancel...0|\n");
       printf("\n        |BACK...2|\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       fflush(stdin);
       printf("Option:");
       scanf("%d",&opt2);
       switch(opt2
       )
       {
	 case 0:
	 goto DATE;
	 case 1:
	 fsave(cno,cname,phon,caddr,sdate);
	 printf("\n    | Record Saved | \n \n          |OK...1| ");
	 getch();
	 //transaction();
	 break;
	 case 2:
	 goto well;
       }
     break;
     case 2:
     clrscr();
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("        INTERNATIONAL BANK\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("          EXIST CUSTOMER\n");
       printf("          ~~~~~~~~~~~~~~\n");
       printf("AcNo:");
       fflush(stdin);
       scanf("%ld",&acid);
       f=exist(acid);
       if(f==0)
       {
	  break;
       }
       else{
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("  |OK...1|     |Cancel...0|\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("Option:");
       scanf("%d",&opt3);
       switch(opt3)
       {
	 case 0:
	 break;
	 case 1:
	 transaction();
	 break;
       }
     }
     break;
     default:
     printf("\nWrong Option");
     printf("\n\nPress any key to continue...");
     getch();
   }
  } while(opt1!=0);

   getch();
}
void transaction()
{
  int opt,opt1,opt2,opt3,opt4;
  long amt,am;
  int i,j=0,a[5],b1[5],c[5],d[10],e[10],p=0,q=0,s,s1,s2,i1;
  int i2,j2=0,a2[5],b2[5],c2[5],d2[10],e2[10],p2=0,q2=0,s3,s4,s5,i3;
  char date1[20],date2[20],date3[20],date4[20];
   do{
   clrscr();
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("        WELCOME TO INTERNATIONAL BANK\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("                 TRANSACTION                  \n");
   printf("   -------------------------------------\n");
   printf("    Deposit..........................1\n");
   printf("    Withdraw.........................2\n");
   printf("    Statement........................3\n");
   printf("    Enquiry..........................4\n");
   printf("    Cancel...........................0\n");
   printf("   -------------------------------------\n\n");
   printf("    Option:");
   scanf("%d",&opt);
   switch(opt)
   {
      case 1:
	DATE1:
	j=0;
	p=0;
	q=0;
	clrscr();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("        WELCOME TO INTERNATIONAL BANK\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("                   DEPOSIT                  \n");
	printf("     -----------------------------------\n");
	printf("        AC/NO:");
	scanf("%ld",&dacn);
	chd=deposit(dacn);
	if(chd==0)
	goto DATE1;
	printf("        Date(dd/mm/yyyy):");
	scanf("%s[^\n]",date1);
	for(i=0;i<strlen(date1);i++)
       {
	 if(date1[i]<47 || date1[i]>57)
	 {
	    printf("\nDate format is wrong\n");
	    getch();
	    date1[0]='\0';
	    goto DATE1;
	 }
       }

       for(i=0;i<strlen(date1);i++)
       {

	    if(date1[i]==48)
	    a[j]=0;
	    if(date1[i]==49)
	    a[j]=1;
	    if(date1[i]==50)
	    a[j]=2;
	    if(date1[i]==51)
	    a[j]=3;
	    if(date1[i]==52)
	    a[j]=4;
	    if(date1[i]==53)
	    a[j]=5;
	    if(date1[i]==54)
	    a[j]=6;
	    if(date1[i]==55)
	    a[j]=7;
	    if(date1[i]==56)
	    a[j]=8;
	    if (date1[i]==57)
	    a[j]=9;
	    j++;
	    if(j==2)
	    {

	       for(i1=0;i1<2;i1++)
	       {
		 if(i1==0)
		  s=a[i1]*10;
		 else
		 s=s+a[i1];
	       }
	       if(s==0)
		 {
		    printf("\nDate format is wrong\n");
		    getch();
		    date1[0]='\0';
		    goto DATE1;
		 }
	       if(s<0 || s>31)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 date1[0]='\0';
		 goto DATE1;
	       }

	      break;

	    }
       }
       if(j<=1)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date1[0]='\0';
	    goto DATE1;
       }

       for(i=j+1;i<strlen(date1);i++)
       {
	     if(date1[i]==48)
	    b1[p]=0;
	    if(date1[i]==49)
	    b1[p]=1;
	    if(date1[i]==50)
	    b1[p]=2;
	    if(date1[i]==51)
	    b1[p]=3;
	    if(date1[i]==52)
	    b1[p]=4;
	    if(date1[i]==53)
	    b1[p]=5;
	    if(date1[i]==54)
	    b1[p]=6;
	    if(date1[i]==55)
	    b1[p]=7;
	    if(date1[i]==56)
	    b1[p]=8;
	    if (date1[i]==57)
	    b1[p]=9;
	    p++;
	    if(p==2)
	    {
	       for(i1=0;i1<2;i1++)
	       {
		 if(i1==0)
		  s1=b1[i1]*10;
		 else
		 s1=s1+b1[i1];
	       }
	       if(s1==0)
		 {
		    printf("\nDate format is wrong\n");
		    getch();
		    date1[0]='\0';
		    goto DATE1;
		 }
	       if(s1<0 || s1>12)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 date1[0]='\0';
		 goto DATE1;
	       }

	       if(s1==4 || s1==6 || s1==9 || s1==11 )
	       {
		  if(s>30)
		  {
		     printf("\nDate format is wrong\n");
		    getch();
		    date1[0]='\0';
		    goto DATE1;
		  }

	       }
	      break;
	    }
       }
       if(p<=1)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date1[0]='\0';
	    goto DATE1;
       }
       for(i=(j+p+2);i<strlen(date1);i++)
       {
	    if(date1[i]==48)
	    c[q]=0;
	    if(date1[i]==49)
	    c[q]=1;
	    if(date1[i]==50)
	    c[q]=2;
	    if(date1[i]==51)
	    c[q]=3;
	    if(date1[i]==52)
	    c[q]=4;
	    if(date1[i]==53)
	    c[q]=5;
	    if(date1[i]==54)
	    c[q]=6;
	    if(date1[i]==55)
	    c[q]=7;
	    if(date1[i]==56)
	    c[q]=8;
	    if (date1[i]==57)
	    c[q]=9;
	    q++;
	    if(q==4)
	    {
		 for(i1=0;i1<4;i1++)
	       {
		 if(i1==0)
		 s2=c[i1]*10;
		 if(i1==1)
		 s2=s2*10+c[i1]*10;
		 if(i1==2)
		 s2=s2*10+c[i1]*10;
		 if(i1==3)
		 s2=s2+c[i1];
	       }
	       if(s2<1900 || s2>2100)
	       {
		   printf("\nDate format is wrong\n");
		   getch();
		   date1[0]='\0';
		   goto DATE1;
	       }
	       if((s2%4==0 && s2%100!=0) || s2%400==0)
	       {
		    if(s1==2)
		    {
			if(s>29)
			{
			   printf("\nDate is wrong\n");
			   getch();
			   date1[0]='\0';
			   goto DATE1;
			}
		    }
	       }
	       else
	       {
		   if(s1==2)
		   {
		      if(s>28)
		      {
			 printf("\nDate is wrong\n");
			   getch();
			   date1[0]='\0';
			   goto DATE1;
		      }
		   }
	       }
	      break;
	    }

       }
       if(q<=3)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date1[0]='\0';
	    goto DATE1;
       }
       if(strlen(date1)>10)
       {
	    printf("\nDate format is wrong\n");
	    getch();
	    date1[0]='\0';
	    goto DATE1;
       }
	printf("        Deposit Balance:");
	scanf("%ld",&amt);
	if(amt<=0)
	{
	    fflush(stdin);
	    printf("\n        Deposit Amount is wrong");
	    getch();
	    goto DATE1;
	}

	updbal=upbal2+amt;
	printf("     ------------------------------------\n");
	printf("        Update balance:%ld\n",updbal);
	printf("     ------------------------------------\n");
	printf("     |OK....1|              |CANCEL....0|\n");
	printf("     ------------------------------------\n\n");
	printf("           Option:");
	scanf("%d",&opt1);
	switch(opt1)
	{
	     case 1:
	     upbal(acn2,name2,phone2,address2,date2,updbal);
	     break;
	     case 0:
	     break;
	}
	break;
      case 2:
      DATE2:
	fflush(stdin);
	j2=0;
	p2=0;
	q2=0;
      clrscr();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("        WELCOME TO INTERNATIONAL BANK\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("                   WITHDRAW                     \n");
	printf("      ---------------------------------\n");
	printf("        AC/NO:");
	fflush(stdin);
	scanf("%ld",&wacn);
	chw=deposit(wacn);
	if(chw==0)
	goto DATE2;
	printf("        Withdraw Balance:");
	scanf("%ld",&wamt);
	if(wamt<=0)
	{
	    printf("\n        Withdraw Amount is wrong\n");
	    printf("\n        |OK...1|  |BACK...0|");
	    scanf("%ld",&ch1);
	    if(ch1==0)
	    break;
	    else
	    goto DATE2;
	}
	if(upbal2<wamt)
	{
	  printf("\n       Your withraw amount is greater than Total amount \n");
	  printf("\n               |OK...1|             |BACK...0|");
	  scanf("%ld",&ch2);
	  if(ch2==0)
	  break;
	  else
	  goto DATE2;
	}

	printf("        Date(dd/mm/yyyy):");
	scanf("%s[^\n]",date4);
	for(i2=0;i2<strlen(date4);i2++)
       {
	 if(date4[i2]<47 || date4[i2]>57)
	 {
	    printf("\nDate format is wrong\n");
	    getch();
	    date4[0]='\0';
	    goto DATE2;
	 }
       }
       for(i2=0;i2<strlen(date4);i2++)
       {

	    if(date4[i2]==48)
	    a2[j2]=0;
	    if(date4[i2]==49)
	    a2[j2]=1;
	    if(date4[i2]==50)
	    a2[j2]=2;
	    if(date4[i2]==51)
	    a2[j2]=3;
	    if(date4[i2]==52)
	    a2[j2]=4;
	    if(date4[i2]==53)
	    a2[j2]=5;
	    if(date4[i2]==54)
	    a2[j2]=6;
	    if(date4[i2]==55)
	    a2[j2]=7;
	    if(date4[i2]==56)
	    a2[j2]=8;
	    if (date4[i2]==57)
	    a2[j2]=9;
	    j2++;
	    if(j2==2)
	    {

	       for(i3=0;i3<2;i3++)
	       {
		 if(i3==0)
		  s3=a2[i3]*10;
		 else
		 s3=s3+a2[i3];
	       }
	       if(s3==0)
		 {

		    printf("\nDate format is wrong\n");
		    getch();
		    date4[0]='\0';
		    goto DATE2;
		 }
	       if(s3<0 || s3>31)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 date4[0]='\0';
		 goto DATE2;
	       }

	      break;

	    }
       }
       if(j2<=1)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date4[0]='\0';
	    goto DATE2;
       }

       for(i2=j2+1;i2<strlen(date4);i2++)
       {
	     if(date4[i2]==48)
	    b2[p2]=0;
	    if(date4[i2]==49)
	    b2[p2]=1;
	    if(date4[i2]==50)
	    b2[p2]=2;
	    if(date4[i2]==51)
	    b2[p2]=3;
	    if(date4[i2]==52)
	    b2[p2]=4;
	    if(date4[i2]==53)
	    b2[p2]=5;
	    if(date4[i2]==54)
	    b2[p2]=6;
	    if(date4[i2]==55)
	    b2[p2]=7;
	    if(date4[i2]==56)
	    b2[p2]=8;
	    if (date4[i2]==57)
	    b2[p2]=9;
	    p2++;
	    if(p2==2)
	    {
	       for(i3=0;i3<2;i3++)
	       {
		 if(i3==0)
		  s4=b2[i3]*10;
		 else
		 s4=s4+b2[i3];
	       }
	       if(s4==0)
		 {
		    printf("\nDate format is wrong\n");
		    getch();
		    date4[0]='\0';
		    goto DATE2;
		 }
	       if(s4<0 || s4>12)
	       {
		 printf("\nDate format is wrong\n");
		 getch();
		 date4[0]='\0';
		 goto DATE2;
	       }

	       if(s4==4 || s4==6 || s4==9 || s4==11 )
	       {
		  if(s3>30)
		  {
		     printf("\nDate format is wrong\n");
		    getch();
		    date4[0]='\0';
		    goto DATE2;
		  }

	       }
	      break;
	    }
       }
       if(p2<=1)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date4[0]='\0';
	    goto DATE2;
       }
       for(i2=(j2+p2+2);i2<strlen(date4);i2++)
       {
	    if(date4[i2]==48)
	    c2[q2]=0;
	    if(date4[i2]==49)
	    c2[q2]=1;
	    if(date4[i2]==50)
	    c2[q2]=2;
	    if(date4[i2]==51)
	    c2[q2]=3;
	    if(date4[i2]==52)
	    c2[q2]=4;
	    if(date4[i2]==53)
	    c2[q2]=5;
	    if(date4[i2]==54)
	    c2[q2]=6;
	    if(date4[i2]==55)
	    c2[q2]=7;
	    if(date4[i2]==56)
	    c2[q2]=8;
	    if (date4[i2]==57)
	    c2[q2]=9;
	    q2++;
	    if(q2==4)
	    {
		 for(i3=0;i3<4;i3++)
	       {
		 if(i3==0)
		 s5=c2[i3]*10;
		 if(i3==1)
		 s5=s5*10+c2[i3]*10;
		 if(i3==2)
		 s5=s5*10+c2[i3]*10;
		 if(i3==3)
		 s5=s5+c2[i3];
	       }
	       if(s5<1900 || s5>2100)
	       {
		   printf("\nDate format is wrong\n");
		   getch();
		   date4[0]='\0';
		   goto DATE2;
	       }
	       if((s5%4==0 && s5%100!=0) || s5%400==0)
	       {
		    if(s4==2)
		    {
			if(s3>29)
			{
			   printf("\nDate is wrong\n");
			   getch();
			   date4[0]='\0';
			   goto DATE2;
			}
		    }
	       }
	       else
	       {
		   if(s4==2)
		   {
		      if(s4>28)
		      {
			 printf("\nDate is wrong\n");
			   getch();
			   date4[0]='\0';
			   goto DATE2;
		      }
		   }
	       }
	      break;
	    }

       }
       if(q2<=3)
       {
	   printf("\nDate format is wrong\n");
	    getch();
	    date4[0]='\0';
	    goto DATE2;
       }
       if(strlen(date4)>10)
       {
	    printf("\nDate format is wrong\n");
	    getch();
	    date4[0]='\0';
	    goto DATE2;
       }



	updbal1=upbal2-wamt;

	printf("      ---------------------------------\n");
	printf("        Remaining Amount:%ld\n",updbal1);
	printf("      ---------------------------------\n");
	printf("          |OK...1|     |CANCEL...0|\n");
	printf("      ---------------------------------\n\n");
	printf("        Option:");
	scanf("%d",&opt2);
	switch(opt2)
	{
	  case 1:
	  upbal(acn2,name2,phone2,address2,date2,updbal1);
	  break;
	  case 0:
	  break;
	}
	break;
      case 3:
	clrscr();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("        WELCOME TO INTERNATIONAL BANK\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("                   STATEMENT                     \n");
	printf("      -----------------------------------\n");
	printf("        Cus_Id:\n");
	printf("        Name:\n");
	printf("        Ac/No:\n");
	printf("        Period:\n");
	printf("        from Date:");
	fflush(stdin);
	gets(date2);
	printf("          to Date:");
	fflush(stdin);
	gets(date3);
	printf("      -----------------------------------\n");
	printf("             |OK....1|\n");
	printf("      -----------------------------------\n\n");
	printf("       Option:");
	scanf("%d",opt3);
      break;
      case 4:
	clrscr();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("        WELCOME TO INTERNATIONAL BANK\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("                   ENQUIRY                     \n");
	printf("      -----------------------------------\n");
	printf("        AC/NO:");
	scanf("%ld",&eacnt);
	enquiry(eacnt);
	printf("      -----------------------------------\n");
	printf("             |OK....1|\n");
	printf("      -----------------------------------\n\n");
	printf("       Option:");
	scanf("%d",&opt4);
	switch(opt4)
	{
	   case 1:
	   break;
	}
      break;
   }
   }while(opt!=0);
}


void fsave(long acno,char *cname,long ph,char *caddr,char *sdate)
{
  FILE *fp;
  fp=fopen("BANK.dat","a+");
 if(fp==NULL)
 {
   printf("\nFile is not open \n");
 }
 else
 {
    b.acn=acno;
    strcpy(b.name,cname);
    b.phone=ph;
    strcpy(b.address,caddr);
    strcpy(b.date,sdate);
    b.ubal=0;
    fwrite(&b,sizeof(b),1,fp);
 }
 fclose(fp);
 cno=actno();
}



int exist(long acnid)
{
FILE *fp;
int f=0;
fp=fopen("BANK.dat","rb+");
while(fread(&b,sizeof(b),1,fp)==1)
{
 if((b.acn==acnid))
 {
  printf("Name:");
  puts(b.name);
  printf("Phone:%ld\n",b.phone);
  printf("Address:");
  puts(b.address);
  f=1;
  return(f);
 }
}
if(f==0)
{
printf("\n-------------------------");
printf("\n|Account number is wrong|\n");
printf("|Please try again.......|\n");
printf("-------------------------\n");
printf("\n      |OK...1|");
getch();
return(f);
}
else
{
  return(1);
}
}



long actno()
{
FILE *fp,*fp1;
fp=fopen("actnof.txt","r");
if(fp==NULL)
{
fp=fopen("actnof.txt","w");
putw((cno),fp);
fclose(fp);
return(cno+1);
}
else
{
  cno=getw(fp);
  fclose(fp);
  fp1=fopen("actnof.txt","w");
  cno=cno+1;
  putw((cno),fp1);
  fclose(fp1);
  return(cno+1);
}
}



int deposit(long acnid)
{
FILE *fp;
fp=fopen("BANK.dat","r");
rewind(fp);
f1=0;
while(fread(&b,sizeof(b),1,fp)==1)
{
 if((b.acn==acnid))
 {
  printf("        Name:");
  puts(b.name);
  printf("        Total Balance:%ld\n",b.ubal);
  acn2=b.acn;
  strcpy(name2,b.name);
  phone2=b.phone;
  strcpy(address2,b.address);
   strcpy(date2,b.date);
   upbal2=b.ubal;
  f1=1;
   fclose(fp);
  return(f1);

 }
}
fclose(fp);
if(f1==0)
{
printf("\n-------------------------");
printf("\n|Account number is wrong|\n");
printf("|Please try again.......|\n");
printf("-------------------------\n");
printf("\n      |OK...1|");
getch();
return(f1);
}
else
{
  return(1);
}
}



void upbal(long acn3,char name3[30],long phone3,char address3[50],char date3[20],long bal3)
{
    FILE *fp;
    int loc,recdno;
	 fp=fopen("BANK.dat","rb+");
	 recdno=recno(acn3);
	 b.acn=acn3;
	  strcpy(b.name,name3);
	  b.phone=phone3;
	  strcpy(b.address,address3);
	  strcpy(b.date,date3);
	  b.ubal=bal3;

	  loc=(recdno-1)*sizeof(b);

	  fseek(fp,loc,SEEK_CUR);
	  fwrite(&b,sizeof(b),1,fp);
    fclose(fp);
}


int recno(long racn)
{
  FILE *fp;
  int count=0;
  fp=fopen("BANK.dat","r");
  rewind(fp);
  while(fread(&b,sizeof(b),1,fp)==1)
  {
    count++;
    if(racn==b.acn)
    break;
  }
  fclose(fp);
  return count;
}


void enquiry(long eacn)
{
   FILE *file;
   int flag3=0;
   file=fopen("BANK.dat","r");
   if(file==NULL)
   {
     printf("\nDatabase connection is wrong");
    }
  else
  {
     while(fread(&b,sizeof(b),1,file)==1)
     {
	  if(b.acn==eacn)
	  {
	      printf("        Name:");
	      puts(b.name);
	      printf("        Address:");
	      puts(b.address);
	      printf("        Phone:%ld\n",b.phone);
	      printf("        Total Balance:%ld\n",b.ubal);
	      flag3=1;
	      fclose(file);
	      break;
	  }
     }
     if(flag3==0)
     {
       printf("\n|Wrong AC/NO|\n");
       printf("\nPress any key to continue...\n");
       getch();
       fclose(file);
     }
  }
}
