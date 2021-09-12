---
status:     pubblicato
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

> {{ site.data.canaro.decadenza-software }}

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
Come di ho detto <a href="/man/programmatore#buon-programmatore" class="xref">in una delle nostre prime chiacchierate</a>, il Buon Programmatore non si accontenta della strada più rapida, ma cerca sempre quella più efficiente e sicura, perché sa che scrivere del buon codice costa meno che riparare del codice fatto male.
Il Maestro Canaro, una volta disse:

> {{ site.data.canaro.marinaio }}

Il Buon Programmatore non può farne a meno, perché è nella sua natura; è questa, la differenza fra chi *fa* il programmatore e chi *è* un programmatore.  

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
 </blockquote>

Il codice della funzione `banner_testo`, però, è troppo ottimistico e delle piccole variazioni nel file di input, come l'aggiunta di punti di sospensione o di una URL, *potrebbero* causare degli errori nel posizionamento dei banner:

<blockquote class="output">
Essere un ossessivo-compulsivo con una leggera tendenza alla paranoia, se ti guadagni da vivere facendo l’esperto di sicurezza, è un bene; le medesime peculiarità caratteriali, al contrario, sono decisamente un male quando alle 21:55 la tua donna di servizio ti scrive: "Ho fatto un molecolare e sono risultata positiva".
<div id="banner-1"></div>
..
Non potrai farti un tampone prima delle 8:00 dell’indomani quindi sai che ti aspettano almeno dieci ore di panico controllato. Qualcuna di meno, se riesci ad addormentarti.
Cerchi di distrarti guardando la televisione, ma l’ennesimo thriller con Jason Statham, intervallato da pubblicità di ansiolitici (un conflitto di interessi che ti riprometti di studiare con più attenzione, se sopravvivi), non fa che aumentare la tua agitazione; così, spegni il televisore, ti prepari una tisana relax, <a href="http://chiplusplus.
<div id="banner-2"></div>
org">leggi un po’</a> e poi cerchi di dormire.
</blockquote>

Questo tipo di errori possono aspettare anni, prima di venire alla luce.
Per esempio, un errore nella valutazione di una data in coincidenza con gli anni bisestili potrebbe aspettare quattro anni prima di manifestarsi; nel frattempo, il codice sarà stato distribuito agli utenti e chi lo ha scritto ne avrà perso memoria o potrebbe addirittura aver cambiato lavoro.  
La correzione dell'errore della funzione `banner_testo`, se fatta per tempo, richiederebbe solo l'aggiunta di una condizione all'istruzione `if`, per verificare che il punto si trovi prima di un a capo:

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

La stessa correzione, fatta dopo che il programma è andato in esercizio, potrebbe richiedere giorni, se non settimane, perché dovrà essere ripetuto tutto il processo di rilascio del sistema:

| attività | ore/uomo |
|:--|:-:|
| creazione di un ambiente di test | 8
| debug | 2
| correzione dell'errore | 1
| test funzionale | 4
| test di carico | 8
| test di sicurezza | 8
| collaudo | 4
| rilascio/distribuzione | 1

Al costo di queste attività vanno ovviamente aggiunti i possibili danni derivanti dal mancato funzionamento del sistema, che potrebbero facilmente essere pari a un mese se non a un anno di stipendio del programmatore.  
Devi pensare a tutto questo, quando scrivi codice, perché hai una responsabilità sia nei confronti del tuo datore di lavoro che degli utenti del sistema, che potrebbero essere anche i tuoi amici o i tuoi parenti.  
Se lavori male per la Coca-Cola, puoi sempre pensare: “Chi se ne frega, io bevo Pepsi”; non è etico, ma almeno non è auto-lesionista. 
Se però lavori male per lo Stato, stai peggiorando la tua vita e di tutte le persone che conosci e questo, oltre a non essere etico, è anche stupido. 

---

