---
status:     redazione
layout:     manuale
class:      capitolo
title:      Istruzioni condizionali
permalink:  /man/istruzioni-condizionali
quote:      "Fare qualcosa d’intenzionale implica capire che esistono delle alternative, e sceglierne una; e questi sono attributi dell’intelligenza"
---

<!-- 
La citazione è da: Asimov, Isaac. Civiltà extraterrestri (Italian Edition) . MONDADORI. Kindle Edition. 
-->

Le istruzioni condizionali sono l'elemento più importante del codice.

Ogni programma deve saper reagire correttamente al variare delle condizioni di utilizzo; per far ciò, si utilizzano le cosiddette *istruzioni condizionali*, che permettono di definire il comportamento del sistema a seconda che una determinata condizione si riveli vera o falsa.  
Il C++ possiede due tipi di istruzione condizionale: le sequenze `if-else` e l'istruzione `switch`.

### Istruzioni if-else

La forma generale di questa istruzione è la seguente:

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
    if ( stipendioCorrente > 0 )
    {
        stipendioCorrente *= 2; 
    }    
    return stipendioCorrente;   
}
```

Similmente, le parentesi graffe possono essere omesse se il blocco istruzioni che racchiudono è costituito da una singola istruzione:

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
} else if ( <seconda condizione> ){
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

Questa forma, per quanto corretta e canonicamente ineccepibile, potrebbe rivelarsi difficile da gestire se le condizioni da considerare fossero molto complesse o numerose.
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
/** Come direbbe Shakespeare: Qui comincia il male.. **/
if ( divisore == 0 ) {
    cout << "Errore: divisione per zero" << endl;
}

/** ..e il peggio lo segue **/
if ( (dividendo / divisore) > 1 ) {
    ...
}
```

Non avendo un'istruzione `return` il codice della prima verifica non bloccherà l'esecuzione della funzione, che andrà in errore quando proverà a eseguire una divisione per zero.


### Istruzione switch

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
Per il C'hi++ la scelta esatta (inteso come participio passato del verbo *esigere*) è la seconda: tutta la materia non è che la manifestazione di una unica Energia, quindi ha poco senso distinguerci gli uni dagli altri; dobbiamo invece ragionare come Saadi di Shiraz, quando dice:

> Son membra d’un corpo solo i figli di Adamo,
da un’unica essenza quel giorno creati.
E se uno tra essi a sventura conduca il destino,
per le altre membra non resterà riparo.

Cercare il proprio tornaconto personale a discapito degli altri è sbagliato.
Bisogna comportarsi bene e cercare di convincere anche gli altri a fare altrettanto, perché, come recita il *Mantiq al-Tayr*:

> tutto il male o il bene che feci, in verità lo feci solo a me stesso.

Ma come si fa a capire cosa sia *bene*?  
Ci sono casi in cui è facile dare la scelta giusta, come nel caso di Bokuju:
<!-- @todo: trovare riferimento bibliografico o quanto meno spiegare di cosa si stia parlando -->

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
Se però queste domande le poni a un giuduce, avrai risposte diverse a seconda della Nazione a cui appartiene, perché, curiosamente, mentre sottrarre dei beni materiali è considerato un reato ovunque, esistono degli Stati in cui è permesso sottrarre a un individuo il bene più prezioso che ha.

<!--

@todo
I punti da evidenziare sono;

1. le leggi non sono fatte in base a delle convinzioni preesistenti, ma in base alla suggestione del momento o, meglio, a specifiche convenienze elettorali;

2. se l'elettorato fosse composto di persone illuminate, non ci sarebbe problema, ma l'elettorato è composto da analfabeti funzionali e da egoisti; 

3. la sparuta minoranza di idealisti agisce in base ai propri sentimenti/auspici perché è vittima dell'Annosa Dicotomia, quindi fa delle scelte irrazionali, come uccidere chi non ha fatto del male (il feto) e non permettere la soppressione di chi ne ha già fatto (il condannato)

4. il C'hi++ è nettamente contratrio all'aborto; capiamo il dramma, ma in un Mondo in cui ci sono coppie sterili alla ricerca di adozioni, non ha senso sopprimere un nascituro; 

5. finché si parla di pillola del giorno dopo, è un conto: in fondo, si sta parlando di cellule; ma se qualcosa ha la forma di un bambino, è un bambino, lo sviluppo cerebrale è solo un pretesto;

6. citare l'esempio del notaio in un'auto guidata da un sistema di IA e del sito che cerca di creare un'etica accumulando pareri (non fornire soluzione, per ora?);

7. il problema con il condannato è che si deve decidere se privare lui della vita o rischiare che lui privi della vita un'altra persona. la soluzione migliore sarebbe quella di metterlo in condizione di non nuocere, ma non è sempre possibile farlo. 

8. lo scopo della punizione DEVE sempre puntare al miglioramento: il condannato deve capire che ha fatto è sbagliato e non ripeterlo in altri cicli; se lo ammazzi, non è detto che capisca ed è possibile che ripeta;

9. d'altro canto, chi dimostra di non potere o volere capire non rientra nel novero degli esseri senzienti; come tale, non è funzionale alla crescita dell'Universo e come il gatto di Nansen, può essere soppresso: Caino ha gli stessi diritti di Abele.





- introdurre l'idea delle "variazioni" della storia dell'Universo
- chiudere con l'aneddoto del Maestro Canaro e il sacerdote buddista.

-->
