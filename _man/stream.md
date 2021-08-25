---
status:     redazione
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
typedef stringbuf  basic_stringbuf<char>
typedef wstringbuf basic_stringbuf<wchar_t>
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

Il comportamento di default degli operatori di input da stream prevede anche delle convenzioni di for­mattazione: <!-- @todo:verificare -->
- **il formato di conversione della base è decimale**;
- **il carattere di riempimento è lo spazio**;
- **la precisione delle cifre a virgola mobile è la stessa utilizzata da print­f()**, con arrotondamento della sesta cifra decimale;
- **la larghezza del campo ha valore di default 0**, il che significa che lo stream di output utilizzerà tutti i caratteri necessari alla visualizzazione dell’intero valore o stringa. 

Le prime tre modifiche sono per­manenti: una volta impostati, i nuovi valori saranno validi fino a che un'altra istruzione non torni a modificarli; le modifiche alla larghezza del campo di input, invece, valgono solo per l'istruzione che le richiede.  
Un'altra caratteristica degli operatori `<<` e `>>` è che la loro precedenza è minore di quasi tutti gli altri operatori, il che vi consente di scrivere delle istruzioni come questa:

```
cout << "Due più due fa: " << 2 + 2 << '\n' ;
```

Sfortunatamente, però, gli operatori logici di AND `|`, di OR inclusivo `&` e di XOR esclusivo `^`, hanno una precedenza minore degli operatori `<<` e `>>`  e, se non vengono isolate tra parentesi, le operazioni che li coinvolgono possono essere causa di errori. 
Per esempio, in un’istruzione come la seguente, l'operatore `&` verrebbe interpretato come un riferimento a un oggetto, con conseguenze diverse da quelle attese:

```
cout << "Il valore è: " << 2 & 2 << '\n' ;	// ERRORE! 
```

la sintassi corretta è, invece:

```
cout << "Il valore è: " << (2 & 2) << '\n' ;	// OK
```

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

<hr id="formattazione-output"> 

In alcuni esempii precedenti abbiamo visto che è possibile modificare il formato di output di default di uno stream tramite dei *maipolatori*:

```
cout << setfill('0') << setw(2) << ora._h << ":" 
     << setfill('0') << setw(2) << ora._m << ":" 
     << setfill('0') << setw(2) << ora._s << endl;
```

Lo stesso risultato si può ottenere per mezzo di apposite funzioni delle classi `ios_base` e `basic_ios`, che permettono di alterare il carattere di riempimento, la precisione delle cifre decimali e la larghezza del campo.
Le prime due modifiche sono permanenti la quarta no.
Se si modifica il formato di output di uno stream, questo resterà nel nuovo stato fino alla prossima istruzione di modifica, mentre il valore della lunghezza del campo viene re-impostato a zero dopo ogni operazione di output:

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

<!--


5.8	modifica dei flags di formattazione
Ma la larghezza del campo, la precisione ed il carattere di riempimento non sono le uniche formattazioni modificabili. Un altro modo di modificare le convenzioni di format­tazione standard è quello di alterare la variabile membro x_flags che contiene i flags per la formattazione. 
La dichiarazione della variabile è:

class ios
{
			...
 protected:
			...
			long x_flags ;
			...
Anche la variabile x_flags, come x_state è un membro protected di ios, quindi anche in questo caso non sarà possibile nessuna modifica diretta da parte di funzioni esterne alla classe, ma solo quelle previste e concesse dalle funzio­ni di interfaccia:
long ios::flags() 
long ios::flags(long flags)
long ios::setf(long flags)
long ios::setf(long group, long bits)
long ios::unsetf(long flags)
I flags che vengono utilizzati con queste funzioni sono definiti in un’enumerazione prop­ria della classe ios:

enum    
{
 skipws    	= 0x0001, 
 left      	= 0x0002,
 right     	= 0x0004,
 internal  	= 0x0008,
 dec 		= 0x0010,
 oct 		= 0x0020,
 hex 		= 0x0040,
 showbase  	= 0x0080,
 showpoint 	= 0x0100,
 uppercase 	= 0x0200,
 showpos   	= 0x0400,
 scientific	= 0x0800,
 fixed     	= 0x1000,
 unitbuf   	= 0x2000,
 stdio     	= 0x4000 
};
La tabella seguente mostra il modo in cui riferirsi ai diversi flag nei programmi e le con­seguenze della loro alterazione sul comportamento della classe:
Funzioni di interfaccia per la modifica della variabile x_flags

Le costanti che invece definiscono i campi di bit su cui operare sono:
Costanti per la modifica della variabile x_flags

Vediamo ora in dettaglio il funzionamento delle diverse funzioni:
long ios::flags() 
long ios::flags(long flags)

La prima versione della funzione flags() è innocua: semplicemente ritorna il valore della variabile x_flags; un po’ più di attenzione va rivolta invece all’utilizzo della secon­da versione, che sostituisce la variabile con quella passatale come parametro, ritornando il vecchio valore. Se per esempio voleste modificare solo il flag ios::hex senza andare ad intaccare lo stato degli altri flag di formattazione, dovreste scrivere qualcosa di simile:
FLAGSTST.CPP - Test della funzione ios::flags()

/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	FLAGSTST.CPP - Test della funzione ios::flags()
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
/////////////////////////////////////////////////////////////
void main()
{
 ostream os(2) ;							  // 001
 long flgs = os.flags() ;					  // 002

 os << "flgs  : " << flgs << "\n" ;				  // 003
 os.flags(flgs ^ ios::dec | ios::hex | ios::showbase); // 004
 os << "flgs  : " << flgs << "\n" ;				  // 005
 os << "flags : " << os.flags() << "\n" ;			  // 006

 os.flags(0) ;							  // 007
 os << "flags : " << os.flags() << "\n" ;			  // 008
};
/////////////////////////////////////////////////////////////
001  Invia l’output a stdout.
002  Salva il valore iniziale di x_flags.
003  Visualizza il valore iniziale di x_flags.
004  Esegue un’operazione di XOR esclusivo sulla variabile per annullare il bit di controllo del formato decimale, quindi, con due operazioni di OR inclusivo, setta i nuovi bit di controllo ed infine passa la variabile alla funzione flags.
005  Visualizza il valore iniziale di x_flags con i nuovi settaggi.
006  Visualizza il nuovo valore della variabile x_flags.
007  Reimposta il formato standard dei flags di formattazione.
008  Visualizza il nuovo valore della variabile x_flags.
L’output di questo programma su una macchina MS-DOS è stato:

flgs  : 1
flgs  : 0x1
flags : 0xd1
flags : 0 
long ios::setf(long flags)
long ios::setf(long flags, long mask)
L’utilizzo della funzione setf() è meno problematico di quello della sua collega: la prima versione modifica i bit di formattazione settati ad 1 in flags e ritorna il vecchio valore della variabile; la seconda versione in­vece assegna ai bit di formattazione specificati da mask il valore dei bit corrispondenti in flags, ritornando il vecchio valore della variabile.
long ios::unsetf(long flags)
Questa funzione di formattazione azzera i flag di formattazione settati ad 1 in flags e ritorna il valore precedente della variabile. La caratteristica di setf() (in tutte e due le sue ver­sioni) di impedire il settaggio di flag in opposizione, fa sì che il suo uso non sia partico­larmente frequente.
5.9	manipolatori
Esiste anche un altro modo per modificare la formattazione dell’I/O delle classi stream e consiste nell’utilizzare particolari funzioni membro, dette manipolatori o gestori e defi­nite nel file iomanip.h. 
La differenza fra i manipolatori e le funzioni di gestione della formattazione che abbiamo appena esaminato, è che i manipolatori restituiscono un riferimento allo stream sul quale intervengono, quindi possono essere utilizzati in cascata, esattamente come gli operatori di inserimento ed estrazione. Attenzione, però, perché, anche se la loro sintassi è la stessa degli operatori << e >>, i manipolatori non effettuano nessun tipo di operazione di in­serimento o estrazione, bensì alterano le variabili di formattazione dello stream, modifi­candone il comportamento nel modo descritto nella tabella seguente:
Manipolatori 

Come vedete, esistono sette gestori non parametrizzati e sei che invece prevedono degli argomenti. I primi sono dichiarati nel file header iostream.h e non necessitano quindi di nessun’altra inclusione per poter essere utilizzati. I gestori parametrizzati, invece, hanno una struttura più complessa, dichiarata nel file header iomanip.h che deve essere perciò incluso in qualunque programma ne faccia uso. 
Nel caso vi stiate chiedendo a cosa mai possa servire un altro metodo di formattazione dell’output, eccovi un breve ma significativo esempio sull’utilizzo dei manipolatori:

MANIPTST.CPP - Utilizzo dei manipolatori
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	MANIPTST.CPP - Utilizzo dei manipolatori
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
#include <iomanip.h>						// 001
/////////////////////////////////////////////////////////////
void main()
{
 int num = 29 ;

	cout.fill('#') ;						// 002
	cout.width(8) ;						// 003
	cout << num << "\n";					// 004

	cout << setfill('.') << setw(7) << num ;		// 005
};
/////////////////////////////////////////////////////////////
001  Inclusione necessaria per utilizzare le versioni parametrizzate.
002  Definisce un carattere di riempimento.
003  Definisce una larghezza di output.
004  Visualizza il numero.
005  La stessa cosa, tutta in una linea di codice.
Come vedete, si ritorna sempre al solito discorso di rendere la vita il più facile possibile al programmatore. E per semplificarvela ancora di più (o complicarvela...), potete scriv­ere voi stessi i vostri manipolatori. 
Questa è la dichiarazione di un manipolatore che in­serisce nello standard stream di ouput il carattere ASCII 7:

ostream & beep (ostream & os)
{
	return os << '\a' ; 	//codice di escape per BELL
}
per scoprire a cosa serve, compilate ed eseguite il seguente esempio:

MANIPDU.CPP - Manipolatori definiti dall’utente
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	MANIPDU.CPP - Manipolatori definiti dall'utente
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
#include <iomanip.h>						
/////////////////////////////////////////////////////////////
ostream & beep (ostream & os)
{
	return os << '\07' ;
}
/////////////////////////////////////////////////////////////
void main()
{
	cout << "\nCosa succede?" << beep ;			
}
/////////////////////////////////////////////////////////////
Crearsi i propri manipolatori personalizzati può essere piuttosto utile e non è un compito particolarmente complesso se si tengono a mente alcune regole di base (ed a patto che ci si ricordi di includere nel codice il file iomanip.h ):
	i gestori hanno associatività da sinistra a destra, quindi per potere modificare la formattazione di una variabile, debbono precederla nell’istruzione di I/O:

int n = 33 ;
cout << n << hex ;	// ERRORE! non succede nulla
cout << hex << n ;	// OK
	il tipo di ritorno dev’essere un riferimento allo stream su cui si intervi­ene. Se state scrivendo un manipolatore che agisce su oggetti di classi derivate da istream  il tipo di ritorno dev’essere di tipo istream & ;
	il primo argomento dev’essere un riferimento allo stream che si deve manipolare (valgono le stesse considerazioni fatte sopra) ;
	oltre al riferimento allo stream, la funzione può avere solo un altro ar­gomento, che dev’essere obbligatoriamente o un int o un long .
5.10 stream per I/O su file
Come avevamo detto all’inizio del capitolo, le classi derivate da ios non permettono solo la gestione dell I/O standard da tastiera e su terminale, ma consentono di estendere i benefici dell’approccio orientato agli stream anche alla gestione dei files. 
Concettualmente, i files possono essere assimilati a degli stream: un file da cui si leggono dei dati è un caso particolare di stream di input, un file sul quale invece i dati vengono scritti è a tutti gli effetti un caso particolare di stream di output. Allo stesso modo, la classe ifstream, che si occupa dell’input da file è una specializzazione di istream, mentre la classe ofstream, che gestisce invece l’output, è derivata da ostream. Entrambe poi ereditano da fstreambase, una classe diretta discendente di ios, che fornisce metodi comuni per la gestione dei files e che, insieme ad iostream, serve da base per fstream. Quest’ultima è una classe che, com’è facilmente prevedibile, dati i natali, permette tanto operazioni di input che di output su file. 
Detto così è complicato come l’intreccio di una soap opera, ma forse lo schema seguente vi può aiutare un po’:

In quanto derivazioni di istream ed ostream, la maggior parte delle regole che si applicano agli stream di I/O su file sono sostanzialmente le stesse che abbiamo finora esaminato per gli stream di input ed output standard, qualche differenza però c’è. 
La prima è che, per per poter utilizzare queste classi, è necessario includere nel vostro sorgente il file fstream.h, le altre riguardano invece il modo in cui gli stream vengono dichiarati e collegati ai files. I metodi possibili sono (diamo per scontato che i nostri ven­tisei lettori siano abbastanza astuti da capire che quando ci riferiamo ad oggetti fstream intendiamo una qualunque delle tre classi per la gestione dei files):
	dichiarare un oggetto fstream senza parametri: in questo modo otten­tete uno stream privo di connessione a file (la connessione verrà fatta in seguito per mezzo della funzione membro open());

fstream unFile ;	// nessuna connessione con files
	dichiarare un oggetto fstream con un inizializzatore intero: l’intero dev’essere ovviamente una handle ad un file DOS aperto precedente­mente ;

ofstream aVideo(2); // associa lo stream con lo stdout
	dichiarare un oggetto fstream passando come parametri al costruttore una stringa ed una modalità di apertura: la stringa conterrà il nome del file da aprire, le modalità di apertura è un elemento dell’enumerazione ios::open_mode, che esamineremo tra breve.

ifstream is("a.dat", ios::in); // apre a.dat in lettura
In quest’ultimo caso, il secondo parametro passato al costruttore dell’oggetto, ios::in, definisce il modo in cui verrà aperto il file da associare allo stream. I valori possibili, così come sono dichiarati all’interno della classe ios, sono:

enum open_mode  
{
 in         = 0x01, // apre il file in lettura
 out        = 0x02, // apre il file in scrittura
 ate        = 0x04, // apre il file, quindi va alla sua fine
 app        = 0x08, // apre il file in modalità append
 trunc      = 0x10, // azzera il file se già esiste
 nocreate   = 0x20, // apre solo un file già esistente
 noreplace	= 0x40, // non apre un file esistente
 binary     = 0x80  // apre il file in modalità binaria
};
Le modalità ios::in è quella di default per la classe ifstream; ios::out, è il de­fault per ofstream. Per ottenere delle modalità particolari come, ad esempio, l’apertura di un file in input binario o in input ed output di un file che non dev’essere però sovras­critto se già esistente, si possono combinare fra loro i valori di open_mode con delle operazioni di OR logico:
fstream fs( "pippo.dat", ios::in | ios::binary);
fstream fs( "pippo.dat", ios::in | ios::out | ios::nocreate);
L’ultimo costruttore delle classi fstream ha anche un terzo parametro che defiisce la modalità di protezione per il file. La sua dichiarazione è infatti():
ifstream(const char* nome, int mode, int prot=ios::openprot);
Come noterete, però, il parametro prot ha un suo valore di default, ios::openprot, che, almeno per ora, è anche l’unico possibile, quindi potete tranquillamente ignorarlo. 

Orbene, dopo aver tanto parlato, eccovi un esempio che mostra tutti questi nostri nuovi amici all’opera:
FSTRTEST.CPP - Utilizzo delle classi fstream
/////////////////////////////////////////////////////////////
//
//  Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//  FSTRTEST.CPP - Utilizzo delle classi fstream
//
/////////////////////////////////////////////////////////////
#include "fstream.h"
#include "stdlib.h"
/////////////////////////////////////////////////////////////
void main()
{
 ifstream is ;                                        // 001
 fstream fs("iofile.dat",
            ios::out|ios::trunc|ios::binary ) ;       // 002

    if( ! fs )
	   cerr << "\nErrore in apertura file di output" ;

    is.open("fstrtest.cpp", ios::nocreate ) ;         // 003

    if( ! is )
        cerr << "\nErrore in apertura file di input" ;

    while(is)                                         // 004
    {
	unsigned char c ;
        
        is.get(c) ;                                   // 005
        if( ! is.good() )                             // 006
        {
		      if( is.eof())
			    cerr << "\nRaggiunta la fine del file" ;

			if( is.fail())
                cerr << "\nErrore irrecuperabile" ;

            if( is.bad() )                           // 007
            {
                cerr << "\nOperazione non valida" ;
	           is.clear() ;                         // 008
            }
        }
        else if( ! fs.put(c) )                       // 009
        {
            cerr << "\nErrore in scrittura" ;
            cerr << " posizione " << fs.tellg() ;
        }
}
/////////////////////////////////////////////////////////////
001  Apre un file stream di input senza associarlo a nessun file.
002  Apre un file stream generico in output binario. Se il file già esiste, lo azzera.
003  Associa l’oggetto ifstream con un file preesistente e lo apre.
004  Ripete il ciclo finché non ci sono errori.
005  Legge un carattere dal file di input.
006  Verifica che non ci siano problemi.
007  Se si è verificato un errore lieve...
008  ...resetta la variabile di stato.
009  Copia il carattere nel file di output.

Come spero l’esempio abbia chiarito, le funzioni di controllo, i manipolatori e gli opera­tori di inserimento ed estrazione, si possono applicare agli stream di I/O su file esatta­mente come avveniva per gli oggetti di classe iostream o ostream. 

La funzione open(), utilizzata alla riga 007, è una funzione membro che serve ad aprire un file colle­gandolo con uno stream precedentemente aperto. La sua dichiarazione, che ricorda molto quella del costruttore della classe fstream, è la seguente:
void open(char const*, int, int = filebuf::openprot) ;

L’altra funzione membro utilizzata nell’esempio è tellg(), che fstream eredita in secondo grado della classe istream. Ritorna la posizione della prossima operazione di estrazione () e la sua dichiarazione è:
long tellg() ;

5.11 POsizionamento negli stream di i/o su file
Simile alla funzione membro tellg(), è la funzione tellp(), che  fstream eredita da sua "nonna" ostream e che ritorna la posizione della prossima operazione di inseri­mento. Complementari a tellg() e tellp() sono, rispettivamente, seekg() e seekp(), che posizionano nel file ad una posizione relativa o assoluta. La tabella seguente riporta le dichiarazioni delle diverse funzioni:
Funzioni di posizionamento su stream

Le funzioni seekg(long pos) e seekp(long pos), posizionano la prossima op­erazione sullo stream all’indirizzo assoluto pos. 
Le versioni seekg(long pos,seek_dir) e seekg(long pos, seek_dir), spostano ad una posizione che è a pos bytes dal punto definito dal secondo argomento della funzione, che è un membro dell’enumerazione  seek_dir, definita, tanto per cambiare, all’interno della classe ios:

enum seek_dir 
{ 
	beg=0, 
	cur=1, 
	end=2 
};
L’effetto dei diversi parametri è il seguente:
	ios::beg: sposta la prossima operazione a pos bytes dall’inizio del file associato;
	ios::cur: si sposta a pos bytes dalla posizione corrente;
	ios::end: si sposta a pos bytes prima della fine del file.

-->
