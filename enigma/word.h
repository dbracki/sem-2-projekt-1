#include <iostream>

#ifndef WORD_H
#define WORD_H

using namespace std;

class Word
{
    public:

        Word(string W);
        string GetData();
        string GetCoded();
        string SetCoded(string word);

    private:
        string Data;
        string Coded;
};

#endif // WORD_H
