#include "Cipher.h"


Cipher::Cipher(){
    for (int i=0; i<4; i++){
        cout<<"Add a Keyword: "<<endl;
        string kword;
        cin>>kword;
        Keyword k(kword);
        cKeyword.push_back(k);
    }
}



