#include <iostream>
using namespace std;


class Stack{
	
	public:
		int size = 0;
		int top  = -1;
		char *items;
		
		Stack(int stackSize){ //constructor
			size = stackSize;
			items = new char[size];
		}
		
		void push(char item){
			if (top == size -1){ //jika stack penuh
				cout << "ERROR: Stack overflow, stack is full" << endl;
			} else {
				top++; //top = top+1;
				items[top] = item;
			}
		}
	
		char pop(){
			char item;
			
			if (top == -1){ //jika stack kosonh
				cout << "ERROR: Stack is empty" << endl;
			} else {
				item = items[top];
				//items[top] = '';
				top--;
			}
			
			return item;
		}
};

int main(int argc, char** argv){
	
	Stack kantong1(11);
	
	kantong1.push('A');
	kantong1.push('B');
	kantong1.push('C');
	kantong1.push('D');
	kantong1.push('Z');
	kantong1.push('R');
	kantong1.push('G');
	kantong1.push('I');
	kantong1.push('P');
	kantong1.push('Q');
	kantong1.push('U');
	
	
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	
	
	return 0;
}
