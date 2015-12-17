#include <iostream>
using namespace std;

template <class E> class Mengde 
{
  public:
    Mengde() {
      head = NULL;
    }

    bool inneholder(E e) {
      Node* temp = head;
      while (temp->next) {
        if (temp->e == e)
          return true;
        temp = temp->next;
      }
      return false;
    }

    bool tom() {
      if (head)
        return false;
      else
        return true;
    }

    bool leggTil(E e) {
      if (inneholder(e))
        return false;
      Node* temp = head;
      while (temp) {
        temp = temp->next;
      }
      temp->e = e;
      return true;
    }

    E* fjernEldste() {
      if(tom())
        return NULL;

      Node* temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      E* r = &temp->e; 
      delete temp;
      temp = NULL;
      return r;
    }

    E* fjernNyeste() {
      E* r = &head->e; 
      delete head;
      head = head->next;
      return r;
    }


  private:
    class Node
    {
      public:
        E e;
        Node* next;
    };
  private:
    Node*  head;
};
