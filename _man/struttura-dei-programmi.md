---
status:     redazione
layout:     manuale
class:      capitolo
title:      Struttura dei programmi C++
permalink:  /man/struttura-dei-programmi
quote:      "question = 2b | ( ! 2b );"
---

La libertà sintattica e la concisione dei costrutti sono la caratteristica principale del C++.

Il C++, come tutti i linguaggi, ha una sua sintassi che definisce gli elementi del codice e il loro utilizzo all'interno dei programmi.
Negli esempii che abbiamo visto finora, ho utilizzato alcuni di questi elementi senza spiegarti precisamente quale sia il loro ruolo, perché volevo darti un quadro d'insieme delle caratteristiche del linguaggio.
Un po' come quando arrivi a una festa e ti presentano gli altri invitati uno dietro l'altro e alla fine l'unica cosa che ti ricordi è il decolleté delle signore.
Adesso però, dobbiamo fare un passo indietro ed esaminare questi elementi a uno a uno, cominciando da quello che è l'elemento principale di ciascun programma C++, ovvero la funzione `main`.


```
int main(int argc, char** argv)
{    
    return 0;
}
```

Quello qui sopra è il più piccolo programma in C++ che tu possa scrivere.
È anche il più inutile, però, perché non fa nulla.  
L'esempio qui sotto è altrettanto inutile, ma un po' più complesso:

```
{% include_relative src/struttura-hello-world.cpp %}
```

Il suo output, come forse avrai intuito, è:

```
% g++ struttura-hello-world.cpp -o ../out/esempio
% ../out/esempio 
Hello, World!
```

La prima linea di codice:

``` 
#include <iostream>
```

non è un'istruzione, ma una direttiva per il preprocessore. 
Il preprocessore è un programma che elabora il codice e lo prepara per la compilazione, ne parleremo [in seguito](/man/preprocessore).
Per il momento, ti basta sapere che questa istruzione fa sì che nel codice venga incluso il file `iostream.h`, che contiene, fra le altre cose, la dichiarazione dello *stream* `cout`, utilizzato nell'unica istruzione del programma.

La seconda linea di codice

```
int main(int argc, char** argv)
```

definisce la funzione `main`, specificando che avrà come valore di ritorno un `int` e due parametri: un intero e un puntatore a puntatori a `char`.
Questi valori servono a gestire i parametri passati da riga di comando: l'intero `argc` (crasi di: *argument count*), specifica il numero di parametri presenti nella chiamata, nome del programma compreso, mentre il parametro `argv` (*argument vector*) è un array di puntatori a tutte le stringhe presenti nella linea di comando.

Il corpo della funzione è racchiuso in una coppia di parentesi graffe `{}`.
L'istruzione:

```
std::cout << "Hello, World!" << std::endl;
```

scrive la stringa `Hello World!` sullo *stream* `std::cout` (*standard character output*), che solitamente corrisponde allo schermo del computer.
L’operatore `<<`, in questo caso, notifica al sistema di inviare in output quanto si trova alla sua destra e torna una *reference* allo stream di output, in modo da poter essere ripetuto su una st­essa linea di codice, che è una forma più efficiente ed elegante di:

```
std::cout << "Hello, World!" ;
std::cout << std::endl;
```

Infine, l'istruzione:

```
return 0;
```

torna il valore `0` al programma chiamante (di solito, la *shell* del computer) per indicare l'assenza di errori nell'elaborazione.
Il programma seguente mette in pratica i concetti visti finora:

```
{% include_relative src/struttura-argc-argv.cpp %}
```

Come ti ho detto, il C++ è un linguaggio *compilato*, quindi il codice, per poter essere eseguito, deve essere elaborato dal complilatore con il comando della *shell*:

```
% g++ struttura-argc-argv.cpp -o src/out/esempio
```

Il parametro `-o`permette di specificare il nome del file di output, in questo caso: `src/out/esempio`.
Se non si defiisce questo valore, il compilatore genera un file di nome `a.out`.

Il comando *shell*:

```
% src/out/esempio; echo $?                                  
```

è composto di due istruzioni, separate dal carattere `;`.
La prima sitruzione esegue il file compilato; la seconda stampa a video il suo valore di ritorno.
Se eseguiamo il programma senza parametri, otteniamo un messaggio e il codice di errore `1`:

```
Specificare almeno un parametro!
1
```

Se invece eseguiamo il programma passandogli dei parametri, otteniamo questo:

```
% src/out/esempio un due tre; echo $?
src/out/esempio
un
due
tre
0
```

---

