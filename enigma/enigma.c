#include <stdio.h>

#define mod(n, m) (((n % m) + m) % m) /* shoutout big C, shoutout stackoverflow, shoutout learning */

#define ROTORFAS "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define ROTORMED "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define ROTORSLO "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define ROTORREF "IXUHFEZDAOMTKQJWNSRLCYPBVG"

#define LETINDEX 'A'
#define NUMCHARS 26

char rapply(char letter, char *rotor) {
        return rotor[letter-LETINDEX];
}

/* Non-cool slow inversion */
char rundo(char letter, char *rotor){
        int i = 0;
        for ( ; i < 26 ; i++){
                /* search for the letter index, add the index to A, get letter :) */
                if (rotor[i] == letter) return i + LETINDEX; 
        }
        return letter;
}

char rotors(char letter) {
        letter = rapply(letter, ROTORFAS);
        letter = rapply(letter, ROTORMED);
        letter = rapply(letter, ROTORSLO);

        letter = rapply(letter, ROTORREF);

        letter = rundo(letter, ROTORSLO);
        letter = rundo(letter, ROTORMED);
        letter = rundo(letter, ROTORFAS);

        return letter;
}

char shiftl(char letter, int n){
        int index = letter - LETINDEX; // get letter pos
        return mod(index + n, NUMCHARS) + LETINDEX; // shift letter according to pos 
}

char shifts(int counter, int n){
        int sarray[7] = {
                counter % NUMCHARS,
                (counter / NUMCHARS) % NUMCHARS,
                (counter / (NUMCHARS * NUMCHARS)) % NUMCHARS,
                0, // reflector does not rotate :exploding_head:
                (counter / (NUMCHARS * NUMCHARS)) % NUMCHARS,
                (counter / NUMCHARS) % NUMCHARS,
                counter % NUMCHARS,
        };
        return sarray[n];
}

int main(int argc, char **argv) {
        printf("%c\n", rapply(argv[1][0], ROTORFAS));
        return 0;
}
