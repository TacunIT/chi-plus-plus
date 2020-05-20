---
status:     bozza
layout:     manuale
class:      capitolo
title:      I puntatori
permalink:  /man/puntatori
quote:      "Tutto è byte"
---

Questo programma mostra come la dimensione di un puntatore modifichi il risultato della lettura dei dati:

```
{% include_relative src/tipi-di-dato-puntatori.cpp %}
```

Quello qui sotto è l'output del programma.
Voglio proprio vedere come farai a farlo entrare nel tuo libro. 

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

Le istruzioni: `p1++` e `p2++` *incrementano* di un'unità il puntatore, ovvero lo spostano in avanti nella memoria del numero di byte corrispondenti alla dimensione del tipo di dato a cui è associato.
Il puntatore `p1` è un `unsigned char`, quindi si sposta di otto bit; il puntatore `p12` è uno `short int`, quindi si sposta di sedici bit.
È questo il motivo per cui il secondo ciclo di lettura dura la metà del primo: perché la quantità di bit letta per ogni iterazione è doppia. 
Se mi fossi distratto e avessi copiato il codice del primo ciclo di lettura così com'è, senza dividere per due il numero di cicli, il puntatore avrebbe continuato a “camminare” in avanti nella memoria, oltre i confini dell'array e questo, come vedremo in seguito, non è assolutamente bene.
