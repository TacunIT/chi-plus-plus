---
status:     redazione
layout:     manuale
class:      capitolo
title:      Il polimorfismo
permalink:  /man/polimorfismo
quote:      "Non puoi immergere i tuoi byte due volte nello stesso stream"
---

Come avrai certamente intuito, da tutto ciò che abbiamo detto finora, la caratteristica principale del C++ è il polimorfismo.  
Avevamo iniziato a parlarne durante la <a href="/man/c-plus-plus#polimorfismo" class="xref">lezione inroduttiva sul C++</a> e l'avevamo illustrato con un esempio che, a questo punto, non dovrebbe più avere segreti, per te:

```
{% include_relative src/cplusplus-template.cpp %}
```

L'output di questo codice, nel caso l'avessi scordato, è:

```
> g++ src/cpp/cplusplus-template.cpp -o src/out/esempio
> src/out/esempio
DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   puledro

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo	    Sesso:f
ESITO:   asino

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Asino	Razza:amiatino	Sesso:m
FEMMINA: Specie:Cavallo	Razza:maremmano	Sesso:f
ESITO:   mulo

DATA:    Sun May 23 14:42:51 2021
MASCHIO: Specie:Cavallo	Razza:lipizzano	Sesso:m
FEMMINA: Specie:Asino	Razza:sardo	    Sesso:f
ESITO:   bardotto
```

Prima di andare avanti, però, è necessario fare un po' di chiarezza su tre termini legati al polimorfismo: *overload*, *override* e *ridefinizione*.  
Con il termine: <b id="overload">overload</b> di una funzione si intende la una funzione che abbia lo stesso nome di un'altra, ma dei parametri differenti. 
Un tipico esempio di *function overload* sono le differenti versioni del costruttore di una classe:

```
Cavallo() {}
Cavallo(const char* razza, const Sesso sesso )
: Animale(razza, sesso ) { 
}
```
Le due funzioni hanno lo stesso nome e il compilatore sceglierà l'una o l'altra in base ai parametri che vengono utilizzati.  
Una funzione <b id="overridden">overridden</b> è una funzione che ha una definizione diversa da quella di una funzione virtuale di una sua classe-base:

```
const char* getSpecie() const {
    return "Asino"; 
}     
```

Come abbiamo visto, il compilatore sceglie l'una o l'altra in base al tipo di oggetto utilizzato per la chiamata.  
Se la funzione della classe base non fosse stata virtuale, questa sarebbe stata una semplice **ridefinizione**:

```
class Persona {
public:
    void getClass(){
        cout << "Persona" << endl;
    }
};
```

In questi casi, il compilatore non fa un controllo di tipo dinamico, basato sul tipo dell'oggetto al momento dell'esecuzione, ma sceglie la funzione da chiamare in base al tipo di puntatore o riferimento utilizzato, cosa che, come abbiamo visto, può creare dei problemi:

```
Madre   * ptrM = new Madre;
Persona * ptrP = ptrM ;
ptrM->getClass() ;
ptrP->getClass() ;  // chiama la funzione di Persona - ERRORE
```

Ora che conosci questa differenza, possiamo correggere i commenti del codice di esempio: 

```
/** Overload dell'operatore di output su stream  */
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}

/** Override della funzione virtuale pura */
const char* getSpecie() const {
    return "Cavallo"; 
}  

/** Override della funzione virtuale pura */
const char* getSpecie() const {
    return "Asino"; 
}     

/** Overload dell'operatore di output su stream */
friend ostream& operator << (ostream& os, const Monta& copula) {
    os << "DATA:    " << asctime(localtime(&copula._giorno)) 
       << "MASCHIO: " << *copula._maschio 
       << "FEMMINA: " << *copula._femmina
       << "ESITO:   " << copula._esito
       << endl;
       return os;   
 };
```

<hr id="overload-operatori"> 

Nel C++, a ogni operatore corrisponde una funzione, che è possibile richiamare direttamente facendo seguire la parola-chiave `operator` dal simbolo dell’operatore. 
Per esempio, la struttura della funzione corrispondente all’operatore binario `+=` è:

```
<tipo>& operator +=  (<tipo>& a, <tipo>& b) ;
```

laddove `a` e `b` sono i due oggetti che intervengono nell’operazione e `<tipo>` è il tipo delle variabili che intervengono nell'operazione.  
La classe `string`, della libreria standard del C++, per esempio, ridefinisce, fra le altre cose, il comportamento degli operatori di assegnazione `+=` e `+` e dell'operatore di output su stream `<<` :

```
{% include_relative src/polimorfismo-operatori.cpp %}
```

L'output di questo codice è ben noto:

```
> g++ src/cpp/polimorfismo-operatori.cpp -o src/out/esempio
> src/out/esempio                                          
PippoPluto
```

Lo stesso risultato si poteva ottenere anche con la funzione `append`:

```
string& append (const string& str)
```

ma utilizzare un operatore standard rende il codice più facile da leggere e da scrivere.

--

Quando si ridefinisce il comportamento di un operatore per una classe, bisogna tenere conto della visibilità dei dati membro che deve utilizzare.
Se l'operatore, com'è probabile, deve gestire dei dati privati o protetti, le possibilità sono due: o sfruttare le funzioni di interfaccia della classe o  dichiarare l'operatore `friend` della classe.
Nell'esempio iniziale sono applicate entrambe le possibilità: l'operatore di output su stream per la classe `Animale` utilizza le funzoni di interaccia della classe:

```
ostream& operator << (ostream& os, const Animale& animale) {
    os  << "Specie:" << animale.getSpecie() << "\t"
        << "Razza:"  << animale.getRazza()  << "\t"
        << "Sesso:"  << animale.getSesso()  
        << endl;
    return os;   
}
```

