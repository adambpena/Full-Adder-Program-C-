#include "gates.h"  // Uses logic gates for full adder function

struct fullAdderIn{ // A structure to be passed to a full adder
  int x;  // Sort of a "carry in"
  int a;  // An in
  int b;  // Another in
};

struct fullAdderOut{ 
  int s;  // Sum
  int c;  // Carry out
};

struct fullAdderOut fullAdder(struct fullAdderIn ins){ // A function fullAdder which returns a fullAdderOut structure and receives a fullAdderIn structure
  struct fullAdderOut outs; // The name for the local adder out struct

  int xor1 = l_xor(ins.a, ins.b);
  int xor2 = l_xor(xor1, ins.x);
  outs.s = xor2;            // Sum is the result of a xor gate in the logic for designing a full adder circuit

  int or1 = l_or(ins.a, ins.b);
  int and1 = l_and(ins.a, ins.b);
  int and2 = l_and(ins.x, or1);
  int or2 = l_or(and1, and2);
  outs.c = or2;             // Carry out is result of an or gate in the logic for designing a full adder circuit

  return outs;              // fullAdderOut returned
}

void fullAdderPrint(){ // A function to print all full adder possibilities
  struct fullAdderIn adderIn;
  struct fullAdderOut adderOut;

  adderIn.x = 0;
  adderIn.a = 0;
  adderIn.b = 0;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (0 0 0): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.b = 1;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (0 0 1): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.a = 1;
  adderIn.b = 0;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (0 1 0): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.b = 1;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (0 1 1): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.x = 1;
  adderIn.a = 0;
  adderIn.b = 0;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (1 0 0): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.b = 1;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (1 0 1): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.a = 1;
  adderIn.b = 0;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (1 1 0): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

  adderIn.b = 1;

  adderOut = fullAdder(adderIn);

  printf("Full Adder (1 1 1): Sum: %d Carry: %d\n", adderOut.s, adderOut.c);

}