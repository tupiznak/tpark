/***********************************************************************
* 					Soldatov A.K. APO-13                               *
*						Task 1_4                                       *
***********************************************************************/
#include <stdio.h>
// This numbers are exeptions from Ferma`s theorem in range 1..10^7
/*
* #define Carmichael_number1 561
* #define Carmichael_number2 41041
* #define Carmichael_number3 825265
*/
//bool Ferma(int N);													// Ferma theoreme (is N prime? True if yes)
//int to_degree(int a, int N);											// fast degree (used in Ferma function)
//int Euclid															// Euclid algorithm
size_t Split_max(size_t *N);											// Checking for the greatest common devisor of N
int main(void) {
    size_t N;															// Natural number
	size_t tempN;														// Container for N value before changes
    size_t A, B;															// Natural numbers
	
	scanf("%ld",&N);
	tempN = N;

	Split_max(&tempN);
	if (tempN == N) {													// If N prime	
		A = tempN - 1;
		B = tempN - A;
	}
	else {
		A = tempN;
		B = N - A;
	}

	if (A > B){
		tempN = A;
		A = B;
		B = tempN;
	}

	printf("%ld %ld", A, B);

// Ferma test for prime numbers (TODO)
/* 
* 	if (Ferma(N)){
*		printf("%u %u", (1), (N-1));
*	}
*/
// Euclid algorithm (run-time error, must change "for" loop)
/*
*	int trueA, trueB, temp_GCD, max_GCD = 0;
*
*	for (A = 2; A <= (N / 2); ++A) { // could we use prime numbers table here? (see prime.txt)
*		B = N - A;
*		temp_GCD = Euclid(A, B);
*		if (max_GCD < temp_GCD) {
*			max_GCD = temp_GCD;
*			trueA = A;
*			trueB = B;
*		}
*	}
*/
}
size_t Split_max(size_t *N){
	for (size_t devider = 2; devider * devider <= *N; ++devider)
		if (*N % devider == 0){
			*N /= devider;
			return *N;													// if N not prime
		}
	return *N;															// if N prime
}
// fast degree (in progress, see 1st lection)
/*
 * TODO
*/
// Ferma test (not working yet)
/*
* bool Ferma(int N){
*	int a = 3;
*	int temp = to_degree(a,N);
*	if (((temp % N) == (a % N)) && (N != Carmichael_number1) && (N != Carmichael_number2) && (N != Carmichael_number3))
*		return true;
*	else
*		return false;
*}
*/
// Euclid algorithm
/*
* int Euclid(int A, int B) {
*	if (B == 0)
*		return A;
*	return Euclid(B, A % B);
* }
*/
