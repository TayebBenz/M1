#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int tab[], int i, int j)
{
  int tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

void triSlect(int * table,int size)
{
  int min;
  int min_index;
  for(int i = 0; i < size; i++)
  {
    min = table[i];
    min_index = i;
    for(int j = i+1;j < size; j++)
    {
      if(min > table[j])
      {
        min = table[j];
        min_index = j;
      }
    }
    if(min_index != i)
    {
      swap(table,i,min_index);
    }
  }
}


int main()
{

  int size = 5;
  int table[] = {10,2,3,4,5};
  triSlect(table,size);
  for(int i = 0; i < size ; i++)
  {
    printf("%d- %d\n",i,table[i]);
  }

  return 0;
}
