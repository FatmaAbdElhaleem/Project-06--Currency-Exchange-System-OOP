#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../lib/clsInputValidate.h"
#include "../Core/clsCurrency.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static void _ShowUpdateRate(clsCurrency &Currency)
    {
        cout << "\n Update Currency Rate: \n";
        cout << "-----------------------\n";
        cout << "Enter New Rate: ";
        float NewRate = clsInputValidate::ReadNumber<float>();
        Currency.UpdateRate(NewRate);
        cout << "\nCurrency Rate Updated Successfully :-)\n";
    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("Update Currency Screen");

        cout << "\n Please Enter Currency Code: ";
        string Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\n Currency is not found, Enter another code : ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);

        if (clsInputValidate::confirmMessage("Are you sure you want to update rate of this currency? y/n "))
        {
            _ShowUpdateRate(Currency);
            _PrintCurrency(Currency);
        }
    }
};
