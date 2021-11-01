---
layout:   log
title:    "Citazioni con nota"
tags:     [redazione, Jekyll]
---

Ho trovato un modo astuto di inserire le citazioni all'interno del testo *insieme* al link per le note.

Tutte le citazioni sono contenute in uno o più file della directory: `_data`.
La struttura del file yml è:
<br />  
```
<autore/testo>:
    <etichetta>: "<testo-citazione>.<a href="<url>" class="nota"></a>"
```

In questo modo, posso spostare facilmente una citazione da un capitolo a un altro e posso tenere sotto controllo gli ID delle citazioni perché sono tutti nello stesso file.

Una suddivisione ancora più strutturata potrebbe essere:

```
<autore>:
    origine: 
        titolo: "<titolo>"
        editore: "<nome editore>"
        anno: "<anno publicazione>"
        uri: "<uri del sito Web>"
    citazioni:
        <etichetta>: "<testo-citazione>.<a href="<url>" class="nota"></a>"
```
