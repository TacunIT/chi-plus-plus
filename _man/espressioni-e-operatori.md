---
status:     redazione
layout:     manuale
class:      capitolo
title:      Espressioni e operatori
permalink:  /man/espressioni-e-operatori
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
{% include_relative src/espressioni-hello-world.cpp %}
```

Il suo output, come forse avrai intuito, è:

```
% g++ espressioni-hello-world.cpp -o ../out/esempio
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

dichiara la funzione `main`, specificando che avrà come valore di ritorno un `int` e due parametri: un intero e un puntatore a puntatori a `char`.
Questi valori servono a gestire i parametri passati da riga di comando: l'intero `argc` (crasi di: *argument count*), specifica il numero di stringhe presenti nella chiamata, mentre il puntatore `argv` (*argument vector*) è un array che contiene tutte le stringhe presenti nella linea di comando, nome del programma compreso.

Il corpo della funzione è racchiuso in una coppia di parentesi graffe `{}`.
L'istruzione:

```
std::cout << "Hello, World!" << std::endl;
```

scrive la stringa `Hello World!` sullo *stream* `std::cout` (*standard character output*), che solitamente corrisponde allo schermo del computer.
L’operatore `<<`, in questo caso, notifica al sistema di inviare in output quanto si trova alla sua destra e torna una *reference* a `basic_ostream` in modo da poter essere ripetuto su una st­essa linea di codice.  
Infine, l'istruzione:

```
return 0;
```

torna il valore `0` al programma chiamante (di solito, la *shell* del computer) per indicare l'assenza di errori nell'elaborazione.
Il programma seguente mette in pratica i concetti visti finora:

```
{% include_relative src/espressioni-argc-argv.cpp %}
```

Come ti ho detto, il C++ è un linguaggio *compilato*, quindi il codice, per poter essere eseguito, deve essere elaborato dal complilatore con il comando della *shell*:

```
% g++ espressioni-argc-argv.cpp -o src/out/esempio
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

La riga di codice:

```
int errore = NO_ERRORI;
```

è un'*istruzione*.
Le istruzioni sono composte da una o più *espressioni*, composte a loro volta da *operatori* e *operandi*.
Le espressioni possono essere o semplici o composte e producono sempre un valore:

```
a = 2 
a + b 
d = a - b + c 
a < d
```

La differenza fra istruzioni ed espressioni è che le istruzioni sono sempre terminate dal carattere `;`:

```
a = 3; 
b = a * 3; 
c = sqrt(b);
```


<!--

Utlizzare l'peratore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. Questo approccio si rirova anche nel precetto:

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
