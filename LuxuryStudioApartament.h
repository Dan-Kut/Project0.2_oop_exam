#include "ApartmentManager.h"
#include "LuxuryApartament.h"
#include "StudioApartament.h"

class LuxuryStudioApartament : public LuxuryApartament, public StudioApartament
{
public:
    LuxuryStudioApartament(const string& address, int price, const string& conciergeService, bool privatePool, bool openLayout) : LuxuryApartament(address, price, conciergeService, privatePool), StudioApartament(address, price, openLayout)
    {
    }

    void print() const override;
};