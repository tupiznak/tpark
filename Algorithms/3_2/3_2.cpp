#include <stdio.h>
#include <stdint.h>

int32_t find_max(int32_t *array, int32_t N);

int main(void){
	int32_t *array;
	int32_t N;
	
	scanf("%d",&N);
	
	array = new int32_t[N];
	for (int32_t i = 0; i < N; ++i)
		scanf("%d",&array[i]);
	printf("%d",find_max(array,N));
	delete[] array;
}

int32_t find_max(int32_t *array, int32_t N){
	int32_t left = 0;
	int32_t right = N - 1;
	int32_t middle = (left + right) / 2;
	
	if (right == 0) // всего 1 элемент в массиве
		return right;
		
	do{ 
		if (middle == N - 1) // дошли до конца массива
			return middle;
		if (right == 1) // for example for array -1 4
			return ((array[0] > array[1])?0:1);
		if (middle == 0)
			return middle;
		if ((array[middle] > array[middle+1]) && (array[middle] > array[middle-1])) // нашли максимум
			return middle;
		if (array[middle] < array[middle-1] /*&& array[middle] > array[middle+1]*/) // идем влево
			right = middle - 1;
		else  // идем вправо
			left = middle + 1;
		middle = (left + right) / 2; 	
	}while( !(left >= right));
	
	return middle;
}
