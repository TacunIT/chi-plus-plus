---
status:     pubblicato 
layout:     manuale
class:      capitolo
title:      I tipi di dato
permalink:  /man/tipi-di-dato
quote:      "Tutto è byte"
---

La varietà dei tipi di dato disponibili è la caratteristica principale del C++.

Il C++ ha ereditato dal C una vasta gamma di tipi di dato.
A seconda della loro natura, possiamo dividere questi tipi di dato in due gruppi: i dati *scalari* e i dati *aggregati*.  
I tipi di dato *scalari* sono: `void`, `bool`, `char`, `wchar_t`, `int`, `float`, `double` e permettono di gestire gli elementi classici di un programma: i numeri interi, i numeri decimali, le lettere e i valori booleani.  
I tipi di dato *aggregati* sono gli *array*, le *unioni*, gli *emumerati*, le *strutture* e le *classi*. 
Questi, come dice anche il loro nome, sono costituiti dall'aggregazione di più dati scalari dello stesso tipo o di tipi differenti.  
Il prossimo brano di codice &mdash; fastidiosamente didascalico, nella sua sostanziale inutilità &mdash; mostra i principali tipi di dato del C++.
Contiene molti elementi di cui ancora non ti ho parlato, quindi non preoccuparti se non capisci del tutto ciò che fa.

```
{% include_relative src/tipi-di-dato-principali.cpp %}
```

Compilando ed eseguendo questo codice, otterrai:

```
% g++ src/cpp/tipi-di-dato-principali.cpp -o src/out/esempio
% src/out/esempio 
booleano:0
carattere:C
intero:1234567890
decimale:3.14
array:abcdefghilmnopqrstuvz
coloreRGB:green
```

Il tipo di dato `void` non ha né una dimensione né un valore e può essere assegnato solo a un puntatore o a una funzione che non torna alcun tipo di valore, come la funzione `nome_colore` della classe `Colore`.  
Il tipo di dato `bool` è utilizzato per gestire i valori booleani.
Può assumere solo due valori: `true` o `false`, quindi ha la dimensione minima possibile, ovvero un byte.  
Il tipo `int` permette di gestire i numeri interi. 
Di solito ha una dimensione di quattro byte, che può essere aumentata o diminuita per mezzo di parole-chiave dette: 
<a href="#modificatori" class="xref">modificatori</a>.  
I tipi `float` e `double` si utilizzano per gestire i numeri decimali. 
Hanno una lunghezza di quattro e otto byte rispettivamente e una precisione di sette e quindici cifre decimali.  
I tre elementi che compaiono al di fuori della funzione `main` sono tipi di dato *aggregati* e permettono di definire dei tipi di dati non standard.  
Gli `enum` permettono di assegnare dei nomi a dei valori, rendendo più facile la programmazione.
Nell'esempio, l'*enum* `RGB` assegna un nome a tre valori della codifica RGB.
Questo nuovo tipo di dato è utilizzato nella struttura `ColoreRGB`.  
Le `struct` permettono di creare degli insiemi di dati eterogenei.
La variabile `ColoreRGB` contiene due variabili differenti: un valore di tipo `RGB` e un 
<a href="#puntatori" class="xref">puntatore</a>   
a carattere.  
Tutti i tipi di dati che abbiamo visto finora sono un retaggio del linguaggio *C*.
La classe `Colore`, invece, è una delle novità introdotte dal C++ e contiene due elementi: una struttura di tipo `ColoreRGB` e una funzione che mostra il nome del colore.  
Attenzione, però: nessuno di questi signori è in realtà ciò che afferma di essere.
Nella variabile `booleano` non c'è il valore `true` o `false`, ma un valore binario che il sistema considera tale.
Allo stesso modo, nella variabile `carattere`, non c'è la lettera `C`, ma il valore binario corrispondente alla codifica ASCII della lettera `C`.
Ogni tipo di dato non è altro che il nome di una quantità di memoria.
Ricordatelo, perché questo è la chiave di tutto. 

---

La dimensione di memoria associata a ciascun tipo di dato non è fissa, ma può variare a seconda del sistema in cui stai lavorando.
Il codice qui sotto ti permette di conoscere la dimensione in byte dei tipi di dato scalari:<a id="sizeof"></a>

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

