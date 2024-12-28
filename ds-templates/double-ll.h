#include <iostream>
#include "ll-node.h"


template<class T>
class DoubleLL
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int length;

	public:
  		DoubleLL()
		{
			head = nullptr;
			tail = nullptr;
			length = 0;
		}

		void AddtoHead(T value)
		{
			Node<T>* temp = new Node<T>(value);
			if (head == nullptr && tail == nullptr)
			{
			head = tail = temp;
			}
			else
			{
			head->prev = temp;
			temp->next = head;
			head = temp;
			}
			length++;
		}

		void AddtoTail(T value)
		{
			Node<T>* temp = new Node<T>(value);
			if (head == nullptr && tail == nullptr)
			{
				head = tail = temp;
			}
			else
			{
				temp -> prev = tail;
				temp->next = nullptr;
				tail->next = temp;
				tail = temp;
			}
			length++;
		}

		void Insertat(T value,int pos)
		{
			Node<T>* temp = new Node<T>(value);
			if(pos >= length)
			{
			AddtoTail(value);
			return;
			}
			else if(pos <= 0)
			{
			AddtoHead(value);
			return;
			}
			else
			{
				Node<T>* finder = head;
				for(int i = 0; i < pos; i++) finder = finder->next;
				temp->next = finder->next;
				if(finder->next) finder->next->prev = temp;
				finder->next = temp;
				temp->prev = finder;
				length++;
			}
		}

		void RemoveHead()
		{
			if (head == nullptr) exit(-1);
			Node<T>* temp = head;
			head = head->next;
			head->prev = nullptr;
			length--;
			delete temp;
		}

		void RemoveTail()
		{
			if (tail == nullptr) return;
			Node<T>* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			length--;
			delete temp;
		}

		void RemoveItem(T value)
		{
			Node<T>* temp = head;
			if (head == nullptr) return;
			while (temp != nullptr)
			{
				if (temp->data == value)
				{
					Node<T>* element = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete element;
					length--;
				}
			}
		}

		bool isEmpty() const
		{
			return length == 0;
		}

		void clear()
		{
			while (head != nullptr)
			{
				Node<T>* temp = head;
				head = head -> next;
				delete temp;
			}
		}

		bool search(T val)
		{
			Node<T>* temp = head;
			while (temp) {
				if (temp->data == val) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
 
		~DoubleLL()
		{
			clear();
		}

		void incrementQuantity(T val) {
			Node<T>* temp = head;
				while (temp) {
					if (temp->data == val) {
						temp->quantity++;
						return;
					}
					temp = temp->next;
				}
		}

		void decrementQuantity(T val) {
			Node<T>* temp = head;
				while (temp) {
					if (temp->data == val) {
						temp->quantity--;
						break;
					}
					temp = temp->next;
				}
				if (temp->quantity ==0 ) RemoveItem(val);
		}

		 Node<T>* getHead() {
			return head;
		}

		Node<T>* getTail() {
			return tail;
		}
};