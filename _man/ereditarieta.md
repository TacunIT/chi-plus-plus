---
status:     redazione
layout:     manuale
class:      capitolo
title:      L'ereditarietà
permalink:  /man/ereditarieta
quote:      "We few, we happy few<br />We bunch of data"
---

L'ereditariaretà, ovvero la possibilità di creare delle genealogie di classi, è la caratteristica principale del C++.

Come abbiamo visto nella <a href="/man/classi-oggetti#dottrina" class="xref">lezione precedente</a>, una ipotetica classe `Pesce` dovrà avere attributi differenti a seconda dell'utilizzo che se ne deve fare.
In un linguaggio come il *C*, che non permette l'ereditariaretà, quindi, si dovranno prevedere due strutture di dati differenti per ciascun caso:

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
{% include_relative src/ereditarieta-singola.cpp %}
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
class Errore : public Mamma, public Mamma
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
Lo <a href="/man/classi-oggetti#specificatori-accesso" class="xref">specificatore di accesso</a> fra i nomi delle due classi definisce la visibilità dei dati della classe base all'interno della classe figlia:

```
class B : public A
{
    // tutti i membri di A mantengono 
    // in B la loro visibilità originale 
};

class B : protected A
{
    // tutti i membri public di A diventano membri 
    // protected di B; i membri protected e private 
    // mantengono la loro visibilità originale
};

class B : private A	
{
    // tutti i membri di A, quale che sia la loro 
    // visibilità, diventano membri private di B;
};

```

In mancanza di un qualificatore di accesso, il compilatore considera privati tutti i dati di una classe dichiarata con la parola chiave `class` e pubblici tutti i dati di una classe dichiarata con la parola chiave `struct`:

```
{% include_relative src/ereditarieta-accesso.cpp %}
```

Se compili questo codice, ottieni un messaggio di errore:

```
> g++ src/cpp/ereditarieta-accesso.cpp -c -o src/out/esempio
src/cpp/ereditarieta-accesso.cpp:25:5: error: cannot cast 'Figlio' 
    to its private base class
      'Mamma'
    figlio.a++;    
    ^
src/cpp/ereditarieta-accesso.cpp:17:16: note: implicitly declared 
    private here
class Figlio : Mamma {
               ^~~~~
src/cpp/ereditarieta-accesso.cpp:25:12: error: 'a' is a private 
    member of 'Mamma'
    figlio.a++;    
           ^
src/cpp/ereditarieta-accesso.cpp:17:16: note: constrained by 
    implicitly private inheritance here
class Figlio : Mamma {
               ^~~~~
src/cpp/ereditarieta-accesso.cpp:8:9: note: member is declared 
    here
    int a;
        ^
2 errors generated.
```


<hr id="costruttore">

Questa è la dichiarazione del costruttore della classe derivata `PesceAlimentare`:

```
PesceAlimentare(Sesso sesso, float prezzo, const char* specie) 
: Pesce(sesso, prezzo, specie) {
    _commestibile = true;
}
```

