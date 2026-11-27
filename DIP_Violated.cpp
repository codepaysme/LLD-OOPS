#include<bits/stdc++.h>
using namepsace std;

class MysqlDB{
public:
    void saveToSQL(string data) cout<<"inserted into mysql"<<data<<endl;
};
class Mongo{
public:
    void saveToMongo(string data) cout<<"inserted into mongo"<<data<<endl;
};

class UserService{
private:
    MysqlDB *sql;
    Mongo *md;
public:
    void storeUserToSQL(string user) sql.saveToSQL(user);
    void storeUserToMongo(string user) md.saveToMongo(user);
};

int main(){
    UserService service;
    service.storeUserToMongo("aditya");
    service.storeUserToSQL("bharat");
}