---
status:     redazione
layout:     manuale
class:      capitolo
title:      Il preprocessore
permalink:  /man/preprocessore
quote:      ""
---

Le direttive al preprocessore sono la caratteristica principale del C++.  
Negli esempi precedenti abbiamo visto alcune istruzioni particolari, perché hanno un carattere `#` all'inizio e non hanno un carattere `;` alla fine:

``` 
#include <iostream>

#define NO_ERRORI    0
#define NO_PARAMETRI 1
```
<!-- @todo - verificare come mai questo brano di codice non appaia formattato correttamente in Chrome, Opera e Firefox mentre è visualizzato correttamente da Safari. Il font è monospace e l'allineamento del paragrafo è a sinistra -->

Queste istruzioni sono delle *direttive al pre-processore* e possono essere di tre tipi:

- direttive di inclusione;
- definizioni e macroistruzioni;
- direttive condizionali.

Le <a id="inclusione" 
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">direttive di inclusione</a> sono quelle che si utilizzano più comunemente e servono a importare nel codice le definizioni delle funzioni di libreria, delle macroistruzioni e dei simboli necessari per la corretta compilazione dei programmi.
Questi elementi, per comodità, sono isolati all'interno di alcuni file, detti *file di include*.
Quando il preprocessore incontra una direttiva `include`, la sostituisce con il contenuto del file a cui fa riferimento.
Per esempio, se più di un programma dovesse usare la Classe `Colore` o la struttura `ColoreRGB` che abbiamo utilizzato nel programma che visualizza la dimensione dei <a href="/man/tipi-di-dato#principali"> principali tipi di dato del C++</a>, questi dovrebbero essere isolati in un file separato con estensione `.h`, a indicare che si tratta di un *header file*:

```
{% include_relative src/preprocessore-colore.h %}
```

Il file verrebbe poi incluso nel codice dei programmi che ne fanno uso con una direttiva `include`:

```
{% include_relative src/preprocessore-main.cpp %}
```

Questo esempio utilizza due forme distinte per la direttiva `include`:

```
#include <iostream>
#include "colore.h" 
```

La prima forma serve a includere i file di sistema, come, appunto, `iostream`, che contiene le definizioni degli *stream* stadard del C++; la seconda forma si utilizza per i file specifici dell'applicazione; nel nostro caso, `colore.h`.  
I file di include possono includere a loro volta altri file; per esempio, `colore.h` include `iostream`, perché utilizza lo *stream* `cout`.
Anche il nostro codice di esempio, però, include `iostream` e questo potrebbe causare un errore di compilazione se il precompilatore effettuasse due volte l'inclusione, perché sarebbbe come se dichiarassimo due volte la stessa funzione.
Per questo motivo, all'inizio del nostro file di include (ma anche di ìostream`) troviamo un altro tipo di diretttive al preprocessore, le cosiddette: 
<a id="condizionali"
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">direttive condizionali</a>:
   
```
#ifndef _CLASS_COLORE
#define _CLASS_COLORE 1

...

#endif /* _CLASS_COLORE */
```

Le direttive condizionali sono:

| direttiva | valore |
|---|---|
| `#if`     | se non zero
| `#ifdef`  | se definito
| `#ifndef` | se non definito
| `#else`   | altrimenti
| `#elif`   | altrimenti se
| `#endif`  | fine del blocco condizionale

Quando il preprocessore legge la prima direttiva nel file di include, verifica che sia definito un valore per `_CLASS_COLORE`.
Se `_CLASS_COLORE` non ha un valore associato, il preprocessore esegue l'istruzione successiva, che gli assegna il valore 1, poi inserisce nel file chiamante tutto il codice fino all'istruzione `#endif`.
Se invece `_CLASS_COLORE` ha già un valore associato perché è già stata inclusa da altri file, il preprocessore salta direttamente alla direttiva `#endif` senza riscrivere le tre dichiarazioni.

<!--

Alcuni esempi validi di costanti simboliche sono:
#define FALSE 0
#define TRUE 1
#define NUMERO 0.2
#define STRINGA "Stringa di caratteri" 
Alcuni esempi validi di macroistruzioni sono:
#define INCREMENTO(x) x * 0.2
#define CUBO(x) x * x * x 

È inoltre possibile eliminare una #define precedentemente assegnata per mezzo della direttiva #undef.

le definizioni possono essere in un file separato o anche nei parametri di compilazione

-->
