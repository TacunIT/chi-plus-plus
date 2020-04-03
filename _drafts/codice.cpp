
class Circonferenza {
  public:
    Circonferenza(float r)
    : _raggio(r) {
    }
    float diametro() {
      return 3.14 * (_raggio + _raggio);
    }
    virtual string descrizione() = 0;
  private:
    float _raggio;
};

class Piatto : public Circonferenza {
  public:
    Piatto(float r)
    : Circonferenza(r) {
    }
    string descrizione() {
      return "supporto in ceramica per i cibi";
    }
}

class Ruota : public Circonferenza {
  public:
    Ruota(float r)
    : Circonferenza(r) {
    }
    string descrizione() {
      return "elemento di riduzione dell'attrito";
    }
}

void main()
{
  Ruota  r(80);
  Circonferenza& c = r;
	cout << r.diametro()    << endl;
	cout << r.descrizione() << endl;
	cout << c.diametro()    << endl;
	cout << c.descrizione() << endl;
}
