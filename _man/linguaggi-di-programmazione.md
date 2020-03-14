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

I linguaggi di programmazione servono a spiegare ai computer com'è fatto
il mondo reale.
Ci sono molti linguaggi di programmazione.
Ciascun linguaggio sa spiegare bene certe cose e meno bene certe altre.
Noi percepiamo il mondo reale come un insieme di eventi che coinvolgono
una o più entità.
Ciascuna entità è identificabile per le sue caratteristiche fisiche e ha
un suo modo particolare di reagire agli stimoli esterni.
Per descrivere le entità, i linguaggi di programmazione hanno i [tipi di
dato](/man/tipi-di-dato); per descrivere gli eventi,
hanno [istruzioni e operatori](/man/espressioni-e-operatori).
Un linguaggio di programmazione è tanto più efficace quanto più i suoi
tipi di dato e i suoi costrutti sintattici riescono a descrivere le
entità che il programma dovrà gestire.<br />
<br />
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
<br />
Bjarne Stroutsup, o forse Brian Kernigan, disse:

> L'unico modo di apprendere un linguaggio di programmazione è quello
di utilizzarlo per scrivere programmi.

Il maestro Canaro sosteneva che anche scrivere un
manuale su un linguaggio di programmazione è un buon sistema per
impararlo.<br />
<br />
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
siano implicite.<br />
<br />
La matematica contiene preposizioni formalmente corrette che sono o false
o paradossali, come la radice quadrata di -1.<br />
Il Maestro Canaro sosteneva che i paradossi sono la crittografia di Dio.
Se fosse vero, la matematica sarebbe utile non perché quasi sempre è coerente,
ma perché, di quando in quando, produce dei paradossi.<br />
<br />
Un giorno un discepolo chiese al maestro Canaro: "Maestro, con quale
tipo di arco si tira meglio?".
Il maestro rispose: "Con quello che utilizzi tutti i giorni".
Il discepolo chiese allora: "Maestro, questo vuol dire che si può
utilizzare uno strumento inadatto, purché si raggiunga lo scopo?".
Il maestro sorrise benevolmente e disse: "Ti prego, vai a meditare
sull'insensatezza delle tue domande mentre pulisci le latrine comuni."<br />
Per molto tempo non riuscii a capire il comportamento del maestro
Canaro. Per un po', credetti che l'errore fosse quel "meglio" nella
prima domanda e che il maestro avesse dato una risposta volutamente
imprecisa allo scopo di portare alle estreme conclusioni un ragionamento
male impostato, ma mi sbagliavo.
La verità era che il maestro Canaro, come mi confessò lui stesso, stava
cercando di scaricare su qualcuno il suo turno di pulizia latrine e il
giovane e impetuoso discepolo gliene aveva dato occasione.