La seconda linea è la <i id="lista-inizializzazione">lista di inizializzazione</i> della classe e contiene i costruttori delle classi base.
Quando si instanzia un oggetto di classe derivata, il sistema richiama per prima cosa i costruttori delle classi base e poi quello della classe figlia.
In questo modo, il costruttore della classe derivata ha la certezza di lavorare su dei dati membro correttamente inizializzati.  
L'utilizzo del costruttore delle classi base per l'inizializzazione dei dati comuni è necessario per due motivi: il primo è che parte dei dati delle classe base potrebbero essere `private` e quindi inaccessibili alla classe derivata; il secondo motivo è che in questo modo si ottiene un <a href="/man/struttura-dei-programmi#coupling" class="xref">low coupling</a> fra classe base e classe derivata e, se  si dovesse modificare l’implementazione interna del costruttore della classe base (mantenendo invariata l'interfaccia), non ci sarebbe bisogno di dover modificare il codice delle sue classi de­rivate.  
L'ordine in cui i costruttori delle classi base sono chiamati durante l'inizializzazione dell'oggetto dipende dall'ordine in cui compaiono nel costruttore della classe figlia.
Lo vediamo con un altro esempio, un po' più complesso del precedente, che mostra anche il funzionamento dei dati e delle funzioni membro statiche:

```
{% include_relative src/ereditarieta-multipla.cpp %}
```

La differenza con il codice precedente è che in questo caso abbiamo isolato i dati relativi al costo del pesce in una classe separata e che le classi derivate ereditano non più da una classe base, ma da due.  
Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/ereditarieta-multipla.cpp -o src/out/esempio
> src/out/esempio                                         
costruttore Pesce
costruttore Articolo
costruttore PesceAlimentare
costruttore Articolo
costruttore Pesce
costruttore PesceAcquario
pesce acquario: Paracheiredon
pesce alimentare: Dicentrarchus labrax
classe base: articolo
articoli creati: 2
pesci creati:    2
distruttore PesceAcquario
distruttore Pesce
distruttore Articolo
distruttore PesceAlimentare
distruttore Articolo
distruttore Pesce
```

Come vedi, l'ordine di chiamata dei costruttori delle classi base rispecchia quello in cui sono elencate nella lista di inizializzazione, mentre quello dei distruttori è invertito.
Se il costruttore della classe derivata non specifica un ordine di chiamata per i costruttori delle classi base, l'ordine di chiamata è dato dall'ordine in cui le classi base compaiono nella dichiarazione della classe figlio:

```
{% include_relative src/ereditarieta-ordine-costruttori.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/ereditarieta-ordine-costruttori.cpp -o src/out/esempio
> src/out/esempio                                                   
costruttore Babbo
costruttore Mamma
costruttore Figlio
costruttore Mamma
costruttore Babbo
costruttore Figlia
```

Un'altra cosa da notare, in questo codice, è che la funzione `getTipo` è presente sia nella classe base `Articolo` che nelle due classi derivate `PesceAlimentare` e `PesceAcquario`.
Per questo motivo, quando si richiama `getTipo` da un'istanza delle due classi derivate, come in:

```
cout <<  pesce1.getTipo() << ": " << pesce1.getSpecie() 
cout <<  pesce2.getTipo() << ": " << pesce2.getSpecie() 
```

il valore tornato è quello della funzione della classe figlia.
Per ottenere il valore della classe base, dobbiamo specificarne il nome nell'istruzione, come in:

```
cout << "classe base: " << pesce1.Articolo::getTipo() << endl;
```

<hr id="classi-virtuali">

Complichiamo un po' le cose.
Immagina che una classe `Figlio` derivi dalle classi `Madre` e `Padre`, a loro volta derivate dalla classe `Persona`. 
Se chiamassimo una funzione della classe `Persona` da un oggetto di classe `Figlio`, quale verrebbe chiamata, quella che ha ereditato da `Padre` o quella che ha ereditato da `Madre`?

```
{% include_relative src/ereditarieta-classi-base-virtuali.cpp %}
```


<!--

Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Forse come classi astratte

Classi astratte, funzioni virtuali e virtuali pure.


Le figure mitiche, è vero, nascono e trapassano, ma non proprio come noi mortali. Hanno bisogno di denominazioni caratteristiche, come quella di «Re nel Passato e nel Futuro». Sono esistite in passato? Allora sono esistite ancor prima, o esisteranno ancora, con altri nomi, sotto altri aspetti, proprio come il cielo ci riporta in eterno le sue configurazioni. Se si cercasse di definirle con precisione come persone e cose, sicuramente svanirebbero ai nostri occhi, quanto i frutti di una fantasia malata. Ma se si rispetta la loro vera natura, riveleranno questa natura come funzioni.

de Santillana, Giorgio; von Dechend, Hertha. Il mulino di Amleto (Italian Edition) . Adelphi. Kindle Edition. 
-->
