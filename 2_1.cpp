#include <stdio.h>
#include <stdint.h>

int32_t *array_init(int32_t N);

int main(){
int32_t N = 0; // number of elements in array
int32_t max= 0; // max (array1[i0]+array2[j0]), i0 <= j0
uint32_t max_i= 0, max_j = 0; // index of max sum 
int32_t temp = 0;
bool flag = false;
int32_t *array1 = NULL;
int32_t *array2 = NULL;
//ptrdiff_t

scanf("%d",&N);

array1 = array_init(N);
array2 = array_init(N);

/* find max(array1[i0]+array2[j0], j0>i0) */
max = array1[N-1] + array2[N-1];
max_i = N - 1; 
max_j = N - 1;
temp = N-1;
//printf("[i] = %u, max_i = %u, max_j = %u, max = %u \n",N-1, max_i, max_j, max);

for (int32_t i = (N-2); i >= 0; --i){
    if (array1[i] >= array1[max_i]){		// compare a[i] and a[i+1]. If a[i] > a[i+1] then it is obvious, max will increase anyway.
        max_i = i;
        max = array1[max_i] + array2[max_j];
    }
    if (array2[i] >= array2[temp]){		// added flag, because without him before 1st change on temp it will be always 0 
						// and array2[0] in next step is not what we want
        temp = i;
        flag = true;
    }
    if (flag && (array1[i] + array2[temp] >= max)){ // in previous step we remembered maximum array2[i] as array2[temp]. Now we need to
						// check for changing in max (could be not with this i, but with some of next)
        max = array1[i] + array2[temp];
        max_i = i;
        max_j = temp;
    }
//    printf("[i] = %u, max_i = %u, max_j = %u, max = %u \n",i, max_i, max_j, max);
}

printf("%u %u",max_i,max_j);
}

int32_t *array_init(int32_t N){
int32_t *array = new int32_t [N];
for (int32_t i = 0; i < N; ++i)
    scanf("%d",&array[i]);
return array;
} 
