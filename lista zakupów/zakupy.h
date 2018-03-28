#include <iostream>

using namespace std;

struct List
{
    int Assignation;
    string Name;
    int Amount;
    double Price;
    List *Next;
};

class Menu
{
    public:
        void ShowList(List *&Start);
        void ShowOptions();
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

class Purchase
{
    public:
        void MostExpensive(List *&Start);
        void ClearList(List *&Start);
        void ShowList(List *&Start);
        void ChoseCategory(Purchase p, Food f[], Alcohol a[], Book b[], Toy t[], List *&Start);
        void BuyFood(Food *f, List *&Start);
        void BuyToy(Toy *t, List *&Start);
        void BuyAlcohol(Alcohol *a, List *&Start);
        void BuyBook(Book *b, List *&Start);
        void AddItem(List *&Start);
        int TotalPrice();
};

