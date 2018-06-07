#include "code.h"

template <typename T>
List<T>::List()
{
    kod = 0;
    kod = 'a';
    head = nullptr;
    current = nullptr;
}

template <typename T>
void List<T>::createnode(char c)
{
    Node<T> *temp=new Node<T>;
    temp->basic=c;
    temp->show=c;
    if(head==NULL)
    {
    head=temp;
    head->next=head;
    head->prev=head;
    temp=NULL;
    }
    else
    {
    temp->next=head->next;
    head->next->prev=temp;
    head->next=temp;
    temp->prev=head;

    }
}

template <typename T>
void List<T>::code(int i){
    if (i==1) cout<<"What number/character you want to use to code?"<<endl;
    else cout<<"What number/character you want to use to decode?"<<endl;
    T data;
    cin>>data;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cin>>data;
    }
    data=data*i;
    kod = kod+data;
    current=head;
    Node<T> *temp= new Node<T>;
    temp=head;
    if(data>0){
        for (int i=0; i<data; i++){
            temp=temp->next;
        }
        for(int i=0; i<26; i++){
            current->show=temp->basic;
            temp=temp->next;
            current=current->next;
        }
    }
    else{
        for (int i=data; i<0; i++){
            temp=temp->prev;
        }
        for(int i=0; i<26; i++){
            current->show=temp->basic;
            temp=temp->next;
            current=current->next;
        }
    }
}
template <typename T>
void List<T>::decode(){
    current=head;
    for (int i=0; i<26; i++){
        current->show=current->basic;
        current=current->next;
    }
}

template <typename T>
T List<T>::getcode(){
    return kod;
}
template <typename T>
void List<T>::addcode(T i){
    kod=i;
}

template <typename T>
string List<T>::codeword(string word){
    for (int i=0; i<word.length(); i++){
        current=head;
        while(word[i]!=current->basic){
            current=current->next;
        }
        word[i]=current->show;
    }
    return word;
}

template <typename T>
void List<T>::test(){
    current=head;
    Node<T> *temp= new Node<T>;
    temp=head;
    for (int i=0; i<2; i++){
        temp=temp->next;
    }
    for(int i=0; i<26; i++){
        current->show=temp->basic;
        temp=temp->next;
        current=current->next;
    }
}




