#include <iostream>
#include "Bol.h"
#include "Mus.h"
using namespace std;

class Katt
{
  public:
    Katt(string navn, int vekt, bool syk);
    Katt(string navn);
    Katt()
    {
      _vekt = 0;
      _antMus = 0;
      _syk = false;
    }
    string navn();
    int vekt();
    int antMus();
    bool syk();
    void bliSyk();
    void spisMus(int v);
    Mus* gaaPaaJaktI(Bol<Mus> *b);


  private:
    string _navn;
    int _vekt;  
    int _antMus;
    bool _syk;

};

Katt::Katt(string navn, int vekt, bool syk)
{
  _navn = navn;
  _vekt = vekt;
  _syk = syk;
  _antMus = 0;
}

Katt::Katt(string navn)
{
  _navn = navn;
  _vekt = 5000;
  _syk = false;
  _antMus = 0;
}

string Katt::navn()
{
  return _navn;
}

int Katt::vekt()
{
  return _vekt;
}

int Katt::antMus()
{
  return _antMus;
}

bool Katt::syk()
{
  return _syk;
}

void Katt::bliSyk()
{
  _syk = true;
}

void Katt::spisMus(int v)
{
  _vekt += v;
  _antMus++;
}

Mus* Katt::gaaPaaJaktI(Bol<Mus> *b)
{
  Mus *mm;
  if (b->tomt()) {
    cout << "her kommer aAAAAaa" << endl;
    return mm;
  } else {
    //bit mus
    mm = b->taUt();
    if (!mm->lever()) {
        //katter spiser ikke døde mus!
        return mm;
    }
    if (antMus() < 2) {
      //spis musen
      if (mm->syk()) {
        //katten blir syk hvis den spise en syk mus
        bliSyk();
      }
      spisMus(mm->vekt());
      //The cat ate the mouse so delete the object.
      //set the pointer to NULL so that we do not point 
      // at invalid memory
      delete mm; 
      mm = NULL; 
      return mm;
    } else if (!mm->syk()) {
      //katten er mett men biter musen likvel.
      // Hvis musen er frisk blir den syk.
      mm->bliSyk();
      return mm;
    } else if (mm->lever()) {
      // Hvis musen er syk dør den.
      mm->die();
      return mm;
    }
  }
  return mm;
}




