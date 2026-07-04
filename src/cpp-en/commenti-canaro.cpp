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
