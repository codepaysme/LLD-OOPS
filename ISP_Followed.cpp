#include<bits/stdc++.h>
using namespace std;

class twoD{
public:
    virtual double area()=0;
};

class threeD{
public:
    virtual double area()=0;
    virtual double volume()=0;
};

class Square : public twoD{
private:
    double side;
public:
    Square(double s) : side(s){}
    double area() override{
        return side*side;
    }
};

class Rectangle: public twoD{
private:
    double length, width;
public:
    Rectangle(double l, double w): length(l), width(w){}
    double area() override{
        return length*width;
    }
};

class Cube : public threeD{
private:
    double side;
public:
    Cube(double s) : side(s){}
    double area() override{
        return 6*side*side;
    }
    double volume() override{
        return side*side*side;
    }
};

int main(){
    twoD *sq=new Square(5);
    twoD *rec=new Rectangle(4,5);
    threeD *cub=new Cube(3);
    cout<<"square area"<<sq->area()<<endl;
    cout<<"rectangle area"<<rec->area()<<endl;
    cout<<"cube area"<<cub->area()<<endl;
    cout<<"cube volume"<<cub->volume()<<endl;
}