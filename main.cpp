#include <vector>
#include <iostream>

using namespace std;

// Function to print elements of a vector.
template<typename T>
void print_vector(const vector<T>& arr, int start, int end) {
    
     // Iterate through the vector 
    // and print each element followed by a space.
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// Function to perform merge sort
template<typename T>
void merge_sort(vector<T>& arr, int start_index, int end_index) {
    
    // If there are fewer than 2 elements, 
    // return immediately.
    if (start_index >= end_index) {
        return; 
    }
    
    cout << "current subvector: ";

    print_vector(arr, start_index, end_index);

    int middle_index = start_index + (end_index - start_index + 1) / 2;
    cout << "mid element = " << arr[middle_index] << '\n';
    
    // Recursively divide the left half of the vector.
    cout << "left part: ";
    print_vector(arr, start_index, middle_index-1);
    merge_sort(arr, start_index, middle_index-1);
    
    // Recursively divide the right half of the vector.
    cout << "right part: ";
    print_vector(arr, middle_index, end_index);
    merge_sort(arr, middle_index, end_index);
}

int main() {
    vector<int> data {5, 4, 7, 3, 2};
    merge_sort(data, 0, data.size()-1);
    return 0;
}