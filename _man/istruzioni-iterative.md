---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      Istruzioni iterative
permalink:  /man/istruzioni-iterative
quote:      "Invero è cosa piuttosto strana a udirsi, ma il nome che noi almeno vi diamo – un nome a cui, per difetto di esperienza in materia, non penserebbe nessuno – è: Spazionismo"
---

Le istruzioni di ciclo sono le componenti fondamentali della programmazione.  

Ci sono tre tipi di istruzioni di ciclo: 

- `for`
- `while`
- `do while`.

Queste istruzioni sono composte di due parti: un’istruzione di *controllo del ciclo*, che ne determina la durata e un *corpo del ciclo*, composto dalle istruzioni che vengono ripetute ad ogni iterazione.
La ripetizione può protrarsi o per un determinato numero di volte o fino a che non sia raggiunta una determinata condizione.

Il ciclo `for` viene utilizzato quando vogliamo eseguire il ciclo in numero determinato di volte. 
La forma generale è la seguente:

```
// controllo del ciclo
for(<stato iniziale> ; <stato finale> ; <variazione>)
{
    // corpo del ciclo
    <istruzioni>
}
```

Le tre condizioni all'interno delle parentesi sono utilizzate dall'istruzione `for` per controllare l'esecuzione delle istruzioni all'interno del corpo del ciclo.  
La prima espressione è valutata solo una volta all'inizio del ciclo e, solitamente, serve a inizializzare le variabili utilizzate.  
La seconda espressione è una condizione logica o relazionale che viene valutata all’inizio di ogni iterazione: se torna `0` o `false` l’esecuzione del ciclo termina, altrimenti prosegue.  
La terza espressione viene valutata al termine di ogni iterazione e, di solito, è costituita da un’espressione di incremento o decremento delle variabili utilizzate per il controllo del ciclo.
Per fare ciò, si utilizzano degli operatori unarii (ovvero che operano su una singola variabile) detti: *operatori di incremento* e *operatori di decremento*, che possono svolgere la loro funzione o prima o dopo l’utilizzo della variabile, a seconda che vengano posti prima o dopo l’identificatore della variabile: 

```
x++     // valuta x e poi la incrementa di un'unità
++x     // incrementa x di un'unità e poi la valuta
x--     // valuta x e poi la riduce di un'unità
--x     // riduce x di un'unità e poi la valuta
```

Se `x` è una variabile di tipo intero o in virgola mobile l’incremento è di un'unità aritmetica; se invece `x` è un puntatore l’incremento equivale alla dimensione della variabile a cui il puntatore riferisce, come ti ho fatto vedere parlando dei tipi di dato.  
<!-- @todo: rimando a esempio nei tipi di dato --> 
In questo caso, la variabile `p` è un intero, quindi l'istruzione:

```
for ( p = POS_MERCURIO; p <= POS_PLUTONE; p++ ) {
```

incrementerà la variabile `p` di 1.

```
{% include_relative src/istruzioni-iterative-for.cpp %}
```

La prima istruzione inizializza il valore di `p` a `1` (il valore della costante `POS_MERCURIO`) e prosegue, per incrementi successivi di 1, fino a che il valore di `p`è minore o uguale a `9` (il valore della costante `POS_PLUTONE`).
A ogni ripetizione il programma mostra il valore della variabile `p`, richiama la funzione `mostraPianeta`, passandole il valore corrente di `p`, poi aggiunge un a capo.  
L'output di questo programma è: 

```
% g++ src/cpp/istruzioni-iterative-for.cpp -o src/out/esempio
% src/out/esempio                                            
1: Mercurio
2: Venere
3: Terra
4: Marte
5: Giove
6: Saturno
7: Urano
8: Nettuno
9: Plutone

```

Si può utilizzare un ciclo `for` anche per effettuare cicli con un numero indefinito di iterazioni, basta omettere le tre espressioni di controllo, mantenendo solo delle *istruzioni nulle*, composte dal solo terminatore `;`:

