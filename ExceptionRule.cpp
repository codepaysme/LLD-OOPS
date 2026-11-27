#include<iostream>
using namespace std;

/*

logic_error
-> invalid argument
-> domain error
-> length error
-> out of range

runtime error
-> range error
-> overflow error
-> underflow error

*/

class Parent{
public:
    virtual void getValue() noexcept(false){
        throw logic_error("parent error");
    }
};

class Child : public Parent{
public:
    void getValue() noexcept(false) override{
        throw out_of_range("child error");
    }
};

class Client{
private:
    Parent* p;
public: 
    Client(Parent *p){
        this->p=p;
    }
    void takeValue(){
        try{
            p->getValue();
        }
        catch(const logic_error &e){
            cout<<"logic error occured"<<e.what()<<endl;
        }
    }
};

int main(){
    Parent* par=new Parent();
    Child* child=new Child();
    Client* client=new Client(child);
    client->takeValue();
}