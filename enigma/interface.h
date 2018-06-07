#ifndef INTERFACE_H
#define INTERFACE_H
#include "word.h"
#include "code.h"
#include "Wordlist.h"
#include <vector>
#include <fstream>

using namespace std;

class Interface
{
    public:

        WordList wl;
        Interface();
        bool Run();
        bool AddList();
        void ChoseCode(int i);
        void Decode();
        void codeword(WordList wl);
        bool test();
        void Files();
        bool Fsave();
        bool Fload();
        void showcodes();

    private:

        List<int> CodeInt;
        List<double> CodeDouble;
        List<char> CodeChar;

        int GetNumber(int Range);
};

#endif // INTERFACE_H