```
for( ; ; )
{
    // istruzioni
}
```

Un ciclo di questo tipo continuerà a ripetersi indefinitamente e, se non viene fermato in qualche maniera, causerà inevitabilmente dei problemi al computer che lo esegue.
È necessario quindi porre un limite al numero di ripetizioni, utilizzando la stessa parola-chiave `break` che abbiamo usato con le istruzioni `switch`.
Stavolta, però, cominceremo a fare le cose come vanno fatte e separeremo le tre componenti del programma precedente in tre file distinti: `pianeti.h`, che conterrà le dichiarazioni delle costanti e della funzione `mostraPianeta`; `pianeti.cpp`, contenente la definizione della funzione `mostraPianeta` e `pianeti-main.cpp` per la funzione `main`:

```
{% include_relative src/pianeti.h %}
```

```
{% include_relative src/pianeti-1.0.cpp %}
```

```
{% include_relative src/pianeti-main.cpp %}
```

L'incremento della variabile `p`, in questo caso, avviene all'interno dell'istruzione:

```
if(!mostraPianeta( p++ )) break; 
```

La parola-chiave `break` è una delle tre *istruzioni di interruzione* che il C++ ha ereditato dal C; le altre due sono l'istruzione `continue`, che riporta l'elaborazione all'inizio del ciclo e l'istruzione `return`, che termina la funzione, restituendo un eventuale valore di ritorno alla funzione chiamante. 
<!-- @todo: ampliare con esempi, ma in altre parti del testo, qui è già troppo carico -->

Per generare il programma, stavolta, dovremo passare al compilatore entrambi i file *.cpp*:

```
% g++ src/cpp/pianeti-main.cpp \
      src/cpp/pianeti.cpp \
   -o src/out/esempio
% src/out/esempio 
1: Mercurio
2: Venere
3: Terra
4: Marte
5: Giove
6: Saturno
7: Urano
8: Nettuno
9: Plutone
10: Inserire un valore da: 1 a 9
```
Se invece avessimo scritto:

```
if(!mostraPianeta( ++p )) break; 
```

il valore di `p` in tutte le istruzioni sarebbe stato maggiore di uno rispetto al valore corretto e il programma avrebbe "saltato" Mercurio perché il valore della variabile `p` sarebbe stato incrementato prima del suo utilizzo da parte della funzione:

```
% src/out/esempio                                            
1: Venere
2: Terra
3: Marte
4: Giove
5: Saturno
6: Urano
7: Nettuno
8: Plutone
9: Inserire un valore da: 1 a 9
```

Si può utilizzare un ciclo `for` in questo modo, ma non ha molto senso.
Meglio, invece, utilizzare l'istruzione di flusso `while`:

```
{% include_relative src/pianeti-while-bool.cpp %}
```

L'output sarà uguale a quello della funzione che utilizzava il ciclo `for`:

```
% g++ src/cpp/pianeti-while-bool.cpp \
      src/cpp/pianeti.cpp \
   -o src/out/esempio
% src/out/esempio                     
1: Venere
2: Terra
3: Marte
4: Giove
5: Saturno
6: Urano
7: Nettuno
8: Plutone
9: Inserire un valore da: 1 a 9
```

Il ciclo `do-while` è uguale al ciclo `while` con la sola differenza che la condizione `while` viene valutata alla fine dell’iterazione e quindi il corpo del ciclo viene eseguito almeno per una volta. 
La forma generale del ciclo `do-while` è:

```
do
{
    <istruzioni>        // corpo del ciclo
} while(espressione)    // espressione di controllo
```

<hr id="isolamento-funzionale">

