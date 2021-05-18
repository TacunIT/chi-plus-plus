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
Mammifero funz();        // né valori di ritorno..
punt = (Mammifero*)ptr;  // né il tipo di una conversione.
Mammifero pollo;         // né il tipo di un oggetto
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

Buona parte degli esempii e delle cose che ti ho detto in questa lezione le ho prese dal manuale di programmazione in C++ che il Maestro Canaro scrisse nel Secolo scorso, modificandoli per adattarli a questo contesto.   
L'esempio originale delle funzioni virtuali, per dire, era così:

```
{% include_relative src/ereditarieta-codice-canaro.cpp %}
```

Essendo un codice scritto per l'ambiente Microsoft del 1995 <!-- con i nomi dei file di otto caratteri al massimo: sembra di parlare della preistoria.. -->, se provassi a compilarlo adesso, con il compilatore GNU, otterresti una lunga serie di errori:

```
> g++ src/cpp/ereditarieta-codice-canaro.cpp -o src/out/esempio
src/cpp/ereditarieta-codice-canaro.cpp:8:10: 
fatal error: 'iostream.h' file not found
#include <iostream.h>
         ^~~~~~~~~~~~
src/cpp/ereditarieta-codice-canaro.cpp:13:8: 
error: use of undeclared identifier 'cout'; 
did you mean 'std::cout'?
        { cout << "Sono un oggetto di classe A \n" ; } 
          ^~~~
          std::cout
/Library/Developer/CommandLineTools/usr/bin/
../include/c++/v1/iostream:54:33: note: 
'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
src/cpp/ereditarieta-codice-canaro.cpp:21:8: 
error: use of undeclared identifier 'cout'

did you mean 'std::cout'?
        { cout << "Sono un oggetto di classe B \n" ; } 
          ^~~~
          std::cout
/Library/Developer/CommandLineTools/usr/bin/
../include/c++/v1/iostream:54:33: note: '
std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
src/cpp/ereditarieta-codice-canaro.cpp:24:1: 
error: 'main' must return 'int'
void main()
^~~~
```

Il valore didattico di questo codice, però, è immutato.
Il *Karma* dei due oggetti è determinato dalla dichiarazione delle loro classi, che non gli lascia altra possibilità che fare ciò per cui sono stati creati.
L'output delle funzioni, lo stile dei commenti o il fatto che in un caso le classi si chiamino `A` e `B`, mentre nell'altro si chiamano `Persona` e `Madre`, sono solo differenze formali che non influiscono sul *Dharma* dell'esempio, che è quello di illustrare il comportamento delle funzioni virtuali.
Se in vece del nuovo codice io avessi usato quello originale del Maestro Canaro, tu avresti capito ugualmente; forse anche meglio, perché il nuovo codice sembra migliore a me, ma non è detto che lo sia per te.  
Lo stesso principio vale anche per l'Universo.
Così come gli oggetti all'interno di uno stesso programma occupano posizioni diverse in memoria, a seconda del momento in cui il programma viene eseguito, gli esseri senzienti possono manifestarsi in luoghi e tempi differenti nei diversi cicli di esistenza.  
Ciascuno di noi è un orchestrale a cui è stata assegnata una partitura.
Possiamo suonarla più o meno bene o non suonarla affatto, nascondendoci nel pieno d'orchestra, ma il nostro valore è solo &mdash; permettimi il gioco di parole &mdash; strumentale, perché ciò che conta non siamo noi: è la musica; e questa, non è né la prima né l'ultima volta che la suoniamo.    
Io, qui, ora, con il mio naso la mia bocca e i miei capelli, ti sto insegnando ciò che so del C'hi++ e tu, che hai il tuo naso la tua bocca e i tuoi capelli, lo stai scrivendo nel tuo libro, ma la stessa informazione che stiamo trasmettendo e perpetuando la potrebbero trasmettere e perpetuare anche persone diverse in un altro tempo o in un altro Pianeta in un altro ciclo dell'Universo.

> {{site.data.citazioni.santillana.mito}} <a class="nota" href="/man/note#miti"></a>

Ogni epoca ha i suoi eroi e i suoi demoni; la memoria delle loro battaglie, genera il mito.  
La Scienza è transeunte: abbiamo poche notizie riguardo le conoscenze scientifiche dei popoli del passato<!-- esempi? -->, mentre conosciamo bene i loro miti, perché il mito è immortale; la Scienza no, a meno che non sia assorbita dal mito e trasformata in leggenda o superstizione.
Il Maestro Canaro, per esempio, era convinto che la superstizione relativa ai numeri 13 e 17 fosse nata dall'osservazione del comportamento delle locuste, <!-- il nome corretto, dice Dawkins, è: “cicale periodiche”, ma, per chiarezza, preferisco utilizzare quello più noto --> che, a seconda della specie, passano o tredici o diciassette anni sotto terra in uno stadio larvale <!-- anche qui, Ricky precisa che il termine tecnico è: “ninfe” -->, poi escono fuori tutte insieme e spendono la loro breve vita devastando le coltivazioni.
La paura dei numeri 13 e 17, secondo lui, era una conoscenza scientifica tramandata nel tempo e nello spazio come superstizione dalle culture contadine che, ciclicamente, vedevano devastati loro raccolti.  

<hr id="arte">

