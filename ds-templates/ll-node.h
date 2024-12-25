template<class T>
class Node
{
public:
  T data;
  Node<T> *next;
  Node<T> *prev;

    Node()
    {
         data = NULL;
         next = nullptr;
         prev = nullptr;
    }
    Node(T data, Node<T> *n =nullptr, Node<T> *p =nullptr)
    {
      this->data = data;
      next = n;
      prev = p;
    }
};