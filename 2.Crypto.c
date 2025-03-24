#include <stdio.h>
#include <stdlib.h>

#define L1_SIZE 19
#define L2_SIZE 22
#define L3_SIZE 23

void LFSR(int L1[], int L2[], int L3[], int bits, int key[]) {
    for (int i = 0; i < bits; i++) {
        int bit1 = (L1[13] ^ L1[16] ^ L1[17] ^ L1[18]);
        int bit2 = (L2[20] ^ L2[21]);
        int bit3 = (L3[7] ^ L3[20] ^ L3[21] ^ L3[22]);
        for (int j = L1_SIZE - 1; j > 0; j--) {
            L1[j] = L1[j - 1];
        }
        L1[0] = bit1;

        for (int j = L2_SIZE - 1; j > 0; j--) {
            L2[j] = L2[j - 1];
        }
        L2[0] = bit2;

        for (int j = L3_SIZE - 1; j > 0; j--) {
            L3[j] = L3[j - 1];
        }
            L3[0] = bit3;
        key[i] = L1[L1_SIZE - 1] ^ L2[L2_SIZE - 1] ^ L3[L3_SIZE - 1];
    }
}

int main() {
    int L1[L1_SIZE], L2[L2_SIZE], L3[L3_SIZE];
    int bits;
    printf("Enter 19-bit LFSR1: ");
    for (int i = 0; i < L1_SIZE; i++) {
        scanf("%1d", &L1[i]);
    }
    printf("Enter 22-bit LFSR2: ");
    for (int i = 0; i < L2_SIZE; i++) {
        scanf("%1d", &L2[i]);
    }
    printf("Enter 23-bit LFSR3: ");
    for (int i = 0; i < L3_SIZE; i++) {
        scanf("%1d", &L3[i]);
    }
    printf("Enter number of output bits to be generated: ");
    scanf("%d", &bits);
    if (bits <= 0) {
        printf("Number of bits must be a positive integer.\n");
        return 1;
    }

    int *key = (int *)malloc(bits * sizeof(int));
    if (key == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    LFSR(L1, L2, L3, bits, key);
    printf("Keystream: ");
    for (int i = 0; i < bits; i++) {
        printf("%d", key[i]);
    }
    printf("\n");
    free(key);

    return 0;
}