<a id="funzioni"></a>
L'ultima cosa di cui ti devo parlare, a proposito dei tipi di dato del C++ sono i cosiddetti *attributi intermediari*, ovvero: le *funzioni*, gli *array*, i *puntatori* e le *reference*.  
Delle *funzioni* parleremo diffusamente 
<a href="/man/funzioni" class="xref">in seguito</a>.
Quello che ci interessa, qui e ora, è che ogni funzione ha un suo tipo di dato.
La funzione `main`, che è la funzione principale di ogni programma, ha come tipo di dato `int` e infatti si chiude con l'istruzione:

```
return 0;
```
    
La funzione `nome_colore`, all'interno della classe `Colore` è di tipo `void` e, come puoi vedere, non ha valore di ritorno.  
Gli *array* sono degli insiemi di dati omogenei e si dichiarano aggiungendo al nome della variabile delle parentesi quadre.
La dimensione dell'array deve essere definita al momento della sua dichiarazione; questo può avvenire o in maniera esplicita, inserendo il numero di elementi fra le parentesi quadre:

```
char elementi[10];
```

o assegnando all'array un valore che ne determinerà la dimensione massima, così come abbiamo visto nel primo esempio:

```
char array[] = "abcdefghilmnopqrstuvz";
```

Ogni elemento dell'array è identificato da un indice che va 0 al numero di elementi dell'array meno uno.
Nel caso dell'array qui sopra, la lettera `a` avrà indice 0, la `b` avrà indice 2 e così via, fino alla `z`, che avrà indice 20.  

<hr id="puntatori">

I *puntatori* sono come i pit-bull: alla maggior parte delle persone fanno paura, ma chi li conosce sa che sono cani dolcissimi, se li sai trattare.
Quello che devi tenere sempre a mente è che il *C++* è solo un modo particolare di vedere la memoria del computer e nella memoria non ci sono caratteri, non ci sono classi, non ci sono immagini e non ci sono film porno, ma solo una lunga sequenza di 1 e di 0:

```
0100001100100111011010000110000101101110011011100110111100100000
0110011001101111011100100111001101100101001000000111010001110101
0111010001110100011001010010000001100101001000000110010001110101
0110010100100000011011000110000100100000011100110111010001100101
0111001101110011011000010010000001100101011101001110000000100000
0000101001001010011001010010000001100110011010010110111101110010
0110100101110011011000110110010100100000011001000110010101101110
0111010001110010011011110010000001100001011011000010000001100011
0110111101110010011001010010000000100111011011100010000001101001
0110110001101100011101010111001101101001011011110110111001100101
```

L'unico modo per dare un senso a questa catena di valori binarii è di suddividerli in blocchi e assegnare un tipo di dato a ciascun blocco.
Per esempio, se suddividi la sequenza binaria qui sopra in blocchi di otto bit: 

```
01000011 00100111 01101000 01100001 01101110 01101110 01101111 
00100000 01100110 01101111 01110010 01110011 01100101 00100000 
01110100 01110101 01110100 01110100 01100101 00100000 01100101 
00100000 01100100 01110101 01100101 00100000 01101100 01100001 
00100000 01110011 01110100 01100101 01110011 01110011 01100001 
00100000 01100101 01110100 11100000 00100000 00001010 01001010 
01100101 00100000 01100110 01101001 01101111 01110010 01101001 
01110011 01100011 01100101 00100000 01100100 01100101 01101110 
01110100 01110010 01101111 00100000 01100001 01110010 00100000 
01100011 01101111 01110010 01100101 00100000 00100111 01101110 
00100000 01101001 01101100 01101100 01110101 01110011 01101001 
01101111 01101110 01100101 
```

e converti ciascun valore nel corrispondente carattere del set ASCII, scopri che una sequenza apparentemente insensata di 1 e di 0 è in realtà l'inizio di una famosa canzone popolare:

```
01000011 =  67 = C
00100111 =  39 = '
01101000 = 104 = h
01100001 =  97 = a
01101110 = 110 = n
01101110 = 110 = n
01101111 = 111 = o
00100000 =  32 = 
```

Per identificare i valori all'interno della sequenza di bit, hai bisogno di due informazioni: il tipo di dato che stai puntando e il suo indirizzo in memoria.
I puntatori ti permettono di ottenere queste informazioni: il loro valore definisce l'indirizzo di memoria da cui leggere; il loro tipo definisce la dimensione del valore puntato.

```
unsigned char * ptr = valori;
```

Molti pensano ai puntatori come a delle bandierine che ti permettono di identificare un punto specifico della memoria, ma questo è vero solo per i puntatori `void`, che non hanno un tipo di dato associato. 
Gli altri puntatori, più che una bandierina, sono una sorta di maschera che può scorrere sulla sequenza di bit, isolando ed evidenziando i singoli valori che la compongono:

