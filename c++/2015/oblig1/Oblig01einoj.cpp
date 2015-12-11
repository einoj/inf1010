#include <iostream>
#include <string>
#include "Katt.h"
using namespace std;

string bool_to_string(bool s)
{
  if (s)
    return "true";
  else
    return "false";
}

class Oblig01einojo
{
    // ** versjon 15.01.28
    // forbedret testene:
    // get-metodene i Katt returnerer "logiske" typer for
    // vekt, antallMus og syk.
    // Skilt ut infoOmTilstand (i Mus) som egen metode
    // Rettet ulogiskheter i sjekkTilstand og infoOmTilstand: se utskriftsfila
    // Det er likegyldig om man leverer denne
    // eller tidligere versjon. Det vesentlige er at klassene fungerer sammen.

  public:
    static void testOmSomForventet(string hva, string verdi, string fverdi)
    {
      string utfall;
      if (verdi.compare(fverdi) == 0) utfall = verdi + ", OK.";
      else utfall =  "FEIL, aktuell verdi: " + verdi 
        + ", forventet verdi: " + fverdi; 
      cout << "== Tester " << hva << ": " << utfall << endl;
    }
    static void testMusebol( Bol<Mus> *musebolet, string id )
    {
      // Klasen Bol<T> skal ha en metode tomt() som returnerer true
      // når bolet ikke er bebodd av ei mus.
      if ( musebolet->tomt() ) {
        cout << " ###### " << id << " Musebolet er tomt" << endl;
      } else {
        cout << " ###### " << id << " Musebolet er bebodd:" << endl;
        musebolet->beboer()->infoOmTilstand(" IBOL ");
      }
    }
    static void hovedprogram() 
    {
      Katt *pus = new Katt("Pus", 4560, false);
      cout << "============= Tester Pus:" << endl;
      testOmSomForventet("kattens navn", pus->navn(), "Pus");
      testOmSomForventet("kattens vekt", to_string(pus->vekt()), "4560");
      testOmSomForventet("antall mus i magen", to_string(pus->antMus()), "0");
      testOmSomForventet("om katten er syk", bool_to_string(pus->syk()), "false");

      // Merk at testmetoden her krever at get-metodene vekt(),
      // antMus() og syk() i Katt returnerer String som type,
      // ikke int og boolean. Dette ser vi av signaturen til
      // testOmSomForventet.

      Katt *mons = new Katt("Mons");
      cout << "============= Tester Mons:" << endl;
      testOmSomForventet("kattens navn", mons->navn(), "Mons");
      testOmSomForventet("kattens vekt", to_string(mons->vekt()), "5000");
      testOmSomForventet("antall mus i magen", to_string(mons->antMus()), "0");
      testOmSomForventet("om katten er syk", bool_to_string(mons->syk()), "false");

      //Katt[] katter = new Katt[5];
      Katt katter[5];
      katter[0] = *mons;
      katter[1] = *pus;

      Mus *m1 = new Mus(37, false);
      m1->sjekktilstand("A", "musNr1", false, 37, true);
      free(m1);
      m1 = NULL;
      //              (testid, navn, syk, vekt, lever) 
      Mus *m2 = new Mus(38, true);
      m2->sjekktilstand("B", "musNr2", true, 38, true);
      free(m2);
      m2 = NULL;

      Bol<Mus> *musebolet = new Bol<Mus>();
      testMusebol(musebolet, "P");

      musebolet->settInn(new Mus(39, false));
      testMusebol(musebolet, "Q");

      /* 
       * Oppgave 1a
       * Tegn datastrukturen slik den ser ut her, med 1 katt-array, 1 musebol,
       * 2 katter og 3 mus. For mus og katt trenger du bare å ha med alle detaljer
       * i ett av objektene
       *
       */


      // Tester taUt-metoden i Bol:
      
      Mus *mm = musebolet->taUt();
      testMusebol(musebolet, "R");
      musebolet->settInn(mm);

      if (mm != musebolet->beboer())
          cout << "S: FEIL: mm og musebol ikke samme musobjekt" << endl;

      // La jakta starte!
      // Først er det Pus som får 3 forsøk
      // Hvis Pus ikke spiser musa, setter vi den inn igjen
      // Hvis Pus har spist musa i musebolet, setter vi inn ei ny

      for (int i=0; i < 2; i++) {

          musebolet->beboer()->infoOmTilstand("B1");
          mm = pus->gaaPaaJaktI(musebolet);

          cout <<"============= Tester Pus (i løkke) :" << endl;
          testOmSomForventet("antall mus i magen", to_string(pus->antMus()), to_string(i+1));
          testOmSomForventet("kattens vekt", to_string(pus->vekt()), to_string(4560+39+i*(55+i-1)));
          testOmSomForventet("om katten er syk", bool_to_string(pus->syk()), "false");

          if (mm != NULL) {
            musebolet->settInn(mm);	
          } else { 
            musebolet->settInn(new Mus(55+i, false));
          }
      }
      delete mm;
      mm = NULL;

      // Så tester vi at Pus nå er mett, og at musa er blitt syk etter
      // å ha blitt bitt...

      musebolet->beboer()->sjekktilstand("X", "musNr5", false, 56, true );
      mm = pus->gaaPaaJaktI(musebolet);
      if ( mm != NULL) musebolet->settInn(mm);
      musebolet->beboer()->sjekktilstand("Y", "musNr5", true, 56, true );


      // Deretter får Mons og Pus 2 forsøk hver annenhver gang:

      for (int i=0; i < 2; i++) {
          musebolet->beboer()->infoOmTilstand("B2");
          mm = mons->gaaPaaJaktI(musebolet);
          if ( mm != NULL) musebolet->settInn(mm);	
          else musebolet->settInn(new Mus(44+i, false));
          musebolet->beboer()->infoOmTilstand("B3");
          mm = pus->gaaPaaJaktI(musebolet);
          if ( mm != NULL) musebolet->settInn(mm);	
          else musebolet->settInn(new Mus(33+i, false));
      }


      //  Vi lar så en ny katt, Jery spise ei syk mus:
      musebolet->beboer()->sjekktilstand("Z", "musNr7", true, 45, true );

      Katt *jerry = new Katt("Jerry");
      mm = jerry->gaaPaaJaktI(musebolet);
      if ( mm != NULL) musebolet->settInn(mm);	
      else musebolet->settInn(new Mus(77, true));

      // Så lar vi en mett katt skade musa til den dør:

      mm = mons->gaaPaaJaktI(musebolet);
      if ( mm != NULL) musebolet->settInn(mm);
      mm = mons->gaaPaaJaktI(musebolet);
      if ( mm != NULL) musebolet->settInn(mm);
      musebolet->beboer()->infoOmTilstand("B4");



      // sjekker til slutt at Jerry ikke spiser den døde musa i bolet
      testOmSomForventet("Jerrys antall mus i magen", to_string(jerry->antMus()), "1");
      mm = jerry->gaaPaaJaktI(musebolet);
      testOmSomForventet("Jerrys antall mus i magen", to_string(jerry->antMus()), "1");
      delete  mm;
      delete musebolet;
      mm = NULL;
      musebolet = NULL;

      cout << "============= Tester Pus:" << endl;
      testOmSomForventet("kattens navn", pus->navn(), "Pus");
      testOmSomForventet("kattens vekt", to_string(pus->vekt()), "4654");
      testOmSomForventet("antall mus i magen", to_string(pus->antMus()), "2");
      testOmSomForventet("om katten er syk", bool_to_string(pus->syk()), "false");

      cout << "============= Tester Mons:" << endl;
      testOmSomForventet("kattens navn", mons->navn(), "Mons");
      testOmSomForventet("kattens vekt", to_string(mons->vekt()), "5100");
      testOmSomForventet("antall mus i magen", to_string(pus->antMus()), "2");
      testOmSomForventet("om katten er syk", bool_to_string(mons->syk()), "true");

      delete pus;
      pus = NULL;
      delete mons;
      mons = NULL;

      cout << "============= Tester Jerry:" << endl;
      testOmSomForventet("kattens navn", jerry->navn(), "Jerry");
      testOmSomForventet("kattens vekt", to_string(jerry->vekt()), "5045");
      testOmSomForventet("antall mus i magen", to_string(jerry->antMus()), "1");
      testOmSomForventet("om katten er syk", bool_to_string(jerry->syk()), "true");

      delete jerry;
      jerry = NULL;

    }	
	
	
};

int main(void) {
    Oblig01einojo *o1 = new Oblig01einojo(); 
    o1->hovedprogram();
    free(o1);
    o1 = NULL;
}
 



       