Gli <b id="errori-analisi">errori di analisi</b> sono una conseguenza dell'Annosa Dicotomia &mdash; e dell'inesperienza dell'analista, ovviamente.  
Come tutti gli esseri senzienti, anche i clienti possono essere vittime dell'Annosa Dicotomia fra ciò che desiderano e ciò di cui realmente hanno bisogno.
Un cliente che espone le sue esigenze è come un bambino che dice alla madre cosa vuole mangiare.
Lo stimolo è reale &mdash; appetito o fame che sia &mdash;, ma il modo in cui lui vorrebbe placarlo non è necessariamente il più corretto; anzi: di solito è un desiderio indotto dal callido servitore dell'Entropia: il Marketing.  
Il cliente ha diritto di comportarsi in questo modo: ciascuno di noi fa la stessa cosa quando entra in un negozio; come analista, però, non devi permettere che i tuoi giudizi siano influenzati dai desiderii del tuo cliente.
In questo, l'Analisi è assimilabile a una disciplina mistica: così come il Buddha dà a ciascuna persona con cui viene in contatto ciò di cui ha bisogno,
<!-- @todo: trovare citazione da Buddismo Tientai --> tu devi annullare te stesso e *diventare* l'altro, pensare come lui, sentire le sue necessità. 
Da quello che dice e da come lo dice, devi riuscire a distinguere i suoi bisogni dai suoi desiderii, evitando che l'ottenimento di questi ultimi intralci il buon successo del progetto.  
Ovviamente, dovrai anche evitare che i *tuoi* desiderii intralcino o rallentino il progetto. 
Così come influenza le opinioni del tuo cliente, il Marketing può influire su di te, spingendoti a scegliere una tecnologia di moda, ma inadatta allo scòpo che devi raggiungere.
Fà attenzione che ciò non accada.
Sorveglia costantemente le tue scelte; così come il Buon Programmatore, pensa sempre su più livelli e confrontati con altri colleghi o con il tuo superiore per essere certo di aver fatto le scelte giuste.
Non vergognarti dei tuoi errori: sono i mattoni su cui edificherai la tua esperienza.  
Sii anche preparato a dover fare degli errori.
O prima o poi, capiterà che un cliente ti chieda di fare una scelta che tu ritieni sbagliata.
Quando ciò accadrà, dovrai per prima cosa cercare di convincerlo dell'errore, spiegandogli perché la sua richiesta non sia corretta.
Se non ci riesci, ripeti la tua opposizione, perché sia chiaro che la tua non è un'ipotesi, ma una certezza, però non insistere oltre: sia perché questo potrebbe creare degli attriti con il tuo interlocutore, sia perché alla lunga potresti scoprire che è lui ad avere ragione.    
Se non riuscirai a convincere il cliente di un suo errore, dovrai portare a termine ciò che ti chiede, ma al contempo dovrai fare in modo che le conseguenze di quella scelta non possano essere attribuite a te in futuro.
Dato che le conseguenze nefaste di un errore architetturale potrebbero manifestarsi dopo mesi o anche anni dalla fase di analisi, non limitarti a *dire* al cliente che si sbaglia, ma scrivilo, in modo che resti traccia della tua opposizione.  
Il tuo peggior nemico, in questi casi, sarà il tuo orgoglio. 
Una volta, il Maestro Canaro mi disse:

> {{ site.data.canaro.ragione }}

---

Parafrasando Iacopone da Todi, un programma per il debug può aiutarti a identificare il punto del tuo codice che genera un errore, ma devi prima capire quale sia la funzione da esaminare, perché fare il debug di tutto il codice di un programma, nei casi in cui questo sia possibile, sarebbe lungo ed estremamente frustrante.  
Il modo in cui è stato scritto il codice lo renderà più o meno facile da verificare.
Immagina che il problema sia la variabile `x`: se tutto il tuo codice ha la possibilità di modificarne il valore, potresti dover esaminare ogni singola funzione per verificare che non ne faccia un uso improprio. 
Al contrario, se la variabile `x` può essere modificata solo alcuni punti del codice, la tua sarà una ricerca più mirata e veloce. 
È per questo motivo, che <a href="/man/istruzioni-iterative#isolamento-funzionale" class="xref">nella lezione sulle funzioni iterative</a> abbiamo diviso l'elaborazione dei dati dalla gestione dell'interfaccia utente: perché in questo modo, a seconda del tipo di errore che dovesse presentarsi &mdash; di calcolo o di output &mdash; sapremo quale funzione andare a guardare.  
Alcune caratteristiche del C++, come la <a href="/man/note.html#tipizzazione" class="xref">tipizzazione forte</a> e l'<a href="/man/note.html#incapsulamento" class="xref">incapsulamento</a> potranno esserti di aiuto in questo senso, ma non sempre saranno sufficienti a identificare il punto esatto in cui il tuo codice fa qualcosa di errato.
In questi casi, dovrai procedere per tentativi, scomponendo il tuo programma in parti sempre più piccole, in modo da ridurre il numero di righe di codice da verificare.
Un modo rapido per farlo è di mettere a commento tutte le chiamate nella funzione `main` ripristinandole poi a una a una, fino a che non individuerai quella in cui è contenuto l'errore:

```
int main(int argc, char** argv)
{    
    ifstream testo;        
        
    verifica_parametri(argc, argv);
    apri_file(testo, argv[2]);            
/*
    elabora_file(testo);
    chiudi_file(testo);
*/    
    return 0;
}
```

Se la *funzione che non funziona* è troppo complessa per farne un debug diretto, ripeterai il processo, mettendo a commento le sue chiamate fino a che la quantità di codice da esaminare sarà ragionevolmente poca.  
Un altro modo in cui puoi semplificare la ricerca degli errori nel codice è l'aggiunta di messaggi che ti permettano di sapere quale operazione sta compiendo il programma:

```
int apri_file(ifstream& testo, const char* path)
{
#ifdef __LOG__    
    log(LOG_DEBUG, 2, "Apro il file: ",  path);
#endif

    testo.open(path);
    return ERR_NONE;
} 
```

La funzione `log` è quella che abbiamo visto nella <a href="/man/funzioni.html#parametri-variabili" class="xref">lezione sulle funzioni con parametri variabili</a> e ci permette di conoscere il nome del file che viene aperto durante l'esecuzione del programma.  
Queste funzioni di tracciatura sono utili nella fase di debug, ma rallentano l'esecuzione del programma perché richiedono l'accesso a un dispositivo esterno, sia esso lo schermo del computer o un file sul disco rigido.
Per questo motivo, è bene avere la possibilità di disabilitarle nella versione definitiva del programma.
In questo caso, l'abbiamo fatto inserendo la chiamata in una direttiva `ifdef` del precompilatore, in modo che venga inserita nel codice solo se è definita la costante `__LOG__`.
Dato che si tratta di una costante che non viene utilizzata dal codice, ma che serve solo per modificare il modo in cui è compilato il programma, possiamo definire `__LOG__` direttamente nella linea di comando del compilatore:

```
> g++ sorgente.cpp -D __LOG__ -o eseguibile
```

---

Quando l'errore si manifesterà &mdash; di solito pochi minuti prima che tu debba smettere di lavorare per uscire o fare qualcos'altro &mdash; e tu dovrai identificarne la causa, il primo problema che avrai sarà di riuscire a riprodurre le condizioni in cui si manifesta.
Come abbiamo visto poco fa, se l'errore dipende dai dati in input, per identificare il problema, dovrai capire quali sono i dati che lo generano; qualche volta sarà facile, ma in altri casi potrà rivelarsi estremamente complesso.  
Diversi anni or sono, il Maestro Canaro dovette registrarsi su un sito Web che gli chiese anche la sua data di nascita &mdash; che, come sai, fu il 29 Febbraio del 1964        .
<!-- Si trattava di Paypal e questo non è il solo errore che ho rilevato -->
La maschera di inserimento nuovo utente non gli diede problemi, ma la maschera di modifica dati, evidentemente scritta da un programmatore meno esperto, non gli permise di aggiornarli perché, a suo dire, la data di nascita era sbagliata.
Ciò vuol dire che il sistema utilizzava due funzioni distinte per il controllo della data di nascita, una nella funzione di inserimento e un'altra nella funzione di modifica, e che almeno la funzione utilizzata in modifica non era una funzione standard, ma codice scritto *ad-hoc*.  
Entrambe queste scelte sono errori: a una determinata azione sui dati deve corrispondere una singola funzione.
Fare la stessa operazione con parti di codice distinte è sbagliato; sia perché aumenta la probabilità di commettere degli errori, sia perché rallenta i tempi di identificazione dell'errore in fase di debug.
È sbagliato anche riscrivere delle funzioni che già esistono: D. J. Bernstein lo fece, con le funzioni di I/O di <a href="http://cr.yp.to/djb.html" target="qmail">qmail</a>, ma la sua fu una precisa scelta architetturale perché voleve delle funzioni che fossero migliori e più sicure delle funzioni della libreria standard.  
<!--- e comunque, fare l'analisi del codice di qmail è un delirio.. -->
A questi due errori di programmazione &mdash; inammissibili, in un sito che gestisca transazioni economiche &mdash; si aggiunge una profonda sciatteria della fase di debug del codice, perché la corretta gestione dei casi particolari, come gli anni bisestili, va sempre verificata.
Quando verifichi il funzionamento di un programma, non puoi limitarti a controllare che faccia ciò che deve fare, ma devi anche assicurarti che non faccia ciò che non deve fare. 
In particolare, devi verificare che si comporti correttamente se:

- gli fornisci i dati di input corretti;
- non gli fornisci alcun dato;
- gli fornisci dati errati;
- gli fornisci dati in eccesso.

Quindi, se l'input è una data, dovrai verificare che il tuo sistema gestisca correttamente sia il valore `29-02-1964` che il valore `29-02-1965`; se l'input è una stringa di testo, dovrai accertarti che il sistema gestisca correttamente anche il caso in cui riceva più caratteri del previsto e che elimini eventuali caratteri di spazio all'inizio o alla fine del testo, a meno che questo non sia un requisito funzionale. 

---

In questo programma, una piccola cosa non è stata fatta come si dovrebbe e ne è derivato un errore:

```
{% include_relative src/debug-gestione-errori.cpp %}
```

In ossequio a quanto abbiamo detto poco fa, per verificare il funzionamento di  questo programma dovremo fare almeno quattro prove:

```
# dati corretti
src/out/esempio src/cpp/debug-testo-1.txt 

# nessun dato
src/out/esempio 

# dati errati
src/out/esempio src/cpp/file-inesistente 

# dati in eccesso
src/out/esempio src/cpp/debug-testo-1.txt abcdefghilmenopqrstuvz  
```

Dobbiamo poi verificare che tutte le condizioni di errore siano gestite correttamente.
Nel nostro caso, gli errori previsti sono:

```
#define ERR_FILE_NONE   -10
#define ERR_FILE_OPEN   -20
#define ERR_FILE_READ   -30
```

I primi due errori sono verificati dalle prove standard; il terzo caso lo possiamo verificare passando al programma un file vuoto:

```
src/out/esempio src/cpp/debug-vuoto.txt 
```

Sfortunatamente, però, se compili ed esegui questo codice con i dati corretti, ottieni un errore, anche se il file esiste:

```
> g++ src/cpp/debug-gestione-errori.cpp -o src/out/esempio
> src/out/esempio src/cpp/debug-testo-1.txt               
-20: Impossibile aprire il file di input
> ls src/cpp/debug-testo-1.txt 
src/cpp/debug-testo-1.txt
```

Se ri-compili il programma definendo la macro `__LOG__` per verificare quale sia il file che il programma sta aprendo:

```
#ifdef __LOG__    
    log(LOG_DEBUG, 2, "Apro il file: ",  path);
#endif
```

quando esegui i programma, ottieni un nuovo errore:

```
> g++ src/cpp/debug-gestione-errori.cpp -D __LOG__ -o src/out/esempio 
> src/out/esempio src/cpp/debug-testo-1.txt                           
[DEBUG] Apro il file: zsh: segmentation fault  src/out/esempio src/cpp/debug-testo-1.txt
```