<pre><code style="color:#999;line-height:1.5">01000011 00100111 01101000 01100001 01101110 01101110 01101111 
00100000 01100110<span style="padding:2px;border:solid 1px;color:#000;margin:0 3px;">01101111</span>01110010 01110011 01100101 00100000 
01110100 01110101 01110100 01110100 01100101 00100000 01100101 
00100000 01100100 01110101
</code></pre>

Questo programma mostra come la dimensione di un puntatore modifichi il risultato della lettura dei dati:

```
{% include_relative src/tipi-di-dato-puntatori.cpp %}
```

Questo è l'output del programma; voglio proprio vedere come farai a farlo entrare nel tuo libro: 

```
 0          01000011    67   C
 1          00100111    39   '
 2          01101000   104   h
 3          01100001    97   a
 4          01101110   110   n
 5          01101110   110   n
 6          01101111   111   o
 7          00100000    32    
 8          01100110   102   f
 9          01101111   111   o
10          01110010   114   r
11          01110011   115   s
12          01100101   101   e
13          00100000    32    
14          01110100   116   t
15          01110101   117   u
16          01110100   116   t
17          01110100   116   t
18          01100101   101   e
19          00100000    32    
20          01100101   101   e
21          00100000    32    
22          01100100   100   d
23          01110101   117   u
24          01100101   101   e
25          00100000    32    
26          01101100   108   l
27          01100001    97   a
28          00100000    32    
29          01110011   115   s
30          01110100   116   t
31          01100101   101   e
32          01110011   115   s
33          01110011   115   s
34          01100001    97   a
35          00100000    32    
36          01100101   101   e
37          01110100   116   t
38          11100000   224   ?
39          00100000    32    
40          00001010    10   
41          01001010    74   J
42          01100101   101   e
43          00100000    32    
44          01100110   102   f
45          01101001   105   i
46          01101111   111   o
47          01110010   114   r
48          01101001   105   i
49          01110011   115   s
50          01100011    99   c
51          01100101   101   e
52          00100000    32    
53          01100100   100   d
54          01100101   101   e
55          01101110   110   n
56          01110100   116   t
57          01110010   114   r
58          01101111   111   o
59          00100000    32    
60          01100001    97   a
61          01110010   114   r
62          00100000    32    
63          01100011    99   c
64          01101111   111   o
65          01110010   114   r
66          01100101   101   e
67          00100000    32    
68          00100111    39   '
69          01101110   110   n
70          00100000    32    
71          01101001   105   i
72          01101100   108   l
73          01101100   108   l
74          01110101   117   u
75          01110011   115   s
76          01101001   105   i
77          01101111   111   o
78          01101110   110   n
79          01100101   101   e

 0  0010011101000011 10051   C
 1  0110000101101000 24936   h
 2  0110111001101110 28270   n
 3  0010000001101111  8303   o
 4  0110111101100110 28518   f
 5  0111001101110010 29554   r
 6  0010000001100101  8293   e
 7  0111010101110100 30068   t
 8  0111010001110100 29812   t
 9  0010000001100101  8293   e
10  0010000001100101  8293   e
11  0111010101100100 30052   d
12  0010000001100101  8293   e
13  0110000101101100 24940   l
14  0111001100100000 29472    
15  0110010101110100 25972   t
16  0111001101110011 29555   s
17  0010000001100001  8289   a
18  0111010001100101 29797   e
19  0010000011100000  8416   ?
20  0100101000001010 18954   
21  0010000001100101  8293   e
22  0110100101100110 26982   f
23  0111001001101111 29295   o
24  0111001101101001 29545   i
25  0110010101100011 25955   c
26  0110010000100000 25632    
27  0110111001100101 28261   e
28  0111001001110100 29300   t
29  0010000001101111  8303   o
30  0111001001100001 29281   a
31  0110001100100000 25376    
32  0111001001101111 29295   o
33  0010000001100101  8293   e
34  0110111000100111 28199   '
35  0110100100100000 26912    
36  0110110001101100 27756   l
37  0111001101110101 29557   u
38  0110111101101001 28521   i
39  0110010101101110 25966   n
```

