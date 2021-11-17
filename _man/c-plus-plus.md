---
class:      capitolo
layout:     manuale
og_desc:    "Non chiederti cosa può fare per te il sistema operativo; chiediti invece cosa puoi fare tu, per il sistema operativo."
og_img:     "/assets/img/og-img/c-plus-plus.jpg"
permalink:  /man/c-plus-plus
quote:      "Non chiederti cosa può fare per te il sistema operativo; chiediti invece cosa puoi fare tu, per il sistema operativo."
status:     pubblicato
title:      Il C++
---

In uno dei suoi libri, Bjarne Stroustrup definì il C++: 

> {{ site.data.citazioni.stroustrup.cpp }}

Fà che si possa dire la stessa cosa di te. 

---

C++ è un linguaggio di programmazione creato da Bjarne Stroustrup nel 1983, quando lavorava ai Laboratori Bell della AT&T.
Dieci anni prima, il suo collega Dennis Ritchie aveva creato un linguaggio di programmazione chiamato *C*. 
Il C, come ti ho detto, era estremamente efficace se dovevi programmare i computer, ma &mdash; così come alcuni dei tuoi confratelli &mdash; non gestiva altrettanto bene le entità della vita reale.  
Stroustrup, che ai tempi del suo dottorato aveva lavorato con un linguaggio a oggetti chiamato *Simula67*, pensò che se avesse potuto aggiungere alla velocità di esecuzione del C la possibilità di creare dei nuovi tipi di dato di Simula, avrebbe ottenuto il linguaggio perfetto.
Aveva ragione.    
Il nome *C++* si riferisce all'operatore `++`, che serve a incrementare di un'unità il valore di una variabile:

```
{% include_relative src/cplusplus-incremento.cpp %}
```
Se compili ed eseguti questo codice, otterrai:

```
> g++ cplusplus-incremento.cpp -o ../out/esempio
> ../out/esempio
Valore di C = 12
Valore di C = 13
```

C++, infatti, non era un nuovo linguaggio: era un C migliorato. 
Tutto il codice e l'esperienza che erano state fatte fino ad allora sul C potevano essere applicate anche al C++.  
Parafrasando Neruda, Stroustrsup fece con il C quello che Gesù fece con l'Ebraismo: così come il Nazareno prese una religione spartana, adatta per un popolo in fuga nel deserto e la  migliorò, rendendola meno autoritaria, il Danese trasformò un linguaggio pensato per gestire unicamente i computer, in un linguaggio che poteva gestire ogni cosa.

---

Le principali novità aggiunte al C dal C++ sono: l'*astrazione dei dati*, la *programmazione a oggetti* e la *generic programming*.
Ora ti spiego cosa sono, ma tu non preoccuparti se non capisci: approfondiremo tutti questi concetti in seguito.  
I tipi di dato del C sono:

    char, int, float, double, array, enum, struct, union

Più che sufficienti per scrivere il *kernel* di Unix, ma decisamente inadeguati per scrivere un programma che gestisca delle linee telefoniche.
Perché un linguaggio di programmazione possa gestire con la stessa facilità un flusso di dati, un utente, una linea telefonica o anche un allevamento di cavalli, è necessario che oltre ai tipi di dato predefiniti, possa gestire anche delle nuove entità definite dal programmatore.
Questa è ciò che si chiama *data abstraction* e il C++ la ottiene per mezzo delle *classi*.
Le classi sono la rappresentazione, all'interno del codice, di un'entità:

```
class Cavallo {
private:
    Sesso  _sesso;
    string _razza;
public:
    const char* getSpecie() const {
        return "cavallo"; 
    } 
    const char getSesso() const {        
        return (char)_sesso;
    }
    const char* getRazza() const {
        return _razza.c_str();
    }
    Cavallo() {}
    Cavallo(const char* razza, Sesso sesso ) {
        _razza  = razza;
        _sesso  = sesso;
    }
};
```

o di un concetto:

