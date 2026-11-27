#include<bits/std++.h>
using namespace std;

/*
Class variant of a parent class Object should not be broken
by child class Object.

Hence, child class can either maintain or strengthen the invariant 
but never narrows it down.

INVARIANT : BALANCE CANNOT BE NEGATIVE

*/

class BankAccount{
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0) throw invalid_argument("balance cant be neg");
        balance=b;
    }
    virtual void withdraw(double amt){
        if(balance-amt<0) throw runtime_error("insuff. funds");
        balance-=amt;
        cout<<"amt withdrawn, balance is "<<balance<<endl;
    }
};


// BREAKS VARIANT
class Cheat: public BankAccount{
public:
    Cheat(double b): BankAccount(b){

    }
    void withdraw(double amt) override{
        balance-=amt;
        cout<<"amount withdrawn, balance: "<<balance<<endl;
    }
};

int main(){
    BankAccount* bank=new BankAccount(100);
    bank->withdraw(100);
}