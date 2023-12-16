#include <stdio.h>
#include<string.h>
#include <conio.h>
#define clrsrc() system("cls")

struct date
{
	int day;
	int month;
	int year;
};

struct BANK
{
	char name[1000];
	char aadhar_number[12];
    char account_number[16];
	struct date dob;
	char mobile_no[10];
	char address[1000];
	float account_balance;
	int Pin;
    float deposit;
    float withdrawal;
    float transact;
};

struct BANK account;

void design();
void create_new_acc();
void login_account();
void account_info(int);
void updt_info(int);
void deposit_amount(int);
void withdrawal_money(int);
void transaction(int);
float check_balance(int);

int main()
{
	int choice1= 0;
    printf("1. Create account\n");
    printf("2. Login to account\n");
	printf("Enter your choice : \n");
    scanf("%d",&choice1);
	switch(choice1)
	{
	case 1:
		create_new_acc();
		break;
	case 2:
		login_account();
		break;
	}
	
	return 0;
}


void design()
{
	//system("cls");
	printf("---------------BANK MANAGEMENT SYSTEM---------------");
	printf("\n\t 1) Create Account.");
	printf("\n\t 2) Account Information.");
	printf("\n\t 3) Update Account Inforamtion.");
	printf("\n\t 4) Deposit Amount.");
	printf("\n\t 5) Withdrawal Account.");
	printf("\n\t 6) Transaction to Another Account.");
	printf("\n\t 7) Check Account.");
	printf("\n\t 8) Exit.");
	printf("\n----------------------------------------------------");
}

void create_new_acc()
{

	int cont = 1;
	FILE *fp;
	fp = fopen("bank_record.txt","a");
	while(cont != 0)
	{
		printf("\nEnter Your Name : ");
		scanf(" %[^\n]s", account.name);
		printf("Enter Your Account Number : ");
		scanf(" %s", account.account_number);
		printf("\nEnter Your Aadhar Number : ");
		scanf(" %s", account.aadhar_number);
		printf("\nEnter Your Date of Birth : ");
		scanf("%d/%d/%d", &account.dob.day , &account.dob.month, &account.dob.year);
		printf("\nEnter Your mobile number : ");
		scanf(" %s",account.mobile_no);
		printf("\nEnter your Address : ");
		scanf(" %[^\n]s", account.address);
		printf("\nEnter your deposit amount : ");
		scanf("%f", &account.account_balance);
		printf("\nEnter Your 4 Digit PIN : ");
		scanf("%d", &account.Pin);
		
		fprintf(fp, " %s\t%s\t%s\t%d/%d/%d\t%s\t%s\t%f\t%d\n",account.name,account.account_number,account.aadhar_number,account.dob.day, account.dob.month, account.dob.year, account.mobile_no,account.address,account.account_balance,account.Pin);
		
        printf("Press 1 to go to to menu\nPress 0 to exit\n");
		printf("Enter Your Choice : ");
		scanf("%d",&cont);

		if(cont == 1)
		{
			login_account();
		}
		else
		{
			exit(0);
		}
	}
	fclose(fp);
}

void updt_info(int check_account_number)
{	
	printf("update information");
}

void deposit_amount(int check_account_number)
{   
	int pin;
	int count = 1;
    FILE *fp = fopen("bank_record.txt","r");
	FILE *fp2 = fopen("bank_record_temp.txt","w");
    while(fscanf(fp,"%s\t%s\t%s\t%d/%d/%d\t%s\t%s\t%f\t%d",account.name,account.account_number,account.aadhar_number,&account.dob.day, &account.dob.month, &account.dob.year, account.mobile_no,account.address,&account.account_balance,account.Pin)!=EOF)
	{
		if(check_account_number==account.account_number)
		{
			PIN:
			printf("\nEnter Your Login Pin : ");
			scanf("%d", &pin);
			if(pin==account.Pin)
			{
				    printf("Enter the amount of money you wish to deposit : ");
					scanf("%f",account.deposit);
					account.account_balance += account.deposit;
					printf("Deposited %.2f\n", account.deposit);
					printf("Current Balance is %f",account.account_balance);


			}
			else
			{
				printf("Enter Correct Pin\n");
				count++;
				if(count<=3)
					goto PIN;
				else
					printf("Invalid Pin Entered Thrice. Returning to Main Menu");
					design();
			}
		}

	}

}

