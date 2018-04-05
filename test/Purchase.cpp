
#include <iostream>
#include "zakupy.h"
#include <fstream>
#include <string>


using namespace std;


void Purchase::Test(TotalPrice TP, Purchase p, Food f[], Alcohol a[], Book b[], Toy t[], List *&Start)
{
    int Amount=3;
    List *New=new List;
    if(Start)
    {
        Start->Prev=New;
        New->Prev=NULL;
        New->Next=Start;

    }
    else {
    Start=New;
    New->Next=NULL;
    New->Prev=NULL;
    }
    New->Assignation=2;
    New->Name=f[1].Name;
    New->Amount=Amount;
    New->Price=f[1].Price*New->Amount;
    Amount=5;
    List *New2 = new List;
    Start->Prev=New2;
    New2->Prev=NULL;
    New2->Next=Start;
    New2->Assignation=2;
    New2->Name=f[3].Name;
    New2->Amount=Amount;
    New2->Price=f[3].Price*New->Amount;
    if(TP.Count(TP, Start)==30.66) cout<<"The tests went good"<<endl;
    else cout<<"The tests didn't work"<<endl;
    p.ClearList(f, a, b, t, Start);


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

double TotalPrice::Count(TotalPrice TP, List *&Start)
{
    List *Current;
    if(!Start) cout<<"There are nop items on the list"<<endl;
    else
    {
    Current=Start;
    while(Current)
    {

            TP.Sum=(TP + Current->Price).get();
            Current=Current->Next;
        }
        printf("Total price: %.2f\n", TP.Sum);
    }
    return TP.Sum;
};

void Purchase::BuyFood(Food f[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<"\n"<<f[i].Number<<endl;
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
    f[decision].IsUsed+=amount;
    List *New=new List;
    if(Start)
    {
        Start->Prev=New;
        New->Prev=NULL;
        New->Next=Start;
        Start=New;

    }
    else {
    Start=New;
    New->Next=NULL;
    New->Prev=NULL;
    }
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
    List *New=new List;
    if(Start)
    {
        Start->Prev=New;
        New->Prev=NULL;
        New->Next=Start;
        Start=New;

    }
    else {
    Start=New;
    New->Next=NULL;
    New->Prev=NULL;
    }
    New->Assignation=3;
    New->Name=a[decision].Name;
    New->Amount=a[decision].IsUsed;
    New->Price=a[decision].Price*New->Amount;
};

void Purchase::BuyToy(Toy t[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<"\n"<<t[i].Number<<endl;
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
    List *New=new List;
    if(Start)
    {
        Start->Prev=New;
        New->Prev=NULL;
        New->Next=Start;
        Start=New;

    }
    else {
    Start=New;
    New->Next=NULL;
    New->Prev=NULL;
    }
    New->Assignation=4;
    New->Name=t[decision].Name;
    New->Amount=t[decision].IsUsed;
    New->Price=t[decision].Price*New->Amount;
};

void Purchase::BuyBook(Book b[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<"\n"<<b[i].Number<<endl;
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
    List *New=new List;
    if(Start)
    {
        Start->Prev=New;
        New->Prev=NULL;
        New->Next=Start;
        Start=New;

    }
    else {
    Start=New;
    New->Next=NULL;
    New->Prev=NULL;
    }
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

void Purchase::ClearList(Food f[], Alcohol a[], Book b[], Toy t[],List *&Start)
{
    List *Current;
    while(Start)
    {
        Current=Start;
        Start=Start->Next;
        delete Current;
        for (int i=0; i<8; i++)
        {
            f[i].IsUsed=0;
            a[i].IsUsed=0;
            b[i].IsUsed=0;
            t[i].IsUsed=0;
        }
    }
};

void Purchase::MostExpensive(List *&Start)
{
    List *Current;
    double Expensive=0;
    Current=Start;
    while(Current)
    {
        if (Current->Price>Expensive) Expensive=Current->Price;
        Current=Current->Next;
    }
    Current=Start;
    while(Current)
    {

        if (Current->Price==Expensive) cout<<Current->Name<<"\tx "<<Current->Amount<<"\t"<<Current->Price<<endl;
        Current=Current->Next;
    }

};

