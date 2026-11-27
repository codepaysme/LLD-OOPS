#include<bits/stdc++.h>
using namespace std;

/*
precondition must be satisfied before a method can be executed
sub class can weaken precondition but cannot strenthen it;
*/

class User{
public:
    virtual void setPassword(string password){
        if(password.length()<8) throw invalid_argument("password shld be atleast 8 characters");
        cout<<"password set successfully"<<endl;
    }
};

class Admin:public User{
public:
    void setPassword(string password) override{
        if(password.length()<6) throw invalid_argument("password must be 6 characters long");
        cout<<"password set successfully"<<endl;
    }
};

int main(){
    User *u=new Admin();
    u->setPassword("Admin2");
}