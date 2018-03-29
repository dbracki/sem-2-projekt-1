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
        string Line;
        for(int i=0; i<8; i++)
        {
            a[i].Number=i+1;
            a[i].IsUsed=0;
            getline(File,Line);
            a[i].Name=Line;
            getline(File,Line);
            a[i].Type=Line;
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
        string Line;
        for(int i=0; i<8; i++)
        {
            f[i].Number=i+1;
            f[i].IsUsed=0;
            getline(File,Line);
            f[i].Name=Line;
            getline(File,Line);
            f[i].Quantity=Line;
            getline(File,Line);
            f[i].ExpirationDate=Line;
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
        string Line;
        for(int i=0; i<8; i++)
        {
            t[i].Number=i+1;
            t[i].IsUsed=0;
            getline(File,Line);
            t[i].Name=Line;
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
            getline(File,Line);
            b[i].Name=Line;
            getline(File,Line);
            b[i].Author=Line;
            getline(File,Line);
            b[i].Type=Line;
            File>>b[i].Price;
        }
    }
    File.close();
    List *Start;
    Start = nullptr;
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
        decision=Check(6);
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
            p.Test(TP, p, f, Start);
            break;

        case 7:
            Close=1;
            break;
        }
    }
};


