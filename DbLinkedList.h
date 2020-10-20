#ifndef DBLINKEDLIST_H
#define DBLINKEDLIST_H
#include<iostream>
#include"Book.h"
#include"Member.h"
#include"Staff.h"
using namespace std;
class DbLinkedList
{
    private:
        class Node{
            public:
                Book B;
                Member M;
                Staff S;
                Node *link;
                Node *plink;
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
        DbLinkedList();
        ~DbLinkedList();
        void AddBook(Book b);
        void AddMember(Member m);
        void AddStaff(Staff s);
        bool LoginMember(string idUser,string password); //เพิ่ม
        bool LoginStaff(string idUser,string password); //เพิ่ม
};
#endif