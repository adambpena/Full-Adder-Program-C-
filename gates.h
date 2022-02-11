int l_and(int a, int b){
  int c;      // "boolean" result of gate operation

  if(a >= 1){  // Just checking inputs, keeping things "boolean"
    a = 1;
  }
  if(a<=0){
    a = 0;
  }

  if(b >= 1){
    b = 1;
  }
  if(b<=0){
    b = 0;
  }
  
  if((a + b) == 2){ // If both inputs are high
    c = 1;          // c (gate result) is high
  }
  else{
    c = 0;
  }

  return c;
}

int l_or(int a, int b){
  int c;      // "boolean" result of gate operation

  if(a >= 1){  // Just checking inputs, keeping things "boolean"
    a = 1;
  }
  if(a<=0){
    a = 0;
  }

  if(b >= 1){
    b = 1;
  }
  if(b<=0){
    b = 0;
  }
  
  if((a + b) >= 1){ // If either or both inputs are high
    c = 1;          // c (gate result) is high
  }
  else{
    c = 0;
  }

  return c;
}

int l_not(int a){
  int notA;      // "boolean" result of gate operation

  if(a > 1){  // Just checking inputs, keeping things "boolean"
    a = 1;
  }
  if(a<=0){
    a = 0;
  }
  
  if(a == 1){
    notA = 0;
  }

  if(a == 0){
    notA = 1;
  }

  return notA;
}

int l_xor(int a, int b){
  int c;      // "boolean" result of gate operation

  if(a >= 1){  // Just checking inputs, keeping things "boolean"
    a = 1;
  }
  if(a<=0){
    a = 0;
  }

  if(b >= 1){
    b = 1;
  }
  if(b<=0){
    b = 0;
  }
  
  if((a + b) == 1){ // If one input is high and not the other
    c = 1;          // c (gate result) is high
  }
  else{             // Otherwise, result is low
    c = 0;
  }

  return c;
}