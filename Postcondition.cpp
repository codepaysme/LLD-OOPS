#include<bits/stdc++.h>
using namespace std;

/*
POST CONDITION
satisfied after a method is executed
child class can strengthen post condition, not weaken it.
*/

class Car{
protected:
    int speed;
public:
    Car(){
        speed=0;
    }
    void accelerate(){
        cout<<"car is accelerated"<endl;
        speed+=20;
    }
    //post condition : speed must reduce;
    virtual void bake(){
        cout<<"apply brakes"<<endl;
        speed-=20;
    }
};

class HybridCar: public Car{
private:
    int charge;
public:
    HybridCar() : Car(){
        charge=0;
    }
    // POST CONDITION : speed musst reduce after brake, charge must increase
    void brake(){
        cout<<"applying brakes"<<endl;
        speed-=20;
        charge+=20;
    }
};

