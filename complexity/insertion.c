#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tableau{
  int * table;
  int size;
};

void swap(int tab[], int i, int j)
{
  int tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}
int str_to_num(char * string)
{
  int number = 0;
  for(int i = 0; string[i] != '\0' && string[i] != '\n' ;i++)
  {
    number = number * 10 + string[i]-'0';
  }
  return number;
}

struct tableau create_array(char * s)
{
  struct tableau table;
  FILE *fp;
 char buff[12];
 fp = fopen(s, "r");
 if(!fp)
 {
   printf("file doesnt exist or rights missing\n");
   exit(-2);
 }

 if(fgets(buff, 255, (FILE*)fp))
 {
   table.size = str_to_num(buff);
   if( table.size > 0)
   {
     table.table = malloc(table.size * sizeof(int));
   }
   else
   {
     printf("Error size of array <= 0\n");
     exit(-1);
   }
  }else
  {
     printf("empty file\n");
     exit(-1);
   }
   int index = 0;
   while(fgets(buff, 255, (FILE*)fp)  && index < table.size)
   {
     table.table[index] = str_to_num(buff);
     index++;
   }

   return table;
}


void insertionSort(int * table,int size)
{
  int x;
  int j;
  for(int i = 1; i < size; i++)
  {
    x = table[i];
    for(j = i; j> 0 && table[j-1] > x;j--)
    {
        table[j] = table[j-1];
    }
    table[j] = x;
  }
}

void arrayTypeout(int j)
{
  if(j == 0)
  {
    printf("For random array, ");
  }
  else if(j == 1)
  {
    printf("For ascending array, ");
  }
  else{
    printf("For descending array, ");
  }
}

int test(int * table, int size)
{
  for(int i = 0; i < size-1; i++)
  {
    if(table[i] > table[i+1])
    {
      printf("error table isn't sorted\n");
      return -1;
    }
  }
}

int main()
{

  int size =5;
  int table[] = {5,1,3,2,4};

  insertionSort(table,size);

  for(int i = 0 ; i < size ; i++)
  {
    printf("table[%d] = %d\n",i,table[i]);
  }

  // struct tableau table;
  // struct tableau array_of_tables[3];
  //
  // array_of_tables[0] = create_array("rand.txt");
  // array_of_tables[1] = create_array("ascend.txt");
  // array_of_tables[2] = create_array("descend.txt");
  //
  // clock_t begin;
  // clock_t end;
  // double time_spent;
  //
  // for(int j = 0; j < 3; j++)
  // {
  //   table = array_of_tables[j];
  //   arrayTypeout(j);
  //
  //
  //   begin = clock();
  //   bubbleSort(table.table,table.size);
  //   end = clock();
  //   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  //   printf("Time spent = %f\n",time_spent);
  // }
  // for(int j = 0; j < 3; j++)
  // {
  //   test(array_of_tables[j].table,array_of_tables[j].size);
  // }

}
