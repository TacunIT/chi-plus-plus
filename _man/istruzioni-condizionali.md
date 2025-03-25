---
class:      capitolo
layout:     manuale
og_desc:    "Come decidere cosa sia giusto e cosa no - I roghi, prima e dopo il 6 Giugno del 1945 - L'importanza del pentimento - Perché Nansen potè tagliare in due il gatto"
og_img:     "/assets/img/og-img/istruzioni-condizionali.jpg"
permalink:  /man/istruzioni-condizionali
quote:      "Fare qualcosa d’intenzionale implica capire che esistono delle alternative, e sceglierne una; e questi sono attributi dell’intelligenza artificiale"
status:     pubblicato
title:      "Istruzioni condizionali"
---

<!--
La perifrasi è da: Asimov, Isaac. Civiltà extraterrestri (Italian Edition) . MONDADORI. Kindle Edition.
-->

Le istruzioni condizionali sono l'elemento più importante del codice.

Ogni programma deve saper reagire correttamente al variare delle condizioni di utilizzo; per far ciò, si utilizzano le cosiddette *istruzioni condizionali*, che permettono di definire il comportamento del sistema a seconda che una determinata condizione si riveli vera o falsa.  
Il C++ possiede due tipi di istruzione condizionale: le sequenze `if-else` e l'istruzione `switch`.  
La forma generale delle istruzioni `if-else` è la seguente:

```
if ( <condizione> ) {
    // istruzioni da eseguire se la condizione è vera
} else {
    // istruzioni da eseguire se la condizione è falsa
}
```

Se l'espressione condizionale all'inizio del codice è vera, il programma eseguirà il primo blocco di istruzioni; se no, eseguirà il secondo blocco di istruzioni.

```
if ( a > 8 ) {
    cout << "maggiore" << endl;
} else {
    cout << "minore" << endl;
}
```

Se la condizione falsa non richiede alcuna azione specifica, il secondo blocco di istruzioni può essere omesso:

```
typedef Importo unsigned long;

Importo raddoppiaStipendio(Importo stipendioCorrente)
{
    if ( stipendioCorrente > 0 ) {
        stipendioCorrente *= 2;
    }    
    return stipendioCorrente;   
}
```

Allo stesso modo, le parentesi graffe possono essere omesse se il blocco istruzioni che racchiudono è costituito da una singola istruzione:

```
if ( a > 8 )
    cout << "maggiore" << endl;
else
    cout << "minore" << endl;
```

Personalmente, trovo che questa forma sia inelegante e che renda il codice meno chiaro, favorendo quindi gli errori.
La utilizzo solo nelle istruzioni di gestione degli errori, dove il flusso del programma si interrompe bruscamente, perché l'aspetto sgraziato dell'istruzione evidenzia l'eccezione, rendendo il codice più auto-esplicativo.

```
if ( divisore == 0 )
    throw std::runtime_error("errore");
```

Se le condizioni da valutare sono più di due, si possono concatenare più istruzioni condizionali utilizzando l'istruzione `else if`, che permette di definire una condizione alternativa alla prima e di associarle un blocco di codice.
Anche in questo caso, si può chiudere la sequenza con un'istruzione `else`, definendo un blocco di istruzioni da eseguire se non si verifica nessuna delle condizioni previste.

```
if ( <prima condizione> ) {
    /*
     * istruzioni da eseguire se
     * la prima condizione è vera
    */
} else if ( <seconda condizione> ) {
    /*
     * istruzioni da eseguire se
     * la prima condizione è vera
     */
} else {
    /*
     * istruzioni da eseguire se nessuna
     * delle due condizioni è vera
     */
}
```

Le istruzioni `if-else` influenzano la leggibilità del codice; è una cosa di cui il buon programmatore deve sempre tenere conto.
Il C++ è un linguaggio indipendente dalla formattazione, quindi, una stessa istruzione può essere scritta in molte maniere diverse:

```
if ( <condizione> )
{
    ...
}
else
{
    ...
}
```

o, pure:

```
if ( <condizione> ) {
    ...
} else {
    ...
}
```

o perfino:

```
if ( <condizione> ) { ...} else { ... }
```

Se le istruzioni sono poche e semplici, una forma vale l'altra (fatte salve le questioni di stile, ovviamente), ma se il flusso del programma fosse, come di solito avviene, più complesso, è necessario fare in modo che la forma dell'istruzione semplifichi la scrittura, la lettura e un'eventuale correzione del codice.  
Immagina un brano di codice che debba fare una verifica all'inizio dell'elaborazione e, a seconda dell'esito, eseguire una sequenza di istruzioni o inviare un messaggio di errore:

```
if ( <condizione> ){
    /*
     * righe di codice da
     * eseguire in caso la
     * condizione sia vera
     */
} else {
    /* gestione dell'errore */
}
```

Se le istruzioni da eseguire in caso di buon successo della verifica sono poche e semplici, questa sequenza non darà problemi, ma se, al contrario, le istruzioni fossero tante e complesse, leggendo il codice potresti arrivare all'istruzione `else` e non ricordarti più a quale condizione fosse associata.
In questi casi, io preferisco la forma:

```
if ( <errore> ) {
    /* gestione dell'errore */
} else {
    /*
     * righe di codice da
     * eseguire in caso la
     * condizione sia vera
     */
}
```

Dato che la gestione dell'errore non richiederà mai più di qualche riga di codice, potrai capire a colpo d'occhio tutto il flusso del programma, indipendentemente dalla lunghezza del secondo blocco di istruzioni.  
Tutto questo, ovviamente, non vuole essere né un invito né una giustificazione per la scrittura di istruzioni complesse.
A meno che non sia necessario limitare le chiamate a funzione per garantire un'alta velocità di esecuzione, è sempre meglio scomporre il flusso del programma in una serie di funzioni distinte e specializzate.
Renderai il tuo programma un po' più lento (o, meglio: un po' meno veloce), ma il codice sarà molto più facile da leggere o da modificare.  
<!-- @todo parlare del "codice spaghetti". -->
Immagina adesso un brano di codice che richieda molte condizioni `if` concatenate:

```
esito = 0;

if ( <condizione 1> ) {
    esito = 1;
} else if ( <condizione 2> ) {
    esito = 2;
} else if ( <condizione 3> ) {
    esito = 3;
} else {
    esito = 9;
}

return esito
```

Questa forma, per quanto corretta e formalmente ineccepibile, potrebbe rivelarsi difficile da gestire se le condizioni da considerare fossero molto complesse o numerose.
Il buon programmatore, allora, può decidere di contravvenire alla (giusta) norma che prescrive di non inserire delle istruzioni `return` all'interno del codice, e scrivere la sequenza in questo modo:

```
esito = 0;

if ( <condizione 1> ) {
    return 1;
}
if ( <condizione 2> ) {
    return 2;
}
if ( <condizione 3> ) {
    return 3;
}

return 9
```

Non ti sto dicendo che sia giusto scrivere così e vedi da solo che il codice è rozzo e inelegante, ma ci potrebbero essere dei casi in cui sia questa, la forma da preferire.
Per esempio, per un sistema che generi del codice in maniera automatica, è molto più semplice gestire delle istruzioni `if` isolate che delle condizioni `if-else` concatenate.
Pensa a una *stored-procedure* che debba controllare l'integrità referenziale dei parametri ricevuti:

```
{% include_relative src/istruzioni-condizionali-stored-procedure.sql %}
```

