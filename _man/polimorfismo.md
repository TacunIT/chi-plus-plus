---
class:      capitolo
layout:     manuale
og_desc:    "Una metafisica non metafisica - Bug noti delle religioni e degli esseri umani - Affinità fra il C'hi++ e le filosofie canoniche - Mappe topografiche e immagini da satellite - La Banda degli Onesti."
og_img:     "/assets/img/og-img/polimorfismo.jpg"
permalink:  /man/polimorfismo
quote:      "When Me they fly, I am the wings<br />I am the double and the int"
status:     pubblicato
title:      "Il polimorfismo"
---

Come avrai certamente intuito da tutto ciò che abbiamo detto finora, la caratteristica principale del C++ è il polimorfismo.  

Avevamo iniziato a parlarne durante la <a href="/man/c-plus-plus#polimorfismo" class="xref">lezione introduttiva sul C++</a> e l'avevamo illustrato con un esempio che, a questo punto, non dovrebbe più avere segreti, per te:

```
{% include_relative src/cplusplus-template.cpp %}
```

L'output di questo codice, nel caso l'avessi scordato, è:

```
> g++ src/cpp/cplusplus-template.cpp -o src/out/esempio
> src/out/esempio
DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Cavallo Razza:lipizzano Sesso:m
FEMMINA: Specie:Cavallo Razza:maremmano Sesso:f
ESITO:   puledro

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Asino   Razza:amiatino  Sesso:m
FEMMINA: Specie:Asino   Razza:sardo     Sesso:f
ESITO:   asino

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Asino   Razza:amiatino  Sesso:m
FEMMINA: Specie:Cavallo Razza:maremmano Sesso:f
ESITO:   mulo

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Cavallo Razza:lipizzano Sesso:m
FEMMINA: Specie:Asino   Razza:sardo     Sesso:f
ESITO:   bardotto
```

Prima di andare avanti, però, è necessario fare un po' di chiarezza su tre termini legati al polimorfismo: *overload*, *override* e *ridefinizione*.  
Con il termine: <b id="overload">overload</b> di una funzione si intende la una funzione che abbia lo stesso nome di un'altra, ma dei parametri differenti.
Un tipico esempio di *function overload* sono le differenti versioni del costruttore di una classe:

```
Cavallo() {}
Cavallo(const char* razza, const Sesso sesso )
: Animale(razza, sesso ) {
}
```
Le due funzioni hanno lo stesso nome e il compilatore sceglierà l'una o l'altra in base ai parametri che vengono utilizzati.  
Una funzione <b id="overridden">overridden</b> è una funzione che ha una definizione diversa da quella di una funzione virtuale di una sua classe-base:

```
const char* getSpecie() const {
    return "Asino";
}     
```

Come abbiamo visto, il compilatore sceglie l'una o l'altra in base al tipo di oggetto utilizzato per la chiamata.  
Se la funzione della classe base non fosse stata virtuale, questa sarebbe stata una semplice **ridefinizione**:

```
class Persona {
public:
    void getClass(){
        cout << "Persona" << endl;
    }
};
```

Quando gestisce queste funzioni, il compilatore non fa un controllo di tipo dinamico, basato sul tipo dell'oggetto al momento dell'esecuzione, ma sceglie la funzione da chiamare in base al tipo di puntatore o riferimento utilizzato, cosa che, come sai, può creare dei problemi:

```
Madre   * ptrM = new Madre;
Persona * ptrP = ptrM ;
ptrM->getClass() ;
ptrP->getClass() ;  // chiama la funzione di Persona - ERRORE
```

Alla luce di tutto ciò, possiamo correggere i commenti del codice di esempio:

```
/** Overload dell'operatore di output su stream  */
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}

/** Override della funzione virtuale pura */
const char* getSpecie() const {
    return "Cavallo";
}  

/** Override della funzione virtuale pura */
const char* getSpecie() const {
    return "Asino";
}     

/** Overload dell'operatore di output su stream */
friend ostream& operator << (ostream& os, const Monta& copula) {
    os << "DATA:    " << asctime(localtime(&copula._giorno))
       << "MASCHIO: " << *copula._maschio
       << "FEMMINA: " << *copula._femmina
       << "ESITO:   " << copula._esito
       << endl;
       return os;   
 };
```

<hr id="overload-operatori">

Nel C++, a ogni operatore corrisponde una funzione.
Quella dell’operatore binario `+=`, per esempio, è:

```
<tipo>& operator +=  (<tipo>& a, <tipo>& b) ;
```

laddove `a` e `b` sono i due oggetti che intervengono nell’operazione e `<tipo>` è il tipo delle variabili che intervengono nell'operazione.  

```
int&    operator +=  (int&    a, int&    b) ;
float&  operator +=  (float&  a, float&  b) ;
double& operator +=  (double& a, double& b) ;
```

