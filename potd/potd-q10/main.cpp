#include <iostream>
#include <math.h>
using namespace std;

//
// Write the function `raise` that accepts an array of integers and
// an integer as the input parameters.
//

int* raise(int arr_in[], int size){
    int *array = new int[size];
    for (size_t i = 0; i < size - 2; i++){
        array[i] = pow(arr_in[i], arr_in[i+1]);
    }
    for (size_t i = size - 2; i < size; i++){
        array[i] = arr_in[i];
    }
    return array;
}

int main() {
  int arr_in[5] = { 1, 2, 3, 4, -1 };
  int *arr_out = raise(arr_in, 5);
  return 0;
}
