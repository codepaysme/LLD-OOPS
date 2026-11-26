#include<bits/stdc++.h>
using namespace std;

// method argument rule : 

/*
subtype method argument can be identical or wider than supertype
C++ imposes this by keeping signature identical
*/
class Parent{
public:
    virtual void print(string msg){
        cout<<"PARENT: "<<msg<<endl;
    }
};

class Child : public Parent{
public:
    void print(string msg) override{
        cout<<"CHILD :"<<msg<<endl;
    }
};

//Client tht pass string as msg as client expects

class Client{
private:
    Parent *p;
public:
    Client(Parent *p){
        this->p=p;
    }
    void printMsg(){
        p->print("Hello!");
    }
};

int main(){
    Parent* par=new Parent();
    Parent* chi=new Child();
    Client* client=new Client(child);
    // u can pass either parent or child
    client->printMsg();
}