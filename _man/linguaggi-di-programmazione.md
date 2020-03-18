---
layout:     manuale
class:      capitolo
title:      C'hi++ - Il senso della Vita è il debug
h2:         I linguaggi di programmazione
permalink:  /man/linguaggi-di-programmazione
precedente: sistemi-di-numerazione
seguente:   c-plus-plus
bozza:      true
---

<blockquote class="motto">
Tutto è byte.
</blockquote>

I linguaggi di programmazione servono a chiedere al computer di fare determinate 
operazioni.  
Perché il computer possa ubbidirci, deve "capire" che tipo di entità deve gestire 
e che tipo di operazioni deve compiere su di esse.
Per esempio, se chiedessimo al computer di raddoppiarci lo stipendio, il computer 
dovrebbe sapere almeno a quanto ammonta il nostro stipendio e come funziona una 
moltiplicazione per due.

```
long raddoppia(long stipendio)
{
    return stipendio * 2;
}
```

Siccome l'unica cosa che il computer conosce sono delle sequenze di 1 e di 0 
– siano esse su un disco, in memoria o sulla porta di comunicazione della 
tastiera o del video, – dobbiamo trovare il modo di "spiegargli" i concetti di
*stipendio* e *moltiplicazione* in forma binaria.	
I linguaggi di programmazione fanno precisamente questo: traducono le nostre 
richieste in un linguaggio che il computer può comprendere.

Noi percepiamo il mondo reale come un insieme di eventi che coinvolgono
una o più entità.
Ciascuna entità è identificabile per le sue caratteristiche fisiche e ha
un suo modo particolare di reagire agli stimoli esterni.  
Per descrivere le entità, i linguaggi di programmazione hanno i [tipi di
dato](/man/tipi-di-dato); per descrivere gli eventi,
hanno [istruzioni e operatori](/man/espressioni-e-operatori).
Un linguaggio di programmazione è tanto più efficace quanto più i suoi
tipi di dato e i suoi costrutti sintattici riescono a descrivere le
entità che il programma dovrà gestire.  

Ci sono molti linguaggi di programmazione.  
Ciascun linguaggio sa spiegare bene certe cose e meno bene certe altre.
Esistono linguaggi che descrivono bene le transazioni bancarie, ma che sono inadatti a gestire il treffico aereo; altri che funzionano molto bene per creare pagine Web, ma con cui sarebbe masochistico scrivere un sistema operativo.  

Un programmatore che conosce a fondo un certo linguaggio di
programmazione può utilizzarlo efficacemente per scrivere qualsiasi
programma, ma a quale prezzo?
Se il linguaggio di programmazione è inadatto a descrivere gli eventi
che interesseranno il programma, il programmatore dovrà preoccuparsi di
piegare o gli eventi o il linguaggio o entrambi per ottenere il
risultato atteso.
Scegliendo invece un linguaggio i cui tipi di dato e i cui costrutti
siano più affini alla realtà da descrivere, si risparmiano tempo e
fatica e si scrive un codice più affidabile.<br />
<br />
Pitagora sosteneva che “tutto è numero”, ma non è vero.
La matematica può descrivere gli eventi che si verificano nell'Universo,
ma non le loro cause o il loro fine.
In quest'ottica, la matematica è un “linguagggio di programmazone” inadatto.
Descrivere i sentimenti con la matematica è come cercare di descrivere
rigorosamente un sogno: si ottiene sempre una rappresentazione parziale.
Meglio descriverlo con una musica, lasciando che le suggestioni
siano implicite.
La matematica, inoltre, contiene preposizioni formalmente corrette che sono o false
o paradossali, come la radice quadrata di -1.<br />
Il Maestro Canaro sosteneva che i paradossi sono la crittografia di Dio.
Se fosse vero, la matematica sarebbe utile non perché quasi sempre è coerente,
ma perché, di quando in quando, produce dei paradossi.<br />
<br />
Bjarne Stroutsup, o forse Brian Kernigan, disse:

> L'unico modo di apprendere un linguaggio di programmazione è quello
di utilizzarlo per scrivere programmi.

Il maestro Canaro sosteneva che anche scrivere un
manuale su un linguaggio di programmazione è un buon sistema per
impararlo.

