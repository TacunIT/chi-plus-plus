/** 
 * @file funzioni-errore-compilazione.cpp
 * Esempio che genera un errore di compilazione.
 */

float scorporaIVA(long stipendio, float aliquota)
{
    float valore;
    valore = stipendio / ((100 + aliquota) / 100);
    return valore;
}

int main(int argc, char** argv)
{    
    /** Utilizzo corretto */
    long  stipendio_1 = 15000;
    float aliquota_1  = 22;
    float iva = scorporaIVA(stipendio_1, aliquota_1);

    /** Utilizzo errato: errore di compilazione */
    int stipendio_2  = 15000;
    const char* aliquota_2 = "22";
    iva = scorporaIVA(stipendio_2, aliquota_2);

    return 0;
}