Come vedi, i bit sono gli stessi, ma cambiando il tipo di dato associato al puntatore e quindi la sua dimensione, il valore dei dati diventa un altro e la conversione dei numeri in lettere perde di significato.  
Le istruzioni: `p1++` e `p2++` incrementano di un'unità il puntatore, ovvero lo spostano in avanti nella memoria del numero di byte corrispondenti alla dimensione del tipo di dato a cui è associato.
Il puntatore `p1` è un `unsigned char`, quindi si sposta di otto bit; il puntatore `p12` è uno `short int`, quindi si sposta di sedici bit.
È questo il motivo per cui il secondo ciclo di lettura dura la metà del primo: perché la quantità di bit letta per ogni iterazione è doppia. 
Se mi fossi distratto e avessi copiato il codice del primo ciclo di lettura così com'è, senza dividere per due il numero di cicli, il puntatore avrebbe continuato a “camminare” in avanti nella memoria, oltre i confini dell'array e questo, come vedremo in seguito, non è assolutamente bene.  
Le *reference* sono degli alias delle variabili a cui sono associati.
Come per i gibboni o i cigni, il legame fra una *reference* e la sua variabile dura tutta la vita.
Mentre i puntatori possono avere un valore `NULL` e possono essere associati a variabili differenti nel corso dell'elaborazione, le *reference* devono sempre essere associate a una variabile e quell'associazione non può essere modificata successivamente.

```
{% include_relative src/tipi-di-dato-reference.cpp %}
```

Compilando ed eseguendo il codice, otterrai:

```
% g++ src/cpp/tipi-di-dato-reference.cpp -o src/out/esempio
% src/out/esempio                                          
valori iniziali: v=10, r=10
valori finali:   v=20, r=20
```

Approfondiremo i pro e i contro delle *reference* quando parleremo delle 
<a href="/man/funzioni" class="xref">funzioni</a>.

<hr id="casting">

Dato che ciascun tipo di dato non è altro che un modo per vedere la memoria, è possibile fare delle conversioni da un tipo all'altro.
Le conversioni possono essere *implicite* o *esplicite*.
Le conversioni *implicite* sono quelle che avvengono quando un valore è copiato fra variabili di tipo compatibile:

```
int  i = 0;
char c = i;
```

In questo caso, assegnamo a una variabile di tipo `char` il valore di una variabile di tipo `int` e il compilatore ce lo lascia fare perché il valore dell'intero può essere salvato senza problemi anche nel singolo byte del `char`.
Se volessimo rendere esplicita questa conversione, dovremmo utilizzare la sintassi:
 
```
int  i = 0;
char c = (char) i;
char c = char (i);
```
Le due forme sono equivalenti. 
La prima è quella che il C++ ha ereditato dal C; la seconda è chiamata *notazione funzionale*. 
Nell'esempio precedente, la variabile `valori` è un puntatore a `unsigned char`, ma abbiamo detto al sistema di considerarla un puntatore a `short int` con l'istruzione:

```
duebyte * p2 = (duebyte*)valori;
```

Il C++ ha anche altri modi per convertire un tipo di dato in un altro, ma siccome si applicano principalmente alle classi, li vedremo in seguito.

<hr id="dottrina">

