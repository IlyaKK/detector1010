static unsigned char sr;
int S;
static union SR {
  struct { 
      unsigned int Bit_0: 1;
      unsigned int Bit_1: 1;
      unsigned int Bit_2: 1;
      unsigned int Bit_3: 1;
      unsigned int Bit_4: 1;
      unsigned int Bit_5: 1;
      unsigned int Bit_6: 1;
    };
    unsigned int SR;
} SR;
unsigned char LFSR_Fibonacci (void);
unsigned char LFSR_Galois (void);
int LCG (void);
void LFSRInit (char, int);
