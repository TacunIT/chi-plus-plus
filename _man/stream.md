---
status:     pubblicato
layout:     manuale
class:      capitolo
no-index:   true
title:      Gli stream
permalink:  /man/stream
quote:      "Non puoi immergere i tuoi byte due volte nello stesso stream"
---

Oggi ti parlerò degli *stream* che, com'è noto, sono la componente più importante del C++.

Il C++ eredita dal C l’assenza di parole chiave per la gestione dell’I/O.
Al posto di istruzioni come la `print` del BASIC, utilizza delle librerie di classi e funzioni che permettono di convertire in testo stampabile gli oggetti gestiti dal programma o di convertire degli elementi testuali in oggetti.
Non potrebbe essere altrimenti: il C++ non deve gestire solo stringhe e numeri, come il BASIC, ma anche numeri in virgola mobile, puntatori e soprattutto i tipi di dato definiti dall’utente, per i quali non sarebbe possibile definire un comportamento standard e che quindi dovrebbero essere trattati in maniera differente dai dati primitivi, con tanti saluti alla coerenza del linguaggio.  
Oltre a poter sfruttare le librerie di funzioni del *C*, il C++ ha una propria libreria di I/O, ba­sata sulla gerarchia delle classi `stream`, che permette di gestire anche i tipi di dato definiti dall'utente.
Abbiamo visto degli esempii di questa caratteristica quando abbiamo parlato di <a href="/man/c-plus-plus#polimorfismo" class="xref">polimorfismo</a> e di <a href="/man/polimorfismo#overload-operatori" class="xref">overload degli operatori</a>:


```
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}
```

Questo codice “insegna” all’operatore `<<` come comportarsi per visualizzare un oggetto di classe `Animale`. 
Lo stesso si può fare (e lo abbiamo fatto) per qualsiasi altro tipo definito dall’utente. 
È la sintassi del linguaggio che si adatta alle esigenze del programmatore, e non viceversa.  
Alcuni concetti chiave per la comprensione degli stream sono:

- uno *stream* è un'astrazione che rappresenta la sorgente o la destinazione di un insieme di dati di lunghezza variabile: l'input da tastiera, l'output su schermo, i buffer di memoria, le stringhe, i file; 
- l’output su stream verso una qualsiasi destinazione, viene definito *scrit­tura* o *inserimento* e si effettua per mezzo dell’operatore `<<`; 
- con i termini *lettura* o *estrazione*, invece, si intende l’operazione di acquisizione da una sorgente, effettuata dall’operatore `>>`.

La libreria `iostream` del C++ permette di gestire le operazioni di I/O su stream per mezzo di classi derivate da due classi base: `streambuf` e `iosbase`.
La libreria ha due diverse “linee genealogiche”: una destinata alla gestione dei caratteri di un byte e una destinata ai caratteri multi-byte.
Le classi della libreria multi-byte hanno lo stesso nome delle classi ordinarie, con l'aggiunta del prefisso: "w".  
Questo è lo schema di ereditarietà delle classi della libreria `iostream`:

```
                              ios_base
                                 |
                             basic_ios
                                 |
               __________________|_________________       
              |                                    | 
              |                                    | 
        basic_istream                         basic_ostream
             | |                                  | |   
             | |                                  | |  
             | |__________________________________| |  
             |                   |                  |   
      _______|______             |         _________|_______       
     |              |            |        |                 | 
basic_istringstream |            |   basic_ostringstream    |
                    |            |                          |
                    |            |                          |
               basic_ifstream    |                  basic_ofstream
                                 |
                            basic_iostream
                         ________|________
                        |                 |
               basic_stringstream    basic_fstream
          
```

A parte `ios_base`, queste sono tutte classi template che sono poi istanziate con parametri differenti per gestire la gestione dei tipi di carattere `char` and `wchar_t`. 
Per esempio, la classe `ostream` è una specializzazione della classe `basic_ostream`:

```
typedef basic_ostream<char> ostream;
```

Il suo corrispettivo multi-byte è la classe `wostream`:

```
typedef basic_ostream<wchar_t> wostream;
```

La classe template `basic_ostream`, a sua volta, deriva da `basic_ios`:

```
template<
    class CharT,
    class Traits = std::char_traits<CharT>
> class basic_ostream 
: virtual public std::basic_ios<CharT, Traits>
```
che, a sua volta, deriva da `ios_base`:

```
template<
    class CharT,
    class Traits = std::char_traits<CharT>
> class basic_ios 
: public std::ios_base	
```

In sostanza: se davanti al nome c'è il prefisso `basic_`, si tratta della classe template; se c'è c'è la lettera “w”, si tratta della versione multi-byte, altrimenti è la classe ordinaria.  
Oltre alle classi derivate da `iosbase`, la libreria comprende anche delle classi per la gestione dei buffer di dati:

```
                       basic_streambuf
                      ________|________
                     |                 |
               basic_stringbuf     basic_filebuf
```

La classe template virtuale `basic_streambuf`, che fa parte della libreria, ma non della discendenza da `ios_base`, contiene i dati e le funzioni necessarie alla gestione di un buffer di caratteri.
Le sue classi derivate `basic_stringbuf` e `basic_filebuf` sono invece specializzate, rispettivamente, nella gestione di buffer in memoria e su file.
Anche in questo caso, la libreria comprende due versioni di ciascuna classe, specializzate per la gestione di `char` and `wchar_t`. 

```
typedef streambuf  basic_streambuf<char>
typedef wstreambuf basic_streambuf<wchar_t>
typedef filebuf    basic_filebuf<char>
typedef wfilebuf   basic_filebuf<wchar_t>
```

Come forse avrai intuito, esaminare le singole classi della libreria `iostream` è un'attività che rivaleggia, in quanto a tedio, con l'epigrafia classica, ma ci permetterà di vedere applicati tutta una serie di principii di cui abbiamo parlato nelle lezioni precedenti, perciò, facciamoci forza e andiamo a incominciare.

---

La classe <code id="ios-base">ios_base</code> e la sua prima discendente <code id="basic-ios">basic_ios</code> sono classi generiche che forniscono le funzioni di base per la gestione degli stream, indipendentemente dal fatto che si tratti di stream di input o di output.  
Una peculiarità di `ios_base` è che non possiede un costruttore pubblico, quindi non è possibile utilizzarla per creare oggetti, ma solo come base per delle classi derivate.  
Le istanze specializzate di `basic_ios` sono: 

```
typedef basic_ios<char>    ios;
typedef basic_ios<wchar_t> wios;
```

Tramite i metodi di queste classi è possibile verificare o modificare lo stato interno dello stream, la sua formattazione o definire delle funzioni callback per la gestione dei dati.  
Il dato membro `openmode`, per esempio, definisce il modo in cui debba essere aperto lo stream:

|---|---|
|*app*    | Fa sì che ogni operazione di output avvenga alla fine dello stream.
|*ate*    | In apertura dello stream, sposta il punto di inserimento al termine  (_**at e**nd_) del buffer di I/O.
|*binary* | Gestisce il contenuto dello stream come un flusso di dati binario.
|*in*     | Permette operazioni di input.
|*out*    | Permette operazioni di output.
|*trunc*  | Azzera il contenuto dello stream all'apertura.

Il dato membro `iostate`, che utilizzeremo in uno dei prossimi esempii, contiene le informazioni sullo stato corrente dello stream:

|---|---|
|*goodbit*  | Nessun errore
|*eofbit*   | È stata raggiunta la fine dello stream.
|*failbit*  | L'ultima operazione di I/O è fallita.
|*badbit*   | L'ultima operazione di I/O non era valida.
|*hardfail* | Si è verificato un errore irrecuperabile.

Entrambi questi dati membro sono delle <a href="/man/note#bitmask" class="xref">bitmask</a>, quindi possono contenere più di un valore.
L'istruzione seguente, per esempio, apre uno stream su file combinando in `OR` tre possibili valori per `openmode`:

```
fstream file_io("io.txt"
               , ios_base::in | ios_base::out | ios_base::app);
```

Dopo `basic_ios`, le classi della libreria si specializzano nell'input o nell'output: da un lato `basic_istream`, da cui derivano i due stream standard di input `cin` e `wcin`; dall'altro `basic_ostream`, da cui derivano gli stream standard di output `cout`, `cerr`, `clog` e le loro controparti "wide": `wcout`, `wcerr`, `wclog`.  
Da queste due classi generiche derivano delle classi template specializzate nell'input o nell'output su file o in memoria:

