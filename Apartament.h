#pragma once
#include "IApartament.h"
class Apartament : virtual public IApartament
{
protected:
    string address;
    int price;

public:
    Apartament(const string& address = "no address", int price = 0);

    const string getAddress() const override;
    const int getPrice() const override;

    void setAddress(const string& address) override;
    void setPrice(int price) override;

    void print() const override;
};