mentre l'operatore di output per la classe `Monta` è dichiarato come `friend` della classe e quindi può accedere ai dati membro direttamente:

```
friend ostream& operator << (ostream& os, const Monta& copula) {
    os << "DATA: "    << asctime(localtime(&copula._giorno)) 
       << "MASCHIO: " << *copula._maschio 
       << "FEMMINA: " << *copula._femmina;
       return os;   
};
```



<hr id="dottrina">

Fra il C'hi++ e le religioni canoniche c'è la stessa differenza che passa fra una mappa topografica e un'immagine da satellite.  
Quel senza Dio di Dawkins, ha detto che: 

> {{ site.data.citazioni.dawkins.analogia }}

Una frase curiosa, da parte di un esponente di una setta che cerca di descrivere tutto ciò che esiste con analogie matematiche e nega l'esistenza di ciò che non riesce a convertire..  
Entusiasmi a parte, le mappe e le immagini da satellite hanno diverse analogie con le discipline metafisiche.
Anche le mappe e le immagini, come la metafisica, sono costrette a rappresentare il loro soggetto a un rapporto di scala ridotto e con due sole dimensioni in vece di tre (o di quattro se, oltre alla profondità, vuoi considerare anche il tempo).
Anche le mappe e le immagini, per questo motivo, devono rappresentare il loro soggetto per mezzo di analogie: le carte topografiche usano delle linee altimetriche e dei simboli; le immagini satellitari usano dei pixel o dei piccoli punti di colore.
In nessuno dei due casi ciò che noi vediamo è davvero ciò che rappresenta; è il nostro cervello che decide di crederlo tale: nel caso della carta topografica, perché la legenda ci permette di definire una correlazione fra significato e significante; nel caso dell'immagine, perché il nostro occhio riconosce in quelle combinazioni di pixel o di punti di colore degli alberi, mare o case.  
Un'altra analogia, conseguenza dei due punti precedenti, è che è sbagliato confondere i simboli con ciò che rappresentano: i quadratini scuri delle mappe *non* sono case; i punti colorati delle immagini *non* sono un bosco.
Mappe e immagini hanno senso solo a un certo livello di lettura; se lo oltrepassiamo, se cerchiamo di ottenere più informazioni o verosimiglianza avvicinando lo sguardo, otteniamo l'effetto opposto, perché i simboli si rivelano per quello che sono: punti colorati o linee su un foglio. 
Questo però non vuol dire che ciò che rappresentano sia falso, ma che noi non stiamo guardando con *il giusto paio di occhi*, come direbbe Hunter Thompson.  
Il Maestro Canaro pensava che fosse per questo motivo che alcune religioni sono contrarie alla rappresentazione diretta della Divinità: perché è facile che poi si confonda il simbolo con ciò che rappresenta. 
<!-- 
Agli Ebrei è vietato dal secondo Comandamento e anche i Cristiani si attennero a questa regola fino al Concilio di Nicea del 787.
@todo: verificare regole simili per l'Islam. 
--> 
Tornando al paragone iniziale, le religioni tradizionali sono delle immagini da satellite, mentre il C'hi++ è una mappa topografica.  
Mentre i Credi religiosi riescono a riprodurre &mdash; nei limiti imposti dalla nostra condizione &mdash; tutta la bellezza del Creato, il C'hi++ si limita a darne una descrizione schematica, più povera di contenuti e di poesia, ma più facile da accettare per chi non abbia la benedizione della Fede.
Un'immagine da satellite ha un valore contemplativo: è bella da guardare sullo schermo del tuo computer o anche da appendere al muro, come un quadro, ma 
se ti sei perso in un bosco o in mezzo ai monti, una mappa topografica, proprio in virtù della sua schematicità, ti permetterà più facilmente di ritrovare la strada di casa.  
Il C'hi++ non cerca di rubare fedeli alle religioni canoniche.
Non avrebbe senso: sarebbe come cercare di convincere chi sia già sposato con l'amore della sua vita a fare un matrimonio di interesse: se tu hai la Fede non hai bisogno di conferme razionali; possono compiacerti, ma non ti sono necessarie. 
Il C'hi++, però, può dare forza a quelle (tante) persone che *ancora credono in tutto ciò in cui più nessuno crede*, come li descrisse Longanesi; quella *Banda degli Onesti*<a href="/man/note#banda-onesti" class="nota"></a> che tutti i giorni fa il proprio dovere al meglio possibile anche se non gli conviene, anche tutto e tutti intorno a loro sembrano spingerli all'egoismo e all'indifferenza.





<!--





3.3 sovrapposizione degli operatori

Stessa cosa dicasi per gli operatori unari, siano essi prefissi o postfissi. Nel primo caso (operatori unari prefissi), la funzione corrispondente avrà un solo argomento, nel secon­do (operatori unari postfissi), per permettere al compilatore di distinguere le due ver­sioni, si aggiungerà un secondo argomento dummy  :

void operator ++ (<tipo> a) ;		   // versione prefissa
void operator ++ (<tipo> a, <tipo>) ; // versione postfissa

Anche se è possibile richiamare le funzioni operatore in maniera diretta, è più semplice e veloce utilizzare direttamente gli operatori corrispondenti. Le prossime due istruzioni, una volta compilate, producono il medesimo codice e risultato, comunque, se riuscite a trovare una ragione qualunque per usare la prima sintassi piuttosto che la seconda, fatelo pure:

a = b.operator + (c) ; 	
a = b + c ;

