---
layout:     manuale
class:      capitolo
index:      7
title:      Il C++
permalink:  /man/c-plus-plus
precedente: linguaggi-di-programmazione
seguente:   commenti
bozza:      true
quote:      "Non chiederti cosa può fare per te il sistema operativo;
chiediti invece cosa puoi fare tu, per il sistema operativo"
---

In uno dei suoi libri, Bjarne Stroustroup definì il C++: 

> Un linguaggio di programmazione per svolgere compiti non banali. 

Fà che si possa dire la stessa cosa di te. 

---

C++ è un linguaggio di programmazione creato da Bjarne Stroustrup nel 1983, quando lavorava alla AT&T.
Dieci anni prima, un suo collega di nome Ritchie aveva creato un linguaggio di programmazione chiamato *C*. 
Il C, come ti ho detto, funzionava piuttosto bene se dovevi programmare i computer, ma – così come molti dei tuoi confratelli – non gestiva altrettanto bene le entità della vita reale.  
I tipi di dato del C sono

    char, int, float, double, array, enum, struct, union


Il nome *C++* si riferisce all'operatiore di incremento `++`:

```
{% include_relative src/7.1-operatore-incremento.cpp %}
```
Se compili ed eseguti questo codice, otterrai:

```
> g++ 7.1-operatore-incremento.cpp -o ../out/esempio
> ../out/esempio
Valore di C = 12
Valore di C = 13
```

<!--

Paragonare l'evoluzione C/C++ al rapporto fra ebraismo e cristianesimo.
Paragonare il rapporto C++/Java al rapporto fra 10 comandamenti ebraici e 10 C cattolici.
> I suspect that the root of many of the differences between C/C++ and Java is that AT&T is primarily a user (a consumer) of computers, languages, and tools, whereas Sun is primarily a vendor of such things.
Bjarne Stroustrup - http://gotw.ca/publications/c_family_interview.htm


C and C++ were invented in the Computer Science Research Center of Bell Labs in Murray Hill a

is a better C
supports data abstraction
supports object-oriented programming
supports generic programming.


Il C++ è un linguaggio orientato agli oggetti, questo vuol dire che le
sue regole interne discendono da dei principî di ordine superiore, il
cosiddetto paradigma a oggetti.

Il C++ rappresenta le entità reali per mezzo degli oggetti.

Le caratteristiche delle entità sono descritte dagli attributi degli
oggetti.

Il modo in cui gli oggetti reagiscono agli stimoli esterni è descritto
dai metodi.

Perché un linguaggio di programmazione possa dirsi orientato agli
oggetti deve possedere tre caratteristiche: le classi, l'ereditarietà e
il polimorfismo.

Le classi sono i prototipi degli oggetti e ne definiscono le
caratteristiche distintive. Le caratteristiche fisiche degli oggetti
sono quantificate dagli attributi della classe; le caratteristiche
comportamentali sono descritte dai metodi.

Grazie alle classi, il programmatore può creare dei nuovi tipi di dato e
utilizzarli all\'interno del suo programma nello stesso modo in cui
utilizzerebbe i tipi di dato primitivi del linguaggio.

L'ereditarietà permette di definire dei nuovi tipi di dato come
estensione dei tipi di dato esistenti. 

L'ereditarietà può essere o singola o multipla.

Quando una nuova classe deriva da un'unica classe base, l'ereditarietà
viene detta singola; se invece una classe deriva da due o più classi
base, l'ereditarietà viene detta multipla. 

Alcuni linguaggi di programmazione permettono solo l'ereditarietà
singola; il C++ permette entrambe le tipologie.

Per polimorfismo si intende la capacità di una funzione o di un
operatore di svolgere il proprio compito indipendentemente dal tipo di
dato che deve gestire.

Quando il programmatore definisce un nuovo tipo di dato per mezzo di una
o più classi, può allo stesso tempo istruire le funzioni e gli operatori
del linguaggio ad utilizzarlo correttamente.

Suppongo che a questo punto tu sia un po\' confuso, ma non dipende dalla
complessità dalle mie enunciazioni.

Il problema è che ti stai concentrando sull\'effetto e non sulla sua
causa.

-->
