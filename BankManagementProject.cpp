#include<iostream>
using namespace std;

class Account
{
	double balance;
	double acno;
	char name[30];
	int choice;

	public:
		Account()
		{
			balance = 0;
		}
		void virtual Withdraw(double amt)
		{
			balance = balance - amt;
		}
		void virtual Deposit(double amt)
		{
			balance = balance + amt;
		}
		double CheckBalance()
		{
			return balance;
		}
};
class SavingsAccount: public Account
{
		int t;
		int limit;
		int e = 0;
	public:
		SavingsAccount()
		{
			t = 0;
			limit = 5;
		}
		void Withdraw(double amt)
		{
			if(t > limit)
			{
				cout<<"\n\t\tTransaction Exceeded";	
				cout<<"\n\n\t\tTransaction Failed......";
			}
			else if(Account::CheckBalance() - amt < e)
			{
				cout<<"\n\n\t\tAmount Exceeds Balance";	
				cout<<"\n\n\t\tTransaction Failed......";
				t++;
			}
			else
			{
				Account::Withdraw(amt);
				t++;
				cout<<"\n\n\t\tAmount Successfully Withdrawn.......";
			}
		}
		void Deposit(double amt)
		{
			if(t > limit)
			{
				cout<<"\n\t\tTransaction Exceeded";
				cout<<"\n\n\t\tTransaction Failed......";
			}
			else
			{
				Account::Deposit(amt);
				t++;
				cout<<"\n\n\t\tAmount Successfully Deposited.......";
			}
		}
};
class VIPSavingsAccount:public SavingsAccount
{
	double minbalance;
	int limit;
	int t;
	public:
		VIPSavingsAccount()
		{
			t= 0;
			limit = 10;
			minbalance = 25000;
		}
		void Deposit(double amt)
		{
			if(t > limit)
			{
				cout<<"\n\t\tTransaction Exceeded";
				cout<<"\n\n\t\tTransaction Failed......";
			}
			else
			{
				Account::Deposit(amt);
				t++;
				cout<<"\n\n\t\tAmount Successfully Deposited.......";
			}
		}
		void Withdraw(double amt)
		{
			if(t > limit)
			{
				cout<<"\n\t\tTransaction Exceeded";
				cout<<"\n\n\t\tTransaction Failed......";
			}
			else if(Account::CheckBalance() - amt < minbalance)
			{
				cout<<"\n\t\tCannot withdraw due to minimum balance";
				cout<<"\n\n\t\tTransaction Failed......";
				t++;
			}
			else
			{
				Account::Withdraw(amt);
				t++;
				cout<<"\n\n\t\tAmount Successfully Withdrawn.......";
			}
		
		}
};
class DematAccount: public Account
{
	double tax;
	double amt;
	int e = 0;
	public:
		DematAccount()
		{
			tax = amt * 0.01;
		}
		void Withdraw(double amt)
		{
			if(Account::CheckBalance() - amt < e)
			{
				cout<<"\n\n\t\tAmount Exceeds Balance";	
				cout<<"\n\n\t\tTransaction Failed......";
			}
			else
			{
				amt = amt + (amt * 0.01);
				Account::Withdraw(amt);
				cout<<"\n\n\t\tAmount Successfully Withdrawn.......";
			}
		}
		void Deposit(double amt)
		{
			amt = amt - (amt * 0.01);
			Account::Deposit(amt);
			cout<<"\n\n\t\tAmount Successfully Deposited.......";
		}
};

