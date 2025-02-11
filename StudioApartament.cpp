#include "StudioApartament.h"

StudioApartament::StudioApartament(const string& address, int price, bool openLayout)
    : Apartament(address, price), openLayout(openLayout) {}

void StudioApartament::setOpenLayout(bool layout) { openLayout = layout; }
bool StudioApartament::hasOpenLayout() const { return openLayout; }

void StudioApartament::print() const
{
    cout << "Studio Apartment: ";
    cout << "Address: " << address << ", Price: " << price << endl;
    cout << " Open Layout: " << openLayout << endl;
}