Quello che ti ho appena detto del C++ vale anche per il C'hi++.
Così come la “realtà” all'interno di un computer altro non è che una sequenza di valori binari che, aggregati fra di loro, costituiscono le entità gestite dal sistema, la realtà in cui noi viviamo altro non è che una manifestazione dell'azione dell'energia dell'Universo sulle particelle che costituiscono tutto ciò che esiste, ovvero gli *spazioni*.  
Puoi pensare all'Universo come a una versione tridimensionale di uno schermo di PC.
Le immagini che vedi su questo schermo sono costituite da minuscoli puntini colorati, detti *pixel*.
Quando lo schermo è spento, i pixel sono neri e non mostrano alcuna immagine; quando lo accendi, l'energia del catodo colpisce i pixel e li rende visibili.
Tutto ciò che vedi, all'interno dello schermo, però, è illusorio.
O meglio: esiste, ma non è ciò che sembra. 
Gli elementi delle finestre non sono tridimensionali, anche se hanno delle ombre e quando vedi il puntatore del mouse spostarsi da una finestra all'altra in realtà stai vedendo i pixel dello schermo che cambiano di colore
È un'illusione auto-indotta e volontaria: il tuo cervello vede qualcosa, ma finge che sia altro, perché è più comodo così.  
La stessa cosa avviene con gli spazioni, solo che invece di essere disposti su una superficie piana, come i pixel dello schermo, gli spazioni sono una matrice tridimensionale e hanno quella che il Maestro Canaro definiva: “esistenza potenziale”; se sono irradiati di energia, acquisiscono massa e quindi esistenza, altrimenti non esistono.
<!--
Più precisamente, hanno "un'esistenza perpetua e non causata", come gli atomi del Vājasaneyī Saṃhitā (IV,1), citato da Ananda in Tempo ed Eternità.
-->
Quando il *Big Bang* irradia la sua Energia nell'Universo, questa colpisce gli spazioni dando loro una massa e generando tutto ciò che esiste, dalle nebulose di *Wolf–Rayet* alla tua maestra delle Elementari.  
Così come un `char`, `double` o `class` sono solo dei nomi convenzionali per degli insiemi di bit, anche `elio`, `tungsteno` o `cocomero` sono nomi convenzionali per delle quantità di energia.
*Energia*, bada bene, non *spazioni*, perché gli spazioni sono fissi; quella che si muove è l'Energia.
Quando tu sposti il braccio come hai fatto adesso, non stai realmente spostando il braccio, ma trasferendo l'energia che costituiva il tuo braccio da un gruppo di spazioni a un altro.
E anche se restiamo immobili, qui, in questa stanza, l'energia di cui siamo costituiti continua a trasferirsi nella matrice degli spazioni perché il Pianeta in cui viviamo ruota intorno al suo asse e intorno al Sole; il Sole ruota intorno alla Via Lattea e la Via Lattea si muove a sua volta rispetto alle altre galassie.
Né io né te siamo, adesso, costituiti dagli stessi spazioni che eravamo pochi secondi fa.
Siamo un'immagine in movimento, come il puntatore del mouse, o come le luci delle decorazioni natalizie.
Come disse Sant'Agostino, siamo, allo stesso tempo, reali e illusorii:

> {{ site.data.citazioni.agostino }} <a id="agostino" href="/man/note/#agostino" class="nota"></a>

Per i *Vedanta*, il Mondo ha la natura dell'Arte perché la realtà dell'arte-fatto è differente dalla realtà dell'arte-fice.
Questa similitudine, oltre che per Platone, è valida anche per i linguaggi di programmazione: un oggetto all'interno di un programma esiste, ma non è realmente ciò che rappresenta, anche se a noi fa comodo ritenerlo tale.
Come scrisse Ezra Pound<a id="pound" href="/man/note/#pound" class="nota"></a>, solo i sogni esistono realmente, perché la loro natura irreale rimane tale anche in una realtà illusoria.

---

Gli spazioni definiscono anche i limiti delle nostre grandezze e delle nostre unità di misura.
Pensa a una retta: teoricamente, è un insieme infinito di punti che si estende in due direzioni.
I punti, però, sono privi di dimensione, quindi, per fare anche solo un piccolo tratto di retta, ne serve un numero infinito.
In sostanza, secondo i matematici, in ciascuna retta coesistono due forme di infinito: quello sincategorematico della lunghezza e quello categoriematico della sequenza di punti.
(O forse il contrario: non mi ricordo mai qual'è l'infinito in atto e quale quello potenziale.)
Capisci bene che questa è una panzana: l'idea che se moltiplichi all'infinito il nulla tu possa ottenere qualcosa è solo un tentativo dei matematici di giustificare la loro vita sessuale.  
La retta è la rappresentazione ideale di un insieme finito di spazioni contigui.
È molto, molto sottile, ma una dimensione ce l'ha.
Anche il piano, con buona pace di René Guenon, è costituito da un insieme finito di spazioni contigui e per un singolo punto non passano infinite rette, ma un numero finito, per quanto alto, perché la granularità degli spazioni limita il numero delle possibili angolazioni.
Stesso discorso vale per i numeri naturali: non li si può estendere all'infinito, ma solo fino al numero totale di spazioni attivi nell'Universo, perché qualsiasi numero superiore indicherebbe una quantità che non esiste e sarebbe quindi insensato.  
Gli spazioni definiscono anche l'unità minima di tempo, quella che il Maestro Canaro definiva scherzosamente lo “spazione-tempo”, ovvero l'intervallo di tempo necessario a uno spazione per acquisire tutta l'energia di uno degli  spazioni con cui è a contatto.
È questo il motivo per cui la velocità luce non può superare i trecento milioni di metri al secondo: perché è limitata dal tempo di trasferimento dell'energia fra gli spazioni.

---

Anche il C'hi++ ritiene simili il Mondo e l'Arte, ma non solo per la loro natura.
Il Mondo e l'Arte sono simili perché il loro scòpo è lo stesso.
