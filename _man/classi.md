---
status:     redazione
layout:     manuale
class:      capitolo
title:      Le classi
permalink:  /man/classi
quote:      "Ceci n'est pas une |"
---

<!-- Quando ho cominciato a scrivere questo capitolo, si è rotto il tasto "o" del mio Mac. È Domenica e siamo in clausura da COVID, quindi non posso andare in un centro commerciale a comprarne una esterna, temporanea. Perdonate eventuali refusi -->
La possibilità di definire nuovi tipi di dato grazie alle classi è la caratteristica principale del C++.

I linguaggi di programmazione “tradizionali”, come il Cobol il Fortran o il Pascal, hanno un insieme limitato di tipi di dato: interi, numeri in virgola mobile, booleani, caratteri e stringhe.. giusto quello che serve a gestire una scheda anagrafica o un conto in banca.
Il C e il Pascal hanno anche la possibilità di accorpare questi tipi di dato in strutture, enumerati o array, ma questi tipi di dato sono solo dei contenitori privi di logica interna.
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
Se un giorno decidessimo di modificare la struttura `Orario`, dovremmo ricordarci di riscrivere anche questa funzione, adeguandola alle nuove caratteristiche della struttura, con un dispendio di tempo e la possibilità di fare degli errori.
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

<hr id="information-hiding">

Le variabili all'interno di una classe, sono dette *dati membro* o *attributi* della classe; le funzioni, invece, sono dette *funzioni membro* o *metodi*.
Quando si crea una variabile di classe `C`, si dice che si: *istanzia* un *oggetto* di classe `C` o che si crea una *istanza* della classe.
I dati e le funzioni membro di una classe sono direttamente accessibili alle funzioni membro della classe, ma per utilizzarli all'interno di funzioni esterne alla classe, si devono utilizzare gli operatori di selezione `.` e `->`. 
Il primo, detto *operatore di selezione diretta*, viene utilizzato con istanze della classe; il secondo, detto *operatore di selezi­one indiretta*, con puntatori ad esse:

```
class Punto
{
public:             
    
    /** Dichiara i dati membro della classe */
    int _x, _y;

    /** 
     *  Le funzioni interne alla classe accedono ai
     *  dati membro con la sintassi ordinaria.
     */  
    Punto(int x, int y) {
        _x = x;
        _y = y;
    }
} ;

int main(int argc, char** argv) 
{
    /** Crea un oggetto di classe Punto */
    Punto p(5,6);       

    /** Assegna l'istanza della classe al puntatore ptr */
    Punto *ptr = &p ;   
    
    /** 
     *  Le funzioni esterne alla classe accedono ai
     *  dati membro tramite gli operatori di selezione.
     */  
    p._x    = 3 ;       // assegna un valore tramite l'oggetto
    ptr->_y = 2 ;       // assegna un valore tramite il puntatore
    ...
}
```

L'etichetta `public` che vedi all'inizio della dichiarazione della classe è un *indicatore di accesso* e serve a stabilire quali membri della classe siano accessibili a funzioni esterne e quali invece siano riservati in esclusiva alla classe stessa.

> il selvaggio non ama dire il suo nome o farsi fotografare, perché per mezzo del suo nome o del ritratto egli è accessibile, e può quindi ricevere danno da chi con questi mezzi è in grado di raggiungerlo<a href="/man/note#selvaggio" class="nota"></a>.

Questa frase di Lucien Lévy-Bruhl si applica anche alle classi del C++. 
Sia gli attributi che i metodi di una classe possono essere protetti da letture o modifiche indebite grazie ai modificatori di accesso `private`, `protected` e `public`.
I metodi o gli attributi dichiarati *private* sono accessibili solo alla classe stessa; quelli dichiarati come *protected* sono accessibili alla classe e a eventuali <a href="/man/ereditarieta" class="xref">classi derivate</a>; quelli dichiarati come *public* sono accessibili a qualunque elemento del programma.
In mancanza di specifiche, tutti i dati e le funzioni di una classe verranno considerati:

-	*privati*, nel caso di una classe;
-	*pubblici*, nel caso di `struct` o `union`.

Per le `struct`, la visibilità dei dati membro può essere modificata con gli indicatori di accesso; i dati delle `union`, invece, possono essere solo pubblici.  
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

Questo tipo di ordinamento della dichiarazione, oltre a garantirti una maggiore leggibilità del codice, ti consentirà, se lo desideri, di omettere l’indicatore di accesso `private` iniziale (è la soluzione di default, ricordi?).  
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
Gli attributi `_h`, `_m` e `_s` compaiono dopo la parola-chiave `private` e saranno quindi visibili solo alle funzioni della classe stessa.  
La funzione `Orario`, che ha lo stesso nome della classe, è detta *costruttore* e viene richiamata ogni volta che si crea una variabile di tipo `Orario`.
Il suo scopo è di inizializzare le variabili all'interno della classe, in questo caso, impostando tutti e tre i valori a 0.  

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

- *esplicitamente*, ma in questi casi dovrai specificare il loro nome per intero, anteponendo il nome della classe e l'operatore di risoluzione `::`, così come vedremo fra poco.
    
Attenzione, però: se a uscire dal campo d’azione è un puntatore, il ditruttore della classe non viene richiamato automaticamente, perciò gli oggetti creati in maniera dinamica con l'operatore `new` dovranno sempre distrutti per mezzo dell’operatore `delete`.  

