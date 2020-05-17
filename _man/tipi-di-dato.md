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
Possiamo dividere questi tipi di dato in due gruppi: i dati **scalari** e i dati *aggregati*.

I tipi di dato **scalari** sono: `void`, `bool`, `char`, `wchar_t`, `int`, `float`, `double` e permettono di gestre gli elementi classici di un programma: i numeri interi, i numeri decimali, le lettere e i valori booleani.

I tipi di dato **aggregati** sono gli array, le unioni, gli emumerati, le strutture e le classi e, come dice anche il loro nome, sono costituiti dalla unione di più dati scalari dello stesso tipo o di tipi differenti.

Questo brano di codice mostra i principali tipi di dato del C++.

```
{% include_relative src/tipi-di-dato-principali.cpp %}
```
Attenzione, però: nessuno di questi signori è in realtà quello che afferma di essere.


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


Function

Pointer
Reference
Abstract or User-Defined Data Types: These data types are defined by user itself. Like, defining a class in C++ or a structure. C++ provides the following user-defined datatypes:
Class

Union
Enumeration
Typedef defined DataType

a cui ha aggiunto la possibilità di creare nuovi tipi di dato grazie alle classi.




Ogni tipo di dato, però, non è altro che il nome di una quantità di memoria.
Ricordatelo, perché questo è la chiave di tutto. 

La dimensione di un dato determina il numero massimo di valori che quel dato può assumere.  
Un `char` è composto da otto bit e può assumere per ciò 2<sup>8</sup> valori, quindi: da 0 a 255.  
Un `int` è composto da sedici bit e può assumere 2<sup>16</sup> valori, ovvero: da 0 a 65.535.  
Un `long int` è composto da trentadue bit e può assumere 2<sup>32</sup> valori, ovvero: da 0 a 4.294.976.295 valori.

<!--
Qui tutto quello che attiene all'etica.

-->
