#include <iostream>

using namespace std;

class Mus
{
 public:
    Mus(int v, bool s) {
      _vekt = v;
      _syk = s;
      _lever = true;
      _cnt++;
    }
    Mus() {
      _vekt = 0;
      _syk = false;
      _lever = false;
      _cnt++;
    }
    int vekt(void);
    bool syk(void);
    bool lever(void);
    void sjekktilstand(const char *testid, const char *navn, bool s, int v, bool l); 
    void infoOmTilstand(string testid);
    void bliSyk();
    void die();

 private:
    int _vekt;
    bool _syk;
    bool _lever;
    static int _cnt;
};

// initilization of object counter
int Mus::_cnt = 0;

int Mus::vekt()
{
  return _vekt;
}

bool Mus::syk()
{
  return _syk;
}

bool Mus::lever()
{
  return _lever;
}

void Mus::bliSyk()
{
  _syk = true;
}

void Mus::die()
{
  _lever = false;
  _syk = false;
}

void Mus::sjekktilstand(const char *testid, const char *navn, bool s, int v, bool l)
{
  cout.setf(std::ios::boolalpha);
  //check variables
  string syksjekk = "ERROR";
  string vektsjekk = "ERROR";
  string leversjekk = "ERROR";
  //sykdom sjekk
  if (s == syk()) {
    syksjekk = "OK";
  }
  //vekt sjekk
  if (v == vekt()) {
    vektsjekk = "OK";
  }
  //lever sjekk
  if (l == lever()) {
    leversjekk = "OK";
  }

  cout << "********* Test av musobjekt, testid: " << testid << " ***" << endl;
  cout << "** " << "navn: " << navn << ", "<< "OK" << "." << endl;
  cout << "** " << "syk: " << s << ", " << syksjekk << "." << endl;
  cout << "** " << "vekt: " << v << ", " << vektsjekk << "." << endl;
  cout << "** " << "lever: " << l << ", " << leversjekk << "." << endl;

}

void Mus::infoOmTilstand(string testid)
{
  cout << "--- " << testid << " --- Info om mus: navn:musNr" << _cnt << ", vekt:" << vekt() << ", syk:" << syk() << ", lever:" << lever() << endl;
}
