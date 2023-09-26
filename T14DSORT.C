/*Dyakonov Nickolay, ND4 , 19.10.2020*/

#include "DSORT.h"

void main( void )
{
  static UINT64 mas[MAX];

  FillRand(mas, MAX);
  DigitalSort(mas, MAX);
  OutMas(mas, MAX);

  getchar();
}