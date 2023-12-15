#include <stdio.h>
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
	int aadhar_number;
    int accountNumber;
	struct date dob;
	int mobile_no;
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
void account_info(struct BANK *);
void updt_info();
void deposit_amount(struct BANK *);
void withdrawal_money(struct BANK *);
void transaction();
float check_balance(struct BANK *);
void exit();

int main()
{
	int pin, choice, count = 0;
    struct BANK account;
    account.accountNumber = 123;      // Change this to your account number
    account.account_balance = 0.0;
    float amount;
PIN:
	printf("Enter Your Login PIN :");
	scanf("%d", &pin);
	if (count <= 3)
	{
		if (pin == 2004)
			do
			{
				design();
				printf("\nEnter Your Choice : ");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
					create_new_acc();
					break;
				case 2:
                    account_info(&account);   
                    break;
				case 3:
					updt_info();
					break;
				case 4:
                    deposit_amount(&account);
					break;
				case 5:
                    withdrawal_money(&account);
					break;
				case 6:
                 //printf("Total Balance: %.2f\n", check_balance(&account));
					transaction();
					break;
				case 7:
                 printf("Total Balance: %.2f\n", check_balance(&account));
					//check_balance();
					break;
				case 8:
					exit(0);
				default:
					printf("Your Choice is Invalid!!!!!!!\nPlease Enter a Valid Choice:\n");
				}
			} while (choice != 8);

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
		printf("\nEnter Your Aadhar Number : ");
		scanf("%d", &account.aadhar_number);
		printf("\nEnter Your Date of Birth : ");
		scanf("%d/%d/%d", &account.dob.day , &account.dob.month, &account.dob.year);
		printf("\nEnter Your mobile number : ");
		scanf("%d",&account.mobile_no);
		printf("\nEnter your Address : ");
		scanf(" %[^\n]s", account.address);
		printf("\nEnter your deposit amount : ");
		scanf("%d", &account.account_balance);
		printf("\nEnter Your 4 Digit PIN : ");
		scanf("%d", &account.Pin);
		
		fprintf(fp, " %s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%d\n",account.name,account.aadhar_number,account.dob.day, account.dob.month, account.dob.year, account.mobile_no,account.address,account.account_balance,account.Pin);
		
		printf("\nDo you wish to continue adding more details. If Yes, press 1. Else, press 0 : ");
		scanf("%d",&cont);
	}
	fclose(fp);
}

void updt_info()
{	
	printf("update information");
}

void deposit_amount(struct BANK *account)
{       
    printf("Enter the amount of money you wish to deposit : ");
    scanf("%f",account->deposit);
    account->account_balance += account->deposit;
    printf("Deposited %.2f\n", account->deposit);
    printf("Current Balance is %f",account->account_balance);
}

void withdrawal_money(struct BANK *account)
{    
    printf("Withdraw Money : ");
    printf("Enter the ammount you wish to withdraw : ");
    scanf("%f",account->withdrawal);
    if(account->withdrawal > account->account_balance)
    {
        printf("Insufficient balance.\n");
    } 
    else 
    {
        account->account_balance -= account->withdrawal;
        printf("Withdrawn %.2f\n", account->withdrawal);
        printf("Current Balance is %0.2f\n",account->account_balance);
    }
}

void transaction()
{  
	printf("transaction");
}

float check_balance(struct BANK *account)
{   

	printf("check balance");
    return account->account_balance;
}
void account_info(struct BANK *account)
{
     
    FILE *fp = fopen("bank_record.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fscanf(fp, "%s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%f",
            account->name, account->aadhar_number, account->dob.day, account->dob.month, account->dob.year,
            account->mobile_no, account->address, account->account_balance);
    printf("\n\n%s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%f\n\n",
            account->name, account->aadhar_number, account->dob.day, account->dob.month, account->dob.year,
            account->mobile_no, account->address, account->account_balance);
            ;
    fclose(fp);;

}
