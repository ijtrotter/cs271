#include <stdio.h>

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

int main(int argc, char **argv) {
        printf("%c\n", rapply(argv[1][0], ROTORFAS));
        return 0;
}
