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
A seconda della loro natura, possiamo dividere questi tipi di dato in due gruppi: i dati *scalari* e i dati *aggregati*.

I tipi di dato *scalari* sono: `void`, `bool`, `char`, `wchar_t`, `int`, `float`, `double` e permettono di gestre gli elementi classici di un programma: i numeri interi, i numeri decimali, le lettere e i valori booleani.

I tipi di dato *aggregati* sono gli array, le unioni, gli emumerati, le strutture e le classi e, come dice anche il loro nome, sono costituiti dalla unione di più dati scalari dello stesso tipo o di tipi differenti.

Questo brano di codice &mdash; fastidiosamente didascalico, nella sua sostanziale inutilità &mdash; mostra i principali tipi di dato del C++. 
Contiene molti elementi di cui ancora non ti ho parlato, quindi non preoccuparti se non capisci del tutto ciò che fa.

```
{% include_relative src/tipi-di-dato-principali.cpp %}
```

Il tipo di dato `void` non ha né una dimensione né un valore e può essere assegnato solo a un puntatore o a una funzione che non torna alcun tipo di valore, come la funzione `nome_colore` della classe `Colore`.

Il tipo di dato `bool` è utilizzato per gestire i valori booleani.
Può assumere solo due valori: `true` o `false`, quindi ha la dimensione minima possibile, ovvero un byte.

Il tipo `int` permette di gestire i numeri interi. 
Di solito ha una dimensione di quattro byte, che può essere aumentata o diminuita per mezzo di parole-chiave dette: [modificatori](#modificatori).

I tipi `float` e `double` si utilizzano per gestire i numeri decimali. 
Hanno una lunghezza di quattro e otto byte rispettivamente e una precisione di sette e quindici cifre decimali.

I tre elementi che compaiono al di fuori della funzione `main` sono tipi di dato *aggregati* e permettono di definre dei tipi di dati non standard.

Gli `enum` permettono di assegnare dei nomi a dei valori, rendendo più facile la programmazione.
Nell'esempio, l'*enum* `RGB`assegna un nome a tre valori della codifica RGB.
Questo nuovo tipo di dato è utilizzato nella struttura `ColoreRGB`.

Le `struct` permettono di creare degli insiemi di dati eterogenei.
La variabile `ColoreRGB` contiene due variabili differenti: un valore di tipo `RGB` e un [puntatore](#puntatori) a carattere.

Tutti i tipi di dati che abbiamo visto finora sono un retaggio del linguaggio *C*.
La classe `Colore`, invece, è una delle novità introdotte dal C++ e contiene due elementi: una struttura di tipo `ColoreRGB` e una funzione che mostra il nome del colore. 

Attenzione, però: nessuno di questi signori è in realtà ciò che afferma di essere.
Nella variabile `booleano` non c'è il valore `true` o `false`, ma un valore binario che il sistema considera tale.
Allo stesso modo, nella variabile `carattere`, non c'è la lettera `C`, ma il valore binario corrispondente alla codifica ASCII della lettera `C`.
Ogni tipo di dato non è altro che il nome di una quantità di memoria.
Ricordatelo, perché questo è la chiave di tutto. 

---

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
Un `int` è composto da trentadue bit e può assumere 2<sup>32</sup> valori, ovvero: da 0 a 4.294.967.295.
Un `float` ha 8 bit per l'esponente e 23 per la mantissa, quindi può assumere valori da 1.175494e-38 a 3.402823e+38 e così via.

<a id="modificatori"></a>
Oltre ai tipi di dato, il C++ ha ereditato dal C anche i cosiddetti *modificatori*, ovvero delle parole-chiave che, se aggiunte al nome di un tipo di dato, ne modificano le caratteristiche.  
I modificatori `short` e `long` alterano la dimensione del dato, riducendolo o aumentandolo.   
I modificatori `signed` e `unsigned` fanno sì che il primo bit del dato sia considerato il suo segno: positivo se il valore è 0; negativo se il valore è 1.
Il segno, però, “ruba” un bit alla variabile *signed* che quindi potrà assumere un numero minore di valori rispetto alla stessa variabile *unsigned*.

Questo programma mostra come la dimensione e i valori minimi e massimi del tipo di dato `int` possano variare con l'utilizzo dei modificatori:

```
{% include_relative src/tipi-di-dato-limiti.cpp %}
```

Se esamini con attenzione il codice scoprirai un'altra caratteristica dei modificatori del C++: se sono riferiti a un dato di tipo intero, è possibile accorciare la dichiarazione omettendo la parola-chiave `int`.

L'output di questo programma, sul mio computer è:

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

---

<a id="puntatori"></a>
Chiudiamo questa chiacchierata sui tipi di dato del *C++* con i cosiddetti *attributi intermediari*, ovvero: le *funzioni*, gli *array*, i *puntatori* e le *reference*.

Delle *funzioni* parleremo diffusamente [in seguito](/man/funzioni).
Quello che ci interessa, qui e ora, è che ogni funzione ha un suo tipo di dato.
La funzione `main`, che è la funzione principale di ogni programma, ha come tipo di dato `int` e infatti si chiude con l'istruzione:

```
    return 0;
```
    
La funzione `nome_colore`, all'interno della classe `Colore` è di tipo `void` e infatti non ha valore di ritorno.

Gli *array* sono degli insiemi di dati omogemei e si dichiarano aggiungendo al nome della variabile delle parentesi quadre.
La dimensione dell'array deve essere definita al momento della sua dichiarazione.
Questo può avvenire o in maniera esplicita, inserendo il numero di elementi fra le parentesi quadre:

```
    char elementi[10];
```

o assegnando all'array un valore che ne determinerà la dimensione massima, così come abbiamo visto nel primo esempio:

```
    char array[] = "abcdefghilmnopqrstuvz";
```

Ogni elemento dell'array è identificato da un indice che va 0 al numero di elementi dell'array meno uno.
Nel caso dell'array qui sopra, la lettera `a` avrà indice 0, la `b` avrà indice 2 e così via, fino alla `z`, che avrà indice 20.

I *puntatori* sono probabilmente l'elemento più temuto del *C* o del *C++*, ma solo perché i programmatori cialtroni agiscono senza sapere quello che stanno facendo.
Come ti ho detto prima, il *C++* è solo un modo particolare di vedere la memoria del computer.
Se tu tieni a mente questo, l'artimetica dei puntatori ti sembrerà ovvia.
Ripensa all'esempio che ti ho fatto l'altro giorno, quello con le mattonelle della cucina e immagina di avere una variabile di tipo `char`, il cui valore è 123, salvata nel quarto byte della memoria, ovvero le mattonelle da 24 a 32:

<table class="memoria">
<tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
</tr>
<tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td class="area prima">0</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">1</td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
</table>  

Per poterla ritrovare, hai bisogno di due informazioni: il tipo di dato che stai puntando e il suo indirizzo in memoria:

```
    char* ptr = 3;
```

Il valore di `ptr` indica quanti byte separano l'inzio della memoria dalla variabile; il suo tipo (`char*`) ti permette di sapere quanti byte devi leggere.
