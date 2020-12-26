---
status:     redazione
layout:     manuale
class:      capitolo
title:      Gestione della memoria
permalink:  /man/memoria
quote:      "Amiamo ciò che ci ucciderà (se tutto va bene) "
---

La gestione della memoria è la componente più importante della programmazione.

Come ti ho detto, tutti i linguaggi di programmazione sono un modo di vedere la memoria del computer.
Quando tu *dichiari* una variabile con un'istruzione come: 

```
int a = 1;
```

in realtà, stai dicendo al compilatore di prendere un'area di memoria di 32 bit (un `int` è grande 4 bytes, ricordi?), associarle il nome `a` e scriverci dentro il valore binario:

 ```
 00000000000000000000000000000001
 ```
 
 Allo stesso modo, se dichiari la stringa:
 
 ```
 const char* motto = "Amiamo ciò che ci ucciderà";
 ```

stai chiedendo al compilatore di prendere un'area di memoria di 28 bytes, di associarle il nome `motto` e scriverci dentro i 27 caratteri della stringa più un ultimo carattere, con valore `0`, che indica la fine della stringa.  
Tutto questo funziona se tu sai in anticipo quanto saranno grandi le variabili con cui avrai a che fare, ma se invece devi gestire dei valori di grandezza variabile, hai due possibilità: o riservi preventivamente una quantità abbondante di spazio, o la allochi sul momento, in base alle tue necessità.
L'allocazione statica va bene se devi gestire pochi dati di dimensioni ridotte, ma se devi gestire molte variabili di grande dimensione, l'allocazione dinamica, anche se più complessa da gestire, è più efficiente.  
Il codice seguente è un esempio di gestione statica della memoria: 

```
{% include_relative src/memoria-statica.cpp %}
```

Se lo compili e lo esegui, passando due stringhe come parametri, ottieni questo output:

```
% g++ src/cpp/memoria-statica.cpp -o src/out/esempio                
% src/out/esempio "Amiamo ciò che ci ucciderà" "(se tutto va bene)"
Amiamo ciò che ci ucciderà (se tutto va bene)
```

Questo codice funziona se devi gestire solo due stringhe che, sommate, hanno meno di 200 caratteri: una condizione piuttosto restrittiva.
Puoi aumentare il numero di stringhe e la dimensione dello spazio in memoria, ma otterresti un programma che è o sovra o sotto dimensionato.
Questa non è buona programmazione.
Il buon programmatore non deve sprecare risorse; per lui, il proverbiale bicchiere non è né mezzo pieno né mezzo vuoto: è grande il doppio del necessario.

```
{% include_relative src/memoria-dinamica.cpp %}
```

L'output di questo programma, molto più parsimonioso della sua versione statica, è il seguente:

```
% src/out/esempio "Amiamo ciò che ci ucciderà" "(se tutto va bene)"                              
48 - Amiamo ciò che ci ucciderà (se tutto va bene)
% src/out/esempio "Amiamo ciò che ci ucciderà" "(se tutto va bene, cosa che non si può mai dire)"
79 - Amiamo ciò che ci ucciderà (se tutto va bene, cosa che non si può mai dire)
% src/out/esempio "Amiamo ciò che ci ucciderà" ""            
30 - Amiamo ciò che ci ucciderà 
```

<!--

@todo: spiegare la differenza fra dichiarazione e definizione; parlare della parola-chiave extern

Utlizzare l'peratore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. 
Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 

Introdurre il concetto di visibilità delle variabili, che serve in seguito per i PostIt.

Questo è anche il capitolo in cui parlare della posizione di un certo dato in memoria, che può variare in successive esecuzioni del programma.
Allo stesso modo, l'io cosciente di ciascuno di noi non è detto che si manifesterà nello stesso individuo, ma potrà essere "allocato" in altri esseri

-->
