#include<bits/stdc++.h>
using namepsace std;

/*
Subclass method shldnt be allowed state changes which parent
class never allowed
*/
class BankAccount{
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0) throw invalid_argument("bal cant be negative");
        balance=b;
    }
    // HISTORY CONSTRAINT : withdraw not allowed
    virtual void withdraw(double amt){
        if(balance-amount<0) throw runtime_error("insuff. funds");
        balance-=amt;
        cout<<"amt withdraw, bal: "<<balance<<endl;
    }
};

class FixedDeposit : public : BankAccount{
public: 
    FixedDeposit(double b):BankAccount(b){
        // LSP BREAKS-History constraint breaks
        //this class will break client code tht relies on withdraw
    }
    void withdraw(double amt) override{
        throw runtime_error("withdraw not allowed on FD");
    }
};

int main(){
    BankAccount* bankacc=new BankAccount(100);
    bankacc->withdraw(100);
}