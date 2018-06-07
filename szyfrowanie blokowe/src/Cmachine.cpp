#include "Cmachine.h"
#include "message.h"
#include "Cipher.h"

Cmachine::Cmachine(){
};

void Cmachine::code(int x){

    message msg;
    int p=msg.Show().length()/64;
    Cipher code;
    int i=0;
    while(i<p){
        int y=0;
        for (int z=0; z<64; z++){
            msg.codeCharacter(i*64+z,(msg.cBlock[i].isChar(y) + (code.cKeyword[i].isChar(y + code.cKeyword[i].isDigit() ))*x)%256);
            cout<<(msg.cBlock[i].isChar(y) + (code.cKeyword[i].isChar(y + code.cKeyword[i].isDigit() ))*x)%256;
            y++;
            if(y>code.cKeyword[i].length()) y=0;
        }
        i++;
    }
    cout<<"Your coded mesage is:\n"<<msg.Show()<<endl;
    cout<<"Safe coded message to file?\n1. Yes\n2. No"<<endl;
    int decision;
    cin>>decision;
    if(decision==1) save(msg.Show());
}

void Cmachine::save(string msg){
    fstream File;
    string filename;
    cout<<"Name of file: "<<endl;
    cin>>filename;
    File.open(filename.c_str(), ios::out);
    File<<msg;
}
