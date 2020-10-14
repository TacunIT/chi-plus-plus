---
status:     in-redazione
layout:     manuale
class:      capitolo
title:      Il preprocessore
permalink:  /man/preprocessore
quote:      ""
---

Negli esempi precedenti abbiamo visto alcune istruzioni particolari, perché hanno un carattere `#` all'inizio e non hanno un carattere `;` alla fine:

``` 
#include <iostream>
```

Queste istruzioni sono delle *direttive a pre-processore* e possono essere di tre tipi:

- direttive di inclusione;
- definizioni e macroistruzioni;
- direttive condizionali.

<!--
6.2   DIRETTIVE DI INCLUSIONE
Le direttive di inclusione sono certamente le più comunemente usate, infatti vengono utilizzate per includere i file con le definizioni delle funzioni di libreria, le definizioni delle macroistruzioni e dei simboli necessari per la corretta compilazione dei programmi.
La forma sintattica di questa direttiva è quella che abbiamo più volte incontrato nei precedenti esempi:
#include <file>
dove per file si intende un qualsiasi file presente nelle directory di include definite con le opzioni del compilatore.
Alcuni dei file piu comunemente usati sono:
stdio.h;
stdlib.h;
string.h;
math.h;
time.h;
Questi file contengono le definizioni dei tipi di dati ed i prototipi delle funzioni utilizzati rispettivamente per le operazione di I/O standard, funzioni di conversione e gestione dinamica della memoria, funzioni di trattamento delle stringhe, funzioni matematiche, funzioni lettura dell’orologio di sistema.
Una forma alternativa è la seguente:
#include "miofile"
In questo caso il file deve trovarsi nella directory corrente. Questa forma è usata per l’inclusione di porzioni di codice inerenti al programma.
È possibile nidificare le direttive #include, infatti un file incluso può a sua volta contenere tale direttiva. Il livello di nidificazione è tuttavia dipendente dallo specifico preprocessore e dall’architettura del sistema. 
6.3   DEFINIZIONI E MACROISTRUZIONI
È possibile definire degli identificatori correlati a stringhe di sostituzione che il preprocessore provvederà ad inserire nel codice sorgente in luogo di detti identificatori prima del processo di compilazione. Generalmente, tali stringhe sono costituite da valori costanti o istruzioni, nel primo caso sono chiamate costanti simboliche, nel secondo sono chiamate macroistruzioni o più brevemente macro.
Alcuni esempi validi di costanti simboliche sono:
#define FALSE 0
#define TRUE 1
#define NUMERO 0.2
#define STRINGA "Stringa di caratteri" 
Alcuni esempi validi di macroistruzioni sono:
#define INCREMENTO(x) x * 0.2
#define CUBO(x) x * x * x 
È inoltre possibile eliminare una #define precedentemente assegnata per mezzo della direttiva #undef.
Vediamo ora un esempio di uso delle definizioni e delle macroistruzioni:
PRE01.C - Definizioni e macroistruzioni
/**********************************************************
 File: pre1.c
 Desc: definizioni e macroistruzioni
 Comm: 
**********************************************************/
#include <stdio.h>

#define NUMERO 3
#define INCREMENTO(x) x * 1.23
#define CUBO(x) x * x * x

int main()
{
  int x;
  double y;
    
  printf("Numero     : %d \n", NUMERO);
  x = CUBO(NUMERO);
  printf("Cubo       : %d \n", x);
  
#undef NUMERO
#define NUMERO 4

  printf("Numero     : %d \n", NUMERO);
  x = CUBO(NUMERO);
  printf("Cubo       : %d \n", x);
  
  y = INCREMENTO((double)x);
  printf("Incremento : %f \n", y);

  return 0;
}
/******* End *********************************************/
Il programma produrrà il seguente output:
Numero     : 3
Cubo       : 27
Numero     : 4
Cubo       : 64
Incremento : 78.720000
Una macro generalmente è di esecuzione piu` veloce di una funzione che effettua le medesime operazioni, in quanto, operando una pura sostituzione di codice  non richiede la memorizzazione sullo stack di alcun indirizzo di ritorno. Nei file standard di "include" possiamo trovare sovente alcune funzioni implementate come macro, generalmente queste ultime sono riconoscibili dal prefisso _(underscore).
Un esempio tipico è quello della funzione toupper(c) che effettua la conversione a maiuscolo di un carattere minuscolo, una forma tipica della sua implementazione come macro è:
#define _toupper(c)     ((c)- 'a'+'A')
oppure:
#define _toupper(c) ((c)>= 'a'&&(c) <= 'z'?(c)& 0x5F:(c))
Questa seconda forma, a prima vista oscura, può essere facilmente così tradotta: se il parametro c è minuscolo, ovvero una lettera compresa tra a e z, l’espressione restituisce la corrispondente maiuscola per mezzo dell’operatore & (bitwise), altrimenti restituisce il carattere senza alcuna modifica.
6.4   DIRETTIVE CONDIZIONALI
Le direttive condizionali consentono di delimitare una o più istruzioni che verranno compilate in determinate condizioni. Questo tipo di compilazione è definito compilazione condizionale e viene utilizzato in molti casi per la creazione di programmi che debbano funzionare su diversi sistemi operativi.
Direttive condizionali
Direttiva
Descrizione
#if
se non zero
#ifdef
se definito
#ifndef
se non definito
#else
altrimenti
#elif
altrimenti se
#endif
fine del blocco condizionale
Vediamo più chiaramente con un esempio gli effetti delle compilazioni condizionali. Consideriamo il seguente programma:
PRE2.C- Compilazione condizionale
/**********************************************************
 File: pre2.c
 Desc: compilazione condizionale
 Comm: 
**********************************************************/
#include <stdio.h>

#define FLAG 1

#if FLAG
#define STRING "Elevazione al cubo"
#define FORMULA(x) x * x * x
#else
#define STRING "Elevazione al quadrato"
#define FORMULA(x) x * x
#endif

int main()
{
  int a = 4, x;
  char s[25];
    
  strcpy(s, STRING);
  printf("Flag : %d  Numero : %d\n", FLAG, a);
  x = FORMULA(a);
  printf("%-25s : %d \n", s, x);

  return 0;
}
/******* End *********************************************/
Compilato ed eseguito darà il seguente output:
Flag : 1  Numero : 4
Elevazione al cubo        : 64
Ora andiamo a sostituire l’istruzione:
#define FLAG 1
con la seguente:

#define FLAG 0
Nuovamente compilato ed eseguito il programma senza altre modifiche produrrà il seguente output:
Flag : 0  Numero : 4
Elevazione al quadrato    : 16
Naturalmente questa direttiva #define può essere contenuta in un file diverso da quello del programma ed incluso con la direttiva #include, la sostituzione di questo file esterno potrà così determinare il differente comportamento del compilatore.
Quest’ultima tecnica viene comunemente usata per le compilazioni condizionali sulla base del sistema operativo, tali compilazioni usano in molti casi lo stato di definizione di una stringa (token-string) mediante la direttiva #ifdef.

-->
