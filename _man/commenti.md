---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      I commenti
permalink:  /man/commenti
quote:      "Il Compilatore e il Linker non usano carità, tengono i diecimila oggetti per cani di paglia"
---

 

I commenti sono la cosa più importante, quando si programma.

Un commento è un breve brano di testo che descrive in linguaggio comune
il funzionamento o lo scòpo del codice a cui è riferito:

```
/**
 * Funzione per il raddoppio dello stipendio.
 * Richiede come paramentro il valore dello 
 * stipendio corrente e ne torna il valore 
 * duplicato.
 */
long raddoppia(long stipendio)
{
    return stipendio * 2;   //  raddoppia il valore 
}
```

Pur essendo all'interno del codice, il commento viene ignorato in fase
di compilazione, perché è un'aggiunta utile solo al programmatore. 
Al processore non interessa sapere a cosa serve il codice che sta eseguendo: lo esegue e basta, senza farsi distrarre da implicazioni funzionali &mdash; o, peggio, etiche &mdash; che allungherebbero i tempi di risposta.

È importante commentare bene il proprio codice.  
Il buon codice produce programmi che durano nel tempo e, col tempo, si
tende a dimenticare.
Anche se si ha la fortuna di possedere una buona memoria, bisogna
considerare la possibilità che il proprio codice sia utilizzato da un
collega. Non solo non è educato costringerlo ad analizzare ogni singola
riga di codice per capirne il funzionamento, ma è anche improduttivo.

Così come la penuria, anche l'eccesso di commenti è un errore da evitare.
Il programmatore inesperto non commenta il proprio codice perché pensa
che sia una perdita di tempo. È davvero un atteggiamento poco
responsabile.
Il neofita zelante riempie il proprio codice di commenti, o perché
ritiene che chi lo andrà a leggere sarà meno esperto di lui o perché
vuole in questo modo esaltare le sue poche conoscenze.
Il programmatore esperto commenta solo ciò che non è di per sé evidente
e indica i possibili punti deboli del suo programma in modo che chi si
trova a riutilizzarlo o a correggerlo vi presti la dovuta attenzione.
Il programmatore perfetto non commenta il suo codice, perché il suo codice è auto-esplicativo:

```
typedef Importo unsigned long;

Importo raddoppiaStipendio(Importo stipendioCorrente)
{
    return stipendioCorrente * 2;   
}
```

È lo stesso brano di codice che abbiamo visto prima, ma stavolta i commenti non servono, perché gli intenti della funzione sono espressi direttamente nel codice, rendendo espliciti il nome della funzione, del suo parametro e del suo valore di ritorno.
L'istruzione `typedef`, che hai visto anche negli esempii precedenti, seve a 
definire dei nuovi tipi di dato, come alias di tipi di dato esistenti.
L'istruzione:

```
typedef time_t Data;
```

definisce il tipo di dato `Data` come alias del tipo di dato standard `time_t`, mentre l'istruzione:

```
typedef Importo unsigned long;
```

definisce il tipo di dato `Importo` come alias del tipo di dato standard `unsigned long`.

La definizione dei proprii tipi di dato non solo rende il codice più leggibile, ma lo rende anche più facile da modificare.
La funzione originale utilizza dei valori di tipo `unsigned long`, ovvero delle sequenze di 4 byte che permettono di memorizzare numeri interi da 0 a 4.294.967.295 (2<sup>32</sup>).
Questo tipo di dato può essere utilizzato per uno stipendio che non abbia cifre decimali, come quello del Maestro Canaro nel secolo scorso, ma se dovessimo raddoppiare uno stipendio con delle cifre decimali, dovremmo utilizzare dei tipi di dato come i `float` o i `double` e, senza una `typedef`, saremmo costretti a modificare sia il valore di ritorno che il tipo di parametro della funzione:

```
float raddoppia(float stipendio)
{
    return stipendio * 2;   //  raddoppia il valore 
}
```  
Se invece abbiamo definito un nostro tipo di dato dobbiamo modificare solo l'istruzione `typedef`, lasciando tutto il resto invariato:


```
typedef Importo float;

Importo raddoppiaStipendio(Importo stipendioCorrente)
{
    return stipendioCorrente * 2;   
}
```

È ammissibile che i commenti abbiano una sfumatura umoristica, può
essere utile per scaricare un po' della tensione in chi legge, così come
scambiarsi una battuta mentre si lavora, ma anche in questo non si deve
esagerare.

```
    case STATE_CR:  // Got CR: look for LF 
        state = STATE_NORMAL;
        if( ch == LF) {
            continue;
        }
        break;
    default:  // Hmmm... this shouldn't happen
        break;
    }
    cgi.param_data[j++] = ch;
}
```

---

Il C++ prevede due modi distinti per commentare il codice: due caratteri
`//` affiancati o la sequenza `/*  */`, che il Linguaggio ha mutuato dal
suo predecessore, il C.
Nel primo caso, il compilatore ignora i caratteri dal simbolo fino alla
fine della riga; nel secondo caso, ignora tutto ciò che è compreso fra
le due sequenze di caratteri.

````
/**
 * Questa sintassi è più comoda per i commenti 
 * che si estendono su più di una riga
 */
for (int i = 0; i < 10; i++) {
    cout << i << endl; // commenti di una riga
}

```

Entrambe le soluzioni hanno dei pro e dei contro che con l'esperienza
risultano evidenti. Scegliere l'uno o l'altro è spesso una questione
di convenienza, altre volte una questione di stile, ma se si capisce la
vera essenza del Linguaggio, è solo una questione di ritmo.

---

{% include_relative canaro/codice-commentato.md %}


<!--
@todo - introdurre il concetto di "post-it"

I commenti sono un po' come la letteratura: se si scrive troppo poco è
male; se si scrive troppo, dilungandosi in descrizioni inutili, è
altrettanto sbagliato.

Il paragone vale anche all'inverso: i libri, le opere letterarie, sono
i commenti al codice della vita. Si scrive ciò che si desidera
ricordare.
-->
