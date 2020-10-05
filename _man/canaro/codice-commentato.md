Una volta, il maestro Canaro mostrò ai suoi allievi un brano di codice e gli chiese di spiegare che cosa facesse:

```
/**********************************************************
 
#include <iostream.h>

#define ERR_NOFILE 1

int errore( int errore );
void leggi_file( char * nomefile );
void crea_matrice(void);
int inizializza(void);
void imposta_probabilita(void);
void attrattore(void);
int chiudi(void);

int main(int argc, char * argv[])
{
    int esito = 0 ;
    if(argc < 2) {
        esito = errore(ERR_NOFILE);
    } else {
        leggi_file(argv[1]);
        crea_matrice();
        if(inizializza()) {
            const char * valore = imposta_probabilita();
            attrattore(valore);
            esito = chiudi();
        }
    }
    return esito ;
}

***********************************************************/
```

Gli allievi studiarono il codice e diedero le loro risposte, ma sbagliarono tutti, perché tutte le istruzioni erano comprese fra un `/*` e un `*/` e non venivano compilate.