Dato che gli operatori unari possono essere prefissi o postfissi, per consentire al compilatore di distinguere le funzione corretta da utilizzare, alla funzione dell'operatore postfisso si aggiunge un secondo parametro, non utilizzato:

```
void operator ++ (<tipo> a) ;           // versione prefissa
void operator ++ (<tipo> a, <tipo>) ;   // versione postfissa
```

Le funzioni degli operatori *overloaded* possono essere richiamate in maniera diretta.
Le due istruzioni qui sotto, una volta compilate, producono il medesimo codice e lo stesso risultato.
Se riesci a trovare una qualunque ragione per usare la prima sintassi piuttosto che la seconda, fallo pure:

```
a = b.operator + (c) ;  
a = b + c ;
```

Il comportamento degli operatori è predefinito per tutti i tipi standard e può essere ridefinito per gestire anche dei tipi di dato aggregati come le strutture o le classi.
La classe `string`, della libreria standard del C++, per esempio, ridefinisce, fra le altre cose, il comportamento degli operatori di assegnazione `+=` e `+` e dell'operatore di output su stream `<<` in modo che si possano compiere delle operazioni sulle stringhe con la stessa sintassi che si utilizza per altri tipi di dato:

```
{% include_relative src/polimorfismo-operatori.cpp %}
```

L'output di questo codice è ben noto:

```
> g++ src/cpp/polimorfismo-operatori.cpp -o src/out/esempio
> src/out/esempio                                          
PippoPluto
```

Lo stesso risultato si può ottenere anche con la funzione `append`:

```
string& append (const string& str)
```

ma utilizzare un operatore standard rende il codice più facile da leggere e da scrivere, se non altro perché non ti devi ricordare come si chiama la funzione per unire due stringhe.  
Gli unici operatori che non possono essere ridefiniti da una classe sono:

- l'operatore di selezione `.`;
- l'operatore di risoluzione di indirizzamento dei puntatori a membri della classe `.*`;
- l'operatore di risoluzione del campo d’azione `::`;
- l'operatore condizionale `? :`;
- i simboli `# ` e `##`, che vengono utilizzati dal preprocessore.

<hr id="operatori-classi">

Tranne alcune eccezioni che vedremo fra poco, tutti gli operatori del C++ possono essere ridefiniti o come funzione membro di una classe o come funzione globale:

```
{% include_relative src/polimorfismo-in-out.cpp %}
```

Quando si ridefinisce il comportamento di un operatore per una classe, bisogna tenere conto della visibilità dei dati membro che deve utilizzare.
Se l'operatore, com'è probabile, deve gestire dei dati privati o protetti, le possibilità sono due: o sfruttare le funzioni di interfaccia della classe o  dichiarare l'operatore `friend` della classe.
Nell'esempio iniziale sono applicate entrambe le possibilità: l'operatore di output su stream per la classe `Animale` utilizza le funzioni di interfaccia della classe:

```
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}
```

mentre l'operatore di output per la classe `Monta` è dichiarato come `friend` della classe e quindi può accedere direttamente ai dati membro dell'istanza:

```
friend ostream& operator << (ostream& os, const Monta& copula) {
    os << "DATA: "    << asctime(localtime(&copula._giorno))
       << "MASCHIO: " << *copula._maschio
       << "FEMMINA: " << *copula._femmina;
       return os;   
};
```

La scelta fra l'una o l'altra possibilità dipende dal tipo di programma che devi scrivere: se punti alla velocità, scegli la seconda, che è più diretta, altrimenti scegli la prima, che sarà probabilmente più lenta in esecuzione, ma non necessiterà di riscritture in caso di modifiche alla struttura della classe.
Non è possibile, però, ridefinire come funzione membro di una classe una funzione operatore che abbia come primo parametro una classe di cui non si ha il controllo (come, per esempio, la funzione operatore `<<`  che ha come primo parametro un riferimento a `ostream`) perché nella funzione membro questo parametro sarebbe sostituito dal parametro implicito `this`, che ha un altro tipo di dato, causando un errore di compilazione.  
Gli operatori `=`, `()`, `[]` e `->` non possono essere ridefiniti come funzioni globali, ma devono sempre essere implementati come funzione membro non statica di una classe
Le altre regole da ricordare, in questi casi, sono:

- l’operatore unario di assegnamento `=` è l’unico caso di funzione membro che non viene eredi­tata da eventuali classi figlie; se non viene ridefinito, prevede l’assegnamento membro a membro degli attributi e ha la sintassi:

    ```
    C& C::operator = (const C& origine) ;
    ```

