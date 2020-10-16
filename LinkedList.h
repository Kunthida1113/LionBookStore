#include<iostream>
#include"Book.h"
#include"Member.h"
#include"Staff.h"
using namespace std;
class LikedList
{
    private:
        class Node{
            public:
                Book B;
                Member M;
                Staff S;
                Node *link;
                Node();
                Node(Book b,Member m, Staff s);
                void setBook(Book b);
                void setMember(Member m);
                void setStaff(Staff s);
        };
        Node *head;
        Node *tail;
        int count;
    public:
        LinkedList();
        ~LinkedList();
        void AddBook(Book b);
        void AddMember(Member m);

};