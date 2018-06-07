#ifndef WORDLIST_H
#define WORDLIST_H

#include <vector>
#include"word.h"

using namespace std;

class WordList
{
    public:
        vector<Word> Words;

        void AddWord(string W);
        void ShowWords();


    protected:

    private:


};

#endif // WORDLIST_H
