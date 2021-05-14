#include "Client.hpp"

int Client::lastId = 0;

Client::Client(string name, string lastName, string cpf)
{
    this->id = generateId();
    this->name = name; 
    this->lastName = lastName;
    this->cpf = cpf;
}

int Client::getId()
{
    return this->id;
}

string Client::getName()
{
    return this->name;
}

void Client::setName(string name)
{
    this->name = name;
}

string Client::getLastName()
{
    return this->lastName;
}

void Client::setLastName(string lastName)
{
    this->lastName = lastName;
}


string Client::getCpf()
{
    return this->cpf;
}

void Client::setCpf(string cpf)
{
    this->cpf = cpf;
}

int Client::generateId()
{
    lastId++;
    return lastId;
}