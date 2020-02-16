# C'hi++ - Un'etica *vendor-independent* per l'intellgenza arificiale

<section class="citazione">
>herefore what you must comply with – you need to determine what you stand for as an organization – what are your brand values? These values should exist whether you use AI or not. You can then define your ethical AI code on the basis of what you stand for. -
<span>Nicolas Economou</span></section>

Abbiamo bisogno di un'etica.
Ne abbiamo bisogno noi e ne ha bisogno il nostro software.
Il problema è che *etica*, così come *amore* e *arte*, è un termine che tutti utilizzano ma che ciascuno può (legittimamente) interpretare a suo modo.
Di fatto, l'etica è una disciplina filosofica, ma per estensione è anche l'oggetto di studio di quella disciplina: uno schema ordinato di valori e di regole che permettono di determinare cosa sia più o meno giusto fare.

In altre parole, comprensibili anche agli adoratori del dio Ferragnez, l'etica è il *dress-code* delle nostre vite e come tutti i *dress-code*, **una determinata etica ha valore solo in determinate condizioni**.
Ciò che è eticamente accettabile in alcuni casi - per esempio uccidere un avversario perché indossa una *divisa di un altro colore*, in guerra -, può non esserlo in altri - per esempio, uccidere un avversario perché indossa una divisa di un altro colore, durante una partita di calcio.
Prendete il primo Articolo della *Déclaration des Droits de l’Homme et du Citoyen* del 1798:

> Les hommes naissent et demeurent libres et égaux en droits. Les distinctions sociales ne peuvent être fondées que sur l’utilité commune.

Questa affermazione, sicuramente condivisibile, non ha prove a conforto e non è valida per chiunque viva in una delle 43 nazioni del Mondo dove vige una monarchia: ovvero una su cinque.

Inoltre, **i valori che costituiscono un'etica sono soggettivi**. 
Questo vale sia per le etiche di natura religiosa che per quelle di natura non religiosa.
Per esempio, la *Declaration of Independence* del 1776 comincia con queste parole:

> We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.

Definire un principio: *self-evident* equivale a dichiarare un dogma: una convinzione che appartiene a chi scrive, ma non si applica necessariamente a tutti gli esseri viventi. La trinità:

> Liberté, Égalité, Fraternité

è dogmatica così come:

> Dio, Patria, Famiglia

Nulla prova che questi valori siano reali o corretti, ci devi credere; e ci credi perché qualcosa o qualcuno ti ha convinto a farlo.
Se consideriamo la notevole disparità di vedute e convinzioni dei Popoli della Terra e, talvolta, degli stessi individui all'interno di un Popolo, è facile capire come la frase:

> AI interactions that consumers and citizens perceive as ethical build trust and satisfaction[^capgemini]

sia ambigua perché ciò che è *percepito* come etico da qualcuno potrebbe non esserlo per altri.

La conseguenza di questa indeterminatezza è che, come dimostrano questi due articoli su [Springer](rd.springer.com), da vent'anni si sta lavorando a del software “sensibile ai valori”, ma ancora non si è riuscito a decidere *quali* debbano essere questi valori.

<img src="../../img/value-sensitive-design.png" style="width:100%;padding:1rem 0;border:solid 1px #999">

Quindi, abbiamo solo due possibilità: o scriviamo del codice specializzato per ciascun tipo di etica o **definiamo un'etica che sia condivisibile dalla maggior parte degli utenti**; una sorta di *dress-code* che sia valido sia a una cena di gala che a un toga party.
Dato poi che è sbagliato ricercare le motivazioni della propria etica all'interno dello schema stesso, negando ogni forma di trascendenza[^spiego], definiremo una metafisica cui fare riferimento, sfruttando le idee che nacquero e si svilupparono nella culla della Civiltà, ovvero gli anni '80.

Buona parte del software, da adesso in poi, avrà due interfacce utente: un'interfaccia grafica, dedicata all'interazione con il sistema sensoriale e un'interfaccia metafisica, dedicata all'interazione con la coscienza[^coscienza].
Per definire un'etica che sia acccettabile dal maggior numero di persone possibile, dobbiamo fare ciò che fecero i creatori delle prime interfacce grafiche: creare una libreria di simboli il cui significato sia chiaro e condiviso da tutti gli utenti.
In sostanza, **abbiamo bisogno di icone**.  
Il sostantivo inglese *file* può tradursi con: documento, ملف (Arabo), 文件 (Cinese), файл (Russo), ファイル (Giapponese), 파일 (Coreano) oppure, più semplicemente, può essere rappresentato con il simbolo:

<p align=center><img src="../../img/file.jpg"></div></p>

Così come la pipa di Magritte, il documento del simbolo non è un documento, ma questo non ha importanza perché ciò che conta, qui, è il significato, non il significante.
Quando l'utente di un sistema di scrittura vede il simbolo *File*, non pensa né che quel documento *sia* quello che vuole scrivere lui né che *non sia* il documento che vuole scrivere lui.
È questo l'atteggiamento che dobbiamo stimolare nei fruitori della nostra etica.
Per riuscirci, dobbiamo operare come i poeti o i disegnatori di fumetti, eliminando dai nostri simboli tutto ciò che è superfluo e lasciando solo ciò che serve a denotare l'oggetto a cui si riferiscono.

<p align=center><img style="margin:auto;display:block" src="../../img/icone.png" ></p>

Pur se complesso, tutto questo è possibile. Spogliate degli orpelli voluti dal Clero e ricondotte alle loro caratteristiche essenziali, le diverse ipotesi metafisiche hanno molti punti in comune perché sono tutte, in una maniera o nell'altra, la risposta a uno stesso bisogno: la ricerca di una giustificazione alla nostra esistenza.

Ma, così come avvenne a Linus Torvaldsen con Linux, dopo qualche anno che lavoravo a un libro dal titolo: **C'hi++ - Il senso della vita è il debug**, capii che era un compito che non potevo svogere da solo.
Perciò misi il progetto su GitHub[^github] e cominciai a scrivere un *Manifesto* per spiegare a dei potenziali collaboratori quali fossero le mie intenzioni. 
Preso atto della mia incapacità di produrre un documento accademico, ho redatto il testo come se fosse un progetto informatico, con un *Executive Summary* e un' *Analisi del sistema attualmente in esercizio* nel quale descrivo il problema che mi propongo di affrontare ed esamino le possibili soluzioni. Ne è derivato un documento di quarantasei pagine: dettagliato, ma decisamente troppo lungo per poter fungere da manifesto del progetto.
L'ho trasformato perciò in [un documento a sé stante](file:///Users/Carlo/Dropbox/Canaro/C'hi++/out/chi-plus-plus-ipotesi-per-una-metafisica-open-source.pdf) e ho cercato di condensare le principali informazioni che conteneva nel file README che compare all'apertura del progetto su GitHub e nel MANIFEST, da cui è tratta buona parte di questo articolo.

Se volete sapere qualcosa di più, il progetto è qui: 

[https://github.com/carlosimonelli/chi-plus-plus] (https://github.com/carlosimonelli/chi-plus-plus) 

Se volete collaborare o anche esporre delle critiche, potere farlo con gli strumenti canonici di [GitHub] (https://github.com).


## Note

[^neruda]: L'originale è: *Quiero hacer contigo lo que la primavera hace con los cerezos*.

[^capgemini]: Rapporto Capgemini: *Why addressing ethical questions in AI will benefit organizations*.

[^spiego]: Spiego perché a pagina 2 del Manifesto.

[^coscienza]: Inteso qui come: *coscienza di sè*.

[^github]: La piattaforma con cui si gestisce la maggior parte del software *open-source*.

