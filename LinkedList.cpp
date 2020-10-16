#include"LinkedList.h"
LikedList::Node::Node(){
    link = NULL;
}
LikedList::Node::Node(Book b,Member m, Staff s){
    this->B = b;
    this->M = m;
    this->S = s;
    link = NULL;
}
LinkedList::LinkedList(){
    this->head=NULL;
    this->tail=NULL;
    count=0;
}
LinkedList::~LinkedList(){
	for(int i=1;i<count;i++){
		Node *tmp = this->head;
		tmp =this->head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
void LinkedList::AddBook(Book b){
	Node *NewNode = new Node();
	NewNode->setBook(b);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
	}else{
		tail->link = NewNode;
		tail = NewNode;
		count++;
	}
}
void LinkedList::AddMember(Member m){
	Node *NewNode = new Node();
	NewNode->setMember(m);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
	}else{
		tail->link = NewNode;
		tail = NewNode;
		count++;
	}
}