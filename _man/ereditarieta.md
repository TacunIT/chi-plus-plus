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
costruttore Padre
costruttore Mamma
costruttore Figlio
costruttore Mamma
costruttore Padre
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

In realtà, nessuna delle due, perché questo codice genera un errore:

```
src/cpp/ereditarieta-classi-base-virtuali.cpp:30:11: 
error: non-static member 'getClass' found in multiple base-class
      subobjects of type 'Persona':
    class Figlio -> class Padre -> class Persona
    class Figlio -> class Madre -> class Persona
    caino.getClass();
          ^
src/cpp/ereditarieta-classi-base-virtuali.cpp:13:10: 
note: member found by ambiguous name lookup
    void getClass(){
         ^
1 error generated.
```
Puoi evitare questo genere di problemi dichiarando la classe `Persona` come classe base *virtuale* delle classi `Madre` e `Padre`:

```
class Padre : public virtual Persona {
};

class Madre : virtual public Persona {
};
```

In questo modo, la classe `Figlio` erediterà tutti i membri propri delle  classi `Madre` e `Padre`, ma solo una copia dei metodi e degli attributi della classe virtuale `Persona` che entrambi contengono.

<hr id="classi-puntatori">

Come ti ho detto, definire una nuova classe equivale a definire un nuovo tipo di dato, che sarà considerato dal compilatore alla stessa stregua dei dati primitivi del linguaggio. 
Questo vuol dire, per esempio, che se vogliamo possiamo creare un array di oggetti di classe `Pesce` così come creeremmo un array di `int` o di `char`:

```
/** Array di oggetti di classe Pesce */
Pesce acquario[10];
```

C'è solo una limitazione: siccome tutti gli elementi di un array devono essere inizializzati al momento della sua creazione, la classe deve avere un costrut­tore di default.
Se decidessimo di creare un array di oggetti della classe `Punto` che abbiamo visto <a href="/man/classi-oggetti#attributi-metodi" class="xref">nella scorsa lezione</a>, gli elementi dell'array dovranno essere inizializzati esplicitamente:

```
Punto spline[3] = { Punto(3,5), Punto(0,0), Punto(7,7) } ;
```
 
Possiamo aggiungere a un array di oggetti di una classe base anche degli oggetti appart­enenti alle sue classi derivate:

```
Persona famiglia[3] = { Padre(), Madre(), Figlio() } ;
```

Al contrario, gli oggetti della classe base non possono comparire in array di oggetti della classe derivata e un'istruzione come quella qui sotto darà errore:

```
Figlio classe[4] = { Figlio(), Figlio(), Persona(), Figlio() } ;
```

Così come, negli scacchi, la regina può muovere come una torre, ma una torre non può muoversi come una regina, un oggetto di tipo `Persona` non contiene tutta l’informazione relativa a un oggetto di tipo `Figlio` e quindi non può essere usato in sua sostituzione.  
Lo stesso discorso fatto per gli array, vale anche per i puntatori. 
A un puntatore a oggetti di tipo `Persona` può essere assegnato un oggetto di tipo `Figlio`, mentre l’operazione inversa causerà un errore di compilazione:

```
Persona *ptrP = new Figlio() ;  // OK
Figlio  *ptrF = new Persona();  // ERRORE!
```

Il compilatore è in grado di capire la relazione che c’è fra una classe derivata e la sua classe base e può quindi stabilire un cammino di coercizione dal tipo dell’oggetto a quello del puntatore, ma non ha modo di accedere ai membri o alle funzioni di una classe derivata da un oggetto di classe base.   
Abbiamo detto <a href="/man/tipi-di-dato#puntatori" class="xref">a suo tempo</a> che i puntatori sono come delle maschere che isolano determinate sequenze di bit, la cui dimensione varia a seconda del tipo del puntatore. 
Lo stesso discorso vale anche per le classi: un puntatore di classe base associato a un oggetto di classe derivata “vedrà” solo i dati e le funzioni della sua classe:

```
{% include_relative src/ereditarieta-puntatori.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/ereditarieta-puntatori.cpp -o src/out/esempio 
> src/out/esempio 
Madre
Persona
```

Non c’è nessun errore: la funzione `getClass()` che interviene nella seconda istruzione di output non è, come ci si aspettava, quella della classe `Madre`, a cui l’oggetto appartiene, bensì quella della classe base, che è l’unica a cui il programma può accedere tramite un puntatore a oggetti di tipo `Persona`.  
Questo comportamento (corretto) del programma diventa particolarmente rischioso se la classe ha un distruttore:

```
{% include_relative src/ereditarieta-distruttori.cpp %}
```

Nessun compilatore ti darà mai errore per questo codice, ma il distruttore chiamato, in tutti e tre i casi, sarà quello della classe base `Padre`, con conseguenze che spaziano dal problematico al disastroso. 

<hr id="funzioni-virtuali">

Per far sì che una funzione membro di una classe derivata possa essere richiamata anche da puntatori a classi base, la si deve dichiarare come `virtual`.

```
{% include_relative src/ereditarieta-funzioni-virtuali.cpp %}
```
L'output di questo codice è:

```
> g++ src/cpp/ereditarieta-funzioni-virtuali.cpp \                 
    -o src/out/esempio
> src/out/esempio                                 
Madre
Madre
```

