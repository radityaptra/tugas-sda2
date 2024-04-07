#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedlList(){
			head = tail = NULL;
		}
		void InsertToTail(char data){
			Node *node = new Node();
			node->id = data;
			
			if (head==NULL){
				head = tail = NULL;
			} else {
				Node *tmp = head;
			}

		}
		
		void InsertToHead(char data){
			Node *node = new Node();
			node->id = data;
			
			if (head==NULL){
				head = tail = NULL;
			} else {
				Node *tmp = head;
			}

		}
		
		void insertNodeAfter(char data, char after){
			
			if (head==NULL){
				cout << "Error Linkedlist Empty" <<endl;
			} else{
				Node *node = new Node();
				node->id = data;
				
				Node *tmp = head;
				while (tmp->id!=after && tmp!=NULL){
					tmp = tmp->next;
				}
			}
		}
		
};

int main(int argc, char** argv) {
	
	LinkedList *link1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	link1->head = node1;
	link1->tail = node1;
	
	cout << node1 << endl;
	cout << link1->head << endl;
	cout << link1->head->id << endl;
	cout << link1->head->next << endl;
	cout << link1->tail->id << endl << endl;
	
	Node *node2 = new Node();
	node2->id = 'B';
	
	link1->tail->next = node2;
	link1->tail = node2;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	Node *node3 = new Node();
	node3->id = 'R';
	
	Node *tmp = link1->head;
	
	link1->head = node3;
	node3->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	Node *node4 = new Node();
	node4->id = 'D';
	
	link1->head = node4;
	node4->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	Node *nodeX = new Node();
	nodeX->id = 'U';
	
	link1->head = nodeX;
	nodeX->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	return 0;
}