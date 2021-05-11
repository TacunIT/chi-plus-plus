/** 
 * @file ereditarieta-accesso.cpp
 * Accesso ai membri della classe base dalle classi derivate.
 */
 
/** Classe base, dati membro pubblici */ 
struct Mamma { 
    int a;
};

/** Classe derivata come struct: dati per default pubblici */
struct Figlia : Mamma {
    int b;
};

/** Classe derivata come class: dati per default privati */
class Figlio : Mamma {
    int c;
};

/** Funzione generica, non friend delle classi */
void funz(Figlia& figlia, Figlio& figlio)
{
    figlia.a++;
    figlio.a++;    
}
