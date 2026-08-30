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

int main(int argc, char **argv) {
        printf("%c\n", rapply(argv[1][0], ROTORFAS));
        return 0;
}