Se scrivi il codice in questa maniera, puoi inserire o rimuovere un parametro (e i relativi controlli) senza alterare il resto del codice, cosa che non avverrebbe se tu concatenassi le istruzioni `if`.
Perderai un po' di velocità di esecuzione, ma il codice sarà molto più facile da scrivere o da modificare.  
Attento, però: mettere in sequenza delle semplici istruzioni `if` è cosa
ben diversa dal creare una catena di istruzioni `else-if` perché, se in caso di errore non blocchi l'elaborazione con un'istruzione `return`, il programma andrà avanti verificando le condizioni seguenti e l'errore nella prima condizione potrebbe ripercuotersi sul codice successivo:

```
/** Qui comincia il male.. **/
if ( divisore == 0 ) {
    cout << "Errore: divisione per zero" << endl;
}

/** ..e il peggio lo segue **/
if ( (dividendo / divisore) > 1 ) {
    ...
}
```

Non avendo un'istruzione `return` il codice della prima verifica non bloccherà l'esecuzione della funzione, che andrà in errore quando proverà a eseguire una divisione per zero.

---

L’istruzione `switch` permette di gestire più casi, basandosi sulla valutazione di una espressione:

```
switch(<espressione>)
{
    case <costante> : istruzioni... [break];
    case <costante> : istruzioni... [break];
    ...
    default: istruzioni...
}
```

Le parole-chiave `case` e `default` identificano i valori gestiti dall'istruzione `switch`.
I `case` possono (ed è utile che siano) più di uno, ma le costanti associate a ciascuno di essi devono avere dei valori diversi.
La condizione `default`, al contrario, deve essere unica.   
L'esecuzione dell'istruzione inizia al `case` la cui costante è uguale al valore dell'espressione di `switch` e termina alla parola chiave `break`.
Se l'espressione ha un valore non previsto dai `case`, l'istruzione esegue il codice associato all'etichetta `default`:

```
{% include_relative src/istruzioni-condizionali-switch.cpp %}
```

Compilando ed eseguendo questo codice, otterrai:

```
% g++ src/cpp/istruzioni-condizionali-switch.cpp -o src/out/esempio
% src/out/esempio                                                  
Inserire un valore da: 1 a 9
% src/out/esempio 4
Marte
% src/out/esempio terra
Valore non valido
```

In sostanza: con una `break` alla fine di ciascun caso, l'istruzione `switch` è una forma più elegante (ed efficiente) dell'istruzione `if - else if`:

```
if(piaeta == POS_ERRORE) {
   cout << "Valore non valido";
} else if(pianeta == POS_MERCURIO) {
    cout << "Mercurio";
} else if(pianeta == POS_VENERE) {
    cout << "Venere";   
} else if ..         
```

Se tu togliessi le interruzioni `break` alla fine di ciascun caso, l'output del programma sarebbe:

```
% src/out/esempio 4    
MarteGioveSaturnoUranoNettunoPlutoneInserire un valore da: 1 a 9
```

che in questo caso non ha senso, ma che può essere la scelta adatta se due casi possibili vanno elaborati nella stessa maniera.  
Un'ultima cosa: ricordati sempre che, per dichiarare delle variabili all'interno dei `case`, è necessario aggiungere delle parentesi graffe; altrimenti, avrai un errore in fase di compilazione:

```
switch( x ) {
    case 1:
        int y = 9;      /** errore di complilazione */
        cout << x + y;
        break;
    case 2: {
        int y = 2;      /** corretto */
        cout << x + y ;
        break;
    }
    default:
        cout << "default" << endl;
}

```

<hr id="dottrina">

La vita ci chiede spesso di fare delle scelte condizionali.
Quando ciò avviene, hai due possibilità: o fai la scelta più conveniente per te o fai la scelta che ti sembra più conveniente per il maggior numero di persone per il più lungo periodo di tempo possibile.
Nel primo caso sarai un vettore di Entropia, mentre nel secondo caso sarai un paladino della Gravità.  
Come sai, per il C'hi++ la scelta esatta (inteso come participio passato del verbo *esigere*) è la seconda: tutta la materia non è che la manifestazione di una unica Energia, quindi ha poco senso distinguerci gli uni dagli altri;
 dobbiamo invece ragionare come Saʿdi di Shirāz, quando dice:

