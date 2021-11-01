---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Classi e oggetti
permalink:  /man/classi-oggetti
quote:      "Ceci n'est pas une |"
---

<!-- Quando ho cominciato a scrivere questo capitolo, si è rotto il tasto "o" del mio Mac. È Domenica e siamo in clausura da COVID, quindi non posso andare in un centro commerciale a comprarne una esterna, temporanea. Perdonate eventuali refusi -->

La possibilità di definire nuovi tipi di dato grazie alle classi è la caratteristica principale del C++.

I linguaggi di programmazione “tradizionali”, come il Cobol il Fortran o il Pascal, hanno un insieme limitato di tipi di dato: interi, numeri in virgola mobile, booleani, caratteri e stringhe.. giusto quello che serve a gestire una scheda anagrafica o un conto in banca.
Il C e il Pascal hanno anche la possibilità di accorpare questi dati in strutture, enumerati o array, ma si tratta solo di contenitori, privi di logica interna.
Inoltre, come hai visto, i dati all'interno di una `struct` sono accessibili a qualunque componente del programma, quindi, se li si modifica, va modificato anche il codice che li utilizza.
Immagina di definire una struttura per la gestione dell'orario, che contenga tre interi, uno per le ore, uno per i minuti e uno per i secondi:

```
struct Orario {
    int h;
    int m;
    int s;
};
```

Per utilizzare questa struttura è necessario conoscerne il contenuto e il rapporto fra un valore e l'altro; in particolare, è necessario sapere (e ricordarsi): 

- che la variabile `h` può contenere solo valori da 0 a 23;
- che il valore di `m` può contenere solo valori da 0 a 59;
- che il valore di `s` può contenere solo valori da 0 a 59;
- che se `s` supera il valore di 59, `m` va incrementato di 1;
- che se `m` supera il valore di 59, `h` va incrementato di 1;

Questo è l'opposto del *low coupling* di cui abbiamo parlato <a href="/man/struttura-dei-programmi#coupling" class="xref">tempo fa</a>, perché lega indissolubilmente una funzione alla struttura del dato che deve gestire.
Per capirsi: una funzione di aggiornamento dei minuti dovrà essere qualcosa di simile a:

```
void aggiornaMinuti(struct Orario &o, int minuti) 
{
    /** Incrementa il numero dei minuti */
    o.m += minuti;
    
    /** Se necessario, incrementa le ore */
    if(o.m >= 60) {

        o.m -= 60;
        o.h += 1;
        
        /** Se necessario, passa al giorno dopo */
        if(o.h >= 24) {
            o.h -= 24;
        }
    }
}
```
Se un giorno decidessimo di modificare la struttura `Orario`, dovremmo ricordarci di riscrivere anche questa funzione, adeguandola alle nuove caratteristiche della struttura, con dispendio di tempo e la possibilità di fare degli errori.
Inoltre, nulla impedirebbe a un programmatore cialtrone di scrivere una funzione che non tiene minimamente conto del rapporto fra ore, minuti e secondi:

```
void incrementa_m(struct Orario &o, int minuti) 
{
    o.m += minuti;
}
```

Se inseriamo queste due funzioni in un programma, otteniamo:

```
{% include_relative src/classi-struttura-orario.cpp %}
```

Compilando ed eseguendo questo codice, ottieni:

```
> g++ src/cpp/classi-struttura-orario.cpp -o src/out/esempio 
> ./src/out/esempio                                          
23:45:00
00:05:00
23:65:00
```
Come puoi vedere, la prima funzione ha aggiornato i dati in maniera corretta, mentre la seconda ha prodotto un valore non valido senza alcuna possibilità di controllo da parte del programma.

<hr id="attributi-metodi">

Le variabili all'interno di una classe, sono dette *dati membro* o *attributi* della classe; le funzioni, invece, sono dette *funzioni membro* o *metodi*.
Quando si crea una variabile di classe `X`, si dice che si: *istanzia* un *oggetto* di classe `X` o che si crea una *istanza* della classe.
I dati e le funzioni membro di una classe sono direttamente accessibili alle funzioni membro della classe, ma per utilizzarli all'interno di funzioni esterne alla classe, si devono utilizzare gli operatori di selezione `.` e `->`. 
Il primo, detto *operatore di selezione diretta*, viene utilizzato con istanze della classe; il secondo, detto *operatore di selezi­one indiretta*, con puntatori ad esse:

```
{% include_relative src/classi-punto.cpp %}
```

L'etichetta `public` che vedi all'inizio della dichiarazione della classe è un <i id="specificatori-accesso">specificatore di accesso</i> e serve a stabilire quali membri della classe siano accessibili a funzioni esterne e quali invece siano riservati in esclusiva alla classe stessa.

> il selvaggio non ama dire il suo nome o farsi fotografare, perché per mezzo del suo nome o del ritratto egli è accessibile, e può quindi ricevere danno da chi con questi mezzi è in grado di raggiungerlo<a href="/man/note#selvaggio" class="nota"></a>.

