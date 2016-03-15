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
	
	if (middle == 0) // всего 1 элемент в массиве
		return middle;
	do{ 
		if ((array[middle] > array[middle+1]) && (array[middle] > array[middle-1]))
			return middle;
		if (middle == N - 1)
			return middle;
		if (array[middle] < array[middle-1] /*&& array[middle] > array[middle+1]*/) // идем влево
			right = middle - 1;
		else  // идем вправо
			left = middle + 1;
		middle = (left + right) / 2; 	
	}while( middle > 0);
	
	return middle;
}
