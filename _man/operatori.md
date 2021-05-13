---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Gli operatori
permalink:  /man/operatori
quote:      "question = 2b | ( ! 2b );"
---

La varietà e soprattutto l'adattabilità degli operatori sono la caratteristica principale del C++.  

Gli operatori sono degli elementi del linguaggio che permettono, appunto, di *operare* delle azioni sulle variabili o sui valori. 
Li possiamo classificare o in base al numero di operandi su cui agiscono:

- primarii
- unarii
- binarii 
- ternarii 

o, in maniera più funzionale al tuo libro, in base al tipo di operazione che compiono:

- aritmetici
- logici
- di relazione
- bitwise
- assegnazione

Gli operatori *aritmetici* sono quelli che permettono di eseguire delle comuni operazioni di addizione, sottrazione, divisione o moltiplicazione sulle variabili:
 
| nome  | descrizione  | esempio   |
|:-:|:-:|:-:|
| +   | addizione       | x + y | 
| -   | sottrazione     | x - y | 
| \*  | moltiplicazione | x * y |  
| \\  | divisione       | x / y |   
| %   | modulo          | x % y |   
| ++  | incremento      | x++   |  
| --  | decremento      | y--   |   

L'operatore modulo `%` permette di calcolare il resto della divisione fra due interi (per esempio: ```15 % 4 = 3```) e non può essere utilizzato con numeri in virgola mobile.  
Gli operatori di incremento `++` e decremento `--` permettono di aumentare o di diminuire di un'unità il valore di una variabile.
Quando questi operatori precedono la variabile, l'incremento o il decremento è calcolato immediatamente; se invece compaiono dopo la variabile, l'operazione di incremento o decremento avviene dopo il suo utilizzo:

```
{% include_relative src/operatori-pre-post.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/operatori-pre-post.cpp -o src/out/esempio 
> src/out/esempio                                       
pre-incremento: 6
post-incremento:7
pre-decremento: 5
post-decremento:8
```
  
Gli operatori *di relazione* permettono di verificare il rapporto fra due variabili:
 
| nome  | descrizione  | esempio  |
|:-:|:-:|:-:|
| == | uguaglianza         | x == x |
| != | differenza          | x != y |
| >  | maggiore di         | x > y  |
| <  | minore di           | x < y  |
| >= | maggiore o uguale a | x >= y |
| <= | minore o uguale a   | x <= y |

Questi operatori tornano un valore booleano, vero o falso a seconda che la condizione sia verificata o no.  
L'operatore `==` torna `true` se gli operandi sono uguali, come nel verso: 

> {{ site.data.citazioni.attar }} <a href="/man/note#attar" class="nota"></a>

 
L'operatore `!=` torna `true` se gli operandi non sono uguali; gli operatori `>` e `<` tornano `true`, rispettivamente, se l'operatore a sinistra è maggiore o minore dell'operando a destra; gli operatori `>=` e `<=` tornano `true` se l'operando a sinistra è maggiore o uguale oppure minore o uguale a quello a destra.  
Gli operatori *logici* permettono di compiere delle operazioni di logica booleana sulle variabili:
 
| nome  | descrizione  | esempio  |
|:-:|:-:|:-:|
| &&   | AND logico    | x && y |
| \|\| | OR logico     | x \|\| y |
| !    | NOT logico    | !(x && y) |

L'operatore `&&` torna `true` se entrambe le variabili sono `true`; l'operatore `||` torna `true` se almeno una delle variabili è `true`; l'operatore `!` inverte il valore dell'operando: se è `true`, torna `false` e viceversa.  
Gli operatori binarii, o: *bitwise* permettono di effettuare delle operazioni sui valori binarii delle variabili:
  
| nome  | descrizione  | esempio  |
|:-:|:-:|:-:|
| &  | AND              | x & y  |
| \| | OR (inclusivo)   | x \| y |
| ^  | XOR (esclusivo)  | x ^ y  |
| ~  | NOT              | x ~ y  |
| >> | shift a destra   | x >> y |
| << | shift a sinistra | x << y |

