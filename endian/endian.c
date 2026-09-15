#include <stdio.h>
#include <stdint.h>

uint32_t my_htonl(uint32_t n) {
        uint8_t swap, *alias = (uint8_t *)&n;
        size_t index;
        for (index = 0; index < (sizeof(n)/2) ; index++){
                size_t max = sizeof(n)-1;

                swap = alias[index];
                alias[index] = alias[max-index];
                alias[max-index] = swap;
        }
        printf("%x\n", n);
        return n;
}

uint64_t my_htonl64(uint64_t n) {
        uint8_t swap, *alias = (uint8_t *)&n;
        size_t index;
        for (index = 0; index < (sizeof(n)/2) ; index++){
                size_t max = sizeof(n)-1;

                swap = alias[index];
                alias[index] = alias[max-index];
                alias[max-index] = swap;
        }
        printf("%llx\n", n);
        return n;
}

int main(){
        unsigned int test = 0x1234ABCD;
        long long unsigned int testl = 0x11223344AABBCCDDULL; /* ULL tells the compiler that it's 64 bit"*/
        long long unsigned int testl2 = 0x1223344556678990ULL;
        my_htonl(test);
        my_htonl64(testl2);

        return 0;

}
