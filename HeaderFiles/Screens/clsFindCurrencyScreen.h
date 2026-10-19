#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../lib/clsInputValidate.h"
#include "../Core/clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
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

    static short _ChooseFindType()
    {
        cout << "Find By: [1]Code , [2]Country: ";
        short Option = clsInputValidate::ReadNumberBetween<short>(1, 2);
        return Option;
    }

    static clsCurrency _FindCurrencyObj(short FindTypeOption)
    {
        switch (FindTypeOption)
        {
        case 1:
        {
            cout << "Enter Currency Code: ";
            string CurrencyCode = clsInputValidate::ReadString();
            return clsCurrency::FindByCode(CurrencyCode);
        }

        case 2:
        {
            cout << "Enter Country Name: ";
            string CountryName = clsInputValidate::ReadString();
            return clsCurrency::FindByCountry(CountryName);
        }
        }
        return clsCurrency(clsCurrency::enMode::EmptyMode, "", "", "", 0);
    }

    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency is Not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("Find Currency Screen");

        short FindTypeOption = _ChooseFindType();

        clsCurrency Currency = _FindCurrencyObj(FindTypeOption);

        _ShowResult(Currency);
    }
};