Non offenderò la tua intelligenza con un esempio; vorrei piuttosto farti notare una cosa grave: il codice di questi programmi è sgraziato.
Il problema è che la funzione mostraPianeta fa troppe cose: non solo stabilisce il nome del Pianeta, ma lo stampa anche a video.
In conseguenza di ciò, nel nostro output abbiamo anche quella brutta stringa di errore relativa alla posizione numero nove.
Nel primo esempio in cui l'abbiamo utilizzata, questo non era un problema, ma adesso che il nostro programma si sta sviluppando, dobbiamo rendere ciascuna funzione più specialistica, dividendo l'elaborazione dei dati (capire quale sia il pianeta) dall'interfaccia utente (la stampa a video del nome).
Per fare ciò, utilizzeremo una nuova funzione che aggiungeremo al file `pianeti.cpp`:

```
/**
 *  nomePianeta 
 *  Torna il nome di un pianeta, data la sua posizione.
 *  @param  int    posizione Posizione del pianeta.
 *  @return string nome      Nome del pianeta o null, se errore.
 */
string nomePianeta(int posizione)
{    
    string nome;

    /** 
     * Questa funzione gestisce solo i casi esistenti 
     * e lascia che sia la funzione chiamate a gestire
     * eventuali errori.
     */
    switch( posizione ) {
        case POS_MERCURIO: 
            nome = "Mercurio";          
            break;
        case POS_VENERE:   
            nome = "Venere";            
            break;
        case POS_TERRA:    
            nome = "Terra";             
            break;
        case POS_MARTE:    
            nome = "Marte";             
            break;
        case POS_GIOVE:    
            nome = "Giove";             
            break;
        case POS_SATURNO:  
            nome = "Saturno";           
            break;
        case POS_URANO:    
            nome = "Urano";             
            break;          
        case POS_NETTUNO:  
            nome = "Nettuno";           
            break;          
        case POS_PLUTONE:  
            nome = "Plutone";           
            break;
    } 
    
    return nome;
}
```
La nuova funzione `main` sarà:

```
{% include_relative src/pianeti-while-string.cpp %}
```

Il codice è sintatticamente più complesso, ma una volta capito che l'istruzione:

```
while(!(nome = nomePianeta(p)).empty())
```

significa:

> esegui la funzione `nomePianeta` passandole come parametro la variabile `p` finché non ti torna una stringa vuota
 
il flusso del programma diventa più evidente di quanto fosse nei casi precedenti.
Il corpo del ciclo è passato da tre istruzioni a una e le due operazioni di elaborazione e visualizzazione sono ben distinte nel tempo.
Oltre ad aver ottenuto un codice più facile da leggere, da correggere da eseguire e da modificare, ci siamo anche sbarazzati dell'odioso messaggio di errore.
Direi che ne valeva la pena, no?

<hr id="dottrina">

La religione dovrebbe aiutare l’Uomo a vivere meglio. Dovrebbe dare uno scòpo alla nostra esistenza, aiutarci a superare i momenti di dolore e definire una scala di valori che ci permetta di prendere delle decisioni in quei casi in cui il raziocinio o il semplice buon senso non possono essere d’aiuto. 
Finora, però, le religioni non hanno aiutato l'Umanità a vivere meglio, anzi: hanno avuto spesso l'effetto opposto perché sono state prese a pretesto per guerre, soprusi e contrasti più o meno violenti.
Ciò dipende da due fattori: la natura umana e la mancanza di solidità logica dei loro principii. Infatti, dovendo interessarsi di argomenti che non possono essere sottoposti a un'analisi razionale, le religioni sono costrette a dedurre le regole della propria dottrina da una serie di dogmi non dimostrabili che i seguaci della religione &mdash; i quali, non a caso, sono detti: “fedeli” o: “credenti” &mdash; devono accettare per buoni senza metterli in discussione.  
I dogmi sono i pilastri su cui si regge l’edificio della dottrina; se uno di essi si indebolisse o, peggio, se fosse rimosso, l’edificio rischierebbe di crollare, quindi ogni forma di eresia è vista dagli apparati ecclesiastici come un potenziale pericolo che va scongiurato con ogni mezzo, anche a costo di abiurare quegli stessi principii che si cerca di difendere. 
Questo, però, non fa che peggiorare le cose, perché i dogmi non sono leggi comprovabili, ma opinioni o speranze e ogni tentativo di renderli più robusti ottiene l’effetto opposto perché si ampliano le dimensioni di una struttura che poggia su basi instabili.  
Aristotele disse che:
 
