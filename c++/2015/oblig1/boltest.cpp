#include <iostream>
#include "Bol.h"
#include "Mus.h"

using namespace std;

int main(void)
{
 Bol<Mus> *musebolet = new Bol<Mus>();
 Mus *m1 = new Mus(37, false);
 musebolet->settInn(m1);
 musebolet->beboer()->infoOmTilstand("A");
 return 0;
}
  