L'operatore `&` imposta a 1 un bit nel risultato se quel bit è 1 in entrambi gli operandi. 
L'operatore `|` imposta a 1 un bit nel risultato se quel bit è 1 in uno dei due operandi. 
L'operatore `^` imposta a 1 un bit nel risultato se quel bit è 1 in uno dei due operandi, ma non nell'altro. 
L'operatore `~` inverte i bit dell'operando.
Gli operatori `<<` e `>>` spostano rispettivamente a sinistra e a destra i bit dell'operando di destra per il numero di bit specificato dall'operando di destra.  
<!-- @todo: spiegare a cosa servano e perché siano utili per "rispettare" la memoria del computer -->
Gli operatori *di assegnazione* eseguono le operazioni che abbiamo visto finora e, in più, assegnano il valore risultante all'operando di sinistra:
 
| nome  | descrizione  | esempio  |
|:-:|:-:|:-:|
| =   | uguaglianza      | x = x   |
| +=  | somma            | x += y  |
| -=  | differenza       | x -= y  |
| *=  | moltiplicazione  | x *= y  |
| /=  | divisione        | x /= y  |
| %=  | modulo           | x %= y  |
| &=  | AND              | x &= y  |
| \|= | OR inclusivo     | x \|= y |
| ^=  | OR esclusivo     | x ^= y  |
| >>= | shift a destra   | x <= y  |
| <<= | shift a sinistra | x <= y  |

Per esempio, l'esperessione:

```
x *= y
```

equivale a:

```
x = (x * y);
```

Il prossimo esempio mostra l'utilizzo e il risultato di ciascun operatore:

```
{% include_relative src/operatori-utilizzo.cpp %}
```

Se compili ed esegui questo codice, ottieni:

```
> g++ src/cpp/operatori-utilizzo.cpp -o src/out/esempio
> src/out/esempio                                      
Operatori aritmetici
x + y = 16
x - y = 8
x * y = 48
x / y = 3
x % y = 0
x++   = 12
x--   = 13

Operatori logici
x && y    = 1
x || y    = 1
!(x && y) = 0

Operatori di relazione
x == y = 0
x != y = 1
x > y  = 1
x < y  = 0
x >= y = 1
x <= y = 0

Operatori bitwise
bit x  = 00001100
bit y  = 00000100
x & y  = 00000100
x | y  = 00001100
x ^ y  = 00001000
x ~ y  = 11111011
x >> y = 00000000
x << y = 11000000

Operatori di assegnazione
x += y = 16
x -= y = 12
x *= y = 48
x /= y = 12
x %= y = 0

```
Adesso dimmi: quanto valgono, le variabili `x` e `y`, alla fine del programma?

---

Sono degli operatori anche i simboli: `sizeof`,  `,`,  `.`,  `->`,  `&`,  `*`,  `()` e `()?:`.
L'operatore `sizeof` lo abbiamo già visto parlando della <a href="/man/tipi-di-dato#sizeof">dimensione dei tipi di dato</a>, perché torna, appunto, la dimensione, in byte, della variabile o del tipo di dato che riceve come parametro.  
L'operatore di *cast* `()` permette di modificare il tipo di una variabile e lo abbiamo già utilizzato nella classe `Animale`, quando abbiamo parlato del <a href="/man/c-plus-plus#cast">polimorfismo</a>:

```
const char getSesso() const {        
    return (char)_sesso;
} 
```

L'operatore condizionale `()?:` è l'unico operatore ternario del C++ e permette di scegliere fra due espressioni a seconda dell'esito di una condizione.
La sua sintassi è:

```
(<condizione>) ? <istruzione vero> : <istruzione falso>
```

Scrivere:

```
x = (a > b) ? 4 : 5;
```

è un modo elegante di scrivere:

```
if(a > b) {
    x = 4;
} else {
    x = 5;
}
```

L'operatore virgola `,` serve ad alterare il modo in cui vengono valutate le espressioni. 
Quando due o più espressioni sono separate dall’operatore virgola, i risultati delle espressioni a sinistra sono ignorati e viene mantenuto solo il risultato dell'espressione più a destra.
In questa espressione, per esempio, alle variabili `a` e `b` è prima assegnato il valore 1 e poi la variabile `b` è incrementata di 2:

```
a = b = 1, b = b + 2;                      
```

il valore finale di `a` e `b` sarà quindi di 1 e 3, mentre nell'espressione qui sotto sarà di 1 e 2:

```
a = b = 1, b = b + 2, b = b - 1;          
```

