---
layout:     pagina
class:      articolo
title:      Donne, stampanti laser e altre cause di degrado del software
permalink:  /opt/donne-stampanti-cause-degrado
footer:     true
---

Così come avviene per tutte le opere dell\'Umano Ingegno - libri, musica, film, ecc. - anche il software, in questi tempi bui, sta subendo un degrado qualitativo lento, ma costante.
Tanto per fare due esempî, prima che il profilo utente di Blogger fosse integrato con quello di Google+, non si poteva inserire, come data di nascita, il 29 febbraio di un anno bisestile: il sistema segnalava errore e non permetteva l\'aggiornamento del dato. Come se non bastasse, andando a controllare nell\'elenco dei bug noti, si scopriva che l\'errore era stato segnalato già da tempo, ma la risposta dei programmatori era stata: \"Ah, sì: in effetti, il calcolo degli anni bisestili è un controllo che andrebbe aggiunto alla funzione di verifica della data..\"
L\'empietà di questa affermazione dovrebbe essere chiara a tutti:

- la verifica di una data non può prescindere dal calcolo degli anni bisestili;
per quale motivo, hanno scritto (male) una funzione di verifica della data, quando ce ne sono di già fatte (bene)?
come che sia, al momento che ti segnalano l\'errore, cosa ti costa, di aggiungere le TRE righe di codice necessarie a correggerlo?

```
if (mese == 2) {
    bisestile = (((anno % 4) == 0) && ((anno % 100) != 0) == 0));
    OK = bisestile ? giorno <= 29 : giorno <= 28;
}
```

Un altro esempio, è <span title=\"Lo era quando ho scritto questo articolo..\">la nuova versione</span> di OSX, <em>Mountain Lion</em>: nella maschera di configurazione del proxy, per motivi che sfuggono all\'Umana Comprensione, non è possibile impostare lo stesso valore per TUTTI i protocolli, ma è necessario andare a scrivere le stesse cose in ciascun campo. Come se non bastasse, un programmatore frettoloso o pecione o tutte e due le cose insieme, ha applicato lo stesso metodo di formattazione sia al campo dell\'IP che a quello della porta, che, se superiore a 999, si ritrova perciò un punto prima delle ultime tre cifre:
<p style=\"font-size:10pt;padding:1em;font-family:courier;\">
 <strong>IP: </strong>127.0.0.1 <strong>porta:</strong> 8.080
</p>
Geniale, no? Nella versione 10.8.1, l\'errore c\'è ancora: vediamo quanto ci metteranno a correggerlo..

