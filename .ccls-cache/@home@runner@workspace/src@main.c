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
  printf("Hello World\n");
  printf("Goodbye World\n");
}
