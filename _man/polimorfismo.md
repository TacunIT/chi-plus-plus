---
status:     redazione
layout:     manuale
class:      capitolo
title:      Il polimorfismo
permalink:  /man/polimorfismo
quote:      "Non puoi immergere i tuoi byte due volte nello stesso stream"
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

<!-- @todo: aggiungere commenti -->
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

<!--
Le function-class o: <i id="functors-stl">functors</i>, meritano un discorso a parte..

@todo: usare l'esempio dei cavalli per illustrare array e iteratori, poi fare un esempio di functor

Ne abbiamo già visto un <a href="/man/c-plus-plus#polimorfismo" class="xref">esempio</a> quando abbiamo detto che sarebbe stato possibile invertire l'ordine della lista delle monte con l'istruzione:

```
monte.reverse();
```

-->

<hr id="dottrina">

Fra il C'hi++ e le religioni canoniche c'è la stessa differenza che passa fra una mappa topografica e un'immagine da satellite.  
Quel senza Dio di Dawkins, ha detto che: 

> {{ site.data.citazioni.dawkins.analogia }}

Una frase curiosa, da parte di un esponente di una setta che cerca di descrivere tutto ciò che esiste con analogie matematiche e nega l'esistenza di ciò che non riesce a convertire..  
Entusiasmi a parte, le mappe e le immagini da satellite hanno diverse analogie con le discipline metafisiche.
Anche le mappe e le immagini, come la metafisica, sono costrette a rappresentare il loro soggetto a un rapporto di scala ridotto e con due sole dimensioni in vece di tre (o di quattro se, oltre alla profondità, vuoi considerare anche il tempo).
Anche le mappe e le immagini, per questo motivo, devono rappresentare il loro soggetto per mezzo di analogie: le carte topografiche usano delle linee altimetriche e dei simboli; le immagini satellitari usano dei pixel o dei piccoli punti di colore.
In nessuno dei due casi ciò che noi vediamo è davvero ciò che rappresenta; è il nostro cervello che decide di crederlo tale: nel caso della carta topografica, perché la legenda ci permette di definire una correlazione fra significato e significante; nel caso dell'immagine, perché il nostro occhio riconosce in quelle combinazioni di pixel o di punti di colore degli alberi, mare o case.  
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
Il C'hi++, però, può dare forza a quelle (tante) persone che *ancora credono in tutto ciò in cui più nessuno crede*, come li descrisse Longanesi; quella *Banda degli Onesti*<a href="/man/note#banda-onesti" class="nota"></a> che tutti i giorni fa il proprio dovere al meglio possibile anche se non gli conviene, anche tutto e tutti intorno a loro sembrano spingerli all'egoismo e all'indifferenza.


<!--

Può aiutarli a non arrendersi e può insegnare loro che non è importante vincere le partite, ma giocare sempre meglio.
Riconoscere gli sbagli che si sono fatti, imparare da essi e cercare di non ripeterli più, partita dopo partita, in una ricerca continua del meglio.
Se si comporteranno così, qualunque sarà il loro lavoro, fosse anche pulire i cessi, sarà comunque Arte.

Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Riprendere la genealogia di classi del capitolo precedente ed esaminare la funzione virtuale pura `isGood` nelle sue variazioni: nel caso della classe `Mare`, il risultato è già definito perché lo ha determinato Dio; per le altre classi, non è altrettanto certo.
Ogni categoria ha una sua implementazione di questa funzione, uno specifico criterio di riscontro per determinare ciò che debba essere considerato ben fatto. 
Per alcuni è il pubblico: il droghiere ti chiede di assaggiare le olive, lo scrittore ti fa leggere ciò che ha scritto, l'attore aspetta la risata o l'applauso alla fine della scena.
Per i filosofi è `true` tutto ciò che può essere descritto con le parole; per gli scienziati, tutto ciò che può essere descritto dalla matematica; per gli informatici è `true` tutto quello che può essere descritto dal codice. 

v. Kant citato da Hertha von Dechend nella prefazione tedesca a Il Mulino di Amleto