int main()
{
	Account* bank[3];
	Account a;
	SavingsAccount sa;
	DematAccount da;
	VIPSavingsAccount vsa;
	char name[30];
	int acno;
	double minbalance = 25000;
	double amt;
	
	int i = 10, j = 5;
	int choice;
	int ch;
	bank[0] = &sa;
	bank[1] = &da;
	bank[2] = &vsa;

	do
	{
		cout<<"\n\n\t\t=======================";
		cout<<"\n\t\tBANK MANAGEMENT PROJECT";
		cout<<"\n\t\t=======================\n";
		cout<<"\t\t     ::MAIN MENU::\n";
		cout<<"\n\t\t1)NEW ACCOUNT";
		cout<<"\n\t\t2)DEPOSIT AMOUNT";
		cout<<"\n\t\t3)WITHDRAW AMOUNT";
		cout<<"\n\t\t4)DISPLAY EXISTING ACCOUNT DETAILS";
		cout<<"\n\t\t5)EXIT";
		cout<<"\n\n\t\tEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1: 
			cout<<"\n\t\tEnter Account Holders Name: ";
			cin>>name;
			cout<<"\n\t\tEnter Account Number: ";
			cin>>acno;
			cout<<"\n\t\tEnter Account Type: ";
			cout<<"\n\n\t\t\t\t1)SAVINGS ACCOUNT";
			cout<<"\n\n\t\t\t\t2)DEMAT ACCOUNT";
			cout<<"\n\n\t\t\t\t3)VIP SAVINGS ACCOUNT";
			cout<<"\n\n\t\tEnter your choice: ";
			cin>>choice;
			if(choice == 1)
			{
				cout<<"\n\n\t\tSavings Account Created..........\n";
				cout<<"\n\n\t\tEnter Opening Balance: ";
				cin>>amt;
				bank[0]->Deposit(amt);
			}
			else if(choice == 2)
			{
				cout<<"\n\n\t\tDemat Account Created..........\n";
				cout<<"\n\n\t\tEnter Opening Balance: ";
				cin>>amt;
				bank[1]->Deposit(amt);
			}
			else if(choice == 3)
			{
				cout<<"\n\n\t\tVIP Savings Account Created..........";
				cout<<"\n\n\t\tAmount should be more than "<<minbalance<<" for Transactions";
				cout<<"\n\n\t\tEnter Opening Balance: ";
				cin>>amt;
				bank[2]->Deposit(amt);
			}
			else
			{
				cout<<"\n\t\tINVALID Choice";
			}
			break;
		case 2:
			if(choice == 1)
			{
				cout<<"\n\n\t\tTotal "<<j<<" Transactions Left";
				cout<<"\n\n\t\tEnter Amount to be Deposited: ";
				cin>>amt;
				bank[0]->Deposit(amt);
				j--;
			} 
			else if(choice == 2)
			{
				cout<<"\n\t\tEnter Amount to be Deposited: ";
				cin>>amt;
				bank[1]->Deposit(amt);
			}
			else if(choice == 3)
			{
				cout<<"\n\n\t\tTotal "<<i<<" Transactions Left";
				cout<<"\n\n\t\tEnter Amount to be Deposited: ";
				cin>>amt;
				bank[2]->Deposit(amt);
				i--;
			}
			else
			{
				cout<<"\n\n\t\tCreate Account to Deposit.............";
			}
			break;
		case 3: 
			if(choice == 1)
			{
				cout<<"\n\n\t\tTotal "<<j<<" Transactions Left";
				cout<<"\n\n\t\tEnter Amount to be Withdrawn: ";
				cin>>amt;
				bank[0]->Withdraw(amt);
				j--;
			} 
			else if(choice == 2)
			{
				cout<<"\n\t\tEnter Amount to be Withdrawn: ";
				cin>>amt;
				bank[1]->Withdraw(amt);
			}
			else if(choice == 3)
			{
				cout<<"\n\n\t\tTotal "<<i<<" Transactions Left";
				cout<<"\n\n\t\tMinimum Balance of "<<minbalance<<" is Mandatory";
				cout<<"\n\n\t\tEnter Amount to be Withdrawn: ";
				cin>>amt;
				bank[2]->Withdraw(amt);
				i--;
			}
			else
			{
				cout<<"\n\n\t\tCreate Account to Withdraw.............";
			}
			break;
		case 4: 
			if(choice == 1)
			{
				cout<<"\n\t\t\t\t\tDETAILS";
				cout<<"\n\t\t\t\t\tAccount Holders Name: "<<name;
				cout<<"\n\t\t\t\t\tAccount Number: "<<acno;
				cout<<"\n\t\t\t\t\tAccount Type: SAVINGS ACCOUNT ";
				cout<<"\n\t\t\t\t\tBalance: "<<bank[0]->CheckBalance();
			}
			else if(choice == 2)
			{
				cout<<"\n\t\t\t\t\tDETAILS";
				cout<<"\n\t\t\t\t\tAccount Holders Name: "<<name;
				cout<<"\n\t\t\t\t\tAccount Number: "<<acno;
				cout<<"\n\t\t\t\t\tAccount Type: DEMAT ACCOUNT ";
				cout<<"\n\t\t\t\t\tBalance: "<<bank[1]->CheckBalance();
			}
			else if(choice == 3)
			{
				cout<<"\n\t\t\t\t\tDETAILS";
				cout<<"\n\t\t\t\t\tAccount Holders Name: "<<name;
				cout<<"\n\t\t\t\t\tAccount Number: "<<acno;
				cout<<"\n\t\t\t\t\tAccount Type: VIP SAVINGS ACCOUNT ";
				cout<<"\n\t\t\t\t\tBalance: "<<bank[2]->CheckBalance();
			}
			break;
		case 5: 
			return 0;
			break;
		}
	}while(1);
}


