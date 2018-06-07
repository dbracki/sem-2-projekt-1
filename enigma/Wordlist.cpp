#include <string>
#include "Wordlist.h"

void WordList::AddWord(string W){
    Word w(W);
    Words.push_back(w);
}

void WordList::ShowWords(){
    if(Words.empty()) cout<<"You didn't add any words to be coded"<<endl;
    else{
        for(auto i=0; i<Words.size(); ++i){
            cout<<Words[i].GetData()<<" - "<<Words[i].GetCoded()<<endl;
        }
    }
}

