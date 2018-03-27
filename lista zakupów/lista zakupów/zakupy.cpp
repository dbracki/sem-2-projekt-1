#include <iostream>
#include "zakupy.h"
#include <fstream>
#include <string>


using namespace std;

void LoadFood()
{
    fstream File;
    File.open("Food.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Food.txt\" :("<<endl;
    }
    else
    {
        string Line;
        Food f[10];
        for(int i=0; i<10; i++)
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
};

void LoadAlcohol()
{
    fstream File;
    File.open("Alcohol.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Alcohol.txt\" :("<<endl;
    }
    else
    {
        string Line;
        Alcohol a[10];
        for(int i=0; i<10; i++)
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
};

void LoadToy()
{
    fstream File;
    File.open("Toy.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Toy.txt\" :("<<endl;
    }
    else
    {
        string Line;
        Toy t[10];
        for(int i=0; i<10; i++)
        {
            t[i].Number=i+1;
            t[i].IsUsed=0;
            getline(File,Line);
            t[i].Name=Line;
            File>>t[i].Price;
        }
    }
    File.close();
};

void LoadBook()
{
    fstream File;
    File.open("Book.txt",ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find \"Book.txt\" :("<<endl;
    }
    else
    {
        string Line;
        Book b[10];
        for(int i=0; i<10; i++)
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
};

void LoadData()
{
    LoadFood();
    LoadAlcohol();
    LoadBook();
    LoadToy();

};

void ShowOptions()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Show the shopping list"<<endl;
    cout<<"2. Add an item to the shopping list"<<endl;
    cout<<"3. Clear the shopping list"<<endl;
    cout<<"4. Run tests"<<endl;
    cout<<"5. Exit program"<<endl;
    int decision;
    cin>>decision;
    switch ( decision )
    {
    case 1:

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    }

};


List::List
