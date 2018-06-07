#include <iostream>
#include "interface.h"


bool Interface::Run(){
    cout<<"\nWhat would you like to do?"<<endl;
    cout<<"1.Add a word to be coded"<<endl;
    cout<<"2.Add a code"<<endl;
    cout<<"3.Decode automatically (only if coded manually)"<<endl;
    cout<<"4.Decode manually"<<endl;
    cout<<"5.Display coded words"<<endl;
    cout<<"6.Display code properties"<<endl;
    cout<<"7.Load/Save to file"<<endl;
    cout<<"8.Test"<<endl;
    cout<<"9.End program"<<endl;
    switch(GetNumber(9))
    {
        case 1:{
            cout<<"Wyraz do zakodowania: ";
            string W;
            cin>>W;
            wl.AddWord(W);
            }

            break;

        case 2:
            ChoseCode(1);
            break;

        case 3:
            Decode();
            break;

        case 4:
            ChoseCode(-1);
            break;

        case 5:
            wl.ShowWords();
            break;

        case 6:
            showcodes();
            break;

        case 7:
            Files();
            break;

        case 8:
            test();
            break;

        case 9:
            return false;

    }
    return true;

}

int Interface::GetNumber(int Range){

    int Choice;
    std::cin >> Choice;
    while(std::cin.fail() || Choice<1 || Choice>Range)
    {
        std::cout << "Wrong number, or not number at all. Pick one of AVAILABLE choices" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> Choice;
    }
    return Choice;
}

bool Interface::AddList(){
    CodeInt.addcode(0);
    CodeDouble.addcode(0);
    CodeChar.addcode(0);
    char c='a';
    for (int i=0; i<26; i++){
        CodeInt.createnode(c);
        CodeDouble.createnode(c);
        CodeChar.createnode(c);
        c=c+1;
    }
    return true;
}

Interface::Interface(){
}

void Interface::ChoseCode(int i){
    if(i==1)cout<<"How do you want to code the given words?"<<endl;
    else cout<<"By which one do you want to decode the given words?"<<endl;
    cout<<"1.Character"<<endl;
    cout<<"2.Number"<<endl;
    cout<<"3.Double digit"<<endl;
    switch(GetNumber(3))
    {
        case 1:
            CodeChar.code(i);
            break;

        case 2:
            CodeInt.code(i);
            break;

        case 3:
            CodeDouble.code(i);
            break;

    }
    if(wl.Words.empty()) cout<<"You didn't add any words to be coded"<<endl;
    else{
    for (int i=0; i<wl.Words.size(); i++){
        wl.Words[i].SetCoded(CodeChar.codeword(wl.Words[i].GetCoded()));
        wl.Words[i].SetCoded(CodeInt.codeword(wl.Words[i].GetCoded()));
        wl.Words[i].SetCoded(CodeDouble.codeword(wl.Words[i].GetCoded()));
        }
    }
}

void Interface::Decode(){
    CodeChar.decode();
    CodeInt.decode();
    CodeDouble.decode();
    for (int i=0; i<wl.Words.size(); i++){
        wl.Words[i].SetCoded(wl.Words[i].GetData());
    }

}

bool Interface::test(){
    string w="daniel";
    CodeInt.test();
    for (int i=0; i<w.length(); i++){
        if(w[i]-2>'a' && w[i]-2<'z')        w[i]-=2;
        else w[i]+=24;
        }
    cout<<"Word being coded - daniel"<<endl;
    cout<<"Word after coding - "<<w<<endl;
    cout<<"Code used: 2"<<endl;
    if(w=="bylgcj") cout<<"Test was succesfull"<<endl;
    else cout<<"Test was unsuccesfull"<<endl;
}

void Interface::Files(){
    cout<<"1.Save to File"<<endl;
    cout<<"2.Load from file (deletes current codes and words)"<<endl;
    switch(GetNumber(3)){
        case 1:
            Fsave();
            break;

        case 2:
            Fload();
            break;
    }
}

bool Interface::Fsave(){
    fstream File;
    string name;
    cout<<"What is the name of file?"<<endl;
    cin>>name;
    File.open(name, ios::out);
    File<<CodeInt.getcode()<<endl;
    File<<CodeDouble.getcode()<<endl;
    File<<CodeChar.getcode()<<endl;
    for(int i=0; i<wl.Words.size(); i++)
    {
        File<<wl.Words[i].GetCoded()<<endl;
    }
    File.close();
    return true;
}


bool Interface::Fload(){
    wl.Words.clear();
    fstream File;
    string name;
    cout<<"What is the name of file?"<<endl;
    cin>>name;
    File.open(name, ios::in);
    if(File.good()==false)
    {
        cout<<"Sorry, couldn't find "<<name<<" :("<<endl;
        return false;
    }
    int codei;
    double coded;
    char codec;
    File>>codei;
    CodeInt.addcode(codei);
    File>>coded;
    CodeDouble.addcode(coded);
    File>>codec;
    CodeChar.addcode(codec);
    string data;
    do{
        File>>data;
        wl.AddWord(data);
    }
    while(File.good());
    File.close();
    return true;
}

void Interface::showcodes(){

    cout<<"Number :"<<CodeInt.getcode()<<endl;
    cout<<"Double digit :"<<CodeDouble.getcode()<<endl;
    cout<<"Character :"<<CodeChar.getcode()<<endl;

}