Questa frase di Lucien Lévy-Bruhl si applica anche alle classi del C++. 
Sia gli attributi che i metodi di una classe possono essere protetti da accessi o modifiche indebite grazie ai modificatori di accesso `private`, `protected` e `public`.
I metodi o gli attributi dichiarati `private` sono accessibili solo alla classe stessa; quelli dichiarati come `protected` sono accessibili alla classe e a eventuali <a href="/man/ereditarieta" class="xref">classi derivate</a>; quelli dichiarati come `public` sono accessibili a qualunque elemento del programma.
In mancanza di specifiche, tutti i dati e le funzioni di una classe verranno considerati:

-	*privati*, nel caso di una classe;
-	*pubblici*, nel caso di `struct` o `union`.

La visibilità dei dati membro di una  `struct` può essere modificata con gli indicatori di accesso; i dati delle `union`, invece, possono essere solo pubblici.  
Il C++ permette di suddividere la dichiarazione di una classe in quante sezioni si desidera e nella sequenza `private`, `public`, `pro­tected` che si preferisce, ma un codice scritto in questo modo è sicuramente più difficile da leggere di uno in cui tutti i membri privati stanno da una parte e tutti quelli pubblici da un’altra.
Quindi, a meno che tu non abbia delle buone ragioni per fare altrimenti (e ce ne potrebbero essere, nel caso di classi particolarmente complesse), cerca di raggruppare in tre sole sezioni `private`, `pro­tected` e `public` tutte le funzioni e i dati membro con gli stessi attributi di accesso:

```
class Persona
{
 private:
    ...
 protected:
    ...
 public:
    ...
};
```

Questo tipo di ordinamento della dichiarazione, oltre a garantirti una maggiore leggibilità del codice, ti consentirà, se lo desideri, di omettere lo specificatore di accesso `private` iniziale (è la soluzione di default, ricordi?).  
Mettiamo in pratica tutto ciò, convertendo in classe la struttura `Orario`:

```
class Orario {
private:
    int _h;
    int _m;
    int _s;
public:
    Orario() {
        _h = 0;
        _m = 0;
        _s = 0;
    }
};
```

La dichiarazione inizia con la parola-chiave `class`, seguìta dal nome della classe.
Nel blocco di codice fra parentesi graffe che costituisce il corpo della classe, contiene i dati e le funzioni membro, accorpate per visibilità. 
In questo caso abbiamo messo prima i dati membro privati e poi quelli pubblici, ma avremmo potuto fare anche il contrario.
Gli attributi `_h`, `_m` e `_s` compaiono dopo la parola-chiave `private` e saranno quindi visibili solo alle funzioni della classe stessa.  
La funzione `Orario` compare dopo l'etichetta `public` e sarà accessibile per ciò a qualsiasi parte del programma.
Questa funzione, che ha lo stesso nome della classe, è detta *costruttore* e viene richiamata ogni volta che si crea una variabile di tipo `Orario`.
Il suo scopo è di inizializzare le variabili all'interno della classe, in questo caso, impostando tutti e tre i valori a 0. 
Ne parleremo fra poco.  
L'ultima cosa che devi notare, nel codice qui sopra, è la presenza del carattere `;` alla fine del blocco di codice della classe, così come avviene per le `union` e le `struct`.


<hr id="costruttori">

Quando dichiariamo una variabile di tipo primitivo come `int`, o `double`, il compilatore svolge automaticamente tutta una serie di operazioni atte ad allocare lo spazio di memoria necessario a contenerla e a inizializzarlo.
Il compilatore, però, non sa come vada creata e inizializzata una variabile di tipo `Orario` ed è per questo che la classe dovrà definire delle *funzioni di gestione* che spieghino sia come creare una nuova variabile, che come distruggerla, se necessario. 
Le funzioni di gestione sono di due tipi: i *costruttori* e i *distruttori*.  
I costruttori hanno alcune peculiarità che le distin­guono dalle altre funzioni membro: 

- hanno lo stesso nome della classe;
- non hanno un tipo di ritorno perché è implicito che ritornino una variabile   della classe cui appartengono.

Una stessa classe può avere più costruttori; la classe `Orario`, per esempio, potrebbe avere un costruttore privo di parametri, che inizializzi ore, minuti e secondi a zero e un costruttore che permetta invece di assegnare valori specifici a ciascun attributo:

```
class Orario {
protected:
    int _h;
    int _m;
    int _s;
public:
    Orario() {
        _h = 0;
        _m = 0;
        _s = 0;
    }
    Orario(int h, int m, int s) 
    : _h(h % 24), _m(m % 60), _s(s % 60) {
    }
};
```

La riga: 

```    
: _h(h % 24), _m(m % 60), _s(s % 60) 
```

si chiama: *lista di inizializzazione* e ed equivale a scrivere:

```
_h = h % 24;
_m = m % 60;
_s = s % 60;
```