Questo non è il comportamento atteso dalla funzione, ma ci permette comunque di capire quale possa essere il problema.
L'errore: `segmentation fault` vuol dire che il programma sta cercando di accedere a un'area di memoria che non gli appartiene.
L'area di memoria in questione è quella associata al parametro `path`, che a sua volta è stato inizializzato con il valore della variabile `argv[2]`:

```
esito = apri_file(testo, argv[2]);
```

Il *bug* è l'indice `2` nell'array `argv`.
Come certamente avrai notato, il codice di questo programma è una rielaborazione del codice della <a href="/man/stream.html" class="xref">lezione sugli stream</a>, che doveva gestire tre parametri da riga di comando.
Stavolta, però, la stringa di chiamata del programma ha solo due valori: il path del programma e il nome del file di input:

```
> src/out/esempio src/cpp/debug-testo-1.txt
```

Riutilizzare il codice è una cosa buona; scordarsi di modificare il valore dell'indice dell'array `argv` è una cosa sbagliata, perché l'indirizzo di memoria puntato da `argv[2]`, adesso, non appartiene al programma: non possiamo utilizzarlo come path per una funzione `open` e non possiamo stamparlo a video.  
Se correggiamo l'indice, il programma gestisce correttamente tutte le condizioni d'uso:

```
> g++ src/cpp/debug-gestione-errori.cpp \
    -D __LOG__ \
    -o src/out/esempio
> src/out/esempio
-10: Definire un file di input

> src/out/esempio src/cpp/file-inesistente
[DEBUG] Apro il file: src/cpp/file-inesistente
-20: Impossibile aprire il file di input

> src/out/esempio src/cpp/debug-vuoto.txt
[DEBUG] Apro il file: src/cpp/debug-vuoto.txt
-30: Impossibile leggere il file di input

> src/out/esempio src/cpp/debug-testo-1.txt
[DEBUG] Apro il file: src/cpp/debug-testo-1.txt
Essere un ossessivo-compulsivo con una leggera tendenza ...
```

Questo errore di distrazione è stato facilitato dall'utilizzo di una costante numerica per la definizione dell'indice dell'array.
Scrivere direttamente un numero o una stringa nel codice è sicuramente più rapido e allettante che definire delle costanti per il precompilatore:

```
#define PARAM_PATH 1
...
esito = apri_file(testo, argv[PARAM_PATH]);
```

ma, sul lungo periodo, è controproducente perché rende il codice più complesso da leggere e da modificare.  
*Più complesso da leggere* perché le costanti aiutano a capire cosa faccia il codice. 
Se leggi l'istruzione:  

```
return (argc < 2) ? ERR_FILE_NONE : ERR_NONE;
```

puoi capire cosa faccia anche se non conosci il codice.
Se invece leggi la stessa istruzione, ma senza le costanti:

```
return (argc < 2) ? -10 : 0;
```

per capire cosa faccia dovrai andare a leggere la documentazione del programma, posto che ce ne sia una.  
*Più complesso da modificare* perché l'utilizzo di costanti al posto di valori *hard-coded* permette di cambiare il valore di una costante agendo in un solo punto:

```
#define ERR_NONE  1 
```

Se non avessimo usato una costante, per ottenere lo stesso risultato avremmo dovuto modificare tre istruzioni distinte:

```
return (argc < 2) ? ERR_FILE_NONE : ERR_NONE;

...

return ERR_NONE;

...

int esito = ERR_NONE;
```

In un programma più complesso del nostro esempio, le modifiche sarebbero state sicuramente di più e più difficili da identificare; inoltre, se ce ne fossimo dimenticata una (probabile), avremmo introdotto un errore nel sistema.  
Le costanti *hard-coded* possono essere utilizzate solo nella prima fase dello sviluppo del programma, quando non sei ancora sicuro che la strada che hai scelto sia quella giusta. 
In questa fase è ammissibile che tu faccia delle prove inserendo dei valori direttamente nel codice, ma quando l'algoritmo sarà ragionevolmente stabile, dovrai convertire tutti i valori in costanti.

<hr id="dottrina">

> {{ site.data.citazioni.croce.testo }}<a href="/man/note#croce" class="nota"></a>

