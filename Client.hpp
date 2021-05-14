#ifndef Client_hpp
#define Client_hpp

#include<iostream>
using namespace std;


class Client
{
public:
    Client(string name, string lastName, string cpf);
    
    int getId();

    string getName();
    void setName(string name);

    string getLastName();
    void setLastName(string lastName);
    
    string getCpf();
    void setCpf(string cpf);

private:
    int id;

    string name;
    string lastName;
    string cpf;

    int static lastId;
    int generateId();
};

#endif