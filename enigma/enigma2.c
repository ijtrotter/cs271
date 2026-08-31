#include <stdio.h>

#define mod(n, m) (((n % m) + m) % m) /* shoutout big C, shoutout stackoverflow, shoutout learning */

#define ROTORFAS "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define ROTORMED "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define ROTORSLO "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define ROTORREF "IXUHFEZDAOMTKQJWNSRLCYPBVG"
#define ROTORFAS_INV "TAGBPCSDQEUFVNZHYIXJWLRKOM"
#define ROTORMED_INV "AJPCZWRLFBDKOTYUQGENHXMIVS"
#define ROTORSLO_INV "UWYGADFPVZBECKMTHXSLRINQOJ"

#define LETINDEX 'A'
#define NUMCHARS 26

char *rarray[7] = { // definitely want to change this or the definitions
        ROTORFAS,
        ROTORMED,
        ROTORSLO,
        ROTORREF,
        ROTORSLO_INV,
        ROTORMED_INV,
        ROTORFAS_INV
};

char rapply(char letter, char *rotor) {
        return rotor[letter-LETINDEX];
}

char shift_letter(char letter, int n){
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

char rotor_map(char letter, int n, char *rotor) { // n here is how much the rotor is rotated..not sure what to name this
        letter = shift_letter(letter, n); // go through turned rotor
        letter = rapply(letter, rotor); // apply the cipher
        letter = shift_letter(letter, -n); // exit rotor

        return letter;
}

char encrypt_letter(char letter, int counter) {
        int i = 0;
        for ( ; i < 7  ; i++){
                letter = rotor_map(letter,shifts(counter, i), rarray[i]); // put a letter in all 7 rotors according to how much shift they have
        }
        return letter;
}

char *enigma(char *input) {
        int i = 0;
        for ( ; input[i] ; i++ ){
                printf("%c", encrypt_letter(input[i], i+1)); // i+1 because enigma starts with one rotation
        }
        printf("\n");
}


int main(int argc, char **argv) {
        char *code = "MNBOASVTTB";

        printf("%c\n", encrypt_letter('A', 1));
        printf("%c\n", encrypt_letter('Z', 1));
        printf("%c\n", encrypt_letter('M', 1));
        printf("%c\n", enigma(code));
        return 0;
}