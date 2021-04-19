---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Il preprocessore
permalink:  /man/preprocessore
quote:      Tutte le potenze, tranne quella di 1, crescono
---

Le direttive al preprocessore sono la caratteristica principale del C++.  

Negli esempi precedenti abbiamo visto alcune istruzioni particolari, perché hanno un carattere `#` all'inizio e non hanno un carattere `;` alla fine:

``` 
#include <iostream>

#define NO_ERRORI    0
#define NO_PARAMETRI 1
```

Queste istruzioni sono delle *direttive al pre-processore* e possono essere di tre tipi:

- direttive di inclusione;
- definizioni e macroistruzioni;
- direttive condizionali.

Le <a id="inclusione" 
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">direttive di inclusione</a> sono quelle che si utilizzano più comunemente e servono a importare nel codice le definizioni delle funzioni di libreria, delle macroistruzioni e dei simboli necessari per la corretta compilazione dei programmi.
Questi elementi, per comodità, sono isolati all'interno di alcuni file, detti *file di include*.
Quando il preprocessore incontra una direttiva `include`, la sostituisce con il contenuto del file a cui fa riferimento.
Per esempio, se più di un programma dovesse usare la Classe `Colore` o la struttura `ColoreRGB` che abbiamo utilizzato nel programma che visualizza la dimensione dei <a href="/man/tipi-di-dato#principali"> principali tipi di dato del C++</a>, questi dovrebbero essere isolati in un file separato con estensione `.h`, a indicare che si tratta di un *header file*:

```
{% include_relative src/preprocessore-colore.h %}
```

Il file verrebbe poi incluso nel codice dei programmi che ne fanno uso con una direttiva `include`:

```
{% include_relative src/preprocessore-main.cpp %}
```

Questo esempio utilizza due forme distinte per la direttiva `include`:

```
#include <iostream>
#include "colore.h" 
```

La prima forma serve a includere i file di sistema, come, appunto, `iostream`, che contiene le definizioni degli *stream* standard del C++; la seconda forma si utilizza per i file specifici dell'applicazione; nel nostro caso, `colore.h`.  
I file di include possono includere a loro volta altri file; per esempio, `colore.h` include `iostream`, perché utilizza lo *stream* `cout`.
Anche il nostro codice di esempio, però, include `iostream` e questo potrebbe causare un errore di compilazione se il precompilatore effettuasse due volte l'inclusione, perché sarebbbe come se dichiarassimo due volte la stessa funzione.
Per questo motivo, all'inizio del nostro file di include (ma anche di `iostream`) troviamo un altro tipo di diretttive al preprocessore, le cosiddette: 
<a id="condizionali"
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">direttive condizionali</a>:
   
```
#ifndef _CLASS_COLORE
#define _CLASS_COLORE 1

...

#endif /* _CLASS_COLORE */
```

Le direttive condizionali sono:

| direttiva | valore |
|---|---|
| `#if`     | se non zero
| `#ifdef`  | se definito
| `#ifndef` | se non definito
| `#else`   | altrimenti
| `#elif`   | altrimenti se
| `#endif`  | fine del blocco condizionale

Quando il preprocessore legge la prima direttiva nel file di include, verifica che sia definito un valore per `_CLASS_COLORE`.
Se `_CLASS_COLORE` non ha un valore associato, il preprocessore esegue l'istruzione successiva, che gli assegna il valore 1, poi inserisce nel file chiamante tutto il codice fino all'istruzione `#endif`.
Se invece `_CLASS_COLORE` ha già un valore associato perché è già stata inclusa da altri file, il preprocessore salta direttamente alla direttiva `#endif` senza riscrivere le tre dichiarazioni.

Le istruzioni seguenti definiscono delle costanti numeriche per i colori dell'`enum RGB`:

```
#define  RGB_RED    0xFF0000
#define  RGB_GREEN  0x00FF00
#define  RGB_BLUE   0x0000FF
```

Le direttvive al preprocessore permettono di definire anche delle costranti stringa:

```
#define  STR_GREEN  "verde"
```

Questa è una buona cosa, perché, come imparerai con l'esperienza, avere delle stringhe *hardcoded* all'interno dei programmi causa sempre dei problemi e soprattutto lega il tuo codice a un determinato linguaggio:

