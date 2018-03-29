
#include <iostream>
#include "zakupy.h"
#include <fstream>
#include <string>


using namespace std;


void Purchase::Test(TotalPrice TP, Purchase p, Food f[], List *&Start)
{
    p.ClearList(Start);
    for(int i=0; i<2; i++)
    {
        List *New;
        New = Start;
        New = new List;
        New->Amount=1;
        New->Price=f[i].Price*New->Amount;
    }
    TP.Count(TP, Start);

};

void Purchase::ChoseCategory(Purchase p, Food f[], Alcohol a[], Book b[], Toy t[], List *&Start)
{
    cout<<"What category you want to chose from?"<<endl;
    cout<<"1. Food"<<endl;
    cout<<"2. Alcohol"<<endl;
    cout<<"3. Toys"<<endl;
    cout<<"4. Books"<<endl;
    int decision;
    decision=Check(4);
    switch ( decision )
    {
        case 1:
            p.BuyFood(f, Start);
            break;

        case 2:
            BuyAlcohol(a, Start);
            break;

        case 3:
            BuyToy(t, Start);
            break;

        case 4:
            BuyBook(b, Start);
            break;
    }


};

void TotalPrice::Count(TotalPrice TP, List *&Start)
{
    List *Current;
    while(Start)
    {
        Current=Start;
        Start=Start->Next;
        TP.Sum=(TP + Current->Price).get();
    }
    cout<<TP.Sum<<endl;
};

void Purchase::BuyFood(Food f[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<f[i].Number<<endl;
            cout<<f[i].Name<<endl;
            cout<<f[i].Quantity<<endl;
            cout<<f[i].ExpirationDate<<endl;
            cout<<f[i].Price<<endl;
    }
    cout<<"\nWhich food would you like to buy?"<<endl;
    cout<<"Object number: ";
    int decision, amount;
    decision=Check(8)-1;
    cout<<"How many would you like to purchase?"<<endl;
    cout<<"Amount of chosen item: ";
    cin>>amount;
    f[decision].IsUsed=amount;
    List *New;
    New = Start;
    New = new List;
    New->Assignation=2;
    New->Name=f[decision].Name;
    New->Amount=f[decision].IsUsed;
    New->Price=f[decision].Price*New->Amount;
};

void Purchase::BuyAlcohol(Alcohol a[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<"\n"<<a[i].Number<<endl;
            cout<<a[i].Name<<endl;
            cout<<a[i].Type<<endl;
            cout<<"Alcohol contained: "<<a[i].Percentage<<endl;
            cout<<a[i].Price<<endl;
    }
    cout<<"\nWhich food would you like to buy?"<<endl;
    cout<<"Object number: ";
    int decision, amount;
    decision=Check(8)-1;
    cout<<"How many would you like to purchase?"<<endl;
    cout<<"Amount of chosen item: ";
    cin>>amount;
    a[decision].IsUsed=amount;
    List *New;
    New = Start;
    New = new List;
    New->Assignation=3;
    New->Name=a[decision].Name;
    New->Amount=a[decision].IsUsed;
    New->Price=a[decision].Price*New->Amount;
};

void Purchase::BuyToy(Toy t[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<t[i].Number<<endl;
            cout<<t[i].Name<<endl;
            cout<<t[i].Price<<endl;
    }
    cout<<"\nWhich food would you like to buy?"<<endl;
    cout<<"Object number: ";
    int decision, amount;
    decision=Check(8)-1;
    cout<<"How many would you like to purchase?"<<endl;
    cout<<"Amount of chosen item: ";
    cin>>amount;
    t[decision].IsUsed=amount;
    List *New;
    New = Start;
    New = new List;
    New->Assignation=4;
    New->Name=t[decision].Name;
    New->Amount=t[decision].IsUsed;
    New->Price=t[decision].Price*New->Amount;
};

void Purchase::BuyBook(Book b[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<b[i].Number<<endl;
            cout<<b[i].Name<<endl;
            cout<<b[i].Author<<endl;
            cout<<b[i].Type<<endl;
            cout<<b[i].Price<<endl;
    }
    cout<<"\nWhich food would you like to buy?"<<endl;
    cout<<"Object number: ";
    int decision, amount;
    decision=Check(8)-1;
    cout<<"How many would you like to purchase?"<<endl;
    cout<<"Amount of chosen item: ";
    cin>>amount;
    b[decision].IsUsed=amount;
    List *New;
    New = Start;
    New = new List;
    New->Assignation=5;
    New->Name=b[decision].Name;
    New->Amount=b[decision].IsUsed;
    New->Price=b[decision].Price*b[decision].IsUsed;
    New->Price=b[decision].Price*New->Amount;
};

void Purchase::ShowList(List *&Start)
{
    List *Current=Start;
    if(!Current) cout<<"There are no purchases on the list yet"<<endl;
    else
    {
        int decision, Amount=0;
        cout<<"Which products would you like to see?"<<endl;
        cout<<"1. All of them!"<<endl;
        cout<<"2. Food"<<endl;
        cout<<"3. Alcohol"<<endl;
        cout<<"4. Toys"<<endl;
        cout<<"5. Books"<<endl;
        decision=Check(5);
        while(Current)
        {
            if (Current->Assignation==decision || decision==1)
            {
                cout<<Current->Name<<"\tx "<<Current->Amount<<"\t"<<Current->Price<<endl;
                Amount++;
            }
            Current=Current->Next;
        }
        if(Amount==0) cout<<"There are no purchases of this class on the list yet"<<endl;
    }
}

void Purchase::ClearList(List *&Start)
{
    List *Current;
    while(Start)
    {
        Current=Start;
        Start=Start->Next;
        delete Current;
    }
};

void Purchase::MostExpensive(List *&Start)
{
    List *Current;
    int Expensive=0;
    while(Start)
    {
        Current=Start;
        Start=Start->Next;
        if (Current->Price>Expensive) Expensive=Current->Price;
    }
    while(Start)
    {
        Current=Start;
        Start=Start->Next;
        if (Current->Price==Expensive) cout<<Current->Name<<"\tx "<<Current->Amount<<"\t"<<Current->Price<<endl;
    }

};

