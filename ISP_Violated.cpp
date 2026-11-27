#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual double area()=0;
    virtual double volume()=0;
};

class Square : public Shape{
private:
    double side;
public:
    Square(double s):side(s){

    }
    double area() override{
        return side*side;
    }
    double volume() override{
        throw logic_error("volume doesnt exist for square");
    }
};

class Rectangle : public Shape{
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w){}
    double area override{
        return length*width;
    }
    double volume() override{
        throw logic_error("volume doesnt exist for rectangle");
    }
};

class Cube : public Shape{
private:
    double side;
public:
    Cube(double s) : side(s){}
    double area() override{
        return 6*side*side;
    }
    double volume() override {
        return side*side*side;
    }
};

int main(){
    Shape* sq=new Square(5);
    Shape* rec=new Rectangle(4,6);
    Shape* cube=new Cube(3);
}