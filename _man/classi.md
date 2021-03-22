---
status:     redazione
layout:     manuale
class:      capitolo
title:      Le classi
permalink:  /man/classi
quote:      "Ceci n'est pas une |"
---

<!-- Quando ho cominciato a scrivere questo capitolo, si è rotto il tasto "o" del mio Mac. È Domenica e siamo in clausura da COVID, quindi non posso andare in un centro commerciale a comprarne una esterna, temporanea. Perdonate eventuali refusi -->
La possibilità di definire nuovi tipi di dato grazie alle classi è la caratteristica principale del C++.

I linguaggi di programmazione come il C, il Cobol il Fortran o il Pascal, hanno un insieme limitato di tipi di dato: interi, numeri in virgola mobile, booleani, caratteri e stringhe.. giusto quello che serve a gestire una scheda anagrafica o un conto in banca.
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

Questo è l'opposto del *low coupling* di cui abbiamo parlato <a href="/man/struttura-dei-programmi#coupling" class="xref">tempo fa</a>, perché lega indissolubilmente una funzione alla struttura del dato che deve gestire.
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
Se un giorno decidessimo di modificare la struttura `orario`, dovremmo ricordarci di riscrivere anche questa funzione, adeguandola alle nuove caratteristiche della struttura, con un dispendio di tempo e maggiore possibilità di fare degli errori.
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

---

> Per questa ragione il selvaggio non ama dire il suo nome o farsi fotografare, perché per mezzo del suo nome o del ritratto egli è accessibile, e può quindi ricevere danno da chi con questi mezzi è in grado di raggiungerlo<a href="/man/note#selvaggio" class="nota"></a>.

Questa frase di Lucien Lévy-Bruhl si applica anche alle classi del C++.  
Le variabili all'interno di una classe, sono dette *dati membro* o *attributi* della classe; le funzioni, invece, sono dette *funzioni membro* o *metodi*.
Sia gli attributi che i metodi di una classe possono essere protette da letture o modifiche indebite grazie a delle parole-chiave, dette: *modificatori di accesso*.
I modificatori di accesso sono tre: `private`, `protected` e `public`.
I metodi o gli attributi dichiarati *private* sono accessibili solo alla classe stessa; quelli dichiarati come *protected* sono accessibili alla classe e a eventuali <a href="/man/ereditarieta" class="xref">classi derivate</a>; quelli dichiarati come *public* sono accessibili a qualunque elemento del programma.  
Se convertiamo in classe la struttura `Orario`, otteniamo:

```
class Orario {
protected:
    int _h;
    int _m;
    int _s;
public:
    Orario() {
        _h = 0;
        _m = 0;
        _s = 0;
    }
};
```
Gli attributi `_h`, `_m` e `_s` compaiono dopo la parola-chiave `private` e saranno quindi visibili solo alle funzioni della classe stessa.  
La funzione `Orario`, che ha lo stesso nome della classe, è detta *costruttore* e viene richiamata ogni volta che si crea una variabile di tipo `Orario`.
Il suo scopo è di inizializzare le variabili all'interno della classe, in questo caso, impostando tutti e tre i valori a 0.  
Una stessa classe può avere più costruttori; la classe `Orario`, per esempio, potrebbe avere un costruttore privo di parametri, che inizializzi ore, minuti e secondi a zero e uno che permetta invece di assegnare valori specifici a ciascun attributo:

```
class Orario {
protected:
    int _h;
    int _m;
    int _s;
public:
    Orario() {
        _h = 0;
        _m = 0;
        _s = 0;
    }
    Orario(int h, int m, int s) 
    : _h(h), _m(m), _s(s){
    }
};
```

La forma: 

```    
Orario(int h, int m, int s) 
: _h(h), _m(m), _s(s){
}
```

è solo un altro modo per inizializzare i dati membro della classe ed equivale a scrivere:

```
_h = h;
_m = m;
_s = s;
```

Un modo più succinto di ottenere lo stesso risultato con un unico costruttore è di utilizzare dei valori di default per i parametri:

```
Orario(int h = 0, int m = 0, int s = 0) 
: _h(h), _m(m), _s(s) {
}
```

Le funzioni membro devono essere dichiarate all'interno della dichiarazione della classe, ma possono essere definite sia dentro che fuori di essa. 
Se le si definisce esternamente alla dichiarazione della classe, vanno identificate aggiungendo il nome della classe prima di quello della funzione:

```
{% include_relative src/classi-classe-orario-1.cpp %}
```

Se compili questo codice, però, ottieni un errore: la funzione `main` può utilizzare il costruttore della classe `Orario` perché è dichiarato `public`, ma non può né leggere né modificare gli attributi `private:

``` 
> g++ src/cpp/classi-classe-orario-1.cpp -o src/out/esempio
src/cpp/classi-classe-orario-1.cpp:34:44: error: '_h' is a protected member of 'Orario'
    cout << setfill('0') << setw(2) << ora._h << ":" 
                                           ^
