#include <stdio.h>
#define lenOfArr 50
void
shift_element (int *arr, int i)
{
  int temp;
  for (int j = i; j >= 0; j--)
    {
      *(arr + j + 1) = *(arr + j);
    }
}

void
insertion_sort (int *arr, int len)
{
  int temp, index;
      for(int i=1;i<len;i++){
        temp=*(arr + i);
        index=i-1;
        while((temp<(*(arr + index)))&&(index>=0)){
            *(arr + index + 1)=*(arr + index);
            index=index-1;
         }
        *(arr + index + 1)=temp;
   }
}

void main ()
{
  int arr[lenOfArr];
  int *temp = &arr;
  for(int i = 0; i < lenOfArr; i++)
  {
      scanf("%d",&arr[i]);
  }

  insertion_sort (&arr, lenOfArr);
  printf ("%d", arr[0]);
  for (int t = 1; t < lenOfArr; t++)
    {
      printf (",%d", arr[t]);
    }

}