``` 
class Monta {
private:
    Cavallo _maschio;
    Cavallo _femmina;
    Data     _giorno;
public:
    Monta(Cavallo& maschio, Cavallo& femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
};
```

Grazie alle classi, il programmatore può creare dei nuovi tipi di dato e
utilizzarli all'interno del suo programma nello stesso modo in cui
utilizzerebbe i tipi di dato primitivi del linguaggio.  
Ciascuna classe ha degli *attributi* e dei *metodi*.
Gli *attributi* sono dei dati che descrivono le caratteristiche della classe, per esempio, la razza o il sesso di un cavallo.
I *metodi* sono delle funzioni che definiscono il modo in cui la classe può interagire con gli altri elementi del programma.
Nelle classi dell'esempio gli *attributi* sono gli elementi che vedi nella sezione `private`, mentre i *metodi* sono le funzioni che vedi nella sezione `public`.
La funzione che ha lo stesso nome della classe si chiama *costruttore* della classe, perché “spiega” al compilatore come debbano essere creati gli oggetti di questa classe.  
Le classi, però, sono la ricetta, non sono la pietanza. 
Per poter essere utilizzate, le classi devono essere *istanziate* negli oggetti:

```
int main()
{
    Cavallo stallone("lipizzano", maschio);    
    Cavallo giumenta("maremmano", femmina);
    Monta   monta(stallone, giumenta);
    cout << monta << endl;
    return 0;               
}
```

`stallone`, `giumenta` e `monta` sono tre oggetti.
I primi due sono istanze della classe `Cavallo`, il terzo è un'istanza della classe `Monta`.  
Se aggiungi un po' di codice alle classi che abbiamo visto prima e compili il programma, otterrai:

```
% g++ cplusplus-classe.cpp -o ../out/esempio 
% ../out/esempio                               
DATA: Sun Apr  5 10:38:31 2020
MASCHIO: Specie:cavallo, Sesso:m, Razza:lipizzano
FEMMINA: Specie:cavallo, Sesso:f, Razza:maremmano```
```

Perché un linguaggio di programmazione possa dirsi *orientato agli oggetti*, però, oltre alle classi deve poter gestire l'*ereditarietà* e il *polimorfismo*.
L'*ereditarietà* permette di definire dei nuove classi come estensione di classi esistenti: 
<a id="cast"></a>

```
class Animale {
private:
    string _specie;
    string _razza;
    Sesso  _sesso;
public:
    const char* getSpecie() const {
        return _specie.c_str(); 
    } 
    const char getSesso() const {        
        return (char)_sesso;
    } 
    const char* getRazza() const {
        return _razza.c_str();
    }
    Animale() {}
    Animale(const char* specie, const char* razza, const Sesso sesso ) {
        _specie = specie;
        _razza  = razza;
        _sesso  = sesso;
    }
};

