#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "methods.h"
#include "detector.h"

unsigned char out = 0;
static char sequence [4] = {' ',' ',' ',' '}; 

void ChangeSequence (unsigned char in) {
    int i; for (i = 3; i > 0; i--) sequence[i] = sequence[i-1];
    sequence[0] = (in) ? '1' : '0';
}

 
void Output (void) {
    int i; for (i = 0; i < 8; i++) fprintf(stdout,"\b");
    fprintf(stdout,"\n %s %c %s %c %s","|",state,"|",(out)?'1':'0',"|");
    for (i = 3; i >= 0; i--) fprintf(stdout,"%c",sequence[i]);
    fprintf(stdout,"%s","|");
    fprintf(stdout,"\n %s","--------------");
}

 
int main(int argc, char *argv[]) {
  char seed;
  int config;
  setlocale( LC_ALL,"Russian" );
  printf("%s","      Методы\n");
  printf("\n");
  printf("%s","1.Метод Фибоначчи\n");
  printf("%s","2.Метод Галуа\n");
  printf("%s","3.Линейный конгруэнтный метода\n");
  printf("\n");
  printf("%s","Введите зерно: ");
  scanf("%d", &seed);
  printf("\n");
  printf("%s","Выберите метод: ");
  scanf("%d", &config);
  printf("%s"," --------------");
  register unsigned char LFSROut;
  LFSRInit (seed, config);
     while (1) {
      if (config == 1) LFSROut = LFSR_Fibonacci();
      else if (config == 2) LFSROut = LFSR_Galois();
      else if (config == 3) LFSROut = LCG(); 
      out = Detector(LFSROut);
      ChangeSequence(LFSROut);
      Output();
      if(out)break;
      sleep(1);
    }
    return 0;
}

