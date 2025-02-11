#pragma once
#include "iostream"
#include "vector"
#include "memory"
#include "algorithm"
using namespace std;

class IApartament
{
public:
    virtual const string getAddress() const = 0;
    virtual const int getPrice() const = 0;

    virtual void setAddress(const string& address) = 0;
    virtual void setPrice(int price) = 0;

    virtual void print() const = 0;
    virtual ~IApartament() {}
};