- l’operatore binario `[]` permette di implementare vettori di tipo particolare, mantenendo una sintassi standard e ha la forma:

    ```
    c.operator [] (n) ;
    ```

    dove `c` è un oggetto di classe `C` e l’indice n può essere un qualsiasi tipo di dato ;

- per ridefinire l’operatore binario di chiamata a funzione `()`, va utilizzata la sintassi:

    ```
    c.operator()(p) ;
    ```

    dove `c` è sempre un oggetto di classe `C` e `p` è un elenco anche vuoto, di parametri;

- l’operatore unario di accesso ai membri della classe `->` viene interpre­tato come:

    ```
    (C.operator -> ())->m ;
    ```

    e ritorna o un oggetto o un puntatore a un oggetto di classe `C`.


Ridefinire gli operatori `new` e `delete`, il cui comportamento è strettamente le­gato all’hardware, potrebbe non essere una scelta astuta dal punto di vista della port­abilità del codice; detto ciò, se una classe ha bisogno di gestire la memoria in modo particolare, lo può fare, ma deve rispettare due regole:

- l’operatore `new` deve avere il primo argomento di tipo `size_t` e resti­tuire un puntatore a `void`;
- l’operatore `delete` deve essere una funzione di tipo `void` che abbia un primo argomento di tipo `void*` e un secondo argomento, facoltativo, di tipo `size_t`.

<hr id="cast">

<!-- @todo: verificare queste affermazioni per il post-C++11 -->
In C, per trasformare un `int` in un `double` si utilizzano gli operatori di cast:

```
long int i = 5 ;
double d = (double) i ;
```

Il C++ accetta questa sintassi, così come accetta che si usi `malloc` al posto di `new`, ma la sua sintassi standard, che ricorda vagamente i costruttori delle classi, prevede che il dato da convertire sia passato come parametro a una funzione con lo stesso nome del tipo in cui si vuole che avvenga la conversione :

```
long int i = 5 ;
double d = double(i) ;
```

Il compilatore del C++ ha la possibilità di convertire un qualunque tipo di dato primitivo in un altro, ma non può sapere come comportarsi con i tipi di dato definiti dall’utente; dobbiamo quindi istruirlo, così come abbiamo fatto con i costruttori e gli operatori, definendo dei cam­mini di coercizione dai tipi di dato primitivi e viceversa.
Il primo caso, ovvero la trasformazione dal tipo primitivo a quello definito dall’utente, è il più semplice: di fatto si tratta di definire, laddove non ci sia già, un cos­truttore per la nuova classe che richieda dei parametri di tipo primitivo.
Quando invece non esiste un costruttore da estendere, ovvero quando la coercizione è dal tipo definito dall’utente a un tipo di dato primitivo o fornito in una libreria di cui non si possiede il codice sorgente, è necessario ridefinire l’operatore di conversione `()`.  
Immagina di aver creato un nuovo tipo di dato `Frazione` per la gestione dei numeri razionali.
Per poterlo utilizzare in espressioni contenenti dati di tipo primi­tivo dovresti ridefinire ciascun operatore per fargli accettare dei dati di tipo misto, sia come primo che come secondo parametro:

```
Frazione operator + (int i, Frazione f) :
Frazione operator - (int i, Frazione f) :
Frazione operator + (double i, Frazione f) :
Frazione operator - (double i, Frazione f) :
...
Frazione operator + (Frazione f, int i) :
Frazione operator - (Frazione f, int i) :
Frazione operator + (Frazione f, double i) :
Frazione operator - (Frazione f, double i) :

```

Puoi risparmiarti questa seccatura ridefinendo solo il com­portamento degli operatori per la nuova classe e fornendo al compilatore dei cammini di conversione dai tipi primitivi al nuovo tipo di dato, in modo che possa trasformare i dati nel tipo appropriato, nel caso di espressioni miste:

```
{% include_relative src/polimorfismo-cast.cpp %}
```

<hr id="template">

L'ultima cosa di cui ti devo parlare, a proposito del polimorfismo, sono i *template*.  
I template, nel C++, sono dei modelli che si utilizzano per definire delle funzioni o delle classi polivalenti.
Se uno stesso compito può essere eseguito in maniera simile su parametri di tipo differente, invece di scrivere delle funzioni o delle classi identiche per ciascun tipo di parametro, si può scrivere una funzione o una classe template e richiamarla ogni volta con il tipo di parametro appropriato:

```
int    somma(int    a, int    b) { return a + b; }
float  somma(float  a, float  b) { return a + b; }
double somma(double a, double b) { return a + b; }

template <class T>
somma(T a, T b) { return a + b; }
```