```
colore.coloreRgb.nome = "verde";     

/** Mostra il valore delle variabili */
cout << "booleano:"    << booleano   << endl;
cout << "carattere:"   << carattere  << endl;
cout << "intero:"      << intero     << endl;
cout << "decimale:"    << decimale   << endl;
cout << "array:"       << array      << endl;
```

Questo può essere accettabile in un programma di esempio, ma è una scelta miope per un programma reale, specie se le stringhe si ripetono in contesti diversi:

```
char stringa[] = "ebete";

...

cout << 6 << "ebete" << endl;

```

perché se la stringa dovesse variare (e stai pur certo che succederà), tu dovrai modificare tutte le righe di codice in cui compare.
Al contrario, se definisci delle costanti per tutte le stringhe che utilizzi nel tuo codice, la correzione sarà unica:

```
#define STR_COME_SEI = "astuto";

char stringa[] = STR_COME_SEI;

...

cout << 6 << STR_COME_SEI << endl;

```

Unite alle direttive condizionali, le definizioni di costanti stringa ti permettono di avere un codice multilingua:

```
#ifdef LANG_IT
    #define  STR_RGB    "colore RGB"
    #define  STR_RED    "rosso"
    #define  STR_GREEN  "verde"
    #define  STR_BLUE   "blu"
#else 
    #define  STR_RGB    "RGB color"
    #define  STR_RED    "red"
    #define  STR_GREEN  "green"
    #define  STR_BLUE   "blue"
#endif
```

La definizione della costante che determina la condizione (in questo caso, `LANG_IT`) può avvenire o nel codice del programma che include il file con definizioni:

```
#define LANG_IT
#include "colore.h"
```

o direttamente da riga di comando, come parametro di compilazione:

```
% g++ ./cpp/preprocessore-main.cpp -D LANG_IT -o ./out/esempio
% ./out/esempio                                               
  booleano: 0
 carattere: C
    intero: 1234567890
  decimale: 3.14
     array: abcdefghilmnopqrstuvz
colore RGB: verde
% g++ ./cpp/preprocessore-main.cpp -D LANG_EN -o ./out/esempio
% ./out/esempio                                               
   boolean: 0
 character: C
   integer: 1234567890
   decimal: 3.14
     array: abcdefghilmnopqrstuvz
RGB color: green
```

È possibile eliminare una `#define` precedentemente assegnata per mezzo della direttiva `#undef`:

```
#define LANG_IT
#include "preprocessore-colore.h"
#undef LANG_IT

#ifdef LANG_IT
    #define  STR_BOOL   "booleano"
    #define  STR_CHAR   "carattere"
    #define  STR_INT    "intero"
    #define  STR_DEC    "decimale"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "verde"
#else 
    #define  STR_BOOL   "boolean"
    #define  STR_CHAR   "character"
    #define  STR_INT    "integer"
    #define  STR_DEC    "decimal"
    #define  STR_ARRAY  "array"
    #define  STR_VERDE  "green"
#endif
```

L'output di questo codice, sarà:

```
% g++ src/cpp/preprocessore-main.cpp -D LANG_EN -o src/out/esempio
% ./src/out/esempio                                               
   boolean: 0
 character: C
   integer: 1234567890
   decimal: 3.14
     array: abcdefghilmnopqrstuvz
colore RGB: verde
```

<hr id="dottrina">