> Son membra d’un corpo solo i figli di Adamo,
da un’unica essenza quel giorno creati.
E se uno tra essi a sventura conduca il destino,
per le altre membra non resterà riparo.<a class="nota" href="/man/note#fn-saadi" id="saadi">1</a>

Cercare il proprio tornaconto personale a discapito degli altri è sbagliato.
Bisogna comportarsi bene e cercare di convincere anche gli altri a fare altrettanto, perché, come recita il *Mantiq al-Tayr*:

> tutto il male o il bene che feci,
in verità lo feci solo a me stesso<a class="nota" href="/man/note#fn-mantiq" id="mantiq">2</a>.

Ma come si fa a capire cosa sia *bene*?
Ci sono casi in cui è facile dare la scelta giusta, come nel caso del maestro Zen Bokuju<a class="nota" href="/man/note#fn-bokuju" id="bokuju">3</a>:

```
switch( stimolo ) {
    case fame:  
        azione = mangio;
        break;
    case sonno:
        azione = dormo;
        break;
    case sete:  
        azione = bevo;
        break;
}
```
ma altre volte ci troviamo di fronte a scelte più complesse:

> Una ragazza è rimasta incinta a séguito di una violenza: può decidere di abortire?

oppure:

> Un uomo, condannato per omicidio, in carcere ha ucciso altri due carcerati e una guardia: va condannato a morte o no?

Se queste domande le fai a un cattolico, lui &mdash; coerentemente con il suo Credo &mdash; ti risponderà che no, non è possibile né abortire né condannare a morte perché la vita è un dono di Dio e nessuno ce ne può privare.
Se invece queste domande le poni a un Giudice, avrai risposte diverse a seconda della Nazione a cui appartiene, perché mentre sottrarre dei beni materiali è considerato un reato ovunque, esistono degli Stati in cui è permesso sottrarre a un individuo il bene più prezioso che ha.   
Un tempo, i credenti mettevano al rogo gli scienziati, accusandoli di eresia; il 6 Giugno del 1945, però, la Scienza ha mostrato al Mondo il suo potere ed è diventata di fatto il nuovo Dio per milioni di persone; da allora, le parti si sono invertite e adesso sono gli scienziati a mettere al rogo ogni forma di spiritualità.
Il problema è che se privi la giurisprudenza di una base spirituale, quello che otterrai sono Leggi *pret-a-porter*, rimedii temporanei a delle esigenze contingenti.
Nella migliore delle ipotesi.  
La teocrazia è un errore, ma anche la *a*-teocrazia dev'essere evitata.
La Fede è stata la colla che ha tenuto unita la nostra società per quasi duemila anni.
Gran parte di quella colla era solo una nostra invenzione, ma lo sono anche gli Stati, il denaro, i Diritti Umani, le Leggi<a class="nota" href="/man/note#fn-sapiens" id="sapiens">4</a>.
Nessuno di questi concetti così importanti per la nostra Società esiste davvero, ma li utilizziamo lo stesso perché, come il linguaggio *C*, pur essendo solo delle convenzioni, sono utili al loro scòpo.  
Ora che questa colla non c'è più, le scelte dei legislatori non sono più mosse dal perseguimento di un obiettivo comune (corretto o sbagliato che fosse), ma dalla ricerca dell'approvazione di un elettorato composto in buona parte da zombie culturali<a class="nota" href="/man/note#fn-istat" id="istat">5</a> e da egoisti che perseguono unicamente il proprio interesse momentaneo: il pascolo ideale per demagoghi con aspirazioni dittatoriali.
La minoranza di idealisti e di persone colte, priva di valori trascendenti, non può che agire in base ai propri sentimenti o ai propri auspici e subisce inevitabilmente il malefico influsso dell'Annosa Dicotomia: fanno scelte che puntano al bene comune, ma si tratta di un bene comune molto spesso miope e temporaneo.
Come scacchisti mediocri, vedono ciò che è bene qui e ora, ma non riescono a valutarne le conseguenze a lungo termine.  
Pensa a quale potrebbe essere, secondo te, la soluzione giusta alle due domande che ti ho fatto e poi pensa al *motivo* quella soluzione ti appare giusta.
Perché permettiamo la soppressione di un feto che non ha fatto del male a nessuno, mentre lasciamo in vita chi ne ha già fatto?
Vogliamo fare la cosa giusta o vogliamo solo sentirci buoni?  
Il Maestro Canaro si fece molti nemici con la sue idee sull'aborto.
<!--
@todo: valutare la possibilità di aggiungere i punti interessanti della conversazione con Massimo:
    a. non sono cattolico, ma ho studiato embriologia e so quando
       qualcosa smette di essere un agglomerato di cellule e diventa
       altro
    b. quando, un programma diventa un programma?
    c. l'aborto non può essere un metodo contraccettivo: una volta
       nella vita, è possibile, ma non tre volte l'anno. -->
