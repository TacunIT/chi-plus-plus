Le classi
=========

Non accetterei mai di far parte di una rete

che abbia un server come me fra i suoi nodi

Mettere radici non è male, ma è pericoloso, c'è sempre qualcuno pronto a
coprirtele di letame.

Funzioni di interfaccia
-----------------------

Lévy-Bruhl, citato da Coomaraswamy (*Grande Brivido*, pag. 227) «Per
questa ragione il selvaggio non ama dire il suo nome o farsi
fotografare, perché per mezzo del suo nome o del ritratto egli è
accessibile, e può quindi ricevere danno da chi con questi mezzi è in
grado di raggiungerlo.»

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
avviciniamo lo sguardo, le irregolarità diventeranno sempre più
evidenti.

Questo non vuol dire che le forme geometriche siano delle menzogne.

Esse esistono, ma hanno un valore puramente simbolico, e non possono
essere utilizzate in contesti reali.

È la stessa differenza che passa fra l'Adamo celeste e l'Adamo
terrestre. L'Adamo celeste è l'emanazione del Pensiero di Dio ed è per
ciò immortale; l' Adamo terrestre è l'incarnazione del modello celeste
nella materia ed è quindi soggetto al ciclo di nascita e morte.

E tu certamente saprai cosa vuol dire *ādām*, in ebraico.

Le *classi astratte* del C++ sono delle classi generiche che possono
essere utilizzate come capostipite per una discendenza di classi
specializzate, ma che non possono essere utiliz­zate direttamente.

Le regole che si applicano alle classi astratte sono:

-   viene considerata *astratta* qualunque classe che abbia almeno una
    funzi­one virtuale pura;
-   non si possono utilizzare classi astratte come argomenti o come tipi
    di ritorno di funzioni ;
-   le classi astratte non possono essere il tipo di un oggetto o di una
    con­versione esplicita.

Quindi, se definissimo una classe astratta Circonferenza, tutte le
istruzioni seguenti darebbero luogo ad errori di compilazione:

> void funz(Circonferenza);

> Circonferenza funz();

> Circonferenza piatto;

> Circonferenza\* ptr = (Circonferenza\*)disco;

Ciò che i teorici definiscono "paradossi" altro non sono che degli
errori di compilazione.

Lo prova il fatto che i paradossi esistono solo nella teoria, nella
pratica esistono solo le cose possibili e le cose impossibili \[come un
quadrato la cui area non sia proporzionale al diametro del cerchio
inscritto\], perché i paradossi non possono essere compilati.

"Breve storia dell'Infinito" cap. II, pag. 32-33

Quadratura del cerchio secondo Antifonte e confutazione di Aristotele.

Entrambe le affermazioni sono vere, ma in contesti differenti.

Nella realtà, esiste sempre un limite che blocca la ricorsione
all'infinitesimo.

All'interno di uno schermo, ha ragione Antifonte, perché non potremo
disegnare poligoni i cui lati siano più piccoli di un pixel.

Su uno schermo, un cerchio è di fatto un poligono con tanti lati quanti
sono i pixel che ne costituiscono la circonferenza.

Quindi, la circonferenza euclidea esiste, ma è una classe astratta.

Per poterla trasformare in una ruota di carro o in un piatto dobbiamo
creare una nuova classe

> class Ruota : public Circonferenza

> {

> \...

> };

Nessuna di queste istruzioni darà luogo a errori di compilazione:

> void funz(Ruota);

> Ruota funz();

> Ruota r;

> punt = (Circonferenza\*) ptr ;

> Ruota\* anteriore = new Ruota();

Possiamo dichiarare un puntatore o un riferimento ad una classe
astratta, così come è possibile assegnare un'istanza della classe
derivata ad un puntatore ad oggetti della classe base:

> Circonferenza\* ptr = anteriore;

> Circonferenza& rif(anteriore);

E del resto, sarebbe stato assurdo il contrario: a cosa sarebbe servito
definire una classe a cui non è possibile accedere in nessun modo?

Funzioni virtuali pure
----------------------

A questo punto è giusto che tu sappia cosa sia, una *funzione virtuale
pura*.

Come ti ho detto, la sintassi delle funzioni virtuali pure dev'essere:

> virtual \<*tipo*\> nomefunzione(\[*argomenti*\]) = 0 ;

\...

> \#include\<iostream\>

> \#include\<string\>

> using namespace std;

> class Circonferenza {

> public:

> Circonferenza(float r): \_raggio(r) {}

> float diametro() { return (\_raggio + \_raggio); }

> virtual string descrizione() = 0;

> private:

> float \_raggio;

> };

> class Piatto : public Circonferenza {

> public:

> Piatto(float r): Circonferenza(r) {}

> string descrizione() { return \"supporto in ceramica per i cibi\";}

> };

> int main() {

> Piatto p(12);

> Circonferenza& c = p;

> cout \<\< p.descrizione() \<\< \", diam. \" \<\< p.diametro() \<\< \"
> cm \" \<\< endl;

> cout \<\< c.descrizione() \<\< \", diam. \" \<\< c.diametro() \<\< \"
> cm \" \<\< endl;

> return 0;

> }