```
template 
<class Elem, class Tr = char_traits<Elem>>
class basic_ifstream 
: public basic_istream<Elem, Tr>

template 
<class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_istringstream 
: public basic_istream<Elem, Tr>

template 
<class Elem, class Tr = char_traits<Elem>>
class basic_ofstream 
: public basic_ostream<Elem, Tr>

template 
<class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_ostringstream 
: public basic_ostream<Elem, Tr>
```

e una classe capace di gestire entrambe le operazioni:

```
template 
<class Elem, class Tr = char_traits<Elem>>
class basic_iostream 
: public basic_istream<Elem, Tr>
, public basic_ostream<Elem, Tr>
```

anche questa, con due specializzazioni per la gestione di file e memoria:

```
template 
<class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_stringstream 
: public basic_iostream<Elem, Tr>

template 
<class Elem, class Tr = char_traits<Elem>>
class basic_fstream 
: public basic_iostream<Elem, Tr>
```

Prima che ci assalga un attacco di narcolessia, vorrei mettere in atto tutto questo con qualche esempio.  
Abbiamo già visto diversi esempii di output su stream:

```
cout << "Hello World!"  // stringhe
     << 12              // interi
     << 0.35            // float
     << argv[1]         // puntatori
     << endl;               
``` 

Non abbiamo ancora parlato dell'input da stream, che però ha un funzionamento piuttosto simile:

```
{% include_relative src/stream-input-1.cpp %}
```

Questo codice legge una stringa dallo standard input e la scrive sullo schermo, ma ci mostra una peculiarità dell'input da stream:

```
> g++ src/cpp/stream-input-1.cpp -o src/out/esempio
> src/out/esempio                                
Inserire una stringa: Penso, quindi sono.
Penso,
```

Come vedi, le operazioni di lettura con l’operatore >> si arrestano al primo carattere di spaziatura; perciò, se vogliamo leggere tutta la stringa, dobbiamo modificare il codice:

```
{% include_relative src/stream-input-2.cpp %}
```

```
> g++ src/cpp/stream-input-2.cpp -o src/out/esempio
> src/out/esempio                                  
Inserire una stringa: Penso, quindi sono.
Penso, quindi sono.
Inserire una stringa: Cogito ergo sum.
Cogito ergo sum.
```

Un'altra caratteristica degli operatori `<<` e `>>` è che la loro precedenza è minore di quasi tutti gli altri operatori, il che vi consente di scrivere delle istruzioni come questa:

```
cout << "Due più due fa: " << 2 + 2 << '\n' ;
```

Gli operatori logici di AND `|`, di OR inclusivo `&` e di XOR esclusivo `^`, hanno una precedenza minore degli operatori `<<` e `>>`  e, se non vengono isolate tra parentesi, le operazioni che li coinvolgono possono essere causa di errori. 
Per esempio, in un’istruzione come la seguente, l'operatore `&` verrebbe interpretato come un riferimento a un oggetto, con conseguenze diverse da quelle attese:

```
cout << "Il valore è: " << 2 & 2 << '\n' ;	// ERRORE! 
```

la sintassi corretta è, invece:

```
cout << "Il valore è: " << (2 & 2) << '\n' ;	// OK
```

Il comportamento di default degli operatori di input da stream prevede anche delle convenzioni di for­mattazione: <!-- @todo:verificare -->
- **il formato di conversione della base è decimale**;
- **il carattere di riempimento è lo spazio**;
- **la precisione delle cifre a virgola mobile è la stessa utilizzata da print­f()**, con arrotondamento della sesta cifra decimale;
- **la larghezza del campo ha valore di default 0**, il che significa che lo stream di output utilizzerà tutti i caratteri necessari alla visualizzazione dell’intero valore o stringa. 

Le prime tre modifiche sono per­manenti: una volta impostati, i nuovi valori saranno validi fino a che un'altra istruzione non torni a modificarli; le modifiche alla larghezza del campo di input, invece, valgono solo per l'istruzione che le richiede.  
In alcuni esempii precedenti abbiamo visto che è possibile modificare il formato di output di default di uno stream tramite dei *maipolatori*:

```
cout << setfill('0') << setw(2) << ora._h << ":" 
     << setfill('0') << setw(2) << ora._m << ":" 
     << setfill('0') << setw(2) << ora._s << endl;
```