Gli operatori `.` e `->` servono a identificare i membri di una classe o di un altro dato aggregato. 
Se  ti ricordi (ne dubito), li abbiamo visti per la prima volta parlando del <a href="/man/c-plus-plus#membro">polimorfismo</a> e li utilizzeremo quando ci occuperemo delle classi.  
Gli operatori `&` e `*`, infine, tornano, rispettivamente, l'indirizzo di memoria di una variabile e un puntatore a una variabile:

```
{% include_relative src/operatori-altri.cpp %}
```

Se compili ed esegui questo codice, otterrai:

```
> g++ src/cpp/operatori-altri.cpp -o src/out/esempio 
> src/out/esempio                                    
&a: 0x7ffee65bba5c
sa: 4
sp: 8
t : 9
c : $
```
<hr id="risoluzione">

L'ultimo operatore di cui dobbiamo parlare è anche quella con il nome più lungo: l’operatore di *risoluzione del campo d’azione* `::`. 
Oltre ad altri utilizzi connessi con la gestione dei dati delle classi, di cui parleremo in seguito, questo operatore permette di riferirsi a delle variabili con visibilità globale anche nei casi in cui queste vengano oscurate dalla ridefinizione di variabili locali con lo stesso nome:

```
{% include_relative src/operatori-risoluzione.cpp %}
```
Compilando ed eseguendo questo codice, ottieni:

```
> g++ src/cpp/operatori-risoluzione.cpp -o src/out/esempio 
> ./src/out/esempio                                       
Stringa locale
Stringa globale
```

<!-- 
@todo: aggiungere nota su overload degli operatori 

-->

<hr id="dottrina">

La definizione dei concetti di *vero* e di *falso* è sempre frutto di un arbitrio. È inevitabile.
Possiamo definire *falso* come il contrario di *vero*, ma non possiamo dedurre o inferire il concetto di *vero* perché, quale che sia la definizione prescelta, prima di poterla prendere per buona dovremo poterla considerare vera, ma ciò è impossibile perché non sappiamo ancora cosa sia, effettivamente, *vero*.    
Bertrand Russell disse che la condizione di *vero* o di *falso* è uno stato dell'organismo, determinato da condizioni esterne all'organismo;<a href="/man/note#russell" class="nota"></a> è un'affermazione vera.. o, meglio, *valida* anche per i computer: i valori booleani *vero* e *falso* sono due stati possibili per un'istruzione e spesso dipendono da condizioni esterne all'istruzione stessa, come la presenza di un file o un'azione dell'utente.
La cosa interessante è che, anche per i computer, i valori che vengono interpretati come *vero* e *falso* sono del tutto arbitrarii e spesso specifici per un dato sistema. 
Prendi per esempio i programmi che gestiscono le basi di dati: per *Access*, il valore booleano *false* è `-1`; per le prime versioni di *MySQL* è `f`; per Postgres o Oracle, è `0`.  
Il computer non ha *in sé* il concetto di *vero* o di *falso*, ma solo l'associazione dei valori booleani *true* e *false* a una determinata sequenza di bit. 
*Vero* e di *falso*, quindi, sono dei valori simbolici che noi inseriamo nella logica del computer, traducendo nel suo linguaggio un concetto che è proprio del nostro mondo; un riferimento esogeno che può generare delle apparenti conraddizioni come, per esempio, il fatto che tutti i valori digitali siano basati su grandezze analogiche (la carica magnetica di un nastro, un'infossatura nella superificie di un CD o la tensione all'interno di un circuito), o dei veri e proprii paradossi, come il fatto che, nelle schede perforate, il valore `1` sia associato al vuoto del foro, mentre il valore `0` sia associato alla presenza della carta; di fatto, una negazione logica della realtà.  
Questi paradossi, apparenti o reali che siano, non causano alcun problema al sistema, a patto vengano condivisi da tutti gli attori al suo interno. 
Il paradosso delle schede perforate (buco = 0, carta = 1) era condiviso sia dalle macchine Hollerith che dalle perforatrici delle schede, perciò, le elaborazioni che ne derivavano erano corrette, indipendentemente dal valore relativo attribuito ai concetti di *vero* e di *falso* all'interno del sistema.
Da questo punto di vista, non possiamo che dare ragione a William James, quando dice che un'idea è *vera* fintanto che credere in essa è utile per le nostre vite. 