Anche alcune persone che inizialmente lo avevano appoggiato lo accusarono di cercare l'appoggio della Chiesa Cattolica, mentre stava solo applicando il precetto del *Metta Sutra* che predica la felicità non solo per tutti coloro che sono nati, ma anche per coloro che devono nascere:

> bhåtà và sambhavesã và sabbe sattà bhavantu sukhitattà<a class="nota" href="/man/note#fn-metta" id="metta" >6</a>

<p class="metta">
<i>bhåtà</i> quelli che sono nati<br />  
<i>và</i>  o  <br />
<i>sambhavesã</i> quelli che cercano la nascita  <br />
<i>và</i> o  <br />
<i>sabbe</i> tutti  <br />
<i>sattà</i> gli esseri   <br />
<i>bhavantu</i> possano essere  <br />
<i>sukhitattà</i> felici nel loro cuore
</p>

Tutto questo a lui non importava: quando gliene parlai, mi disse che preferiva perdere un milione di seguaci che una vita.    

<hr id="pentimento">

Rispondere alla domanda sul condannato è più difficile.
Lo scòpo delle tue azioni deve essere, come sempre, il miglioramento: chi sbaglia deve capire che ha fatto un errore e non ripeterlo in altri cicli di esistenza:

```
int pentimento( azione ){

    bool ripetere;

    if ( azione == errore ) {
        ripetere = false;
    } else {
        ripetere = true;
    }

    return ripetere;
}
```
Se il peccatore è davvero pentito, allora è giusto che sia assolto, perché, come dice Attar:

> Cento Mondi di peccato sono dissipati dalla luce di un solo pentimento<a class="nota" href="/man/note#fn-pentimento" id="pentimento">7</a>.

Ma il pentimento dev'essere reale: il peccatore deve detestare il suo errore e scegliere di morire piuttosto che ripeterlo ancora.  
Tagliare una mano a chi ruba, costringendolo a portare il cibo alla bocca con la stessa mano con cui si pulisce il sedere, è un metodo un po' drastico, ma efficace per costringere qualcuno a meditare sull'insensatezza delle sue azioni passate &mdash; specie in un luogo come il deserto, dove i bidet sono più rari che in Francia.
La *Lex Talionis* può funzionare per reati minori, perché chi la subisce ha il tempo di riflettere sui suoi errori, ma nel caso di un omicidio non solo è contraria all'obbligo di benevolenza che abbiamo nei confronti degli altri esseri senzienti, ma potrebbe anche essere controproducente, perché se il condannato non capisce il suo errore prima di morire è possibile che le sue azioni delittuose vengano ripetute in altri cicli dell'Universo.  
D'altro canto, abbiamo un obbligo di benevolenza anche nei confronti degli altri carcerati e delle guardie carcerarie, quindi non possiamo lasciare che il condannato li uccida.
La soluzione ideale sarebbe quella di metterlo in condizione di non nuocere a terzi, lasciandolo poi meditare sui suoi errori, ma se questo non fosse possibile, come ci dovremmo comportare?
Se un individuo riconosce i proprii errori e impara da essi, contribuisce al miglioramento dell'Universo; se invece ripete più volte lo stesso atto delittuoso evidentemente non capisce o non vuole capire il suo errore.
Se non capisce, non è *senziente*, quindi non può concorrere al miglioramento dell'Universo.
Se non è utile al miglioramento, possiamo considerarlo alla stessa stregua del gatto di Nansen:

