---
class:      capitolo
layout:     manuale
og_desc:    "Cosa disse Brian Kernigan - Un computer è come una nave - Come tornare al tuo albergo in Cina - I paradossi sono la crittografia di Dio - PacMan non paga le tasse."
og_img:     "/assets/img/og-img/linguaggi-di-programmazione.jpg"
permalink:  /man/linguaggi-di-programmazione
quote:      "Dio non programma in Assembler con l'Universo"
status:     pubblicato
title:      I linguaggi di programmazione
---

Brian Kernigan, disse:

> {{ site.data.citazioni.kernigan }}


Il maestro Canaro sosteneva che anche scrivere il manuale di un linguaggio di programmazione è un buon sistema per impararlo.  

---

I linguaggi di programmazione servono a chiedere al computer di fare determinate operazioni.
Perché il computer possa ubbidirci, deve "capire" che tipo di entità deve gestire e che tipo di operazioni deve compiere su di esse.
Per esempio, se chiedessimo al computer di raddoppiarci lo stipendio, il computer dovrebbe sapere almeno a quanto ammonta il nostro stipendio e come funziona una moltiplicazione per due.

```
long raddoppia(long stipendio)
{
    return stipendio * 2;
}
```

Siccome l'unica cosa che il computer conosce sono delle sequenze di 1 e di 0  – siano esse su un disco, in memoria o sulla porta di comunicazione della tastiera o del video, – dobbiamo trovare il modo di "spiegargli" i concetti di *stipendio* e *moltiplicazione* in forma binaria.
I linguaggi di programmazione fanno precisamente questo: traducono le nostre richieste in un linguaggio che il computer può comprendere.

---

Il linguaggi di programmazione possono essere di *alto livello* o di *basso livello*.
I linguaggi di alto livello, come il *C* o il *C++* hanno dei costrutti simili al linguaggio naturale e non sono legati a una determinata architettura hardware.
I linguaggi di basso livello, come l'*assembly* hanno dei costrutti simili al codice nativo della macchina e sono, per questo motivo, legati a uno specifico tipo di hardware.   
La funzione *raddoppia*, che abbiamo visto prima, tradotta in linguaggio *assembly*, diventa:

```
raddoppia(long):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        add     rax, rax
        pop     rbp
        ret
```

I programmi scritti con linguaggi di alto livello, come vedi, sono più facili da scrivere e da correggere, ma sono più lenti da eseguire perché il codice deve essere “tradotto” in una forma comprensibile alla CPU.
I programmi scritti con linguaggi di basso livello sono più complessi da scrivere o da correggere, ma sono molto più veloci da eseguire perché contengono solo le istruzioni strettamente necessarie a svolgere il compito desiderato. 

---

Un computer è come una nave. 
L'hardware è in basso, come la sala macchine e la CPU è il capo-smacchinista: non vede il mare, non vede il cielo, non sa nemmeno se la nave stia andando a Nord oppure a Sud; riceve le sue istruzioni dall'interfono e si interessa solo solo della velocità e dei consumi.
Il sistema operativo è l'equipaggio: è in una posizione intermedia, né in basso né in alto e si prende cura della nave e del carico; può parlare con il Comandante e con il capo macchinista, ma non parla mai con gli armatori.
L'interfaccia utente, invece, è il ponte di comando: è il punto più alto della nave, da cui si può vedere tutto; è in contatto diretto con gli armatori, da cui riceve delle direttive su ciò che deve o non deve fare e con l'equipaggio, che lo informa sullo stato della nave.  
Ciascun livello del computer ha il suo linguaggio.
La CPU di questo computer “ragiona” in quello che si chiama: *linguaggio macchina*, ovvero una lunga serie di valori decimali che indicano sia le operazioni da compiere che le grandezze coinvolte.
Il sistema operativo è scritto in C, perché è il linguaggio che si adatta meglio a gestire un computer.
L'interfaccia utente, infine, sfrutta dei linguaggi a oggetti come il C++ per creare gli elementi grafici che le consentono di interagire con l'utente.  
I linguaggi e i costrutti che si applicano a un livello non funzionano, se si applicano agli altri livelli, perché ciascun livello concepisce e gestisce gli elementi di un programma in maniera diversa.
L'interfaccia utente conosce molte caratteristiche del programmatore: vede il suo viso nella Webcam, ascolta la sua voce nel microfono, talvolta legge le sue impronte digitali sullo scanner.
Il sistema operativo non lo può vedere o sentire, ma conosce i suoi dati anagrafici e sa tutto quello che lui scrive ai suoi amici.
La CPU non sa nulla di lui: gestisce i suoi dati, ma non sa cosa siano.
Può elaborare la sequenza di byte:

```
01000011 
01100001 
01101110 
01100001 
01110010 
01101111
```

ma non sa che è il nome: *Canaro*.
In effetti, non sa nemmeno cosa sia, la parola: *nome*.
Per lui è solo la sequenza di byte:

```
01001110 
01101111 
01101101 
01100101
```

Invertendo questi concetti, una volta il Maestro Canaro disse: 

> {{ site.data.canaro.dio-buono }}

---

Noi percepiamo il mondo reale come un insieme di eventi che coinvolgono una o più entità.
Ciascuna entità è identificabile per le sue caratteristiche fisiche e ha un suo modo particolare di reagire agli stimoli esterni.
Per descrivere le entità, i linguaggi di programmazione hanno i 
<a href="/man/tipi-di-dato" class="xref">tipi di dato</a>; 
per descrivere gli eventi,
<a href="/man/operatori" class="xref">istruzioni e operatori</a>
Un linguaggio di programmazione è tanto più efficace quanto più i suoi tipi di dato e i suoi costrutti sintattici riescono a rappresentare le entità che il programma dovrà gestire.  
Ci sono molti linguaggi di programmazione.
Ciascun linguaggio sa spiegare bene certe cose e meno bene certe altre.
Esistono linguaggi che descrivono bene le transazioni bancarie, ma che sono inadatti a gestire il traffico aereo; altri che funzionano molto bene per creare pagine Web, ma con cui sarebbe masochistico scrivere un sistema operativo. 
Un programmatore che conosce a fondo un certo linguaggio di programmazione può utilizzarlo efficacemente per scrivere qualsiasi programma, ma a quale prezzo?
Se il linguaggio di programmazione è inadatto a descrivere gli eventi che interesseranno il programma, il programmatore dovrà preoccuparsi di piegare o gli eventi o il linguaggio o entrambi per ottenere il risultato atteso.
Scegliendo invece un linguaggio i cui tipi di dato e i cui costrutti siano più affini alla realtà da descrivere, si risparmiano tempo e fatica e si scrive un codice più affidabile.  
I linguaggi di programmazione possono essere di due tipi: *interpretati* o *compilati*.
Posso spiegarti la differenza in questo modo: immagina di essere in Cina e di dover tornare al tuo albergo in taxi.
Se non parli il Cinese, ha due possibilità: o porti con te un interprete che spieghi al tassista dove devi andare o ti fai dare dall'albergo un foglio di carta con l'indirizzo e lo fai vedere al guidatore del taxi.
Entrambe le possibilità hanno lati positivi e negativi.
Se scegli di portarti dietro un interprete avrai dei costi in più, ma sarai libero di andare dove vuoi: in albergo, in un ristorante o in un locale notturno.
Se invece opti per il foglio con l'indirizzo risparmierai i soldi dell'interprete, ma, una volta salito in taxi, potrai solo tornare all'albergo.  
Con i linguaggi di programmazioni avviene la stessa cosa.
Il codice dei linguaggi interpretati viene letto da un programma chiamato: *interprete* che prima traduce le istruzioni nel linguaggio del computer e poi le esegue.
Il codice dei linguaggi compilati, al contrario, viene letto da un programma chiamato *compilatore*, che lo converte in istruzioni comprensibili dal computer, scrive queste istruzioni in un nuovo file, detto: *object-file* e lo passa a un altro programma, chiamato *linker*, che lo trasforma in un file *eseguibile*.   
Anche in questo caso, ciascun metodo ha lati positivi e lati negativi.  
I linguaggi interpretati sono più lenti, perché il passaggio lettura/conversione/esecuzione si ripete ogni volta che il codice viene elaborato; inoltre, richiedono delle risorse di sistema in più da destinare all'interprete.
In compenso, ogni modifica al codice sorgente viene trasmessa immediatamente anche al programma in esecuzione.
I linguaggi compilati sono più rapidi e richiedono meno risorse di sistema perché la compilazione avviene solo una volta, dopo di che il programma può essere eseguito autonomamente, ma se si modifica il codice sorgente, il programma dovrà essere ri-compilato per funzionare correttamente.  
Anche la religione è, da un certo punto di vista, un linguaggio di programmazione, perché consente agli umani di dialogare con Dio.
Il codice, in questo caso, è la preghiera, che i fedeli formulano e inviamo alla Divinità nella speranza che la esegua.
Anche le religioni, come i linguaggi di programmazione, possono essere o compilate o interpretate, a seconda che la comunicazione fra il fedele e Dio sia diretta o mediata da un Ordine sacerdotale.