<hr id="effimeri">

Anche gli esseri umani, come i computer, devono riferire le proprie convinzioni a schemi di valori preesistenti perché buona parte dei principii e dei valori su cui modelliamo la nostra e l'altrui esistenza non hanno un riscontro oggettivo nei fatti: sono solo convizioni o convenzioni che abbiamo deciso di adottare, così come il fatto che `true` equivalga al valore binario `000000001` e `false` a `00000000`.  
Prendi la ricchezza, per esempio: si dice che i soldi non danno la felicità ed è vero; nemmeno essere poveri rende felici, ma questo non lo dice nessuno.
Comunque, una delle persone più ricche che ho conosciuto non poteva avere figli.
Possedeva case in diversi Paesi, uno yacht e perfino un aereo personale, ma non poteva avere qualcosa che anche l'uomo più povero della Terra può facilmente ottenere.
Che senso aveva, la sua ricchezza? Era reale?  
Si definisce: *prestigio* qualcosa che sembra ciò che non è, come i giochi degli illusionisti, mentre *successo* non è che il participio passato del verbo *succedere*: tutto ciò che è avvenuto in passato è, per definizione, “successo”; malgrado ciò, molte persone, sotto l'influsso dell'Annosa Dicotomia, dedicano la propria vita alla ricerca o dell'uno o dell'altro o di entrambi.
La *fama* è altrettanto aleatoria: quante persone sono state famose e ora sono dimenticate? 
Gli inventori della ruota e del fuoco hanno cambiato per sempre la storia della nostra specie e del mondo con le loro scoperte, ma nessuno sa chi siano stati.
In tempi più recenti, il pittore Giovanni Baglione fu molto famoso, alla fine del sediccesimo Secolo, ma se ci ricordiamo di lui oggi è solo per via dei suoi rapporti con Caravaggio e, comunque, la loro fama terminerà con la nostra specie, insieme a quella di Shakespeare, Leonardo o Einstein.  
Non sono inconsistenti solo i valori mondani, come fama successo o denaro, ma anche quelli che consideriamo usualmente “nobili”, come il rispetto della vita altrui.
Se tu mi chiedi perché non si debba uccidere un uomo, ti risponderò che uccidere è sbagliato perché tutto il male che fai, lo stai facendo a te stesso; penso che sia vero perché me lo ha insegnato il Maestro Canaro, che aveva visto il codice del programma dell'Universo.
Se invece lo chiedi a un cristiano o a un ebreo, lui ti risponderà che è vietato dai Dieci Comandamenti che Dio ha dato a Mosé; loro pensano che sia vero perché è scritto nella Bibbia, che è la Parola di Dio.
Se infine lo chiedi a un paladino del laicismo, ti risponderà che l'omicidio, per il nostro ordinamento giuridico, è un reato; ciò dev'essere vero, perché le nostre Leggi applicano i concetti espressi nella nostra Costituzione la quale, a sua volta, si rifà ai principii di libertà e uguaglianza della *Dichiarazione dei Diritti dell’Uomo e del Cittadino* francese, che a sua volta si rifaceva alla *Dichiarazione di Indipendenza* americana, che a sua volta riprendeva le idee di Locke e Montesquieu.  
Nessuna di queste affermazioni è valida di per sé: sono tutte fondate su una qualche forma di fede &mdash; religiosa o laica che sia &mdash; in chi ha promulgato la Legge o il Principio.  
È, applicato all'etica, lo stesso meccanismo che si utilizza per certificare un server Web. 
Quando tu accedi al sito Web della tua banca, sai che è davvero il server della tua banca perché possiede un certificato digitale che attesta la sua identità, firmato digitalmente da un ente certificatore detto *Certification Authority* (o, più brevemente: *CA*).
Tu sai che l'ente certificatore è davvero chi dice di essere perché anche lui ha un suo certificato, firmato da un'altro ente certificatore, chiamato: *root CA*.
La *root CA* garantisce per la CA intermedia che a sua volta garantisce per la tua banca.
Sfortunatamente, però, né i legislatori né i loro certificatori ideologici sono sottoposti alle regole e ai controlli che deve rispettare una *Certification Authority* e spesso è accaduto che chi ha definito delle regole sia stato anche il primo a non tenerne conto.  
Mosé, con il sesto Comandamento ancora fresco di stampa, chiese ai figli di Levi: 

