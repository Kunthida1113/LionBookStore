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
void DbLinkedList::Node::setInfo(Member m,Book b){
	this->M = m;
	this->B = b;
}

DbLinkedList::DbLinkedList(){
    this->head=NULL;
    this->tail=NULL;
    count=0;
}
DbLinkedList::~DbLinkedList(){
	for(int i=1;i<count;i++){
		Node *tmp = this->head;
		tmp =this->head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
int DbLinkedList::size(){
	return count;
}
void DbLinkedList::AddBook(Book b){
	Node *NewNode = new Node();
	NewNode->setBook(b);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		tail->link = NewNode;
		NewNode->plink = tail;
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
		tail->link = NewNode;
		NewNode->plink = tail;
		tail = NewNode;
		count++;
	}
}
void DbLinkedList::AddStaff(Staff s){
	Node *NewNode = new Node();
	NewNode->setStaff(s);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		tail->link = NewNode;
		NewNode->plink = tail;
		tail = NewNode;
		count++;
	}
}
void DbLinkedList::ShowCategory(string cate){
	cout<<"================================================================================================================="<<endl;
    cout<<left<<setw(12)<<"ID Books"<<left<<setw(55)<<"Books Name"<<left<<setw(30)<<"Author"<<left<<setw(10)<<"Year"<<left<<setw(10)<<"Price"<<endl;
	cout<<"================================================================================================================="<<endl;
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		if(temp->B.getCate()==cate){
			cout<<left<<setw(12)<<temp->B.getIdBook()<<left<<setw(55)<<temp->B.getNameBook()<<left<<setw(30)<<temp->B.getAuthor()
			<<left<<setw(10)<<temp->B.getYear()<<left<<setw(10)<<temp->B.getRentPrice()<<endl;
		}
	}
	cout<<"================================================================================================================="<<endl;
}
Book DbLinkedList::getBook(string idBook){
	Book b;
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		if(temp->B.getIdBook() == idBook){
			b = temp->B;
		}
	}
	return b;
}
Book DbLinkedList::getBook(int index){
	Book b;
	Node * tmp = head;
    for(int i=1;i<=index;i++){
        if(index==1&&i==index){
            b = tmp->B;
        }
        else if(i==index){
            tmp = tmp->link;
            b = tmp->B;
        }
    }
	return b;
}
Member DbLinkedList::getMember(int index){
	Member m;
	Node * tmp = head;
    for(int i=1;i<=index;i++){
        if(index==1&&i==index){
            m = tmp->M;
        }
        else if(i==index){
            tmp = tmp->link;
            m = tmp->M;
        }
    }
	return m;
}
Book DbLinkedList::getBookName(string NameBook){
	Node *temp = new Node;
	while (temp != NULL){
		if(NameBook==temp->B.getNameBook())
		{
			return temp->B;
		}
		
	}
}//ของเนมนะจ๊ะ

Member DbLinkedList::getMember(string id){
	Member m;
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		if(temp->M.getId()==id){
			m = temp->M;
			return m;
		}
	}
}
Staff DbLinkedList::getStaff(string id){
	Staff s;
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		if(temp->S.getId()==id){
			s = temp->S;
			return s;
		}
	}
}
bool DbLinkedList::LoginMember(string idUser,string password){
	Node *tmp;
	for(tmp=head; tmp != NULL; tmp=tmp->link){
		if(tmp->M.getId() == idUser && tmp->M.getPass() == password){
			return true;
		}
	}
	return false;
}
bool DbLinkedList::LoginStaff(string idUser,string password){
	Node *tmp;
	for(tmp=head; tmp != NULL; tmp=tmp->link){
		if(tmp->S.getId() == idUser && tmp->S.getPass() == password){
			return true;
		}
	}
	return false;
}
 void DbLinkedList::ShowBookList(){
	 int i=1;
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		cout<<i<<"."<<temp->B.getIdBook()<<setw(20)<<left<<temp->B.getNameBook()<<setw(20)<<left<<temp->B.getAuthor()<<setw(20)<<left<<temp->B.getRentPrice()<<setw(20)<<left<<temp->B.getBuyPrice()<<endl;
		i++;
	}
 }