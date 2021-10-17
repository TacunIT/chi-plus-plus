---
status:     pubblicato
layout:     manuale
class:      capitolo
title:      I sistemi di numerazione
permalink:  /man/sistemi-di-numerazione
quote:      "Ci sono 10 tipi di persone: quelli che capiscono la numerazione binaria e quelli che non la capiscono"
---

Per dissuadere i pochi ostinati che sono arrivati a leggere fin qui, voglio parlarti dei sistemi di numerazione.

Secondo antiche leggende, la razza umana sarebbe il frutto di un esperimento di ingegneria genetica operato da alieni esadattili arrivati sulla Terra trecentomila anni prima di Cristo.
Che sia vero o no, immagina di avere intorno a un tavolo uno di questi alieni, uno dei tuoi confratelli e un uomo che abbia solo un dito. 
Se poggiassi una dozzina di uova sul tavolo e chiedessi a ciascuno di loro di numerarle, cosa otterresti?
Il tuo amico, che conta in base alle dieci dita delle sue mani, direbbe che le uova sono pari a una volta tutte le sue dita più due. 
Se esprimessimo questa risposta con potenze del numero delle dita delle mani del tuo confratello, otterremmo che:

<pre>
1x10<sup>1</sup> + 2x10<sup>0</sup> = 12
</pre>

L\'alieno, abituato a contare in base alle sue dodici dita, direbbe che
le uova sono:

<pre>
1x12<sup>1</sup> + 0x12<sup>0</sup> = 10
</pre>

Il disgraziato con un dito, che può considerare solo le due possibilità:
*un dito/nessun dito*, sarebbe costretto a fare un calcolo più lungo:

<pre>
1x2<sup>3</sup> + 1x2<sup>2</sup> + 1x2<sup>1</sup> + 0x2<sup>0</sup> = 1100
</pre>

Questi tre risultati, per quanto differenti, non sono sbagliati, perché ciascuno dei tre conta le dodici uova in base al numero delle proprie dita e risponde di conseguenza. Le uova rimangono le stesse: cambia solo il sistema di numerazione.  
Del resto, è naturale che sia così: i numeri sono solo concetti astratti; simboli che si utilizzano per identificare delle quantità.
Potresti sostituire i numeri da 0 a 9 con le prime dieci lettere dell\'alfabeto e non cambierebbe nulla:

<table style="margin:1rem auto">
    <tr>
        <td>0</td><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td><td>6</td><td>7</td><td>8</td><td>9</td>
    </tr>
    <tr>
        <td>a</td><td>b</td><td>c</td><td>d</td><td>e</td><td>f</td><td>g</td><td>h</td><td>i</td><td>l</td>
    </tr>
</table>
<pre>
a + b = b     
b + c = d   
d * e = bc
</pre>

Il metodo di calcolo resta lo stesso: quando la quantità da valutare è maggiore del numero delle cifre disponibili, si riporta la differenza a sinistra, nella colonna di ordine superiore.
Il valore *bc* della moltiplicazione, significa infatti:

<pre>
b*(numero di cifre)<sup>1</sup> + 
c*(numero di cifre)<sup>0</sup>
</pre>

ovvero, visto che il numero di cifre a nostra disposizione è 10:

<pre>
b*10 + c*1
</pre>

Se sostituiamo le lettere con i numeri, otteniamo:

<pre>
1*10 + 2*1 = 3*4
</pre>

La numerazione esadecimale fa proprio questo: utilizza le lettere dalla A alla F in aggiunta ai dieci valori della numerazione araba:
<table class="esadecimale">
    <tr>
        <td>0</td><td>1</td><td>2</td><td>3</td>
        <td>4</td><td>5</td><td>6</td><td>7</td>
        <td>8</td><td>9</td><td>A</td><td>B</td>
        <td>C</td><td>D</td><td>E</td><td>F</td>
    </tr>
</table>

