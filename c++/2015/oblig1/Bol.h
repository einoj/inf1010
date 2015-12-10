#include <cstddef>
#include <iostream>
using namespace std;

template <class T> class Bol
{
  public:
    Bol () {
      _beboer = NULL;
    }

    T* beboer() {
      return _beboer;
    }

    void settInn(T* t);
    T* taUt();
    bool tomt();
  private:
    T* _beboer;
};

//template <class T> T Bol<T>::beboer()
//{
//  return _beboer;
//}

template <class T> void Bol<T>::settInn(T* t)
{
  _beboer = t;
}

/*I am pretty sure that this function delets the object stored in BOL.
 * However I should test it for memory leakage in valgrind
 */
template <class T> T* Bol<T>::taUt()
{
  T* t = _beboer; 
  // Sett the pointer to the mouse to NULL
  //OBS! the object still exists in memory
  //_beboer is just not pointing at it
  _beboer = NULL; 
  return t;       // return the address to the object
}

template <class T> bool Bol<T>::tomt()
{
  if (_beboer == NULL)
  {
    return true;
  } else {
    return false;
  }
}