class Cavallo : public Animale {
public:
    Cavallo() {}
    Cavallo(const char* razza, const Sesso sesso )
    : Animale("Cavallo", razza, sesso ) { 
    }
};
```

Nell'esempio qui sopra, abbiamo prima definito una classe `Animale`, che ha tre attributi: la `specie `, la `razza ` e il `sesso `; poi abbiamo definito una classe `Cavallo`, derivandola dalla classe `Animale`.
In questo modo, se oltre ai cavalli il nostro programma dovesse gestire anche altri ungulati, non dovremmo ripetere in ciascuna classe le stesse istruzioni, ma potremmo utilizzare quelle della classe base:

```
class Asino : public Animale {
public:
    Asino() {}
    Asino(const char* razza, const Sesso sesso )
    : Animale("Asino", razza, sesso ) { 
    }
};
```

A questo punto, la tua sagacia dovrebbe averti fatto rilevare un possibile problema (posto che tu sia sveglio, cosa di cui non sono del tutto certo): la classe `Monta` può gestire solo oggetti di tipo `Cavallo`.  
Un linguaggio che non gestisca il polimorfismo ci costringerebbe a scrivere due nuove classi: una per i muli e una per i bardotti:

```
class MontaMulo {
private:
    Asino   _maschio;
    Cavallo _femmina;
    Data     _giorno;
public:
    MontaMulo(Asino& maschio, Cavallo& femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
};

class MontaBardotto {
private:
    Cavallo _maschio;
    Asino   _femmina;
    Data     _giorno;
public:
    Monta(const Cavallo& maschio, const Asino& femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
};
```

Il problema è che più codice scrivi, più è probabile che farai degli errori e meno facile sarà correggerli.
Al contrario, i programmi con meno righe di codice sono più affidabili e più facili da correggere o da modificare.   
Il C++ ci aiuta in questo senso perché permette il <i id="polimorfismo">polimorfismo</i>, ovvero la capacità di una funzione o di un operatore di svolgere il proprio compito indipendentemente dal tipo di dato che deve gestire.
Se riscriviamo la classe `Monta` usando, al posto dei parametri di tipo `Cavallo`, dei parametri che hanno il tipo della classe base `Animale`:

```
class Monta {
private:
    Animale* _maschio;
    Animale* _femmina;
    Data     _giorno;
public:
    Monta(Animale* maschio, Animale* femmina) {
        _maschio = maschio;
        _femmina = femmina;
        time(&_giorno);
    }
};

```

Potremo creare degli oggetti di classe `Monta` con qualunque classe derivata:

```
{% include_relative src/cplusplus-polimorfismo.cpp %}
```

Compilando ed eseguendo il programma, otterrai:

```
% g++ cplusplus-polimorfismo.cpp -o ../out/esempio
% ../out/esempio                                    
PULEDRO
DATA: Sun Apr  5 12:33:45 2020
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f

CIUCO
DATA: Sun Apr  5 12:33:45 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo	    Sesso:f

MULO
DATA: Sun Apr  5 12:33:45 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f

BARDOTTO
DATA: Sun Apr  5 12:33:45 2020
MASCHIO: Specie:Asino	Razza:sardo	    Sesso:f
FEMMINA: Specie:Cavallo	Razza:lipizzano	Sesso:m
```

Come ti ho detto, però, un buon programmatore non si accontenta di essere riuscito a produrre il risultato atteso, ma si chiede sempre se ci sia un modo più efficiente per ottenerlo.
Nel nostro caso, il codice che abbiamo utilizzato per mostrare il risultato degli accoppiamenti:

```
Monta puledro(cavallo, giumenta);
Monta ciuco(asino, asina);
Monta mulo(asino, giumenta);
Monta bardotto(asina, cavallo);

cout << "PULEDRO\n"  << puledro  << endl;
cout << "CIUCO\n"    << ciuco    << endl;
cout << "MULO\n"     << mulo     << endl;
cout << "BARDOTTO\n" << bardotto << endl;
```

non è il massimo dell'efficienza, sia perché potremmo sbagliarci ad accoppiare la specie dei genitori con il nome del figlio, sia perché le istruzioni devono essere ripetute per ciascun oggetto. 
Per risolvere il primo difetto possiamo aggiungere alla classe `Monta` un attributo e un metodo per definire autonomamente che tipo di genìa venga prodotta dalla copula:
<a id="membro"></a>
```
string   _esito;
void setEsito() {
    if(strcmp(_maschio->getSpecie(),"Asino") == 0) {
        if(strcmp(_femmina->getSpecie(),"Asino") == 0){
            _esito = "asino";
        } else {
            _esito = "mulo";
        } 
    } else {        
        if(strcmp(_femmina->getSpecie(),"Cavallo") == 0) {
            _esito = "puledro";
        } else {
            _esito = "bardotto";
        } 
    }
}
```

ma anche così dovremo comunque riscrivere quattro righe di codice per modificare l'output del programma: un approccio inaccettabile per i sistemi di produzione, dove le entità da gestire possono essere migliaia.
Possiamo risolvere questo problema grazie alla *generic programming* e al modo in cui viene implementata nel C++: le classi <i id="template">template</i>:

```
template < class T> class list;
```

La classe `list` è una delle classi *template* del C++ e permette di inserire, rimuovere, spostare, unire, ordinare ed elencare una lista di oggetti di una stessa classe.
La sintassi per creare una lista di oggetti di classe `Monta` è:

```
list<Monta> monte;
```

Fatto ciò, possiamo aggiungere elementi alla nostra lista con la funzione `push_back()`, alla quale passeremo direttamente il costruttore della classe:

```
monte.push_back(Monta(cavallo, giumenta)); 
monte.push_back(Monta(asino, asina));       
monte.push_back(Monta(asino, giumenta));     
monte.push_back(Monta(cavallo, asina));
```

Questo codice è una forma più efficiente di:

```
Monta m1(cavallo, giumenta); 
Monta m2(asino, asina);       
Monta m3(asino, giumenta);     
Monta m4(cavallo, asina);

monte.push_back(m1);  
monte.push_back(m2);  
monte.push_back(m3);
monte.push_back(m4);
```

Per visualizzare il contenuto della lista, indipendentemente dal numero di elementi, basta l'istruzione:

```
for (list<Monta>::iterator it=monte.begin(); it!=monte.end(); it++) {
    cout << *it << endl;
}
```

La funzione `main()` del nostro programma sarà quindi:

```
int main()
{
    Animale* cavallo  = new Cavallo("lipizzano", maschio);    
    Animale* giumenta = new Cavallo("maremmano", femmina);    
    Animale* asino    = new Asino("amiatino", maschio);
    Animale* asina    = new Asino("sardo", femmina);
    list<Monta> monte;
    monte.push_back(Monta(cavallo, giumenta)); 
    monte.push_back(Monta (asino, asina));       
    monte.push_back(Monta (asino, giumenta));     
    monte.push_back(Monta (cavallo, asina));
    for (list<Monta>::iterator it=monte.begin(); 
         it!=monte.end(); it++) {
        cout << *it << endl;
    }
    return 0;               
}
```

e l'output che otterremo è:

```
$ g++ cplusplus-template.cpp -o ../out/esempio
% ../out/esempio                                
DATA:    Sun Apr  5 16:19:24 2020
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   puledro

DATA:    Sun Apr  5 16:19:24 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo	    Sesso:f
ESITO:   asino

DATA:    Sun Apr  5 16:19:24 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   mulo

DATA:    Sun Apr  5 16:19:24 2020
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo     Sesso:f
ESITO:   bardotto
```

Se per qualche motivo volessimo invertire l'ordine degli elementi nella lista, tutto quello che dovremmo fare è di aggiungere prima del ciclo `for` l'istruzione:

```
monte.reverse();
```

e l'output che otterremo è:

```
% g++ cplusplus-template.cpp -o ../out/esempio
% ../out/esempio                                
DATA:    Sun Apr  5 17:08:27 2020
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo	Sesso:f
ESITO:   bardotto

DATA:    Sun Apr  5 17:08:27 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   mulo

DATA:    Sun Apr  5 17:08:27 2020
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo     Sesso:f
ESITO:   asino

DATA:    Sun Apr  5 17:08:27 2020
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   puledro

```

Oltre alle classi template predefinite della *Standard Template Library*, il C++ permette di definire le proprie classi template, ma di questo parleremo <a href="/man/polimorfismo#template" class="xref">a tempo debito</a>.  
Queste caratteristiche, unite alla compatibilità con il codice scritto in C, fecero di C++ il linguaggio *object-oriented* più utilizzato degli anni '90.
L'avvento, alla fine del Secolo, del linguaggio con la "J", quello che ha bisogno di un sistema di *garbage collecion* per sopperire alla pochezza dei suoi programmatori, avrebbe dovuto darci un'idea di quello che sarebbe stato il millennio che ci si presentava davanti.
Non a caso, Stroustrsup disse:

> {{ site.data.citazioni.stroustrup.java }} <a id="stroustrup" href="/man/note#cpp" class="nota"></a>

<!--

<hr id="dottrina">

-->
