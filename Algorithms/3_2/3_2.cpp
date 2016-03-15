#include <stdio.h>
#include <stddef.h>

ptrdiff_t *array_init(size_t N);
size_t find_max(ptrdiff_t *array, size_t N);

int main(void){
	ptrdiff_t *array;
	size_t N;
	
	scanf("%ld",&N);
	array = array_init(N);
	printf("%ld",find_max(array,N));
	
}

ptrdiff_t *array_init(size_t N){
	ptrdiff_t *array = new ptrdiff_t [N];
	for (size_t i = 0; i < N; ++i)
		scanf("%ld",&array[i]);
	delete [] array;
	return array;
}

size_t find_max(ptrdiff_t *array, size_t N){
	ptrdiff_t left = 0;
	ptrdiff_t right = N - 1;
	ptrdiff_t middle = (left + right) / 2;
	
	if (middle == 0) // всего 1 элемент в массиве
		return middle;
	
	do{ 
		if ((array[middle] > array[middle+1]) && (array[middle] > array[middle-1]))
			return middle;
		if (array[middle] < array[middle-1] /*&& array[middle] > array[middle+1]*/) // идем влево
			right = middle - 1;
		else // идем вправо
			left = middle + 1;
		middle = (left + right) / 2; 	
	}while( middle > 0);
	
	return middle;
}
