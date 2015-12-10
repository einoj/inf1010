#include "Mengde.h"
#include <string>
using namespace std;

/* 
  Testmetodekallene i  denne klassen kaller pÃ¥ metoder som ikke er generiske.
Ellers er klassen identisk med Oblig2TestB
  
Denne klassen skal du ikke trenge aa endre paa, den er bare til hjelp
for deg og for retterne(men lever den sammen med resten).

Konsentrer deg om en test om gangen og ikke vent til du er helt ferdig med
aa bruke testene. Lykke til!
*/

string bool_to_string(bool s)
{
  if (s)
    return "true";
  else
    return "false";
}

static void testBoolean(string description, bool expected, bool actual) {
    if (expected == actual) {
      cout << "OK - " << description << endl;
    } else {
      cout << "FEIL - " << description  << ". Skulle vaert: " << bool_to_string(expected) <<". Var: " << bool_to_string(actual) << endl;
    }
}

static void teststring(string description, string expected, string actual) {
if (expected == actual) {
   cout << "OK - " << description << endl;
    } else {
      cout << "FEIL - " << description  << ". Skulle vaert: " << expected <<". Var: " << actual << endl;
    }
}

template <typename T>
static void test(string description, T expected, T actual) {
if (expected != NULL && expected.equals(actual)) {
    cout << "OK - " << description << endl;
} else if (expected == actual) {
    cout << "OK - " << description << endl;
} else {
      cout << "FEIL - " << description  << ". Skulle vaert: " << expected <<". Var: " << actual << endl;
}
} 



int main(void) {
  //Oblig01einojo *o1 = new Oblig01einojo(); 
  //o1->hovedprogram();
  Mengde<string> *tomMengde = new Mengde<string>();
  testBoolean("tom() paa tom mengde returnerer true", true, tomMengde->tom());
  //      beskrivelse          forventet returverdi, det vi tester
  delete tomMengde;

  string *str = new string("Hei");
//  Mengde<string> *litenMengde = new Mengde<string>();
//  litenMengde->leggTil(str);
//  testBoolean("tom() paa ikke-tom mengde returnerer false", false, litenMengde->tom());
//
  Mengde<int> tallMengde;
  int *en = new int;
  *en = 1;
  testBoolean("inneholder() paa en tom mengde skal returnere false", false, tallMengde.inneholder<int>(en));
//  testBoolean("leggTil() med et nytt element skal returnere true", true, tallMengde.leggTil(en));
//  tallMengde.leggTil(2);
//  Integer tre = 3;
//  tallMengde.leggTil(tre);
//  tallMengde.leggTil(4);
//  Integer fem = 5;
//  tallMengde.leggTil(fem);
//  testBoolean("inneholder() skal returnere false for elementer som ikke er i mengden", false, tallMengde.inneholder(100));
//  testBoolean("inneholder() skal klare aa finne eldste element", true, tallMengde.inneholder(en));
//  testBoolean("inneholder() skal klare aa finne et element midt i mengden", true, tallMengde.inneholder(tre));
//  testBoolean("inneholder() skal klare aa finne nyeste element", true, tallMengde.inneholder(fem));
//  testBoolean("leggTil() med et eksisterende element skal returnere false", false, tallMengde.leggTil(tre));
//
//  teststring("fjernEldste() paa en tom mengde skal returnere NULL", NULL, tomMengde.fjernEldste());
//
//  Mengde<Boolean> boolMengde = new Mengde<>();
//  boolMengde.leggTil(true);
//  boolMengde.fjernEldste();
//  testBoolean("fjernEldste() paa en mengde med ett element skal gi en tom mengde", true, boolMengde.tom());
//
//  Mengde<string> halloMengde = new Mengde<>();
//  string hallo = "Hallo";
//  halloMengde.leggTil(hallo);
//  halloMengde.leggTil("Hei");
//  halloMengde.leggTil("Tjolahopp!");
//  teststring("fjernEldste() skal returnere det forste objektet vi la inn", hallo, halloMengde.fjernEldste());
//
//  teststring("fjernNyeste() paa en tom mengde skal returnere NULL", NULL, tomMengde.fjernNyeste());
//
//  Mengde<Boolean> boolMengde2 = new Mengde<>();
//  boolMengde2.leggTil(true);
//  boolMengde2.fjernNyeste();
//  testBoolean("fjernNyeste() paa en mengde med ett element skal gi en tom mengde", true, boolMengde2.tom());
//
//  Mengde<string> heiMengde = new Mengde<>();
//  string hei = "Hei";
//  heiMengde.leggTil("Hallo");
//  heiMengde.leggTil("Tjolahopp!");
//  heiMengde.leggTil(hei);
//  teststring("fjernNyeste() skal returnere det siste objektet vi la inn", hei, heiMengde.fjernNyeste());
  return 0;
}