Questo torna molto utile quando hai a che fare con dei byte di otto cifre, come vedremo dopo.

---

Nei sistemi di numerazione *posizionali* il valore di una cifra dipende dal punto in cui si trova: le cifre a sinistra hanno più valore delle cifre a destra, ma non tutti i sistemi di numerazione funzionano allo stesso modo.
Se tu chiedessi a un antico romano di calcolare il numero delle uova, ti risponderebbe:

<pre>
XII
</pre>

Anche questo sarebbe un risultato corretto, pur se diverso dai precedenti.
Il sistema di numerazione romano è un po\' più complicato dei sistemi in base 10, 12 e 2 che abbiamo visto finora.
Nella numerazione romana, il valore di una cifra (I, V, X, L, C, D, M) non dipende dalla sua posizione assoluta, ma dalla sua posizione in rapporto alle altre cifre.  
Il Maestro Canaro nacque il 29 febbraio 1964; in cifre romane, questa data è:

<pre>
XXIX II MCMLXIV
</pre>

ovvero:

<pre>
10+10+(10-1)<br/> 
1+1<br/>
1000+(1000-100)+50+10+(5-1)
</pre>

I numeri romani possono andar bene per un popolo di conquistatori: sono facili da scolpire nel marmo, a memoria di una battaglia vittoriosa e non considerano lo zero, la nullità, ma per il commercio e per i calcoli in generale sono piuttosto scomodi.
Quando gli arabi diffusero nel bacino del Mediterraneo il sistema di numerazione che avevano a loro volta imparato dagli indiani, la sua diffusione fu tanto rapida quanto inevitabile.  
I computer, però, non sono né egocentrici come un imperatore romano, né astuti come un mercante fenicio; al contrario, sono veloci, ma tonti: bisogna spiegar loro le cose in maniera semplice, perché le possano portare a termine.  
La numerazione romana non fa per loro, perché richiede troppi simboli e troppe regole per essere messa in pratica.
La numerazione decimale è già un po\' meglio, ma richiede comunque la definizione di dieci simboli diversi, uno per ciascuna cifra da 0 a 9.
Paradossalmente, il sistema di calcolo che un calcolatore può capire più facilmente è quello per noi più complicato, ovvero il sistema binario.
Questo sistema richiede solo la definizione di due simboli: *1* e *0*; due concetti che possono capire facilmente sia un transistor che una scheda perforata.

---

Qualcuno potrebbe dirti che ci sono sistemi di calcolo migliori del binario.
Qualcuno, probabilmente uno di quei disgraziati individui che amministrano le basi di dati, potrebbe dirti che il sistema ternario bilanciato funziona molto meglio e semplifica i calcoli.
Ciò corrisponde al vero.  
La ragione per cui il Maestro Canaro non approvava i sistemi ternarii era filosofica, non tecnica. I due valori del sistema binario possono essere identificati con i valori logici sì/no, vero/falso; ovvero con le due condizioni di esistenza e non esistenza, per esempio, di un buco in una scheda perforata o di una corrente in un circuito.
Al contrario, i sistemi con basi superiori a due, richiedono la definizione di un terzo stato che non può essere né sì, né no; né vero, né falso; né esistente, né in-esistente.
Questo terzo stato intermedio può essere definito solo per mezzo di una valutazione che non è logica, ma quantitativa.
Mettiamo che su una scheda perforata il valore 0 sia associato all\'assenza di fori e il valore 1 sia associato alla presenza di un foro; un terzo valore, differente da 0 e da 1, potrebbe essere identificato o da un foro di dimensioni differenti o da una concavità.
Quale che sia la soluzione scelta, saremmo costretti a definire un valore in base a una grandezza fisica, ovvero, a basare il calcolo digitale su una misurazione analogica.  
Il Maestro Canaro pensava che ciò fosse empio.

---