> Ognuno di voi si metta la spada al fianco; percorrete l’accampamento da una porta all’altra di esso, e ciascuno uccida il fratello, ciascuno l’amico, ciascuno il vicino!<a href="/man/note#levi" class="nota"></a> 

Gli Americani, che scrissero:

> We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.

commerciavano in schiavi e hanno sterminato i Nativi Americani per rubar loro le terre.
I Francesi, il cui motto era:

> Liberté, Égalité, Fraternité

hanno applicato questi principii a colpi di ghigliottina.
L'ONU, che nel 1948 ha pubblicato la *Dichiarazione Universale dei Diritti Umani* ha al suo vertice dei Paesi che sono i principali produttori di armi del Mondo<a href="/man/note#armi" class="nota"></a> e che violano costantemente quelle stesse regole da loro promosse.  
Attenzione, però: il fatto che i principii laici di pace, uguaglianza e libertà derivino, in ultima analisi, dalle convinzioni<a href="/man/note#self-evident" class="nota"></a> di un gruppo di credenti<a href="/man/note#credenti" class="nota"></a>, non vuol dire che siano sbagliati, ma che non gli si può attribuire nessuna veridicità oggettiva; possiamo solo accettarli per fede, così come i dogmi religiosi.
*Scegliamo* di credere in uno schema di valori, così come potremmo scegliere di credere negli UFO: non abbiamo convinzioni innate, se non l'egoismo.  
Le persone per bene hanno una cosa in comune con i malandrini: pensano che il resto del Mondo sia come loro, ma si sbagliano.
Noi troviamo condivisibile, quasi pleonastico, che ciascun essere umano abbia diritto alla vita, alla libertà e a una giustizia imparziale, perché siamo stati educati con questi valori, ma qualcuno con un differente livello culturale potrebbe non ritenere queste affermazioni altrettanto evidenti *in sé*.  
Per gli autori della *Dichiarazione di Indipendenza* era *self-evident* che tutti gli uomini fossero stati creati uguali, ma sei Stati del Sud, nelle loro Costituzioni, precisarono che si stava parlando di uomini liberi, non degli schiavi<a href="/man/note#freemen" class="nota"></a>.  
I nazisti utilizzarono le macchine Hollerith per censire e sterminare gli ebrei; furono anche aggiunte delle colonne alle schede perforate per poter gestire i dati relativi alla religione<a href="/man/note#black" class="nota"></a>.
Noi oggi critichiamo sia loro sia chi li aiutò a farlo, ma forse i nostri nipoti criticheranno noi per la tolleranza che abbiamo mostrato nei confronti di chi ci vende il petrolio per le nostre automobili; la stessa tolleranza che loro mostreranno a chi li rifornirà di materie prime per le batterie, o di acqua.

---

Scegliamo un ethos perché rende migliore la nostra vita, non perché ci sta simpatico l'autore.
Il Maestro Canaro, per esempio, era convinto che il Libro dell'Esodo fosse il resoconto di un esperimento alieno su una popolazione isolata nel deserto per due generazioni (“capisci: la circoncisione serviva a identificare i maschi e l'appartenenza al gruppo era stabilita in base alla madre perché così era verificabile grazie ai mitocondri”); ciò non ostante, regolava la sua vita e le sue decisioni in base ai dieci Comandamenti di Mosé. 
Quando gli chiesi perché avesse scelto proprio quelle regole, mi rispose: “Se li avessi seguiti anche da giovane, adesso avrei molti rimorsi in meno.” 

<!--
Il fine dichiarato di Kanāda nei Vaiśesika Sūtra, considerati da Dasgupta come pre-buddhisti, è di spiegare il Dharma (la Legge Eterna) come il fondamento, da un lato, della manifestazione (abhyudaya) e, dall’altro, del “Sommo Bene” (nihśreyasam), cioè della Liberazione: la validità dei Veda è stabilita dal fatto che questi sono i loro fini.

Coomaraswamy, Ananda K.. Tempo ed Eternità (Orizzonti dello spirito) (Italian Edition) (Kindle Locations 322-327). Edizioni Mediterranee. Kindle Edition. 
-->