O prima o poi, la tua vita andrà in errore, come il software.  
Non importa quanto tu sia stato prudente o quale sia il tuo *Karma*: a un certo punto la terra sotto i tuoi piedi comincerà a franare e tu cadrai giù, lungo la montagna che stavi scalando, ritrovandoti al punto di partenza. 
Quello che farai in quel momento deciderà del resto della tua vita e ti farà capire che tipo di uomo sei &mdash; o che donna, visto che queste cose non succedono solo ai maschietti.  
Comincia a prepararti da adesso a quel momento, perché, quando avverrà (*quando*, non: *se*), probabilmente sarai solo e prendere delle decisioni sarà molto difficile perché avrai perso ogni fiducia in te stesso.
Se ti rompi una gamba, o un braccio, il tuo cervello ti può dire se stanno guarendo o peggiorando, ma se batti la testa non è facile capire come stai, perché l'organo in esame e l'organo esaminatore coincidono.
<!-- @todo - decidere se aggiungere aneddoto su Maestro Canaro e solitario -->
Allo stesso modo, se non ti fidi di te stesso, è difficile capire se le scelte che fai sono corrette. 
La paura o la prudenza potrebbero spingerti a non fare la scelta giusta, quindi, per prima cosa, dovrai fare il *debug* della tua vita per capire se e in quale misura devi biasimarti per ciò che è avvenuto; fatto ciò, dovrai identificare i tuoi errori e trovare un modo per non ripeterli.  
L'approccio più comune è di guardarsi indietro e cercare di capire quali siano state le proprie colpe, considerando queste degli eventi isolati in un'esistenza fatta prevalentemente di scelte corrette. 
Dato però che ciascuno di noi tende &mdash; più o meno inconsciamente &mdash;, a cercare cause esogene alle sue sventure inventandosi complotti o trasferendo le proprie responsabilità a terzi, la cosa migliore, in questi casi, è di adottare l'atteggiamento opposto e partire dal presupposto che *tutto* ciò che è successo di male nella tua vita sia una tua colpa, per poi individuare i casi in cui ciò che è successo, in effetti, non è dipeso da te.
Questo approccio *bottom-down*<a href="/man/note#bottom-down" class="nota"></a> ha due pregi: il primo  è che, analizzando gli eventi passati potresti scoprire che alcune colpe che ti attribuivi non erano reali; il secondo è che sarà più difficile mentire a te stesso.
Ciascuno di noi ha una parte di responsabilità in ciò che gli succede, anche negli eventi che non genera direttamente.
Assumersi a priori la colpa di tutto il male che ci è successo rende più difficile mentirci e ci permette di identificare tutte le nostre colpe, per piccole che siano.  
Attenzione, però: non devi pensare alle tue colpe come se fossi un inquisitore del tredicesimo Secolo, ma come se fossero dei *bug* nel programma della tua vita. 
Qualcuna genererà degli errori, altre solo dei *warning* e il tuo dovere è quello di identificarne il più possibile, per poi cercare di correggerle per migliorare il funzionamento del sistema.

> {{ site.data.citazioni.deen.testo }}<a href="/man/note#deen" class="nota"></a>

Contrariamente a quello che avviene con il software, non sempre è possibile correggere i *bug* della nostra esistenza.
Si può modificare un aspetto deteriore del nostro carattere, ma non è detto che sia possibile rimediare ai danni che questo ha causato a noi o a terzi.
Per fare un paragone con il debug del software, i difetti caratteriali sono errori di compilazione, mentre gli effetti dei nostri sbagli sono errori di esecuzione; i primi li possiamo correggere, gli errori di esecuzione, no: ormai è andata. 
Quello che possiamo e che dobbiamo fare, però, è di <a href="/man/istruzioni-condizionali#pentimento" class="xref">pentircene sinceramente</a>, ovvero riconoscerli come errori, in modo da evitare di ripeterli nei prossimi cicli di esistenza.  
Anche se non possiamo cancellare gli effetti di un nostro errore, possiamo comunque chiedere perdòno a coloro i quali abbiamo arrecato danno.
Non basterà chiedere scusa: si chiede scusa quando ciò che hai fatto non dipende da te, come quando qualcuno di urta e tu versi il tuo vino sul vestito del vicino; se invece il vino glielo hai tirato addosso intenzionalmente, dovrai chiedere *perdòno*, cercare per quanto possibile di riparare all'errore fatto e non commetterlo mai più, né con lui (o lei) né con altri.  
Non sottovalutare il potere terapeutico del perdono, anche se ci saranno dei casi in cui non lo otterrai.
Se è vero che non si può cambiare il passato per qualcuno che abbiamo ferito, è altrettanto vero che si può provare a compensare il danno fatto rendendogli migliore il presente o il futuro. 
Le persone a cui facciamo del male sono spesso quelle a cui siamo più legati; far sapere loro che che non li abbiamo dimenticati e che ciò che è successo ci addolora, può servire a ricucire delle ferite; dall'una e dall'altra parte. 

