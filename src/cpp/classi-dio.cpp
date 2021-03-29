/** 
 * @file classi-dio.cpp
 * Dichiarazione della classe Dio.
 */
 
#include <iostream>

using namespace std;

// Classe astratta da utilizzare come base
// per tutti gli elementi del Creato.
class Creatura {
public:
   // Funzione virtuale pura di verifica.
   virtual bool isGood() = 0;
   
};

// Classi derivate per la gestione degli 
// elementi del Creato.
class Mare   : public Creatura {
    bool isGood() { return true; }; 
};
class Uomo   : public Creatura { 
    bool isGood(); 
};
class Donna  : public Creatura {};
class Padre  : public Uomo     {};
class Figlio : public Uomo     {};
class Popolo : public Creatura {};

class  {
private:

    // Funzioni membro per la generazione degli elementi 
    // del Creato, accessibili solo alla classe. 
    Creatura* creaLuce();
    Creatura* creaStelle();
    Creatura* creaAcquaTerra();
    Creatura* creaPiante();
    Creatura* creaSoleLuna();
    Creatura* creaAnimali();

    // Funzioni per la generazione degli umani.
    Uomo&  creaUomo();
    Donna& creaDonna(Uomo& adamo);

    // Interruzione per il settimo giorno.
    void shabat();
    
    // Funzioni di interfaccia con gli umani.
    bool scacciaDaEden(Uomo& adamp, Donna& eva);
    bool printComandamenti(ostream& tavole);
    bool checkFede(Padre& abramo, Figlio& isacco);
    bool splitAcque(Mare& marRosso, Popolo& ebrei);

private:
    
    // Funzione membro accessibile anche alle 
    // classi figlio.
    bool donaVita(Uomo& lazzaro);
    
public:

     // Funzione membro pubblica.
     // Torna il numero di preghiere da recitare.
    int rimettiPeccati(Creatura* fedele) { return 0;};
                   
} Dio;