Il comportamento degli operatori è predefinito per tutti i tipi standard, ma cosa succede quando si introducono in un programma dei tipi di dati definiti dall’utente? Abbiamo detto, più di una volta, che la definizione di una nuova classe è, di fatto, la definizione di un nuovo tipo di dato e che gli oggetti appartenenti alla nuova classe possono essere trat­tati esattamente come gli oggetti di tipo primitivo: questo comporta che anche per le di noi create di volta in volta si possa definire (o ri-definire) il comportamento degli operatori? La risposta è sì: gli unici operatori non sovrapponibili sono: 

·	. (operatore di selezione) ;
·	.* (operatore di risoluzione di indirizzamento dei puntatori a membri della classe);
·	:: (operatore di risoluzione del campo d’azione);
·	?: (operatore condizionale) ;
·	i simboli # e ## che vengono utilizzati dal preprocessore.

3.4	sovrapposizione degli operatori per una classe

La sovrapposizione di un operatore per una determinata classe può essere compiuta in due maniere differenti:
·	ridefinendo il comportamento di un operatore globale per quella parti­colare classe.
·	definendo una funzione membro non statica per la classe;

Le differenze principali fra l’una e l’altra soluzione sono che una funzione operatore membro ha (generalmente) un argomento in meno della corrispondente funzione globale (il riferimento all’operando di sinistra viene assicurato dall’argomento this che, come sappiamo, viene sempre passato come parametro nelle funzioni), mentre una funzione operatore globale ridefinita non varia la sua sintassi, ma non ha accesso ai dati privati della classe. Questo ci pone di nuovo di fronte ad un bivio: o dichiariamo la funzione come friend oppure facciamo in modo che agisca su funzioni di interfaccia. La prima soluzione è la più efficiente, la seconda sarà probabilmente più lenta in esecuzione ma non necessiterà di riscritture in caso di modifiche alla struttura della classe.
Scendendo più in dettaglio (e posto che C sia il nome di una classe e Op un qualsiasi op­eratore), se avessimo a che fare con un operatore unario, le alternative saranno quindi o una funzione membro che non richieda parametri:
C::operator Op () ;	
o una funzione globale che accetti un argomento del tipo della classe, ovvero :
operator Op (C)  ;	
È possibile invece ridefinire un operatore binario o definendo una funzione membro che accetti un argomento 
C::operator Op (C) ;
oppure ridefinendo una funzione globale che accetti due argomenti :
operator Op (C left, C right) ;
Vediamo ora come tutte queste regole si possano applicare alla classe Punto:

#include "iostream.h"
class Punto
{
 private:
		int X, Y ;				
		static int PuntiCreati ;	
 public:
		Punto(int x, int y) ; 		
		~Punto() ;
	
		static int Istanze() { return PuntiCreati ; }	
		int ValX() { return X ; }	
		int ValY() { return Y ; }

		Punto& operator+ (Punto &p) ;	                  // 001
		Punto& operator+=(Punto &p) ;	                  // 001

	friend Punto& operator-= (Punto &p1, Punto &p2); // 002
};
/////////////////////////////////////////////////////////////
Punto operator - (Punto &p1, Punto &p2)              // 003
{
	return Punto(p1.ValX()-p2.ValX(),p1.ValY()-p2.ValY()) ;
}
/////////////////////////////////////////////////////////////
Punto Punto::operator + (Punto p)
{
	return Punto( X + p.X, Y + p.Y ) ;
}
/////////////////////////////////////////////////////////////
Punto Punto::operator += (Punto p)
{
	X = X + p.X ;
	Y = Y + p.Y ;
}
/////////////////////////////////////////////////////////////
Punto operator -= (Punto &p1, Punto &p2)
{
	p1.X = p1.X - p2.X ;
	p1.Y = p1.Y - p2.Y ;
}
/////////////////////////////////////////////////////////////
001  Gli operatori + e +=, sono dichiarati come membri della classe Punto, quindi non hanno problemi di accesso ai dati privati.
002  L’operatore -= è dichiarato friend della classe Punto, e quindi anche lui può accedere ai dati membro privati X e Y in maniera diretta.
003  L’operatore globale -- accede ai dati privati per mezzo delle funzioni di interfaccia ValX() e ValY().
Notate bene che la pletora di approcci utilizzata qui come esempio, pur se corretta da un punto di vista sintattico, sarebbe inaccettabile in un programma reale. La sovrapposizione degli operatori va fatta in maniera coerente per ogni classe, scegliendo un metodo ed applicandolo in tutti i casi. Decidere di fare il contrario non è un errore, ovviamente, ma potrebbe complicare la vita a voi e/o alle per­sone che, dopo di voi, potrebbero aver a che fare con il vostro codice. 
3.4.1 Limitazioni alla sovrapposizione
Oltre agli operatori non sovrapponibili elencati al paragrafo 3.3, esistono degli operatori di cui non è consentito ridefinire tramite overload la versione globale. Questi sono:  =, () , [], -> e ->* ,che possono essere solo sovrapposti come funzioni membro non static. Altre regole da ricordare in questi casi sono:
·	l’operatore unario di assegnamento = per una qualsiasi classe C, se non ridefinito, prevede l’assegnamento membro a membro degli attributi ed ha la sintassi :

C& C::operator = (const C& origine) ;
	questo è inoltre l’unico caso di funzione membro che non viene eredi­tata da eventuali classi figlie;
·	l’operatore binario []permette di implementare vettori di tipo particolare, ma con la sintassi standard ed ha la forma:
 
c.operator [] (n) ;
	dove c è un oggetto di classe C e l’indice n può essere un qualsiasi tipo di dato ;
·	per ridefinire l’operatore binario di chiamata a funzione per la solita classe C, va utilizzata una sintassi del tipo: 