<hr id="come-capire">

Quando ripenserai a ciò che ti è avvenuto in passato, come un buon analista, dovrai cercare di immedesimarti nelle persone con cui hai avuto a che fare, capire le loro ragioni al di là di eventuali rancori o recriminazioni.
Per fare ciò, dovrai tenere a mente alcuni fattori che influenzano il comportamento di tutti noi. 
Il primo, ovviamente, è l'influenza dell'Annosa Dicotomia, che, per mano del suo lacché il Marketing, spinge le persone a soddisfare i proprii desiderii invece che i proprii bisogni, creando degli schemi di valori fallaci e spingendoli a dimenticare che esistono per tutti la vecchiaia e la morte.   
Il secondo fattore da considerare è la natura umana; ricorda:

> {{ site.data.canaro.malizia }}

Per derimere le questioni relative ai rapporti di coppia, invece, l'approccio più sicuro è quello antropologico.
Come diceva il Maestro Canaro:

> {{ site.data.canaro.femminismo }}

Secondo lui, qualsiasi comportamento anomalo nell'ambito di una coppia può essere spiegato tenendo a mente tre principii:

1. le donne sono incubatrici parlanti;<br />
2. gli uomini sono dispenser di sperma;<br />
3. ogni eccesso nasconde un eccesso di natura opposta e pari entità.

Parafrasando quel senza Dio di Dawkins, noi siamo l'*hard-disk* dei nostri geni, la memoria di massa che garantisce loro una persistenza.
Il nostro software può variare, ma il <a href="/man/note#firmware" class="xref">firmware</a> che definisce il nostro comportamento a basso livello è immutato da migliaia di anni e ci spinge a fare ciò per cui siamo stati creati, ovvero riprodurci.  
Né le sovrastrutture culturali che abbiamo inventato, né gli idoli ai cui piedi ci prostriamo e nemmeno l'Annosa Dicotomia possono modificare la nostra ROM.
Ignorare o, peggio, ribellarsi a questo stato di fatto è il primo passo verso la rovina o l'infelicità o entrambe le cose.  

<hr id="fine">

Ecco: questo è tutto. 
Ricorda però: ciò che ti ho insegnato non è un punto di arrivo, ma un punto di partenza.
La fine del cammino che abbiamo percorso insieme coincide con l'inizio del cammino che percorrerai da solo. 
Da questo momento in poi tu hai il dovere di diffondere le idee che ti ho trasmesso e, allo stesso tempo, di metterle costantemente alla prova per emendarle dai molti errori che certamente avrò commesso, così come il Maestro Canaro prima di me.
Scrivi il tuo libro, se lo desideri, ma che non sia un libro stupido; fa' in modo che lo si possa correggere facilmente, se necessario, in modo che ciò che afferma sia sempre il punto più vicino alla verità che tu possa raggiungere, perché l'oggetto dei tuoi sforzi dev'essere sempre la verità, non la tradizione.



<!--


Perfino l'esistenza della pirateria informatica, in ultima analisi, può essere ricondotta al fatto che le donne hanno un imene.
<a href="/opt/penetration" class="xref"></a>

importanza dell'impaginazione dei nomi: OPEN, CLOSE, READ / INPUT, DELETE, UPDATE

-->
