---
status:     redazione
layout:     manuale
class:      capitolo
title:      L'ereditarietà
permalink:  /man/ereditarieta
quote:      "We few, we happy few<br />We bunch of data"
---

L'ereditariaretà, ovvero la possibilità di creare delle genealogie di classi, è il principale punto di forza del C++.

Come abbiamo visto nella <a href="/man/classi-oggetti#dottrina" class="xref">lezione precedente</a>, una ipotetica classe `Pesce` dovrà avere attributi differenti a seconda dell'utilizzo che se ne deve fare.
In un linguaggio come il *C*, che non permette l'E., quindi, si dovranno prevedere due strutture di dati differenti per ciascun caso:

```
enum Acqua  { dolce, salata };
enum Sesso  { maschio, femmina };
enum Colore { rosso, blu, verde, argento };

struct PesceAlimentare {
    Sesso  _sesso;
    char*  _specie;
    float  _prezzo;
    time_t _data_cattura;  
    int    _peso;
    bool   _commestibile;
    char*  _area_pesca; 
    ...
};

struct  PesceAcquario {
    Sesso  _sesso;
    char*  _specie;
    float  _prezzo;
    time_t _data_acquisto;  
    Colore _colore;
    Acqua  _acqua;
    ...
};
```
e funzioni differenti per la gestione dei dati:

```
void gestisciPesceAlimentare(struct PesceAlimentare& pesce);
void gestisciPesceAcquario(struct PesceEcologista& pesce);
````

Questo vuol dire che se hai già scritto (e verificato, corretto e collaudato) un programma di gestione per un pescivendolo, per poterlo trasformare in un programma di gestione per la vendita di pesci da acquario, dovrai riscrivere (e ri-verificare, ri-correggere e collaudare) tutto il codice, anche se parte dei dati da considerare sono gli stessi.  
L'ereditariaretà, al contrario, ti permette di isolare in una classe le caratteristiche comuni a tutti e due i contesti e di *derivare* da questa classe di base due classi specializzate:

```
{% include_relative src/ereditarieta-pesce.cpp %}
```

Questo approccio ha due lati positivi: il primo è che non sarà necessario ripetere le fasi di test, debug e collaudo per le funzioni comuni ai due sistemi, perché saranno state già verificate durante lo sviluppo del primo sistema; il secondo è che, riutilizzando parte del codice, sarà possibile identificare e correggere eventuali errori sfuggiti alla prima fase di test o migliorare il comportamento delle funzioni comuni, con benefici per entrambi i sistemi.

<hr id="tipi">

L'ereditarietà, nel C++, può essere o *singola* o *multipla*, a seconda che la nuova classe erediti le caratteristiche da una o più classi preesistenti:

```
class Figlio : public Mamma
{
    /** Ereditarietà singola */
};

class Figlio : public Mamma, private Papa
{
    /** Ereditarietà singola */
};
```

Al contrario, non è permesso (né sensato) che una classe erediti due volte dalla stessa classe base:

```
class Errore : public Mamma : public Mamma
{
	...
};
```

Le classi `Mamma` e `Papa` possono essere definite: *classi base* o *sottoclassi* o *classi fondamentali* o *sotto-tipi*; la classe `Figlio` può essere chiamata o *classe derivata* o *superclasse* o *supertipo*.  
L'istruzione:

```
class PesceAlimentare : public Pesce {
    ...
};
```
dichiara la classe `PesceAlimentare` come classe derivata dalla classe `Pesce`.
Lo specificatore di accesso fra i nomi delle due classi definisce la visibilità dei dati della classe base all'interno della classe figlia:

|:--:|:--|
|`public`| i membri `public` e `protected` della classe base mantengono la loro visibilità anche nella classe derivata |
|`protected`| i membri `public` e `protected` della classe base sono ereditati come membri protetti della classe derivata |
|`private`| i membri `public` e `protected` della classe base sono ereditati come membri privati della classe derivata |

In tutti i casi, i membri `private` della classe base non sono visibili alle classi derivate, a meno che queste non siano dichiarate come `friend`.  
In mancanza di un qualificatore di accesso, il compilatore considera privati tutti i dati di una classe dichiarata con la parola chiave `class` e pubblici tutti i dati di una classe dichiarata con la parola chiave `struct`:

```
{% include_relative src/ereditarieta-accesso.cpp %}
```

Se compili questo codice, ottieni un messaggio di errore:

```
> g++ src/cpp/ereditarieta-accesso.cpp -c -o src/out/esempio
src/cpp/ereditarieta-accesso.cpp:25:5: error: cannot cast 'Figlio' to its private base class
      'Mamma'
    figlio.a++;    
    ^
src/cpp/ereditarieta-accesso.cpp:17:16: note: implicitly declared private here
class Figlio : Mamma {
               ^~~~~
src/cpp/ereditarieta-accesso.cpp:25:12: error: 'a' is a private member of 'Mamma'
    figlio.a++;    
           ^
src/cpp/ereditarieta-accesso.cpp:17:16: note: constrained by implicitly private inheritance here
class Figlio : Mamma {
               ^~~~~
src/cpp/ereditarieta-accesso.cpp:8:9: note: member is declared here
    int a;
        ^
2 errors generated.
```

<!--

private:
    
    /** Dati privati della classe */
    time_t _data_cattura;  
    string _area_pesca; 

public:

    /** Costruttore della classe inline */
    PesceAlimentare(Sesso sesso, float prezzo, const char* specie) 
    : Pesce(sesso, prezzo, specie)
    {
        /** Auspicabilmente.. */
        _commestibile = true;
    }

    //...


Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Forse come classi astratte

Classi astratte, funzioni virtuali e virtuali pure.


Le figure mitiche, è vero, nascono e trapassano, ma non proprio come noi mortali. Hanno bisogno di denominazioni caratteristiche, come quella di «Re nel Passato e nel Futuro». Sono esistite in passato? Allora sono esistite ancor prima, o esisteranno ancora, con altri nomi, sotto altri aspetti, proprio come il cielo ci riporta in eterno le sue configurazioni. Se si cercasse di definirle con precisione come persone e cose, sicuramente svanirebbero ai nostri occhi, quanto i frutti di una fantasia malata. Ma se si rispetta la loro vera natura, riveleranno questa natura come funzioni.

de Santillana, Giorgio; von Dechend, Hertha. Il mulino di Amleto (Italian Edition) . Adelphi. Kindle Edition. 
-->
