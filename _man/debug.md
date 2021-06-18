---
status:     bozza
layout:     manuale
class:      capitolo
no-index:   true
title:      Il debug
permalink:  /man/debug
quote:      "Cento Mondi di peccato sono dissipati dalla luce di un solo ticket"
---

Il debug potrà non essere il senso della vita, come recita apodittico il tuo libro, ma è indubbiamente l'aspetto più importante della programmazione.  

Nella tua vita di programmatore potrai non utilizzare mai una classe *functor* o ridefinire l'operatore `->`, ma sicuramente farai degli errori e li dovrai correggere.
Malgrado ciò, i manuali di programmazione non parlano mai del *debug*.
Si sono scritte migliaia di pagine sui diversi linguaggi di programmazione; non c'è primavera che non veda fiorire un nuovo paradigma di programmazione &mdash; strutturata, *object-oriented*, *agile*, *fuzzy* &mdash; eppure, nessuno si è mai preoccupato di formalizzare il processo di correzione del codice.
O, se lo ha fatto, nessuno se n'è accorto.  
Trascurare il debug è come affermare che non si faranno mai errori.
Non importa quanto sia efficiente il linguaggio di programmazione; non importa quanto sia astuto e vigile il compilatore; non importa nemmeno quanto sia bravo il programmatore: o prima o poi, la stanchezza o un evento esterno permetteranno a un errore di intrufolarsi nel codice.
Un puntatore utilizzato impropriamente, un ciclo in più o in meno in un'istruzione `for` o una virgola dimenticata fra i parametri di una `printf`: qualunque cosa sia, se il compilatore non sarà in grado di riconoscerla, finirà nel programma è lì resterà in attesa di produrre i suoi effetti dannosi.
Magari per anni il programma funzionerà a meraviglia, ma poi, un bel giorno, qualcosa non andrà come sarebbe dovuto andare e a quel punto bisognerà analizzare il codice per trovare l'errore.  
Fare degli errori è inevitabile, ed è importante sapere come porvi rimedio.
Ancora più importante, però, è sapersi accorgere degli errori.
Così come <a href="/man/ereditarieta#ikebarba" class="xref">l'Ikebarba inizia nel negozio</a>, il debug comincia nel momento in cui si scrive il codice.
Il modo migliore per evitare che il codice contenga degli errori è scrivere del buon codice.  
La decadenza del software è iniziata quando le stampanti laser hanno soppiantato le vecchie stampanti ad aghi.
Il codice non si può leggere su un foglio A4: a meno che non sia un programma banale, non c'entrerà né in altezza né in larghezza.
Il modulo in continuo di una stampante ad aghi a 136 colonne, al contrario, ti permette di stampare tutto il tuo codice e di rileggerlo con calma; correggerlo, se necessario e migliorarlo se possibile.
È così che si facevano, le revisioni di codice, quando ancora c'era il tempo di fare le revisioni del codice.

<hr id="tipi-errore">

<!--
Tecnicamente, gli errori possono essere di due tipi: gli errori che si manifestano durante la fase di compilazione e gli errori che si manifestano durante l'esecuzione del programma.

Errori di compilazione

Quando si compila del codice non corretto, si possono ottenere o degli errori o degli avvisi, o *warning*.
Gli errori sono causati da costrutti incorretti, che bloccano la compilazione e impediscono la creazione del programma.
I *warning*, al contrario, sono causati da anomalie che non bloccano la compilazione e consentono la generazione dell'eseguibile.
In questo, i *warning* sono più dannosi degli errori, perché possono essere degli errori potenziali, ma possono venir trascurati.   
Se compilassi questo codice, otterresti un avviso perché la variabile *buffer* non è utilizzata:

int main() {
    char *str = "byte occupati inutilmente: ";
    double buffer[8000];
    cout << str << (sizeof(double)*8000) << endl;
    return 0;
}

Il fatto che *buffer* non sia utilizzata, in sé, non causa alcun
problema al codice, ma oltre ad essere una sciatteria, causa un'inutile
occupazione della memoria e può dare luogo a errori, quindi l'avviso non
deve essere ignorato.

Nessun avviso deve essere ignorato.



<!--

v. Orologiaio, pos. 3836 


## Errori di esecuzione

Solo un programma formalmente ineccepibile può dare luogo ad errori di
esecuzione. Se non fosse formalmente ineccepibile, infatti, non sarebbe
stato compilato e non potrebbe essere eseguito.

Gli errori di esecuzione sono tanto più pericolosi quanto più i loro
effetti sono lievi.

Un errore che causi il blocco del sistema non passerà mai inosservato.

Di contro, un leggero errore di calcolo potrebbe passare inosservato e
quindi causare grandi problemi.

Gli errori di esecuzione possono essere di due tipi: quelli che si
manifestano in maniera deterministica e quelli che si manifestano in
maniera casuale.

-->
<!--

Il cambiamento inizia quando si intraprende un nuovo sentiero , anche se questo sentiero non è che una traccia lasciata da una capra assetata che ha trovato una sorgente .
M. Deen - Per antiche strade

Se non lo si è fatto finora, spiegare che gli esempii del testo sono studiati per essere progressivamente migliorati, per dimostrare come la scrittura di codice sia un'attività in continua evoluzione.

B. Croce -- Breviario di estetica -- Laterza, Bari 1928 -- p.12

Un sistema è una casa che, subito dopo costruita e adornata, ha bisogno (soggetta com'è all'azione corroditrice degli elementi) di un lavorio più o meno energico, ma assiduo, di manutenzione, e che a un certo momento non giova più restaurare e puntellare, e bisogna gettare a terra e ricostruire dalle fondamenta. Ma con siffatta differenza capitale: che, nell'opera del pensiero, la casa perpetuamente nuova e sostenuta perpetuamente dall'antica, la quale, quasi per opera magica, perdura in essa.

riprendere, se utile, gli esempii del ciclo for per illustrare i diversi tipi di errore che ne possono derivare

-->
