---
status:     redazione
layout:     manuale
class:      capitolo
title:      Gestione della memoria
permalink:  /man/memoria
quote:      "Amiamo ciò che ci ucciderà (se tutto va bene) "
---

La gestione della memoria è l'attività più importante della programmazione.

Come ti ho detto, tutti i linguaggi di programmazione sono un modo di vedere la memoria del computer.
Quando tu *dichiari* una variabile con un'istruzione come: 

```
int a = 1;
```

in realtà, stai dicendo al compilatore di prendere un'area di memoria di 32 bit (un `int` è grande 4 byte, ricordi?), associarle il nome `a` e scriverci dentro il valore binario:

 ```
 00000000 00000000 00000000 00000001
 ```
 
 Come puoi vedere, la maggior parte della variabile è inutilizzata, quindi, se hai a che fare con valori minori di 65.535, è meglio usare degli `short int`, che occupano solo due byte.  
 Allo stesso modo, se dichiari la stringa:
 
 ```
 const char* motto = "Amiamo ciò che ci ucciderà";
 ```

stai chiedendo al compilatore di prendere un'area di memoria di 28 bytes, di associarle il nome `motto` e scriverci dentro i 27 caratteri della frase più un ultimo carattere, con valore `0`, che indica la fine della stringa.  
Puoi usare questo metodo se sai in anticipo quanto saranno grandi le variabili con cui avrai a che fare, ma se invece devi gestire dei valori di grandezza variabile (come, per esempio, l'input di un utente), hai due possibilità: o riservi preventivamente una quantità abbondante di spazio, o la allochi sul momento, in base alle tue necessità.
Il primo caso va bene se devi gestire pochi dati di dimensioni ridotte, ma se devi gestire molte variabili di grandi dimensioni, l'allocazione dinamica, anche se più complessa da gestire, è più efficiente.  
Il codice seguente è un esempio di gestione statica della memoria: 

```
{% include_relative src/memoria-statica.cpp %}
```

Se lo compili e lo esegui, passando due stringhe come parametri, ottieni questo output:

```
% g++ src/cpp/memoria-statica.cpp -o src/out/esempio                
% src/out/esempio "Stringa uno" "Stringa due"
Stringa uno Stringa due
```

Questo codice funziona se devi gestire solo due stringhe che, sommate, hanno meno di 200 caratteri: una condizione piuttosto restrittiva.
Puoi aumentare il numero di stringhe e la dimensione dello spazio in memoria, ma otterresti un programma che è o sovra o sotto dimensionato.
Questa non è buona programmazione.
Il buon programmatore non deve sprecare risorse; per lui, il proverbiale bicchiere non è né mezzo pieno né mezzo vuoto: è grande il doppio del necessario.

```
{% include_relative src/memoria-dinamica.cpp %}
```

L'output di questo programma, molto più parsimonioso della sua versione statica, è il seguente:

```
% src/out/esempio "Stringa uno" "Stringa due"        
0x7fead1405910
24
Stringa uno Stringa due

% src/out/esempio "Stringa uno" "Stringa due più lunga"
0x7fbb6e405910
35
Stringa uno Stringa due più lunga

% src/out/esempio "Stringa uno" ""                     
0x7fcf8f405910
13
Stringa uno 
```

La parola-chiave `new` permette di allocare una determinata quantità di memoria e torna un puntatore al primo indirizzo dell'area allocata:

```
char* stringa = new char[lunghezza];
```

Il puntatore `stringa`, adesso, contiene l'indirizzo dell'area di memoria allocata dall'istruzione `new`. 
Se lo passiamo come parametro all'operatore `<<`, dato che si tratta di un puntatore a `char`, verrà visualizzato come una stringa:

```
cout << stringa << endl;
```

Per conoscere il suo valore effettivo, dobbiamo convertirlo in un puntatore `void` con un'operazione di <a href="/man/tipi-di-dato#casting">casting</a>: 

```
cout << (void*)stringa << endl;
```

Il lato negativo dell'allocazione dinamica della memoria è che, mentre un buffer dinamico “vive” quanto il blocco di istruzioni in cui è stato creato, la memoria allocata dinamicamente rimane occupata fino a che non viene liberata con un'istruzione `delete`:

```
delete[] stringa;
```

Il prossimo esempio dovrebbe aiutarti a capire come funziona la visibilità delle variabili nel C++:

```
{% include_relative src/memoria-visibilita.cpp %}
```

Se compili ed esegui questo codice, otterrai:

```
% g++ src/cpp/memoria-visibilita.cpp -o src/out/esempio
% src/out/esempio                                      
blocco: Stringa interna
funz:   Stringa esterna
funz:   Stringa globale
main:   Stringa globale
```

Come vedi, la stringa definita globalmente è visibile sia nella funzione `main` che nella funzione `funz`; la variabile definita all'inizio della funzione `funz` è visibile all'interno della funzione stessa, ma non nel blocco di codice, dove è visibile la nuova variabile `stringa`.
L' “aspettativa di vita” di ciascuna variabile dipende dal punto in cui è stata definita: la prima variabile esisterà per tutta la durata del programma; la seconda variabile viene creata quando si richiama la funzione `funz` e viene eliminata quando la funzone termina; la variabile all'interno del blocco di codice esiste solo per due istruzioni, poi il blocco di codice finisce e viene eliminata.  
Al contrario, quando un'area di memoria è allocata dinamicamente, rimane occupata fino a che il programma (o, più precisamente: il programmatore) non la rilascia con un'istruzione `delete`.
Se il programma fa una sola chiamata, come nel nostro esempio, il fatto che una cinquantina di byte non siano disponibili per qualche minuto non crea grossi problemi (lo so per certo perché, nella prima versione dell'esempio, avevo dimenticato di aggiungere l'istruzione `delete` alla fine e il computer ha continuato a funzionare lo stesso), se però quello stesso programma continuasse a girare sullo stesso computer per lungo tempo, a poco a poco esaurirebbe tutta la memoria disponibile, causandone il blocco.  
Per questo motivo, il linguaggio con la "J" ha un sistema di *garbage collection* che, come le squadre di pulizia dei Servizi Segreti, provvede a eliminare le prove dell'incompetenza dei suoi programmatori prima che questa arrechi danno ai sistemi. 
Qualcuno ti dirà che non è vero, che i programmatori "J" sono dei professionisti competenti, ma ragiona: se esiste un sistema di raccolta dei rifiuti, ci dovrà pur essere qualcuno che li produce, no?

<hr id="dottrina
 
Come le variabili del C++, anche gi esseri umani sono chiamati a vivere, svolgono il loro compito e alla fine vengono rimossi dal sistema.
Le risorse che occupiamo sono un insieme di spazioni, invece che delle sequenze di byte, ma anche ciò che comunemente definiamo: *noi* non è altro che un modo di vedere le trasizioni di energia all'interno del sistema.
A differenza delle variabili del software, però, gli esseri umani sono capaci di valutare l'esito delle loro scelte o delle loro azioni e possono decidere se ripetere quella scelta o quell'azione in altri cicli di vita dell'Universo.
Siamo, allo stesso tempo, una parte del programma, i *beta-tester* e gli sviluppatori e, se ci accorgiamo di un'istruzione errata, possiamo modificarla nelle successive "esecuzioni" del programma, così come un giocatore di scacchi evita di ripetere una mossa che si è rivelata perdente.
In questo modo, genereremo a una nuova variante della storia che, come una variante scacchistica, potrà rivelarsi migliore o peggiore di quelle precedenti.  
Un *Koan* molto famoso parla dello “Zen di ogni istante”:

> Gli studenti di Zen stanno con i loro maestri almeno dieci anni prima di presumere di poter insegnare a loro volta. Nan-in ricevette la visita di Tenno, che, dopo aver fatto il consueto tirocinio era diventato insegnante.
Era un giorno piovoso, perciò Tenno portava zoccoli di legno e aveva con sé l’ombrello. 
Dopo averlo salutato, Nan-in disse: “Immagino che tu abbia lasciato gli zoccoli nell’anticamera. Vorrei sapere se hai messo l’ombrello alla destra o alla
sinistra degli zoccoli”.
Tenno, sconcertato, non seppe rispondere subito. Si rese conto che non sapeva portare il suo Zen in ogni istante. 
Diventò allievo di Nan-in e studiò ancora sei anni per perfezionare il suo Zen di ogni istante.<a href="/man/note#zen" class="nota"></a>

Il Maestro Canaro detestava questo *Koan* perché era molto distratto.
Se Nan-in l'avesse fatta a lui, la domanda, probabilmente l'avrebbe guardato con aria infastidita e gli avrebbe chiesto: “Quali zoccoli?”.
Malgrado ciò, ne riconosceva l'importanza perché più prestiamo attenzione a tutto ciò che facciamo, più errori riusciremo a identificare e, si spera, a correggere.

---

Un'altra differenza fra gli esseri umani e il codice C++ è il nostro rapporto con l'operatore `delete`.   
Gli uomini hanno sempre avuto paura della morte e, da Gilgamesh in poi, hanno sempre cercato di sfuggirle o di annulare il suo operato.
Arte, religione, scienza: potremmo dire che tutto ciò che di buono o quanto meno di notevole abbiamo prodotto come specie nasce dal naturale rifiuto della transitorietà della nostra esistenza.
La morte è stata la causa e, talvolta, il soggetto dei migliori frutti del nostro ingegno.
Tutte queste creazioni, nel tempo, hanno creato un bozzolo culturale che, da un lato, ci ha protetto dalla paura e, dall'altro, ci ha dato degli ideali comuni per cui lottare, anche se non sempre a fin di bene.
Negli ultimi due secoli, però, la Scienza ha squarciato questo bozzolo, privando gli esseri umani delle loro bugie confortanti e sostituendole con delle certezze inquietanti, mentre il suo figlio scemo (il Movimento del '68) ha spazzato via delle parti sicuramente rivedibili, ma fondamentali della nostra Società senza darle nulla in cambio, tranne la minigonna.    
C'è un aneddoto apocrifo sul Maestro Canaro che parla proprio di questo:

<blockquote class="incluso">
{% include il-computer-della-zia.md %}
</blockquote>

L'Umanità, messa di fronte all'ineluttabilità della fine e, allo stesso tempo, privata del conforto della religione e del sostegno della famiglia, ha reagito  

La dottoressa Kübler Ross, nel 1969, ha elaborato la teoria delle cinque fasi del lutto:

1. negazione;
2. rabbia;
3. negoziazione;
4. depressione;
5. accettazione.



<!--
 così come reagiscono individualmente
n maniera coerente con le *cinque fasi del lutto* della dottoressa Kübler Ross:



@todo: spiegare la differenza fra dichiarazione e definizione; parlare della parola-chiave extern

Utlizzare l'peratore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. 
Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 

Introdurre il concetto di visibilità delle variabili, che serve in seguito per i PostIt.

Questo è anche il capitolo in cui parlare della posizione di un certo dato in memoria, che può variare in successive esecuzioni del programma.
Allo stesso modo, l'io cosciente di ciascuno di noi non è detto che si manifesterà nello stesso individuo, ma potrà essere "allocato" in altri esseri

-->