> le scienze che derivano da un numero minore di premesse sono più rigorose delle scienze che ne discendono per mezzo dell’aggiunta di nuove premesse
 <a href="/man/note/#aristotele" class="nota"></a>

In quest'ottica, il C'hi++ è una metafisica abbastanza rigorosa, perché richiede l'accettazione di due sole affermazioni non comprovabili e, di queste, solo una è strettamente necessaria alla coerenza interna della dottrina, l'altra è solo un auspicio.  
Ai fedeli del C'hi++ è richiesto di credere, anche in assenza di prove o in presenza di prove contrarie (gli scienziati non sono infallibili: sono gli stessi che avevano visto dei canali su Marte) 
<!-- 
@todo: valutare utilizzo di questo aneddoto (dopo averlo verificato..)
Lemaitre fu il primo a formulare la teoria dell’espansione dell’universo, che nel 1949 Fred Hoyle, togato docente di Cambridge, sostenitore della teoria dello stato stazionario, con una punta di sarcasmo, chiamò teoria del Big Bang.
Gregori, Claudio. Merckx, il Figlio del tuono (VITE INATTESE) (Italian Edition) (Kindle Locations 7169-7172). 66THAND2ND. Kindle Edition. 
-->
che ci sarà un momento in cui l'espansione dell'Universo terminerà e che tutto ciò che esiste tornerà a riunirsi nell'Uno primigenio:

```
void eternita() 
{
    /** 
     * La condizione è sempre vera, quindi il ciclo si ripete
     * indefinitamente
     */
    while(1) {
        
        unoPrimigenio();
        
        bigBang();
        
        espansione();
        
        contrazione();
        
        bigCrunch();
        
        /**
         * Il fatto che questa istruzione sia a commento è
         * una delle differenze fra C'hi++ e Buddismo.
         * if(satori()) break;     
         */  
    }
}
```

Se non ci fosse questa ciclicità, ovvero senza un'alternanza fra Entropia e Gravità, fra *Prakṛti* e *Puruṣa*, lo Spazionismo e, di conseguenza, il C'hi++ non avrebbero più senso, così come la nostra esistenza.
La Vita si rivelerebbe un epifenomeno destinato a esaurirsi nella morte termica dell'Universo e nessun ordine sociale sarebbe più possibile, perché ciascuno cercherebbe di ottenere il massimo possibile dai pochi anni che gli sono concessi, indifferente al costo che questo avrebbe per gli altri. 
Qualcosa di simile al *Black Friday* in un centro commerciale americano, per intendersi.. <a href="/man/note/#blackfriday" class="nota"></a>

```
typedef struct {
    string evento;
    bool   esito;
} PostIt ;
```

Il secondo dogma del C'hi++ è l'esistenza di una memoria persistente dell'Universo che mantiene traccia dell'esito delle scelte fatte in ciascun ciclo; qualcosa di simile all'inconscio collettivo di Jung o ai *vāsanā* dell'Induismo:

> {{ site.data.citazioni.gita.vasana }}<a href="/man/note/#vasana" class="nota"></a>

