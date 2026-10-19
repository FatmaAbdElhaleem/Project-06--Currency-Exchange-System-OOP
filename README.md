# Currency Exchange System

The Currency Exchange System is a C++ console-based application developed using Object-Oriented Programming (OOP). It allows users to manage currencies, view currency records, search for currencies, update exchange rates, and calculate currency conversions.

## 📌 Features

- **List Currencies:** Display all available currencies and their exchange rates.
- **Find Currency:** Search for a currency using its code or other supported criteria.
- **Update Currency Rate:** Modify the exchange rate of a selected currency.
- **Currency Calculator:** Calculate currency conversions based on stored exchange rates.
- **File Handling:** Store and retrieve currency data from a text file.

## 📂 Project Structure

```text
Project_Root/
│
├── Data/
│   └── Currencies.txt
│
├── HeaderFiles/
│   ├── Core/
│   │   └── clsCurrency.h
│   │
│   ├── Lib/
│   │   ├── Global.h
│   │   ├── clsDate.h
│   │   ├── clsInputValidate.h
│   │   ├── clsString.h
│   │   └── clsUtil.h
│   │
│   └── Screens/
│       ├── clsCurrenciesListScreen.h
│       ├── clsCurrencyCalculatorScreen.h
│       ├── clsCurrencyMainScreen.h
│       ├── clsFindCurrencyScreen.h
│       ├── clsScreen.h
│       └── clsUpdateCurrencyRateScreen.h
│
├── .gitignore
└── main.cpp
```

## ⚙️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Standard Template Library (STL)

## 🧰 Concepts Applied

- Classes and Objects
- Encapsulation
- Abstraction
- Inheritance
- Polymorphism
- Code Organization and Separation of Responsibilities