Le diverse religioni, possono essere delle forme derivate di una stessa mistica iniziale?
Esistono dei "dati membro" e delle funzioni comuni, che siano state ridefinite con il passare del tempo, ma che facciano capo a un corpo di credenze (o di nozioni) iniziale?
Anche solo in questa mappa, se ne trovano diverse (p.es. Empedocle -&gt; Poe).
Così come le classi di un lunguaggio OO sono ridefinite per adattarsi a uno specifico contesto di utilizzo, così pure la Mistica iniziale potrebbe essere stata "overloaded" per adattarsi a uno specifico luogo o tempo.
Se fosse così, tanto più si va indietro nel tempo, e quindi nella gerarchia di classi, tanto più ci si dovrebbe avvicinare alle caratteristiche proprie della Mistica.
E' possibile definire una gerarchia di classi figlie della classe astratta "credo"?(semplificando molto, visto che sono le 3 di notte) Budda e Zoroastro influenzano i greci, che influenzano gli ebrei, che a loro volta infulenzano i cristiani, che alla fine producono i Testimoni di Geova...
Allo stesso modo (sempre semplificando), dal C si è evoluto il C++ e dal C++, Java.Sfortunatamente, però, i (cattivi) programmatori Java hanno fatto alla programmazione quello che i cattolici hanno fatto al cristianesimo.
V. Corano

Quando il programmatore definisce un nuovo tipo di dato per mezzo di una o più classi, può allo stesso tempo istruire le funzioni e gli operatori del linguaggio ad utilizzarlo correttamente.

Noi viviamo prevalentemente sulla terraferma e riteniamo perciò che la normalità sia questa. Se però si trascorre un lungo periodo di tempo su una nave o in un'isola, si ha modo di capire come la normalità sia l'acqua e la terra sia solo un'eccezione.
Similmente, noi diamo grande importanza al ciclo di nascita, riproduzione e morte che chiamiamo "vita" e in essa vediamo il fine ultimo dell'Universo, dimenticandoci che la vita è solo un caso particolare di esistenza e che un universo di sassi sarebbe comunque prodigioso.
Ciascuna forma di vita consociata, per poter sopravvivere, richiede la legittimazione di alcune follie biologiche.
Il rispetto di queste follie, essendo in-naturale, richiede l'istituzione di un livello superiore di costrizione, ovvero un corpo di regole formali ancora più distante del precedente dal comportamento biologico degli esseri viventi.
Con il passare del tempo, molte di queste convenzioni nate in seguito a esigenze contingenti, finiscono inevitabilmente per contrastare con il senso comune di giustizia e devono essere o abolite o modificate, solo che ciascuna modifica o adattamento invece di renderle più "giuste", le allontana ulteriormente dal loro scòpo iniziale e le rende soggette a interpretazioni errate o addirittura opposte a quelle che era il loro fine primario.
Sant'Agostino ha detto la stessa cosa, ma molto meglio di quanto stia facendo io adesso.
Si vede che era sobrio.

La specializzazione come un male.

"La specializzazione va bene per gli insetti" (dove l'ho letto?)

Un tempo, l'uomo virtuoso sapeva fare molte cose, più o meno bene.
Ora se ne sa fare solo una, benissimo.
Si cerca l'eccesso, il continuo superamento del limite.

Lo sport (citare Arlìa?), da attività formativa è diventato una forma di intrattenimento e, come tale, deve essere sempre più spettacolare.
Lo sportivo è visto come un costoso strumento usa e getta.

È però importante che il polimorfismo non dia luogo ad anfibologie.
Non ti dirò cosa vuol dire, cercalo sul vocabolario come ho fatto io.

parlare degli operatori di cast 
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)

@todo: verificare
Se eliminassimo le parentesi nell'istruzione di output finale:

```
cout << (a + b + a) << endl;
```

otterremmo un errore di compilazione, perché non esiste un operatore `+` capace di gestire la somma di un `int` (il tipo tornato dalla somma di `a + b`) con un oggetto di classe `A`.

```
{% include_relative src/polimorfismo-operatore-simmetrico.cpp %}
```


-->
