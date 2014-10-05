//*************************************************************
//
//  Accounts.cpp
//
//  This program contains a BankAccount class and two derived
//  classes - MoneyMarketAccount and CDAccount - and a function
//  for transferring from one account to another.  The three
//  classes have different rules for withdrawing funds; hence,
//  the withdraw function is virtual.  The main function tests
//  the classes and the transfer function.
//
//*************************************************************

#include <iostream>
#include <string>

using namespace std;

//
// Constants to indicate status after withdrawal attempt
//
const int OK = 0;
const int INSUFFICIENT_FUNDS = -1;

//=================================
//  BankAccount Class Declaration
//=================================
class BankAccount
{
public:
    BankAccount(string name, double balance);
    // Sets up a BankAccount object with the given name and balance
    
	BankAccount();      // Default Constructor Added to the exercise
    
    string getName() const;
    // Returns the name on the BankAccount
    
    double getBalance() const;
    // Returns the balance on the BankAccount
    
    void deposit(double amt);
    // Precondition: amt is a nonnegative number
    // Postcondition: amt has been added to the account balance
    
    virtual int withdraw(double amt);
    // Precondition: amt is a nonnegative number
    // Postcondition: amt has been subtracted from the balance if
    // there were sufficient funds (balance >= amt)
    // Returns 0 (OK) if the withdrawal was completed; -1 (INSUFFICIENT_FUNDS)
    // if there were insufficient funds.
    
protected:
    string acctName;
    double acctBalance;
};


//================================
//  MoneyMarketClass Declaration
//================================
class MoneyMarketAccount: public BankAccount
{
public:
    MoneyMarketAccount(string name, double balance);
    // Sets up a MoneyMarketAccount with the given name and balance
    
    virtual int withdraw(double amt);
    // Precondition: amt is a nonnegative integer
    // Postcondition: If numWithdrawals < FREE_WITHDRAWALS and
    // amt <= acctBalance, amt is subtracted from acctBalance and
    // numWithdrawals is incremented; if numWithdrawals >= FREE_WITHDRAWALS
    // and amt + WITHDRAWAL_FEE <= acctBalance, amt + WITHDRAWAL_FEE is
    // subtracted from acctBalance.
    // Returns 0 (OK) if either of the above occurred; otherwise returns
    // INSUFFICIENT_FUNDS (-1).
    
    int getNumWithdrawals() const;
    // Returns the number of withdrawals
    
private:
    int numWithdrawals;
    static const int FREE_WITHDRAWALS;
    static const double WITHDRAWAL_FEE;
};
// Allocate Memory and Initialize MoneyMarketAccount static fields
const int MoneyMarketAccount::FREE_WITHDRAWALS = 2;
const double MoneyMarketAccount::WITHDRAWAL_FEE = 1.50;

//==========================
//  CDAccount Declaration
//==========================
class CDAccount: public BankAccount
{
public:
    CDAccount(string name, double balance, double rate);
    // Sets up a CDAccount object with the name and balance and interestRate
    // equal to rate/100 (rate converted to decimal form)
    
    virtual int withdraw(double amt);
    // Precondition: amt is a nonnegative number
    // Postcondition: If amt + the penalty (PENALTY*interestRate*acctBalance)
    // is less than or equal to the account balance, the amount and the
    // penalty are subtracted from the balance.
    // Returns OK (0) if there were sufficient funds for the withdrawal and
    // returns INSUFFICENT_FUNDS (-1) otherwise.
    
private:
    double interestRate;
    static const double PENALTY;     //Will use 25% of interest
};
// Allocate Memory and Initialize CDAccount static field
const double CDAccount::PENALTY = 0.25; //25% of interest

void transfer (double amt, BankAccount& fromAcct, BankAccount& toAcct);
// Precondition: amt is a nonnegative number, fromAcct and toAccount
// exist.
// Postcondition: If there are sufficient funds in the fromAccount
// to cover amt plus any charges (withdrawal fee or penalties, depending
// on the type of account), amt plus any charges are subtracted from
// fromAcct and amt is added to toAcct.


