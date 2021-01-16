---
status:     bozza
layout:     manuale
class:      capitolo
title:      Algebra booleana
permalink:  /man/algebra-booleana
quote:      "And what is TRUE, Phaedrus,<br />And what is FALSE<br />Need we ask anyone to tell us these things?"
---


<!--
“Il pendolo della mente oscilla tra senso e non senso, non tra giusto e sbagliato.” - Carl Jung-

Ho messo intenzionalmente il capitolo sull'algebra booleana DOPO quello sugli operatori per dimostrare come i concetti di vero/falso giusto/sbagliato debbano essere definiti per prima cosa

Mettere qui tutto quello che attiene all'etica.
@todo: Riprendere i concetti visti nel Manfesto a proposito delle
ideologie dell'ultimo cinquantennio quando si parla di vero e falso

Operatore == “Io vidi il mio Signore con l'occhio del cuore. Gli chiesi: chi sei? Rispose: Te!”.  
'Attar, Farid al-din. Il verbo degli uccelli (Mantiq al-Tayr) 

### operatore di negazione

la negazione e il paradosso come metodo per comprendere ciò che non è
di per sé evidente

Parlare del male che diventa bene, fare esempio dell'idiota che ha sparat un razzo nel locale  di Ginevra dandogli fuoco, ma causando la composizione di Smoke on the water.
O della stronza di Ipanema, che ha reso ricco Jobim

-->



È impossibile definire in maniera assoluta i concetti di *vero* e di
*falso*, se non facendo riferimento a sistemi di ordine superiore.

Possiamo definire "falso" il contrario di "vero", ma non potendo
definire il concetto di "vero", non possiamo sapere cosa sia il suo
contrario.
La ragione per cui non possiamo definire il concetto di "vero" è che
farlo implica una ricorsione: quale che sia la definizione prescelta,
prima di poterla prendere per buona dovremo poterla considerare vera, ma
ciò è impossibile perché non sappiamo (ancora) cosa sia, effettivamente,
"vero".

Tutto ciò non vuol dire che non esistano il vero e il falso, ma solo che
i nostri strumenti dialettici sono inadeguati a descriverli.

Bertrand Russell disse che la condizione di “vero” o di “falso” è uno stato dell'organismo, determinato da condizioni esterne all'organismo. Questo è vero anche per i computer: “vero” e “falso” sono stati possibili per un'istruzione e dipendono per lo più da cause esterne all'istruzione stessa. La cosa interessante, in questo caso, è che “vero” e “falso” sono anche delle convenzioni che esulano del tutto dal contesto specifico del sistema. Per Access, “falso” è -1; per le prime versioni di MySQL è 'f'; per Postgres o Oracle, è 0. Il computer, però, non ha IN SE' il concetto di “vero” o di “falso”, ma solo l'associazione del valore booleano *false* a una determinata sequenza di bit. Il concetto di “vero” e di “falso”, quindi, è un valore simbolico che NOI inseriamo nella logica del computer, traducendo nel suo linguaggio un concetto che è propio del nostro mondo. 

Da questo punto di vista, potremmo essere d'accordo con William James, quando dice che un'idea è "vera" fintanto che credere in essa è utile per le nostre vite. 
