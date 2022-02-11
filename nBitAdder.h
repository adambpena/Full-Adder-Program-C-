#include "fulladder.h"

struct nBitAdderResult{ // A structure holding the result of an nBitAdder operation
  int length;   // The common length of the two arrays (same as ins.n so somewhat redundant, only here for easy dot operator access to print via for loop, see main)
  int carryOut; // The carry out bit
  int sum[];    // Array holding the sum of the bit arrays, sans the carry out bit
};

struct nBitsToAdd{  // A structure passing info to the n-bit adder function
  int n;        // The number "n" of bits to add
  int* bits1;   // A pointer to an int array to be added 
  int* bits2;   // A pointer to another array to be added
  int carryIn;  // The carry in bit
};

struct nBitAdderResult nBitAdder(struct nBitsToAdd ins){ // The n-bit adder function, receives a nBitsToAdd structure and returns a nBitAdderResult structure
  struct nBitAdderResult result;  // The result structure to return
  struct fullAdderIn adderIn;     // A fullAdderIn structure
  struct fullAdderOut adderOut;   // A structure to receive full adder result
  
  result.length = ins.n;  // Result.length = length of bit arrays to be added
  int bitArr1[ins.n]; // Creating array of proper length to add
  int bitArr2[ins.n]; // A second array of proper length to add

  for(int i = 0; i < ins.n; i++) // For loop counting up to length
  {
    bitArr1[i] = ins.bits1[i];  // Populating array 1
    bitArr2[i] = ins.bits2[i];  // Populating array 2
  }

  for(int i = ins.n; i >= 0; i--){ // Loop adding arrays in proper MSB -> LSB order
    // Preparing for full adder function call
    adderIn.x = ins.carryIn;  // The carry in bit = the carry in of nBitsToAdd struct
    adderIn.a = bitArr1[i];   // Populate array starting w/ LSB of 1st array
    adderIn.b = bitArr2[i];   // Populate other array starting w/ LSB of 2nd array

    adderOut = fullAdder(adderIn);  // adderOut struct defined with fullAdder call on previously defined adderIn function

    if(i == 0){
      result.carryOut = adderOut.c;   // The carry out of the result = the adderOut's carry bit at the last calculation
    }
    
    result.sum[i] = adderOut.s;     // Populate the resulting sum array with the sum of the two corresponding bits
    ins.carryIn = adderOut.c;       // n adder's carry in = the n-1 adder's carry out
  }

  return result;  // Return the resulting structure
};