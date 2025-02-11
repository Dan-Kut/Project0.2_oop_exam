#include "LuxuryStudioApartament.h"

void LuxuryStudioApartament::print() const
{
    cout << "Luxury Studio Apartment: ";
    Apartament::print();
    cout << " Concierge Service: " << getConciergeService()
        << ", Private Pool: " << (hasPrivatePool() ? "Yes" : "No")
        << ", Open Layout: " << (hasOpenLayout() ? "Yes" : "No") << endl;
}