c.operator()(p) ;
	dove c, tanto per cambiare è un oggetto di classe C e p è un elenco anche vuoto, di parametri;
·	l’operatore unario di accesso ai membri della classe -> viene interpre­tato come:

(C.operator -> ())->m ;
	e ritorna o un oggetto o un puntatore ad un oggetto di classe C.
3.5	Overload degli operatori new e delete
Ridefinire degli operatori come new e delete, il cui comportamento è strettamente le­gato all’hardware, non sempre è la cosa migliore da fare dal punto di vista della port­abilità del codice, comunque, se si desidera che una classe abbia un modo particolare di gestire la memoria libera dello heap, lo si può fare, ricordandosi però di rispettare alcune regole di base:
·	l’operatore new deve avere il primo argomento di tipo size_t e resti­tuire un puntatore a void;
·	l’operatore delete deve essere una funzione di tipo void che abbia un primo argomento di tipo puntatore a void ed un secondo argomento, facoltativo, di tipo size_t;
in pratica, qualcosa di simile:

class C
{ 
 private:
		...
 public:
		...

		void * operator new(size_t dim)
					{ return miaAlloc(dim) ; }

		void operator delete(void * p) 	
					{ miaFree(dim) ; }
} ;
laddove miaAlloc() e miaFree() sono due funzioni di allocazione e rilascio della memoria definite dall’utente.
Una chiamata al costruttore di una classe C comporta una chiamata alla funzione opera­tore X::operator new() per l’allocazione della memoria necessaria a contenere la nuova istanza. Quella stessa memoria, in seguito ad una chiamata al distruttore della classe, verrà rilasciata dall’operatore C::operator delete(). In conseguenza di ciò (se new fosse una normale funzione membro, sarebbe impossibile creare la prima istanza della classe ed altri problemi nascerebbero cercando di utilizzare delete per distruggere l’istanza cui appartiene) entrambe queste funzioni, anche se non lo sono state dichiarate esplicitamente, sono membri statici di C e non possono in alcun modo essere implemen­tate come funzioni virtuali.
La ridefinizione per una classe degli operatori new e delete nasconde gli operatori globali (ovviamente all’interno del campo d’azione della classe) solo se gli oggetti da creare o distruggere appartengono alla classe o a delle classi da essa derivate, in tutti gli altri casi (tipi di dato primitivi o classi non derivate), l’operatore che interviene è comunque quello globale. 

void* C::operator new (size_t dim)
{ 
 char* ptr = new char[dim] ;             // new globale
	...
}

void* C::operator delete (void * ptr)
{ 
	...
	delete (void *) ptr ;               // delete globale
}
Per utilizzare gli operatori globali anche con dati appartenenti alla classe si dovrà ricor­rere all’ operatore di risoluzione del campo d’azione.
3.6	Overload dei cammini di coercizione
In C, per trasformare un int in un double si utilizzano gli operatori di cast:
long int i = 5 ;
double d = (double) i ;
C++ accetta questa sintassi così come accetta che si usi malloc al posto di new, ma la sua sintassi standard (che ricorda vagamente i costruttori delle classi) prevede che il dato da convertire venga passato come parametro ad una funzione con lo stesso nome del tipo in cui si vuole che avvenga la conversione :
long int i = 5 ;
double d = double(i) ;
Com’è facilmente intuibile, il compilatore C++ ha la possibilità di convertire un qualunque tipo di dato primitivo in un altro, ma non ha la più pallida idea di come comportarsi in presenza di tipi di dato definiti dall’utente: come era avvenuto già per i costruttori e gli operatori, è nostro compito istruirlo, definendo grazie alla sovrapposizione, nuovi cam­mini di coercizione dal nuovo tipo di dato a quelli primitivi e viceversa.
Quest’ultima parte del lavoro, la trasformazione dal tipo primitivo a quello definito dall’utente, è la più semplice: di fatto si tratta di definire, laddove non ci sia già, un cos­truttore per la nuova classe che richieda dei parametri di tipo primitivo. Quando invece non esiste un costruttore da estendere, ovvero quando la coercizione è dal tipo definito dall’utente ad un tipo di dato primitivo o fornito in una libreria di cui non si possiede il codice sorgente, si procede sovrapponendo l’operatore di conversione del tipo.
Immaginate di aver implementato un nuovo tipo di dato chiamato Frazione, per la gestione dei numeri razionali. Per utilizzarlo in espressioni contenenti dati di tipo primi­tivo possiamo estendere ciascun operatore per fargli accettare dei dati di tipo misto:
Frazione operator + (int i, Frazione f) :
Frazione operator - (int i, Frazione f) :
Frazione operator + (double i, Frazione f) :
Frazione operator - (double i, Frazione f) :
...
Questo metodo però richiede la sovrapposizione di tutti gli operatori per tutti i tipi di dato, una cospicua mole di lavoro che ci possiamo risparmiare ridefinendo solo il com­portamento degli operatori per la nuova classe e fornendo al compilatore dei cammini di conversione dai tipi primitivi al tipo Frazione, da applicare in caso di espressioni miste:

class Frazione
{
 private:
		int num ;
		int den ;
 public:
		Frazione(int n, int d = 1) 
				{ num = n ; den = d ; }              // 001
		Frazione(double) ;

