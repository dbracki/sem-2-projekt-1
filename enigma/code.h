#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node{
    char basic;
    char show;
    Node *next;
    Node *prev;
};

template <typename T>
class List
{
private:

    T kod;
    Node<T> *head;
    Node<T> *current;

    char showcode(Node<T> *current);

    public:
        void test();
        void addcode(T i);
        void decode();
        void code(int i);
        void createnode(char c);
        string codeword(string word);
        T getcode();
        List<T>();


};

template class List<int>;
template class List<double>;
template class List<char>;


#endif // CODE_H