void withdrawal_money(int check_account_number)
{    
	FILE *fp = fopen("bank_record.txt","r");
	FILE *fp2 = fopen("bank_record_temp.txt","w");

    printf("Withdraw Money : ");
    printf("Enter the ammount you wish to withdraw : ");
    scanf("%f",account.withdrawal);
    if(account.withdrawal > account.account_balance)
    {
        printf("Insufficient balance.\n");
    } 
    else 
    {
        account.account_balance -= account.withdrawal;
        printf("Withdrawn %.2f\n", account.withdrawal);
        printf("Current Balance is %0.2f\n",account.account_balance);
    }
}

void transaction(int check_account_number)
{  
	FILE *fp = fopen("bank_record.txt","r");
	FILE *fp2 = fopen("bank_record_temp.txt","w");
	printf("transaction");
}

float check_balance(int check_account_number)
{   
	FILE *fp = fopen("bank_record.txt","r");
	FILE *fp2 = fopen("bank_record_temp.txt","w");

	printf("check balance");
    return account.account_balance;
}
void account_info(int check_account_number)
{
     
    FILE *fp = fopen("bank_record.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fscanf(fp, "%s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%f",
            account.name, account.aadhar_number, account.dob.day, account.dob.month, account.dob.year,
            account.mobile_no, account.address, account.account_balance);
    printf("\n\n%s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%f\n\n",
            account.name, account.aadhar_number, account.dob.day, account.dob.month, account.dob.year,
            account.mobile_no, account.address, account.account_balance);
    fclose(fp);

}

void login_account()
{
    FILE *fp = fopen("bank_record.txt", "a");
	int pin, choice,count=1;
	int check_account_number;
	acc_no:
	printf("Enter Your Account Number :");
	scanf("%d", &check_account_number);

	
    while(fscanf(fp,"%s\t%d\t%d\t%d/%d/%d\t%d\t%s\t%d\t%d",account.name,account.account_number,account.aadhar_number,account.dob.day, account.dob.month, account.dob.year, account.mobile_no,account.address,account.account_balance,account.Pin))
	{
		if(check_account_number==account.account_number)
		{
			PIN:
			printf("\nEnter Your Login Pin : ");
			scanf("%d", &pin);
			
			if(pin != account.Pin)
			{
				printf("\nEnter Correct Pin\n");
				count++;
				if(count<=3)
				{
					goto PIN;
				}
				else
				{
					printf("Incorrect Pin Entered Thrice. Returning to main menu");
					design();
				}
			}
		}
		else
		{
			printf("Account Number does not exist");
			int acc_exist;
			printf("Options:\n1. Enter Account Number again\n2. Create New Account\n3. Go To Main Menu\n 4. Exit");
			scanf("%d",&acc_exist);
			switch(acc_exist)
			{
				case 1:
					goto acc_no;
				case 2:
					create_new_acc();
				case 3:
					login_account();
				case 4:
					exit(0);
			}

		}
	}
	if (count <= 3)
	{
		if (pin == account.Pin)
			do
			{
				printf("---------------BANK MANAGEMENT SYSTEM---------------");
				printf("\n\t 1) Account Information.");
				printf("\n\t 2) Update Account Inforamtion.");
				printf("\n\t 3) Deposit Amount.");
				printf("\n\t 4) Withdrawal Account.");
				printf("\n\t 5) Transaction to Another Account.");
				printf("\n\t 6) Check Account.");
				printf("\n\t 7) Exit.");
				printf("\n----------------------------------------------------");
				printf("\nEnter Your Choice : ");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
                    account_info(check_account_number);   
                    break;
				case 2:
					updt_info(check_account_number);
					break;
				case 3:
                    deposit_amount(check_account_number);
					break;
				case 4:
                    withdrawal_money(check_account_number);
					break;
				case 5:
					transaction(check_account_number);
					break;
				case 6:
                 printf("Total Balance: %.2f\n", check_balance(check_account_number));
					break;
				case 7:
					exit(0);
				default:
					printf("Your Choice is Invalid!!!!!!!\nPlease Enter a Valid Choice:\n");
				}
			} 
			while (choice != 7);

		else
		{
			printf("Invalid PIN\n");
			
			if (count == 2)
				exit(0);
			count++;

			goto PIN;

		}
	}
	return 0;
}


