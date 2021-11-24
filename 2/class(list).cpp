#include <iostream>
using namespace std;

template <typename T>
class List {
public:
	List();
	~List();
	void pushback(T data);
	int getsize() {
		return (size);	
	}
	T& operator[](const int index);
	void pop_front();
	void clear();
	void insert(T value, T index);
	void push_front(T data);
	void removeAt(T index);
	void pop_back();
private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext=nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};
	int size;
	Node<T>* head;
};
template <typename T>
List <T>::List() {
	size = 0;
	head = nullptr;
}
template <typename T>
List <T>::~List() {
	
}
template <typename T>
void List <T>:: pushback(T data) {
	if (head == nullptr) {
		head = new Node <T>(data);
	}
	else {
		Node <T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node <T> *current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
template<typename T>
void List<T>::pop_front()
{
	Node <T>* temp = head;
	head = head->pNext;
	delete temp;
}
template<typename T>
void List<T>::clear()
{
	while (size) {
		 pop_front();
	}
}
template<typename T>
void List<T>::insert(T value, T index)
{
	if (index == 0) {
	push_front(value);
}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i = index - 1; i++) {
			previous = previous->pNext;

		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::push_front(T value)
{
	head = new Node <T>(value);
	size++;
}
template<typename T>
void List<T>::removeAt(T index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i = index - 1; i++) {
			previous = previous->pNext;

		}
		Node<T>* todelete = previous->pNext;
		previous->pNext = todelete->pNext;
		delete todelete;
		size--;
	}
}
template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}
int main() {
	setlocale(LC_ALL, "Russian");
	List<int> lst;
	lst.pushback(5);
	lst.pushback(12);	
	lst.pushback(22);
	lst.pushback(22);
	cout << "Вывожу все элементы списка" << endl;
	for (int i = 0; i < lst.getsize(); i++) {
		
		cout << lst[i] << endl;
	}
	cout << "Использую метод removeAt" << endl;
	lst.removeAt(1);
	cout << "Вывожу все элементы списка" << endl;
	for (int i = 0; i < lst.getsize(); i++) {

		cout << lst[i] << endl;
	}
	cout << "Использую метод insert" << endl;
	lst.insert(14, 1);
	cout << "Вывожу все элементы списка" << endl;
	for (int i = 0; i < lst.getsize(); i++) {

		cout << lst[i] << endl;
	}
	cout << "Вызываю вторую ячейку" << endl;
	cout << lst[2];
	
	return 0;
	

}