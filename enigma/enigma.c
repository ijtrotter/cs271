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

char shift_letter(char letter, int n){
		int index = letter - LETINDEX; // get letter pos
		return mod(index + n, NUMCHARS) + LETINDEX; // shift letter according to pos 
}

char rotor_map(char letter, int offset, char *rotor) { // offset here is how much the rotor is rotated
		letter = shift_letter(letter, offset); // go through turned rotor
		letter = rapply(letter, rotor); // apply the cipher
		letter = shift_letter(letter, -offset); // exit rotor

		return letter;
}

char rotor_map_inv(char letter, int offset, char *rotor) { //..the inverse
		letter = shift_letter(letter, offset);
		letter = rundo(letter, rotor);
		letter = shift_letter(letter, -offset);

		return letter;
}

char encrypt_letter(char letter, int counter) {
		int shiftfas = counter % NUMCHARS; // how much the rotor rotates based on number of characters passed through
		int shiftmed = (counter / NUMCHARS) % NUMCHARS;
		int shiftslo = (counter / (NUMCHARS * NUMCHARS)) % NUMCHARS;

		letter = rotor_map(letter, shiftfas, ROTORFAS);
		letter = rotor_map(letter, shiftmed, ROTORMED);
		letter = rotor_map(letter, shiftslo, ROTORSLO);

		letter = rotor_map(letter, 0, ROTORREF); // reflector does not rotate :exploding_head:

		letter = rotor_map_inv(letter, shiftslo, ROTORSLO);
		letter = rotor_map_inv(letter, shiftmed, ROTORMED);
		letter = rotor_map_inv(letter, shiftfas, ROTORFAS);

		return letter;
}

void *enigma(char *input) {
	int i = 0;
	for ( ; input[i] ; i++ ){
		printf("%c", encrypt_letter(input[i], i+1)); // i+1 because enigma starts with one rotation
	}
	printf("\n");
}

int main(int argc, char **argv) {
	enigma(argv[1]);
	return 0;
}
