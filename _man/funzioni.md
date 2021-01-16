---
status:     redazione
layout:     manuale
class:      capitolo
title:      Le funzioni
permalink:  /man/funzioni
quote:      "Call me: IsNull"
---

Le funzioni sono la caratteristica principale del C++.

Lo scopo delle funzioni è di migliorare la gestione del codice.
È possibile scrivere un programma che abbia solo la funzione `main`, ma questo ha un senso solo per programmi molto semplici, come alcuni degli esempii che abbiamo visto finora.
Il flusso di un programma *non banale*, come direbbe Stroutsup, sarà sempre suddiviso in più funzioni perché in questo modo il codice sarà più facile da leggere, da correggere e da modificare.  


```
{% include_relative src/tipi-di-dato-dimensione.cpp %}
```

Questo è il codice di un esempio che abbiamo visto nel capitolo sui <a href="/man/tipi-di-dato">tipi di dato</a>.
Se decidessimo di modificare il modo in cui il programma mostra i dati all'utente, dovremmo intervenire su tutte le righe del programma, cosa che sarebbe noiosa e potrebbe generare degli errori.
Al contrario, se isoliamo la funzione di visualizzazione, così come abbiamo fatto nell'esempio successivo, delle eventuali modifiche o correzioni dovranno essere applicate solo in un punto:

```
{% include_relative src/tipi-di-dato-limiti.cpp %}
```
Ogni volta che nel tuo codice ci sono delle istruzioni che si ripetono, valuta la possibilità di isolarle in una funzione.
Lo puoi fare anche in questo caso, con le istruzioni `cout` della funzione `main`.
Non l'ho fatto prima perché non volevo complicarti troppo le idee:

```
{% include_relative src/funzioni-limiti-modificato.cpp %}
```

L'output di questo codice è identico a quello dell'esempio precedente:

```
% g++ src/cpp/funzioni-limiti-modificato.cpp -o src/out/esempio
% src/out/esempio                                              
           int: 4 bytes, da:          -2147483648  a:           2147483647
         short: 2 bytes, da:               -32768  a:                32767
unsigned short: 2 bytes, da:                    0  a:                65535
          long: 8 bytes, da: -9223372036854775808  a:  9223372036854775807
 unsigned long: 8 bytes, da:                    0  a: 18446744073709551615
```


<!--

Spiegare COME fare a capire quale sia il proprio ruolo nell'Universo.
Non posso metterlo nel capitolo sulla memoria che è già stracolmo.

C’è una frase bellissima in un libro sulla vita dello spadaccino Myamoto Musashi: 

>Non bisogna interferire nel funzionamento dell’Universo,  
 ma prima è necessario capire quale sia,
    il funzionamento dell’Universo

Utilizzare la definizione delle funzioni senza dichiarazione come esempio per i dogmi.
?? Questo concetto verrà riutilizzato nel capitolo sulle funzioni ricorsive a proposito dei Post-It.

“Non esiste distinzione fra un essere, la sua funzione e il tempo della sua apparizione.
Gli esseri appaiono dalla non-esistenza, esistono per un istante e poi cessano di esistere.
La loro esistenza, attività e azione sono un'unica cosa.
Passato e futuro sono meri nomi.”
Samyutta Nikaya, citato da Ananda, Tempo ed Eternità, pag. 45


<a id="definizione" 
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">definizione</a>

<a id="dichiarazione" 
      onclick="history.back()" 
      title="fare click per tornare alla pagina precedente">dichiarazione</a>

<a id="inline" 
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">funzioni inline</a>


Funzioni ricorsive
------------------

Nella Lettera agli artisti, Giovanni Paolo II utilizza i termini
\'buono\' e \'bello\', ma li definisce in maniera ricorsiva, l\'uno in
funzione dell\'altro. Stesso discorso per il concetto di \'Arte\'

Bizzarro, perché la stessa cosa avviene, in condizioni diametralmente
opposte, in "Un'etica senza Dio" di Lecaldano, dove ci si appella a
concetti di 'buono' e 'giusto' senza definirli.

Differenza con i manuali SW (in cui i termini utilizzati sono tutti
definiti) e le le classi C++

Nota 7 (S.Gregorio++)


-->
