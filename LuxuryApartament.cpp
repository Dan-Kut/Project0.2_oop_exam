#include "LuxuryApartament.h"

LuxuryApartament::LuxuryApartament(const string& address, int price, const string& conciergeService, bool privatePool)
    : Apartament(address, price), conciergeService(conciergeService), privatePool(privatePool) {}

void LuxuryApartament::setConciergeService(const string& service) { conciergeService = service; }
void LuxuryApartament::setPrivatePool(bool pool) { privatePool = pool; }

string LuxuryApartament::getConciergeService() const { return conciergeService; }
bool LuxuryApartament::hasPrivatePool() const { return privatePool; }

void LuxuryApartament::print() const
{
    cout << "Luxury Apartment: ";
    cout  << "Address: " << address << ", Price: " << price << endl;
    cout << " Concierge Service: " << conciergeService << ", Private Pool: " << privatePool << endl;
}