L'utilizzo dell'operatore modulo `%` è indispensabile, in questo caso, per evitare che siano assegnati valori non corretti alle variabili.  
Quando definisci un costruttore, puoi usare indifferentemente l'una o l'altra sintassi o anche mischiarle, a seconda dei casi.
Un modo più succinto di ottenere lo stesso risultato con un unico costruttore è di utilizzare dei valori di default per i parametri:

```
Orario(int h = 0, int m = 0, int s = 0) 
: _h(h % 24), _m(m % 60), _s(s % 60) {
}
```

Alle volte, può essere utile definire un costruttore che crei delle nuove variabili della classe partendo da variabili esis­tenti, operando quindi una sorta di clonazione. 
Questo tipo di funzioni si chiamano: *costruttori di copia* o: *costruttori di inizializ­zazione* e richiedono come argomento un riferimento a una variabile della stessa classe:

```
/** 
 * Dichiarazione del costruttore di copia 
 * all'interno della classe. 
 * Possiamo copiare il valore delle variabili 
 * così com'è perché è già stato verificato 
 * dal costruttore della variabile o1.  
 */
Orario::Orario(const Orario& )
: _h(o._h), _m(o._m), _s(o._s) {
}

/** Utilizzo */
Orario o2 = o1;
```

Il costruttore di copia è un tipo di costruttore molto importante in quanto presiede alla maggior parte delle attività di inizializzazione di oggetti della classe cui appartiene; per questa ragione, nel caso non venga definito dall’utente, è automaticamente generato dal compilatore.

<hr id="distruttori">

Come è facile intuire, mentre il costruttore di una classe presiede alla creazione di nuove variabili, il distruttore si occupa della loro cancellazione. 
Non sempre è necessario definire un distruttore per una classe.
Una variabile di tipo `Orario`, che contiene solo tre interi, probabilmente non avrà bisogno di un distruttore, mentre una variabile che faccia uso di memoria dinamica quasi sicuramente sì. 
Il perché risulta più chiaro se si esamina la cosa dal punto di vista del compilatore.
Per creare una variabile di tipo `Orario` il compilatore deve allocare spazio per:

```
3 * sizeof(int);
```

Quando arriva il momento di distruggere la variabile, il compilatore non farà altro che liberare i ```3 * sizeof(int) ``` byte successivi all’indirizzo dell’oggetto; un comportamento che in questo caso è corretto, ma che potrebbe dare rivelarsi disastroso con una classe come questa:

```
class Buffer
{
private:
    char* _dati;
    int   _size;
 public:
    Buffer(int size) 
    : _size(size) {
        _dati = new char[_size];
    }
    ...
};
```

In mancanza di istruzioni specifiche, per distruggere una variabile di tipo `Buffer`, il compilatore libererà ```sizeof(char*) + sizeof(int)``` byte dopo il suo indirizzo di memoria, ma così facendo, distruggerà solo l’intero `_size` e il puntatore a char `_dati`, senza liberare l’area di memoria a cui quest’ultimo puntava.
Questo, come sai, è un grave errore ed è necessario quindi aggiungere alla classe una funzione che lo istruisca in tal senso.   
Come il costruttore, il distruttore di una classe non ha tipo di ritorno, ma mentre ci possono essere più costruttori per una stessa classe, il distrut­tore è sempre unico.
Non ha mai parametri formali e il suo nome è uguale a quello della classe cui appartiene, preceduto da un carattere tilde `~`:

```
class Buffer
{
private:
    char* _dati;
    int   _size;
 public:
    Buffer(int size) 
    : _size(size) {
        _dati = new char[_size];
    }
    ~Buffer() {
        delete [] _dati
    }
};
```

I distruttori possono essere chiamati in due modi: 

- *implicitamente*, dal programma, ogni volta che un oggetto esce dal suo campo d’azione o, nel caso di oggetti con visibilità globale, al termine della funzione `main`;

- *esplicitamente*, dal codice, ma in questi casi dovrai specificare il loro nome per intero, anteponendo il nome della classe e l'operatore di risoluzione `::`, così come vedremo fra poco.
    
Attenzione, però: se a uscire dal campo d’azione è un puntatore, il distruttore della classe non viene richiamato automaticamente, perciò gli oggetti creati in maniera dinamica con l'operatore `new` dovranno sempre distrutti per mezzo dell’operatore `delete`.  

<hr id="funzioni-di-interfaccia">

Le funzioni membro devono essere dichiarate all'interno della dichiarazione della classe e possono essere definite sia dentro che fuori di essa. 
Definirle all'interno della dichiarazione della classe equivale a dichiararle <a href="/man/funzioni#inline" class="xref">inline</a>
Se invece le si definisce esternamente alla dichiarazione della classe, vanno identificate aggiungendo il nome della classe prima di quello della funzione, seguito dall'<a href="/man/operatori#risoluzione" class="xref">operatore di risoluzione</a>:

```
{% include_relative src/classi-classe-orario.cpp %}
```

