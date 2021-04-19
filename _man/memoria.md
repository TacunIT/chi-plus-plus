---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Gestione della memoria
permalink:  /man/memoria
quote:      "cogito ∴ sum()"
---

La gestione della memoria è la caratteristica principale del C++.

Come ti ho detto, tutti i linguaggi di programmazione sono un modo di vedere la memoria del computer.
Quando tu *dichiari* una variabile con un'istruzione come: 

```
signed int a = 1;
```

in realtà, stai dicendo al compilatore di prendere un'area di memoria di 32 bit (un `int` è grande 4 byte, ricordi?), associarle il nome `a` e scriverci dentro il valore binario:

 ```
 00000000 00000000 00000000 00000001
 ```
 
 Come puoi vedere, la maggior parte della variabile è inutilizzata, quindi, se hai a che fare con valori minori di 65.535, è meglio usare degli `short int`, che occupano solo due byte.  
 Allo stesso modo, se dichiari la stringa:
 
 ```
 const char* motto = "Cogito ergo sum";
 ```

stai chiedendo al compilatore di prendere un'area di memoria di 16 byte, di associarle il nome `motto` e scriverci dentro i 15 caratteri della frase più un ultimo carattere, con valore `0`, che indica la fine della stringa.  
Puoi usare questo metodo se sai in anticipo quanto saranno grandi le variabili con cui avrai a che fare, ma se invece devi gestire dei valori di grandezza variabile (per esempio, l'input di un utente), hai due possibilità: o riservi preventivamente una quantità abbondante di spazio, o la allochi sul momento, in base alle tue necessità.
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

Il lato negativo dell'allocazione dinamica della memoria è che, mentre un buffer statico “vive” quanto il blocco di istruzioni in cui è stato creato, la memoria allocata dinamicamente rimane occupata fino a che non viene liberata con un'istruzione `delete`:

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

<hr id="dottrina">
 
Come le variabili del C++, anche gi esseri umani sono chiamati a vivere, svolgono il loro compito e alla fine vengono rimossi dal sistema.
Le risorse che occupiamo sono un insieme di spazioni, invece che delle sequenze di byte, ma ciò che comunemente definiamo: *noi* non è altro che un modo di vedere le trasizioni di energia all'interno del sistema.
A differenza delle variabili del software, però, gli esseri umani sono capaci di valutare l'esito delle loro scelte o delle loro azioni e possono decidere se ripetere quella scelta o quell'azione in altri cicli di vita dell'Universo.
Siamo, allo stesso tempo, una parte del programma, i *beta-tester* e gli sviluppatori e, se ci accorgiamo di un'istruzione errata, possiamo modificarla nelle successive "esecuzioni" del programma, così come un giocatore di scacchi evita di ripetere una mossa che si è rivelata perdente.
In questo modo, genereremo a una nuova variante della storia che, come una variante scacchistica, potrà rivelarsi migliore o peggiore di quelle precedenti.  
Un *Koan* molto famoso parla dello <i id="istante">Zen di ogni istante</i>:

> Gli studenti di Zen stanno con i loro maestri almeno dieci anni prima di presumere di poter insegnare a loro volta. Nan-in ricevette la visita di Tenno, che, dopo aver fatto il consueto tirocinio era diventato insegnante.
Era un giorno piovoso, perciò Tenno portava zoccoli di legno e aveva con sé l’ombrello. 
Dopo averlo salutato, Nan-in disse: “Immagino che tu abbia lasciato gli zoccoli nell’anticamera. Vorrei sapere se hai messo l’ombrello alla destra o alla
sinistra degli zoccoli”.
Tenno, sconcertato, non seppe rispondere subito. Si rese conto che non sapeva portare il suo Zen in ogni istante. 
Diventò allievo di Nan-in e studiò ancora sei anni per perfezionare il suo Zen di ogni istante.<a class="nota" href="/man/note#zen"></a>

Il Maestro Canaro detestava questo *Koan* perché era molto distratto.
Se Nan-in l'avesse fatta a lui, la domanda, probabilmente l'avrebbe guardato con aria infastidita e gli avrebbe chiesto: “Quali zoccoli?”.
Malgrado ciò, ne riconosceva l'importanza perché più prestiamo attenzione a tutto ciò che facciamo, più errori riusciremo a identificare e, si spera, a correggere.

<hr id="delete">

Un'altra differenza fra gli esseri umani e il codice C++ è il nostro rapporto con l'operatore `delete`.   
Gli uomini hanno sempre avuto paura della morte e, da Gilgamesh in poi, hanno sempre cercato di sfuggirle o di annulare il suo operato.
Arte, religione, scienza: potremmo dire che tutto ciò che di buono o quanto meno di notevole abbiamo prodotto come specie nasce dal naturale rifiuto della transitorietà della nostra esistenza.
La morte è stata la causa e, talvolta, il soggetto dei migliori frutti del nostro ingegno.
Tutte queste creazioni, nel tempo, hanno creato un bozzolo culturale che, da un lato, ci ha protetto dalla paura e, dall'altro, ci ha dato degli ideali comuni per cui lottare, anche se non sempre a fin di bene.
Negli ultimi due secoli, però, la Scienza ha squarciato questo bozzolo, privando gli esseri umani delle loro bugie confortanti e sostituendole con delle certezze inquietanti, mentre il suo figlio scemo (il Movimento del '68) ha spazzato via delle parti sicuramente rivedibili, ma fondamentali della nostra Società senza darle nulla in cambio, tranne la minigonna.    
C'è un aneddoto apocrifo sul Maestro Canaro che parla proprio di questo:

<blockquote class="incluso" id="zia">
{{ site.data.canaro.computer-zia }}
</blockquote>

L'Umanità, messa di fronte all'ineluttabilità della fine e, allo stesso tempo, privata del conforto della religione e del sostegno della famiglia, ha reagito come un paziente a cui sia diagnosticato un male incurabile, elaborando il suo dolore secondo le cinque fasi definite dalla dottoressa Kübler Ross<a class="nota" href="/man/note#kubler"></a>:    

<i>Negazione:</i> così come l'Epoca vittoriana aveva il tabù del sesso, la nostra “cultura” ha il tabù della morte: i nostri bis-nonni fingevano di non avere interessi carnali, noi fingiamo che la morte non esista.
La neghiamo a parole, usando dei giri di parole per non nominarla: “Se n'è andato”, “Non c'è più”, “È scomparso”, neanche si stesse parlando di un evaso o di un illusionista. 
La neghiamo nei fatti, isolando i moribondi nelle corsie d'ospedale, lontani dalle loro case e dai loro cari.
La neghiamo nei nostri pensieri e nelle nostre azioni, perché altrimenti l'insensatezza delle nostre vite, spese inseguendo il miraggio effimero del successo<a class="nota" href="/man/note#successo"></a> diventerebbe evidente e innegabile.  

<i>Rabbia:</i> anche se rabbia e aggressività sono sempre state presenti nella nostra storia, dalla metà del Secolo scorso, oltre che dall'oppressione e dal disagio, hanno cominciato a fiorire rigogliose anche dal benessere.
Gli scontri fra *Mods* e *Rockers* negli anni '60, le lotte armate degli anni '70, il *Punk* e, in tempi più recenti, i *foreign fighters* e l'aggressività nei *social-network*: nessuno di questi fenomeni nasce nei ghetti o da uno stato di bisogno, sono tutti degli *hobby* del Ceto medio.  

<i>Negoziazione:</i> nel 1982 Jane Fonda pubblicò una videocassetta nella quale insegnava a fare ginnastica aerobica<a class="nota" href="/man/note#aerobica"></a> nel salotto di casa a chiunque potesse permettersi di spendere sessanta Dollari<a class="nota" href="/man/note#sessanta"></a> per un VHS. 
Fu una delle videocassette più vendute di tutti i tempi e diede il via a una moda che divenne uno stile di vita per milioni di persone.
La mania del *fitness*, insieme al rifiorire della spiritualità *New Age*, sono stati il modo in cui i popoli civilizzati hanno cercato di venire a patti con la nuova, terrificante realtà presentata loro dalla Scienza, prendendo atto dei proprii errori e cercando di porvi rimedio cambiando stile di vita.
Sfortunatamente, però, gli pseudo-mistici non hanno mai capito che recitare il *Sutra del Loto* perché credi che possa aiutarti a realizzare i tuoi desiderii è una contraddizione in termini.
La religione è come gli antibiotici: non fa effetto se non prendi la dose intera.

<i>Depressione:</i> la sindrome depressiva è la seconda malattia più diffusa al Mondo, dopo i disturbi cardiaci, segno evidente che la fase di negoziazione non ha sortito gli effetti sperati.
Fallito ogni tentativo di combattere la realtà, l'Uomo del terzo Millennio  ha cercato scampo nella fuga.
Così come il Giappone dei Tokugawa, si è rinchiuso in sé stesso<a class="nota" href="/man/note#isolamento"></a>, ma senza il rifiorire delle arti che si accompagnò al *Sakoku*<a class="nota" href="/man/note#sakoku"></a>, perché la Realtà non è un predatore, che possiamo sperare di seminare.
La realtà è ovunque e anche isolandoci non possiamo sfuggirle; anzi: la solitudine genera un *feedback* che amplifica lo stato di malessere e rende ancora più difficile e improbabile il raggiungimento dello stadio successivo.

<i>Accettazione:</i> il solo modo per salvarsi è rinunciare agli insegnamenti dei cattivi maestri del passato e accettare il fatto di non essere delle gocce d'acqua uniche e insostituibili, ma di far parte del mare.
Chi vuole, potrà credere che in quel mare ci sia Poseidone; gli altri saranno liberi di pensare che ci siano solo pesci, molluschi e alghe: non ha importanza; ciò che conta è sottrarsi all'influenza separatrice dell'Entropia e riacquistare un senso di appartenenza a qualcosa che va oltre le nostre brevi e limitate esistenze.
Solo così, potremo vincere la nostra battaglia contro l'Annosa Dicotomia.
Solo così, potremo smettere di inseguire una fama transeunte e trovare forza nella consapevolezza del fatto che ciascuno di noi può modificare l'evoluzione dell'Mondo con le sue azioni.  
Secondo lo *Yoga Sutra Bhāṣya*<a class="nota" href="/man/note#yoga"></a>:

> Il Mondo intero subisce una mutazione a ogni istante; così, tutte le qualità esteriori del Mondo dipendono da questo istante presente.

Così come tutti gli istanti sono importanti, per il Mondo, ciascun essere è importante per l'Universo, se svolge il compito che gli è stato assegnato; anche qualcuno o qualcosa che apparentemente è insignificante.
È noto che il Maestro Canaro raggiunse il primo stato di Illuminazione quando vide un arbusto crescere su una parete di roccia a picco sul mare.
Un arbusto apparentemente inutile: i suoi semi non avrebbero mai raggiunto una terra dove germogliare e i suoi rami erano troppo esili perché un uccello ci potesse costruire il suo nido; malgrado ciò, la caparbietà con cui quella pianta svolgeva il ruolo che gli era stato assegnato, permise al Maestro Canaro di capire ciò che molti libri non erano riusciti a spiegargli, posando la prima pietra di quello che sarebbe sato poi il suo insegnamento.  
Quello che noi percepiamo come il nostro “valore” è relativo. 
Pensa alla variabile `a` che abbiamo visto all'inizio: 

```
00000000 00000000 00000000 00000001
```

Il bit iniziale vale `0`, che è un valore nullo, se lo consideri individualmente, ma se invece lo valuti in rapporto ai due byte a cui appartiene, diventa il valore da cui <a href="/man/tipi-di-dato#modificatori">dipende il segno della variabile</a>.
Se per un caso il valore di quel bit diventasse `1`, il valore della variabile `a` diventerebbe negativo, con delle ripercussioni imprevedibili sul programma.
Molte, troppe persone sono come quel bit e pensano di valere zero perché considerano il proprio valore solo in termini soggettivi.
Mesmerizzati dall'Annosa Dicotomia, spendono tutte le loro energie cercando di valere `1` e si distraggono così da quello che sarebbe stato il loro destino, con conseguenze molto più gravi di un'alterazione di segno in una variabile.

---

Il buon programmatore deve sempre controllare che il suo codice non contenga dei difetti e ciò che ti ho appena detto ne ha uno, piuttosto grave: può essere utilizzato come pretesto per creare un sistema di caste che limiti le possibilità di crescita di coloro che effettivamente sono destinati ad aumentare il loro valore.
La domanda quindi è: come può, un bit o un essere senziente, decidere quale sia il suo valore esatto?
Sicuramente non può dirglielo un'Autorità costituita né tanto meno una consuetudine.
La famiglia può dargli dei suggerimenti, ma non può decidere per lui: i genitori hanno sicuramente più esperienza dei figli, ma non sono infallibili.
La risposta è in una frase di Jacopone da Todi:

> Prima devi sape' perché stai ar monno.   
 Quanno sai er perché, te devi impara' a stacce .

In queste due frasi è racchiuso il senso della Vita: capire quale sia il proprio ruolo e svolgerlo al meglio delle proprie possibilità, senza farsi influenzare dalle mode e soprattutto senza cadere vittima dell'Annosa Dicotomia.  
Il C++ è un linguaggio a tipizzazione forte<a class="nota" href="/man/note#tipizzazione"></a>, perciò, quando si dichiara una variabile, le si deve sempre assegnare un tipo di dato:

```
bool    booleano  = false;
char    carattere = 'C';
int     intero    = 1234567890;
float   decimale  = 3.14;
char    array[]   = "abcdefghilmnopqrstuvz";
```
Allo stesso modo, tutto ciò che esiste ha delle capacità che sono funzionali al suo ruolo nell'Universo.
Suonare, scrivere, recitare, insegnare, convincere, guidare, amare: a ciascuno di noi, l'Universo dà uno strumento e un banco di lavoro, anche se il ruolo che ci verrà assegnato non sempre è evidente fin dalla nascita.
Prendi Lech Walesa, per esempio (è l'unico Nobel per la Pace che mi viene in mente che non fosse laureato): lui cominciò a lavorare come elettricista navale, ma le sue capacità lo trasformarono in un leader politico<a class="nota" href="/man/note#walesa"></a>.
Oppure, meglio, pensa a te stesso: se avessi voluto, a diciott'anni avresti potuto lasciare l'Ordine, tornare a casa e diventare un *vice-qualcosa* nell'azienda della tua famiglia, invece sei rimasto qui a scrivere il tuo libro.
Sarà stata la scelta giusta? 
Cosa si aspettava, l'Universo, da te? che, come monaco, rendessi il Mondo un luogo migliore con la tua Bibbia per smanettoni o che, come manager, migliorassi le condizioni di vita dei dipendenti della tua azienda?
Lo scopriremo solo quando torneremo a essere Uno; fino ad allora, potremo solo fare delle supposizioni, oppure chiederci: quale è stato, il motivo della tua scelta?
Sei rimasto qui per pigrizia o perché avevi paura del Mondo o della tua famiglia? hai fatto un errore.
Sei rimasto perché non desideri il lusso o il potere? potresti aver fatto la scelta giusta. Forse.
Sei rimasto, anche se sarebbe stato più facile e comodo tornare in seno alla tua famiglia, perché pensavi che restando qui saresti stato più utile? o sei terribilmente ingenuo o hai fatto la cosa giusta.  
A ogni modo, bisogna sempre fare bene il proprio mestiere, quale che sia, perché non sappiamo come e quando dovremo renderci utili.
Una volta, un amico del Maestro Canaro, appena tornato dal Giappone, gli disse:

> La differenza fra noi e i Giapponesi è che se tu, qui, metti uno a pulire i cessi, quello si sente disprezzato e lavora male, mentre un giapponese cerca di diventare il miglior pulitore di cessi di tutto il Paese.

Un altro modo per capire se si è nel giusto, è in base all'amore.
L'amore è la droga perfetta: dà assuefazione come il *crack* e ti fa credere di saper volare, come l'LDS; è il miele con cui la Vita attira le formiche dei nostri pensieri, facendole andare dove vuole lei.
Quindi, se quello che ti spinge ad agire è una qualche forma di amore &mdash; e non solo amore per qualcuno, ma anche per qualcosa, che sia il mare, la montagna, uno sport, una forma di arte o un lavoro &mdash; è molto probabile che tu stia facendo ciò che devi.  
Nell'ottica della gestione della memoria, l'amore ha anche un altro utilizzo, riassunto nel precetto:

> Amiamo ciò che ci ucciderà (se tutto va bene) 

Adesso, però, è tardi e questa lezione è stata fin troppo lunga; ne parleremo un'altra volta.

<!--

@todo: decidere se mettere un riferimento incrociato alla lezione sulle classi.

@todo: classi di memorizzazione: extern, static, auto 

-->
