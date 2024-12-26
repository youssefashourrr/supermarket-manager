template<class T>
class Node
{
public:
  T data;
  Node<T> *next;
  Node<T> *prev;
  int quantity;

    Node()
    {
         data = NULL;
         next = nullptr;
         prev = nullptr;
         quantity=1;
    }
    Node(T data, Node<T> *n =nullptr, Node<T> *p =nullptr,int q=1)
    {
      this->data = data;
      next = n;
      prev = p;
      quantity = q;
    }
};