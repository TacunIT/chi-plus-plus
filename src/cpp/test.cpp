#include <iostream>
#include <ctime>

using namespace std;

class Coniglio {
private:
    string _razza;
    char   _sesso;
public:
    Coniglio();
};

typedef time_t Data;

class Accoppiamento {
private:
    Coniglio _maschio;
    Coniglio _femmina;
    Data     _giorno;
public:
    Accoppiamento();
};

int main()
{
    Coniglio Jessica;
    Coniglio Roger;
    Accoppiamento();
    return 0;               
}
