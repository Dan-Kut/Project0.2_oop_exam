#pragma once
#include "Apartament.h"
class LuxuryApartament : virtual public Apartament
{
private:
    string conciergeService;
    bool privatePool;

public:
    LuxuryApartament(const string& address, int price, const string& conciergeService, bool privatePool);

    void setConciergeService(const string& service);
    void setPrivatePool(bool pool);

    string getConciergeService() const;
    bool hasPrivatePool() const;

    void print() const override;
};