Quando il compilatore trova nel codice un template, sia esso la dichiarazione di una classe o una chiamata a funzione, la sostituisce con il codice corrispondente, così come avviene per le <a href="/man/preprocessore#macro" class="xref">macro-istruzioni del precompilatore</a>, ma, a differenza di quello che avviene per le macro, il tipo dei parametri del template è sottoposto a uno stretto controllo, così come il resto del codice.  
Il formato per la dichiarazione di una <i id="funzioni-template">funzione template</i> è:

<p class="code">
<b>template <class</b> <i>identificatore</i><b>></b> <i>dichiarazione</i>;
<br />  
<b>template <typename</b> <i>identificatore</i><b>></b> <i>dichiarazione</i>;
</p>

Non c'è nessuna differenza fra la prima e la seconda forma: sia `class` che `typename` producono lo stesso effetto.  
*identificatore* è un simbolo che identifica un determinato tipo di dato o una classe definita dall'utente.
Per esempio, la sintassi di una funzione template che torna il maggiore di due parametri sarà qualcosa di simile:

```
template<class T>
T maggiore (T x, T y) {
    return (x > y) ? x : y;
}
```

In questo caso, l'identificativo del tipo è la lettera `T` che compare sia fra gli apici nella prima riga che fra parentesi nella seconda, ma può essere qualsiasi stringa.
I parametri possono essere più di uno:

```
template<class C1, class C2>
T funz (C1 x, C2 y) {
...
}
```

e possono avere un valore di default:

```
template<class N = int>
T funz (N n) {
...
}
```

La chiamata delle funzioni template è simile a quella delle funzioni ordinarie, con l'aggiunta del tipo dei parametri che devono essere gestiti:

```
cout << maggiore<int>   (  9,  12) << endl;    
cout << maggiore<double>(0.4, 1.2) << endl;    
cout << maggiore<char>  ('a', 'z') << endl;    
```
<!-- @todo: verificare i casi in cui non c'è specifica del tipo di dato -->
Il prossimo esempio mostra la differenza fra una macro del precompilatore e una funzione template:
<!-- NOTA: se si cambia o si rimuove la macro nel codice, va aggiornato il testo del capitolo sul preprocessore -->
```
{% include_relative src/polimorfismo-macro-template.cpp %}
```

La macro `MAGGIORE` e la funzione template `maggiore` eseguono la stessa operazione: confrontano i due parametri che hanno ricevuto in input e tornano il maggiore dei due.
La grossa differenza fra questi due approcci<!-- ce ne sono anche altre, ma sono legate al tipo di compilatore e preferisco tralasciarle --> è che, mentre il tipo dei parametri del template è verificato dal compilatore, la macro è una banale sostituzione che non fa alcun controllo sulle variabili che utilizza.
L'istruzione:

```
cout << MAGGIORE('a', b) << endl;
```

compara un carattere con un double e, senza dare problemi in compilazione torna il valore `97`, corrispondente al codice ASCII della lettera `a`.
Al contrario, l'istruzione:

```
int   a = 10;
short b = 0;
cout << maggiore(a, b) << endl;  
```

<!-- @todo: correggere questo codice, sia qui che nello script: l'errore si manifesta solo se si omette lo specificatore del tipo per il template -->
causa un errore di compilazione perché i due parametri sono di tipo differente:

```
> g++ src/cpp/polimorfismo-template.cpp -o src/out/esempio
src/cpp/polimorfismo-template.cpp:52:13:
    error: no matching function for call to 'maggiore'
    cout << maggiore(a, b) << endl;    
            ^~~~~~~~
src/cpp/polimorfismo-template.cpp:22:3:
    note: candidate template ignored:
        deduced conflicting types for parameter 'T'
      ('int' vs. 'short')
T maggiore (T x, T y) {
  ^
```

La dichiarazione di una <i id="classi-template">classe template</i> ha la forma:

<p class="code">
<b>template <class</b> <i>identificatore</i><b>></b> <i>dichiarazione</i>;
</p>

La lista dei parametri fra i simboli `<>` può contenere uno o più simboli per i tipi dato gestiti dalla classe.
L'utilizzo di queste classi è simile a quello delle funzioni template:

```
{% include_relative src/polimorfismo-classe-template.cpp %}
```

<hr id="stl">

Il codice che ti ho mostrato all'inizio di questa lezione utilizza una classe template:

```
list<Monta> monte;
```

La classe `list` è una delle classi della *Standard Template Library* del C++, una libreria di classi e di funzioni che permettono di risolvere dei problemi comuni della programmazione, come la memorizzazione, l'ordinamento o la ricerca di una serie di dati.
Le componenti della STL è sono:

- una libreria di **container** che permettono di immagazzinare oggetti e dati;
- degli **iteratori** che consentono di scorrere il contenuto dei container;
- una collezione di **algoritmi** che permettono di eseguire delle operazioni di ordinamento e ricerca su insiemi di dati;
- degli oggetti-funzioni, o: **functors**, che incapsulano una specifica funzione.

