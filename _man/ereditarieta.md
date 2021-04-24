---
status:     redazione
layout:     manuale
class:      capitolo
title:      L'ereditarietà
permalink:  /man/ereditarieta
quote:      "We few, we happy few<br />We bunch of data"
---

L'ereditariaretà, ovvero la possibilità di creare delle genealogie di classi, è il principale punto di forza del C++.

Come abbiamo visto nella <a href="/man/classi-oggetti#dottrina" class="xref">lezione precedente</a>, una ipotetica classe `Pesce` dovrà avere attributi differenti a seconda dell'utilizzo che se ne deve fare.

```
{% include_relative src/ereditarieta-pesce-alimentare.cpp %}
```

L'ereditarietà può essere o *singola* o *multipla*, a seconda che la nuova classe erediti le caratteristiche da una o più classi preesistenti:

```
class Figlio : public Mamma
{
    /** Ereditarietà singola */
};

class Figlio : public Mamma, private Papa
{
    /** Ereditarietà singola */
};
```

Non è permesso (né sensato) che una classe erediti due volte dalla stessa classe base:

```
class Errore : public Mamma : public Mamma
{
	...
};
```

Le classi `Mamma` e `Papa` possono essere definite: *classi base* o *sottoclassi* o *classi fondamentali* o *sotto-tipi*; la classe `Figlio` può essere chiamata o *classe derivata* o *superclasse* o *supertipo*.



<!--

Questo vuol dire che se dovessi scrivere un programma *non banale* che gestisca la vendita o lo studio dei pesci, dovrai utilizzare o delle classi `Pesce` con caratteristiche differenti o un'unica classe `Pesce` che abbia più funzioni di quelle che serv

Alcuni linguaggi di programmazione permettono solo l'ereditarietà
singola; il C++ permette entrambe le tipologie.

Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Forse come classi astratte

Classi astratte, funzioni virtuali e virtuali pure.

-->
