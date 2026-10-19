#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../lib/clsInputValidate.h"
#include "../Core/clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency, string CardTitle = "Currency Card:")
    {
        cout << "\n"
             << CardTitle << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static clsCurrency _GetCurrency(string Message)
    {
        cout << Message;
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Currency not found, Enter another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCalculationResults(clsCurrency Currency1, clsCurrency Currency2, double ExchangAmount)
    {

        _PrintCurrency(Currency1, "Convert From:");
        double AmountInUSD = Currency1.ConvertToUSD(ExchangAmount);
        cout << ExchangAmount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD" << endl;

        if (Currency2.CurrencyCode() == "USD")
            return;

        _PrintCurrency(Currency2, "Convert To:");
        double AmountInCurrency2 = Currency1.ConvertToAnotherCurrency(ExchangAmount, Currency2);
        cout << ExchangAmount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        _DrawScreenHeader("Currency Calculator Screen");
        do
        {
            clsCurrency Currency1 = _GetCurrency("Enter Currency1 Code: ");
            clsCurrency Currency2 = _GetCurrency("Enter Currency2 Code: ");

            cout << "Enter Amount to Exchange: ";
            double ExchangAmount = clsInputValidate::ReadNumber<double>();

            _PrintCalculationResults(Currency1, Currency2, ExchangAmount);

        } while (clsInputValidate::confirmMessage("Do you want to perform another calculation y/n ? "));
    }
};
