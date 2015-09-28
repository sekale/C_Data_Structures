//
//  bitwise_operations.c
//  
//
//  Created by Siddhant Ekale on 9/27/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int findlargestnum(int *arr,int size);
int *radix_sort(int *arr_sort, int size);
void print_arr(int *arr_sort,int size);
int check_sort(int *arr_sort,int size);
int *radix_sort_bitwise(int *arr_sort, int size);
int* radixsort_1(int *a, int n);

int main()
{
    
    clock_t start, end;
    double cpu_time_used;
    int a = 0;
    int size = 4;
    printf("\nPlease Enter Size");
    scanf("%d", &size);
    int *arr_sort;
    arr_sort = malloc(sizeof(int)*size);
    for(a = 0; a < size; a++)
    {
        arr_sort[a] = rand();
    }
    //arr_sort[1] = 621;
    //arr_sort[2] = 127;
    //arr_sort[0] = 321;
    //arr_sort[3] = 926;
    

    //print_arr(arr_sort,size);
    start = clock();
    //arr_sort = radix_sort(arr_sort, size);
    arr_sort = radixsort_1(arr_sort,size);
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n Cpu Time = %f",cpu_time_used);
    if(check_sort(arr_sort,size) == 0)
    {
        printf("\nSorted");
    }
    else
    {
        printf("\nUnsorted");
    }
    
    free(arr_sort);
    return 0;
}




int check_sort(int *arr_sort,int size)
{
    int ele;
    int i = 0;
    for(i = 0; i < size - 1; i++)
    {
        if(arr_sort[i] > arr_sort[i+1])
        {
            return - 1;
        }
    }
    return 0;
}
void print_arr(int *arr_sort,int size)
{
    int i = 0;
    printf(" \n \n");
    for(i = 0; i < size; i++)
    {
        printf(" %d  ",arr_sort[i]);
    }
}

int findlargestnum(int *arr, int size)
{
    int i = 0;
    int large_num = arr[i];
    
    for(i = 0; i < size; i++)
    {
        if(arr[i] > large_num)
        {
            large_num = arr[i];
        }
    }
    return large_num;
}


int *radix_sort(int *arr_sort, int size)
{
    int *almost_sorted;
    almost_sorted = malloc(sizeof(int) * size);
    int i = 0;
    int large_num = findlargestnum(arr_sort,size);
    int sig_digit = 1;
    int bucket[10] = {0};
    printf("%d",large_num);
    while((large_num / sig_digit) > 0)
    {
        for(i = 0; i < 10; i++)
        {
            bucket[i] = 0;
        }
        for(i = 0; i < size; i++)
        {
            bucket[(arr_sort[i]/sig_digit)%10]++;
        }
            //print_arr(&bucket[0],10);
        
        for(i = 1; i < 10; i++)
        {
            bucket[i] += bucket [i-1];
        }
        //print_arr(&bucket[0],10);
        
        for(i = size - 1; i >= 0; i--)
        {
            //printf("\n index = %d",--bucket[(arr_sort[i] / sig_digit) % 10]);
            almost_sorted[--bucket[(arr_sort[i] / sig_digit) % 10]] = arr_sort[i];
        }
        for(i = 0; i < size; i ++)
            arr_sort[i] = almost_sorted[i];
        sig_digit *= 10;
        
    }
    free(almost_sorted);
    return arr_sort;
}

int *radix_sort_bitwise(int *arr_sort, int size)
{
    int *almost_sorted;
    almost_sorted = malloc(sizeof(int)*size);
    int large_num = findlargestnum(arr_sort,size);
    int sig_digit = 1;
    int bucket[2] = {0};
    int mask = 1;
    int i = 0;
    while((large_num >> (sig_digit)) > 0)
          {
              printf("\nSig_Digit = %d",sig_digit);
              for(i = 0; i < 2; i++)
              {
                  bucket[i] = 0;
              }
              
              for(i = 0; i < size; i++)
              {
                  bucket[(arr_sort[i] >> (sig_digit * 2)) & mask]++;
              }
              
              
              for(i = 1; i < 2; i++)
              {
                  bucket[i] += bucket[i-1];
              }
              
              for(i = size - 1; i >=0 ;i--)
              {
                  almost_sorted[--bucket[(arr_sort[i] >> (sig_digit)) & mask]] = arr_sort[i];
              }
              
              for(i = 0; i < size; i ++)
                  arr_sort[i] = almost_sorted[i];
              
              sig_digit +=1;
              
          }
    printf("Val = %d",(arr_sort[i] >> (sig_digit)) & mask);
          free(almost_sorted);
          return arr_sort;
}

#define BITS 2
int* radixsort_1(int *a, int n) {
    int i,m = a[0], pos = 0;
    int buckets=1<<BITS;
    int mask=buckets-1;
    for (i = 0; i < n; i++) if (a[i] > m) m = a[i];
    int *b = malloc(sizeof(int)*n);
    while ((m>>(pos*BITS)) > 0) {
        int bucket[1<<BITS] = { 0 };
        for (i = 0; i < n; i++)       bucket[(a[i]>>(pos*BITS)) & mask]++;
        for (i = 1; i < buckets; i++) bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--)  b[--bucket[(a[i]>>(pos*BITS)) & mask]] = a[i];
        for (i = 0; i < n; i++)       a[i] = b[i];
        pos++;
    }
    free(b);
    return a;
}