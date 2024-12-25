template<class T>
class node
{
public:
  T data;
  node<T> *next;
  node<T> *prev;

    node()
    {
         data = NULL;
         next = nullptr;
         prev = nullptr;
    }
    node(T data, node<T> *n =nullptr, node<T> *p =nullptr)
    {
      this->data = data;
      next = n;
      prev = p;
    }
};