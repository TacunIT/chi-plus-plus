---
status:     redazione
layout:     manuale
class:      capitolo
title:      Le funzioni
permalink:  /man/funzioni
quote:      "Call me: IsNull"
---

Le funzioni sono la caratteristica principale del C++.

Lo scopo delle funzioni è di migliorare la gestione del codice.
È possibile scrivere un programma che abbia solo la funzione `main`, ma questo ha un senso solo per programmi molto semplici, come alcuni degli esempii che abbiamo visto finora.
Il flusso di un programma *non banale*, come direbbe Stroutsup, sarà sempre suddiviso in più funzioni perché in questo modo il codice sarà più facile da leggere, da correggere e da modificare.  


```
{% include_relative src/tipi-di-dato-dimensione.cpp %}
```

Questo è il codice di un esempio che abbiamo visto nel capitolo sui <a href="/man/tipi-di-dato">tipi di dato</a>.
Se decidessimo di modificare il modo in cui il programma mostra i dati all'utente, dovremmo intervenire su tutte le righe del programma, cosa che sarebbe noiosa e potrebbe generare degli errori.
Al contrario, se isoliamo la funzione di visualizzazione, eventuali modifiche o correzioni dovranno essere applicate solo in un punto.
Il codice qui sotto è un esempio, perfettibile, di questo approccio:

```
{% include_relative src/tipi-di-dato-limiti.cpp %}
```
Ogni volta che nel tuo codice ci sono delle istruzioni che si ripetono, valuta la possibilità di isolarle in una funzione.
Per esempio, nella funzione `main` del programma qui sopra ci sono delle funzioni di output che si ripetono, cosa che complica la lettura del codice, ne rende più lunga e laboriosa la modifica e aumenta la probabilità di fare degli errori, perché sei tu che definisci la stringa con il nome del tipo di dato e devi fare attenzione a scrivere il valore giusto ogni volta:

```
cout << setw(16) << "int: "; 
...
cout << setw(16) << "unsigned int: "; 
...
cout << setw(16) << "short int: "; 
...
cout << setw(16) << "unsigned short: "; 
...
cout << setw(16) << "long int: "; 
...
cout << setw(16) << "unsigned long: "; 
```

Nel caso specifico, si trattava di una scelta inevitabile perché, essendo uno dei primi esempii che ti ho fatto, non volevo complicarti troppo le idee, ma non è questo il modo corretto di scrivere codice.
È sbagliato (o, quanto meno, rischioso) mischiare elaborazione dei dati e funzioni di interfaccia, specie in questo caso, dove parte dell'output è già demandato a una funzione specifica.
Meglio lasciare che sia la funzione `dimensione` a gestire tutto l'output, mentre la funzione `main` si limiterà a definire il flusso dell'elaborazione, richiamando la funzione di output per i tipi di dato che ci interessano:

```
{% include_relative src/funzioni-limiti-modificato.cpp %}
```

L'istruzione: 

``` 
abi::__cxa_demangle(typeid(T).name(), NULL, NULL, NULL);
```

mostra il tipo di dato della variabile corrente.
Per il momento, accettala in maniera dogmatica; ti spiegherò il comportamento dell'operatore `::` quando parleremo delle classi.  
L'output di questo codice è identico a quello dell'esempio precedente; anzi: è un po' meglio, perché ho ridotto la spaziatura della prima colonna da 16 a 14 caratteri e l'ho fatto modificando solo un'istruzione `setw(14)`, contro le sei del codice precedente:

```
% g++ src/cpp/funzioni-limiti-modificato.cpp -o src/out/esempio
% src/out/esempio                                              
           int: 4 bytes, da:          -2147483648  a:           2147483647
         short: 2 bytes, da:               -32768  a:                32767
unsigned short: 2 bytes, da:                    0  a:                65535
          long: 8 bytes, da: -9223372036854775808  a:  9223372036854775807
 unsigned long: 8 bytes, da:                    0  a: 18446744073709551615
```

---

