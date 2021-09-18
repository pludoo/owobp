#include <iostream>

int BinarySearch(int _arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - 1) / 2;

        if (_arr[mid] == x)
            return mid;

        if (_arr[mid] > x)
            return BinarySearch(_arr, l, mid -1, x);

        return BinarySearch(_arr, mid + 1, r, x);
    }


    return -1;
}




void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; } //swaps two passed pointers

void BubbleSort(int _arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++) {
        if (_arr[j] > _arr[j + 1])
            swap(&_arr[j], &_arr[j + 1]);
    }
}

void PrintArray(int _arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        std::cout << _arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {4, 6, 1, 2, 7, 21, 62, 12, 15, 13, 10, 61, 68, 65, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sFor = 10;
    std::cout << "Before Sort: \n";
    PrintArray(arr, n); //print unsorted array
    std::cout << "\n";
     
    BubbleSort(arr, n); //sort array with bubble sort
    int result = BinarySearch(arr, 0, n - 1, sFor); //set result to the output of binary search



    std::cout << "After Sort: \n";
    PrintArray(arr, n); //print sorted array
    std::cout << "\n";

    if (result == -1) { std::cout << "Element not found in index\n"; } // if result -1 element is not found
    else { std::cout << "Element " << sFor << " found at index: " << result << std::endl; } // print index which sFor is found at
    std::cin.get();

}