Lo stesso risultato si può ottenere per mezzo di apposite funzioni delle classi `ios_base` e `basic_ios`, che permettono di alterare il carattere di riempimento, la precisione delle cifre decimali e la larghezza del campo:

```
{% include_relative src/stream-format.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> src/out/esempio                                 

Valori di default
  precision: 6
  fill:      ' '
  width:     0
  output:    123.457

Valori modificati
  output:    #####123.5

Valori correnti
  precision: 4
  fill:      '#'
  width:     0
  output:    123.5
```

<hr id="iostate"> 

Quando un’operazione di lettura o scrittura su stream fallisce, il valore del dato membro `iostate` assume un valore differente da zero.
La classe basic_ios ha delle funzioni membro booleane che tornano `true` o `false` se il valore `iostate` indica un determinato evento e la funzione `rdstate` che torna il valore assoluto di `iostate`:

|---|---|
| good    | nessun errore: il valore di `iostate` è 0
| eof     | è stata raggiunta la fine del file
| fail    | c'è stato un errore di I/O non bloccante
| bad     | c'è stato un errore di I/O bloccante
| rdstate | torna il valore corrente di `iostate`

Queste funzioni permettono di interrompere la lettura o la scrittura di uno stream quando si verifica un errore o se si è raggiunta la fine del file.
Una cosa che non devi fare mai, però, è di utilizzare la funzione `eof` all'interno di un ciclo `while` per la lettura di un file:

```
{% include_relative src/stream-eof.cpp %}
```

Se fai leggere a questo programma un file che contenga i numeri: 10, 20 e 30, otterrai questo output: 

```
> g++ src/cpp/stream-eof.cpp -o src/out/esempio
> src/out/esempio src/cpp/stream-eof.txt       
10
20
30
30
```

L'errore si verifica perché il controllo della funzione `eof` avviene prima della quarta operazione di lettura, quando lo stream è ancora in stato `good`.
Un modo migliore di gestire questi casi è di utilizzare la funzione `good`, che ci permette di verificare anche la corretta apertura del file:

```
{% include_relative src/stream-good.cpp %}
```
Se compili ed esegui questo programma, ottieni il risultato corretto:

```
> g++ src/cpp/stream-good.cpp -o src/out/esempio
> src/out/esempio src/cpp/stream-eof.txt        
10
20
30
```

<hr id="eccezioni"> 

Le *eccezioni* permettono di gestire gli errori che avvengono durante l'esecuzione del programma. 
Quando succede qualcosa di anormale, il sistema *lancia* un'eccezione, ovvero trasferisce il controllo del processo dalla funzione corrente a blocchi di istruzioni specifici, chiamati *exception handler*. 
Perché tutto questo avvenga, il codice che genera l'errore deve essere racchiuso in un blocco `try`/`catch`:

```
try {
    
    // codice che potrebbe dare errore
    
} catch (...) {

    //  istruzioni per la gestione dell'errore
}
```

Le eccezioni possono essere lanciate e gestite sia da codice specifico all'interno del programma, sia dai meccanismi automatici del C++:

```
{% include_relative src/stream-eccezioni-1.cpp %}
```

Se compili ed esegui questo codice, causerai un errore che, non essendo gestito dal programma, è gestito dalla funzione standard del C++:

```
> g++ src/cpp/stream-eccezioni-1.cpp -o src/out/esempio
> src/out/esempio
libc++abi: terminating with uncaught exception of type
std::__1::ios_base::failure: ios_base::clear
: unspecified iostream_category error
zsh: abort      src/out/esempio
```

Se però inseriamo il codice che apre il file in un blocco `try`/`catch` e definiamo un *handler* per la gestione degli errori in apertura dei file, il risultato sarà più controllato:

```
{% include_relative src/stream-eccezioni-2.cpp %}
```

```
> g++ src/cpp/stream-eccezioni-2.cpp -o src/out/esempio
> src/out/esempio                                      
Errore in esecuzione
```

Possiamo addirittura prevenire gli errori in apertura del file facendo sì che sia lo stesso programma a lanciare un'eccezione se si accorge che manca il nome del file nei parametri di avvio:

```
{% include_relative src/stream-eccezioni-3.cpp %}
```

In questo modo, il programma è in condizione di gestire tutti i possibili errori di esecuzione:

```
> g++ src/cpp/stream-eccezioni-3.cpp -o src/out/esempio
> src/out/esempio                                      
Nome file mancante
> src/out/esempio nomefile.txt
Errore in esecuzione
```

La libreria standard del C++ ha una classe specifica per la gestione delle eccezioni:

```
class exception {
public:
    exception () throw();
    exception (const exception&) throw();
    exception& operator= (const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
}
```

Definendo una classe derivata da `exception` con altri dati membro e una funzione `what` specializzate, è possibile gestire in maniera più strutturata le segnalazioni di errore.
È quello che faremo nel prossimo esempio. 

```
{% include_relative src/stream-eccezioni-4.cpp %}
```

Se compili ed esegui questo codice, otterrai il seguente output, a seconda dei parametri forniti:

```
> g++ src/cpp/stream-eccezioni-4.cpp -o src/out/esempio
> src/out/esempio                                      
-10: Errore nei parametri di input.
USO: esempio <n caratteri> <path file>

> src/out/esempio 41                                   
-10: Errore nei parametri di input.
USO: esempio <n caratteri> <path file>

> src/out/esempio 41 src/cpp/stream-input.txt          
Nacqui da famiglia ricca, ma troppo tardi

> src/out/esempio 0 src/cpp/stream-input.txt 
Nacqui da famiglia ricca, ma troppo tardi.  
Secondogenito, vidi la florida impresa paterna andare in dote  
per diritto di nascita, ma anche per naturale inclinazione
ai miei monozigotici fratelli maggiori e, com'è consuetudine 
per i figli cadetti, fui avviato alla vita monastica.
Entrai in seminario all'età di nove anni e presi i voti il 
giorno del mio diciottesimo compleanno.
Conobbi il Maestro quattro anni dopo.  
```

<hr id="dottrina"> 

Il Maestro Canaro diceva che una filosofia, per spingere i suoi seguaci a comportarsi in maniera corretta, deve possedere due caratteristiche: *trascendenza* e *permanenza*.  
Se, per un caso o per volere del Cielo, gli esempii che ti ho fatto finora prendessero coscienza di sé, senza però sapere di far parte di una serie di lezioni, probabilmente si sentirebbero inutili e sciocchi.
Perfino l'ultimo esempio che abbiamo visto, che è il più complesso di tutti, non potrebbe fare a meno di chiedersi quale sia il senso della sua esistenza, dato che lo stesso risultato si può ottenere con una semplice istruzione da riga di comando:

```
head -c 41 src/cpp/stream-input.txt
``` 

