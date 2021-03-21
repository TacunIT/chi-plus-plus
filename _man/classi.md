---
status:     redazione
layout:     manuale
class:      capitolo
title:      Le classi
permalink:  /man/classi
quote:      "Ceci n'est pas une |"
---

La possibilità di definire nuovi tipi di dato grazie alle classi è la caratteristica principale del C++.

I linguaggi di programmazione come il C, il Cobol il Fortran o il Pascal, hanno un insieme limitato di tipi di dato: interi, numeri in virgola mobile, booleani, caratteri e stringhe, insomma, quello che serve a gestire un'anagrafica.
C e Pascal hanno anche la possibilità di accorpare questi tipi di dato in strutture, enumerati o array, ma questi tipi di dato sono solo dei contenitori privi di logica interna.
Inoltre, i dati all'interno di una `struct` sono accessibili a qualunque componente del programma, quindi, se li si modifica, va modificato anche il codice che li utilizza.
Immagina di definire una struttura per la gestione dell'orario, che contenga tre interi, uno per le ore, uno per i minuti e uno per i secondi:

```
struct orario {
    int h;
    int m;
    int s;
};
```

Per utilizzare questa struttura è necessario conoscerne il contenuto e il rapporto fra un valore e l'altro; in particolare, è necessario sapere (e ricordarsi): 

- che la variabile `h` può contenere solo valori da 0 a 23;
- che il valore di `m` può contenere solo valori da 0 a 59;
- che il valore di `s` può contenere solo valori da 0 a 59;
- che se `s` supera il valore di 59, `m` va incrementato di 1;
- che se `m` supera il valore di 59, `h` va incrementato di 1;

Questo è l'opposto del *low cupling* di cui abbiamo parlato <a href="/man/struttura-dei-programmi#coupling" class="xref">tempo fa</a>, perché lega indissolubilmente una funzione alla struttura del dato che deve gestire.
Per capirsi: una funzione di aggiornamento dei minuti dovrà essere qualcosa di simile a:

```
void aggiornaMinuti(struct orario &o, int minuti) 
{
    /** Incrementa il numero dei minuti */
    o.m += minuti;
    
    /** Se necessario, incrementa le ore */
    if(o.m >= 60) {

        o.m -= 60;
        o.h += 1;
        
        /** Se necessario, passa al giorno dopo */
        if(o.h >= 24) {
            o.h -= 24;
        }
    }
}
```
Se un giorno decidessimo di modificare la struttura `orario`, dovremmo ricordarci di riscrivere anche questa funzione, adeguandola alle nuove caratteristiche della struttura. 
Servirebbero più ore/uomo di lavoro e aumenterebbe la possibilità di fare degli errori.
Inoltre, nulla impedirebbe a un programmatore cialtrone di scrivere una funzione che non tiene minimamente conto del rapporto fra i ore, minuti e secondi:

```
void incrementa_m(struct orario &o, int minuti) 
{
    o.m += minuti;
}
```

Se inseriamo queste due funzioni in un programma, otteniamo:

```
{% include_relative src/classi-struttura-orario.cpp %}
```

Compilando ed eseguendo questo codice, ottieni:

```
> g++ src/cpp/classi-struttura-orario.cpp -o src/out/esempio 
> ./src/out/esempio                                          
23:45:00
00:05:00
23:65:00
```
Come puoi vedere, la prima funzione ha aggiornato i dati in maniera corretta, mentre la seconda ha prodotto un valore non valido.


<!-- 


A proposito delle unzioni di interfaccia: 

> Per questa ragione il selvaggio non ama dire il suo nome o farsi fotografare, perché per mezzo del suo nome o del ritratto egli è accessibile, e può quindi ricevere danno da chi con questi mezzi è in grado di raggiungerlo<a href="/man/note#selvaggio" class="nota"></a>.

Le classi del C++, per quanto duttili, non possono descrivere dei concetti astratti come: amore, arte o Dio.


Classi astratte
---------------

\[cfr. *Breve storia dell'infinito*, pagg. 30-40\]

Si può dire che esista qualcosa che non ha dimensioni?

Il punto non ha dimensioni.

La retta è costituita da punti.

La circonferenza è costituita da punti.

Apparentemente, tutta la geometria euclidea è basata sul nulla.

Se una circonferenza fosse costituita da punti privi di dimensione, noi
non la potremmo vedere.

Per vederla, e quindi per poterla in qualche modo utilizzare, dobbiamo
dare uno spessore ai punti che la compongono, siano essi dei minuscoli
residui di grafite o dei pixel.

Allo stesso modo, se disegnassimo con la massima precisione due aree
contigue e, con la stessa precisione, le colorassimo in maniera
differente, la linea di demarcazione fra al fine di un'area e l'inizio
dell'altra non sarebbe rettilinea, ma seguirebbe l'andamento del foglio,
o dei pixel.

Da lontano potrà anche sembrare rettilinea, ma a mano a mano che
-->
<!--
parlare degli operatori di cast 
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)


Come potrebbe essere, una classe Dio?
Forse come classi astratte



@todo: parlare della posizione di un certo dato in memoria, che può variare in successive esecuzioni del programma. Allo stesso modo, l'io cosciente di ciascuno di noi non è detto che si manifesterà nello stesso individuo, ma potrà essere "allocato" in altri esseri. In quest'ottica, il: "Cogito ergo sum" di Cartesio è insensato, perché ciò che cogita non è ciò che è. cfr. Ananda, note a capitolo sull'Induismo

@todo: Utlizzare l'operatore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. 
Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 


-->
