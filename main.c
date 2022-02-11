//Title:   Full Adder Program
//Name:    Adam Pena
//Date:    12/9/2021

#include <stdio.h>
#include "nBitAdder.h"

int main(void) {
// Testing the logic gates:

  printf("AND(0, 0): %d\n", l_and(0, 0));
  printf("AND(0, 1): %d\n", l_and(0, 1));
  printf("AND(1, 0): %d\n", l_and(1, 0));
  printf("AND(1, 1): %d\n", l_and(1, 1));

  printf("\n");

  printf("OR(0, 0): %d\n", l_or(0, 0));
  printf("OR(0, 1): %d\n", l_or(0, 1));
  printf("OR(1, 0): %d\n", l_or(1, 0));
  printf("OR(1, 1): %d\n", l_or(1, 1));

  printf("\n");

  printf("NOT(0): %d\n", l_not(0));
  printf("NOT(1): %d\n", l_not(1));

  printf("\n");

  printf("XOR(0, 0): %d\n", l_xor(0, 0));
  printf("XOR(0, 1): %d\n", l_xor(0, 1));
  printf("XOR(1, 0): %d\n", l_xor(1, 0));
  printf("XOR(1, 1): %d\n", l_xor(1, 1));

  printf("\n");

// Testing the full adder:

  fullAdderPrint();

// Testing the n_bit adder a few times

  printf("\n");

  int b1[9] = {1, 0, 1, 1, 1, 0, 1, 0, 0};
  int b2[9] = {0, 1, 1, 0, 1, 1, 1, 0, 1};

  struct nBitsToAdd forNBitAdder;
  forNBitAdder.n = 9;
  forNBitAdder.bits1 = b1;
  forNBitAdder.bits2 = b2;

  struct nBitAdderResult sumOfBits = nBitAdder(forNBitAdder);
  
  printf("101110100 + 011011101 =\n");
  printf("   Carry bit: %d\n   Sum: ", sumOfBits.carryOut);
  for(int i = 0; i < sumOfBits.length; i++){
    printf("%d", sumOfBits.sum[i]); 
  }

  printf("\n");

  int b3[13] = {1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0};
  int b4[13] = {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1};

  struct nBitsToAdd forNBitAdder2;
  forNBitAdder2.n = 13;
  forNBitAdder2.bits1 = b3;
  forNBitAdder2.bits2 = b4;

  struct nBitAdderResult sumOfBits2 = nBitAdder(forNBitAdder2);

  printf("1001011010010 + 0110111011001 =\n");
  printf("   Carry Bit: %d\n   Sum: ", sumOfBits2.carryOut);
  for(int i = 0; i < sumOfBits2.length; i++){
    printf("%d", sumOfBits2.sum[i]); 
  }

  printf("\n");

  int b5[10] = {0, 0, 1, 0, 1, 1, 0, 1, 1, 0};
  int b6[10] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0};

  struct nBitsToAdd forNBitAdder3;
  forNBitAdder3.n = 10;
  forNBitAdder3.bits1 = b5;
  forNBitAdder3.bits2 = b5;

  struct nBitAdderResult sumOfBits3 = nBitAdder(forNBitAdder3);

  printf("0010110110 + 0010101010 =\n");
  printf("   Carry Bit: %d\n   Sum: ", sumOfBits3.carryOut);
  for(int i = 0; i < sumOfBits3.length; i++){
    printf("%d", sumOfBits3.sum[i]); 
  }

  return 0;
}