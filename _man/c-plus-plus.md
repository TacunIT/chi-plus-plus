---
layout:     manuale
class:      capitolo
index:      7
title:      Il C++
permalink:  /man/c-plus-plus
precedente: linguaggi-di-programmazione
seguente:   commenti
bozza:      true
quote:      "Non chiederti cosa può fare per te il sistema operativo;
chiediti invece cosa puoi fare tu, per il sistema operativo"
redazione:  true
---


In uno dei suoi libri, Bjarne Stroustroup definì il C++: 

> Un linguaggio di programmazione per svolgere compiti non banali. 

Fà che si possa dire la stessa cosa di te. 

---

C++ è un linguaggio di programmazione creato da Bjarne Stroustrup nel 1983, quando lavorava ai Laboratori Bell della AT&T.
Dieci anni prima, il suo collega Dennis Ritchie aveva creato un linguaggio di programmazione chiamato *C*. 
Il C, come ti ho detto, era estremamente efficace se dovevi programmare i computer, ma – così come molti dei tuoi confratelli – non gestiva altrettanto bene le entità della vita reale.

Stroustrup, che ai tempi del suo dottorato aveva lavorato con un linguaggio a oggetti chiamato *Simula67*, pensò che se avesse potuto aggiungere alla velocità di esecuzione del C la possibilità di creare dei nuovi tipi di dato di Simula, avrebbe ottenuto il linguaggio perfetto.
Aveva ragione.  

Il nome *C++* si riferisce all'operatore `++`, che serve a incrementare di un'unità il valore di una variabile:

```
{% include_relative src/7.1-operatore-incremento.cpp %}
```
Se compili ed eseguti questo codice, otterrai:

```
> g++ 7.1-operatore-incremento.cpp -o ../out/esempio
> ../out/esempio
Valore di C = 12
Valore di C = 13
```

C++, infatti, non era un nuovo linguaggio: era un C migliorato. 
Tutto il codice e l'esperienza che erano state fatte fino ad allora sul C potevano essere applicate anche al C++.
Questa scelta fece sì che il C++ ebbe quasi da subito un buon successo,   diventando il linguaggio object-oriented più utilizzato degli anni '90.

L'avvento, alla fine del Secolo, di quell'*altro* linguggio, quello che ha bisogno di un sistema di *garbage collecion* per sopperire alla pochezza dei suoi programmatori, avrebbe dovuto darci un'idea di quello che sarebbe stati il millennio che ci si presentava davanti.

---

Le principali novità aggiunte dal C++ al C sono tre: l'astrazione dei dati, la programmazone a oggetti e la “generic programming”.  
Adessso ti spiego cosa sono, ma tu non preoccuparti se non capisci: approfondiremo tutti questi concetti in seguito. 

I tipi di dato del C sono:

    char, int, float, double, array, enum, struct, union

Più che sufficienti per scrivere il *kernel* di Unix, ma decisamente inadeguati per scrivere un programma che gestisca delle linee telefoniche.

Perché un linguaggio di programmazione possa gestire con la stessa facilità un flusso di dati, un utente, una linea telefonica o anche un allevamento di cavalli, è necessario che oltre ai tipi di dato predefiniti, possa gestire anche delle nuove entità definite dal programmatore.

Questa è quella che si chiama *data abstraction* e il C++ la ottiene per mezzo delle *classi*.
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
class Accoppiamento {
private:
    Cavallo _maschio;
    Cavallo _femmina;
    Data     _giorno;
public:
    Accoppiamento(Cavallo& maschio, Cavallo& femmina) {
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
I *metodi* sono delle funzioni che definiscono il modo in cui la classe può reagire agli stimoli esterni.
Nelle classi dell'esempio i *metodi* sono le funzioni che vedi nella sezione *public* della classe.
La funzione che ha lo stesso nome della classe si chiama *costruttore* della classe, perché “spiega” al compilatore come debbano essere creati gli oggetti di questa classe.

Le classi, però, sono la ricetta, non sono la pietanza. 
Per poter essere utilizzate, le classi devono essere *istanziate* negli oggetti:

```
int main()
{
    Cavallo lui("lipizzano", maschio);    
    Cavallo lei("maremmano", femmina);
    Accoppiamento monta(lui, lei);
    cout << monta << endl;
    return 0;               
}
```

`lui`, `lei` e `monta` sono tre oggetti.
I primi due sono istanze della classe *Cavallo*, il terzo è un'istanza della classe *Accoppiamento*.

Se aggiungi un po' di codice alle classi che abbiamo visto prima e compili il programma, otterrai:

```
% g++ 7.2-esempio-classe.cpp -o ../out/esempio 
% ../out/esempio                               
DATA: Sun Apr  5 10:38:31 2020
MASCHIO: Specie:cavallo, Sesso:m, Razza:lipizzano
FEMMINA: Specie:cavallo, Sesso:f, Razza:maremmano```
```

Perché un linguaggio di programmazione possa dirsi orientato agli
oggetti, però, oltre alle classi deve poter gestire l'*ereditarietà* e
il *polimorfismo*.

L'*ereditarietà* permette di definire dei nuove classi come
estensione di classi esistenti: 

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

Nell'esempio qui sopra, abbiamo prima definito una classe *Animale*, che ha tre attributi: la *specie*, lal *razza* e il *sesso*; poi abbiamo definito una classe *Cavallo*, derivandola dalla classe *Animale*.
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

Per *polimorfismo* si intende la capacità di una funzione o di un
operatore di svolgere il proprio compito indipendentemente dal tipo di
dato che deve gestire.



Vedremo tutto questo in seguito, ora non voglio complicarti troppo le idee.


<!--

Suppongo che a questo punto tu sia un po\' confuso, ma non dipende dalla
complessità dalle mie enunciazioni.

Il problema è che ti stai concentrando sull\'effetto e non sulla sua
causa.

Paragonare l'evoluzione C/C++ al rapporto fra ebraismo e cristianesimo.
Paragonare il rapporto C++/Java al rapporto fra 10 comandamenti ebraici e 10 C cattolici.
> I suspect that the root of many of the differences between C/C++ and Java is that AT&T is primarily a user (a consumer) of computers, languages, and tools, whereas Sun is primarily a vendor of such things.
Bjarne Stroustrup - http://gotw.ca/publications/c_family_interview.htm

Parafrasando Neruda, Stroustrsup fece con il C quello che Gesù fece con l'Ebraismo: prese una religione dura, adatta per un popolo in fuga nel deserto e la  migliorò, rendendola meno autoritaria.


-->
