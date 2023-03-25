/* Author : Pulluri Poojitha
   Date : 30-10-2021 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
void login(void);
void create_acc(void);
void loginsu(void);
void display(int);
int gen_accno(char[],char[]);
void checkbalance(void);
void deposit (void);
void withdraw(void);
void logout(void);

struct pass {
	int acc_no;
	int date, month, year;
    int age;   
	double pnumber;
	char adharnum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char citizenship[15];
	char typeaccount[20];
	float acc_bal;
};

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int gen_accno(char fname[],char lname[]){
	int i,sum = 0;
	int n = strlen(fname)+strlen(lname);
	char *name = (char*)malloc(n*sizeof(char));
	
	strcpy(name,fname);
	strcat(name,lname);
	for(i=0;i<n;i++){
		sum += name[i];
	}
	return sum;
}

int main()
{
	int choice;
		printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");

    	printf("**********************************\n\n");
		printf("1.... CREATE A BANK ACCOUNT\n\n");
		printf("2.... ALREADY A USER? SIGN IN\n\n");
		printf("3.... EXIT\n\n");
		printf("\n\nENTER YOUR CHOICE..");

		scanf("%d", &choice);

		switch (choice) 
		{
		case 1:
			system("cls");
			create_acc();
			break;
	
		case 2:
			login();
			break;
	
		case 3:
			exit(0);
			break;
	
			getch();
		
    } 
}
void create_acc(void){
	
	int i;
	char ch;
	FILE *fp;
	struct pass u1;

	fp = fopen("username.txt", "a+");

	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME-");
	scanf("%s", &u1.fname);

	printf("\n\nLAST NAME-");
	scanf("%s", &u1.lname);

	printf("\n\nFATHER's NAME-");
	scanf("%s", &u1.fathname);

	printf("\n\nMOTHER's NAME-");
	scanf("%s", &u1.mothname);

	printf("\n\nAGE-");
	scanf("%d", &u1.age);

    fflush(stdin);
	printf("\n\nCITY-");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u1.typeaccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nADHAR NUMBER-");
	scanf("%s",&u1.adharnum);

	printf("\n\nPHONE NUMBER-");
	scanf("%lf", &u1.pnumber);
	
	system("cls");
	
	printf("PLEASE WAIT\n\nYOUR DATA IS PROCESSING...\n\n");
	fordelay(1000000000);
	//delay(2000);
	printf("ACCOUNT CREATED SUCCESSFULLY\n\n");
	printf("YOUR ACCOUNT NUMBER - \n\n");
	u1.acc_no = gen_accno(u1.fname,u1.lname);
	printf("%d",u1.acc_no);
	
	u1.acc_bal = 0;
	
	
    fprintf(fp ,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f\n",
			u1.acc_no,u1.fname,u1.lname,u1.fathname,u1.mothname,u1.age,
			u1.date,u1.month,u1.year,u1.address,u1.pnumber,u1.typeaccount,u1.adharnum,u1.acc_bal);

	fclose(fp);
    //system("cls");
	printf("\n\nPress enter to login\n\n");
	getch();
	login();
}

void login(void) 
{
	system("cls");

	int check_acc;
	FILE *fp;
	struct pass u1;
//	struct userpass u2;

	fp = fopen("username.txt","r");

	if (fp == NULL) 
	{
		printf("ERROR IN OPENING FILE");
	}
	printf(" ACCOUNT LOGIN \n\n");
	printf("*******************************************************************************\n\n");
	
	printf("==== LOG IN ====\n\n");


	printf("ACCOUNT NUMBER..\n\n");
	fflush(stdin);
	scanf("%d",&check_acc);
	
while(fscanf(fp,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f",&u1.acc_no,&u1.fname,&u1.lname,&u1.fathname,&u1.mothname,
&u1.age,&u1.date,&u1.month,&u1.year,&u1.address,&u1.pnumber,&u1.typeaccount,&u1.adharnum,&u1.acc_bal)!=EOF)
	{
	if (check_acc == u1.acc_no){
		loginsu();
		fclose(fp);
		display(check_acc);
	}
	else
	{
	   printf("Incorrect Account Number..");	
	}
	}
    
}

void loginsu(void)
{
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	//delay(2000);
	fordelay(1000000000);

	printf("LOGIN SUCCESSFUL....\n\n");
	printf("Press enter to continue");
	getch();
}
void display(int check_acc)
{
	system("cls");
	FILE* fp;
	int choice;
	fp = fopen("username.txt", "r");
	struct pass u1;

	if (fp == NULL) 
	{
		printf("error in opening file");
	}

	while(fscanf(fp,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f",&u1.acc_no,&u1.fname,&u1.lname,&u1.fathname,
	&u1.mothname,&u1.age,&u1.date,&u1.month,&u1.year,&u1.address,&u1.pnumber,&u1.typeaccount,&u1.adharnum,&u1.acc_bal)!=EOF)
	{
		if (check_acc == u1.acc_no) 
		{
			printf("WELCOME, %s %s",u1.fname, u1.lname);
			
			printf("***************************\n\n");
			
			printf("==== YOUR ACCOUNT INFO ====\n\n");
		
			printf("***************************\n\n");
			
			printf("\n\nNAME..%s %s", u1.fname,u1.lname);

			printf("\n\nFATHER's NAME..%s",u1.fathname);

			printf("\n\nMOTHER's NAME..%s",u1.mothname);

			printf("\n\nADHAR CARD NUMBER..%s",u1.adharnum);

			printf("\n\nMOBILE NUMBER..%.0lf",u1.pnumber);

			printf("\n\nDATE OF BIRTH.. %d-%d-%d",u1.date, u1.month, u1.year);

			printf("\n\nCITY..%s", u1.address);

			printf("\n\nACCOUNT TYPE..%s",u1.typeaccount);
		}
	}
	printf("\n\n***************************\n\n");
	fclose(fp);
	//delay(2000);
	fordelay(1000000000);
while(1)
	{
	
		printf("\n\n HOME \n\n");
		printf("******\n\n");
		printf("1....CHECK BALANCE\n\n");
		printf("2....WITHDRAW\n\n");
		printf("3....DEPOSIT\n\n");
		printf("4....LOG OUT\n\n");
		printf("5....EXIT\n\n");
	
		printf("ENTER YOUR CHOICES..");
		scanf("%d", &choice);
		system("cls");
		switch (choice) {
		case 1:
			checkbalance();
			break;
	
		case 2:
			withdraw();
			break;
	
		case 3:
			deposit();
			break;
					
		case 4:
			logout();
			login();
			break;
	
		case 5:
			exit(0);
			break;
		}
	}
}
void checkbalance(void)
{
	FILE *fo,*fn;
	fo=fopen("username.txt","r");
	fn= fopen("new.txt", "w");
	struct pass u1;
	
	while(fscanf(fo,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f",&u1.acc_no,&u1.fname,&u1.lname,&u1.fathname,
		&u1.mothname,&u1.age,&u1.date,&u1.month,&u1.year,&u1.address,&u1.pnumber,&u1.typeaccount,&u1.adharnum,&u1.acc_bal)!=EOF)
	{
		printf ("\n\n---Account Balance---\n\n");
		fordelay(1000000000);
		printf ("\n\nYour Current Balance is: %f\n\n",u1.acc_bal);
			
		fprintf(fn ,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f\n",
			u1.acc_no,u1.fname,u1.lname,u1.fathname,u1.mothname,u1.age,
			u1.date,u1.month,u1.year,u1.address,u1.pnumber,u1.typeaccount,u1.adharnum,u1.acc_bal);
	}
	
			
	fclose(fo);
	fclose(fn);
	remove("username.txt");
	rename("new.txt","username.txt");
	fordelay(1000000000);
}

void deposit(void)
{	
	float dep_amt;
	FILE *fo,*fn;
	fo=fopen("username.txt","r");
	fn= fopen("new.txt", "w");

	struct pass u1;
	
	while(fscanf(fo,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f",&u1.acc_no,&u1.fname,&u1.lname,&u1.fathname,
		&u1.mothname,&u1.age,&u1.date,&u1.month,&u1.year,&u1.address,&u1.pnumber,&u1.typeaccount,&u1.adharnum,&u1.acc_bal)!=EOF)
	{
	printf ("\n\n---Deposit---\n\n");
	printf ("Enter Amount     :");
	scanf ("%f",&dep_amt);
	u1.acc_bal += dep_amt;
	fordelay(1000000000);
	printf ("\n\nAmount deposited: %f",dep_amt);
	printf ("\nNew Balance: %f\n\n",u1.acc_bal);
	
	fprintf(fn ,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f\n",
			u1.acc_no,u1.fname,u1.lname,u1.fathname,u1.mothname,u1.age,
			u1.date,u1.month,u1.year,u1.address,u1.pnumber,u1.typeaccount,u1.adharnum,u1.acc_bal);
	}
	
	fclose(fo);
	fclose(fn);
	remove("username.txt");
	rename("new.txt","username.txt");		

	fordelay(1000000000);
}
void withdraw(void)
{
	float wdraw_amt;
	FILE *fo,*fn;
	fo=fopen("username.txt","r");
	fn= fopen("new.txt", "w");

	struct pass u1;
	
	while(fscanf(fo,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f",&u1.acc_no,&u1.fname,&u1.lname,&u1.fathname,
		&u1.mothname,&u1.age,&u1.date,&u1.month,&u1.year,&u1.address,&u1.pnumber,&u1.typeaccount,&u1.adharnum,&u1.acc_bal)!=EOF)
	{
			
			printf ("Enter Amount :");
			scanf ("%f", &wdraw_amt);
		
		if (u1.acc_bal>=wdraw_amt)
		{
			u1.acc_bal -= wdraw_amt;
			fordelay(1000000000);
			printf ("\n\nAmount withdraw: %f",wdraw_amt);
			printf ("\nNew balance: %f\n\n", u1.acc_bal);
			fprintf(fn ,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f\n",
				u1.acc_no,u1.fname,u1.lname,u1.fathname,u1.mothname,u1.age,
				u1.date,u1.month,u1.year,u1.address,u1.pnumber,u1.typeaccount,u1.adharnum,u1.acc_bal);
		}
		else
		{
			printf ("\n\n Insufficient Funds--\n");
			printf ("please be reminded that your current balance is: %f\n",u1.acc_bal);
			printf ("\n\n---Withdraw---\n\n");
			withdraw();
			fprintf(fn ,"%d %s %s %s %s %d %d %d %d %s %lf %s %s %f\n",
				u1.acc_no,u1.fname,u1.lname,u1.fathname,u1.mothname,u1.age,
				u1.date,u1.month,u1.year,u1.address,u1.pnumber,u1.typeaccount,u1.adharnum,u1.acc_bal);
		}
	
	
	}

	fclose(fo);
	fclose(fn);
	remove("username.txt");
	rename("new.txt","username.txt");
	fordelay(1000000000);
}
void logout(void)
{
	system("cls");
	printf("please wait, logging out");

	printf("Sign out successfully..\n");

	printf("press any key to continue..");

	getch();
}
