#include "methods.h"

void LFSRInit (char seed, int config) 
{
  if (config == 1) 
  {
  	sr = seed;
  }  
  else if(config == 2) 
  {
  	SR.SR = (unsigned char)seed;
  }
  else if(config == 3)
  {
  	S = seed;
  }
}

unsigned char LFSR_Fibonacci (void)
{
    auto char fb = ~((sr & (1 << 0)) ^ ((sr & (1 << 3)) >> 3)) & (1 << 0);
    sr = ((fb << 4) & (1 << 4)) | (sr >> 1);
    return sr & (1 << 0);
}

unsigned char LFSR_Galois (void)
{
    SR.Bit_6 = SR.Bit_0;
    SR.Bit_2 = ~(SR.Bit_0 ^ SR.Bit_3);
    SR.SR >>= 1;
    return SR.Bit_2;
}

int LCG (void)
{
  S = (S * 7 + 19 ) % 65535;
  return S & 1 ;
}
 
