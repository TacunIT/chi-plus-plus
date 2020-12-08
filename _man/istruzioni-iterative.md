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
È necessario quindi porre un limite al numero di ripetizioni, utilizzando la stessa parola-chiave `break`che abbiamo usato con le istruzioni `switch`.
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

Il ciclo `do-while` è uguale al ciclo `while`con la sola differenza che la condizione `while` viene valutata alla fine dell’iterazione e quindi il corpo del ciclo viene eseguito almeno per una volta. 
La forma generale del ciclo `do-while` è:

```
do
{
    <istruzioni>        // corpo del ciclo
} while(espressione)    // espressione di controllo
```

Non offenderò la tua intelligenza con un esempio; vorrei piuttosto farti notare una cosa grave: il codice di questi programmi è sgraziato.
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

<hr id="dottrina">

<!--

@todo - qui va introdotto il concetto di ciclicità dell'Universo.
- introdurre l'idea delle "variazioni" della storia dell'Universo

-->
