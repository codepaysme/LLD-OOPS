#include<bits/stdc++.h>
using namespace std;

class Account{
public:
    // virtual means abstract class
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;
};

class SavingAccount : public Account{
private:
    double balance;
public:
    SavingAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" new balance: "<<balance<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdraw: "<<amount<<" new balance: "<<balance<<endl;
        }
        else{
            cout<<"insufficient balance"<<endl;
        }
    }
};

class CurrentAccount : public Account{
private:
    double balance;
public:
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" new balance: "<<amount<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdraw: "<<amount<<" new balance: "<<balance<<endl;
        }
        else{
            cout<<"insufficient balance"<<endl;
        }
    }
};

class FixedTermAccount : public Account{
private:
    double balance;
public:
    FixedTermAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" new balance: "<<amount<<endl;
    }
    void withdraw(double amount){
        throw logic_error("withdrawal isnt allowed!!");
    }
};

class BankClient{
private:
    vector<Account*>accounts;
public:
    BankClient(vector<Account*>accounts){
        this->accounts=accounts;
    }
    void processTransactions(){
        for(Account* acc: accounts){
            acc->deposit(1000);
            try{
                acc->withdraw(500);
            }
            catch(const logic_error &e){
                cout<<"exception"<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*>accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client=new BankClient(accounts);
    client->processTransactions(); //throws exception when withdraw done
}