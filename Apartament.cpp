#include "Apartament.h"
Apartament::Apartament(const string& address, int price) : address(address), price(price) {}

const string Apartament::getAddress() const { return address; }
const int Apartament::getPrice() const { return price; }

void Apartament::setAddress(const string& address) { this->address = address; }
void Apartament::setPrice(int price) { this->price = price; }

void Apartament::print() const
{
    cout << "Standart - " << "Address: " << address << ", Price: " << price << endl;
}