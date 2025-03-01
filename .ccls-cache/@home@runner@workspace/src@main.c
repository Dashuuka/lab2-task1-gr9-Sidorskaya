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

void sort_by_digit_sum(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (sum_of_digits(arr[j]) < sum_of_digits(arr[j + 1])) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char *argv[]) {
		if (argc != 2) {
				printf("Size: %s <size_array>\n", argv[0]);
				return 1;
		}

		int n = atoi(argv[1]);
		if (n <= 0) {
				printf("Error: n<=0.\n");
				return 1;
		}

		int *arr = malloc(n * sizeof(int));
		if (!arr) {
				perror("Error with memory");
				return 1;
		}

		srand(time(NULL));
		printf("Array (%d elements):\n", n);
		for (int i = 0; i < n; i++) {
				arr[i] = rand() % 10000;
				printf("%d ", arr[i]);
		}

		sort_by_digit_sum(arr, n);

		printf("\n\nAfter sort:\n");
		for (int i = 0; i < n; i++) {
				printf("%d (Sum: %d)\n", arr[i], sum_of_digits(arr[i]));
		}

		free(arr);
		return 0;
}