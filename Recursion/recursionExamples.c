#include <stdlib.h>
#include <stdio.h>

/* Factorial */

// n! = 1 if n = 0  => Base Case
// n! = n * (n - 1) * ....... * 1 if n > 0
int factorial(int currentNumber) {
	if (currentNumber == 0)return 1;
	int previousFactorial = factorial(currentNumber - 1);
	int currentFactorial = previousFactorial * currentNumber;
	return currentFactorial;
}
// Short hand for the previous function
int fact(int currentNumber) {
	return currentNumber == 0 ? 1 : fact(currentNumber - 1) * currentNumber;
}

// -------------------------------------------------------------------------

/* Multiplication */

// a * b = a if b = 1 => Base Case
// a * b = a * (b - 1) + a if b > 1
int multiplication(int firsNumber, int secondNumber) {
	if (secondNumber == 1)return firsNumber;
	int previousMultiplication = multiplication(firsNumber, secondNumber - 1);
	int currentMultiplication = previousMultiplication + firsNumber;
	return currentMultiplication;
}
// Short hand for the previous function
int mult(int firsNumber, int secondNumber) {
	return secondNumber == 1 ? firsNumber : mult(firsNumber, secondNumber - 1) + firsNumber;
}

// -------------------------------------------------------------------------

/* Fibonacci */

// fib(n) = n if n = 0 or n = 1 => Base Case
// fib(n) = fib(n-1) + fib(n-2) if n >= 2
int fibonacci(int currentNumber) {
	if (currentNumber <= 1)return currentNumber;
	int firstPreviousFibonacci = fibonacci(currentNumber - 1);
	int secondPreviousFibonacci = fibonacci(currentNumber - 2);
	int currentFibonacci = firstPreviousFibonacci + secondPreviousFibonacci;
	return currentFibonacci;
}
// Short hand for the previous function
int fib(int currentNumber) {
	return currentNumber <= 1 ? currentNumber : fib(currentNumber - 1) + fib(currentNumber - 2);
}

// -------------------------------------------------------------------------

/* Binary Search */

// if (low>high) => Base Case
// 	return -1
// mid=(low+high)/2
// if(x==a[mid]) => Base Case
// 	return mid
// if(x<a[mid])
// 	search for x in a[low] to a[mid-1]
// else
// 	search for x in a[mid+1] to a[high]
int binarySearch(const int a[], const int x, int low, int high) {
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (x == a[mid])
		return mid;
	if (x < a[mid])
		binarySearch(a, x, low, mid - 1);
	else
		binarySearch(a, x, mid + 1, high);
}
// Short hand for the previous function
int bs(const int a[], const int x, int low, int high) {
	if (low > high)return -1;
	int mid = (low + high) / 2;
	return x == a[mid] ? mid : (x < a[mid] ? bs(a, x, low, mid - 1) : bs(a, x, mid + 1, high));
}

// -------------------------------------------------------------------------