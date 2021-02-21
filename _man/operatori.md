---
status:     redazione
layout:     manuale
class:      capitolo
title:      Gli operatori
permalink:  /man/operatori
quote:      "And what is TRUE, Phaedrus,<br />And what is FALSE<br />Need we ask anyone to tell us these things?"
---

La varietà e soprattutto l'adattabilità degli operatori sono la caratteristica principale del C++.  
Gli operatori sono degli elementi del linguaggio che permettono, appunto, di *operare* delle azioni sulle variabili o sui valori. 
Li possiamo classificare o in base al numero di operandi su cui agiscono:

- primarii
- unarii
- binarii 
- ternarii 

o in base al tipo di operazione che compiono:

- aritmetici
- logici
- di relazione
- bitwise
- assegnazione

 Gli operatori *aritmetici* sono:
 
 | nome  | descrizione  | esempio  |
 |:-:|:-:|:-:|
 | +   | addizione       | x + y |
 | -   | sottrazione     | x - y |
 | \*  | moltiplicazione | x * y |
 | \\  | divisione       | x / y |
 | %   | modulo          | x % y |
 | ++  | incremento      | x++   |
 | --  | decrementi      | y--   |

 Gli operatori *logici* sono:
 
 | nome  | descrizione  | esempio  |
 |:-:|:-:|:-:|
 | &&   | AND logico    | x && y |
 | \|\| | OR logico     | x \|\| y |
 | !    | NOT logico    | !(x && y) |
  

<hr id="dottrina">


È impossibile definire in maniera assoluta i concetti di *vero* e di *falso*, se non facendo riferimento a sistemi di ordine superiore.

Possiamo definire "falso" il contrario di "vero", ma non potendo definire il concetto di "vero", non possiamo sapere cosa sia il suo contrario.
La ragione per cui non possiamo definire il concetto di "vero" è che farlo implica una ricorsione: quale che sia la definizione prescelta prima di poterla prendere per buona dovremo poterla considerare vera, ma ciò è impossibile perché non sappiamo (ancora) cosa sia, effettivamente, "vero".  
Bertrand Russell disse che la condizione di “vero” o di “falso” è uno stato dell'organismo, determinato da condizioni esterne all'organismo. Questo è vero anche per i computer: “vero” e “falso” sono stati possibili per un'istruzione e dipendono per lo più da cause esterne all'istruzione stessa. La cosa interessante, in questo caso, è che “vero” e “falso” sono anche delle convenzioni che esulano del tutto dal contesto specifico del sistema. Per Access, “falso” è -1; per le prime versioni di MySQL è 'f'; per Postgres o Oracle, è 0. Il computer, però, non ha IN SE' il concetto di “vero” o di “falso”, ma solo l'associazione del valore booleano *false* a una determinata sequenza di bit. Il concetto di “vero” e di “falso”, quindi, è un valore simbolico che NOI inseriamo nella logica del computer, traducendo nel suo linguaggio un concetto che è propio del nostro mondo.   

Se tu mi chiedi perché non si debba uccidere un uomo, ti risponderò che uccidere è sbagliato perché tutto il male che fai, lo stai facendo a te stesso; penso che sia così   perché me lo ha insegnato il Maestro Canaro, che aveva visto il codice del programma dell'Universo.
Se in vece lo chiedi a un cristiano o a un ebreo, lui ti risponderà che è vietato dai Dieci Comandamenti che Dio ha dato a Mosé; lo sa per certo perché è scritto nella Bibbia, che è la Parola di Dio.
Se infine lo chiedi a un paladino del laicismo, ti risponderà che l'omicidio, per il nostro ordinamento giuridico, è un reato; ciò dev'essere vero, perché le nostre Leggi applicano i concetti espressi nella nostra Costituzione la quale, a sua volta, si rifà ai principii di liberà e uguaglianza della *Dichiarazione dei Diritti dell’Uomo e del Cittadino* francese, che a sua volta si rifaceva alla *Dichiarazione di Indipendenza* americana, che a sua volta riprendeva le idee di Locke, Montesquieu<a href="/man/note#jefferson" class="nota"></a>  c.  
Nessuna di queste affermazioni è valida di per sé: sono tutte fondate su una qualche forma di fede &mdash; religiosa o laica che sia &mdash; in chi ha promulgato la Legge o il principio.
Sfortunatamente, però, queste persone sono state anche le prime a non tenerne conto: Mosé, con i Comandamenti ancora freschi di stampa, chiese ai figli di Levi: 

