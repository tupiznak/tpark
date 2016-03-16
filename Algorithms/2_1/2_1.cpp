/***********************************************************************
* 					Soldatov A.K. APO-13                               *
*						Task 2_1                                       *
***********************************************************************/
#include <stdio.h>
#include <stdint.h>

int32_t *array_init(int32_t N);											// array initialisation (array filling)

int main(){
int32_t N = 0; 															// number of elements in array
int32_t max= 0; 														// max (array1[i0]+array2[j0]), i0 <= j0
uint32_t max_i= 0, max_j = 0; 											// indexes of max sum 
int32_t temp = 0;														// contains index of max element in array2 
int32_t *array1 = NULL;
int32_t *array2 = NULL;

scanf("%d",&N);

array1 = array_init(N);
array2 = array_init(N);


max = array1[N-1] + array2[N-1];										// consider last elements sum to be max
max_i = N - 1; 
max_j = N - 1;
temp = N-1;
// debug message
// printf("[i] = %u, max_i = %u, max_j = %u, max = %u \n",N-1, max_i, max_j, max);

for (int32_t i = (N-2); i >= 0; --i) {									//find max(array1[i0]+array2[j0], j0>i0) 
    if (array1[i] >= array1[max_i]) {									// if a[i] > a[i+1], max will increase anyway.
        max_i = i;
        max = array1[max_i] + array2[max_j];
    }
    if (array2[i] >= array2[temp]) 										// save index of maximum element in array2  
        temp = i;
    if (array1[i] + array2[temp] >= max) { 								// compare current sum with max sum
        max = array1[i] + array2[temp];
        max_i = i;
        max_j = temp;
    }
// debug message
// printf("[i] = %u, max_i = %u, max_j = %u, max = %u \n",i, max_i, max_j, max);
}

printf("%u %u",max_i,max_j);
}

int32_t *array_init(int32_t N){
int32_t *array = new int32_t [N];
for (int32_t i = 0; i < N; ++i)
    scanf("%d",&array[i]);
return array;
} 
