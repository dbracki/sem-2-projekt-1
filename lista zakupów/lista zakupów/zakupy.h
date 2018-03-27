#include <iostream>

using namespace std;

class Purchase
{
        void ChoseCategory();
        void BuyFood();
        void BuyToy();
        void BuyAlcohol();
        void BuyBook();
        int TotalPrice();
};

class Menu
{
    public:
        void LoadData();
        void ShowOptions();
        void LoadFood();
        void LoadAlcohol();
        void LoadToy();
        void LoadBook();
};

class Food
{
    public:
        int Number;
        int IsUsed;
        string Name;
        string Quantity;
        string ExpirationDate;
        double Price;
};

class Alcohol
{
    public:
        int Number;
        int IsUsed;
        string Name;
        string Type;
        int Percentage;
        double Price;
};

class Toy
{
    public:
        int Number;
        int IsUsed;
        string Name;
        double Price;
};

class Book
{
    public:
        int Number;
        int IsUsed;
        string Name;
        string Author;
        string Type;
        double Price;
};

struct List
{
    string *Name;
    int Amount;
    double Price;
    List *Next;
    List *Previous;
    List::List();
};
