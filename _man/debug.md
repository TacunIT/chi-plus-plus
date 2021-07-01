---
status:     redazione
layout:     manuale
class:      capitolo
no-index:   true
title:      Il debug
permalink:  /man/debug
quote:      "Cento Mondi di peccato sono dissipati dalla luce di un solo ticket"
---

Il debug potrà non essere il senso della vita, come recita il titolo del tuo libro, ma è indubbiamente l'aspetto più importante della programmazione.  

Nella tua carriera di programmatore potrai non utilizzare mai una classe *functor* o ridefinire l'operatore `->`, ma sicuramente farai degli errori e li dovrai correggere.
Malgrado ciò, i manuali di programmazione non parlano mai del *debug*.  
Si sono scritte migliaia di pagine sui diversi linguaggi di programmazione; non c'è primavera che non veda fiorire un nuovo paradigma di programmazione &mdash; strutturata, *object-oriented*, *agile*, *fuzzy* &mdash; eppure, nessuno si è mai preoccupato di formalizzare il processo di correzione del codice.  
Trascurare il debug è come affermare che non si faranno mai errori.
Non importa quanto sia efficiente il linguaggio di programmazione; non importa quanto sia astuto e vigile il compilatore; non importa nemmeno quanto sia bravo il programmatore: o prima o poi, la distrazione, la stanchezza o un evento esterno permetteranno a un errore di intrufolarsi nel codice.
Un puntatore utilizzato impropriamente, un ciclo in più o in meno in un'istruzione `for` o una virgola dimenticata fra i parametri di una `printf`: qualunque cosa sia, se il compilatore non sarà in grado di riconoscerla, finirà nel programma è resterà lì in attesa di produrre i suoi effetti dannosi.
Il programma potrà funzionare correttamente per anni, ma poi, un bel giorno, qualcosa non andrà come sarebbe dovuto andare e a quel punto bisognerà analizzare il codice per trovare l'errore.  
Fare degli errori è inevitabile, ed è importante sapere come porvi rimedio.
Ancora più importante, però, è sapersi accorgere degli errori.
Così come *l'Ikebarba inizia nel negozio*, il debug comincia nel momento in cui si scrive il codice.
Il modo migliore per evitare che il codice contenga degli errori è scrivere del buon codice.
Scrivere del buon codice vuol dire fare sempre il meglio che ti è possibile.
Non salvare mai un file se non sei certo che funzionerà come deve e cerca sempre di pensare a cos'altro potrebbe fare il tuo codice, oltre a quello che vuoi tu.
Come di ho detto <a href="/man/programmatore#buon-programmatore" class="xref">in una delle nostre prime chiacchierate</a>, il buon programmatore non si accontenta della strada più rapida, ma cerca sempre quella più efficiente e sicura, perché sa che scrivere del buon codice costa meno che riparare del codice fatto male.
Il Maestro Canaro, una volta disse:

> {{ site.data.canaro.marinaio }}

Il buon programmatore non può farne a meno, perché è nella sua natura; è questa, la differenza fra chi *fa* il programmatore e chi *è* un programmatore.  
La decadenza del software è iniziata quando le stampanti laser hanno soppiantato le vecchie stampanti ad aghi.
Il codice non si può leggere su un foglio A4: a meno che non sia un programma banale, non c'entrerà né in altezza né in larghezza.
Il modulo in continuo di una stampante ad aghi a 136 colonne, al contrario, ti permette di stampare tutto il tuo codice e di rileggerlo con calma; correggerlo, se necessario e migliorarlo se possibile.
È così che si facevano, le revisioni di codice, quando ancora c'erano il tempo e i soldi per fare le revisioni di codice.

<hr id="tipi-errore">

Gli errori del software possono essere di tre tipi: 

- gli errori che si manifestano durante la fase di compilazione;
- gli errori che si manifestano durante l'esecuzione del programma;
- gli errori di analisi.  

Gli <b id="errori-compilazione">errori di compilazione</b> sono causati da costrutti incorretti, che bloccano il processo di creazione del programma. 
Un errore che farai spesso è di dimenticare il punto e virgola alla fine della dichiarazione di una classe:

```
class C {
private:
    float _raggio;
    float _area;
public:
    C (int m) : _raggio(m) {}
    float getRaggio() { return _raggio; }
    float area() {
       Quadrato q;
       return 3.14159 * q(_raggio);
    }
}
```

una banale distrazione che causerà immancabilmente il messaggio:

```
> g++ src/cpp/debug-errori.cpp  -c -o src/out/esempio 
src/cpp/debug-errori.cpp:28:2: error: expected ';' after class
}
 ^
 ;
1 error generated.
```

Gli errori di compilazione sono i più facili da gestire, perché è il compilatore stesso a dirti quale sia il problema e in quale punto del codice si trovi.
L'unica difficoltà che potresti avere, specie se stai lavorando con la `STL`, è decifrare i messaggi del compilatore:

```
In file included from /Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/iostream:38:
In file included from /Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/ios:216:
In file included from /Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/__locale:15:
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/string:2027:19: error: no viable conversion from
      'const std::__1::basic_string<char>' to 'std::__1::basic_string<char, std::__1::char_traits<char>,
      std::__1::allocator<char> >::value_type' (aka 'char')
        push_back(*__first);
                  ^~~~~~~~
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/string:2075:5: note: in instantiation of function
      template specialization 'std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>
      >::__init<std::__1::istream_iterator<std::__1::basic_string<char>, char, std::__1::char_traits<char>, long> >'
      requested here
    __init(__first, __last);
    ^
src/cpp/debug-errori.cpp:43:12: note: in instantiation of function template specialization
      'std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>
      >::basic_string<std::__1::istream_iterator<std::__1::basic_string<char>, char, std::__1::char_traits<char>,
      long> >' requested here
    string s(begin,end);
           ^
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/string:876:5: note: candidate function
    operator __self_view() const _NOEXCEPT { return __self_view(data(), size()); }
    ^
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/string:1055:31: note: passing argument to parameter
      '__c' here
    void push_back(value_type __c);
```
<!-- Grazie, John Berryman https://bit.ly/3vIU4hN -->

Se un costrutto è formalmente corretto, ma *potrebbe* essere un errore, il compilatore può segnalarlo con un <b id="warning">warning</b>, un messaggio di avviso che non blocca la compilazione, ma richiama l'attenzione del programmatore sull'anomalia.  
Ho usato il condizionale (*può segnalarlo*) perché la notifica dei *warning* è un'opzione che deve essere attivata dal programmatore, specificando, fra i parametri di compilazione, quali avvisi vuole ricevere.
Dato che i parametri per attivare i diversi tipi di *warning* sono davvero tanti:

```
-Waddress   
-Wbool-compare  
-Wbool-operation  
-Wchar-subscripts  
-Wcomment  
-Wformat   
-Wformat-overflow  
-Wformat-truncation  
-Wint-in-bool-context  
-Winit-self  
-Wlogical-not-parentheses 
-Wmaybe-uninitialized 
-Wmemset-elt-size 
-Wmemset-transposed-args 
-Wmisleading-indentation 
-Wmismatched-dealloc 
-Wmismatched-new-delete 
-Wmissing-attributes 
-Wmultistatement-macros  
-Wnarrowing   
-Wnonnull  
-Wnonnull-compare  
-Wopenmp-simd 
-Wparentheses  
-Wpessimizing-move   
-Wpointer-sign  
-Wrange-loop-construct   
-Wreorder   
-Wrestrict   
-Wreturn-type  
-Wsequence-point  
-Wsign-compare   
-Wsizeof-array-div 
-Wsizeof-pointer-div 
-Wsizeof-pointer-memaccess 
-Wstrict-aliasing  
-Wstrict-overflow=1  
-Wswitch  
-Wtautological-compare  
-Wtrigraphs  
-Wuninitialized  
-Wunknown-pragmas  
-Wunused-function  
-Wunused-label     
-Wunused-value     
-Wunused-variable  
-Wvolatile-register-var  
-Wzero-length-bounds
```

e che possono essere tutti rilevanti nel processo di creazione del codice, la cosa migliore che puoi fare è di attivarli globalmente, con il parametro: `-Wall`

```
{% include_relative src/debug-errori-warning.cpp %}
```

Se compili questo codice senza attivare i *warning*, il compilatore non ti segnala nulla di anomalo:

```
> g++ src/cpp/debug-errori-warning.cpp -c -o src/out/esempio
> 
```

Se però aggiungi il parametro `-Wall` alla riga di comando, scopri che il parametro `_area` della classe `C` non viene utilizzato:

```
> g++ src/cpp/debug-errori-warning.cpp -Wall -c -o src/out/esempio
src/cpp/debug-errori-warning.cpp:19:11: 
    warning: private field '_area' is not used 
        [-Wunused-private-field]
    float _area;
          ^
1 warning generated.
```

