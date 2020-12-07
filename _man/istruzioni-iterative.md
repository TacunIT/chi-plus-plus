---
status:     redazione
layout:     manuale
class:      capitolo
title:      Istruzioni iterative
permalink:  /man/istruzioni-iterative
quote:      "Dopo di me, il reboot"
---

Le istruzioni di ciclo sono una delle componenti fondamentali della programmazione.  
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
La seconda espressione è una condizione logica o relazionale che viene valutata all’inizio di ogni iterazione: se torna `0` o `false` l’esecuzione del ciclo termina, altrimenti posegue.  
La terza espressione viene valutata al termine di ogni iterazione e, di solito, è costituita da un’espressione di incremento delle variabili utilizzate per il controllo del ciclo.

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
È necessario quindi porre un limite al numero di ripetizioni, utilizzando la stessa parola-chiave `break`che abbiamo usato con le istruzioni `switch`.
Stavolta, però, cominceremo a fare le cose come vanno fatte e separeremo le tre componenti del programma precedente in tre file distinti: `pianeti.h`, che conterrà le dichiarazioni delle costanti e della funzione `mostraPianeta`; `pianeti.cpp`, contenente la definizione della funzione `mostraPianeta` e `pianeti-main.cpp` per la funzione `main`:

```
{% include_relative src/pianeti.h %}
```

```
{% include_relative src/pianeti.cpp %}
```

```
{% include_relative src/pianeti-main.cpp %}
```

L'incremento della variabile `p`, in questo caso, avviene all'interno dell'istruzione:
<!-- @todo: parlare dell'operatore di incremento -->

```
if(!mostraPianeta( p++ )) break; 
```

Per generare questo programma dovremo passare al compilatore emntrambi i file *.cpp*:

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

Questo codice, però, è sgraziato.
Il problema è che la funzione `mostraPianeta` fa troppe cose: non solo stabilisce il nome del Pianeta, ma lo stampa anche a video.
In conseguenza di ciò, nel nostro output abbiamo anche quella brutta stringa di errore relativa alla posizione numero nove.
Nel primo esempio in cui l'abbiamo utilizzata, questo non era un problema, ma adesso che il nostro programma si sta sviluppando, dobbiamo rendere ciascuna funzione più specialistica, dividendo l'elaborazione dei dati (capire quale sia il pianeta) dall'interfaccia utente (la stampa a video del nome).
Per fare ciò, utilizzermo una nuova funzione che aggiungeremo al file `pianeti.cpp`:

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

<!--
Anche in questo caso è possibile forzare il numero dei cicli indefinitamente sostituendo l’espressione con una costante nonzero, per esempio:

while(1)
{
  ...istruzioni...(corpo del ciclo)
}


## Il ciclo do-while
Il ciclo do-while si differenzia dal ciclo while che abbiamo visto in precedenza solamente per il fatto di valutare la condizione while alla fine dell’iterazione, questo determina l’esecuzione del corpo del ciclo almeno per una volta. 
La forma generale è la seguente:

do
{
  ...istruzioni...(corpo del ciclo)
} while(espressione)

Il ciclo viene eseguito una prima volta per effettuare l’assegnazione di un valore ad a e quindi viene ripetuto fino a quando la variabile a assume il valore zero (false).

### Istruzioni di interruzione
Queste istruzioni sono usate per controllare l’esecuzione di altre istruzioni. Il loro utilizzo più comune è quello di interrompere cicli o, come abbiamo già visto per break, l’istruzione di switch. Le tre istruzioni di interruzione sono:

break;
continue;
return.

Istruzione break
L’istruzione break termina i cicli for, while e do-while, nonché l’istruzione switch che la includono, passando il controllo all’istruzione immediatamente successiva al blocco istruzioni del ciclo (corpo del ciclo) o dello switch.

4.4.2   Istruzione continue
L’istruzione continue determina il passaggio del controllo alla fine del singolo ciclo di iterazione senza determinare l’uscita dal corpo del ciclo che può riprendere con la successiva iterazione.

4.4.3   Istruzione return
L’istruzione return consente di terminare l’esecuzione di una funzione e di avere un eventuale valore di ritorno alla funzione chiamante. Vediamone un esempio:



<hr id="dottrina">

<!--

@todo - qui va introdotto il concetto di ciclicità dell'Universo.
- introdurre l'idea delle "variazioni" della storia dell'Universo

-->