L'arte è il motore del mito.
Un motore che si auto-alimenta, perché si nutre di eventi epici e li genera a sua volta ispirando gli eroi a imprese degne di memoria.  
La parola *arte*, così come: *amore*, del resto, è una di quelle parole che le gente utilizza spesso ma di cui non viene mai data una definizione precisa, perché le si ritiene dei concetti auto-esplicativi che non occorre definire. 
È sbagliato: come abbiamo visto, tutte le parole, anche quelle più comuni, possono essere interpretate in maniera differente.
In un suo saggio giovanile su Amore e Arte, il Maestro Canaro scrisse che:
 
 > L'Arte è la traccia del cammino dell'Uomo verso Dio 
 
 specificando poi che, con il termine: "Dio" (altra parola interpretata in maniera differente da ciascuno di noi), intendeva il senso dell'Esistenza.
Alcuni anni dopo, però, guardando delle foto di crostate realizzate dallo chef Gianluca Fusto<a href="/note/#fusto" class="nota"></a>, capì che la sua definizione era imperfetta, perché non includeva, o quanto meno lasciava a margine, gli arte-fatti che non ricadevano nelle categorie artistiche canoniche. 
Modificò per ciò la sua definizione di Arte in:

> L'Arte è la traccia del cammino dell'Uomo verso la Perfezione

Non si trattò di una contraddizione, ma di una precisazione, dato che per lui &mdash; così come per noi del resto &mdash; la ricerca della perfezione era, effettivamente, il senso dell'Esistenza.  
Questo episodio della vita del Maestro Canaro ha la peculiarità di dimostrare i principii stessi che afferma: il primo è che dobbiamo sempre verificare e mettere in discussione le nostre idee, se ci accorgiamo che sono sbagliate o incomplete; il secondo è che, se affrontiamo la vita nel modo giusto, tutto ciò che facciamo sarà Arte, non solo la disposizione dei fiori o la cerimonia del Té.  
Nella vita non esistono momenti di serie *A*, in cui facciamo le cose che ci piacciono e momenti di serie *B*, in cui facciamo ciò che è necessario fare: ogni istante è importante.
Per sottolineare questo precetto, il Maestro Canaro definì un'estetica per la disposizione del bucato sullo stendi-panni; per non correre il rischio di essere preso troppo sul serio, la chiamò <i id="ikebarba">Ikebarba</i>.  
I principii dell'Ikebarba, così come li formulò il Maestro Canaro, sono:

**L'Ikebarba è fatta per l'uomo, non l'uomo per l'Ikebarba<a href="/man/note#shabbat" class="nota"></a>.**  
L'Ikebarba non deve essere un peso per chi la pratica, ma un obbligo giojoso.
I panni devono comunque essere messi ad asciugare; il tempo necessario a farlo in maniera sciatta o consapevole è pressocché lo stesso, ma un'Ikebarba ben fatta provvederà panni asciutti in minor tempo e renderà la vista dello stendipanni meno fastidiosa.

**L'Ikebarba comincia nel negozio.**  
Gli indumenti di colore diverso o con colori sgargianti sono difficili da accostare cromaticamente; è preferibile quindi acquistare abiti dalle tinte sobrie e possibilmente intonati gli uni agli altri, in modo da renderne più facile e più elegante la composizione sullo stendi-panni.
Attenzione, però: un guardaroba di tipo militare o maoista, con indumenti identici e dello stesso colore è un eccesso da rifuggire, perché renderebbe
monotona la composizione (e non solo quella).

**L'Ikebarba rifugge le mollette.**  
Le mollette sono utili come la psicanalisi: è l'equilibrio che deve tenere i panni sui fili, non una forza di coercizione esterna.
I diversi capi devono essere posti sul filo in modo che il peso di una parte bilanci quello dell'altra.

Esistono tre tipi di Ikebarba:

- **cromatica:** quando i panni vengono posizionati sullo stendino in base al loro colore;

- **funzionale:** quando gli indumenti sono posizionati in funzione dei rispettivi tempi di asciugatura, ponendo i capi pesanti all'esterno, dove ricevono più aria, e quelli più leggeri o sintetici all'interno;

- **perfetta:** quando gli aspetti estetici e funzionali si fondono in un tutt'uno armonico.

Come puoi facilmente intuire, gli intenti del Maestro Canaro erano per buona parte ironici (mi confessò che la prima formulazione della disciplina era nata come un tentativo di dissimulare la sua ossessione per l'ordine) e per lungo tempo fu indeciso se includerla o meno nel corpo della Dottrina.
Si decise a farlo quando capì che le sue perplessità nascevano proprio da quelle forme di prevenzione che l'Ikebarba doveva contrastare.  
A ogni modo, l'Ikebarba può davvero comportare dei benefici per chi la pratica.
In primo luogo, modera l'effetto nefasto dell'Annosa Dicotomia e dei suoi servitori *Marketing* e *Moda*, che ci spingono ad acquistare indumenti che non ci occorrono e che sfrutteremo solo per breve tempo.
Riducendo le variazioni cromatiche del bucato, poi, riduce anche il numero di lavaggi settimanali e con esso il fabbisogno di energia elettrica, acqua, prodotti detergenti e plastica.
Anche il ripudio delle mollette ha una sua valenza funzionale: se i capi sono messi ad asciugare a cavallo dei fili, l'acqua nel tessuto tenderà a scendere da entrambi i lati, riducendo il tempo dell'asciugatura.  
Indubbiamente, il fatto che la Regola del nostro Ordine ci imponga l'uso di camicie bianche non risolve il problema dell'inquinamento, ma, come diceva il Maestro Canaro: 

> La pelliccia è fatta di peli

e finché la nostra specie non imparerà a fare un uso più responsabile delle sue gonadi, non potremo far altro che compensare come possiamo i problemi legati alla sovrappolazione.


<!--
Banzan e Paul Simon ci insegnano che la Verità è ovunque, se la sappiamo cercare, anche sui muri delle metropolitane o nelle botteghe dei mercati.

l'Ikebarba riduce la necessità di energia e quindi l'inquinamento. 


-->
