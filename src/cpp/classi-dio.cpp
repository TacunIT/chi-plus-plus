/** 
 * @file classi-dio.cpp
 * Dichiarazione della classe Dio.
 */
 
#include <iostream>

using namespace std;

class  {
public:
    
    /**
     *  Classe astratta da utilizzare come base
     *  per tutti gli elementi del Creato.
     */
    class Creatura {
        
        /** Funzione virtuale pura di verifica */
        virtual bool isGood() = 0;
    };
    
    /**
     *  Classi derivate per la gestione degli 
     *  elementi del Creato.
     */ 
    class Mare   : public Creatura {};
    class Uomo   : public Creatura {};
    class Donna  : public Creatura {};
    class Padre  : public Uomo {};
    class Figlio : public Uomo {};
    class Popolo : public Creatura {};
    
private:

    /** 
     * Funzioni membro per la generazione degli elementi 
     * del Creato, accessibili solo alla classe. 
     */
    Creatura* creaLuce();
    Creatura* creaStelle();
    Creatura* creaAcquaTerra();
    Creatura* creaPiante();
    Creatura* creaSoleLuna();
    Creatura* creaAnimali();

    /** Funzioni per la generazione degli umani */
    Uomo&  creaUomo();
    Donna& creaDonna(Uomo& adamo);

    /** Interruzione per il settimo giorno */
    void shabat();
    
    /** Funzioni di interfaccia con gli umani */
    bool scacciaDaEden(Uomo& adamp, Donna& eva);
    bool printComandamenti(ostream& tavole);
    bool checkFede(Padre& abramo, Figlio& isacco);
    bool splitAcque(Mare& marRosso, Popolo& ebrei);

private:
    
    /** 
     * Funzioni membro accessibili anche alle 
     * classi figlio.
     */
    bool donaVita(Uomo& lazzaro);
    
public:

    /** 
     * Funzione statica, accessibile tramite la classe.
     * Torna il numero di preghiere da recitare.
     */   
    static int rimettiPeccati(Creatura& fedele);
                   
} Dio;
