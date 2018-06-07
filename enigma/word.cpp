#include "word.h"

using namespace std;
Word::Word(string W)
{
    Data=W;
    Coded=W;
}

string Word::GetData(){
    return Data;
}

string Word::GetCoded(){
    return Coded;
}

string Word::SetCoded(string word){
    Coded=word;
    return Coded;
}