I *Post-It*, come li chiamava il Maestro Canaro, non sono indispensabili per il C'hi++, sono solo un'auspicio, perché la loro esistenza dà un senso alla nostra vita.
Ho detto: *dà* in vece di: *darebbe* perché, così come avviene per gli esopianeti, noi non li “vediamo”, ma possiamo inferire la loro esistenza dall'effetto che hanno su ciò che li circonda: istinto, premonizioni, *deja-vu*.  
L'esistenza dei *Post-It* rende l'Universo *stateful*<a href="/man/note/#stateful" class="nota"></a> e quindi più appetibile per noi, ma anche in un Universo *stateless*<a href="/man/note/#stateful" class="nota"></a>, in cui ciascun ciclo di esistenza fa storia a sé, noi non avremmo né motivo né convenienza a comportarci in maniera egoistica.
In primo luogo perché, come abbiamo già detto, essendo tutti la manifestazione di una stessa Energia, ciò che facciamo agli altri lo facciamo in realtà a noi stessi; in secondo luogo perché non è detto che in ciascun ciclo di esistenza il nostro io cosciente si manifesti nella stessa persona e quindi, se in un ciclo siamo *Jack the Ripper*, in un altro potremmo essere Mary Ann Nichols.  
I *Post-It* furono sempre una spina nel fianco, per il Maestro Canaro, che spese gli ultimi anni della sua vita cercando un modo per ricondurli a qualcosa di reale o di eliminarli dalla dottrina, ma non riuscì a fare nessuna delle due cose. 
Inizialmente pensò la cosa più ovvia, ovvero che i Post-It fossero nel cervello, che fossero una particolare mappatura delle sinapsi contenente le istruzioni per reagire a determinate condizioni future<a href="/man/note/#openworm" class="nota"></a>.
Ipotizzò anche che i sogni avessero la duplice funzione di prepararci a queste condizioni, anticipandocele e tenendo vive le connessioni cerebrali che avremmo dovuto sfruttare per affrontarle.
Tutto questo, però, poteva essere solo una proiezione dei Post-It, una copia in memoria RAM di informazioni preservate altrove, perché, per poter essere persistenti, i Post-It devono trovarsi al di fuori dello *scope* della nostra esistenza, nella ROM o nell'*hard-disk* dell'Universo:

```

/** Dichiarazione della struttura PostIt */
typedef struct {
    string evento;
    bool   esito;
} PostIt ;

void eternita() 
{
    /** Array di puntatori a PostIt */
    PostIt** vasana;

    while(1) {
        
        /** Inizio di un nuovo ciclo */
        unoPrimigenio();        
        bigBang();
        
        /**
         *  L'array di eventi viene passato alle fasi
         *  espansione e di contrazione, che lo incrementano
         *  in funzione delle esperienze fatte dagli 
         *  esseri senzienti
         */
        espansione(vasana);        
        contrazione(vasana);

        /**
         *  Qui gli esseri senzienti sono annichiliti,
         *  ma l'informazione non si perde, perché è 
         *  salvata altrove
         */
        bigCrunch();
    }
}
```

I Post-It, quindi, sono per definizione metafisici (o, nel caso del codice qui sopra, *meta-ciclici*) perché tutto ciò che è fisico verrà annichilito al termine di un ciclo di esistenza e rigenerato all'inizio del seguente.
Possiamo credere nella loro esistenza, ma dobbiamo farlo per fede, in maniera dogmatica.  
Il Maestro Canaro rifuggiva i dogmi; diceva che se tu imponi una verità, poi sei legato a essa e non puoi più cambiare idea, anche se ti accorgi di avere sbagliato.
Prendi il tuo libro, per esempio; quel sottotitolo che hai scelto: *Lo scopo della vita è il debug* ti impone di credere nei Post-It.
Se il giorno dopo che l'hai pubblicato si scoprisse che non esistono, saresti costretto a ristamparlo o ad accettare il fatto che dice una cosa non vera.
Il Maestro Canaro non voleva che questo avvenisse al C'hi++; per questo motivo, stabilì che dovesse avere un versionamento, come il software: perché potesse evolversi.  

---