Le tre forze che regolano la vita dell'Universo &mdash; Gravità, Entropia e Annosa Dicotomia &mdash; non influenzano solo la fisica, ma anche l'etica. 
Esistono valori che potremmo definire: “entropici” e valori “gravitazionali”.
I valori legati all'Entropia sono quelli che tendono a disgiungere e a esaltare il singolo rispetto alla massa, come la libertà, la ricchezza, il successo o la fama; i valori legati alla Gravità sono quelli che, al contrario, uniscono gli individui, come l'*égalité* e la *fraternité* dei Francesi, ma senza la ghigliottina.  
<a href="/man/operatori#effimeri" class="xref">Ieri</a> abbiamo visto come i valori legati all'Entropia siano effimeri &mdash;  non potrebbe essere altrimenti, per una forza che tende alla disgregazione &mdash; e di come chi li persegua sia spesso vittima dell'Annosa Dicotomia, ma questo non vuol dire che li si debba ripudiare.
Non fare l'errore di pensare che ci sia una forza buona e una cattiva, come in *Star Wars*: sia la Gravità che l'Entropia sono necessarie per una corretta evoluzione dell'Universo.
Il Maestro Canaro, che anche in tarda età amava molto andare in bicicletta, una volta mi disse che l'equilibrio dell'Universo è come l'equilibrio di un ciclista che percorra una strada sterrata in salita: non deve tenere il peso troppo in avanti, perché altrimenti la ruota posteriore perderebbe trazione e comincerebbe a slittare, ma non deve nemmeno tenere il peso troppo indietro, perché altrimenti la ruota anteriore si alleggerirebbe e non sarebbe più possibile sterzare.  
Considerata la rispettabile quantità di cadute e contusioni collezionate dal Maestro Canaro nel corso delle sue escursioni in sella, ti consiglio di valutare solo il valore metaforico di questo insegnamento, ovvero che ci deve essere un bilanciamento fra Gravità ed Entropia, perché senza la Gravità, l'Universo è inutile, ma senza l'Entropia è noioso. 
In questo momento, l'Universo è in fase di espansione sotto l'influsso dell'Entropia ed è quindi normale che ci sia una preponderanza di azioni tendenti alla separazione.
Per mantenere l'equilibirio, quindi, bisogna incentivare le attività e i valori che tendono a riunire, come l'amore o l'arte.  
Molte persone pensano che amore e arte siano dei concetti vaghi e aleatorii, ma solo perché ne fraintendono l'essenza, ritenendoli dei concetti auto-esplicativi, che non occorre definire; qualcosa di simile alla definizione di “*pornografia*” che diede il Giudice Potter Steward, a proposito del film *Les Amants* di Louis Malle:

> I shall not today attempt further to define the kinds of material I understand to be embraced within that shorthand description; and perhaps I could never succeed in intelligibly doing so. But I know it when I see it, and the motion picture involved in this case is not that.<a href="/man/note/#steward" class="nota"></a>

Questo approccio entropico/soggettivo, per quanto corretto nel caso di *Les Amants*, è chiaramente sbagliato in termini generali: tutte le parole, anche quelle più comuni, possono essere interpretate in maniera differente da chi le ascolta o le utilizza. 
Così come la parola: <i id="pesce">pesce</i>, per quanto banale, può non avere lo stesso valore per un biologo marino, un ecologista o per un pescatore, anche la parola *arte* può assumere significati diversi per un gallerista, per un artista o per un Papa.  
È altrettanto sbagliata l'interpretazione entropico/romantica che comunemente si attribuisce alle parole: *amore* e *arte*.
L'amore non è il sentimento vago che ha fatto la fortuna di poeti, musici e letterati, ma uno stato (più o meno persistente) del nostro organismo in cui riteniamo che qualcuno o qualcosa sia più importante di noi stessi.
Di contro, l'Arte (ti prego di scrivere questo termine con l'iniziale maiuscola, nel tuo libro) non è l'esaltazione della personalità di un singolo, ma è &mdash; e dev'essere &mdash; la traccia del nostro cammino alla ricerca del Senso della Vita: Dio, per chi ci crede, o la Perfezione per i non credenti.
Approfondiremo quest'ultimo concetto <a href="/man/estetica" class="xref">in séguito</a>; qui e ora, come direbbe Céline Dion, *let's talk about love*.

--- 