src/cpp/classi-classe-orario-1.cpp:14:9: note: declared protected here
    int _h;
        ^
src/cpp/classi-classe-orario-1.cpp:35:44: error: '_m' is a protected member of 'Orario'
         << setfill('0') << setw(2) << ora._m << ":" 
                                           ^
src/cpp/classi-classe-orario-1.cpp:15:9: note: declared protected here
    int _m;
        ^
src/cpp/classi-classe-orario-1.cpp:36:44: error: '_s' is a protected member of 'Orario'
         << setfill('0') << setw(2) << ora._s << endl;
                                           ^
src/cpp/classi-classe-orario-1.cpp:16:9: note: declared protected here
    int _s;
        ^
3 errors generated.
```

Per rendere disponibili gli attributi di una classe, si utilizzano delle funzioni dette: *funzioni di interfaccia*, che permettono un accesso controllato ai dati sia in lettura che in modifica. 
Nel caso della classe `Orario`, ne occorrono sei: una la lettura e una per la scrittura di ciascuno dei tre dati membro:

```
/** Funzioni di lettura inline */
inline int getH() { return _h; }
inline int getM() { return _m; }
inline int getS() { return _s; }

/** Funzioni di scrittura inline */
inline int setH(int h) { return _h = (h % 24); }
inline int setM(int m) { return _m = (m % 60); }
inline int setS(int s) { return _s = (s % 60); }
```

Ovviamente, puoi chiamare queste funzioni come preferisci, ma utilizzare i prefissi `get` e `set`, seguiti dal nome del parametro su cui operano rende più facile l'utilizzo della classe da parte di altri programmatori.
È lo stesso motivo per cui aggiungo il carattere *underscore* davanti al nome dei dati membro delle classi, in modo che li si possa distinguere dai  parametri delle funzioni che abbiano lo stesso nome:

```
return _h = (h % 24);
```
Non nemmeno sei obbligato a dichiarare le funzioni di interfaccia come `inline`; l'ho fatto qui perché erano estremamente semplici, ma valgono sempre le considerazioni fatte <a href="/man/funzioni#inline" class="xref">a suo tempo</a>.  
Così come abbiamo fatto per il costruttore della classe, potremmo unificare le funzioni di lettura e scrittura, utilizzando un parametro di default che determini il comportamento del programma:

```
inline int ore(int h = -1) { 
    return _h = ((h != -1) ? _h = (h % 24) : h); 
}
```

Questa sintassi è l'equivalente di:

```
inline int ore(int h = -1) { 
    if(h != -1) {
        _h = (h % 24);
    }
    return _h; 
}
```

Anche se meno evidente, è più comoda perché permette di tenere il codice su una sola riga e ti dà modo di fare un po' di pratica con gli operatori.  
Questo tipo di funzioni, però, ha due difetti: limita i valori che puoi assegnare all'attibuto e limita la granularità dei privilegi sulle funzioni.
Limita il numero di valori che puoi assegnare all'attibuto, perché esclude il valore del parametro di default; cosa che non crea problemi in questo caso, dato che non esiste un'ora `-1`, ma che potrebbe farlo nel caso di una stringa con parametro di default nullo.
Limita la granularità dei privilegi sulle funzioni, perché ti costringe a rendere pubbliche le funzioni di scrittura dei dati membro e questo, in certi casi potrebbe non essere saggio. 
Ti consiglio perciò di scrivere sempre due funzioni di interfaccia distinte per la lettura e la scrittura: sul momento ti sembrerà uno spreco di tempo, ma, a meno che il tuo programma non sia particolarmente banale, o prima o poi ti accorgerai di aver fatto la scelta corretta.

<!-- 

\[cfr. *Breve storia dell'infinito*, pagg. 30-40\]

Si può dire che esista qualcosa che non ha dimensioni?


parlare degli operatori di cast 
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)


@todo: parlare della posizione di un certo dato in memoria, che può variare in successive esecuzioni del programma. Allo stesso modo, l'io cosciente di ciascuno di noi non è detto che si manifesterà nello stesso individuo, ma potrà essere "allocato" in altri esseri. In quest'ottica, il: "Cogito ergo sum" di Cartesio è insensato, perché ciò che cogita non è ciò che è. cfr. Ananda, note a capitolo sull'Induismo

@todo: Utlizzare l'operatore `delete` per illustrare il rapporto del C’hi++ con la morte, che non è più considerata un nemico da combattere, ma un fenomeno naturale necessario al buon funzonamento dell’Universo. 
Questo approccio si rirova anche nel precetto:

    Amiamo ciò che ci ucciderà (se tutto va bene) 


-->
