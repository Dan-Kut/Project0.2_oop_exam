#pragma once
#include "Apartament.h"
class StudioApartament :
    public Apartament
{
private:
    bool openLayout;

public:
    StudioApartament(const string& address, int price, bool openLayout);

    void setOpenLayout(bool layout);
    bool hasOpenLayout() const;

    void print() const override;
};

