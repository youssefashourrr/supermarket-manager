#include "ll-node.h"

template<class T>
class DoubleLL
{
private:
  node<T>* head;
  node<T>* tail;
  int length;

public:
  Double_LL()
  {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }

  void AddtoHead(T value)
  {
    node<T>* temp = new node<T>(value);
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
    node<T>* temp = new node<T>(value);
    if (head == nullptr && tail == nullptr)
    {
      head = tail = temp;
    }
    else
    {
      temp -> prev = tail;
      tail->next = temp;
      tail = temp;
    }
    length++;
  }

  void Insertat(T value,int pos)
  {
    node<T>* temp = new node<T>(value);
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
        node<T>* finder = head;
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
    node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    length--;
    delete temp;
  }

  void RemoveTail()
  {
    if (tail == nullptr) return;
    node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    length--;
    delete temp;
  }

  void RemoveItem(T value)
  {
    node<T>* temp = head;
    if (head == nullptr) return;
    while (temp != nullptr)
    {
      if (temp->data == value)
      {
        node<T>* element = temp;
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
        node<T>* temp = head;
        head = head -> next;
        delete temp;
      }
  }

  ~Double_LL()
  {
    clear();
  }


};