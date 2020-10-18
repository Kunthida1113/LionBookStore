#include"DbLinkedList.h"
DbLinkedList::Node::Node(){
    link = NULL;
	plink = NULL;
}
DbLinkedList::Node::Node(Book b,Member m, Staff s){
    this->B = b;
    this->M = m;
    this->S = s;
    link = NULL;
	plink = NULL;
}
void DbLinkedList::Node::setBook(Book b){
	this->B = b;
}
void DbLinkedList::Node::setMember(Member m){
	this->M = m;
}
void DbLinkedList::Node::setStaff(Staff s){
	this->S = s;
}
DbLinkedList::DbLinkedList(){
    this->head=NULL;
    this->tail=NULL;
    count=0;
}
DbLinkedList::~DbLinkedList(){
	for(int i=0;i<count;i++){
		Node *tmp = head;
		tmp =head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
void DbLinkedList::AddBook(Book b){
	Node *NewNode = new Node();
	NewNode->setBook(b);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		NewNode->plink = tail;
		tail->link = NewNode;
		tail = NewNode;
		count++;
	}
}
void DbLinkedList::AddMember(Member m){
	Node *NewNode = new Node();
	NewNode->setMember(m);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		NewNode->plink = tail;
		tail->link = NewNode;
		tail = NewNode;
		count++;
	}
}
int DbLinkedList::size(){
	return count;
}
void DbLinkedList::ShowCategory(string cate){
	for(Node *tmp=head;tmp!=NULL;tmp=tmp->link){
		if(tmp->B.getCate()==cate){
			cout<<tmp->B.getId()<<"\t"<<tmp->B.getName()<<endl;
		}
	}
}
void DbLinkedList::ShowAllBook(){
	for(Node *tmp=head;tmp!=NULL;tmp=tmp->link){
			cout<<tmp->B.getId()<<endl;
	}
}

