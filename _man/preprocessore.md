---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Il preprocessore
permalink:  /man/preprocessore
quote:      ""
---

Le direttive al preprocessore sono la caratteristica principale del C++.  

Negli esempi precedenti abbiamo visto alcune istruzioni particolari, perché hanno un carattere `#` all'inizio e non hanno un carattere `;` alla fine:

``` 
#include <iostream>

#define NO_ERRORI    0
#define NO_PARAMETRI 1
```
<!-- @todo - verificare come mai questo brano di codice non appaia formattato correttamente in Chrome, Opera e Firefox mentre è visualizzato correttamente da Safari. Il font è monospace e l'allineamento del paragrafo è a sinistra -->

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

L'amore è un difetto di fabbrica.  
Più che un difetto, è una bomba a tempo, che viene inserita di nascosto nel tuo software, per essere certi che farai la cosa giusta quando arriverà il momento.
Ti sei mai innamorato?
No? be' succederà.
Ci sono due modi, di innamorarsi: o conosci una persona e te ne innamori o conosci una persona e scopri che è lei (o lui) che hai sempre amato.
Il primo è il caso più comune; il secondo caso, non è un caso.  
Il Maestro Canaro una volta disse (ma non credo fosse farina del suo sacco):

> Le donne cercano per tutta la vita il loro uomo ideale; nel frattempo, si sposano.

Questo è vero per tutti, uomini e donne.
Il tuo DNA contiene i geni che hanno fatto nascere l'amore fra i tuoi genitori: occhi verdi, spalle larghe, un bel seno o magari un bel sedere<a href="/man/note/#dawkins" class="nota"></a>.
<!-- 
Utilizzo questa idea perché mi fa comodo e perché è bello pensare che nel nostro DNA ci sia anche ciò che ha fatto innamorare i nostri genitori, ma personalmente, non concordo con le conclusioni di Dawkins - almeno, nel modo in cui sono esposte nel libro: la scelta del compagno avviene in base a un'analisi delle sue probabilità di essere un buon padre (nel senso di: "sano") o su fattori genetici? Che esistano dei geni che spingono le femmine a ricercare maschi sani mi sembra una forzatura..
-->
Allo stesso modo, dentro di te potrebbe esserci qualcosa che ti spingerà a cercare e ad amare una persona in particolare, perché quella persona è importante per la tua vita. 
Quando (se) la incontrerai, avrai l'impressione di conoscerla da sempre e capirai che tutte le volte che ti sei innamorato, ti sei innamorato di lei, anche se non la conoscevi ancora.
Sfortunatamente, questo non vuol dire che la vostra storia durerà o che vivrete per sempre felici e contenti, come nelle favole. Anzi.  
Il Cielo non è interessato alla tua felicità, ma al miglioramento, che, come ogni forma di crescita, ha il suo prezzo.
Tutti sanno che il Maestro Canaro risolse il *Koan Mu* in una notte di profondo dolore dopo la morte di un cane di nome Lele.
Molti, per ciò, ritengono il cane Lele un *Bodhisattva* che diede la vita per generare nel Maestro la prima scintilla dell'Illuminazione.
Hanno ragione, ma solo in parte.
La morte del cane Lele fu solo una delle cause dell'amarezza di quella notte.
Il Maestro Canaro mi disse che buona parte del dolore era stato causato da una donna, che lui amava e dalla quale era stato ferito.
Il motivo per cui me lo raccontò è lo stesso per cui io lo sto raccontando ora a te: anni dopo, quando il Maestro aveva già definito le basi del C'hi++, lui tornò da quella donna e la ringraziò per il torto che gli aveva fatto, perché lo aveva messo nella condizione d'animo necessaria a capire qualcosa a cui altrimenti avrebbe potuto non arrivare mai.  
Ringraziare chi ci fa del bene con azioni gentili fa parte dell'educazione; ringraziare chi ci fa del bene attraverso il male non è facile, ma è necessario per far sì che quell'azione venga ripetuta anche nelle prossime esistenze.


<!--
@todo: non so se abbia senso aggiungere questo brano, visto che si parla di bombe a tempo; lo lascio quì, mentre decido.

---
Ti lascio andare, ora: ho saputo di tuo padre

La perdita di un genitore è un evento doloroso, ma naturale; perfino auspicabile, per certi versi, visto che l'evento opposto, ovvero la morte del generato, è un sovvertimento delle Leggi naturali così ingiusto che non si è voluto nemmeno assegnare un nome allo stato che ne consegue, quasi che, de-nominandolo, lo si potesse in qualche modo esorcizzare.
Quando il dolore passa e rimane quello che, con una figura forse banale, ma veritiera, si potrebbe definire: *un affettuoso ricordo*, si scopre una curiosa caratteristica di questo particolare tipo di mancanza: non è totale.
Mentre la morte di un amico è qualcosa di definitivo, che ti priva del tutto e per sempre di tutto ciò che lui era e rappresentava nella tua vita, un genitore non scompare mai del tutto, perché parte di ciò che lui era è dentro di te, come una bomba a tempo innescata al momento del tuo concepimento.
Senza rendertene conto, ti troverai a fare dei gesti che erano i suoi o a comportarti o a pensare o a parlare così come si comportava o pensava o parlava lui.
Questo non lo riporterà in vita, ovviamente, nè renderà piu' lieve la sua mancanza, ma in qualche modo ti farà sentire che cio' che è stato non è svanito nel nulla. 

Non del tutto, almeno.
-->