---

Tutti i linguaggi hanno una sintassi, tutti i linguaggi hanno dei tipi di dato; pochissimi linguaggi hanno anche dei principii.
I principii sono importanti, perché danno robustezza al linguaggio.
Il linguaggio C, da cui è derivato il C++, non ha principii: è solo un modo per descrivere gli eventi all'interno di un computer.  
L'istruzione:

```
char b = 23;
```

è un modo per dire al computer:

1. trova un'area di memoria libera larga 1 byte;
1. assegna l'indirizzo di quell'area alla variabile *b*;
1. inserisci nell'area di memoria il valore *23*.

Immagina che tu sia il C.
Il muro della cucina è la memoria del computer e ciascuna mattonella è un *bit*.
Le prime diciassette mattonelle sono occupate, ma dalla diciottesima alla venticinquesima ci sono otto mattonelle libere, così tu prendi un pennarello e, senza farti vedere dal cuoco, scrivi nelle otto mattonelle libere il corrispondente binario del numero 23:

<table class="memoria">
<tr>
  <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
</tr>
	<tr>
    <td></td>
    <td class="area prima">0</td>
    <td class="area">0</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
</table>  

La variabile *b*, a questo punto, avrà un *indirizzo*, ovvero il numero della prima mattonella in cui hai scritto (18) e un *valore*, ovvero il numero binario contenuto nelle otto mattonelle (23).  
<!-- 
@todo - approfondire i concetti di rvalue, lvalue e le nuove categorie del C++11
-->
Se l'istruzione successiva fosse:

```
char c = b * 2;
```

tutto quello che dovresti fare è di cercare un'altra serie di otto mattonelle libere in cui scrivere il valore della variabile *b* spostato verso sinistra di una mattonella:

<table class="memoria">
<tr>
  <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
</tr>
	<tr>
    <td></td>
    <td class="area prima">0</td>
    <td class="area">0</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td>
    <td class="area prima">0</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">0</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">1</td>
    <td class="area">0</td>
    <td></td><td></td><td></td><td></td><td></td>
  </tr>
</table>  

Ti vedo perplesso, ma ragiona: la moltiplicazione per due, in binario, è l'equivalente della moltiplicazione per dieci nella numerazione decimale.
Se devi moltiplicare un numero decimale per la base del sistema di numerazione &mdash; che è dieci, appunto &mdash;, lo sposti a sinistra di un posto e aggiungi uno zero a destra:

```
    1234 * 10 = 12340
```

Se devi moltiplicare un valore binario per la base del sistema, che in questo caso è due, fai la stessa cosa:

```
00010111 * 00000010 = 00101110
```

Il valore `00101110` equivale a 46, che è il doppio di 23.

--- 

Il C è un linguaggio estremamente efficiente per gestire tutte le entità che puoi trovare in un computer – numeri, stringhe, flussi di dati –, ma la sua forza è allo stesso tempo il suo limite, perché non funziona altrettanto bene se hai a che fare con oggetti più complessi.
Anche la gestione delle stringhe di testo, nel C, è rudimentale: se tu provassi a eseguire la somma di cui parla il Maestro Canaro nel suo diario:

```
{% include_relative src/linguaggi-programmazione-pippopluto.c %}
```

il compilatore C ti avviserebbe che non può sommare due variabili di tipo char.