		operator int () 
					{ return num / den ; }         // 002
		operator double() 
			{ return (double) num / (double) den ; }   // 003

friend Frazione operator+ (Frazione f1, Frazione f2); // 004
friend Frazione operator- (Frazione f1, Frazione f2); // 004

} ;
/////////////////////////////////////////////////////////////
001 Costruttore inline (vi ricordate questa sintassi?).
002  Costruttore che funziona anche da operatore di conversione.
003  Operatori di conversione sovrapposti.
004  Ridefinizione degli operatori globali di addizione e sottrazione.
Semplice, no? Basta ridefinire i cammini di coercizione ai/dai tipi primitivi ed una man­ciata di operatori, ed il nostro nuovo tipo Frazione è pronto per essere utilizzato in qualsiasi espressione, delegando al compilatore il compito di trasformare i dati nel tipo appropriato, nel caso di espressioni miste.
3.7	Template di funzioni
La sovrapposizione delle funzioni è una gran bella cosa, ma non sempre è il sistema più efficiente di procedere. Riprendiamo un attimo l’esempio minore.cpp: se avessimo voluto ride­finire la funzione minore() per tutti i tipi di dato, avremmo dovuto scrivere una funzi­one, uguale alle altre, ma con  parametri diversi per ciascun tipo di dato primitivo; un la­voro magari non particolarmente complicato ma decisamente noioso e che avrebbe certamente aumen­tato le dimensioni del codice. 
Per evitare ciò avremo potuto tentare la strada delle macroistruzioni del precompilatore:
#define minore(a,b) ( (a < b ) ? a : b )
purtroppo, però il precompilatore non fa altro che sostituire una serie di istruzio­ni con un’altra, senza curarsi minimamente del contesto in cui queste si trovano. In certi casi la sua superficialità non causa nessuna differenza, in altri può causare dei problemi mica da ridere:

# define minore(a,b) ( (a < b ) ? a : b )

class Dummy
{
 private:
		...
 public:
		...

		float minore(float, float);  // qui avviene l'errore
} ;
Nel caso stiate pensando che in fondo, usare le macro  stando attenti che questo tipo di inconvenienti non si verifichi è sempre meglio che dover scrivere una serie di funzioni tutte uguali, ho due notizie per voi: una buona ed una cattiva.
La notizia cattiva è che l’opzione macro è inaccettabile comunque, perché ha il difetto di privarci di tutti i benefici effetti dell’accurato controllo dei tipi operato dal C++. Il precompilatore, infat­ti, non eseguendo nessun tipo di verifica del tipo dei dati, opera senza segnalare nessun tipo di errore anche con oggetti fra loro incompatibili (come potrebbero essere un dou­ble ed una struttura), il che non è affatto ciò che si definisce un comportamento affida­bile. 
La notizia buona è che in C++ c’è un sistema per venir fuori elegantemente da questo genere di situazioni: i template di funzioni. Un template di funzione è un po' come un modello in carta per sarti: restituisce la stessa forma indipendentemente dal tipo di stoffa che si utilizza:

template <class T> 
T minore(T a, T b)
{
	return ( a < b ) ? a : b ;
}
dove <class T> è una sorta di parametro aggiuntivo rappresentante il tipo di dati che verranno forniti alla funzione. Abbiamo così definito uno stampo; sarà compito del compi­latore riempirlo di volta in volta con i dati adatti, e questo sia che si tratti di tipi di dato primitivi che, come vedremo nel prossimo esempio, di dati definiti dall’utente. Prima di far questo, però, dobbiamo aggiornare la classe Punto.
Per prima cosa vanno sovrapposti gli operatori < e > per poter confrontare fra loro le is­tanze della classe; in secondo luogo, bisogna ridefinire gli operatori di output << e >> per poter  visualizzare i dati relativi ad un oggetto di tipo Punto in maniera coerente con quella utilizzata per gli altri tipi di dato. Attenzione, però, perché quest’ultima operazione va fatta in maniera differente per ciascuno dei due operatori. Infatti se l’output dei dati pri­vati della classe Punto non costituisce un problema, essendo garantito dalla funzioni di interfaccia ValX() e ValY(), la modifica degli stessi dati non è consentita che a funzi­oni appartenenti alla classe e qualunque tentativo di accesso a  X e Y da parte dell’operatore >> causerebbe un errore in fase di compilazione. 
Ci sono tre modi in cui è possibile risolvere questo problema: 
·	creare delle funzioni di interfaccia anche per la modifica dei dati membro X e Y;
·	ridefinire l’operatore >> come membro della classe;
·	dichiarare l’operatore >> friend della classe Punto.
Quest’ultima è la soluzione adottata. Una piccola novità: anche in vista di quello che ci aspetta nel prossimo capitolo, il codice relativo la classe Punto è stato diviso in due files distinti, come si conviene. 
Il file punto.h che trovate immediatamente dopo queste righe, contiene la dichiarazione della classe, mentre punto.cpp contiene la definizione (o ride­finizione) delle funzioni membro. punto.cpp va unito in un file di progetto() al file mintempl.cpp, che definisce il template di funzione minore() e la funzione main() per l’esempio.
PUNTO.H - Dichiarazione della classe Punto
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	PUNTO.H - Dichiarazione della classe Punto
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
/////////////////////////////////////////////////////////////
class Punto
{
 private:
		static int PuntiCreati ;
		int X, Y ;
 public:
		Punto(int x = -1, int y = -1) ;
		~Punto() ;

		static int Istanze()	{ return PuntiCreati ; }
		int ValX()		{ return X ; }
		int ValY()		{ return Y ; }

		Punto & operator += (Punto &);
		Punto & operator -= (Punto &);
		Punto & operator *= (double);
		Punto & operator /= (double);
		Punto operator + ();
		Punto operator - ();