Un esempio di tutto ciò di cui ti ho parlato oggi lo trovi nella codifica RGB dei colori delle pagine Web.
Nella codifica RGB, ciascun colore è definito come una combinazione di rosso verde e blu – i colori *Red*, *Green* e *Blue* le cui iniziali costituiscono l'acronimo del sistema.  
La quantità di ciascun colore è determinata da un valore di 8 bit e può quindi variare da 0 a 255 (2<sup>8</sup>).  
I possibili colori della codifica RGB possono essere calcolati o moltiplicando fra loro i tre valori di R, G e B: 

```
256 * 256 * 256 = 16.777.216
```

oppure considerando i tre byte un unico valore binario di 24 cifre:

<pre>
2<sup>24</sup> = 16.777.216
</pre>

Un colore RGB con tutti e tre i suoi byte a zero è nero; uno con tutti i byte di valore 255 è bianco. 

<table class="rgb">
<tr>
    <td style="background-color:rgb(0,0,0)"></td>
    <td>RGB(0,0,0)</td>
</tr>
<tr>
    <td style="background-color:rgb(255,255,255)"></td>
    <td>RGB(255,255,255)</td>
</tr>
</table>

Fra questi due estremi ci sono le restanti 16.777.214 possibili combinazioni dei tre valori.
Se assegnamo un valore solo a uno dei tre byte, otterremo delle gradazioni di rosso, verde o blu: 

<table class="rgb">
<tr>
    <td style="background-color:rgb(234,0,0)"></td>
    <td>RGB(234,0,0)</td>
</tr>
<tr>
    <td style="background-color:rgb(0,111,0)"></td>
    <td>RGB(0,111,0)</td>
</tr>
<tr>
    <td style="background-color:rgb(0,0,80)"></td>
    <td>RGB(0,0,80)</td>
</tr>
</table>

Se attribuiamo dei valori a tutti e tre i byte, otterremo dei colori composti.
Per esempio, il colore di sfondo dei brani di codice del tuo libro o il colore dei link di navigazione:

<table class="rgb">
<tr>
    <td style="background-color:rgb(232,232,222)"></td>
    <td>RGB(232,232,222)</td>
</tr>
<tr>
    <td style="background-color:rgb(85,85,0)"></td>
    <td>RGB(85,85,0)</td>
</tr>
</table>

Gli stessi valori possono essere espressi in notazione esadecimale:

<table class="rgb">
<tr>
    <td style="background-color:#000000"></td>
    <td>000000</td>
</tr>
<tr>
    <td style="background-color:#FFFFFF)"></td>
    <td>FFFFFF</td>
</tr>
<tr>
    <td style="background-color:#ea0000"></td>
    <td>ea0000</td>
</tr>
<tr>
    <td style="background-color:#006f00"></td>
    <td>006f00</td>
</tr>
<tr>
    <td style="background-color:#000050"></td>
    <td>000050</td>
</tr>
<tr>
    <td style="background-color:#e8e8de"></td>
    <td>e8e8de</td>
</tr>
<tr>
    <td style="background-color:#555500"></td>
    <td>555500</td>
</tr>
</table>

L'unica diffferenza è che la numerazione esadecimale è più facile da utilizzare e da memorizzare, perché ciascuna lettera corrisponde a un byte.
Il valore binario e il colore visualizzato, rimangono gli stessi, indipendentemente dal modo in cui tu li vuoi misurare.

<hr id="dottrina">

C'è qualcosa, in tutto questo, sulla quale vorrei che tu soffermassi la tua attenzione: i numeri *descrivono* un valore, non *sono* un valore.
I valori esistevano da prima che esistessero i numeri e gli sopravviveranno.
La quantità di fiammiferi che vedi qui sul mio tavolo, rimane la stessa sia che tu la chiami *4*, *100* o *IV*, così come rimarrebbe la stessa se tu la chiamassi *five* o *cinco*.  
I numeri li abbiamo inventati noi, i valori, no.
 
<!--
@todo - aggiungere note su geometria e matematica
-->
