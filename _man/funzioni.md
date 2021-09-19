---
status:     pubblicato
layout:     manuale 
class:      capitolo
title:      Le funzioni
permalink:  /man/funzioni
quote:      "Call me: IsNull"
---

Le funzioni sono la caratteristica principale del C++.

Lo scopo delle funzioni è di migliorare la gestione del codice.
È possibile scrivere un programma che abbia solo la funzione `main`, ma questo ha un senso solo per programmi molto semplici, come alcuni degli esempii che abbiamo visto finora.
Il flusso di un programma *non banale*, come direbbe Stroutsup, sarà sempre suddiviso in più funzioni perché in questo modo il codice sarà più facile da leggere, da correggere e da modificare.  

```
{% include_relative src/tipi-di-dato-dimensione.cpp %}
```

Questo è il codice di un esempio che abbiamo visto nella lezione sui <a href="/man/tipi-di-dato">tipi di dato</a>.
Se decidessimo di modificare il modo in cui il programma mostra i dati all'utente, dovremmo intervenire su tutte le righe del programma, cosa che sarebbe noiosa e potrebbe generare degli errori.
Al contrario, se isoliamo la funzione di visualizzazione, le eventuali modifiche o correzioni dovranno essere applicate solo in un punto.
Il codice dell'esempio successivo è un esempio, perfettibile, di questo approccio:

```
{% include_relative src/tipi-di-dato-limiti.cpp %}
```
Ogni volta che nel tuo codice ci sono delle istruzioni che si ripetono, valuta la possibilità di isolarle in una funzione.
Per esempio, nella funzione `main` del programma qui sopra ci sono delle funzioni di output ripetute, cosa che complica la lettura del codice, ne rende laboriosa la modifica e aumenta la probabilità di fare degli errori, perché sei tu che definisci la stringa con il nome del tipo di dato e devi fare attenzione a scrivere il valore giusto ogni volta:

```
cout << setw(16) << "int: "; 
...
cout << setw(16) << "unsigned int: "; 
...
cout << setw(16) << "short int: "; 
...
cout << setw(16) << "unsigned short: "; 
...
cout << setw(16) << "long int: "; 
...
cout << setw(16) << "unsigned long: "; 
```

Nel caso specifico, si trattava di una scelta inevitabile perché, essendo uno dei primi esempii che ti ho fatto, non volevo complicarti troppo le idee, ma non è questo il modo corretto di scrivere codice.
È sbagliato (o, quanto meno, rischioso) mischiare elaborazione dei dati e funzioni di interfaccia, specie in questo caso, dove parte dell'output è già demandato a una funzione specifica.
Meglio lasciare che sia la funzione `dimensione` a gestire tutto l'output, mentre la funzione `main` si limiterà a definire il flusso dell'elaborazione, richiamando la funzione di output per i tipi di dato che ci interessano:

```
{% include_relative src/funzioni-limiti-modificato.cpp %}
```

L'istruzione: 

``` 
abi::__cxa_demangle(typeid(T).name(), NULL, NULL, NULL);
```

mostra il tipo di dato della variabile corrente.
Per il momento, accettala in maniera dogmatica; ti spiegherò il comportamento dell'operatore `::` quando parleremo delle classi.  
L'output di questo codice è identico a quello dell'esempio precedente; anzi: è un po' meglio, perché ho ridotto la spaziatura della prima colonna da 16 a 14 caratteri e l'ho fatto modificando solo un'istruzione `setw(14)`, contro le sei del codice precedente:

```
% g++ src/cpp/funzioni-limiti-modificato.cpp -o src/out/esempio
% src/out/esempio                                              
           int: 4 bytes, da:          -2147483648  a:           2147483647
         short: 2 bytes, da:               -32768  a:                32767
unsigned short: 2 bytes, da:                    0  a:                65535
          long: 8 bytes, da: -9223372036854775808  a:  9223372036854775807
 unsigned long: 8 bytes, da:                    0  a: 18446744073709551615
```

---

Le funzioni sono uno dei <a href="/man/tipi-di-dato#funzioni">tipi di dato</a> del C++ e, come tutti i tipi di dato, possono essere *dichiarate* e *definite*.  
La <a id="dichiarazione">dichiarazione</a> di una funzione stabilisce il suo tipo di ritorno e i parametri richiesti in input:

```
float scorporaIVA(long stipendio, float aliquota);
```

La <a id="definizione">definizione</a> di una funzione, ne stabilisce il comportamento:

```
float scorporaIVA(long stipendio, float aliquota)
{
    float valore;
    valore = stipendio / ((100 + aliquota) / 100);
    return valore;
}
```

Come ti ho detto quando abbiamo parlato dei <a href="/man/linguaggi-di-programmazione">linguaggi di programmazione</a>, la generazione di un file eseguibile avviene in due fasi: per prima cosa il compilatore converte il codice C++ in un *file oggetto*, poi il *linker* trasforma i file oggetto (potrebbero essere più d'uno) in un unico eseguibile. 
Perché questo processo possa funzionare, la *dichiarazione* di una funzione deve essere presente in tutti i brani di codice che la utilizzano, per consentire al compilatore di controllare che l'utilizzo che se ne fa sia corretto; la *definizione*, al contrario, deve comparire solo una volta.  

```
{% include_relative src/funzioni-stipendio-main.cpp %}
```

```
{% include_relative src/funzioni-stipendio-funz.cpp %}
```
Se compiliamo separatamente i due file qui sopra, aggiungendo il parametro `-c`, che dice al compilatore di generare solo il file oggetto senza richiamare il linker per la generazione di un eseguibile:

```
% g++ -c src/cpp/funzioni-stipendio-main.cpp -o src/out/main.o
% g++ -c src/cpp/funzioni-stipendio-funz.cpp -o src/out/funz.o
```
e poi generiamo un file eseguibile utilizzando i due file oggetto:

```
% g++ -o src/out/esempio src/out/main.o src/out/funz.o        
```
otterremo tre file, due *object-file* e il file eseguibile `esempio`, che darà il risultato atteso:

```
% ls -1 src/out                                               
esempio
funz.o
main.o

% src/out/esempio                                             
3000
```

Ma siccome io sono pigro, negli esempii che ti farò, utilizzerò sempre un comando unico per la compilazione e il *linking* dei programmi:

```
g++ src/cpp/funzioni-stipendio-funz.cpp  \                                                       
    src/cpp/funzioni-stipendio-main.cpp  \
    -o src/out/esempio
% src/out/esempio                                                                                 
3000
```

Se non dichiarassimo la funzione `raddoppiaStipendio` nel file che contiene la funzione `main`, il compilatore ci darebbe l'errore:

```
src/cpp/funzioni-stipendio-main.cpp:19:18: error: use of undeclared identifier 'raddoppiaStipendio'
    std::cout << raddoppiaStipendio(1500) << std::endl;                     ^
1 error generated.
```

Otterremmo lo stesso errore se definissimo una funzione dopo che un altra parte del programma l'ha richiamata:

```
{% include_relative src/funzioni-stipendio-errore.cpp %}
```

```
g++ -c src/cpp/funzioni-stipendio errore.cpp                                                    

src/cpp/funzioni-stipendio-errore.cpp:13:18: error: use of undeclared identifier 'raddoppiaStipendio'
    std::cout << raddoppiaStipendio(1500) << std::endl;    
                 ^
1 error generated.

```

Quando si scrive un programma in un unico file sorgente, o si definiscono le diverse funzioni prima che vengano utilizzate, mettendo la funzione `main` in fondo, oppure le si deve dichiarare all'inizio del file. 
(In realtà, non occorre metterle tutte all'inizio del file, basta che la dichiarazione preceda l'utilizzo, ma è più scomodo: mettile all'inizio.)  
Avresti ottenuto un errore di compilazione anche se avessi provato a separare in due file distinti la funzione `main` e la funzione `dimensione` dell'esempio qui sopra, anche se avessi dichiarato `dimensione` prima del suo utilizzo nella funzione `main`:

```
% g++ src/cpp/funzioni-limiti-main.cpp -c -o src/out/main.o         
src/cpp/funzioni-limiti-main.cpp:19:5: error: use of undeclared identifier 'dimensione'
    dimensione<int>();
    ^
src/cpp/funzioni-limiti-main.cpp:19:19: error: expected '(' for function-style cast or type construction
    dimensione<int>();
               ~~~^
src/cpp/funzioni-limiti-main.cpp:19:21: error: expected expression
    dimensione<int>();
                    ^
src/cpp/funzioni-limiti-main.cpp:20:5: error: use of undeclared identifier 'dimensione'
    dimensione<short int>();
    ^
src/cpp/funzioni-limiti-main.cpp:20:22: error: expected '(' for function-style cast or type construction
    dimensione<short int>();
               ~~~~~ ^
src/cpp/funzioni-limiti-main.cpp:21:5: error: use of undeclared identifier 'dimensione'
    dimensione<unsigned short>();
    ^
src/cpp/funzioni-limiti-main.cpp:21:25: error: expected '(' for function-style cast or type construction
    dimensione<unsigned short>();
               ~~~~~~~~ ^
src/cpp/funzioni-limiti-main.cpp:22:5: error: use of undeclared identifier 'dimensione'
    dimensione<long int>();
    ^
src/cpp/funzioni-limiti-main.cpp:22:21: error: expected '(' for function-style cast or type construction
    dimensione<long int>();
               ~~~~ ^
src/cpp/funzioni-limiti-main.cpp:23:5: error: use of undeclared identifier 'dimensione'
    dimensione<unsigned long>();
    ^
src/cpp/funzioni-limiti-main.cpp:23:25: error: expected '(' for function-style cast or type construction
    dimensione<unsigned long>();
               ~~~~~~~~ ^
```

Questo avviene perché i `template` non sono vere funzioni, ma solo degli schemi che il compilatore utilizza per generare la versione corretta del codice.
La dichiarazione delle funzioni template, quindi deve comprendere anche la loro definizione, per dare modo al compilatore di gestire appropriatamente la chiamata<a class="nota" href="/man/note#template"></a>.

<hr id="inline">

Prima ti ho detto di *valutare* la possibilità di isolare in una funzione le istruzioni che si ripetono all'interno del tuo codice, perché non sempre creare una funzione è la scelta corretta.  
Il software, come molte attività umane, è il frutto di una serie di compromessi e tu dovrai fare scelte architetturali differenti a seconda del tipo di programma che devi realizzare.
Un buon software, oltre che funzionare correttamente, dovrebbe essere veloce, facile da modificare e richiedere poche risorse di sistema.
Alle volte, però, si deve sacrificare una di queste caratteristiche positive per esaltarne un'altra.
Per esempio, se dovessi scrivere un software estremamente veloce, potrebbe essere meglio avere delle istruzioni duplicate che delle chiamate a funzione, perché richiamare una funzione causa inevitabilmente dei rallentamenti.
<!-- @todo: spiegare perché; o qui o in una nota -->
Però, se replichi delle istruzioni, non solo aumenti le dimensioni del programma, ma lo rendi anche più difficile da leggere e da modificare, che è male.  
In questi casi, l'aumento delle dimensioni del codice è inevitabile, ma le *funzioni inline* ti permettono di mantenere il codice leggibile e modificabile:

```
{% include_relative src/funzioni-inline-1.cpp %}
```
<!-- @todo: spiegare cosa sia la classe ofstream  -->
Compilando ed eseguendo il codice qui sopra, ottieni:

```
% g++ src/cpp/funzioni-inline-1.cpp -o src/out/esempio
% ./src/out/esempio                                   
ho aperto il file 
ho scritto sul file
ho chiuso il file
```

Le istruzioni di output nell'esempio si differenziano solo per il testo da visualizzare e potrebbero benissimo essere isolate in una funzione autonoma.

```
{% include_relative src/funzioni-inline-2.cpp %}
```

L'output di questo programma è identico a quello dell'esempio precedente, ma se aggiungi la parola chiave `inline` prima del tipo di ritorno della funzione `log`:

```
inline void log(const char* messaggio)
{
    /** Mostra il messaggio a video */
    cout << messaggio << endl;
}
```

 e compili nuovamente il programma, vedrai che la dimensione del file eseguibile è aumentata, perché il compilatore ha sostituito tutte le chiamate a funzione con una copia del codice della funzione stessa.
<!-- @todo: specificare che il compilatore può decidere di non rendere inline la funzione -->
Anche se le dimensioni dell'eseguibile sono aumentate, il codice è ancora facilmente leggibile e modificabile: 

```
{% include_relative src/funzioni-inline-3.cpp %}
```

Se compili il codice e lo esegui, ottieni:

```
% g++ src/cpp/funzioni-inline-3.cpp -o src/out/esempio

% src/out/esempio                                     
 errore: specificare il path del file

% src/out/esempio /esempio.txt                        
 errore: impossibile aprire il file

% src/out/esempio src/out/esempio.txt                 
 avviso: ho aperto il file
  debug: ho scritto sul file
 avviso: ho chiuso il file
 ```

Per la cronaca: nel secondo caso, il programma fallisce perché l'utente non ha privilegi di scrittura nella *root-directory*.

---

L'esistenza di una funzione `inline` ricorda un po' un passo del <i>Samyutta Nikaya</i>:

 > Non esiste distinzione fra un essere, la sua funzione e il tempo della sua apparizione. Gli esseri appaiono dalla non-esistenza, esistono per un istante e poi cessano di esistere. La loro esistenza, attività e azione sono un'unica cosa. Passato e futuro sono meri nomi.<a class="nota" href="/man/note#samyutta"></a>

In generale, comunque, il ciclo di vita di una funzione prevede tre fasi distinte: la *dichiarazione*, la *definizione* e il suo successivo utilizzo:

```
/** Dichiarazione */
float raddoppiaStipendio(float stipendio);

/** Definizione */
float raddoppiaStipendio(float stipendio)
{
    return stipendio * 2;
}

/** Chiamata */
float importo = raddoppiaStipendio(1500);

```

Solo la funzione `main` fa eccezione a questa regola, perché non richiede una dichiarazione e non viene richiamata da altre funzioni.
<!-- Qui si potrebbe fare un parallelo con gli elementi costitutivi dell'Universo, secondo lo Spazionismo, ma preferisco separare la dottrina dal manuale C++ vero e proprio -->
La variabile `float stipendio`, che compare fra parentesi sia nella dichiarazione che nella definizione della funzione, viene detta: *parametro* della funzione.
Il valore `1500` che viene attribuito al parametro nella chiamata a funzione, è detto: *argomento*.
Queste variabili sono chiamate anche: *parametri formali*, nel caso della dichiarazione e della definizione e: *parametri attuali*, nel caso della chiamata.  
Quando richiami una funzione, le puoi passare gli argomenti in tre modi: per *valore*, per *riferimento*, per *puntatore*:

```
{% include_relative src/funzioni-argomenti.cpp %}
```

L'output di questo programma è:

```
% g++ src/cpp/funzioni-argomenti.cpp -o src/out/esempio
% src/out/esempio                                      
Valore iniziale: x=11, y=22
      perValore: x=11, y=22
 perRiferimento: x=22, y=11
   perPuntatore: x=11, y=22
```

Passare la *reference* a una variabile come argomento di una funzione equivale a passarle la variabile stessa.
Questo può essere un bene nel caso di funzioni che richiedano in input oggetti di grosse dimensioni o che abbiano la necessità di modificare direttamente il valore delle variabili passategli come parametri, ma va evitato in qualsiasi altro caso, perché permette al programma di modifi­care il valore di una variabile in maniera subdola, che può essere molto difficile da scoprire in caso di errori.  
Un'altra cosa da sapere, a proposito dei parametri delle funzioni, è che possono avere dei valori di default:

```
{% include_relative src/funzioni-parametri-default.cpp %}
```
L'output di questo programma sarà:

```
% g++ src/cpp/funzioni-parametri-default.cpp -o src/out/esempio
% src/out/esempio 
Valore: 123
Valore: 0
```

Il valore di default del parametro deve essere indicato nella dichiarazione della funzione.
Ricordati però che, quando si assegna un valore di default a uno dei parametri di una funzione, bisogna fare altrettanto con tutti i parametri che lo seguono, se ce ne sono:

```
void funz1(float f, void * ptr = NULL);        // OK
void funz2(double d, int b = 2, char c = 'c'); // OK
void funz3(int i = 3, int n );                 // ERRORE!
```

I valori di default si utilizzano quando a uno o più parametri della funzione è assegnato spesso un determinato valore.
Per esempio, se la funzione `log` che abbiamo visto nell'esempio precedente fosse richiamata prevalentemente con uno stesso valore per il parametro `livello`, glielo si potrebbe assegnare come default:

```
inline void log(const char* messaggio, int livello = LOG_AVVISO);
```

rendendo la scrittura del codice più facile e veloce: 

```
log("ho aperto il file");

doc << "Testo del documento.\n";
log("ho scritto sul file", LOG_DEBUG);

doc.close();
log("ho chiuso il file");
```

<hr id="parametri-variabili">

In una delle nostre [prime chiacchierate](/man/programmatore), ti ho detto che il Buon Programmatore, mentre scrive il codice, si chiede sempre se possa esistere sistema più efficiente di fare ciò che sta facendo.
Oggi ne hai avuto una dimostrazione: abbiamo migliorato il primo esempio del paragrafo sulle funzioni `inline` unificando la gestione dei messaggi in un'unica funzione e poi l'abbiamo migliorato ancora rendendo quella funzione `inline`. 
C'è un problema, però: l'output del programma:

```
% ./src/out/esempio                                   
ho aperto il file 
ho scritto sul file
ho chiuso il file
```

va bene solo se il file da gestire è uno solo, come nel nostro caso. 
Se però ci fossero due (o più) file di input o di output, sarebbe utile sapere a *quale* file si riferisca il messaggio.
Per risolvere il problema, potremmo aumentare il numero di parametri formali della funzione `log`:

```
void log(int livello, const char* messaggio, const char* file);
```

ma il nuovo parametro sarebbe inutile nel caso di chiamate come:

```
log(LOG_ERRORE, "specificare il path del file");
```

In alternativa, potremmo definire il messaggio all'interno della funzione chiamante:

```
string s1 = "ho chiuso il file: ";
string s2 = filename;
string s3 = s1 + s2;
log(LOG_AVVISO, s3.c_str());
```

ma questo renderebbe il codice più pesante, più complicato e più lento; inoltre, trasferirebbe nelle funzioni chiamanti parte delle funzionalità di output che avevamo felicemente isolato nella funzione `log`.    
La soluzione corretta per questo tipo di problemi sono le *funzioni con parametri variabili*.  
Un esempio tipico di questo tipo di funzioni lo abbiamo visto con la funzione del linguaggio C `printf`, che ha un primo argomento che serve a determinare il tipo e il numero degli argomenti che seguono:

```
/** Dichiarazione, nel file stdio.h */
int printf(const char *format, ...) ;

/** Utilizzo */
printf("stringa: %s; intero: %d", "codice errore", -1);

``` 

Per indicare degli argomenti variabili, nella dichiarazione di una funzione, si utilizzano tre punti, dopo i parametri fissi:

```
void log(int livello, int n_parametri, ...);
```

Nella definizione della funzione, per gestire i parametri, è necessario creare un ciclo di lettura utilizzando tre marco definite nel file `stdarg.h`:

```
void va_start(va_list ap, lastfix);
type va_arg(va_list ap, type);
void va_end(va_list ap);
```

`va_start` inizializza la lista di variabili `ap` affinché possa ricevere gli argomenti variabili; il parametro `lastfix` specifica quale sia l'ultimo parametro fisso della funzione.

`va_arg` torna il successivo parametro nella lista `ap`; il parametro `type` indica il tipo di dato del parametro.

`va_end` termina l'elaborazione dei parametri e deve essere sempre chiamata prima che la funzione termini.


```
{% include_relative src/funzioni-variabili.cpp %}
```

L'output di questo codice è:

```
% g++ src/cpp/funzioni-variabili.cpp -o src/out/esempio

% src/out/esempio                    
  errore | specificare il path del file

% src/out/esempio /esempio.txt 
  errore | impossibile aprire il file:/esempio.txt

% src/out/esempio src/out/esempio.txt
  avviso | ho aperto il file: src/out/esempio.txt
   debug | ho scritto sul file: src/out/esempio.txt
  avviso | ho chiuso il file: src/out/esempio.txt```
```

<!-- @todo: Aggiungere un paragrafo sui valori di default per i parametri -->

---

A questo punto, non mi resta che parlarti delle funzioni che richiamano sé stesse, ovvero, le *funzioni ricorsive*:

```
{% include_relative src/funzioni-ricorsiva.cpp %}
```
Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/funzioni-ricorsiva.cpp -o src/out/esempio
> src/out/esempio                                      
 1 2 3 4 5 6 7 8 9
```

Attenzione, però: una funzione che richiama sé stessa, se non è scritta bene, può generare una ricorsione in[de]finita, come due specchi posti l'uno di fronte all'altro.
Lo spazio prospettico all'interno degli specchi è inesauribile, ma la memoria dei computer, per quanto estesa, ha i suoi limiti e un numero eccessivo di ricorsioni potrebbe generare uno *stack overflow*.<a href="/man/note#stack" class="nota"></a> 
Per questo motivo, bisogna ricorrere alla ricorsione solo nei casi in cui è indispensabile, preferendole, quando possibile, le [istruzioni iterative](https://chiplusplus.org/man/istruzioni-iterative) e applicando sempre dei meccanismi di controllo della profondità di ricorsione che prevengano un sovraccarico dello stack.  
Un altro tipo di ricorsione di cui diffidare è quella con cui si cerca, alle volte, di dare credibilità a una convinzione priva di fondamenti reali utilizzando un'altra convinzione simile.   

<hr id="dottrina">

In un romanzo sulla vita dello spadaccino giapponese Myamoto Musashi c'è una frase che è la logica conseguenza del suggerimento di Jacopone da Todi:

>Non bisogna interferire nel funzionamento dell’Universo, ma prima è necessario capire quale sia, il funzionamento dell’Universo<a href="/man/note/#musashi" class="nota"></a>

Il problema dei romanzi è che ti dicono spesso cosa fare, ma non ti spiegano quasi mai come farlo, o perché.  
Diffida dei maestri che sanno solo insegnare, perché tutto ciò che ti raccontano l'hanno imparato dai libri.
Un buon maestro deve eccellere in qualcosa, che sia la scherma, il tiro con l'arco, la carpenteria o la manutenzione delle motociclette.
Può non essere *il* migliore, ma deve essere *fra i* migliori; solo così, saprai che le sue idee sono valide.
Al contrario, i maestri che non sono mai usciti da una scuola, non hanno mai dovuto mettere le loro idee alla prova dei fatti.
Ti insegnano ciò che pensano sia giusto, ma ciò che è giusto o vero in una scuola, non sempre è altrettanto vero o giusto nel mondo reale.  
È facile essere dei santi, in un monastero, fra persone che hanno la tua stessa cultura<!-- qui, in senso letterale --> e i tuoi stessi principii; il difficile è restare dei santi anche fuori. 
Il Buddha Shakyamuni predicò la Benevolenza Universale perché visse in India, duemilaseicento anni fa, ma se fosse rimasto imbottigliato nel traffico di una città, dopo una giornata di lavoro, forse le sue idee sarebbero state più simili a quelle di Nietzsche.  
Per fortuna, Musashi &mdash; quello vero, il Samurai &mdash;, fu sempre molto chiaro sia su ciò che è giusto fare che sul modo di ottenerlo. 
Nel *Libro dei Cinque Anelli*, diede ai suoi discepoli nove regole di vita:
<!-- 
 @todo: verificare la traduzione di questi punti e dei successivi 
 @nota: uso il nome (Musashi) in vece del cognome (Myamoto), così come direi "Raffaello" o "Michelangelo".
-->

> {{ site.data.citazioni.musashi.cinque-anelli.regole }}

Nel *Dokkodo*, scritto una settimana prima della sua morte, fu ancora più specifico:

> {{ site.data.citazioni.musashi.dokkodo }}

Queste regole, che hanno permesso a Musashi di arrivare alla venerabile età di sessant'anni<a href="/man/note/#eta" class="nota"></a>, dopo essere sopravvissuto vittorioso ad altrettanti combattimenti con tutti i migliori spadaccini del suo tempo, possono aiutarti a capire quale sia il funzionamento dell'Universo e cosa fare per non perturbarlo.  
La pratica delle arti, siano esse intellettuali o marziali, e la conoscenza dei mestieri, unite all'attenzione per tutto ciò che ti circonda, aumenteranno il tuo bagaglio di esperienza e ti permetteranno di distinguere i pro e i contro di ogni situazione.
Questo ti libererà dal demone dell'invidia, perché imparerai che tutte le  condizioni, anche quelle apparentemente idilliache, hanno dei lati negativi.
Il passo successivo sarà affrancarsi dal desiderio e dall'attaccamento alle cose: così come la funzione `log` ha bisogno di sapere quali siano i parametri fissi e quali siano quelli variabili, tu dovrai imparare a distinguere i tuoi desiderii dalle tue necessità, per sfuggire all'influsso dell'Annosa Dicotomia.  
La Via, con la "V" maiuscola è simile a una via con la "v" minuscola.
Lungo la via, incontri dei cartelli stradali, che ti indicano la direzione in cui procedere o la velocità da tenere, e dei cartelloni pubblicitarii, che ti segnalano delle attrazioni nelle vicinanze e ti invitano a deviare dal tuo cammino per andarle a visitare.
Allo stesso modo, lungo la Via, troverai delle necessità, che ti instraderanno verso la tua destinazione e dei desiderii, che ti dis-trarranno dal tuo percorso e ti at-trarranno verso destinazioni alternative.
Se tu agirai in base alle necessità, saprai sempre che ti stai muovendo nella direzione giusta, anche quando sarai costretto a rallentare o a percorrere strade che non gradisci.
Se invece agirai in base ai desiderii andrai di qua e di là, come “un asino privo di briglie”<!-- @todo: cercare la citazione da Attar --> e quando alla fine tornerai sulla strada giusta, potresti non avere più il tempo per arrivare alla tua destinazione.

---

Ti ho parlato delle regole di Musashi non perché siano le uniche disponibili, ma perché sono estremamente personali.
Attingono ai principii di altre discipline, come il Buddismo, il Bushido o il Tao, ma sono *something else*, come direbbe Eddie Cochran.
Tu dovrai fare altrettanto: imparare tutto ciò che puoi, tanto dai buoni quanto dai cattivi maestri, e poi definire le tue regole di vita, che potranno essere uguali, simili o del tutto differenti da quelle che ti sono state insegnate.   
La Via, così come la Verità, è una modella, che ciascuno di noi ritrae dal suo punto di vista, cercando di intuire il corpo che si cela dietro alle pieghe del drappeggio. 
Ritrarla nello stesso modo in cui l'ha fatto un altro sarebbe sbagliato, perché il tuo punto di vista non è uguale al suo, ma guardarla da più punti di vista può aiutarti a capire meglio la sua forma.
Musashi dice di prestare attenzione anche alle cose insignificanti, Nan-in e Tenno sviluppano il loro *Zen di ogni istante*, Wittgenstein nei suoi *Diari*, scrive:

> {{ site.data.citazioni.wittgenstein.diari }}

È chiaro che stanno tutti dipingendo la stessa immagine, anche se ciascuno lo fa con il suo stile.
È per questo motivo, che Musashi prescrive di conoscere la Via degli altri mestieri: perché c'è sempre qualcosa da imparare, da chi fa bene il suo lavoro. 
Questo, per esempio, è il parallelo che lui fa fra lo stratega e il carpentiere:

> {{ site.data.citazioni.musashi.cinque-anelli.carpentiere }}<a href="/man/note/#5anelli" class="nota"></a>
 
Ciò che è vero per il carpentiere, cambiando il punto di vista, è vero anche per lo stratega e potrà esserlo anche per te, se ti troverai ai gestire un progetto o un gruppo di lavoro.
Anche come programmatore, comunque, dovrai tenerti costantemente aggiornato sulle tecniche e sui linguaggi di programmazione e dovrai conoscere il modo in cui lavora chi si occupa delle basi-dati o dei sistemi.
Dovrai essere capace di identificare i malfunzionamenti anche se non hanno effetti sull'interfaccia grafica e potrai riuscirci solo se presterai attenzione anche al più piccolo dettaglio.
Cambiano i nomi, perché sono passati quattro secoli, ma i problemi restano gli stessi, così come le soluzioni.  
Del resto, arte, scienza, filosofia e religione sono tutti tentativi di dare una risposta alle stesse domande sulla nostra esistenza. 
Dato che l'oggetto di studio è lo stesso, è più che normale che, alle volte, le risposte si somiglino, allo stesso modo in cui l'algoritmo per il calcolo del fattoriale di un numero sarà più o meno lo stesso, indipendentemente dal linguaggio di programmazione.  


<!--

aggiungere i 10C rivisti dal Maestro Canaro
specificare che quando aveva redatto la prima versione era un "angy young man", come direbbe Santillana, ma che poi aveva capito che le religioni sono come le opere teatrali e non le si può giudicare in base alle capacità degli attori.


-->