		friend Punto operator +  (Punto &, Punto &);
		friend Punto operator -  (Punto &, Punto &);
		friend Punto operator *  (Punto &, double);
		friend Punto operator *  (double, Punto &);
		friend Punto operator /  (Punto &, double);
		friend int   operator == (Punto &, Punto &);
		friend int   operator != (Punto &, Punto &);
		friend int   operator >  (Punto &, Punto &) ;
		friend int   operator <  (Punto &, Punto &) ;
		friend istream& operator>> (istream& is, Punto& p);
} ;

ostream & operator << (ostream & os, Punto & p) ;
PUNTO.CPP - Definizione della classe Punto
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	PUNTO.CPP - Definizione della classe Punto
//
/////////////////////////////////////////////////////////////
#include "punto.h"
/////////////////////////////////////////////////////////////
int Punto::PuntiCreati = 0 ;
/////////////////////////////////////////////////////////////
Punto::Punto(int x, int y)
: X(x), Y(y)
{
	PuntiCreati ++ ;
}
/////////////////////////////////////////////////////////////
Punto::~Punto()
{
	PuntiCreati -- ;
}
/////////////////////////////////////////////////////////////
Punto Punto::operator + ()
{
    return *this ;
}
/////////////////////////////////////////////////////////////
Punto  Punto::operator -()
{
    return Punto(-X, -Y) ;
}
/////////////////////////////////////////////////////////////
Punto & Punto::operator += (Punto & right)
{
    X += right.X ;
    Y += right.Y ;
    return *this ;
}
/////////////////////////////////////////////////////////////
Punto & Punto::operator -= (Punto  & right)
{
    X -= right.X ;
    Y -= right.Y ;
    return *this ;
}
/////////////////////////////////////////////////////////////
Punto & Punto::operator *= (double d)
{
    X *= d ;
    Y *= d ;
    return *this ;
}
/////////////////////////////////////////////////////////////
Punto & Punto::operator /= (double d)
{
    X /= d ;
    Y /= d ;
    return *this;
}
/////////////////////////////////////////////////////////////
Punto operator + (Punto & left, Punto & right)
{
    return Punto(left.X + right.X, left.Y + right.Y) ;
}
/////////////////////////////////////////////////////////////
Punto operator - (Punto & left, Punto & right)
{
    return Punto(left.X - right.X, left.Y - right.Y) ;
}
/////////////////////////////////////////////////////////////
Punto operator * (Punto & left, double d)
{
    return Punto(left.X * d, left.Y * d) ;
}
/////////////////////////////////////////////////////////////
Punto operator * (double d, Punto & right)
{
    return Punto(right.X * d, right.Y * d) ;
}
/////////////////////////////////////////////////////////////
Punto operator / (Punto & left, double d)
{
    return Punto(left.X / d, left.Y / d) ;
}
/////////////////////////////////////////////////////////////
int operator == (Punto & left, Punto & right)
{
    return left.X == right.X && left.Y == right.Y ;
}
/////////////////////////////////////////////////////////////
int operator != (Punto & left, Punto & right)
{
    return left.X != right.X || left.Y != right.Y ;
}
/////////////////////////////////////////////////////////////
int operator < (Punto & left, Punto & right)
{
	return (left.X < right.X && left.Y < right.Y ) ;
}
/////////////////////////////////////////////////////////////
int operator > (Punto & left, Punto & right)
{
	return (left.X > right.X && left.Y > right.Y ) ;
}
/////////////////////////////////////////////////////////////
ostream & operator << ( ostream & os, Punto & p)
{
	os << '(' << p.ValX() << ',' << p.ValY() << ')' ;
	return os ;
}
/////////////////////////////////////////////////////////////
istream & operator >> ( istream & is, Punto & p)
{
	is >> p.X >> p.Y ;
	return is ;
}
/////////////////////////////////////////////////////////////
MINTEMPL.CPP - Esempio di funzione template applicata alla classe Punto
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	MINTEMPL.CPP - Esempio di funzione template applicata
//				  alla classe Punto
//
/////////////////////////////////////////////////////////////
#include "punto.h"
/////////////////////////////////////////////////////////////
template <class T> T minore(T a, T b)
{
	return ( a < b ) ? a : b ;
}
/////////////////////////////////////////////////////////////
void main()
{
	int    i1, i2 ;
	float  f1, f2 ;
	Punto  p1, p2, p3 ;

	cout <<"\nInserire i valori per i due interi i1 e i2 :";
	cin >> i1 >> i2 ;

	cout <<"\nInserire i valori per i due float f1 e f2 :" ;
	cin >> f1 >> f2 ;

	cout <<"\nInserire i valori per il primo punto :" ;
	cin >>	p1  ;
	cout <<"\nInserire i valori per il secondo punto :" ;
	cin >>	p2  ;
	cout <<"\nInserire i valori per il terzo punto :" ;
	cin >>	p3  ;

	cout << "i1       :" << i1 << "\n" ;
	cout << "i2       :" << i2 << "\n" ;
	cout << "f1       :" << f1 << "\n" ;
	cout << "f2       :" << f2 << "\n" ;
	cout << "p1       :" << p1 << "\n" ;
	cout << "p2       :" << p2 << "\n" ;
	cout << "p2       :" << p3 << "\n" ;
	cout << "p1 + p2  :" << (p1 + p2) << "\n" ;
	cout << "p1 - p2  :" << (p1 - p2) << "\n" ;
	cout << "p1 / i1  :" << (p1 / i1) << "\n" ;
	cout << "p1 * i2  :" << (p1 * i2) << "\n" ;
	cout << "p1 += p2 :" << (p1 += p2) << "\n" ;
	cout << "p1 -= p2 :" << (p1 -= p2) << "\n" ;
	cout << "p1 /= i1 :" << (p1 /= i1) << "\n" ;
	cout << "p1 *= i2 :" << (p1 *= i2) << "\n" ;
	cout << "+(p1)    :" << +(p1) << "\n" ;
	cout << "-(p1)    :" << -(p1) << "\n" ;

	cout << "minore() versione int   :" 
					<< minore(i1,i2) << "\n" ;
	cout << "minore() versione float :" 
					<< minore(f1,f2) << "\n" ;
	cout << "minore() versione 1     :" 
					<< minore(p1,p2) << "\n" ;
	cout << "minore() versione 2     :" 
					<< minore(p1,p3) << "\n" ;
}
/////////////////////////////////////////////////////////////
Se si desidera che una funzione template non sia eseguita per un determinato tipo di dati, basta definire una funzione non template che accetti quel tipo di dato come parametro. 
Per dare un’esempio di come questo avvenga, ci serviremo della classe Frazione, utilizzata come esempio nel paragrafo 3.6 (notate alla linea 002 l’utilizzo del costruttore di inizializzazione che, anche se non definito esplicitamente per la classe Frazione, è stato creato automaticamente dal compilatore).
NOTEMPL.CPP - Esclusione di funzione template
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	NOTEMPL.CPP - Esclusione di funzione template
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
/////////////////////////////////////////////////////////////
class Frazione
{
 private:
		int num ;
		int den ;
 public:

	Frazione(int n, int d = 1) { num = n ; den = d ; }	  	Frazione(double) ;

	operator int () 	{ return num / den ; }			
	operator double()	{ return double(num)/double(den); }	  

	friend ostream& operator << (ostream & os, Frazione f) ; 
	friend istream& operator >> (istream & is, Frazione f) ; 
} ;
/////////////////////////////////////////////////////////////
ostream & operator << (ostream & os, Frazione f)
{
	os << '(' << f.num << ',' << f.den << ')' ;
	return os ;
}
/////////////////////////////////////////////////////////////
istream & operator >> (istream & is, Frazione f)
{
	is >> f.num >> f.den ;				
	return is ;
}
/////////////////////////////////////////////////////////////
Frazione minore(Frazione & left, Frazione & right)
{
 int esito = double(left) > double(right) ;		// 001

	return(esito?Frazione(left):Frazione(right));	// 002
}
/////////////////////////////////////////////////////////////
template<class T> T minore(T a, T b)
{
	return (a < b ) ? a : b ;
}
/////////////////////////////////////////////////////////////
void main()
{
 int 	i1 = 12, i2 = 57 ;
 char     c1 = 'A', c2 = 'Z' ;
 Frazione f1(3, 6), f2(3, 5) ;

    cout << minore(i1, i2) << "\n" ;	// 003
    cout << minore(c1, c2) << "\n" ;	// 004
    cout << minore(f1, f2) << "\n" ;	// 005
}
/////////////////////////////////////////////////////////////
001  Utilizza l’operatore di conversione per determinare la minore delle due frazioni.
002  Utilizzo del costruttore di inizializzazione.
003  Richiama minore template con parametri int.
004  Richiama minore template con parametri char.
005  Richiama minore(Frazione &, Frazione &).
3.8	Template di classi
Ciò che si può fare con le funzioni, è possibile farlo con intere classi. Il codice seguente crea una classe Buffer indipendente dal tipo di dato con cui poi verrà riempita:
CLASTEMP.CPP - Esempio di template di classe
/////////////////////////////////////////////////////////////
//
//	Dal C a Windows - Carlo Simonelli & Claudio Munisso
//
//	CLASTEMP.CPP - Esempio di template di classe
//
/////////////////////////////////////////////////////////////
#include <iostream.h>
/////////////////////////////////////////////////////////////
template <class T>
class Buffer
{
 private:
		T * Area ;                                      // 001
		int Dimensione ;                                // 002
 public:
		Buffer(int dim =  0) ;                          // 003
		~Buffer() ;                                     // 004

		T& operator[] (int n) { return Area[n] ; }	 // 005
} ;
/////////////////////////////////////////////////////////////
template <class T> Buffer<T>::Buffer(int dim)
{
	Area = new T[dim] ;                              // 006
	Dimensione = dim ;                               // 006
}
/////////////////////////////////////////////////////////////
template <class T> Buffer<T>::~Buffer()
{
	delete [] Area ;                                 // 007
}
/////////////////////////////////////////////////////////////
void main()
{
 Buffer<int> b1(5) ;						// 008
 Buffer<double> b2(5) ;						// 009

	for( int n = 0 ; n < 5 ; ++n )                  // 010 
	{
		b1[n] = n ;
		b2[n] = double(n) / 3 ;
	}

	for( n = 0 ; n < 5 ; n++)                       // 011
	{
		cout <<"\nValore di b1[" << n << "]: " << b1[n] ;
		cout <<"\nValore di b2[" << n << "]: " << b2[n] ;
	}
}
/////////////////////////////////////////////////////////////
001  Puntatore al tipo di dati del buffer.
002  Dimensione del buffer.
003  Costruttore della classe.
004  Distruttore.
005  Ridefinizione dell’operatore [].
006  Il costruttore della classe, per prima alloca spazio per un array di dim oggetti, quindi assegna l’indirizzo dell’area di memoria al puntatore Area.
007  Viene eliminato l’array di ogetti allocato dal costruttore.
008  Crea un buffer di int.
009  Crea un buffer di double.
010  Assegna dei valori agli elementi dei buffer...
011  ... e li visualizza.
Come già visto per le  funzioni, anche in questo caso basta una definizione esplicita della classe per un tipo di dato per evitare gli effetti della classe template.
class Buffer<float> { ... } ;