I letterati, gli scultori, i pittori non possono modificare le loro opere, una volta che sono state pubblicate. Possono dare un ritocco di colore qui, un colpo di scalpello là, ma si tratta sempre di aggiustamenti minimi, che non cambiano la struttura stessa dell'arte-fatto.
I musicisti, i teatranti e, in parte, i cineasti sono un po' più fortunati, perché possono apportare più facilmente delle modifiche alle loro opere, ma si tratta comunque di eventi che accadono di rado.  
Al contrario, la buona produzione di software ha il vantaggio di essere in continua evoluzione.
Un software può essere *stabile*, ovvero non avere difetti noti, ma non è mai finito, completo, *perfetto*; sia perché l'utilizzo potrebbe rivelare dei difetti sfuggiti alla fase di test, sia perché delle variazioni del contesto di utilizzo potrebbero richiedere delle modifiche al sistema.
Il buon software viene quindi costantemente aggiornato e le diverse versioni di uno stesso prodotto sono numerate in maniera progressiva con dei codici composti da tre numeri separati da punti che indicano, rispettivamente, la versione *major*, la versione *minor e* la *patch*; per esempio: *1.4.12*.
La versione *major* viene incrementata ogni volta che si apportano delle drastiche modifiche al software, rendendolo incompatibile con le versioni precedenti.
La versione *minor* viene incrementata quando si modifica il codice in maniera minore, aggiungendo o modificando delle funzionalità in maniera compatibile con le versioni precedenti.
Il numero di *patch* è incrementato ogni volta che si apportano delle modifiche o delle correzioni anche minime al sistema.
La *major version zero* (_0.y.z_) è destinata allo sviluppo iniziale, quando il software non è ancora stabile e tutto può cambiare in ogni momento.  

---

Prima ti ho detto che gli scienziati non sono infallibili. 
Non è una maldicenza: è la verità; gli scienziati sono i primi ad ammetterlo e questa è la loro forza, perché possono correggere i loro errori senza perdere di credibilità.
Il Maestro Canaro voleva che questo fosse possibile anche per il C'hi+.
Come scrisse alla fine della sua <a href="/proposta" target="proposta">*Proposta per una metafisica open-source*</a>:

> Se anche un giorno dovessi scoprire che gli elementi costituivi dell'Universo non si chiamano *spazioni*, ma *culturi* e fossi per ciò costretto a cambiare il nome della mia cosmogonia in *Culturismo*, io incrementerò di un'unità la *major-version* del mio progettto e andrò avanti.
Non per ostinazione, né per idealismo, ma perché questa *metafisica-non-metafisica*, come l'ho definita prima, funziona: mi aiuta a decidere quale sia la cosa giusta da fare quando non è facile capire quale sia la cosa giusta da fare e mi aiuta ad affrontare i momenti difficili della vita, mia o altrui che sia, senza accettazioni per fede, ma basandomi solo su considerazioni di ordine logico.
Inoltre, è una storia che non è ancora stata scritta e, allo stesso tempo, la storia che la nostra razza scrive da sempre.
Mi sembra un motivo più che sufficiente. 

<!--

@todo: 

- introdurre l'idea delle "variazioni" della storia dell'Universo

L'Esistenza potrebbe essere un sistema per smaltire l'energia dell'Universo (o di quello che ha intorno), così come le perturbazioni sono un sistema per smaltire l'energia dell'atmosfera?

Eudosso scrive che gli Egiziani raccontano di Zeus questa storia. Il dio non poteva camminare, giacché le sue gambe erano sin dalla nascita saldate in un pezzo solo, e per la vergogna passava il suo tempo in solitudine. Fu Iside a tagliare e separare quella strana parte del suo corpo, mettendolo così in grado di camminare con le sue gambe. E il significato della storia è che la mente e la ragione del dio sono di per sé immobili nell’invisibile e nell’insensibile, e prendono la strada della creazione grazie a una spinta motrice.
Plutarco, citato da Giorgio Santillana, Sirio, Adelphi. 
Confrontare con le divinità con una sola gamba, come Houragan

In Borges, *Finzioni*: lo scrittore che vuole riscrivere Don Chisciotte dice che potrebbe farcela, se solo fosse immortale (v. *Breve storia dell'Infinito*). La stessa cosa vale per l'Universo: avendo a disposizione un tempo infinito, la ripetizione è inevitabile.

-->
