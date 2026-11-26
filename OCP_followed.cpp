#include<bits/stdc++.h
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

// ABSTRACT CLASS 
class Persistence{
private:
    ShoppingCart *cart;
public:
//virtual method
    virtual void save(ShoppingCart *cart)=0;
};

class sqlPersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout<<"saving shopping cart to mysql"<<endl;
    }
};

class mongoPersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout<<"saving shopping cart to mongodb"<<endl;
    }
};

class filePersistence : public Persistence{
public:
    void save(ShoppingCart *cart) override{
        cout<<"saving shopping cart to file"<<endl;
    }
};

int main(){
    ShoppingCart* cart=new ShoppingCart;
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer=new ShoppingCartPrinter(cart);
    printer->printInvoice();
    Persistence *db=new sqlPersistence();
    Persistence *mongo=new mongoPersistence();
    Persistence *file=new filePersistence();
    db->saveToDB(cart);
    mongo->saveToDB(cart);
    file->saveToDB(cart);
}
