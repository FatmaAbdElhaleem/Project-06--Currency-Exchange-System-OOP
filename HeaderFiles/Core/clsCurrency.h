#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../lib/clsString.h"
#include "../lib/Global.h"

class clsCurrency
{
public:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };

private:
    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
                           stod(vCurrencyData[3]));
    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    static vector<clsCurrency> _LoadCurrencysDataFromFile()
    {
        vector<clsCurrency> vCurrenciesData;
        fstream MyFile;
        MyFile.open(CurrenciesFileName, ios::in);
        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vCurrenciesData.push_back(Currency);
            }

            MyFile.close();
        }
        return vCurrenciesData;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> _vCurrenciesData)
    {
        fstream MyFile;
        MyFile.open(CurrenciesFileName, ios::out);
        string DataLine;
        if (MyFile.is_open())
        {

            for (clsCurrency C : _vCurrenciesData)
            {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsCurrency> _vCurrenciesData;
        _vCurrenciesData = _LoadCurrencysDataFromFile();
        for (clsCurrency &C : _vCurrenciesData)
        {
            if (C.CurrencyCode() == this->CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrenciesData);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    static vector<clsCurrency> GetAllUSDRates()
    {

        return _LoadCurrencysDataFromFile();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open(CurrenciesFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open(CurrenciesFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    bool IsEmpty()
    {
        return (this->_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    float Rate()
    {
        return _Rate;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C = FindByCode(CurrencyCode);
        return !C.IsEmpty();
    }

    static vector<clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }

    double ConvertToUSD(double Amount)
    {
        return Amount / Rate();
    }

    double ConvertToAnotherCurrency(double Amount, clsCurrency Currency2)
    {
        return (this->ConvertToUSD(Amount)) * Currency2._Rate;
    }
};
