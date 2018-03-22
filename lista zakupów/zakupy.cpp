#include <iostream>
#include "zakupy.h"
#include <fstream>
#include <string>


using namespace std;

int pobierz()
{
    int x;
    fstream plik;
    plik.open("zakupy.txt",ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie udalo sie wczytac gotowej listy"<<endl;
    }
    else
    {
        string linia;
        plik>>x;
        lista p[x];
        for(int i=0; i<x; i++)
        {
            p[i].numer=i+1;
            p[i].uzycie=0;
            getline(plik,linia);
            p[i].kategoria=linia;
            getline(plik,linia);
            p[i].nazwa=linia;
            plik>>p[i].cena;
        }
    }
    plik.close();
    return x;
};

void wczytaj(int i){

};