Le funzioni sono uno dei <a href="/man/tipi-di-dato#funzioni">tipi di dato</a> del C++ e, come tutti i tipi di dato, possono essere *dichiarate* e *definite*.  
La <a id="dichiarazione">dichiarazione</a> di una funzione stabilisce il suo tipo di ritorno e i parametri richiesti in input:

```
float scorporaIVA(long stipendio, float aliquota);
```

La <a id="definizione">definizione</a> di una funzione, ne stabilisce il comportamento:

```
float scorporaIVA(long stipendio, float aliquota)
{
    float valore;
    valore = stipendio / ((100 + aliquota) / 100);
    return valore;
}
```

Come ti ho detto quando abbiamo parlato dei <a href="/man/linguaggi-di-programmazione">linguaggi di programmazione</a>, la generazione di un file eseguibile avviene in due fasi: per prima cosa il compilatore converte il codice in un *file oggetto*, poi il *linker* trasforma il o <i>i</i> file oggetto (potrebbero essere più d'uno) in un unico eseguibile. 
Perché questo processo possa funzionare, la *dichiarazione* di una funzione deve essere presente in tutti i brani di codice che la utilizzano, per consentire al compilatore di controllare che l'utilizzo che se ne fa sia corretto; la *definizione*, al contrario, deve comparire solo una volta.  

```
{% include_relative src/funzioni-stipendio-main.cpp %}
```

```
{% include_relative src/funzioni-stipendio-funz.cpp %}
```
Se compiliamo separatamente i due file qui sopra aggiungendo il parametro `-c`, che dice al compilatore di generare solo il file oggetto, senza richiamare il linker per la generazione di un eseguibile:

```
% g++ -c src/cpp/funzioni-stipendio-main.cpp -o src/out/main.o
% g++ -c src/cpp/funzioni-stipendio-funz.cpp -o src/out/funz.o
```
e poi generiamo un file eseguibile utilizzando i due file oggetto:

```
% g++ -o src/out/esempio src/out/main.o src/out/funz.o        
```
otterremo tre file, due *object-file* e il file eseguibile `esempio`, che darà il risultato atteso:

```
% ls -1 src/out                                               
esempio
funz.o
main.o

% src/out/esempio                                             
3000
```

Ma siccome io sono pigro, negli esempii che ti farò utilizzerò sempre un comando unico per la compilazione e il *linking* dei programmi:

```
g++ src/cpp/funzioni-stipendio-funz.cpp  \                                                       
    src/cpp/funzioni-stipendio-main.cpp  \
    -o src/out/esempio
% src/out/esempio                                                                                 
3000
```

Se non dichiarassimo la funzione `raddoppiaStipendio` nel file che contiene la funzione `main`, il compilatore ci darebbe l'errore:

```
src/cpp/funzioni-stipendio-main.cpp:19:18: error: use of undeclared identifier 'raddoppiaStipendio'
    std::cout << raddoppiaStipendio(1500) << std::endl;                     ^
1 error generated.
```

Otterremmo lo stesso errore se definissimo una funzione dopo che un altra parte del programma l'ha richiamata:

```
{% include_relative src/funzioni-stipendio-errore.cpp %}
```

```
g++ -c src/cpp/funzioni-stipendio errore.cpp                                                    

src/cpp/funzioni-stipendio-errore.cpp:13:18: error: use of undeclared identifier 'raddoppiaStipendio'
    std::cout << raddoppiaStipendio(1500) << std::endl;    
                 ^
1 error generated.

```

Quando si scrive un programma in un unico file sorgente, o si definiscono le diverse funzioni prima che vengano utilizzate, mettendo la funzione `main` in fondo, oppure le si deve dichiarare all'inizio del file. 
(In realtà, non occorre metterle tutte all'inizio del file, basta che la dichiarazione preceda l'utilizzo, ma è più scomodo: mettile all'inizio.)  
Avresti ottenuto un errore di compilazione anche se avessi provato a separare in due file distinti la funzione `main` e la funzione `dimensione` dell'esempio qui sopra, anche se avessi dichiarato `dimensione` prima del suo utilizzo nella funzione `main`:

```
% g++ src/cpp/funzioni-limiti-main.cpp -c -o src/out/main.o         
src/cpp/funzioni-limiti-main.cpp:19:5: error: use of undeclared identifier 'dimensione'
    dimensione<int>();
    ^
src/cpp/funzioni-limiti-main.cpp:19:19: error: expected '(' for function-style cast or type construction
    dimensione<int>();
               ~~~^
src/cpp/funzioni-limiti-main.cpp:19:21: error: expected expression
    dimensione<int>();
                    ^
src/cpp/funzioni-limiti-main.cpp:20:5: error: use of undeclared identifier 'dimensione'
    dimensione<short int>();
    ^
src/cpp/funzioni-limiti-main.cpp:20:22: error: expected '(' for function-style cast or type construction
    dimensione<short int>();
               ~~~~~ ^
src/cpp/funzioni-limiti-main.cpp:21:5: error: use of undeclared identifier 'dimensione'
    dimensione<unsigned short>();
    ^
src/cpp/funzioni-limiti-main.cpp:21:25: error: expected '(' for function-style cast or type construction
    dimensione<unsigned short>();
               ~~~~~~~~ ^
src/cpp/funzioni-limiti-main.cpp:22:5: error: use of undeclared identifier 'dimensione'
    dimensione<long int>();
    ^
src/cpp/funzioni-limiti-main.cpp:22:21: error: expected '(' for function-style cast or type construction
    dimensione<long int>();
               ~~~~ ^
src/cpp/funzioni-limiti-main.cpp:23:5: error: use of undeclared identifier 'dimensione'
    dimensione<unsigned long>();
    ^
src/cpp/funzioni-limiti-main.cpp:23:25: error: expected '(' for function-style cast or type construction
    dimensione<unsigned long>();
               ~~~~~~~~ ^
```

Questo avviene perché i `template` non sono vere funzioni, ma solo degli schemi che il compilatore utilizza per generare la versione corretta del codice.
La dichiarazione delle funzioni template, quindi deve comprendere anche la loro definizione, per dare modo al compilatore di gestire appropriatamente la chiamata<a class="nota" href="/man/note#template"></a>.


<!-- ------------------------------

Spiegare COME fare a capire quale sia il proprio ruolo nell'Universo.
Non posso metterlo nel capitolo sulla memoria che è già stracolmo.

C’è una frase bellissima in un libro sulla vita dello spadaccino Myamoto Musashi: 

>Non bisogna interferire nel funzionamento dell’Universo,  
 ma prima è necessario capire quale sia,
    il funzionamento dell’Universo

Utilizzare la definizione delle funzioni senza dichiarazione come esempio per i dogmi.
?? Questo concetto verrà riutilizzato nel capitolo sulle funzioni ricorsive a proposito dei Post-It.

“Non esiste distinzione fra un essere, la sua funzione e il tempo della sua apparizione.
Gli esseri appaiono dalla non-esistenza, esistono per un istante e poi cessano di esistere.
La loro esistenza, attività e azione sono un'unica cosa.
Passato e futuro sono meri nomi.”
Samyutta Nikaya, citato da Ananda, Tempo ed Eternità, pag. 45






<a id="inline" 
   onclick="history.back()" 
   title="fare click per tornare alla pagina precedente">funzioni inline</a>


Funzioni ricorsive
------------------

Nella Lettera agli artisti, Giovanni Paolo II utilizza i termini
\'buono\' e \'bello\', ma li definisce in maniera ricorsiva, l\'uno in
funzione dell\'altro. Stesso discorso per il concetto di \'Arte\'

Bizzarro, perché la stessa cosa avviene, in condizioni diametralmente
opposte, in "Un'etica senza Dio" di Lecaldano, dove ci si appella a
concetti di 'buono' e 'giusto' senza definirli.

Differenza con i manuali SW (in cui i termini utilizzati sono tutti
definiti) e le le classi C++

Nota 7 (S.Gregorio++)


-->