I linguaggi di programmazione possono essere di due tipi: *interpretati* o *compilati*.  
Posso spiegarti la differenza in questo modo: immagina di essere in Cina e di dover tornare al tuo albergo in taxi.
Se non parli il Cinese, ha due possibilità: o porti con te un interprete che
spieghi al tassista dove devi andare o ti fai dare dall'albergo un foglio di
carta con l'indirizzo e lo fai vedere al guidatore del taxi.
Entrambe le possibilità hanno lati positivi e negativi.  
Se scegli di portarti dietro un interprete avrai dei costi in più, ma sarai libero di andare dove vuoi: in albergo, in un ristorante o in un locale notturno.
Se invece opti per il foglio con l'indirizzo risparmierai i soldi dell'interprete, ma una volta salito in taxi, potrai solo tornare all'albergo.  
Con i linguaggi di programmazioni avviene la stessa cosa.
Il codice dei linguaggi interpretati viene letto da un programma chiamato: *interprete*, che traduce le istruzioni scritte dall'umano nel linguaggio del computer e le esegue.
Il codice dei linguaggi compilati, al contrario, viene letto da un programma chiamato *compilatore*, che lo converte in istruzioni comprensibili dal computer e scrive queste istruzioni in un nuovo file, detto: *eseguibile*.

Anche in questo caso ciascun metodo ha lati positivi e lati negativi.  
I linguaggi interpretati sono più lenti, perché il passaggio lettura/conversione/esecuzione si ripete ogni volta che il codice viene elaborato; inoltre, richiedono delle risorse di sistema in più da destinare all'interprete.
In compenso, ogni modifica al codice sorgente viene trasmessa contestualmente anche al programma in esecuzione.  
I linguaggi compilati sono più rapidi e richiedono meno risorse di sistema perché la compilazione avviene solo una volta, dopo di che il programma può essere eseguito autonomamente, ma se si modifica il codice sorgente, il programma dovrà essere ri-compilato per funzionare correttamente.<br />
<br />
Anche la religione è, da un certo punto di vista, un linguaggio di programmazione, perché consente agli umani di dialogare con Dio.
Il codice, in questo caso, è la preghiera, che i fedeli formulano e inviamo alla Divinità nella speranza che la esegua.
Anche le religioni possono essere o compilate o interpretate, a seconda che la comunicazione fra il fedele e Dio sia diretta o mediata da un Ordine sacerdotale.  


Tutti i linguaggi hanno una sintassi; tutti i linguaggi hanno dei tipi
di dato.
Solo pochissimi linguaggi hanno anche dei principî.  

<!--
@todo: Completare.
@body: I principi sono importanti, perché danno robustezza al linguaggio.
Avere dei principi non è limitativo.
Il C non ha principi, ma i suoi costrutti sono limitati ai tipi di dato
previsti.
Al contrario, il C++, che si basa sui principi dell'Object-oriented e
delle classi, ha una maggior duttilità e può adattare i suoi
costrutti a qualsiasi contesto.
Qui si possono riprendere i concetti visti nel Manfesto a proposito delle
ideologie dell'ultimo cinquantennio.

-->

Un giorno un discepolo chiese al maestro Canaro: "Maestro, con quale
tipo di arco si tira meglio?".
Il maestro rispose: "Con quello che utilizzi tutti i giorni".
Il discepolo chiese allora: "Maestro, questo vuol dire che si può
utilizzare uno strumento inadatto, purché si raggiunga lo scopo?".
Il maestro sorrise benevolmente e disse: "Ti prego, vai a meditare
sull'insensatezza delle tue domande mentre pulisci le latrine comuni."
<br />
Per molto tempo non riuscii a capire il comportamento del maestro
Canaro. Per un po', credetti che l'errore fosse quel "meglio" nella
prima domanda e che il maestro avesse dato una risposta volutamente
imprecisa allo scopo di portare alle estreme conclusioni un ragionamento
male impostato, ma mi sbagliavo.
La verità era che il maestro Canaro, come mi confessò lui stesso, stava
cercando di scaricare su qualcuno il suo turno di pulizia latrine e il
giovane e impetuoso discepolo gliene aveva dato occasione.
