/**********************************************************

#include <iostream.h>

#define ERR_NOFILE 1

int error( int error );
void read_file( char * filename );
void create_matrix(void);
int initialize(void);
void set_probability(void);
void attractor(void);
int close(void);

int main(int argc, char * argv[])
{
    int outcome = 0 ;
    if(argc < 2) {
        outcome = error(ERR_NOFILE);
    } else {
        read_file(argv[1]);
        create_matrix();
        if(initialize()) {
            const char * value = set_probability();
            attractor(value);
            outcome = close();
        }
    }
    return outcome ;
}

***********************************************************/