> Nansen un giorno vide i monaci delle sale Orientali e Occidentali che litigavano per un gatto.
Egli sollevò il gatto e disse: “Se mi direte una parola di Zen, salverò il gatto; se no, lo ucciderò”.  
Nessuno seppe rispondere e Nansen tagliò il gatto in due<a class="nota" href="/man/note#fn-nansen" id="nansen" >8</a>.

Per lungo tempo, il Maestro Canaro si chiese perché Nansen potesse tagliare in due l'incolpevole gatto.
La spiegazione che si diede fu che il gatto non essendo un essere senziente, e quindi incapace di contribuire con la propria esperienza alla crescita dell'Universo, fosse sacrificabile, se ciò poteva portare in qualche all'Illuminazione dei monaci.  
Attenzione, però: la morte del condannato, se mai dovesse rendersi necessaria, non deve essere considerata una vendetta di cui gioire, ma un evento tanto doloroso quanto inevitabile, di cui dolersi come di un'amputazione.
Ciascuno, in quel giorno, dovrebbe chiedersi se, con *pensieri, parole, opere e omissioni*, non abbia contribuito in qualche modo a quella perdita.
Una Società che esalta l'individualismo, il successo e il denaro non può dirsi del tutto innocente se chi non ha i mezzi o la capacità di ottenerli in maniera lecita cerca di procurarseli in altro modo.

---

Un insegnante buddhista, saputo che il Maestro Canaro, nei suoi scritti, sosteneva che non c'è modo di sottrarsi al ciclo delle rinascite, si recò da lui e, deciso a dimostrare che si sbagliava, lo sfidò a un *Dharma Combat* per chiarire le reciproche posizioni.
Il Maestro Canaro rispose che non sapeva cosa fosse un *Dharma Combat*; al che, l'insegnante buddhista spiegò che era un confronto dialettico, per dimostrare la propria conoscenza della dottrina.
Il Maestro Canaro allora annuì e disse:
“Va bene, ma prima che cominciamo, dimmi se tu, questo confronto, lo vuoi vincere o perdere, in modo che io possa accontentarti.”
Sentendo quelle parole, l'insegnante buddhista si rese conto che le sue intenzioni non erano pure: non voleva quella sfida per arrivare alla verità, ma solo per il piacere della vittoria.
Così si inchinò, ringraziò il Maestro Canaro per avergli fatto capire quella sua debolezza e, da quel momento in poi, divenne un suo discepolo.

<!--

@todo

Il Metta Sutra predica la benevolenza per tutti gli "esseri che respirano"

> Ye keci pàõa-bhåt' atthi

<p class="metta">
<i>Ye keci</i> Ciascun<br />
<i>pàõa-</i>   respirante<br />
<i>bhåt'</i>   essere<br />
<i>atthi</i>   che esiste<br />
</p>

allora, perché Nansen taglia in due il gatto? e perché i maestri Zen potevano uccidere i loro discepoli?
Ho cercato la definizione di "senziente", ma non mi sembra che ci sia una risposta univoca.
In attesa di accertare la questione (posto che sia possibile),

Il Contrappasso:

6. citare l'esempio del notaio in un'auto guidata da un sistema di IA e del sito che cerca di creare un'etica accumulando pareri (non fornire soluzione, per ora?);

-->
