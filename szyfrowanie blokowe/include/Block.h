#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>

using namespace std;

class Block
{
    public:
        Block();
        char info[8];
        int bytes[64];
        char isChar(int x);

    private:

};

#endif // BLOCK_H