Qualche esempio riuscirebbe comunque a fare il proprio dovere, ma ce ne sarebbero altri che reagirebbero male a questa epifania: i più deboli si deprimerebbero, mentre i più ambiziosi cercherebbero una compensazione nell'accumulo eccessivo di risorse di sistema: RAM, spazio disco o cicli CPU.  
Al contrario, se gli esempii sapessero di essere parte integrante di una serie di lezioni, tutto ciò che altrimenti appare insensato o inutile, dai commenti pleonastici fino al parametro numerico dell'ultimo esempio, acquisterebbe il giusto significato e ciascun esempio saprebbe di essere non solo utile, ma necessario.  
Se c'è una cosa che sappiamo per certa dell'Universo in cui viviamo è che si sta espandendo. 
Se nulla interverrà a mutare questo stato di cose, tutto ciò che esiste, dagli esseri viventi alle stelle, è destinato o prima o poi a spegnersi nella vittoria di Pirro dell'Entropia come un computer portatile a cui si scarichi la batteria.  
Al contrario, se la Gravità riuscirà a invertire il moto delle galassie, tutto ciò che esiste, dalle stelle agli esseri viventi, è destinato o prima o poi ad annichilirsi nell'Uno in attesa di un nuovo ciclo di esistenza.  
Questo, però, non basterà da solo a dare un senso alle nostre esistenze, perché, senza persistenza, le nostre azioni saranno come degli oggetti di classe `streambuf`: una volta spento il computer, non esisteranno più e tutto ciò che abbiamo fatto, giusto o sbagliato che sia, non avrà alcuna influenza su ciò che accadrà successivamente.  
L'unica cosa che può salvarci dall'oblio e dall'insensatezza sono i `Post-It`, la persistenza.  
Per dare un senso alla nostra esistenza abbiamo bisogno di un *hard-disk* su cui salvare gli stream delle nostre vite, in modo che ogni ciclo di esistenza possa fare tesoro delle esperienze passate.
Senza di esso, Hitler varrà quanto Ghandi e Albert Schweitzer quanto Ted Bundy.
Dovrà essere però un *hard-disk* meta-fisico, per sfuggire al *Big Crunch*, e questo ci riporta all'importanza della trascendenza.  
Se mi guardo indietro, per il mezzo secolo su cui ho visibilità diretta, vedo una lunga serie di fallimenti ideologici.
Il Sessantotto ha spazzato via delle parti sicuramente rivedibili, ma fondamentali della nostra Società senza darci nulla in cambio, tranne la minigonna.
La lotta armata degli anni settanta ha sparato alle persone sbagliate, mentre la *reaganomics* è crollata alla fine degli anni '80 insieme al muro di Berlino.
Le speranze degli anni '90 si sono schiantate l'11 Settembre 2001 sulle Torri Gemelle e anche Internet, che nelle intenzioni iniziali sarebbe dovuta essere un mezzo per dare a tutti la possibilità di esprimere le proprie idee si è trasformata, nel tempo, in un sistema di controllo e di dis-informazione di massa.  
Quel poco che restava dei nostri valori e delle nostre idee è stato annichilito dagli *smart-phone* e dai *social-network*.  
Esiste un fattore comune alle ideologie degli ultimi cinquant’anni che ne ha accelerato l’obsolescenza e le ha rese incapaci di sopravvivere alla prima sconfitta: il rifiuto più o meno accanito di ogni forma non strumentale di spiritualità.  
Se si definisce uno schema di valori negando allo stesso tempo qualsiasi forma di trascendenza, si è costretti a ricercare i valori e le motivazioni della propria etica all’interno dello schema stesso. 
Si può fare, ma è sbagliato e limitativo. 
È sbagliato, perché le regole che si definiscono sono sempre una conseguenza di esigenze contingenti (guerre, sopraffazioni, disparità sociali), venendo a mancare le quali lo schema logico del sistema perde di significato e si disgrega.
È limitativo, perché restringe il numero dei possibili obiettivi da perseguire a un insieme finito di azioni o traguardi, raggiunti i quali non esiste più possibilità di migliorare.  
Pensa al gioco degli Scacchi: non esiste nessun motivo, all’interno della scacchiera, che costringa ciascun pezzo a muoversi solo in una specifica maniera.
Le torri si muovono in orizzontale, gli alfieri in diagonale e il cavallo salta con una traiettoria a “L” in ossequio a delle regole definite al di fuori della scacchiera, ma è proprio da queste limitazioni che deriva il fascino del gioco. 
Al contrario, la Società moderna è una scacchiera in cui ciascun pezzo si muove nella maniera che preferisce perché, in ossequio a un malinteso senso di libertà, sono state eliminate tutte le regole. 
Le persone di successo che si privano della vita sono pedoni che, arrivati alla fine della scacchiera grazie alla loro abilità, hanno scoperto che non esiste alcuna forma di promozione, perché insieme alle regole sono stati aboliti anche i giocatori.

<hr id="canaro">

Il Maestro Canaro una volta mi disse:

> {{ site.data.canaro.lennon }}

<!--
come nacque il gioco degli scacchi: due principi indiani, Gav e Talhend, si contendevano il regno, nonostante la loro madre li pregasse di condividerlo come bravi fratelli. I due non ci riuscirono e una loro lite si trasformò in una sanguinosa guerra, che venne infine vinta da Gav, e nella quale Talhend perse la vita. La madre, disperata, chiese al figlio superstite di raccontarle per filo e per segno come si fosse svolta la battaglia tra i due, e per spiegarle tutto quanto in modo dettagliato, Gav creò una scacchiera e fece intagliare nel legno le figurine di torri, cavalli e soldati, creando così le basi del gioco degli scacchi.
Fois, Mila. Miti Persiani: Zoroastro e il Libro dei Re (Meet Myths) (Italian Edition) (pp. 131-132). Kindle Edition. 


@todo: decidere se spiegare che gli esempii del testo sono studiati per essere progressivamente migliorati, per dimostrare come la scrittura di codice sia un'attività in continua evoluzione.



-->