Tutti noi agiamo in base a degli schemi di valori che determinano le nostre scelte. 
L'istinto di sopravvivenza, solitamente, ci spinge a porre la nostra persona al vertice di questa piramide, ma alle volte può capitarci di eleggere a nostro bene supremo qualcuno o qualcosa diverso da noi stessi.  
Quel senza Dio di Dawkins
<!-- Utilizzo questo appellativo in maniera affettuosamente canzonatoria: Dawkins ha cambiato il mio modo di vedere il Mondo o, almeno, parte di esso. Credo solo che faccia un errore di generalizzazione, ritenendo tutti i fedeli dei fanatici e dei bigotti. --> 
ha dimostrato come l'attaccamento che noi proviamo per i nostri parenti sia direttamente proporzionale al numero di cromosomi che condividiamo con essi e che quindi può essere riconducibile al desiderio primordiale di perpetuare il nostro patrimonio genetico<a href="/man/note/#selfish" class="nota"></a>. 
Questa interpretazione ribonucleica dell'amore funziona molto bene per i rapporti di sangue (padre/figlio, nonno/nipote, zio/nipote ecc.), ma non spiega l'amore fra mamma e papà o fra nonno e nonna &mdash; almeno, nelle famiglie che non ritengono l'incesto una pratica accettabile.  
L'*egoismo dei geni* non spiega nemmeno altre forme d'amore come l'amor di Patria, che spinge i giovani a sacrificare la propria vita in guerra,
<!--
La maggior parte dei soldati parte controvoglia perché costretta, ma la storia - e sfortunatamente anche i cimiteri -, sono pieni di esempii di giovani che si sono arrulati volontariamente. Boccioni ed Hemingway, per esempio, ma anche diversi ciclisti.
-->
l'amore per il prossimo, che porta il missionario a sacrificare la sua vita per aiutare i malati o l'amore per una forma di arte, uno sport o un lavoro. 
La realtà è che l'amore è una *backdoor*, o, meglio: una bomba a tempo, che viene inserita di nascosto nel tuo software, per essere certi che farai la cosa giusta quando arriverà il momento.  
L'amore è l'unica forza allo stesso tempo gravitazionale ed entropica.
Gravitazionale, perché unisce gli individui; entropica, perché li porta a riprodursi, replicando il loro DNA in qualcos'*altro*.
Ti spinge a restare in casa, davanti a una tela, uno spartito o un foglio bianco o ti fa uscire, su una sella, una pista o con una macchina fotografica in mano.
Ti porta in cima a una montagna o in una baraccopoli; al Polo o nel deserto; ti getta nel mare, ma non ti viene a salvare, come nella canzone; ti fa lasciare un lavoro sicuro perché non riconosci più la persona che vedi nello specchio la mattina o ti fa restare in un monastero, anche se.  
E questa è la parte facile; poi c'è l'amore fra gli individui.  
Ti sei mai innamorato?
No? be', succederà.
Ci sono due modi, di innamorarsi: o conosci una persona e te ne innamori o conosci una persona e scopri che è lei (o lui) che hai sempre amato.
Il primo è il caso più comune; il secondo caso, non è un caso.  
Il Maestro Canaro una volta disse (ma non credo fosse farina del suo sacco):

> Le donne cercano per tutta la vita il loro uomo ideale; nel frattempo, si sposano.

Questo è vero per tutti, uomini e donne.
Il tuo DNA contiene i geni che hanno fatto nascere l'amore fra i tuoi genitori: occhi verdi, spalle larghe, un bel seno o magari un bel sedere<a href="/man/note/#orologiaio" class="nota"></a>.
Allo stesso modo, dentro di te potrebbe esserci qualcosa che ti spingerà a cercare e ad amare una persona in particolare, perché quella persona è importante per la tua vita. 
Quando (se) la incontrerai, avrai l'impressione di conoscerla da sempre e capirai che tutte le volte che ti sei innamorato, ti sei innamorato di lei, anche se non la conoscevi ancora.
Sfortunatamente, questo non vuol dire che la vostra storia durerà o che vivrete per sempre felici e contenti, come nelle favole. Anzi.  
Il Cielo non è interessato alla tua felicità, ma al miglioramento, che, come ogni forma di crescita, ha il suo prezzo.
Tutti sanno che il Maestro Canaro risolse il *Koan Mu* in una notte di profondo dolore dopo la morte di un cane di nome Lele.
Molti, per ciò, ritengono il cane Lele un *Bodhisattva* che diede la vita per generare nel Maestro la prima scintilla dell'Illuminazione.
Hanno ragione, ma solo in parte, perché la morte del cane Lele fu solo una delle cause dell'amarezza di quella notte.
Il Maestro Canaro mi disse che buona parte del dolore era stato causato da una donna, che lui amava e dalla quale era stato ferito.
Il motivo per cui me lo raccontò è lo stesso per cui io lo sto raccontando ora a te: anni dopo, quando il Maestro aveva già definito le basi del C'hi++, lui tornò da quella donna e la ringraziò per il torto che gli aveva fatto, perché lo aveva messo nella condizione d'animo necessaria a capire qualcosa a cui altrimenti avrebbe potuto non arrivare mai.  
Ringraziare chi ci fa del bene con azioni gentili fa parte dell'educazione; ringraziare chi ci fa del bene attraverso il male non è facile, ma è necessario per far sì che quell'azione venga ripetuta anche nelle prossime esistenze.