<hr id="funzioni-di-interfaccia">

Le funzioni membro devono essere dichiarate all'interno della dichiarazione della classe, ma possono essere definite sia dentro che fuori di essa. 
Definirle all'interno della dichiarazione della classe equivale a dichiararle <a href="/man/funzioni#inline" class="xref">inline</a>
Se invece le si definisce esternamente alla dichiarazione della classe, vanno identificate aggiungendo il nome della classe prima di quello della funzione, seguito dall'<a href="/man/operatori#risoluzione" class="xref">operatore di risoluzione</a>:

```
{% include_relative src/classi-classe-orario-1.cpp %}
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

Il modo più rapido per accedere ai dati privati di una classe attraverso una funzione o una classe esterna è quello di dichiararle come `friend`.
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

Questa soluzione è molto comoda, ma non ne abusare.
Come avviene nella realtà, prima di dare la tua amicizia a qual­cuno, verificane l’affidabilità: un `friend` ha la possibilità di fare grossi danni, altrimenti.  
Un metodo più sicuro consiste nel definire delle funzioni membro pubbliche che consentano un accesso controllato ai dati che si vogliono proteggere. 
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
Non sei nemmeno obbligato a dichiarare le funzioni di interfaccia come `inline`; l'ho fatto qui perché erano estremamente semplici, ma valgono sempre le considerazioni fatte <a href="/man/funzioni#inline" class="xref">a suo tempo</a>.  
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
Questo tipo di funzioni, però, ha due difetti: limita i valori che puoi assegnare all'attibuto e limita la granularità dei privilegi che puoi assegnare a chi utilizza la classe.
Limita il numero di valori che puoi assegnare all'attibuto, perché esclude il valore del parametro di default &mdash; cosa che non crea problemi in questo caso, dato che non esiste un'ora `-1`, ma che potrebbe farlo nel caso di una stringa con parametro di default nullo.
Limita la granularità dei privilegi sulle funzioni, perché ti costringe a rendere pubbliche le funzioni di scrittura dei dati membro e questo, in certi casi potrebbe non essere saggio. 
Ti consiglio perciò di scrivere sempre due funzioni di interfaccia distinte per la lettura e la scrittura: sul momento ti sembrerà uno spreco di tempo, ma, a meno che il tuo programma non sia particolarmente banale, o prima o poi ti accorgerai di aver fatto la scelta corretta.  

<hr id="this">


<!--

Oltre a quelli definiti dall’utente, la lista dei membri di una classe comprende sempre anche un “clandestino”, che viene dichiarato implicitamente. Si chiama `this` ed è un puntatore all'istanza corrente.

Oltre a quelli definiti dall’utente, poi, la lista dei membri di una classe comprende sempre anche un clandestino, che viene dichiarato implicitamente. Si chiama this ed è utilizzato, in maniera implicita o esplicita, per riferirsi all’istanza cui appartiene, ovvero, se C è una classe di cui Ist è un’istanza, this di Ist sarà un puntatore a oggetti di tipo C che punta all’indirizzo di Ist o, se preferite:
X * this = &x ;
NOTA: 
Questa istruzione ha unicamente valore di esempio: non è possibile inserire una simile linea di codice in un programma senza ricevere un messaggio da parte del compilatore con l'avviso che this è una parola chiave e non può essere usata come identificatore.
Non capita molto spesso di dover utilizzare this in maniera esplicita, mentre è sempre passato come membro nascosto nelle funzioni membro, per specificare su quale istanza della classe la funzione debba operare. 
2.4.1 Dati membro statici
Le uniche funzioni membro che non possono fare uso di this sono quelle dichiarate come static, che si comportano in maniera molto particolare: 
·	mentre di tutti gli oggetti non statici della lista dei membri, dati o funzi­oni che siano, viene fatta una copia distinta in ciascuna nuova istanza della classe, i membri dichiarati come static sono unici e vengono per­ciò condivisi dalle diverse istanze;
·	non è possibile inizializzare membri static all’interno della dichiarazione e si deve quindi farlo altrove nel programma come per un qualsiasi oggetto a visibilità globale;
·	si può accedere ad essi, oltre che con i normali operatori di selezione, facendo riferimento alla classe stessa.
Cerchiamo di spiegarci meglio con un esempio. Immaginiamo di voler tenere nota in una variabile del numero di oggetti della classe Punto che sono stati creati: nessun modo migliore per farlo di aggiungere alla nostra classe un membro static:

fare esempio di classe con attributi binarii

\[cfr. *Breve storia dell'infinito*, pagg. 30-40\]

Si può dire che esista qualcosa che non ha dimensioni?


parlare degli operatori di cast 
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)


@todo: parlare della posizione di un certo dato in memoria, che può variare in successive esecuzioni del programma. Allo stesso modo, l'io cosciente di ciascuno di noi non è detto che si manifesterà nello stesso individuo, ma potrà essere "allocato" in altri esseri. In quest'ottica, il: "Cogito ergo sum" di Cartesio è insensato, perché ciò che cogita non è ciò che è. cfr. Ananda, note a capitolo sull'Induismo

@todo: Utlizzare l'operatore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. 
Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 


-->