Può aiutarli a non arrendersi e può insegnare loro che non è importante vincere le partite, ma giocare sempre meglio.
Riconoscere gli sbagli che si sono fatti, imparare da essi e cercare di non ripeterli più, partita dopo partita, in una ricerca continua del meglio.
Se si comporteranno così, qualunque sarà il loro lavoro, fosse anche pulire i cessi, sarà comunque Arte.

Data una classe: `umano` si possono ridefinire gli operatori di relazione per capire se un oggetto sia piò o meno ricco o più o meno giovane di un altro, ma sarebbe estremamente complesso scrivere una funzione che permetta di capire se un oggetto sia più o meno amato da un altro.
Nel caso di oggetti che hanno una linea genealogica comune, la funzione potrebbe basarsi, come dice Dawkins, sulla percentuale di DNA che i due oggetti condividono, moltiplicata per il tempo passato insieme, tenendo conto anche di com'è stato quel tempo, ma nel caso di due oggetti che appartengono a genealogie differenti, quale sarebbe l'algoritmo?

Riprendere la genealogia di classi del capitolo precedente ed esaminare la funzione virtuale pura `isGood` nelle sue variazioni: nel caso della classe `Mare`, il risultato è già definito perché lo ha determinato Dio; per le altre classi, non è altrettanto certo.
Ogni categoria ha una sua implementazione di questa funzione, uno specifico criterio di riscontro per determinare ciò che debba essere considerato ben fatto. 
Per alcuni è il pubblico: il droghiere ti chiede di assaggiare le olive, lo scrittore ti fa leggere ciò che ha scritto, l'attore aspetta la risata o l'applauso alla fine della scena.
Per i filosofi è `true` tutto ciò che può essere descritto con le parole; per gli scienziati, tutto ciò che può essere descritto dalla matematica; per gli informatici è `true` tutto quello che può essere descritto dal codice. 

v. Kant citato da Hertha von Dechend nella prefazione tedesca a Il Mulino di Amleto

Le diverse religioni, possono essere delle forme derivate di una stessa mistica iniziale?
Esistono dei "dati membro" e delle funzioni comuni, che siano state ridefinite con il passare del tempo, ma che facciano capo a un corpo di credenze (o di nozioni) iniziale?
Anche solo in questa mappa, se ne trovano diverse (p.es. Empedocle -&gt; Poe).
Così come le classi di un lunguaggio OO sono ridefinite per adattarsi a uno specifico contesto di utilizzo, così pure la Mistica iniziale potrebbe essere stata "overloaded" per adattarsi a uno specifico luogo o tempo.
Se fosse così, tanto più si va indietro nel tempo, e quindi nella gerarchia di classi, tanto più ci si dovrebbe avvicinare alle caratteristiche proprie della Mistica.
E' possibile definire una gerarchia di classi figlie della classe astratta "credo"?(semplificando molto, visto che sono le 3 di notte) Budda e Zoroastro influenzano i greci, che influenzano gli ebrei, che a loro volta infulenzano i cristiani, che alla fine producono i Testimoni di Geova...
Allo stesso modo (sempre semplificando), dal C si è evoluto il C++ e dal C++, Java.Sfortunatamente, però, i (cattivi) programmatori Java hanno fatto alla programmazione quello che i cattolici hanno fatto al cristianesimo.
V. Corano

Quando il programmatore definisce un nuovo tipo di dato per mezzo di una o più classi, può allo stesso tempo istruire le funzioni e gli operatori del linguaggio ad utilizzarlo correttamente.

Noi viviamo prevalentemente sulla terraferma e riteniamo perciò che la normalità sia questa. Se però si trascorre un lungo periodo di tempo su una nave o in un'isola, si ha modo di capire come la normalità sia l'acqua e la terra sia solo un'eccezione.
Similmente, noi diamo grande importanza al ciclo di nascita, riproduzione e morte che chiamiamo "vita" e in essa vediamo il fine ultimo dell'Universo, dimenticandoci che la vita è solo un caso particolare di esistenza e che un universo di sassi sarebbe comunque prodigioso.
Ciascuna forma di vita consociata, per poter sopravvivere, richiede la legittimazione di alcune follie biologiche.
Il rispetto di queste follie, essendo in-naturale, richiede l'istituzione di un livello superiore di costrizione, ovvero un corpo di regole formali ancora più distante del precedente dal comportamento biologico degli esseri viventi.
Con il passare del tempo, molte di queste convenzioni nate in seguito a esigenze contingenti, finiscono inevitabilmente per contrastare con il senso comune di giustizia e devono essere o abolite o modificate, solo che ciascuna modifica o adattamento invece di renderle più "giuste", le allontana ulteriormente dal loro scòpo iniziale e le rende soggette a interpretazioni errate o addirittura opposte a quelle che era il loro fine primario.
Sant'Agostino ha detto la stessa cosa, ma molto meglio di quanto stia facendo io adesso.
Si vede che era sobrio.

La specializzazione come un male.

"La specializzazione va bene per gli insetti" (dove l'ho letto?)

Un tempo, l'uomo virtuoso sapeva fare molte cose, più o meno bene.
Ora se ne sa fare solo una, benissimo.
Si cerca l'eccesso, il continuo superamento del limite.

Lo sport (citare Arlìa?), da attività formativa è diventato una forma di intrattenimento e, come tale, deve essere sempre più spettacolare.
Lo sportivo è visto come un costoso strumento usa e getta.

È però importante che il polimorfismo non dia luogo ad anfibologie.
Non ti dirò cosa vuol dire, cercalo sul vocabolario come ho fatto io.

parlare degli operatori di cast 
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)

-->
