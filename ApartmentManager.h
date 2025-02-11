#pragma once
#include "string"
#include "IApartament.h"
#include "Apartament.h"
#include "iostream"
#include "vector"
#include "memory"
#include "algorithm"

using namespace std;

class ApartmentManager
{
private:
    vector<shared_ptr<IApartament>> apartments;

public:
    void addApartment(shared_ptr<IApartament> apartment);

    void removeApartmentByAddress(const string& address);

    void updateApartmentByAddress(const string& address);

    shared_ptr<IApartament> searchByAddress(const string& address) const;

    void printAll() const;

    void menu();
};
