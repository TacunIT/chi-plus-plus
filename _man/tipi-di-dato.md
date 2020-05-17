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

Dalla dimensione del tipo di dato dipende la quantità di valori che può assumere.
Un `char` è composto da otto bit e può assumere per ciò 2<sup>8</sup> valori, quindi: da 0 a 255.
Un `int` è composto da sedici bit e può assumere 2<sup>16</sup> valori, ovvero: da 0 a 65.535.
Un `float` ha 8 bit per l'esponente e 23 per la mantissa, quindi può assumere valori da 1.175494e-38 a 3.402823e+38 e così via.

Oltre ai tipi di dato, il C++ ha ereditato dal C anche i cosiddetti *modificatori*, ovvero delle parole-chiave che, se aggiunte al nome di un tipo di dato, ne modificano le caratteristiche.  
I modificatori `short` e `long` alterano la dimensione del dato, riducendolo o aumentandolo.   
I modificatori `signed` e `unsigned` fanno sì che il primo bit del dato sia considerato il suo segno: positivo se il valore è 0; negativo se il valore è 1.
Il segno, però, “ruba” un bit alla variabile *signed* che quindi potrà assumere un numero minore di valori rispetto alla stessa variabile *unsigned*.

Questo programma mostra come la dimensione e i valori minimi e massimi del tipo di dato `int` possano variare con l'utilizzo dei modificatori:

```
{% include_relative src/tipi-di-dato-limiti.cpp %}
```

Su questo computer, i valori sono:

```
% g++ tipi-di-dato-limiti.cpp -o ../out/esempio
% ../out/esempio                               
           int: 4 bytes, da:          -2147483648  a:           2147483647
  unsigned int: 4 bytes, da:                    0  a:           4294967295
     short int: 2 bytes, da:               -32768  a:                32767
unsigned short: 2 bytes, da:                    0  a:                65535
      long int: 8 bytes, da: -9223372036854775808  a:  9223372036854775807
 unsigned long: 8 bytes, da:                    0  a: 18446744073709551615
 ```







-->
