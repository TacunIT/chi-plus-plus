---
status:     redazione
layout:     manuale
class:      capitolo
title:      Istruzioni iterative
permalink:  /man/istruzioni-iterative
quote:      "Dopo di me, il reboot"
---

Le istruzioni di ciclo sono una delle componenti fondamentali della programmazione.
Le istruzioni che determinano l’esecuzione dei cicli rivestono particolare importanza nella 
programmazione in quanto consentono l’esecuzione ripetitiva di gruppi di istruzioni per un determinato numero di volte o fino al raggiungimento di un determinato risultato, sono queste istruzioni, in definitiva, che consentono principalmente di utilizzare efficacemente la potenza di calcolo degli elaboratori elettronici.
Il linguaggio C mette a disposizione tre istruzioni di ciclo: il ciclo for, il ciclo while ed il ciclo do while.
La caratteristica generale delle istruzioni di ciclo è quella di avere un’istruzione di controllo del ciclo ed un corpo del ciclo costituito da una o più istruzioni che vengono ripetute ad ogni iterazione.
Vediamo ora nel dettaglio le caratteristiche di queste tre istruzioni di controllo dei cicli.

## Il ciclo for
Questa istruzione viene utilizzata quando vogliamo eseguire il ciclo in numero determinato di volte. La forma generale è la seguente:

for(<espressione1> ; <espressione2> ; <espressione3>)
{
  ...istruzioni...(corpo del ciclo)
}

L’istruzione for valuta le tre espressioni per controllare l’esecuzione delle istruzioni che costituiscono il corpo del ciclo. Le tre espressioni vengono valutate nel modo seguente:
·	l’espressione1 viene valutata solo una volta precedentemente alla prima iterazione del ciclo, usualmente vengono inizializzate le variabili delle espressioni;
·	l’espressione2 è un’espressione logica o relazionale che determina se eseguire ulteriormente il ciclo, questa espressione viene valutata all’inizio di ogni iterazione. Se il valore risolto è zero (false) l’esecuzione del ciclo for termina, altrimenti continua.
·	l’espressione3 viene valutata al termine di ogni iterazione ed usualmente è costituita da un’espressione di incremento delle variabili inizializzate da espressione1.
Iniziata l’esecuzione essa continua fino a che espressione2 viene risolta in valore 0 (false), oppure viene incontrata una istruzione di interruzione break.
Un caso particolare di istruzione for viene utilizzato per effettuare cicli con numero indefinito di iterazioni, in questo caso si omettono le tre espressioni di controllo, ma si mantengono le istruzioni null (vedi capitolo 4.1.1); la sintassi è la seguente:

for( ; ; )
{
  ...istruzioni...(corpo del ciclo)
}


