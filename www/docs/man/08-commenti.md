commenti
--------

I commenti sono la cosa più importante, quando si programma.

Un commento è un breve brano di testo che descrive in linguaggio comune
il funzionamento o lo scopo del codice seguente.

Pur essendo all'interno del codice, il commento viene ignorato in fase
di compilazione.

È importante commentare bene il proprio codice.

Il buon codice produce programmi che durano nel tempo e, col tempo, si
tende a dimenticare.

Anche se si ha la fortuna di possedere una buona memoria, bisogna
considerare la possibilità che il proprio codice sia utilizzato da un
collega. Non solo non è educato costringerlo ad analizzare ogni singola
riga di codice per capirne il funzionamento, ma è anche improduttivo.

Così come la penuria, anche l'eccesso di commenti è un errore da
evitare.

Il programmatore inesperto non commenta il proprio codice perché pensa
che sia una perdita di tempo. È davvero un atteggiamento poco
responsabile.

Il neofita zelante riempie il proprio codice di commenti, o perché
ritiene che chi lo andrà a leggere sarà meno esperto di lui o perché
vuole in questo modo esaltare le sue poche conoscenze.

Il programmatore esperto commenta solo ciò che non è di per sé evidente
e indica i possibili punti deboli del suo programma in modo che chi si
trova a riutilizzarlo o a correggerlo vi presti la dovuta attenzione.

Il programmatore Perfetto non commenta il suo codice, perché non è
necessario.

Spesso gli opposti coincidono.

È ammissibile che i commenti abbiano una sfumatura umoristica, può
essere utile per scaricare un po' della tensione in chi legge, così come
scambiarsi una battuta mentre si lavora, ma anche in questo non si deve
esagerare.

È buona norma anteporre a ogni funzione un breve commento che ne
illustri il funzionamento, ma se si ha cura di scegliere dei nomi
auto-esplicativi per le funzioni questo può non essere necessario.
Sarebbe un'inutile ridondanza aggiungere un commento se il nome della
funzione basta da solo a chiarirne la ragione e l'uso.

Il C++ prevede due modi distinti per commentare il codice: due caratteri
// affiancati o la sequenza /\* \*/, che il Linguaggio ha mutuato dal
suo predecessore, il C.

Nel primo caso, il compilatore ignora i caratteri dal simbolo fino alla
fine della riga; nel secondo caso, ignora tutto ciò che è compreso fra
le due sequenze di caratteri.

Entrambe le soluzioni hanno dei pro e dei contro che con l\'esperienza
risultano evidenti. Scegliere l\'uno o l\'altro è spesso una questione
di convenienza, altre volte una questione di stile, ma se si capisce la
vera essenza del Linguaggio, è solo una questione di ritmo.

Una volta, il maestro Canaro mostrò ai suoi allievi un brano di codice e
gli chiese di spiegare che cosa facesse:

> /\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

> \#include \<iostream.h\>

> \#define ERR\_NOFILE 1

> int errore( int errore );

> void leggi\_file( char \* nomefile );

> void crea\_matrice(void);

> int inizializza(void);

> void imposta\_probabilita(void);

> void attrattore(void);

> int chiudi(void);

> int main(int argc, char \* argv\[\])

> {

> int esito = 0 ;

> if(argc \< 2) {

> esito = errore(ERR\_NOFILE);

> } else {

> leggi\_file(argv\[1\]);

> crea\_matrice();

> if(inizializza()) {

> const char \* valore = imposta\_probabilita();

> attrattore(valore);

> esito = chiudi();

> }

> }

> return esito ;

> }

> \*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*/

Gli allievi studiarono gli algoritmi e diedero le loro risposte, ma
sbagliarono tutti, perché il codice era compreso fra un /\* e un \*/ e,
di fatto, non faceva nulla.

I commenti sono un po\' come la letteratura: se si scrive troppo poco è
male; se si scrive troppo, dilungandosi in descrizioni inutili, è
altrettanto sbagliato.

Il paragone vale anche all\'inverso: i libri, le opere letterarie, sono
i commenti al codice della vita. Si scrive ciò che si desidera
ricordare.