Nessun programma degno di questo nome ha solo la funzione `main`, ma suddivide il suo lavoro in una serie di funzioni che svolgono compiti precisi e ben definiti.
In un programma ben scritto, le funzioni presentano due caratteristiche, che gli anglosassoni e gli anglofili definiscono: *low coupling* e *high cohesion*.  
Con il termine *accoppiamento* di due funzioni si intende la quantità di informazioni che la funzione *A* deve avere riguardo la funzione *B* per poterla utlizzare.
Ciascuna funzione si aspetta di ricevere una serie ben definita di parametri: la funzione `raddoppia`, che abbiamo visto prima, si aspetta di ricevere un solo parametro, di tipo `long`:

```
long raddoppia(long stipendio)
{
    return stipendio * 2;   
}
```

mentre un'ipotetica funzione `scorpora` potrebbe richiederne due; l'importo dello stipendio e l'aliquota IVA:

<!-- @todo: completare il corpo della funzione -->
```
long scorpora(long lordo, float iva)
{
    ...;   
}
```

In entrambi questi casi, tutto ciò di cui ha bisogno una terza funzione per richiamare `raddoppia` o `scorpora` è la la loro *interfaccia*, ovvero il numero, il tipo e l'ordine dei parametri da passare.
Ora immagina che ci sia un'altra funzione, `facciQualcosa` che possa compiere più azioni distinte, in base ai parametri ricevuti:

```
float facciQualcosa(long stipendio, int azione, float aliquota = 0)
{
    float valore = 0;
    /** Differenzia l'azione in base al valore di azione */
    if(azione == 1) {
        valore = stipendio * 2;
    } else if(azione == 2) {
        valore = stipendio / ((100 + aliquota) / 100);
    }
    return valore;
}
```

Per poter utilizzare questa funzione, non solo dobbiamo conoscere la sua interfaccia, ma dobbiamo anche sapere quali azioni corrispondono ai diversi valori del parametro `azione`.
Questa è follia, *meshuggah*, perché, se un giorno l'autore la modificasse e decidesse che il valore `1` del parametro `azione` causa lo scorporo dell'IVA mentre il valore `2` causa il raddoppio dello stipendio, noi dovremmo modificare anche *tutte* le funzioni che l'hanno chiamata per adattarle alle nuove regole.
Non solo perderemmo del tempo, ma se dimenticassimo di aggiornare una o più chiamate otterremmo un programma con un funzionamento errato.

Il *coupling* <!-- uso il termine inglese per evitare anfibologie con l'attività sessuale.. --> è come il colesterlolo: più è basso, meglio è; quindi, per evitare errori, dobbiamo ridurlo, creando un `enum` a cui assegnare i possibili valori del parametro `azione`:

```
enum Azione { raddoppia, scorpora }; 
```

Come spesso avviene, una singola riga di codice ben scritto ci permette di risparmiare tempo e di ottenere del codice più robusto, perché l'effetto del parametro `azione`, in questo modo, sarà del tutto indipendente dal suo valore numerico:

<!-- @todo: verificare il codice -->
```
enum Azione { raddoppia, scorpora }; 

float facciQualcosa(long stipendio, Azione azione, float aliquota = 0)
{
    float valore = 0;
    /** Agisce in base all'etichetta, non al valore */
    if(azione == raddoppia) {
        valore = stipendio * 2;
    } else if(azione == scorpora) {
        valore = stipendio / ((100 + aliquota) / 100);
    }    
    return valore;
}
```

La funzione `facciQualcosa` ha anche un altro difetto progettuale, oltre all'alto accoppiamento: manca di coesione interna.
In un programma ben scritto, ciascuna funzione deve avere solo una.. funzione:

<!-- @todo: verificare il codice -->
```
enum Azione { raddoppia, scorpora }; 

inline long raddoppiaStipendio(long stipendio)
{
    return stipendio * 2;
}

inline float scorporaIVA(long stipendio, float aliquota)
{
    return (stipendio / ((100 + aliquota) / 100);
}
```

Anche in un esempio così semplice, vedi bene che differenza ci sia, fra una funzione che può svolgere più azioni eterogenee e una funzione che svolge una singola azione, ben precisa.
Riducendo la complessità della funzione, inoltre, abbiamo la possibilità di dichiararla come [`inline`](/man/funzioni#inline), aumentando la velocità di esecuzuione del programma.

<!--


L\'Esistenza potrebbe essere un sistema per smaltire l\'energia
dell\'Universo (o di quello che ha intorno), così come le perturbazioni
sono un sistema per smaltire l\'energia dell\'atmosfera?

Utlizzare l'operatore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 

Ho messo intenzionalmente il capitolo sull'algebra booleana DOPO quello sugli operatori per dimostrare come i concetti di vero/falso giusto/sbagliato debbano essere definiti per prima cosa

## operatori

### operatore di negazione

la negazione e il paradosso come metodo per comprendere ciò che non è
di per sé evidente

### operatore di incremento
mettere qui, perché servono nel codice seguente
## cicli

### ciclo for

### ciclo while

### ciclo do-while

-->
