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

class ShoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product *p) products.push_back(p);
    const vector<Product*>&getProduct(){
        return products;
    }
    double calculateTotal(){
        double total=0;
        for(auto p: products) total+=p->price;
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart *cart;
public:
    ShoppingCartPrinter(ShoppingCart *cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Shopping Cart Invoice"<<endl;
        for(auto p:products) cout<<p->name<<" $"<<p->price<<endl;
        cout<<"Total: "<<calculateTotal()<<endl;
    }
};


class ShoppingCartShortage{
private:
    ShoppingCart* cart;
public:
    ShoppingCartShortage(ShoppingCart *cart){
        this->cart=cart;
    }
    void saveToDB(){
        cout<<"saving to db"<<endl;
    }
};

int main(){
    ShoppingCart* cart=new ShoppingCart;
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer=new ShoppingCartPrinter(cart);
    cart->printInvoice();
    ShoppingCartShortage *db=new ShoppingCartShortage(cart);
    cart->saveToDB();
}