4.3.2   Il ciclo while
Il ciclo while viene principalmente usato nei casi dove non sia preventivamente determinato il numero di iterazioni da effettuare. Questa istruzione valuta un’espressione e quindi esegue il corpo del ciclo zero o piu` volte fino a che l’espressione è valutata pari a zero (false).
La forma generale è la seguente: 

while(espressione)
{
  ...istruzioni...(corpo del ciclo)
}

Anche in questo caso è possibile forzare il numero dei cicli indefinitamente sostituendo l’espressione con una costante nonzero, per esempio:

while(1)
{
  ...istruzioni...(corpo del ciclo)
}

Il ciclo verrà ripetuto un numero indefinito di volte, salvo l’istruzione di interruzione break come per il ciclo for.
Vediamo anche in questo caso un esempio di inizializzazione di array, in particolare prenderemo il programma di esempio istr05.c e sostituiremo le istruzioni for con istruzioni while, inizializzeremo un array di 15 elementi prima con tutti i valori a zero e poi con valori corrispondenti al numero di indice dall’elemento il cui numero è dato in input.

Nel seguente esempio vedremo come sia possibile nidificare una funzione di lettura dello standard input nell’espressione valutata dall’istruzione while.
Il programma effettua una lettura di valori interi fino a quando incontra il carattere ‘#’ che determina la fine del ciclo di input, successivamente vengono presentati in output i numeri in forma tabellare di 5 colonne per n righe.
ISTR07.C - Ciclo while per input numeri
/**********************************************************
 File: istr07.c
 Desc: ciclo while per input numeri
 Comm: 
**********************************************************/
#include <stdio.h>

int main()
{
  int a[100], n=0, i, x;

  printf("\nInput(al massimo 100)interi, seguiti da # :\n");

  while(n<100 && scanf("%d", &x))               /* 001 */
  {
    a[n++] = x;
  }
  printf("\nTermine input");
                  
  printf("\nNumeri in forma tabellare (5 per linea):\n");

  for(i=0; i<n; i++)                            /* 002 */
  {
    printf("%c%9d", i % 5 ? ' ':'\n', a[i]);
  }
  printf("\nFine\n");
  
  return 0;
}
/******* End *********************************************/
001 Ciclo ‘while’ di input, notiamo che l’espressione è composta ed è formata da un’espressione relazionale (n<100) in ‘AND logico’ con una chiamata alla funzione di libreria standard ‘scanf’, tale funzione che riceve come argomenti un formato ed un indirizzo di variabile, legge dallo standard input un valore congruente al formato e lo scrive nella locazione di memoria relativa all’indirizzo. In questo caso se il carattere non è numerico la funzione ritorna il valore 0 (false) determinando così la fine del ciclo. Altrettanto accade nel caso il valore di ‘n’ non sia inferiore a 100. Entrambe queste condizioni debbono essere vere per la prosecuzione del ciclo. Il corpo del ciclo è costituito dall’assegnazione di ‘x’ all’elemento dell’array ‘n’, notiamo come sia utilizzato il post-incremento di ‘n’ per "scorrere" l’array.
002 Ciclo ‘for’ per effettuare l’output dell’array in forma tabellare. Nella funzione ‘printf’ sono nidificati l’operatore modulo (%) e l’operatore ternario (?:). La ‘printf’, dopo aver stampato il valore dell’elemento dell’array valuta il modulo del relativo indice, se non è divisibile per 5, senza resto, stampa un carattere "blank", altrimenti stampa un carattere "new line".

## Il ciclo do-while
Il ciclo do-while si differenzia dal ciclo while che abbiamo visto in precedenza solamente per il fatto di valutare la condizione while alla fine dell’iterazione, questo determina l’esecuzione del corpo del ciclo almeno per una volta. 
La forma generale è la seguente:

do
{
  ...istruzioni...(corpo del ciclo)
} while(espressione)

Il ciclo viene eseguito una prima volta per effettuare l’assegnazione di un valore ad a e quindi viene ripetuto fino a quando la variabile a assume il valore zero (false).

### Istruzioni di interruzione
Queste istruzioni sono usate per controllare l’esecuzione di altre istruzioni. Il loro utilizzo più comune è quello di interrompere cicli o, come abbiamo già visto per break, l’istruzione di switch. Le tre istruzioni di interruzione sono:

break;
continue;
return.

Istruzione break
L’istruzione break termina i cicli for, while e do-while, nonché l’istruzione switch che la includono, passando il controllo all’istruzione immediatamente successiva al blocco istruzioni del ciclo (corpo del ciclo) o dello switch.
Vediamo ora un esempio di interruzione in un ciclo.
INTE01.C - Istruzione break
/**********************************************************
 File: inte01.c
 Desc: istruzione break
 Comm: 
**********************************************************/
#include <stdio.h>

int main()
{
  int i=0;
  
  while(++i)                                    /* 001 */
  {
    if(i == 5) break;                           /* 002 */
    printf("valore di i: %d\n", i);
  }

  return 0;
}
/******* End *********************************************/
001 Ciclo ‘while’ con pre-incremento della variabile ‘i’. Tale ciclo se non fosse interrotto da ‘break’ continuerebbe ad essere eseguito fino al verificarsi della condizione di overflow della variabile ‘i’.
002 Istruzione ‘break’ controllata dalla condizione di ‘i’ uguale a 5. In questo caso il ciclo viene eseguito solamente 4 volte.
Il programma produce il seguente output:
valore di i: 1
valore di i: 2
valore di i: 3
valore di i: 4
4.4.2   Istruzione continue
L’istruzione continue determina il passaggio del controllo alla fine del singolo ciclo di iterazione senza determinare l’uscita dal corpo del ciclo che può riprendere con la successiva iterazione.
Vediamo un esempio di un ciclo for che contiene due istruzioni di stampa a video, di cui una viene eseguita sempre e l’altra solo quando il contatore raggiunge un numero dispari.
INTE02.C - Istruzione continue
/**********************************************************
 File: inte02.c
 Desc: istruzione continue
 Comm: 
**********************************************************/
#include <stdio.h>

int main()
{
  int i;
  
  for(i=1; i<10; i++)                           /* 001 */
  {
    printf("\nciclo numero: %d ", i);
    if(i % 2) continue;                         /* 002 */
    printf("contatore pari");
  }
  printf("\nfine\n");

  return 0;
}
/******* End *********************************************/
001 Ciclo ‘for’ di 9 iterazioni.
002 Istruzione ‘continue’ eseguita solo se ‘i’ è un numero pari, in questo caso il salto alla fine del ciclo corrente determina la non esecuzione dell’ultima istruzione ‘printf’.
Il programma produce il seguente output:
ciclo numero: 1
ciclo numero: 2 contatore pari
ciclo numero: 3
ciclo numero: 4 contatore pari
ciclo numero: 5
ciclo numero: 6 contatore pari
ciclo numero: 7
ciclo numero: 8 contatore pari
ciclo numero: 9
fine
4.4.3   Istruzione return
L’istruzione return consente di terminare l’esecuzione di una funzione e di avere un eventuale valore di ritorno alla funzione chiamante. Vediamone un esempio:
INTE03.C - Istruzione return
/**********************************************************
 File: inte03.c
 Desc: istruzione return
 Comm: 
**********************************************************/
#include <stdio.h>

int  fa(int);
void fb(int);

int main()
{
  int i;
  
  for(i=1; i<10; i++)                            /* 001 */
  {
    printf("\nciclo numero: %d ", i);
    printf("valore ritornato da fa: %d", fa(i)); /* 002 */
  }

  fb(i);
  
  return 0;                                      /* 003 */
}

/* --- funzione fa ------------------------------------- */
int fa(int x)
{
  int a=5;

  if(!(x % 2))
  {
    printf("(pari)    ");
    return a * x;
  }
  printf("(dispari) ");
  return 1;
}

/* --- funzione fb ------------------------------------- */
void fb(int x)
{
  printf("\nfine (valore di i: %d)\n", x);
  return;
}
/******* End *********************************************/
001 Ciclo for di 9 iterazioni.
002 Output del valore ritornato dalla funzione fa.
003 Istruzione ‘return’ della funzione ‘main’. Secondo la direttiva ANSI la funzione ‘main’ restituisce un intero al livello del sistema operativo, il valore 0 costituisce il segnale di corretta terminazione del programma. Se però utilizziamo un compilatore K&R la funzione ‘main’ non dovrà avere valore di ritorno.
funzione fa:
Questa funzione riceve come argomento il numero di ciclo in esecuzione e ritorna il valore pari al numero di ciclo moltiplicato 5 se il numero ricevuto è pari, altrimenti ritorna il valore costante 1. Notiamo come la condizione ‘if’ sia vera (nonzero) applicando in NOT logico (!) al modulo tra ‘i’ e 2 e siano necessarie la parentesi tonde per stabilire la corretta priorità delle operazioni.
funzione fb:
Questa funzione riceve come argomento il valore corrente di ‘i’, ne effettua l’output e non ritorna nulla (finzione void). Notiamo come il valore corrente di ‘i’ sia 10 in quanto il ciclo ‘for’, pur non eseguendo il corpo del ciclo effettua comunque un ultima volta l’incremento di ‘i’ (i++).
Il programma produce il seguente output:
ciclo numero: 1 (dispari) valore ritornato da fa 1
ciclo numero: 2 (pari)    valore ritornato da fa 10
ciclo numero: 3 (dispari) valore ritornato da fa 1
ciclo numero: 4 (pari)    valore ritornato da fa 20
ciclo numero: 5 (dispari) valore ritornato da fa 1
ciclo numero: 6 (pari)    valore ritornato da fa 30
ciclo numero: 7 (dispari) valore ritornato da fa 1
ciclo numero: 8 (pari)    valore ritornato da fa 40
ciclo numero: 9 (dispari) valore ritornato da fa 1
fine (valore di i 10)



<hr id="dottrina">

<!--

@todo - qui va introdotto il concetto di ciclicità dell'Universo.
- introdurre l'idea delle "variazioni" della storia dell'Universo

-->
