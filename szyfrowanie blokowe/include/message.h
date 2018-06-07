#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <vector>

#include "Block.h"


using namespace std;

class message
{
    public:

        vector <Block> cBlock;
        message();
        void codeCharacter(int x, char c);
        string Show();


    private:
        string cMessage;

};

#endif // MESSAGE_H
