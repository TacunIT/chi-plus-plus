---
status:     redazione 
layout:     manuale
class:      capitolo
title:      I tipi di dato
permalink:  /man/tipi-di-dato
quote:      "Tutto è byte."
---

La varietà dei tipi di dato disponibili è la caratteristica principale del C++.

Il C++ ha ereditato dal C una vasta gamma di tipi di dato.
A seconda della loro natura, possiamo dividere questi tipi di dato in due gruppi: i dati **scalari** e i dati *aggregati*.

I tipi di dato **scalari** sono: `void`, `bool`, `char`, `wchar_t`, `int`, `float`, `double` e permettono di gestre gli elementi classici di un programma: i numeri interi, i numeri decimali, le lettere e i valori booleani.

I tipi di dato **aggregati** sono gli array, le unioni, gli emumerati, le strutture e le classi e, come dice anche il loro nome, sono costituiti dalla unione di più dati scalari dello stesso tipo o di tipi differenti.

Questo brano di codice mostra i principali tipi di dato del C++. 
Contiene molti elementi di cui ancora non ti ho parlato, quindi non preoccuparti se non capisci del tutto ciò che fa.

```
{% include_relative src/tipi-di-dato-principali.cpp %}
```

Attenzione, però: nessuno di questi signori è in realtà quello che afferma di essere.
Nella variabile `booleano` non c'è il valore `true` o `false`, ma un valore binario che il sistema considera tale.
Allo stesso modo, nella variabile `carattere`, non c'è la lettera `C`, ma il valore binario corrispondente alla codifica ASCII della lettera `C`.
Ogni tipo di dato non è altro che il nome di una quantità di memoria.
Ricordatelo, perché questo è la chiave di tutto. 

La dimensione di memoria associata a ciascun tipo di dato non è fissa, ma può variare a seconda del sistema in cui stai lavorando.
Il codice qui sotto ti permette di conoscere la dimensione in byte dei tipi di dato scalari:

```
{% include_relative src/tipi-di-dato-dimensione.cpp %}
```

Compilando ed eseguendo questo codice, otterrai:

```
% g++ tipi-di-dato-dimensione.cpp -o ../out/esempio
% ../out/esempio                                   
      bool: 1
      char: 1
       int: 4
     float: 4
    double: 8
```

Dalla dimensione del tipo di dato dipende la quantità di valori che può assumere:

```
{% include_relative src/tipi-di-dato-valori.cpp %}
```

```
% g++ tipi-di-dato-valori.cpp -o ../out/esempio
% ../out/esempio                               
        tipo      minimo     massimo
      bool:            0           1
      char:            0         255
       int:            0  4294967295
     float:  1.17549e-38 3.40282e+38
    double: 2.22507e-3081.79769e+308
```

<!--

| `void` | utilizzato solo per funzioni o puntatori |  
| `bool` | valori booleani `true` e `false`|
| `char` | caratteri semplici |
| `wchar_t` | caratteri estesi |
| `int` | valori interi |
| `float`, `double` | valori decimali
| array      | insiemi di dati dello stesso tipo |  
| `class`    | tipi di dato definiti dall'utente |  
| `enum`     |  |  
| `structure |  |  
| `union`    |  |  



La dimensione di un dato determina il numero massimo di valori che quel dato può assumere.  
Un `char` è composto da otto bit e può assumere per ciò 2<sup>8</sup> valori, quindi: da 0 a 255.  
Un `int` è composto da sedici bit e può assumere 2<sup>16</sup> valori, ovvero: da 0 a 65.535.  
Un `long int` è composto da trentadue bit e può assumere 2<sup>32</sup> valori, ovvero: da 0 a 4.294.976.295 valori.

-->
