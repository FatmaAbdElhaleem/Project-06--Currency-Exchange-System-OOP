#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "../lib/clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyMainScreen : protected clsScreen
{
private:
    enum enCurrencyMainScreenOptions
    {
        eListCurrencies = 1,
        eFindCurrencies = 2,
        eUpdateRate = 3,
        eCurrencyCalc = 4
        // eMainMenue = 5
    };

    static void _goBackToCurrencyMainScreen()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        ShowCurrencyMainScreen();
    }

    static void _ShowCurrenciesListScreen()
    {
        // cout << "\nCurriencies List Screen Will Be Here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        // cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        // cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "\nCurrency Calculator Screen Will Be Here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyMainMenueOp(enCurrencyMainScreenOptions CurrencyMainOp)
    {
        switch (CurrencyMainOp)
        {
        case enCurrencyMainScreenOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _goBackToCurrencyMainScreen();
            break;
        }

        case enCurrencyMainScreenOptions::eFindCurrencies:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _goBackToCurrencyMainScreen();
            break;
        }

        case enCurrencyMainScreenOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _goBackToCurrencyMainScreen();
            break;
        }

        case enCurrencyMainScreenOptions::eCurrencyCalc:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _goBackToCurrencyMainScreen();
            break;
        }

            // case enCurrencyMainScreenOptions::eMainMenue:
            // {
            //
            // }
        }
    }

    static short _ReadCurrenciesMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

public:
    static void ShowCurrencyMainScreen()
    {
        system("cls");
        string Title = "Currency Exchange Main Screen";
        clsScreen::_DrawScreenHeader(Title);

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        // cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMainMenueOp((enCurrencyMainScreenOptions)_ReadCurrenciesMainMenueOptions());
    }
};