Le *funzioni virtuali* sono delle funzioni che vengono richiamate in base alla classe dell’oggetto cui appartengono, indipendentemente dal tipo del riferimento o del puntatore che si utilizza. 
Ciò è reso possibile da un meccanismo chiamato *binding dinamico* o *late binding*, che consiste nel posticipare il *linking* delle funzioni al momento dell’esecuzione del programma, contrariamente a quanto avviene per le funzioni membro normali, che sono collegate al codice in fase di compilazione &mdash; il cosiddetto *early binding*.  
In pratica, la cosa funziona così: gli indirizzi di tutte le  funzioni dichiarate come `virtual` vengono memorizzati in una tabella interna e solo quando una di queste funzioni viene richiamata dal programma, il sistema ne cerca l’indirizzo, effettuandone poi il *linking* in tempo reale.
Capisci da te che l’utilizzo delle funzioni virtuali, oltre a comportare un leg­gero ritardo nel tempo di esecuzione del programma, visto che l’indirizzo della funzione va ben cercato, impegna anche parte delle risorse del sistema per la memorizzazione della tabella degli indirizzi, quindi, come per tutte le cose, è bene non abusarne.   
Le regole che riguardano l’utilizzo delle funzioni virtuali sono:

- le versioni delle funzioni delle classi derivate debbono avere il medesi­mo tipo di ritorno e gli stessi parametri della versione della classe base: se non è così, il compilatore considera differenti le due funzioni e l’effetto “virtuale” si perde;

- una funzione `virtual` non può essere anche `static`: il concetto stesso di funzione virtuale prevede un collegamento fra un oggetto e una funzi­o­ne; le funzioni statiche sono indipendenti dagli oggetti della loro classe, quindi le due cose sono incompatibili;

- una funzione può essere dichiarata `virtual` solo nella classe base: non è possibile effettuare la dichiarazione in una classe derivata; 

- si può ripetere la specifica `virtual` anche nelle classi derivate, ma non è necessario: lo vedi nell’esempio, dove la seconda versione della funzione `getClass()` non ha la parola chiave `virtual` davanti;

- l’utilizzo dell’operatore di risoluzione della portata annulla inevitabilmente l’effetto delle funzioni virtuali.

<hr id="classi-astratte">

È possibile dichiarare una funzione virtuale nella classe base senza definirne il comportamento, se si utilizza la sintassi:

```
virtual <tipo> nomefunzione([argomenti]) = 0 ;
```    

Questo tipo di funzioni si chiamano <i id="funzioni-virtuali-pure">funzioni virtuali pure</i> e rendono la classe a cui appartengono una *classe astratta*.  
Le classi astratte sono delle classi generiche che possono essere utilizzate come capostipiti per una discendenza di classi specializzate, ma che non possono essere utiliz­zate direttamente.
Le regole che si applicano alle classi astratte sono:

- viene considerata astratta qualunque classe che abbia almeno una funzi­one virtuale pura;
- le funzioni virtuali pure sono ereditate come dalle classi derivate come funzioni virtuali pure, quindi, se una classe derivata non ridefinisce una funzione virtuale pura della sua classe base sarà considerata dal compilatore come una classe as­tratta;
- non si possono utilizzare classi astratte come argomenti o come tipi di ritorno di funzioni;
- le classi astratte non possono essere il tipo di un oggetto o di una con­versione esplicita.

Data una classe astratta `Mammifero`, le istruzioni seguenti causerebbero degli errori di compilazione:

```
void funz(Mammifero m);  // non possono essere argomenti..
Mammifero funz();        // nè valori di ritorno..
Mammifero pollo;         // nè il tipo di un oggetto()..
punt = (Mammifero*)ptr;  // nè il tipo di una conversione.
```

È possibile, però, dichiarare un puntatore o una *reference* a una classe astratta e utilizzarli per creare degli array o delle code che possano essere utilizzati con istanze di classi diverse: 

```
{% include_relative src/ereditarieta-classi-astratte.cpp %}
```

Se compili ed esegui questo codice, otterrai:

```
> g++ src/cpp/ereditarieta-classi-astratte.cpp -o src/out/esempio
> src/out/esempio                                                
cane
femmina
Scylla
cane
femmina
```

La classe base `Mammifero` definisce solo un’astrazione, lasciando alle sue classi derivate il compito di definire attributi e metodi specifici per ciascuna specie particolare. 
Allo stesso modo, la funzione `getSpecie` definisce solo un concetto, non un algoritmo; saranno le singole classi deri­vate a ridefinire il comportamento della funzione, adattandolo alle proprie esigen­ze.  
È possibile, comunque, definire un comporta­mento anche per le funzioni virtuali pure; per la classe `Mammifero` potrebbe essere qualcosa di simile:

```
inline void Mammifero::getSpecie() 
{
    cout << "nessuna" << endl ;
}
```

Non potendo esistere oggetti di classe `Mammifero`, però, la versione base della funzione `getSpecie` potrebbe essere richiamata solo facendo uso dell’operatore `::` 

```
mioCane.Mammifero::getSpecie();
cane.Mammifero::getSpecie();
```
<hr id="dottrina">

> Le figure mitiche, è vero, nascono e trapassano, ma non proprio come noi mortali. Hanno bisogno di denominazioni caratteristiche, come quella di «Re nel Passato e nel Futuro». Sono esistite in passato? Allora sono esistite ancor prima, o esisteranno ancora, con altri nomi, sotto altri aspetti, proprio come il cielo ci riporta in eterno le sue configurazioni. Se si cercasse di definirle con precisione come persone e cose, sicuramente svanirebbero ai nostri occhi, quanto i frutti di una fantasia malata. 
Ma se si rispetta la loro vera natura, riveleranno questa natura come funzioni.
<a class="nota" href="/man/note#miti"></a>

<!--



Forse come classi astratte

-->
