
#include <iostream>

using namespace std;


struct List
{
    int Assignation;
    string Name;
    int Amount;
    double Price;
    struct List *Next;
    struct List *Prev;
};

class TotalPrice
{
public:
    TotalPrice(double Total)
        :Sum(Total)
        { }
    TotalPrice operator +( const double & Total ) const
    {
        return TotalPrice(Total*1.23 + Sum );
    }

    const double & get() const
    {
        return Sum;
    }
    double Sum;
    double Count(TotalPrice TP, List *&Start);
};


class Menu
{
    public:
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
        int Total;
        void Test(TotalPrice TP, Purchase p, Food f[], Alcohol a[], Book b[], Toy t[], List *&Start);
        void MostExpensive(List *&Start);
        void ClearList( Food f[], Alcohol a[], Book b[], Toy t[], List *&Start);
        void ShowList(List *&Start);
        void ChoseCategory(Purchase p, Food f[], Alcohol a[], Book b[], Toy t[], List *&Start);
        void BuyFood(Food f[], List *&Start);
        void BuyToy(Toy t[], List *&Start);
        void BuyAlcohol(Alcohol a[], List *&Start);
        void BuyBook(Book b[], List *&Start);
        void AddItem(List *&Start);
};

int Check(int decision);
