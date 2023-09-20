#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account 
{
private:
	int id;
	double balance;
	double annualInterestRate;
public: 
	Account() 
	{
		id = 0;
		balance = 0;
		annualInterestRate = 0;
	}
	int getID()const
	{
		return id;
	}
	double getBalance()const
	{
		return balance;
	}
	double getAnnualInterestRate()const
	{
		return annualInterestRate;
	}
	void setID(int id) {
		this->id = id;
	}
	void setBalance(double bal) 
	{
		if (bal > 0)
			balance = bal;
	}
	void setAnnualInterestRate(double rate)
	{
		if (rate > 0)
			annualInterestRate = rate;
	}
	double getMonthlyInterestRate()const
	{
		return annualInterestRate / 12;
	}
	void withdraw(double amount)
	{
		if (amount > 0 && amount < balance)
			balance = balance - amount;
		else
			cout << "Sorry, you have insuffucuent funds" << endl;
	}
	void deposit(double amount) {
		if (amount > 0)
			balance += amount;
	}
	double getMonthlyInterest()const
	{
		return getMonthlyInterestRate() * getBalance() / 100;
	}
};

int main() 
{
	Account myAccount;
	myAccount.setID(1122);
	myAccount.setBalance(20000);
	myAccount.setAnnualInterestRate(4.5);
	
	cout << "Account Details:" << endl;
	cout << "Account ID: " << myAccount.getID() << endl;
	cout << "Account Balance: $" << myAccount.getBalance() << endl;
	cout << "Account Interest Rate Percentage: " << myAccount.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate Percentage: " << myAccount.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest Earned: $" << myAccount.getMonthlyInterest() << endl;

	cout << endl;
	cout << "Withdrawing $2500 amount..\n";
	myAccount.withdraw(2500);
	cout << "Account Balance: $" << myAccount.getBalance() << endl;
	cout << "Monthly Interest Earned: $" << myAccount.getMonthlyInterest() << endl;

	cout << endl;
	cout << "Depositing $3000 amount..\n";
	myAccount.deposit(3000);
	cout << "Account Balance: $" << myAccount.getBalance() << endl;
	cout << "Monthly Interest Earned: $" << myAccount.getMonthlyInterest() << endl;

	return 0;
}
