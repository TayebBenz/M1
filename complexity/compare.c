#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


void bubbleSort(int * table,int size)
{
  int swapped = 1;
  for(int new_size = size; new_size >1 && swapped == 1;new_size--)
  {
    swapped = 0;
    for(int i = 0;i < new_size-1;i++)
    {
      if(table[i]>table[i+1])
      {
        swapped = 1;
        swap(table,i,i+1);
      }
    }
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
    printf("for ascending array, ");
  }
  else{
    printf("for descending array, ");
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

void selectionSort(int * table,int size)
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

struct tableau  copy_table(struct tableau table)
{
  struct tableau t;
  int * p = malloc(table.size * sizeof(int));
  memcpy(p,table.table,table.size * sizeof(int));
  t.table = p;
  t.size = table.size;
  return t;
}

void selection(int choice, struct tableau * array_of_tables)
{
  clock_t begin;
  clock_t end;
  double time_spent;
  struct tableau table;

  if(choice == 0)
  {
    printf("Selection Sort:\n");
    for(int j = 0; j < 3; j++)
    {
      table = copy_table(array_of_tables[j]);
      arrayTypeout(j);
      begin = clock();
      selectionSort(table.table,table.size);
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Time spent = %f\n",time_spent);
      test(table.table,table.size);
    }
  }
  else if(choice == 1)
  {
    printf("insertion Sort:\n");
    for(int j = 0; j < 3; j++)
    {
      table = copy_table(array_of_tables[j]);
      arrayTypeout(j);
      begin = clock();
      insertionSort(table.table,table.size);
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Time spent = %f\n",time_spent);
      test(table.table,table.size);
    }
  }
  else{
    printf("bubble Sort:\n");
    for(int j = 0; j < 3; j++)
    {
      table = copy_table(array_of_tables[j]);
      arrayTypeout(j);
      begin = clock();
      bubbleSort(table.table,table.size);
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Time spent = %f\n",time_spent);
      test(table.table,table.size);
    }
  }

}


int main()
{

  struct tableau array_of_tables[3];

  array_of_tables[0] = create_array("rand.txt");
  array_of_tables[1] = create_array("ascend.txt");
  array_of_tables[2] = create_array("descend.txt");

  for(int i = 0; i < 3 ; i++)
  {
    selection(i,array_of_tables);
    printf("\n\n");
  }

}