La classe `list` è un esempio di container e rappresenta un elenco di elementi memorizzati in aree non contigue della memoria.
Al contrario, la classe `vector` implementa un elenco di elementi memorizzati in un'unica area di memoria, così come avviene per gli array del C.  
Tutti i vettori della STL posseggono delle funzioni membro che consentono di gestirne gli elementi; la funzione `push_back`, per esempio, aggiunge un elemento in coda alla lista:

```
monte.push_back(Monta(cavallo, giumenta));
monte.push_back(Monta (asino, asina));       
monte.push_back(Monta (asino, giumenta));     
monte.push_back(Monta (cavallo, asina));
```

Gli <i id="iteratori-stl">iteratori</i> sono dei costrutti che permettono di scorrere il contenuto di un container, individuandone gli elementi.
Ne abbiamo utilizzato uno nell'istruzione:

```
list<Monta>::iterator it;
for (it=monte.begin(); it!=monte.end(); it++) {
    cout << *it << endl;
}
```

La prima istruzione del ciclo `for` assegna all'iteratore `it` il primo elemento della lista, tornato dalla funzione membro `monte.begin`.
La seconda istruzione, verifica che l'iteratore sia differente da `monte.end`, che punta alla fine della lista.
La terza istruzione incrementa l'iteratore di una posizione e dimostra come la ridefinizione di un operatore per una classe renda il codice più facile da leggere: anche se tu non hai mai visto una classe template, capisci subito che quella istruzione incrementa il valore di `it` di un'unità.  
Gli <i id="algoritmi-stl">algoritmi</i> della STL, definiti nell'header `<algorithm>` sono funzioni template che permettono di individuare, copiare, ordinare, unire o eliminare i dati all'interno di un container.


```
{% include_relative src/polimorfismo-algoritmi.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/polimorfismo-algoritmi.cpp -o src/out/esempio
> src/out/esempio                                          
10
70
10 70 21 49 35
10 21 35 49 70
70 49 35 21 10
```

Le function-class o: <i id="functors-stl">functors</i> sono delle classi che ridefiniscono il comportamento dell'operatore `()` e che possono quindi agire come se fossero delle funzioni:

```
{% include_relative src/polimorfismo-functor-stl.cpp %}
```
Utilizzati così, i *functor* hanno poco senso, ma possono essere (e sono) molto utili quando si utilizzano quelle funzioni della STl che elaborano tutti gli elementi di un container, come per esempio la funzione `transform`:

```
{% include_relative src/polimorfismo-rot13.cpp %}
```
Se compili ed esegui questo programma, otterrai :

```
> g++ src/cpp/polimorfismo-rot13.cpp -o src/out/esempio     
> ./src/out/esempio
CvccbCyhgb
PippoPluto
```

Le funzioni ordinarie ti permettono di sfruttare l'algoritmo `transform` per cifrare un testo con un valore fisso, ma non puoi fare la stessa cosa utilizzando una chiave variabile, perché il quarto parametro non accetta funzioni con più di un parametro.
Se provassi a utilizzarlo con qualcosa come:

```
unsigned char cifra(unsigned char c, int chiave)
{
    return c + chiave;
}
```

otterresti l'errore:

```
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/algorithm:1855:34: error: too few arguments to
      function call, expected 2, have 1
        *__result = __op(*__first);
                    ~~~~         ^
src/cpp/polimorfismo-transform-chiave.cpp:25:5: note: in instantiation of function template specialization
      'std::__1::transform<std::__1::__wrap_iter<char *>, std::__1::__wrap_iter<char *>, unsigned char
      (*)(unsigned char, int)>' requested here
    transform(
    ^
```

È in questi casi che tornano utili i *functor*, perché possono essere inizializzati con uno o più valori specifici e poi essere utilizzati come funzioni unarie:

```
{% include_relative src/polimorfismo-functor.cpp %}
```

Compilando ed eseguendo questo programma, ottieni :

```
> g++ src/cpp/polimorfismo-functor.cpp -o src/out/esempio
> ./src/out/esempio
QjqqpQmvup
```
che corrisponde ai caratteri della stringa *PippoPluto* incrementati di un'unità.

<hr id="dottrina">

