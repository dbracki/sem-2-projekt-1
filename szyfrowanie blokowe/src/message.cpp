#include "message.h"

message::message(){
    cout<<"Add a message (up to 255 characters):"<<endl;
    string message;
    cin>>message;
    int a=message.length();
    for(int x=0; x<a%64; x++){
        Block b;
        cout<<"blok "<<x<<endl;
        for (int i=0; i<a-x*64; i++){
            string mes;
            mes[i]=message[x*64+i];
            b.info=mes;
        }
    cout<<"blok "<<x<<endl;
    cBlock.push_back(b);
    cout<<"blok "<<x<<endl;
    }
};


void message::codeCharacter(int x, char c){
cMessage[x]=c;
}

string message::Show(){
return cMessage;
}
