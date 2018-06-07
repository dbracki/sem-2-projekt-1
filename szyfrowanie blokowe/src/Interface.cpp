#include "Interface.h"


Interface::Interface(){
};


bool Interface::run(){

    cout<<"What would you like to do?"<<endl;
    cout<<"1. Code a message"<<endl;
    cout<<"2. Decode a message"<<endl;
    cout<<"3. End program"<<endl;
    int x;
    cin>>x;
    switch (x)
    {
        case 1:
            cm.code(1);
            break;

        case 2:
            cm.code(-1);
            break;

        case 3:
            return false;
    }
    return true;

}