Il codice è stato compilato, perché questa potrebbe essere una scelta intenzionale, ma il sistema ti notifica comunque l'anomalia, in modo che tu possa decidere se mantenerla o eliminarla.  
Aggiungendo il parametro `-Wextra`, ottieni un *warning* aggiuntivo perché i parametri della funzione `main` non sono utilizzati:

```
> g++ src/cpp/debug-errori-warning.cpp -Wall -Wextra -o src/out/esempio
src/cpp/debug-errori-warning.cpp:29:14: 
    warning: unused parameter 'argc' 
        [-Wunused-parameter]
int main(int argc, char** argv) 
             ^
src/cpp/debug-errori-warning.cpp:29:27: 
    warning: unused parameter 'argv' 
        [-Wunused-parameter]
int main(int argc, char** argv) 
                          ^
src/cpp/debug-errori-warning.cpp:19:11: 
    warning: private field '_area' is not used 
        [-Wunused-private-field]
    float _area;
          ^
3 warnings generated.
```

Oltre a quelli definiti dai parametri `-Wall` e `-Wextra`, il compilatore prevede una lunga lista di *warning* che possono essere definiti individualmente, a seconda delle esigenze del programma. 
Per esempio, il parametro `-Wdouble-promotion` segnala quando una variabile di tipo `float` è promossa implicitamente a `double`:

```
> g++ src/cpp/debug-errori-warning.cpp -Wall -Wextra \
    -Wdouble-promotion -c -o src/out/esempio
src/cpp/debug-errori-warning.cpp:25:27: 
    warning: implicit conversion increases 
        floating-point precision: 'float' to
      'double' [-Wdouble-promotion]
       return 3.14159 * q(_raggio);
                        ~ ^~~~~~~
src/cpp/debug-errori-warning.cpp:29:14: 
    warning: unused parameter 'argc' [-Wunused-parameter]
int main(int argc, char** argv) 
             ^
src/cpp/debug-errori-warning.cpp:29:27: 
    warning: unused parameter 'argv' [-Wunused-parameter]
int main(int argc, char** argv) 
                          ^
src/cpp/debug-errori-warning.cpp:19:11: 
    warning: private field '_area' is not used 
        [-Wunused-private-field]
    float _area;
          ^
4 warnings generated.
```

Molti programmatori ignorano i *warning*, pensano che se il programma può essere compilato non ci sia nient'altro di cui preoccuparsi.
Tu non fare questo errore: nessun avviso deve essere ignorato.

<hr id="errori-esecuzione">

Solo un programma formalmente ineccepibile può dare luogo a **errori di esecuzione**.
Se non fosse formalmente ineccepibile, infatti, non sarebbe stato compilato e non potrebbe essere eseguito.  
Gli errori di esecuzione sono tanto più pericolosi quanto più i loro
effetti sono lievi.
Un errore che causi il blocco del sistema sarà certamente rilevato e corretto; al contrario, un leggero errore di calcolo potrebbe passare inosservato e
quindi causare grandi problemi.  
Se dimentichi l'operatore di incremento all'interno di un ciclo `while` produrrai un ciclo infinito, che certamente attirerà la tua attenzione:

```
{% include_relative src/pianeti-while-errore-1.cpp %}
```

```
> g++ src/cpp/pianeti-while-errore-1.cpp \
      src/cpp/pianeti-2.0.cpp \
   -o src/out/esempio
> src/out/esempio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
Mercurio
...
```

Se invece incrementi la variabile nel modo sbagliato:

```
{% include_relative src/pianeti-while-errore-2.cpp %}
```
causerai un errore che, in questo caso, è evidente, perché all'elenco manca Mercurio, ma che in un programma più complesso potrebbe essere difficile da individuare:

```
> g++ src/cpp/pianeti-while-errore-2.cpp \
      src/cpp/pianeti-2.0.cpp \
   -o src/out/esempio
> src/out/esempio
Venere
Terra
Marte
Giove
Saturno
Urano
Nettuno
Plutone
```

Gli errori di esecuzione possono essere di due tipi: quelli che si
manifestano in maniera deterministica e quelli che si manifestano in
maniera casuale.
L'errore nell'elenco dei pianeti si manifesterà a ogni esecuzione del programma e sarà quindi (relativamente) facile da individuare.
Al contrario, questo codice produrrà un errore solo in determinate condizioni:

```
{% include_relative src/debug-errore-stocastico.cpp %}
```

La funzione `banner_testo` inserisce il *tag* HTML di un banner all'interno del testo di una pagina Web.
I banner devono essere posizionati dopo un punto fermo, a distanza di almeno `N_CHAR_MIN` caratteri l'uno dall'altro.  
Questo codice funziona correttamente con alcuni tipi di testo:

<blockquote class="output">
Essere un ossessivo-compulsivo con una leggera tendenza alla paranoia, se ti guadagni da vivere facendo l’esperto di sicurezza, è un bene; le medesime peculiarità caratteriali, al contrario, sono decisamente un male quando alle 21:55 la tua donna di servizio ti scrive: "Ho fatto un molecolare e sono risultata positiva.
<div id="banner-1"></div>
Non potrai farti un tampone prima delle 8:00 dell’indomani quindi sai che ti aspettano almeno dieci ore di panico controllato; qualcuna di meno, se riesci ad addormentarti.
Cerchi di distrarti guardando la televisione, ma l’ennesimo thriller con Jason Statham, intervallato da pubblicità di ansiolitici (un conflitto di interessi che ti riprometti di studiare con più attenzione, se sopravvivi), non fa che aumentare la tua agitazione; così, spegni il televisore, ti prepari una tisana relax, leggi un po’ e poi cerchi di dormire.
<div id="banner-2"></div>
Appena chiudi gli occhi, però, il tuo cervello comincia a fare ciò che sa fare meglio, ovvero analizzare ciclicamente tutte le possibili conseguenze di un determinato evento; solo che stavolta, quello che potrebbe essere infetto non è un computer, sei tu.
Notizia buona: non hai sintomi. Notizia cattiva: hai visto la tua donna di servizio solo quattro giorni prima, quindi i giochi sono ancora aperti.
<div id="banner-3"></div>
 </blockquote>

Il codice della funzione, però, è troppo ottimistico e delle piccole variazioni dell'input, come l'aggiunta di punti di sospensione o di una URL, *potrebbero* causare degli errori:

<blockquote class="output">
Essere un ossessivo-compulsivo con una leggera tendenza alla paranoia, se ti guadagni da vivere facendo l’esperto di sicurezza, è un bene; le medesime peculiarità caratteriali, al contrario, sono decisamente un male quando alle 21:55 la tua donna di servizio ti scrive: "Ho fatto un molecolare e sono risultata positiva".
<div id="banner-1"></div>
..
Non potrai farti un tampone prima delle 8:00 dell’indomani quindi sai che ti aspettano almeno dieci ore di panico controllato. Qualcuna di meno, se riesci ad addormentarti.
Cerchi di distrarti guardando la televisione, ma l’ennesimo thriller con Jason Statham, intervallato da pubblicità di ansiolitici (un conflitto di interessi che ti riprometti di studiare con più attenzione, se sopravvivi), non fa che aumentare la tua agitazione; così, spegni il televisore, ti prepari una tisana relax, <a href="http://cplusplus.
<div id="banner-2"></div>
org">leggi un po’</a> e poi cerchi di dormire.
</blockquote>

Un errore come questo, che dipende dai dati in input, può aspettare anni, prima di venire alla luce. 
Nel frattempo, il codice sarà stato distribuito agli utenti e chi lo ha scritto ne avrà perso memoria o potrebbe addirittura aver cambiato lavoro.  
La correzione della funzione, se fatta per tempo, richiederebbe solo l'aggiunta di una condizione all'istruzione `if`, per verificare che il punto si trovi prima di un a capo:

```
if(c == PUNTO 
&& letti >= N_CHAR_MIN 
&& n_banner <= N_BANNER_MAX
&& testo.peek() == A_CAPO) { 
    cout << endl 
         << "<div id=\"banner-" << n_banner << "\">"
         << "</div>" 
         << endl;
    n_banner++;
    letti = 0;
}
```

La stessa correzione, fatta dopo che il programma sia andato in esercizio, potrebbe richiedere giorni, se non settimane, perché dovrà essere ripetuto tutto il processo di rilascio del sistema:

- debug
- correzione
- test funzionale
- test di carico
- test di sicurezza
- collaudo
- distribuzione

<!--

la fase di debug è quella più complessa, perché si deve trovare chi la faccia e tirare su un ambiente di test

v. Orologiaio, pos. 3836 

Il cambiamento inizia quando si intraprende un nuovo sentiero , anche se questo sentiero non è che una traccia lasciata da una capra assetata che ha trovato una sorgente .
M. Deen - Per antiche strade

Se non lo si è fatto finora, spiegare che gli esempii del testo sono studiati per essere progressivamente migliorati, per dimostrare come la scrittura di codice sia un'attività in continua evoluzione.

riprendere, se utile, gli esempii del ciclo for per illustrare i diversi tipi di errore che ne possono derivare

-->
