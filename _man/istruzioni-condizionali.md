---
status:     bozza
layout:     manuale
class:      capitolo
title:      Istruzioni condizionali
permalink:  /man/istruzioni-condizionali
quote:      ""
---

Le istruzioni condizionali sono l'elemento più importante del codice.

Ogni programma deve saper reagire correttamente al variare delle condizioni di utilizzo; per far ciò, si utilizzano le istruzioni condizionali, che permettono di definire il comportamento del sistema a seconda che una determinata condizione si riveli vera o falsa.
Il C++ possiede due tipi di istruzione condizionale: le sequenze `if-else` e l'istruzione `switch`.

### Istruzioni `if-else`

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

Se la condizione *falso* non richiede alcuna azione specifica, il secondo blocco di istruzioni può essere omesso:

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
<!-- @todo - aggiugere codice di esempio -->

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

Se le istruzioni sono poche e semplici, una forma vale l'altra (fatte salve le questioni di stile, ovviamente), ma se il flusso del programma prevede, come di solito avviene, delle condizioni annidate, è necessario fare in modo che la forma dell'istruzione semplifichi tanto la scrittura che la lettura che un'eventuale correzione del codice.  
Immagina un brano di codice che debba fare una verifica all'inizio dell'elaborazione e, a seconda dell'esito, eseguire una sequenza di istruzioni o inviare un messaggio di errore:

```
if ( <condizione> )
{
    /*
     * righe di codice da
     * eseguire in caso la
     * condizione sia vera
     */
}
else
{
    /* messaggio di errore */
}
```

Se le istruzioni da eseguire in caso di buon successo della verifica sono poche e semplici, questa sequenza non darà problemi, ma se, al contrario, le istruzioni fossero tante e complesse, leggendo il codice potresti arrivare all'istruzione `else` e non ricordarti più a quale condizione fosse associata.  
In questi casi, io preferisco la forma:

```
if ( <errore> )
{
    /* messaggio di errore */
}
else
{
    /*
     * righe di codice da
     * eseguire in caso la
     * condizione sia vera
     */
}
```

Dato che la gestione dell'errore non richiederà mai più di qualche riga di codice, a colpo d'occhio potrai capire tutto il flusso del programma, indipendentemente dalla lunghezza del secondo blocco di istruzioni.

Tutto questo, ovviamente, non vuole essere né un invito né una giustificazione per la scrittura di istruzioni complesse.
A meno che non sia necessario evitare le chiamate a funzione per garantire un'alta velocità di esecuzione, è sempre meglio scomporre il flusso del programma in una serie di funzioni distinte.
Renderai il tuo programma un po' più lento (o, meglio: un po' meno veloce), ma il codice sarà molto più facile da leggere o da modificare. 
<!-- @todo parlare delle macro, ma non qui. -->

Immagina adesso un brano di codice che richieda molte condizioni `if` concatenate:

```
esito = 0;

if ( <condizione 1> ) {
    esito = 1
} else if ( <condizione 2> ) {
    esito = 2
} else if ( <condizione 3> ) {
    esito = 3
} else {
    esito = 9
}

return esito
```

Questa forma, per quanto corretta e canonicamente ineccepibile, potrebbe rivelarsi difficile da gestire se le condizioni da considerare fossero molto complesse o numerose.
Il buon programmatore, allora, può decidere di contravvenire alla (giusta) norma che prescrive di non inserire delle istruzioni `return` all'interno del codice, e scrivere la sequenza in questo modo:

```
esito = 0;

if ( <condizione 1> ) {
    return 1
}
if ( <condizione 2> ) {
    return 2
} 
if ( <condizione 3> ) {
    return 3
} 
return 9
```

Non ti sto dicendo che sia giusto scrivere così e vedi da solo che il codice è rozzo e inelegante, ma ci potrebbero essere dei casi in cui sia questa, la forma più efficiente.
Per esempio, per un sistema che generi del codice in maniera automatica, è molto più semplice gestire delle istruzioni `if` isolate che delle condizioni `if-else` concatenate.
Pensa a una *stored-procedure* che debba controllare l'integrità referenziale dei parametri ricevuti:

```
CREATE FUNCTION utente_insert (
  _id_classe INTEGER
, _id_gruppo INTEGER
, _username  VARCHAR(255)
, _cognome   VARCHAR(80)
, _nome      VARCHAR(80)
)
RETURNS INTEGER DETERMINISTIC
BEGIN
    DECLARE _id    INTEGER DEFAULT -1;
    DECLARE _count INTEGER DEFAULT 0;

    SELECT count(*) INTO _count FROM classe WHERE (id = _id_classe);
    IF _count = 0 THEN
        RETURN -2;
    END IF;

    SELECT count(*) INTO _count FROM gruppo WHERE (id = _id_gruppo);
    IF _count = 0 THEN
        RETURN -3;
    END IF;

    IF (_username IS NULL) OR (_username = '') THEN
        RETURN -4;
    END IF;
    
    IF (_cognome IS NULL) OR (_cognome = '') THEN
        RETURN -5;
    END IF;

    IF (_nome IS NULL) OR (_nome = '') THEN
        RETURN -6;
    END IF;

    ...

```

Se scrivi il codice in questa maniera, puoi inserire o rimuovere un parametro (e i relativi controlli) senza alterare il resto del codice, cosa che non avverrebbe se tu concatenassi le istruzioni `if`.

<!--
Attento, però: mettere in sequenza delle semplici istruzioni `if` è cosa
ben diversa dal creare una catena di istruzioni `else-if` .

@todo
- specificare la differenza e la necessità del return per bloccare i controlli;
- introdurre l'idea delle "variazioni" della storia dell'Universo
- chiudere con l'aneddoto del Maestro Canaro e il sacerdote buddista.

-->

### Istruzione `switch`
