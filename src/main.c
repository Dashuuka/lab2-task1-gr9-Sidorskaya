/* hello.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_of_digits(int number) {
		number = abs(number);
		int sum = 0;
		while (number > 0) {
				sum += number % 10;
				number /= 10;
		}
		return sum;
}


int main(int argc, char *argv[])
{
	printf ("Hello World\n");
	printf ("Goodbye World\n");
}