Se compili questo codice, però, ottieni un errore: la funzione `main` può utilizzare il costruttore della classe `Orario` perché è dichiarato `public`, ma non può né leggere né modificare gli attributi definiti come `private`:

``` 
> g++ src/cpp/classi-classe-orario-1.cpp -o src/out/esempio
src/cpp/classi-classe-orario-1.cpp:34:44: error: '_h' is a protected member of 'Orario'
    cout << setfill('0') << setw(2) << ora._h << ":" 
                                           ^
src/cpp/classi-classe-orario-1.cpp:14:9: note: declared protected here
    int _h;
        ^
src/cpp/classi-classe-orario-1.cpp:35:44: error: '_m' is a protected member of 'Orario'
         << setfill('0') << setw(2) << ora._m << ":" 
                                           ^
src/cpp/classi-classe-orario-1.cpp:15:9: note: declared protected here
    int _m;
        ^
src/cpp/classi-classe-orario-1.cpp:36:44: error: '_s' is a protected member of 'Orario'
         << setfill('0') << setw(2) << ora._s << endl;
                                           ^
src/cpp/classi-classe-orario-1.cpp:16:9: note: declared protected here
    int _s;
        ^
3 errors generated.
```

Il C++ prevede due modi per rendere disponibili gli attributi di una classe anche alle funzioni esterne alla classe stessa: 

- le classi o le funzioni `friend`.
- le *funzioni di interfaccia*;

Il modo apparentemente più rapido per accedere ai dati privati di una classe attraverso una funzione o una classe esterna è quello di dichiararle come `friend`.
In virtù di ciò, la funzione o la classe acquisteranno una visibilità completa sui dati protetti:

```
class Orario {
private:

    /** Dati membro privati */
    int _h;
    int _m;
    int _s;

public:
    
    /** Costruttore della classe */
    Orario(int h = 0, int m = 0, int s = 0) ;

    /** Costruttore di copia inline */
    Orario(const Orario& o) {
        _h = o._h;
        _m = o._m;
        _s = o._s;
    }

    /** Funzioni di lettura  */
    int getH() { return _h; }
    int getM() { return _m; }
    int getS() { return _s; }

    /** Funzioni di scrittura */
    int setH(int h) { return _h = (h % 24); }
    int setM(int m) { return _m = (m % 60); }
    int setS(int s) { return _s = (s % 60); }

    /** Dichiarazione di una funzione friend */
    friend int aggiornaMinuti(Orario& o, int m);
    friend class Orologio(); 	

};
```

Come ho detto, questa soluzione è solo apparentemente più rapida, perché tutta la logica di gestione dei dati della classe `Orario` dovrà essere replicata sia nella funzione `aggiornaMinuti` che nella classe `Orologio`.
Inoltre, se in seguito dovessi apportare delle modifiche alla classe `Orario`, le stesse modifiche andranno riportate anche nelle funzioni delle classi `friend` che la utilizzano.  
Un metodo più sicuro e più efficiente di gestire gli attributi privati di una classe consiste nel definire delle funzioni membro pubbliche che consentano un accesso controllato ai dati che si vogliono proteggere. 
Nel caso della classe `Orario`, ne occorrono sei: una per la lettura e una per la scrittura di ciascuno dei tre dati membro:

```
/** Funzioni di lettura */
int getH() { return _h; }
int getM() { return _m; }
int getS() { return _s; }

/** Funzioni di scrittura */
int setH(int h) { return _h = (h % 24); }
int setM(int m) { return _m = (m % 60); }
int setS(int s) { return _s = (s % 60); }
```

Ovviamente, puoi chiamare queste funzioni come preferisci, ma utilizzare i prefissi `get` e `set`, seguiti dal nome del parametro su cui operano rende più facile l'utilizzo della classe da parte di altri programmatori.
È lo stesso motivo per cui aggiungo il carattere *underscore* davanti al nome dei dati membro delle classi, in modo che li si possa distinguere dai  parametri delle funzioni che abbiano lo stesso nome:

```
return _h = (h % 24);
```

L'utilizzo della lista di inizializzazione, all'interno del costruttore, ti permette di utilizzare dei parametri che abbiano lo stesso nome dei dati membro della classe:

```
class Punto
{
    int x, y;
public:             
    Punto(int x, int y) 
    : x(x), y(y) {
    }
};
```
ma il fatto che qualcosa sia possibile non vuol dire che sia una buona scelta, come penso che tu abbia imparato, nel corso della tua vita.  
Non sei nemmeno obbligato a dichiarare le funzioni di interfaccia come `inline`; l'ho fatto qui perché erano estremamente semplici, ma si dovrebbe evitare di aggiungere il codice delle funzioni all'interno della dichiarazione di una classe già di per sé complessa perché la rende più difficile da leggere.
C'è anche chi pensa che ciò sia sbagliato perché, se da un lato rende le cose più facili a chi scrive il codice, complica la vita di chi lo legge perché mischia ciò che la classe fa con il modo in cui lo fa<a href="/man/note#inline" class="nota"></a>.
Io non sono del tutto d'accordo con questa affermazione perché alle volte è più comodo e rapido avere il codice delle funzioni all'interno della dichiarazione della classe, ma essendo un precetto che antepone il bene di tanti (i fruitori del codice) rispetto a quello del singolo (l'autore del codice), mi sono sentito in dovere di riferirtelo.  
Così come abbiamo fatto per il costruttore della classe, potremmo unificare le funzioni di lettura e scrittura, utilizzando un parametro di default che determini il comportamento del programma:

```
int ore(int h = -1) { 
    return _h = ((h != -1) ? _h = (h % 24) : h); 
}
```

Questa sintassi è l'equivalente di:

```
int ore(int h = -1) { 
    if(h != -1) {
        _h = (h % 24);
    }
    return _h; 
}
```

Anche se meno evidente, è più comoda perché permette di tenere il codice su una sola riga e ti dà modo di fare un po' di pratica con gli operatori.  
Questo tipo di funzioni, però, ha due difetti: limita i valori che puoi assegnare all'attributo e limita la granularità dei privilegi che puoi assegnare a chi utilizza la classe.
Limita il numero di valori che puoi assegnare all'attributo, perché esclude il valore del parametro di default &mdash; cosa che non crea problemi in questo caso, dato che non esiste un'ora `-1`, ma che potrebbe farlo nel caso di una stringa con parametro di default nullo.
Limita la granularità dei privilegi sulle funzioni, perché ti costringe a rendere pubbliche le funzioni di scrittura dei dati membro e questo, in certi casi potrebbe non essere saggio. 
Ti consiglio perciò di scrivere sempre due funzioni di interfaccia distinte per la lettura e la scrittura: sul momento ti sembrerà uno spreco di tempo, ma, a meno che il tuo programma non sia particolarmente banale, o prima o poi ti accorgerai di aver fatto la scelta corretta.  

<hr id="static">

Ogni variabile di una determinata classe possiede delle copie dei dati membro, mentre le funzioni membro di una classe sono condivise da tutte le sue istanze.
Per consentire al programma di sapere quale sia l'istanza che sta richiamando un determinato metodo, il compilatore aggiunge a ogni chiamata a funzione un parametro nascosto chiamato `this`, che punta all'istanza che ha richiesto la funzione.
Il parametro `this`, anche se non dichiarato, può essere utilizzato nel corpo delle funzioni membro per riferirsi all'istanza corrente.
Per esempio, il costruttore di copia della classe `Orario` (così come qualsiasi altra funzione membro della classe) potrebbe essere riscritto così:

```
Orario(const Orario& o) {
    this->_h = o._h;
    this->_m = o._m;
    this->_s = o._s;
}
```

Le uniche funzioni membro che non possono fare uso del puntatore `this` sono quelle dichiarate come `static`.  
Una classe può avere sia attributi che funzioni membro statiche.
La particolarità di questi elementi è di non essere legati a una specifica variabile, ma di essere condivisi da tutte le istanze della classe; questo fa sì che abbiano un comportamento leggermente diverso da quello dei membri non statici:

- per inizializzarli all’interno della dichiarazione, li si deve dichiarare come `inline static`<a href="/man/note#cpp17" class="nota"></a>, 
altrimenti, devono essere inizializzati altrove nel programma, come un qualsiasi oggetto a visibilità globale;

- si può accedere ad essi, oltre che con i normali operatori di selezione, facendo riferimento alla classe stessa.

Cerco di chiarirti un po' le idee con un esempio:

```
{% include_relative src/classi-static.cpp %}
```

Se compili ed esegui questo codice, otterrai:

```
> g++ src/cpp/classi-static.cpp -o src/out/esempio
> src/out/esempio                                 
Da istanza c1: 1
Da istanza c2: 3
Da istanza c3: 3
Dalla classe : 3
```

Come vedi, tutte le istanze della classe condividono lo stesso valore per il dato membro `nIstanze` e la funzione di interfaccia, dichiarata come `static`, può essere richiamata anche senza fare riferimento a un'istanza.
Per questo motivo, se utilizzi il puntatore `this` all'interno di una classe statica:

```
static int nIstanze() {  
    return this->_nIstanze;
}
```

ottieni l'errore di compilazione:

```
> g++ src/cpp/classi-static.cpp -o src/out/esempio 
src/cpp/classi-static.cpp:26:16: error: invalid use of 'this' 
 outside of a non-static member function
        return this->_nIstanze;
               ^
1 error generated.
```

perché, se la funzione fosse chiamata direttamente dalla classe, `this` non punterebbe ad alcun oggetto.

<hr id="classi-anonime">

L'ultima cosa di cui dobbiamo parlare, sono le *classi anonime*, un tipo particolare di classe che, come dice il nome (perdonami il gioco di parole), non hanno nome e per ciò non possono avere né un costruttore né un distruttore e non possono essere utilizzate né come parametri né come valori di ritorno delle funzioni.  
L'unico modo per dichiarare un oggetto con classe anonima è di aggiungerlo alla dichiarazione della classe stessa:

```
class 
{
...
} obj;
```

Questo codice dichiara allo stesso tempo la classe e la sua unica istanza, la variabile globale `obj`.  
Quando il Maestro Canaro provò a fare il *porting* dell'<a href="/man/mitopoietica#universo-in-cpp" class="xref">Universo in C++</a>, avrebbe voluto utilizzare una classe anonima per la variabile `Dio`, perché, priva di un costruttore e istanziata dalla sua stessa classe, quella variabile sarebbe stata visibile in tutto il codice, ma nessuna parte del programma ne avrebbe potuta generare un'altra:

```
{% include_relative src/classi-dio.cpp %}
```

L'idea, in sé, era buona, ma venne abbandonata quando si trattò di definire gli attributi e i metodi della classe.
Dio, infatti, ha *tutti* gli attributi immaginabili e ciascuno di essi ha valore infinito.
Allo stesso modo, essendo onnipotente, deve avere delle funzioni membro per portare a termine *tutte* le possibili azioni e il codice di queste funzioni, utilizzando una classe anonima, avrebbe dovuto essere definito all'interno della dichiarazione della classe, perché, mancando un nome, non lo si sarebbe potuto definire esternamente:

```
bool ...::checkFede(Padre& abramo, Figlio& isacco)
{

}
```

<hr id="dottrina">

È un peccato che Platone non sia vissuto duemilaquattrocentoundici anni, perché avrebbe certamente apprezzato l'affinità delle classi del C++ con le sue teorizzazioni riguardo le *idee* e le *forme*.
In questo codice, possiamo considerare la dichiarazione della classe come l'*idea* del pesce, mentre l'istanza ne è la *forma*:

```
{% include_relative src/classi-pesce.cpp %}
```

Come abbiamo detto parlando del <a href="/man/preprocessore#pesce" class="xref">preprocessore</a>, però, la parola *pesce* può avere diversi valori, a seconda di chi la utilizza, quindi, la dichiarazione/idea della classe `Pesce` varierà a seconda dell'utilizzo che se ne deve fare.
Per esempio, sapere se un pesce sia commestibile o no è determinante per un pescatore o per un ecologista, ma potrebbe non esserlo per un biologo marino.
Al contrario, il tipo di scheletro o il sistema di respirazione, rilevanti per un biologo, sono del tutto irrilevanti per un pescivendolo, a cui invece interesseranno sicuramente il prezzo al chilo, la data di cattura e il tipo di conservazione applicato.
Di questo, parleremo nelle prossime lezioni; adesso dobbiamo tornare su una questione che avevamo lasciato in sospeso, ovvero il precetto:

> Amiamo ciò che ci ucciderà (se tutto va bene) 

Abbiamo visto che l'Amore è una forza allo stesso tempo gravitazionale ed entropica, perché unisce gli individui, ma allo stesso tempo li porta a riprodursi in forme differenti.  
In un certo senso, possiamo considerare l'Amore come il “costruttore” delle nostre istanze, perché genera le condizioni che spingono i nostri genitori a incontrarsi e ad accoppiarsi e soprattutto li spinge a restare insieme dopo l'accoppiamento.
La monogamia non è una costante, anzi, in natura esistono quattro modi differenti di gestire la prole e John Maynard Smith li ha catalogati in base alla specie animale che le adotta<a href="/man/note#maynard" class="nota"></a>:

|:--:|:--|
| **Anitra**    | il maschio abbandona, la femmina alleva
| **Spinarello**| la femmina abbandona, il maschio alleva
| **Moscerino** | entrambi i genitori abbandonano
| **Gibbone**   | entrambi i genitori allevano
   
Noi, per lo più, ci comportiamo come i gibboni, anche se è un comportamento che conviene principalmente alle femmine.
Da un punto di vista strettamente statistico, un maschio avrebbe più probabilità di tramandare il suo DNA se fecondasse più compagne.
È lo stesso motivo per cui, nel nostro campo, si creano delle copie dei proprii dati in *server-farm* diverse (e distanti) da quella originale, in modo che se il sito principale va a fuoco o se viene colpito da un meteorite, i dati non vadano persi.
L'Amore, invece, spinge il *webmaster* a tenere i suoi dati in una sola *server-farm*, accudendoli e proteggendoli personalmente, per preservarne il contenuto informativo.  
Ciascuno di noi è l'istanza di una classe che è stata chiamata a vivere per svolgere un determinato compito.
Veniamo generati, assolviamo il nostro compito e poi, così come gli oggetti di un programma, dobbiamo essere rimossi per non occupare inutilmente delle risorse del sistema.
Per essere certi che questo avverrà, c'è bisogno di un distruttore che termini la nostra esistenza nel momento opportuno.
L'Amore può servire anche a questo: così come ha generato nei nostri genitori l'interesse necessario a causare la nostra nascita, genera in noi un interesse che causa le condizioni necessarie alla nostra morte.
Questo interesse può applicarsi a qualunque cosa &mdash; una sostanza, un'attività, un luogo, una o più persone &mdash; e deve essere superiore all'interesse che l'individuo ha nei confronti della sua stessa esistenza.  
Capisci bene che questo è un aspetto potenzialmente rischioso della nostra dottrina, perché potrebbe giustificare delle forme di auto-indulgenza  nei confronti di sostanze o attività dannose come l'abuso di droga o alcol.
La morte di Robert Capa, sopravvissuto allo sbarco in Normandia e ucciso, dieci anni dopo, da una mina anti-uomo mentre fotografava dei soldati sul delta del Fiume Rosso, è un esempio inequivocabile di questo precetto, ma come possiamo sapere se la morte di Jimi Hendrix, Janis Joplin o Jim Morrison, sia stata ciò che doveva essere, o non sia stata, al contrario, la conseguenza di una scelta drammaticamente errata?
Soprattutto, come possiamo evitare che questo precetto non diventi il pretesto per altre scelte errate?  
Ho scelto le tre "J" &mdash; Jim, Jimi e Janis &mdash; perché il Maestro Canaro pensava che, nel loro caso, la morte fosse ciò a cui erano destinati:

> Capisci, avevano tutti ventisette anni e poi quella "J" che ricorre nel nome.. non credo fosse un caso. 
“*Muß es sein? Es muß sein!*”, come direbbe Beethoven.
So cosa stai pensando: che sto cercando di definire un dogma per giustificare una mia speranza, ma non è così. 
La teoria del “27 Club”, anche se include Amy Winehouse e Robert Johnson, lascia dolorosamente fuori il Elvis e Andrea Pazienza<a href="/man/note#pazienza" class="nota"></a>, che io ho amato molto di più.

<hr id="libero-arbitrio">

D'altro canto, non sempre le cose vanno come previsto e può accadere che per una scelta errata o per paura, una “istanza” devii dal suo cammino anticipando o ritardando la propria fine.
Questo perché il nostro agire è preordinato, ma non è obbligato: siamo programmati per fare bene qualcosa e meno bene quacos'altro, ma siamo liberi di scegliere cosa fare.  
Molti si sono chiesti se le nostre azioni siano predestinate o se esista il libero arbitrio; la risposta è: sì, ma in tempi diversi.
Riprendendo il paragone con le classi, la predestinazione è nella dichiarazione, mentre il libero arbitrio è proprio delle istanze.
L'insieme dei tuoi attributi e dei tuoi metodi è predefinito: puoi saltare, ma non puoi volare; puoi nuotare, ma non puoi restare a lungo in immersione; il tuo sangue ha un flusso ben definito e così pure il tuo cibo.
D'altro canto, quello che deciderai di fare dipende da te: puoi decidere di attenerti ai limiti che ti sono stati imposti o cercare di sorpassarli, creandoti delle ali artificiali per volare o dei respiratori per andare sott'acqua. 
Attento, però: questo non farà di te né un uccello né un pesce. Puoi superare i limiti imposti dalla tua classe, ma non la puoi cambiare.  
Non è difficile conciliare il libero arbitrio con l'onniscenza e l'onnipotenza di Dio; la risposta è ovvia, se non fai distinzione fra artefatto e artefice.
Con buona pace di Einstein, Dio gioca davvero a dadi con l'Universo; lo sbaglio è pensare che il risultato di un tiro di dadi derivi da fattori casuali.
Quando si lanciano dei dadi, il risultato finale varia in base a due ordini di fattori, uno facilmente prevedibile e uno difficilmente prevedibile.
Le possibili combinazioni dei dadi sono facilmente prevedibili, noto il numero delle facce e i valori che vi sono impressi.
La combinazione che verrà effettivamente prodotta da un certo lancio di dadi è altrettanto deterministica, ma dipende da fattori molto più complessi, come il tempo per cui li si è agitati, della loro posizione al momento del lancio o l'angolo di impatto con il piano.
Così come è impossibile che un lancio di dadi nel Backgammon produca un valore superiore a dodici, è impossibile che un dado, lanciato con una certa energia in una certa direzione adotti una traiettoria diversa da quella che gli impongono le Leggi della fisica.
Anche se non riusciamo a prevederla, non vuol dire che sia casuale.    
Allo stesso modo, quando l'Uno primigenio “lancia” la sua energia nell'Universo, 
è *onniscente*, perché conosce tutte le scelte che in precedenza si sono rivelate corrette e quelle che invece hanno prodotto del dolore; 
è *benevolo*, perché spera di ottenere il miglior risultato possibile, evitando di ripetere gli sbagli già fatti;
è *onnipotente*, perché può potenzialmente produrre tutte le possibili permutazioni <!-- l'allitterazione è intenzionale :-) --> dell'esistenza dovute all'interazione energia/spazioni.
Malgrado ciò, non sa quale di quelle permutazioni avrà luogo e non lo vuole nemmeno sapere.
Auspica che il nuovo ciclo di esistenza sia migliore dei precedenti, ma non desidera che avvenga un certo evento o che non avvenga un altro,
 perché il desiderio lo renderebbe vulnerabile alle lusinghe dell'Annosa Dicotomia.   
 Un famoso velista<a href="/man/note#straulino" class="nota"></a>, una volta disse:

 > {{ site.data.citazioni.straulino.testo }} 

 L'Uno si comporta in maniera simile: ligio al precetto del *Wu Wei*<a href="/man/note#wu-wei" class="nota"></a> taoista, pone le condizioni necessarie per il ripetersi degli eventi che si sono rivelati benefici, ma non li impone.
Scrive l'analisi del sistema, ma lascia che siano i programmatori a scrivere il codice, anche se sa che faranno certamente degli errori. 
Definisce delle regole, ma lascia le sue istanze libere di trasgredirle, perché sa che l'evoluzione è sempre frutto di un errore venuto male, di qualcosa che non sarebbe dovuto essere così e invece così è meglio.   
Le regole non devono essere una rete che imprigiona e immobilizza, ma una rete che salva e sostiene, così come il “religare” delle religioni non deve essere un legame che impastoia, ma che sorregge.
Le regole che definiscono e quindi limitano la nostra esistenza sono come un edificio che abbia una struttura in cemento armato e dei muri in cartongesso. 
I muri interni possono essere abbattuti o modificati, se necessario, ma i pilastri e le travi devono essere lasciati al loro posto.
Similmente, la modifica delle regole può essere benefica, ma deve essere permessa solo a chi le conosce bene <!-- per esempio, Gesù --> perché un carpentiere maldestro potrebbe - per errore o per stupidità - rimuovere uno dei pilastri portanti mettendo in pericolo la solidità dell'edificio. <!-- per esempio, il Movimento del '68 -->  
Per questi motivi, la modifica delle regole non può essere un'attività ammessa da chi le ha promulgate, anche se ne riconosce l'utilità, ma dev'essere un'attività apparentemente clandestina, svolta da elementi sacrificabili, che possano fungere da capri espiatorii se qualcosa va male.  
Non fu per ingenuità, che l'Altissimo concesse a Iblīs una proroga alla sua punizione<a href="/man/note#iblis" class="nota"></a> e non fu un caso se il Maestro Canaro venne aggiunto al gruppo degli angeli caduti, dopo che, vittima dell'Annosa Dicotomia, cercò di contravvenire alle regole definite dall'Analista.
Se rifiuti le dissonanze, tutt'al più, puoi suonare il Blues; con le dissonanze, hai il Jazz.

<hr id="livelli-esistenza">

Così come l'immagine di una stampa litografica o di una serigrafia esiste sia nella matrice che nella copia, ciascuno di noi ha due livelli di esistenza.
Uno è ideale, simile alla dichiarazione della classe e definisce quale sia il nostro ruolo nell'esistenza: ciò che *possiamo* fare, ciò che *non possiamo* fare e ciò che *dovremmo* fare.
L'altro livello è la nostra manifestazione reale, dovuta all'interazione dell'energia dell'Uno con gli spazioni.
Questo livello è assimilabile all'istanza di una classe, che mette in atto ciò che nella dichiarazione era solo potenziale: *the hearts that break, the mess we make*, come dice la canzone<!-- Audition (The Fools Who Dream)</i> - dal film: La La Land -->.  
La nostra entità ideale è unica e costante, mentre la nostra manifestazione fisica è mutevole: come sai, uno stesso oggetto può essere allocato in aree differenti di memoria, in successive esecuzioni di un programma, così come una stessa stampa può essere riprodotta su supporti diversi.
In questo ciclo di esistenza, il Maestro Canaro e il cane Lele sono stati un umano e un cane che correvano sulle colline intorno al lago di Bracciano, ma in altre esistenze potrebbero essere &mdash; o essere stati &mdash; altre persone e altri animali, in altri luoghi o addirittura in altri pianeti. 
Il nostro livello ideale, infatti, non stabilisce cosa dobbiamo essere, ma quale debba essere il nostro contributo all'economia dell'Universo; la forma che assumiamo o il luogo in cui ci manifestiamo sono del tutto incidentali. 
Per il C'hi++, come per l'Induismo<a href="/man/note#cogito" class="nota"></a>, la frase: “Cogito ergo sum” di Cartesio è insensata, perché ciò che cogita è l'istanza.
Ciò che siamo realmente, la nostra essenza, si manifesta in ciò che facciamo istintivamente.

<!--

@todo: aggiungere  le specifiche sulla visibilità delle classi 

@todo: aggiungere specifiche sull'ordine di inizalizzazione nel costruttore


-->
