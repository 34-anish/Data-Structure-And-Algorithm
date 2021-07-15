#include <iostream>
#include <string>
#include <sstream>

using namespace std;


template <class T>
class DLL {
	private:
		T data;
	public:
		DLL* next;
		DLL* previous;
		DLL(T data);
		T getData();
		string toString();
		~DLL();
};

template <class T>
DLL<T>::DLL(T data) {
	this->data = data;
}

template <class T>
T DLL<T>::getData() {
	return this->data;
}

template <class T>
string DLL<T>::toString() {
	stringstream s;
	s << this->getData();
	return s.str();
}

template <class T>
DLL<T>::~DLL() { }

/* Linked List: */
 
template <class T>
class MyList {
	private:
		T* head;
		T* tail;
		int list_size;
	public:
		MyList();
		T* getHead();
		T* getTail();
		int size(bool update=false);
		void addtoTail(T* new_node);
		void addtoHead(T* new_node);
		void push(T* new_node);
		T* pop();
		T* peek();
		void enqueue(T* new_node);
		T* dequeue();
		T* get(int index);
		void printList();
		void printListBackwards();
		~MyList();
};

template <class T>
MyList<T>::MyList() {
	this->head = NULL;
	this->tail = NULL;
	this->list_size = 0;
}

template <class T>
T* MyList<T>::getHead() {
	return this->head;
}

template <class T>
T* MyList<T>::getTail() {
	return this->tail;
}

template <class T>
int MyList<T>::size(bool update) {
	if (!update) {
		return this->list_size;
	}
	int size = 0;
	T* temp = this->head;
	while (temp) {
		size++;
		temp = temp->next;
	}
	this->list_size = size;
	return this->list_size;
}

template <class T>
void MyList<T>::addtoTail(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if (this->head == NULL) {
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	} else {
		this->tail->next = new_node;
		new_node->previous = this->tail;
		this->tail = new_node;
		this->list_size = this->list_size + 1;
	}
}

template <class T>
void MyList<T>::addtoHead(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if (this->head == NULL) {
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	} else {
		this->head->previous = new_node;
		new_node->next = this->head;
		this->head = new_node;
		this->list_size = this->list_size + 1;
	}
}

template <class T>
void MyList<T>::push(T* new_node) {
	this->addtoHead(new_node);
}

template <class T>
T* MyList<T>::pop() {
	T* temp = this->head;
	this->head = this->head->next;
	this->head->previous = NULL;
	this->list_size = this->list_size - 1;
	return temp;
}

template <class T>
T* MyList<T>::peek() {
	return this->head;
}

template <class T>
void MyList<T>::enqueue(T* new_node) {
	this->addtoTail(new_node);
}

template <class T>
T* MyList<T>::dequeue() {
	return this->pop();
}

template <class T>
T* MyList<T>::get(int index) {
	if (index == 0) {
		return this->head;
	} else if (index == this->list_size - 1) {
		return this->tail;
	} else if (index < 0 || index >= this->list_size) {
		return NULL;
	}
	if (index < this->list_size / 2) {
		T* temp = this->head;
		int i = 0;
		while (temp) {
			if (i == index) { return temp; }
			i++;
			temp = temp->next;
		}
	} else {
		T* temp = this->tail;
		int i = this->list_size - 1;
		while (temp) {
			if (i == index) { return temp; }
			i--;
			temp = temp->previous;
		}
	}
	return NULL;
}

template <class T>
void MyList<T>::printList() {
	cout << "HEAD: ";
	T* temp = this->head;
	while(temp) {
		cout << temp->toString() << " -> ";
		temp = temp->next;
	}
	cout << "\b\b\b\b :TAIL" << endl;
}

template <class T>
void MyList<T>::printListBackwards() {
	cout << "TAIL: ";
	T* temp = this->tail;
	while(temp) {
		cout << temp->toString() << " -> ";
		temp = temp->previous;
	}
	cout << "\b\b\b\b :HEAD" << endl;
}

template <class T>
MyList<T>::~MyList() {
	while (this->head) {
		T* next = this->head->next;
		delete this->head;
		this->list_size = this->list_size - 1;
		this->head = next;
	}
}

void stackAsString() {
	MyList<DLL<string> > stack;
	int i = 0;
	cout << "String Stack:" << endl;
	
	stack.push(new DLL<string>("Alpha"));
	stack.push(new DLL<string>("Bravo"));
	stack.push(new DLL<string>("Charlie"));
	stack.push(new DLL<string>("Delta"));
	stack.push(new DLL<string>("Echo"));
	stack.push(new DLL<string>("Foxtrot"));
	stack.push(new DLL<string>("Golf"));
	stack.push(new DLL<string>("Hotel"));
	stack.push(new DLL<string>("India"));
	stack.push(new DLL<string>("Juliet"));
	stack.push(new DLL<string>("Kilo"));
	stack.push(new DLL<string>("Lima"));
	stack.push(new DLL<string>("Mike"));
	stack.push(new DLL<string>("November"));
	stack.push(new DLL<string>("Oscar"));
	stack.push(new DLL<string>("Papa"));
	stack.push(new DLL<string>("Quebec"));
	stack.push(new DLL<string>("Romeo"));
	stack.push(new DLL<string>("Sierra"));
	stack.push(new DLL<string>("Tango"));
	stack.push(new DLL<string>("Uniform"));
	stack.push(new DLL<string>("Victor"));
	stack.push(new DLL<string>("Whiskey"));
	stack.push(new DLL<string>("X-ray"));
	stack.push(new DLL<string>("Yankee"));
	stack.push(new DLL<string>("Zulu"));
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();
}

void stackAsInt() {
	MyList<DLL<int> > stack;
	int i = 0;
	cout << "Integer Stack:" << endl;
	
	for (i = 1; i < 27; i++) {
		stack.push(new DLL<int>(i));
	}
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();
}

void stackAsChar() {
	MyList<DLL<char> > stack;
	char c = 0;
	cout << "Character Stack:" << endl;
	
	for (c = 'A'; c < 'Z'+1; c++) {
		stack.push(new DLL<char>(c));
	}
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();	
}

int main()
{
	stackAsString();
	cout << endl << endl;
	stackAsInt();
	cout << endl << endl;
	stackAsChar();
	cout << endl << endl;
	return 0;
}