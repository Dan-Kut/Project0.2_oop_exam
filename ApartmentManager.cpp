#include "ApartmentManager.h"
#include "LuxuryApartament.h"
#include "StudioApartament.h"
#include "LuxuryStudioApartament.h"

void ApartmentManager::addApartment(shared_ptr<IApartament> apartment)
{
	apartments.push_back(apartment);
}

void ApartmentManager::removeApartmentByAddress(const string& address)
{
	apartments.erase(remove_if(apartments.begin(), apartments.end(),
		[&address](const shared_ptr<IApartament>& apt) { return apt->getAddress() == address; }), apartments.end());
}

void ApartmentManager::updateApartmentByAddress(const string& address)
{
    if (auto apt = searchByAddress(address))
    {
        int choice;
        cout << "1. Update Address" << endl;
        cout << "2. Update Price" << endl;
        if (dynamic_pointer_cast<LuxuryApartament>(apt))
        {
            cout << "3. Update Concierge Service" << endl;
            cout << "4. Update Private Pool" << endl;
        }
        else if (dynamic_pointer_cast<StudioApartament>(apt))
        {
            cout << "3. Update Open Layout" << endl;
        }
        if (dynamic_pointer_cast<LuxuryStudioApartament>(apt))
        {
            cout << "5. Update Open Layout (Luxury Studio Specific)" << endl;
        }
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string newAddress;
            cout << "Enter new address: ";
            cin.ignore();
            getline(cin, newAddress);
            apt->setAddress(newAddress);
            break;
        }
        case 2:
        {
            int newPrice;
            cout << "Enter new price: ";
            cin >> newPrice;
            apt->setPrice(newPrice);
            break;
        }
        case 3:
            if (auto luxApt = dynamic_pointer_cast<LuxuryApartament>(apt))
            {
                string service;
                cout << "Enter new concierge service: ";
                cin.ignore();
                getline(cin, service);
                luxApt->setConciergeService(service);
            }
            else if (auto studioApt = dynamic_pointer_cast<StudioApartament>(apt))
            {
                bool layout;
                cout << "Open layout (1 - Yes, 0 - No): ";
                cin >> layout;
                studioApt->setOpenLayout(layout);
            }
            break;
        case 4:
            if (auto luxApt = dynamic_pointer_cast<LuxuryApartament>(apt))
            {
                bool pool;
                cout << "Private pool (1 - Yes, 0 - No): ";
                cin >> pool;
                luxApt->setPrivatePool(pool);
            }
        case 5:
            if (auto luxStudioApt = dynamic_pointer_cast<LuxuryStudioApartament>(apt))
            {
                bool layout;
                cout << "Open layout (1 - Yes, 0 - No): ";
                cin >> layout;
                luxStudioApt->setOpenLayout(layout);
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    else
    {
        cout << "Apartment not found." << endl;
    }
}

shared_ptr<IApartament> ApartmentManager::searchByAddress(const string& address) const
{
    for (const auto& apt : apartments)
    {
        if (apt->getAddress() == address)
        {
            return apt;
        }
    }
    return nullptr;
}

void ApartmentManager::printAll() const
{
    for (const auto& apt : apartments)
    {
        apt->print();
    }
}

void ApartmentManager::menu()
{
    int choice;
        while (true)
        {
            cout << "\n1. Add Apartment" << endl;
            cout << "2. Remove Apartment by Address" << endl;
            cout << "3. Search Apartment by Address" << endl;
            cout << "4. Update Apartment by Address" << endl;
            cout << "5. Print All Apartments" << endl;
            cout << "6. Exit" << endl;
            cout << "Choose an option: ";
            cin >> choice;

            if (choice == 6) break;

            string address;
            int price;
            switch (choice)
            {
            case 1:
                int typeChoice;
                cout << "Select Apartment Type: 1 - Standard, 2 - Luxury, 3 - Studio, 4 - Luxury Studio: ";
                cin >> typeChoice;
                cout << "Enter address: ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter price: ";
                cin >> price;

                if (typeChoice == 1)
                {
                    addApartment(make_shared<Apartament>(address, price));
                }
                else if (typeChoice == 2)
                {
                    string conciergeService;
                    bool privatePool;
                    cout << "Enter concierge service: ";
                    cin.ignore();
                    getline(cin, conciergeService);
                    cout << "Private pool (1 - Yes, 0 - No): ";
                    cin >> privatePool;
                    addApartment(make_shared<LuxuryApartament>(address, price, conciergeService, privatePool));
                }
                else if (typeChoice == 3)
                {
                    bool openLayout;
                    cout << "Open layout (1 - Yes, 0 - No): ";
                    cin >> openLayout;
                    addApartment(make_shared<StudioApartament>(address, price, openLayout));
                }
                else if (typeChoice == 4)
                {
                    string conciergeService;
                    bool privatePool, openLayout;
                    cout << "Enter concierge service: ";
                    cin.ignore();
                    getline(cin, conciergeService);
                    cout << "Private pool (1 - Yes, 0 - No): ";
                    cin >> privatePool;
                    cout << "Open layout (1 - Yes, 0 - No): ";
                    cin >> openLayout;
                    //addApartment(make_shared<LuxuryStudioApartament>(address, price, conciergeService, privatePool, openLayout));
                }
                else
                {
                    cout << "Invalid apartment type." << endl;
                }
                break;

            case 2:
                cout << "Enter address to remove: ";
                cin.ignore();
                getline(cin, address);
                removeApartmentByAddress(address);
                break;

            case 3:
                cout << "Enter address to search: ";
                cin.ignore();
                getline(cin, address);
                if (auto apt = searchByAddress(address))
                {
                    apt->print();
                }
                else
                {
                    cout << "Apartment not found." << endl;
                }
                break;

            case 4:
                cout << "Enter address to update: ";
                cin.ignore();
                getline(cin, address);
                updateApartmentByAddress(address);
                break;

            case 5:
                printAll();
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
            }
        }
}