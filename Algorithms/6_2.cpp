#include <iostream>

long long answer(int val, long long **matrix, int height, bool stop)						
{														
	long long  res = 0;
	for (int i = 0; i <= val; ++i)
	{
		if (height == 1 && (val==1 || val ==2))
			return 1;
		else if (height >= val && stop)
			return 0;

		if (matrix[val][height] != -1 && stop)
		{
			return matrix[val][height];
		}
		res += answer(val - height, matrix, height, true) + answer(val - height, matrix, height - 1, true);
		if (stop)
		{
			if (matrix[val][height] == -1)
				matrix[val][height] = res;
			return res;
		}
		height++;
	}
	return res;
}


int main()
{
	int value = 0;
	long long ans = 0;
	std::cin >> value;
	long long **matrix = new long long*[value + 1];
	for (int i = 0; i < value + 1; ++i)
		matrix[i] = new long long[value + 1]; 
	for (int i = 0; i < value + 1; ++i)
	for (int j = 0; j < value + 1; ++j)
	{
		matrix[i][j] = -1;
	}
	for (int i = 0; i < value + 1; ++i)
	{
		matrix[i][0] = 0;
		matrix[0][i] = 0;
	}
	ans = answer(value, matrix, 1,false);
	std::cout << ans;
	for (int i = 0; i < value + 1; i++)
		delete matrix[i];
	delete[] matrix;
	return 0;
}