Da migliaia di anni, gli uomini cercano di capire quale sia il significato dell'Esistenza.  
Le risposte che si sono dati variano a seconda del periodo storico e del territorio in cui il profeta o il filosofo ha vissuto, ma hanno tutte una particolarità: richiedono ai loro seguaci l'accettazione di postulati non dimostrabili, come l'esistenza di una o più divinità o di stati di esistenza diversi da quello che conosciamo.
Anche la Scienza ha provato a dare delle risposte agli stessi interrogativi, ma la sua indagine si è limitata agli aspetti pratici del problema: ha prodotto delle interessanti teorie sulla genesi dell'Universo e sugli eventi che hanno portato alla nostra esistenza, ma non si è mai pronunciata su quello che potrebbe essere il nostro ruolo in tutto ciò, con le conseguenze di cui abbiamo parlato durante <a href="/man/memoria#delete" class="xref">la lezione sulla memoria</a>.  
Il Maestro Canaro, che non riusciva ad accettare né i dogmi delle religioni tradizionali né lo scollamento fra uomo e Universo prodotto dalle ipotesi scientifiche, si pose una domanda:

> È possibile dare una spiegazione dell’Esistenza sfruttando solo ciò di cui abbiamo esperienza diretta?

La maggior parte delle religioni, per “funzionare”, richiede da una a tre dimensioni aggiuntive, oltre quelle note; la Scienza, per le sue *super-stringhe* ha bisogno almeno di sette dimensioni aggiuntive, ovvero il doppio di quelle che servono per un Aldilà non spirituale.
Esiste una spiegazione più semplice?  
Non essendo né un filosofo né un mistico, approcciò lo sviluppo della sua dottrina come se fosse stata un sistema software.
Per prima cosa fece un'analisi del "sistema in esercizio", evidenziandone i principali difetti; poi identificò delle vulnerabilità logiche delle religioni canoniche e definì delle linee-guida atte a prevenirle; infine, descrisse le caratteristiche del C'hi++, spiegando come queste avrebbero potuto risolvere alcuni dei problemi evidenziati in precedenza.
Come scrisse nella <a href="/proposta#errori" class="xref">Proposta</a>, ci sono dei “bug” che possiamo considerare comuni a tutte le metafisiche:

> {{ site.data.canaro.errori-religioni }}

ed altri, che possiamo considerare comuni agli esseri umani:

> {{ site.data.canaro.errori-umani }}

Per correggere o quanto meno mitigare questi problemi, la sua metafisica avrebbe dovuto:

> {{ site.data.canaro.chi-requisiti }}

Il Maestro Canaro applicò allo sviluppo della sua *metafisica-non-metafisica* lo stesso approccio che adottava quando doveva realizzare un software.
Ci sono due modi diversi di progettare un software: il primo consiste nell'analizzare tutti i sistemi che svolgono azioni simili, prendere il meglio di ciascuno e metterlo nel nuovo sistema; in alternativa, si può progettare il sistema da zero e solo quando se ne è definita per grandi linee la struttura, studiare le soluzioni adottate dagli altri, integrandole nel proprio programma se lo si ritiene utile.
Il primo approccio è più rapido e sicuro, ma tende a produrre risultati ripetitivi; il secondo approccio è più complesso, sia in termini di analisi che di implementazione, ma facilita l'innovazione perché l'immaginazione dell'analista non è condizionata da ciò che ha visto.  
Essendo un sostenitore del secondo metodo, il Maestro Canaro lo applicò anche al C'hi++ e, dopo alcuni di anni di studio, arrivò alla conclusione che non solo è possibile ipotizzare una cosmogonia quasi del tutto priva di elementi metafisici (non del tutto priva, perché, come vedremo <a href="/man/stream#dottrina" class="xref">in seguito</a>, una dose minima di trascendenza è necessaria per garantire la buona funzionalità della dottrina), ma che i precetti di questa dottrina erano compatibili con molti  principii delle religioni canoniche.  

<hr id="portabilita">

