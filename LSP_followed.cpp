#include<bits/stdc++.h>
using namespace std;

class DepositOnly{
public:
    virtual void deposit(double amount)=0;
};
class Withdraw: public DepositOnly{
public:
    virtual void withdraw(double amount)=0;
};

class SavingAccount: public Withdraw{
private:
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

class CurrentAccount: public Withdraw{
private:
    double balance;
public:
    CurrentAccount(){
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

class FixedTermAccount: public DepositOnly{
private:
    double balance;
public:
    FixedTermAccount(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" balance: "<<balance<<endl;
    }
};

class BankClient{
private:
    vector<Withdraw*> withdrawableacc;
    vector<DepositOnly*>depositonly;
public:
    BankClient(vector<Withdraw*>withdrawableacc, vector<DepositOnly*>depositonly){
        this->withdrawableacc=withdrawableacc;
        this->depositonly=depositonly;
    }
    void processTransactions(){
        for(Withdraw *acc: withdrawableacc){
            acc->deposit(100);
            acc->withdraw(500);
        }
        for(DepositOnly* acc: depositonly){
            acc->deposit(5000);
        }
    }
};

int main(){
    vector<Withdraw*>withdrawableacc;
    withdrawableacc.push_back(new SavingAccount());
    withdrawableacc.push_back(new CurrentAccount());
    vector<DepositOnly*>depositonly;
    depositonly.push_back(new FixedTermAccount());

    BankClient* client=new BankClient(withdrawableacc,depositonly);
    client->processTransactions();
}