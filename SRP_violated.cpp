#include<bits/stdc++.h>
using namespace std;

class Product{
public:
    string name;
    double price;
    //constructor
    Product(string name, double price){
        this->name=name;
        this->price=price;
    }
};

// ..VIOLATES SRP..
class ShoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }
    const vector<Product*>&getProduct(){
        return products;
    }
    // 1. Calc total price in cart
    double calculateTotal(){
        double total=0;
        for(auto p: products) total+=p->price;
        return total;
    }
    // 2. Violates SRP - prints invoice
    void printInvoice(){
        cout<<"Shopping Cart Invoice"<<endl;
        for(auto p:products) cout<<p->name<<" $"<<p->price<<endl;
        cout<<"Total: "<<calculateTotal()<<endl;
    }
    // 3. Violating SRP - Saves to DB
    void saveToDB(){
        cout<<"Saving to db"<<endl;
    }
};

int main(){
    ShoppingCart* cart=new ShoppingCart;
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse",50));
    cart->printInvoice();
    cart->saveToDB();
}