Il C'hi++ ereditò alcuni concetti proprii delle filosofie note al Maestro Canaro, come il dualismo Gravità/Elettricità elaborato da Poe in *Eureka*, che lo aveva affascinato per il modo in cui trasformava una forza cieca e inspiegabile come la Gravità nell'intenzione, cosciente, di tutto ciò che esiste di tornare a essere Uno.
D'altro canto, la dottrina del Maestro Canaro rinnegò alcuni concetti comuni a molte religioni, come la possibilità di sottrarsi al ciclo delle rinascite o la presenza di punizioni o premii *ad-personam*.  
Così come quando si analizza il funzionamento di un software non ci si cura delle singole variabili, ma si pensa al flusso complessivo del sistema, così il C'hi++ vede l'esistenza non in termini di interazioni fra individui, ma come l'evoluzione del flusso dell'Energia dell'Uno all'interno della matrice tridimensionale degli spazioni.
Per il C'hi++ non esistono né anime, né fiumi infernali e chi muore in mare non troverà ad accoglierlo Rán, nella sua birreria in fondo al mare, ma verrà semplicemente riciclato, come le aree di memoria RAM all'interno di un computer.  
Le nostre esistenze sono incidentali; pensare di punirle o di premiarle non avrebbe senso e contrasterebbe con il principio generale che tutto ciò che esiste è la manifestazione di un'unica Entità.
Come ti ho detto all'inizio di queste lezioni, non è possibile andare in Paradiso o all'Inferno da soli: qualunque cosa avvenga nell'Universo, ci riguarda tutti.  
Questo però non vuol dire che il C'hi++ rifiuti tutti concetti delle religioni che lo hanno preceduto; anzi.
Molti precetti del C'hi++ sono compatibili con precetti o idee appartenenti ad altre mistiche o filosofie e si tratta spesso di filosofie che il Maestro Canaro non conosceva, quando pose la basi della sua dottrina.
<!--
@todo: valutare se inserire questo brano; al momento, non mi convince.
Per esempio, il Maestro Canaro non lesse mai (con suo grande rammarico) la *Divina Commedia*; ciò non ostante, il C'hi++ ha un punto di contatto con la visione dantesca dell'Aldilà come conseguenza del pentimento.
Dante mette in Purgatorio i peccatori che hanno capito di aver sbagliato, mentre condanna all'Inferno quelli che, malgrado tutto, non riescono a prendere coscienza delle proprie colpe.
Come abbiamo detto <a href="/man/istruzioni-condizionali#pentimento" class="xref">in precedenza</a> e come vedremo durante la lezione sul <a href="/man/debug#pentimento" class="xref">debug</a>, il C'hi++ concorda con questa idea.  
Similmente, ci
-->
Per esempio, ci sono diverse affinità fra il C'hi++ e la *Bhagavad-Gita*, anche se il Maestro Canaro la lesse mentre stava redigendo la *Proposta*, quando i punti nodali del suo Credo erano già stati definiti da una decina d'anni.
Oltre alla citazione che ti ho fatto parlando del <a href="/man/programmatore#azione" class="xref">programmatore</a>, nella *Gita* è possibie trovare alcuni brani che ricordano molto le affermazioni contenute in *Sostiene Aristotele*; per esempio, quelle sulla natura dell'Universo:

> {{ site.data.citazioni.gita.caos }}
> {{ site.data.citazioni.gita.cicli }}

O sul dualismo Gravità/Entropia :

> {{ site.data.citazioni.gita.dualismo }}

O su quelli che lui definiva: i *Post-It*:

> {{ site.data.citazioni.gita.vasana }}

Puoi trovare delle analogie con i precetti del C'hi++ anche nel *Mantiq al-Tayr*:

> {{ site.data.citazioni.mantiq.tutto }}

o anche:

> {{ site.data.citazioni.mantiq.male }}

Per certi versi anche la stessa Genesi biblica può essere considerata un'allegoria della cosmogonia spazionista: il Paradiso è l'Uno primigenio, mentre Adamo (*Puruṣa*) ed Eva (*Prakṛti*) sono l'Ente che ne causa la disgregazione, generando un Universo dove si partorisce nel dolore e dove ci si deve guadagnare il pane con il sudore della fronte.  
Il Maestro Canaro pensava che tutto questo fosse normale.
Come scrisse nel <a href="{{ site.url_github }}/blob/master/MANIFEST.md" target="github">MANIFEST</a> GitHub del C'hi++:  

> {{ site.data.canaro.metafisiche }}

In una nota della mappa mentale su cui basò lo sviluppo iniziale della dottrina, aggiunse:

> {{ site.data.canaro.religioni-oo }}

Solo alcuni anni dopo, annotò questa frase in un libro di Guenon:

> {{ site.data.citazioni.guenon.spirito }}<a class="nota" href="/man/note#guenon-spirito" id="guenon-spirito"></a>

<hr id="igm">

Fra il C'hi++ e le religioni canoniche c'è la stessa differenza che passa fra una mappa topografica e un'immagine da satellite.  
Quel senza Dio di Dawkins, ha detto che:

> {{ site.data.citazioni.dawkins.analogia }}<a class="nota" href="/man/note#dawkins-analogia" id="dawkins-analogia"></a>