Le cause di questo progressivo degrado sono molteplici e vanno dalla natura virale del cattivo codice (cfr. <a href=\"http://bit.ly/oFwoMI\" title=\"Codice virale\" target=\"_blank\">http://bit.ly/oFwoMI</a>) alle imposizioni del <em>time-to-market</em>; quelle su cui ci concentreremo qui sono tre: le stampanti laser, le donne e la tradizione orale.

<h3>Le stampanti laser</h3>
Comparse sul mercato nel 1982, un anno dopo l\'uscita del primo Personal Computer IBM, le stampanti laser sono utilissime per segretarie e commerciali, a cui permettono di scrivere lettere eleganti, presentazioni accattivanti e, soprattutto, stampare dolcissime immagini di gattini da appendere alle pareti dell\'ufficio, ma per il programmatori sono il Male, perché non consentono di stampare il codice in una sequenza continua, frammentandolo in una serie di pagine che ne rendono fastidiosa la lettura.
Inoltre, lavorando prevalentemente con fogli in formato A4, larghi solo 217 mm., le stampanti laser hanno la tendenza a mandare a capo le righe più lunghe, rendendo la lettura del codice ancora più complessa. Stando così le cose, è perfettamente naturale che i programmatori non stampino più il loro codice, ma si accontentino di farne il debug a video.
I nuovi paradigmi di programmazione, come la programmazione a oggetti (che ha cominciato a diffondersi dalla metà degli anni \'80: un caso?) compensano questo limite, scomponendo il flusso delle istruzioni in tante piccole funzioni specializzate, ma altri linguaggi meno strutturati, come, per esempio, quelli per la gestione delle basi di dati (SQL, PL/SQL, ecc.) richiedono ancora molto spazio, sia in verticale, che in orizzontale:

<code class=\"articolo\">INSERT INTO utente (
  id
, id_gruppo
, id_classe
, attivo
, e_mail
, username
, nome
, cognome
, recapito
, ts_creazione
, ts_modifica )
SELECT * FROM old_utente WHERE (e_mail NOT IN (SELECT e_mail FROM utente)) AND upper(concat(cognome, nome)) NOT IN (SELECT upper(concat(cognome,nome)) FROM utente);</code>

Nel secolo scorso, prima della diffusione delle stampanti laser, il codice veniva stampato sui moduli in continuo delle stampanti ad aghi, che consentivano diversi benefici:
<ul style=\"width:85%;\">
  <li>il codice poteva essere esaminato nella sua totalità; </li>
  <li>le 132 colonne di larghezza della pagina limitavano il numero degli a-capo;</li>
  <li>la suddivisione del foglio in righe di colore differente facilitava la lettura; </li>
  <li>le fasce laterali, con i buchi per il trascinamento del foglio, potevano essere staccate e arrotolate a mo\' di stella filante, favorendo la concentrazione.</li>
</ul>
Ci si poteva riunire con tutto il gruppo di lavoro, stendere il foglio sul tavolo, aprire una birra (il debug viene meglio, se è bagnato) e leggere, commentare, appuntare. Era, anche, un\'occasione conviviale nella quale i programmatori più anziani potevano trasmettere le loro esperienze ai più giovani. Al giorno d\'oggi, invece, il programmatore corregge il suo codice direttamente nel programma di scrittura. Solo, seduto allo stesso posto che occupa tutto il giorno, lavora in forma ossessiva, pungolato dall\'acronimo <em>ASAP</em> che compare nelle lettere del suo responsabile; splendido esempio della <em>Monade senza finestre</em> di Leibnitz, fa errori che potrebbero essere evitati e quello che impara di nuovo non può condividerlo con nessuno. Ma su questo torneremo in séguito.

<h3>Le donne</h3>
Comparse sul mercato intorno all\'ottavo giorno dalla Creazione, un paio di giorni dopo l\'uscita del primo Uomo, le donne sono state utilizzate per migliaia di anni per la produzione e l\'allevamento dei bambini, attività che ha influenzato significativamente il loro modo di pensare e di comportarsi. Da poco più di cento anni, si è tentato di convertirle anche ad attività produttive (che è cosa ben diversa dalle attività ri-produttive), fra cui, in tempi più o meno recenti, la creazione e l\'utilizzo di software. Questo cambio di destinazione d\'uso, se da un lato ha prodotto effetti mirabili, come, per esempio, Ada Lovelace, Grace Murray Hopper o il mio affascinante capo, nella stragrande maggioranza dei casi si è rivelato controproducente; sia per il processo produttivo, che per le donne.
Pensateci un attimo: per millennî, le donne hanno accudito i bambini della tribù, mentre gli uomini andavano a caccia nei boschi. Se l\'uomo, nei boschi, falliva nel suo lavoro (leggi: non riusciva a catturare una preda), non doveva preoccuparsene più di tanto, perché sapeva perfettamente che c\'erano ancora tante prede disponibili: tempo un\'ora e un nuovo cervo o cinghiale sarebbero certamente comparsi all\'orizzonte.
Al contrario, per la donna, fallire nel suo lavoro (leggi: perdere un bambino) era un evento drammatico, perché significava - anche al di là delle considerazioni di carattere affettivo - perdere tutto il tempo e gli alimenti spesi per allevarlo. Questo condizionamento - durato, lo ripetiamo, decine se non centinaia di migliaia di anni - ha inculcato nelle donne la convinzione che ogni singolo fallimento nel proprio lavoro sia un evento disastroso, da temere come la morte (appunto) e dal quale non c\'è alcuna possibilità di ritorno. D\'altro canto, e paradossalmente, l\'essersi occupate dell\'educazione dei cuccioli le ha rese più tolleranti dell\'uomo nei confronti degli errori dei proprî \"sottoposti\".
Entrambe queste peculiarità caratteriali sono positive per una madre o un\'educatrice, ma risultano dannosissime per una manager, che deve avere una notevole dose di inerzia emotiva nei confronti del proprio lavoro e, allo stesso tempo, deve giudicare con adeguata severità sia gli errori dei suoi collaboratori che quelli dei suoi fornitori. Fino a che le donne hanno avuto un ruolo puramente esecutivo, i loro condizionamenti mentali sono stati positivi per il processo produttivo (si pensi, per esempio, alle cosiddette: \"<a href=\"http://bit.ly/QCBnF2\" title=\"Ragazze dell\'ENIAC\" target=\"_blank\">Ragazze dell\'ENIAC</a>\"), ma al momento in cui le donne, giustamente, hanno cominciato a pretendere e ottenere dei ruoli di potere, le cose hanno cominciato a peggiorare perché, da un lato, la loro benevolenza materna nei confronti dei programmatori li ha resi meno timorosi e quindi più propensi all\'errore, alla dimenticanza o alla trascuratezza; d\'altro canto, la loro innata propensione a conciliare (\"Su, su: datevi un bacetto e fate la pace..\"), le ha rese meno selettive ed esigenti nei confronti dei prodotti utilizzati.
L\'uomo medio non gira con la spia dell\'olio accesa o con una delle gomme sgonfia: va dal meccanico o dal gommista; la donna media, al contrario, non se ne accorge nemmeno e continua a guidare tranquilla fino a che:
<ul style=\"width:85%;\">
  <li>fonde il motore;</li>
  <li>si spalma su un platano; </li>
  <li>il marito o il compagno prende la sua auto e la porta dal meccanico e dal gommista;</li>
  <li>tutte e tre le ipotesi precedenti.</li>
</ul>
Volete un altro esempio, più precìpuo? eccolo qui: nel mio gruppo, ho due maschietti e una femminuccia. Le competenze e l\'esperienza sono tutto sommato simili, ma, mentre i due maschietti, se il loro computer fa le bizze, re-installano il sistema operativo o cambiano direttamente l\'hardware, la femminuccia va avanti ormai da anni con un computer completamente instabile e imprevedibile, non perché sia più pigra - anzi, dei tre, è lei la stacanovista - ma perché il suo retaggio femminile non le fa percepire questa cosa come un problema.

<h3>La tradizione orale</h3>
Fin qui, abbiamo scherzato (tranne che sulle stampanti e sulle donne, ovviamente); il terzo punto del nostro elenco, però è tristemente vero. Come accennavo prima, alla fine del XX secolo, quando con i computer ci lavorava solo chi voleva lavorare con i computer, i programmatori senior trasmettevano le loro esperienze agli junior, aiutandoli a non compiere errori prevedibili. La trasmissione orale delle esperienze fra le varie generazioni di programmatori riduceva i tempi di realizzazione del software, lo rendeva più stabile e faceva sì che ogni nuova generazione fosse, mediamente, un po\' più brava di quella che l\'aveva preceduta. Questo metodo formativo era conveniente anche per i programmatori senior, che potevano sub-appaltare alle nuove leve le attività più banali, dedicandosi ai problemi più complessi o, anche, passare a mansioni di livello superiore. L\'aumento indiscriminato degli operatori informatici, séguito al boom della <em>New-economy</em>, però, ha aumentato la competizione all\'interno della popolazione informatica e la crisi degli ultimi anni ha ridotto le possibilità di crescita all\'interno delle aziende. Al giorno d\'oggi, il programmatore senior non ha più tanta voglia di condividere con gli junior le sue esperienze, perché teme che gli possano rubare il posto o l\'incarico; preferisce piuttosto tenersi per sé la propria esperienza lasciando che gli ultimi arrivati se la cavino da soli. Se sbagliano, tanto meglio: <em>Mors tua, vita mea</em>.
La miopia di questo atteggiamento è tanto più evidente laddove, come spesso accade, questi programmatori \"incolti\" lavorino a commesse statali o para-statali, perché la cattiva qualità del codice da loro prodotto non danneggerà una singola azienda (cosa che sarebbe comunque grave), ma la gestione stessa dello Stato.
Le colpe dei senior, quindi, non ricadranno solo sugli junior, ma su tutti quanti: sul cliente, che avrà un codice non rispondente alle sue esigenze; sui committenti, che dovranno decurtare dai profitti derivanti dalla realizzazione del sistema i costi per la sua correzione, andando spesso in passivo; sugli utenti, che dovranno combattere con sistemi instabili e dis-funzionali; sulle nuove generazioni, che dipenderanno sempre più da sistemi informatici sempre più scadenti.
Infatti, così come un tempo la trasmissione delle esperienze causava una progressiva evoluzione della casta dei programmatori, la mancata trasmissione delle esperienze ne causa oggi un inesorabile regresso.

Finché perdurerà questo stato di cose, potremo anche sostituire tutte le stampanti laser del mondo con delle stampanti ad aghi e relegare le donne a ruoli di second\'ordine, ma non ne verremo fuori comunque. Il software continuerà a peggiorare e, con lui, la qualità della nostra vita. Un bel giorno verrà, ne sono certo, \"il vento che spazzerà via il fango\", ma quando il vento sarà passato, cosa resterà in piedi?
', 'Perché il software funziona sempre peggio?', '', 'publish', 'open', 'open', '', 'principali-cause-del-degrado-della-qualita-del-software', '', '', '2012-09-11 00:00:00', '2012-09-10 22:00:00', '', 0, 'http://blog.canaro.net/?p=70', 0, 'post', '', 0),