//====================
//   main function
//====================
int main()
{
    string name;
    double balance;
    double interestRate;
    double amount;
    int choice;
    char moreTransfers;
    
    cout << endl;
    cout << "Transferring Money..." << endl;
    cout << "First set up three accounts - a basic account, a " << endl;
    cout << "Money Market account, and a Certificate of Deposit account."
    << endl;
    cout << endl;
    cout << "Enter the name of owner of the accounts: ";
    cin >> name;
    cout << "Enter the opening balance in the basic account: ";
    cin >> balance;
    BankAccount basicAcct(name, balance);
    cout << "Enter the opening balance in the Money Market Account: ";
    cin >> balance;
    MoneyMarketAccount moneyMarket(name, balance);
    cout << "Enter the opening balance for the CD: ";
    cin >> balance;
    cout << "Enter the interest rate for the CD (for example, 2 for 2%): ";
    cin >> interestRate;
    CDAccount CD(name, balance, interestRate);
    cout << endl;
    
    do
    {
        cout << "Choose a direction to transfer funds: " << endl;
        cout << "1. From the basic account to the Money Market Account" << endl;
        cout << "2. From the basic account to the CD" << endl;
        cout << "3. From the Money Market Account to the basic account" << endl;
        cout << "4. From the Money Market Account to the CD" << endl;
        cout << "5. From the CD to the basic account" << endl;
        cout << "6. From the CD to the Money Market Account" << endl;
        cout << "Enter the number of your choice: ";
        cin >> choice;
        cout << endl;
        
        cout << "Enter the amount to transfer: ";
        cin >> amount;
        cout << endl;
        
        switch (choice)
        {
            case 1:
                transfer(amount, basicAcct, moneyMarket);
                break;
            case 2:
                transfer (amount, basicAcct, CD);
                break;
            case 3:
                transfer (amount, moneyMarket, basicAcct);
                break;
            case 4:
                transfer (amount, moneyMarket, CD);
                break;
            case 5:
                transfer (amount, CD, basicAcct);
                break;
            case 6:
                transfer (amount, CD, moneyMarket);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        
        cout << endl;
        cout << "Current Balances: " << endl;
        cout << "Basic Account: " << basicAcct.getBalance() << endl;
        cout << "Money Market Account: " << moneyMarket.getBalance() << endl;
        cout << "CD Account: " << CD.getBalance() << endl;
        
        cout << "Transfer more money? (y/n): ";
        cin >> moreTransfers;
        cout << endl;
    }
    while (moreTransfers == 'y' || moreTransfers == 'Y');
    
    return 0;
    
}


//===========================
//  BankAccount Definitions
//===========================

BankAccount::BankAccount(string name, double balance)
{
    acctName = name;
    acctBalance = balance;
}

BankAccount::BankAccount()
{
    acctName = "Not Given";
    acctBalance = 0.0;
}



string BankAccount::getName() const
{
    return acctName;
}


double BankAccount::getBalance() const
{
    return acctBalance;
}


void BankAccount::deposit(double amt)
{
    if (amt < 0)
    {
        cout << "Attempt to deposit negative amount - program terminated."
        << endl;
        exit(1);
    }
    
    acctBalance += amt;
}


int BankAccount::withdraw(double amt)
{
    int status = OK;
    
    if (amt < 0)
    {
        cout << "Attempt to withdraw negative amount - program terminated."
        << endl;
        exit(1);
    }
    
    if (amt <= acctBalance)
        acctBalance -= amt;
    else
    {
        cout << "Amount exceeds balance - withdrawal denied." << endl;
        status = INSUFFICIENT_FUNDS;
    }
    return status;
}

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
//       WRITE THE CODE FOR THE FOLLOWING 3 MEMBER FUNCTIONS
//        FOR THE MoneyMarketAccount CLASS
// --------------------------------
MoneyMarketAccount::MoneyMarketAccount(string name, double balance)
{
    this->acctName = name;
    this->acctBalance = balance;
}

int MoneyMarketAccount::getNumWithdrawals() const
{
    return this->numWithdrawals;
}

int MoneyMarketAccount::withdraw(double amt)
{
    this->numWithdrawals++;
    
    this->acctBalance -= amt;
    
    if (this->acctBalance >= 0)
        return 0;
    else
        return -1;
}

// --------------------------------
// --------- END USER CODE --------
//       WRITE THE CODE FOR THE FOLLOWING 3 MEMBER FUNCTIONS
//        FOR THE CDAccount CLASS
// --------------------------------

CDAccount::CDAccount(string name, double balance, double rate)
{
    BankAccount::acctName = name;
    BankAccount::acctBalance = balance;
    this->interestRate = rate;
}

int CDAccount::withdraw(double amt)
{
    this->acctBalance -= amt;
    
    if (this->acctBalance >= 0)
        return 0;
    else
        return -1;
}

void transfer (double amt, BankAccount& fromAcct, BankAccount& toAcct)
{
    fromAcct.withdraw(amt);
    toAcct.deposit(amt);
}