Una frase curiosa, da parte di un esponente di una setta che cerca di descrivere tutto ciò che esiste con analogie matematiche e nega l'esistenza di ciò che non riesce a convertire..  
Entusiasmi a parte, le mappe e le immagini da satellite hanno diverse analogie con le discipline metafisiche.
Anche le mappe e le immagini, come la metafisica, sono costrette a rappresentare il loro soggetto a un rapporto di scala ridotto e con due sole dimensioni in vece di tre (o di quattro se, oltre alla profondità, vuoi considerare anche il tempo).
Anche le mappe e le immagini, per questo motivo, devono rappresentare il loro soggetto per mezzo di analogie: le carte topografiche usano delle linee altimetriche e dei simboli; le immagini satellitari usano dei pixel o dei piccoli punti di colore.
In nessuno dei due casi ciò che noi vediamo è davvero ciò che rappresenta; è il nostro cervello che decide di crederlo tale: nel caso della carta topografica, perché la legenda ci permette di definire una correlazione fra significato e significante; nel caso dell'immagine, perché il nostro occhio riconosce in quelle combinazioni di pixel o di punti di colore degli alberi, il mare o delle case.  
Un'altra analogia, conseguenza dei due punti precedenti, è che è sbagliato confondere i simboli con ciò che rappresentano: i quadratini scuri delle mappe *non* sono case; i punti colorati delle immagini *non* sono un bosco.
Mappe e immagini hanno senso solo a un certo livello di lettura; se lo oltrepassiamo, se cerchiamo di ottenere più informazioni o verosimiglianza avvicinando lo sguardo, otteniamo l'effetto opposto, perché i simboli si rivelano per quello che sono: punti colorati o linee su un foglio.
Questo però non vuol dire che ciò che rappresentano sia falso, ma che noi non stiamo guardando con *il giusto paio di occhi*, come direbbe Hunter Thompson.  
Il Maestro Canaro pensava che fosse per questo motivo che alcune religioni sono contrarie alla rappresentazione diretta della Divinità: perché è facile che poi si confonda il simbolo con ciò che rappresenta.
<!--
Agli Ebrei è vietato dal secondo Comandamento e anche i Cristiani si attennero a questa regola fino al Concilio di Nicea del 787.
@todo: verificare regole simili per l'Islam.
-->
Tornando al paragone iniziale, le religioni tradizionali sono delle immagini da satellite, mentre il C'hi++ è una mappa topografica.  
Mentre i Credi religiosi riescono a riprodurre &mdash; nei limiti imposti dalla nostra condizione &mdash; tutta la bellezza del Creato, il C'hi++ si limita a darne una descrizione schematica, più povera di contenuti e di poesia, ma più facile da accettare per chi non abbia la benedizione della Fede.
Un'immagine da satellite ha un valore contemplativo: è bella da guardare sullo schermo del tuo computer o anche da appendere al muro, come un quadro, ma
se ti sei perso in un bosco o in mezzo ai monti, una mappa topografica, proprio in virtù della sua schematicità, ti permetterà più facilmente di ritrovare la strada di casa.  
Il C'hi++ non cerca di rubare fedeli alle religioni canoniche.
Non avrebbe senso: sarebbe come cercare di convincere chi sia già sposato con l'amore della sua vita a fare un matrimonio di interesse: se tu hai la Fede non hai bisogno di conferme razionali; possono compiacerti, ma non ti sono necessarie.
Il C'hi++, però, può dare forza a quelle (tante) persone che *ancora credono in tutto ciò in cui più nessuno crede*, come li descrisse Longanesi; quella *Banda degli Onesti*<a class="nota" href="/man/note#banda-onesti" id="banda-onesti"></a> che tutti i giorni fa il proprio dovere al meglio possibile anche se non gli conviene, anche tutto e tutti intorno a loro sembrano spingerli all'egoismo e all'indifferenza.
Può aiutarli a non arrendersi e può insegnare loro che non è importante vincere le partite, ma giocare sempre meglio.
Riconoscere gli sbagli che si sono fatti, imparare da essi e cercare di non ripeterli più, partita dopo partita, in una ricerca continua del meglio.
Se si comporteranno così, qualunque sarà il loro lavoro, fosse anche pulire i cessi, sarà comunque Arte.

<!--

Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Riprendere la genealogia di classi dell'esempio classi-dio.cpp ed esaminare la funzione virtuale pura `isGood` nelle sue variazioni: nel caso della classe `Mare`, il risultato è già definito perché lo ha determinato Dio; per le altre classi, non è altrettanto certo.
Ogni categoria ha una sua implementazione di questa funzione, uno specifico criterio di riscontro per determinare ciò che debba essere considerato ben fatto.
Per alcuni è il pubblico: il droghiere ti chiede di assaggiare le olive, lo scrittore ti fa leggere ciò che ha scritto, l'attore aspetta la risata o l'applauso alla fine della scena.

@todo: trovare il riferimento bibliografico per il prossimo paragrafo; so che esiste, ma non mi ricordo quale fosse - Le religioni nate in zone temperate, con abbondanza di acqua e di cibo, hanno un pantheon di divinità più o meno benevole, mentre quelle nate in zone aspre hanno un numero ristretto di Dei, più severi.

La specializzazione come un male.
"La specializzazione va bene per gli insetti" (dove l'ho letto?)
Un tempo, l'uomo virtuoso sapeva fare molte cose, più o meno bene.
Ora se ne sa fare solo una, benissimo.
Si cerca l'eccesso, il continuo superamento del limite.

parlare degli operatori di cast:
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)

-->
