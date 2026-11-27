#include<bits/stdc++.h>
using namespace std;

// ABSTRACTION (INTERFACE)
class Db{
public:
    virtual void save(string data)=0;
};
class MysqlDB : public Db{
public:
    void save(string data) override{
        cout<<"saving to mysql"<<data<<endl;
    }
};
class Mongo : public Db{
public:
    void save(string data) override{
        cout<<"saving to mongo"<<data<<endl;
    }
};

class UserService{
private:
    Database *db;
public:
    UserService(Database* database) db=database;
    void storeUser(string user) db->save(user);
};

int main(){
    MysqlDB sd;
    Mongo md;
    UserService serv(&md);
    serv.storeUser("aditya"); 
    UserService serv(&sd);
    serv.storeUser("aditya"); 
}