```
% gcc linguaggi-programmazione-pippopluto.c -o ../out/esempio; 
6.1-pippopluto.c:7:35: 
error: invalid operands to binary expression 
('char *' and 'char *')
    printf("\npippo+pluto=%s\n", a+b);
                                 ~^~
1 error generated.
``````

Il C è un linguaggio che non va oltre l'ambito per cui è stato creato.
È una convenzione.
Se domani smettessimo di utilizzare i computer, il C non esisterebbe più, perché tutti i suoi costrutti sono legati al funzionamento degli apparati informatici.
Al contrario, il C++ e tutti i linguaggi che si basano sul paradigma a oggetti hanno una componente filosofica che trascende l'ambito informatico.
Se domani smettessimo di utilizzare i computer, i costrutti che il C++ ha ereditato dal C non avrebbero più senso, ma i concetti di 
<a href="/man/classi-oggetti" class="xref">classe e di oggetto</a> 
resterebbero ancora validi.  
Molti pensano che avere dei principii sia limitativo, ma non è vero. 
Il C non ha principi e i suoi costrutti sono limitati ai tipi di dato previsti.
Il C++, grazie ai suoi principii, ha una maggior duttilità e può evolversi, adattando i suoi costrutti a qualsiasi contesto.  
Il Maestro Canaro pensava che la Scienza fosse come il C: uno strumento perfetto per descrivere ciò che ci circonda, ma inadatto a descrivere ciò che trascende la nostra conoscenza diretta.
Il problema, secondo lui, era la matematica.
Parafrasando Karl Kraus, diceva che la matematica è una malattia di cui pensa di essere la cura.
Non so se conosci la frase di André Weil: «Dio esiste perché la matematica è coerente; il Diavolo esiste perché non possiamo dimostrarlo.»
È vero il contrario.
I paradossi sono la crittografia di Dio e la matematica è utile non perché quasi sempre è coerente, ma perché, di quando in quando, produce dei paradossi.  
Le filosofie occidentali cercano di sfuggire il paradosso; lo Zen, al contrario, lo cerca incessantemente.
È possibile che sia il paradosso, la chiave per arrivare alla Verità?
O anche: è possibile che non si possa arrivare alla Verità, se non si accetta il paradosso?
Del resto: perché il mondo di Dio, la sua visione delle cose, non dovrebbe essere paradossale, per noi?
Se mostrassimo al personaggio bidimensionale di un gioco per computer il nostro mondo tridimensionale, non lo troverebbe paradossale?
E se spiegassimo a *PacMan* che dobbiamo pagare l'IVA, non lo troverebbe paradossale?  
Un'altra ipotesi è che il paradosso indichi il punto di confine fra il nostro sistema e un sistema di ordine superiore. 
Potrebbe essere, cioè, che nel nostro sistema ci siano degli elementi “di frontiera” che segnano il confine fra il nostro sistema e un altro e che per questa loro ambivalenza non possono essere spiegati compiutamente con gli elementi a nostra disposizione. 
Il Tempo non si può definire senza una tautologia; definire la Verità comporta una ricorsione.. 
È la nostra corda, che è ancora troppo corta, o è piuttosto il pozzo che non ha fondo, almeno in questo Universo?

<hr id="dottrina">

{{ site.data.canaro.arco-meglio }}

<!--
Un codice crittografico che produca un solo risultato può essere più o meno sicuro, ma, una volta de-crittato, non può fare a  meno di rivelare il proprio segreto.
Al contrario, un codice crittografico che possa produrre più di un risultato credibile, è di fatto molto più sicuro perché il decrittatore non potrebbe mai avere la certezza di essere nel giusto.
Se uno stesso brano crittografato potesse produrre le frasi: "Le navi attaccheranno da est" e "Gli aereo attaccheranno da ovest", anche decrittato, avrebbe comunque il pregio di dividere le forze del decrittatore sui due fronti, uno solo dei quali sarà veramente attaccato.
Dio si comporta allo stesso modo: "cifra" le grandi verità con dei paradossi ambivalenti e distrae così, talvolta per millennii, i filosofi.

Un linguaggio, può descrivere sé stesso senza essere tautologico?
Ovvero: i costrutti di un linguaggio, possono descrivere i costrutti del linguaggio senza dire che sono costrutti del linguaggio?
-->
