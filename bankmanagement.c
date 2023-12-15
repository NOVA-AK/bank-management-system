#include <stdio.h>
//#include <conio.h>
//#define clrsrc() system("cls")

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
	int account_balance;
	int Pin;
};

struct BANK B1;

void design();
void create_new_acc();
void saveAccountDetails(struct BANK *);
void updt_info();
void deposit_amount(struct BANK *,float);
void withdrawal_money(struct BANK *,float);
void transaction();
float check_balance(struct BANK *);
void exit();

int main()
{
	int pin, choice, count = 0;
    struct BANK B1;
    B1.accountNumber = 123;      // Change this to your account number
    B1.account_balance = 0.0;
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
				
				case 3:
					updt_info();
					break;
				case 4:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit_amount(&B1, amount);
                saveAccountDetails(&B1);
					//deposit_amount();
					break;
				case 5:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdrawal_money(&B1, amount);
                saveAccountDetails(&B1);
					//withdrawal_money();
					break;
				case 6:
                 //printf("Total Balance: %.2f\n", check_balance(&B1));
					transaction();
					break;
				case 7:
                 printf("Total Balance: %.2f\n", check_balance(&B1));
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
		scanf(" %[^\n]s", B1.name);
		printf("\nEnter Your Aadhar Number : ");
		scanf("%d", &B1.aadhar_number);
		printf("\nEnter Your Date of Birth : ");
		scanf("%d/%d/%d", &B1.dob.day , &B1.dob.month, &B1.dob.year);
		printf("\nEnter Your mobile number : ");
		scanf("%d",&B1.mobile_no);
		printf("\nEnter your Address : ");
		scanf(" %[^\n]s", B1.address);
		printf("\nEnter your deposit amount : ");
		scanf("%d", &B1.account_balance);
		printf("\nEnter Your 4 Digit PIN : ");
		scanf("%d", &B1.Pin);
		
		fprintf(fp, " %s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%d\n",B1.name,B1.aadhar_number,B1.dob.day, B1.dob.month, B1.dob.year, B1.mobile_no,B1.address,B1.account_balance,B1.Pin);
		
		printf("\nDo you wish to continue adding more details. If Yes, press 1. Else, press 0 : ");
		scanf("%d",&cont);
	}



	fclose(fp);
}



void updt_info()
{	
	printf("update information");
}

void deposit_amount(struct BANK *account, float amount)
{       
                account->account_balance += amount;
    printf("Deposited %.2f\n", amount);
}

void withdrawal_money(struct BANK *account, float amount)
{    printf("withdrawal money");
    if (amount > account->account_balance) {
        printf("Insufficient balance.\n");
    } else {
        account->account_balance -= amount;
        printf("Withdrawn %.2f\n", amount);
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
void saveAccountDetails(struct BANK *account)
{
     
    FILE *fp = fopen("account_details.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "%s\t%d\t%d/%d/%d\t%d\t%s\t%d\t%d",
            account->name, account->aadhar_number, account->dob.day, account->dob.month, account->dob.year,
            account->mobile_no, account->address, account->account_balance, account->Pin);
            ;
    fclose(fp);;

}
