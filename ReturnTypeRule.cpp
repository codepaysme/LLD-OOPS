#include<bits/stdc++.h>
using namespace std;

/*
RETURN TYPE RULE

subtype overriden method return type should be either
identical or narrower than parent's return type.
also caller covariance.
*/

class Animal{
    // 
};
class Dog : public Animal{
    //
};
class Parent{
public:
    virtual Animal* getAnimal(){
        cout<<"parent returns animal instance"<<endl;
        return new Animal();
    }
};
class Child: public Parent{
public:
    Dog* getAnimal() override {
        cout<<"child returns dog instance"<<endl;
        return new Dog();
    }
};

class Client{
private:
    Parent *p;
public:
    Client(Parent* p){
        this->p=p;
    }
    void takeAnimal(){
        p->getAnimal();
    }
};

int main(){
    Parent *par=new Parent();
    Child* child=new Child();
    Client* client=new Client(child);
    client->takeAnimal();
    //output : child returning dog instance
}