> Ognuno di voi si metta la spada al fianco; percorrete l’accampamento da una porta all’altra di esso, e ciascuno uccida il fratello, ciascuno l’amico, ciascuno il vicino!<a href="/man/note#levi" class="nota"></a> 

Gli Americani, che scrissero:

> We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.

commerciavano in schiavi e hanno sterminato i Nativi Americani per rubar loro le terre.
I Francesi, il cui motto era:

> Liberté, Égalité, Fraternité

hanno applicato questi principii a colpi di ghigliottina.
L'ONU, che nel 1948 ha pubblicato la *Dichiarazione Universale dei Diritti Umani* e che ha come motto la frase: 

> Peace, dignity and equality on a healthy planet.

ha al suo vertice dei Paesi che sono i principali produttori di armi del Mondo<a href="/man/note#armi" class="nota"></a>  e che violano costantemente quelle stesse regole da loro promosse.     
Attenzione, però: il fatto che i principii laici di pace, uguaglianza e libertà derivino, in ultima analisi dalle convinzioni<a href="/man/note#self-evident" class="nota"></a> di un gruppo di credenti<a href="/man/note#credenti" class="nota"></a>, non vuol dire siano sbagliati, ma che non gli si può attribuire nessuna veridicità oggettiva. Dobbiamo accettarli per fede, così come i dogmi religiosi.



<!--

| **aritmetici**   | `+` `-` `*` `/` `%` `++` `--` |
| **logici**       | `&&` `||` `!`  |
| **relazione**    | `==` `!=` `<` `>` `<=` `>=` |
| **bitwise**      | `&` `|` `^` `~` `<<`  `>>` |
| **assegnazione** | `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=` `^=` `>>=` `<<=`  |

Da questo punto di vista, potremmo essere d'accordo con William James, quando dice che un'idea è "vera" fintanto che credere in essa è utile per le nostre vite. 

“Il pendolo della mente oscilla tra senso e non senso, non tra giusto e sbagliato.” - Carl Jung-

Ho messo intenzionalmente il capitolo sull'algebra booleana DOPO quello sugli operatori per dimostrare come i concetti di vero/falso giusto/sbagliato debbano essere definiti per prima cosa

Mettere qui tutto quello che attiene all'etica.

@todo: Riprendere i concetti visti nel Manfesto a proposito delle ideologie dell'ultimo cinquantennio quando si parla di vero e falso

Operatore == “Io vidi il mio Signore con l'occhio del cuore. Gli chiesi: chi sei? Rispose: Te!”.  
'Attar, Farid al-din. Il verbo degli uccelli (Mantiq al-Tayr) 

### operatore di negazione

la negazione e il paradosso come metodo per comprendere ciò che non è di per sé evidente

Parlare del male che diventa bene, fare esempio dell'idiota che ha sparat un razzo nel locale  di Ginevra dandogli fuoco, ma causando la composizione di Smoke on the water.
O della stronza di Ipanema, che ha reso ricco Jobim

La Dichiarazione di Indipendenza americana, che è la base  comincia con queste parole:

    We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.

Nella Lettera agli artisti, Giovanni Paolo II utilizza i termini \'buono\' e \'bello\', ma li definisce in maniera ricorsiva, l\'uno in funzione dell\'altro. 

> La bellezza è in un certo senso l'espressione visibile del bene, come il bene è la condizione metafisica della bellezza.

Stesso discorso per il concetto di \'Arte\'
Bizzarro, perché la stessa cosa avviene, in condizioni diametralmente opposte, in "Un'etica senza Dio" di Lecaldano, dove ci si appella a concetti di 'buono' e 'giusto' senza definirli.

Differenza con i manuali SW (in cui i termini utilizzati sono tutti definiti) e le le classi C++

Nota 7 (S.Gregorio++)

Tutto ciò non vuol dire che non esistano il vero e il falso, ma solo che i nostri strumenti dialettici sono inadeguati a descriverli.


-->
