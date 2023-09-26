/*Dyakonov Nickolay, ND4 , 19.10.2020*/
#include "DSORT.h"

void OutMas( UINT64 *Arr, UINT64 Size )
{
  int i = 0;

  for (; i < Size; i++)
    printf("%d%c\n", Arr[i], i == Size - 1 ? '\n' : ',');
}

void FillRand( UINT64 *Arr, UINT64 Size )
{
  int i = 0;

  for (; i < Size; i++)
    Arr[i] = rand() % (Size + 1);
}

void DigitalSort( UINT64 *Arr, UINT64 Size )
{
  static UINT64 Count[10], Offset[10], TmpArr[MAX], i, dg_ct = 0, pow  = 1;

  for (; dg_ct < 19; dg_ct++, pow *= 10)
  {
    for (i = 0; i < 10; i++)
      Count[i] = 0;

    for (i = 0; i < Size; i++)
      Count[Arr[i] / pow % 10]++;

    for (Offset[0] = 0, i = 1; i < 10; i++)
      Offset[i] = Offset[i - 1] + Count[i - 1];

    for (i = 0; i < Size; i++)
      TmpArr[Offset[Arr[i] / pow % 10]++] = Arr[i];

    for (i = 0; i < Size; i++)
      Arr[i] = TmpArr[i];
  }
}