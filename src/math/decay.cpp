void decay(unsigned long now, int array[], int size, float decay, unsigned long &decayTimer, unsigned long decayCD){
  if(now - decayTimer >= decayCD){
    decayTimer = now;
    for(int i = 0; i < size; i++ ){
      array[i] = array[i] * decay;
    }
  }
}