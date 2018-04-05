#include <iostream>
#include "zakupy.h"
#include <fstream>
#include <string>


using namespace std;

int Check (int decision)
{
    int Choice;
    std::cin >> Choice;
    while(std::cin.fail() || Choice<1 || Choice>decision)
    {
        std::cout << "Wrong number, or not number at all. Pick one of AVAILABLE choices" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> Choice;
    }
    return Choice;
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
};

void Menu::ShowOptions()
{
    int Close=0;
    TotalPrice TP(0);
    Food f[8];
    Alcohol a[8];
    Toy t[8];
    Book b[8];
    fstream File;
    File.open("Alcohol.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Alcohol.txt\" :("<<endl;
        Close=1;
    }
    else
    {
        for(int i=0; i<8; i++)
        {
            a[i].Number=i+1;
            a[i].IsUsed=0;
            File>>a[i].Name;
            File>>a[i].Type;
            File>>a[i].Percentage;
            File>>a[i].Price;
        }
    }
    File.close();
    File.open("Food.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Food.txt\" :("<<endl;
        Close=1;
    }
    else
    {
        for(int i=0; i<8; i++)
        {
            f[i].Number=i+1;
            f[i].IsUsed=0;
            File>>f[i].Name;
            File>>f[i].Quantity;
            File>>f[i].ExpirationDate;
            File>>f[i].Price;
        }
    }
    File.close();
    File.open("Toy.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Toy.txt\" :("<<endl;
        Close=1;
    }
    else
    {
        for(int i=0; i<8; i++)
        {
            t[i].Number=i+1;
            t[i].IsUsed=0;
            File>>t[i].Name;
            File>>t[i].Price;
        }
    }
    File.close();
    File.open("Book.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Book.txt\" :("<<endl;
        Close=1;
    }
    else
    {
        string Line;
        for(int i=0; i<8; i++)
        {
            b[i].Number=i+1;
            b[i].IsUsed=0;
            File>>b[i].Name;
            File>>b[i].Author;
            File>>b[i].Type;
            File>>b[i].Price;
        }
    }
    File.close();
    Purchase p;
    while (Close==0)
    {
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Show the shopping list"<<endl;
        cout<<"2. Add an item to the shopping list"<<endl;
        cout<<"3. Clear the shopping list"<<endl;
        cout<<"4. Show the most expensive purchase"<<endl;
        cout<<"5. Show total Price"<<endl;
        cout<<"6. Run tests"<<endl;
        cout<<"7. Exit program"<<endl;
        int decision;
        decision=Check(7);
        switch ( decision )
        {
        case 1:
            p.ShowList(Start);
            break;

        case 2:
            p.ChoseCategory(p, f, a, b, t, Start);
            break;

        case 3:
            p.ClearList(Start);
            break;

        case 4:
            p.MostExpensive(Start);
            break;

        case 5:
            TP.Count(TP, Start);
            break;

        case 6:

            break;

        case 7:
            Close=1;
            break;
        }
    }
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
    if (amount<1) cout<<"Wrong amount"<<endl;
    else
    {
        f[decision].IsUsed+=amount;
        List *New = new List;
        New->Prev->Next=Start;
        New->Prev=Start;
        Start->Next->Prev=New;
        Start->Next=New;
        New->Next=NULL;
        New->Assignation=2;
        New->Name=f[decision].Name;
        New->Amount=f[decision].IsUsed;
    }
};

void Purchase::BuyAlcohol(Alcohol a[], List *&Start)
{
    for(int i=0; i<8; i++)
    {
            cout<<"\n"<<a[i].Number<<endl;
            cout<<a[i].Name<<endl;
            cout<<a[i].Type<<endl;
            cout<<"Alcohol contained: "<<a[i].Percentage<<"%"<<endl;
            cout<<a[i].Price<<endl;
    }
    cout<<"\nWhich food would you like to buy?"<<endl;
    cout<<"Object number: ";
    int decision, amount;
    decision=Check(8)-1;
    cout<<"How many would you like to purchase?"<<endl;
    cout<<"Amount of chosen item: ";
    cin>>amount;
    if (amount<1) cout<<"Wrong amount"<<endl;
    else
    {
        a[decision].IsUsed+=amount;
        List *New;
        New = Start;
        New = new List;
        New->Assignation=3;
        New->Name=a[decision].Name;
        New->Amount=a[decision].IsUsed;
    }
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
    if (amount<1) cout<<"Wrong amount"<<endl;
    else
    {
        t[decision].IsUsed+=amount;
        List *New;
        New = Start;
        New = new List;
        New->Assignation=4;
        New->Name=t[decision].Name;
        New->Amount=t[decision].IsUsed;
    }
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
    if (amount<1) cout<<"Wrong amount"<<endl;
    else
    {
        b[decision].IsUsed+=amount;
        List *New;
        New = Start;
        New = new List;
        New->Assignation=5;
        New->Name=b[decision].Name;
        New->Amount=b[decision].IsUsed;
        New->Price=b[decision].Price*b[decision].IsUsed;
    }
};

void Purchase::ShowList(List *&Start)
{
    List *Current=Start;
    Current->Next=Start->Next;
    Current->Prev=Start->Prev;
    if(!Current->Next) cout<<"There are no purchases on the list yet"<<endl;
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
        Current=Current->Next;
        if (Current->Price>Expensive) Expensive=Current->Price;
    }
    while(Start)
    {
        Current=Start;
        Current=Current->Next;
        if (Current->Price==Expensive) cout<<Current->Name<<"\tx "<<Current->Amount<<"\t"<<Current->Price<<endl;
    }

};
