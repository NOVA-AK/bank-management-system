#include <stdio.h>
#include <conio.h>
#define clrsrc() system("cls")

struct BANK
{
	char name[1000];
	int aadhar_number;
	int date;
	char address[1000];
	int account_balance;
	int Pin;
};
struct BANK B1;

void design();
void create_new_acc();
void acc_info();
void updt_info();
void deposit_amount();
void withdrawal_money();
void transaction();
void check_balance();
void exit();

int main()
{
	int pin, choice, count = 0;
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
					acc_info();
					break;
				case 3:
					updt_info();
					break;
				case 4:
					deposit_amount();
					break;
				case 5:
					withdrawal_money();
					break;
				case 6:
					transaction();
					break;
				case 7:
					check_balance();
					break;
				case 8:
					exit(0);
				default:
					printf("Your Choice is Invalid!!!!!!!\nPlease Enter a Valid Choice:\n");
				}
			} while (choice != 8);

		else
			printf("Invalid PIN\n");
		if (count == 3){
			exit(0);
		}
		goto PIN;
	}

	count++;

	return 0;
}

void design()
{
	system("cls");
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
	FILE *fp;
	fp = fopen("bank_record.txt","a");
	system("cls");

	printf("\nEnter Your Name : ");
	scanf(" %[^\n]s", &B1.name);
	printf("\nEnter Your Aadhar Number : ");
	scanf("%d", &B1.aadhar_number);
	printf("\nEnter your Address : ");
	scanf(" %[^\n]s", &B1.address);
	printf("\nEnter your deposit amount : ");
	scanf("%d", &B1.account_balance);
	printf("Enter Your 4 Digit PIN : ");
	scanf("%d", &B1.Pin);

	fprintf(fp, " %s %d %s %d %d\n",B1.name,B1.aadhar_number,B1.address,B1.account_balance,B1.Pin);

	fclose(fp);
}

void acc_info()
{

	printf("account information");
}

void updt_info()
{
	printf("update information");
}

void deposit_amount()
{

	printf("deposit amount");
}

void withdrawal_money()
{

	printf("withdrawal money");
}

void transaction()
{

	printf("transaction");
}

void check_balance()
{

	printf("check balance");
}
void exit()
{
	
}
