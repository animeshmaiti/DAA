#include <iostream>
#include <fstream>

int* readIntegersFromFile(const std::string& file_name, int& n) {
    std::ifstream file(file_name);
    int num;
    int capacity = 10; // Initial capacity of the array
    int* integers = new int[capacity];
    n = 0;

    while (file >> num) {
        if (n == capacity) {
            // If the array is full, resize it by doubling its capacity
            capacity *= 2;
            int* new_integers = new int[capacity];
            for (int i = 0; i < n; i++) {
                new_integers[i] = integers[i];
            }
            delete[] integers;
            integers = new_integers;
        }

        integers[n++] = num;
    }

    return integers;
}

int countDuplicates(const int* arr, int n) {
    int num_duplicates = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            num_duplicates++;
        }
    }

    return num_duplicates;
}

int findMostRepeatingElement(const int* arr, int n) {
    int most_repeating_element = arr[0];
    int max_repetitions = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max_repetitions) {
            most_repeating_element = arr[i];
            max_repetitions = count;
        }
    }

    return most_repeating_element;
}

int main() {
    std::string file_name = "input2.txt"; // Update this with the actual file name containing integers
    int n;
    int* integers_array = readIntegersFromFile(file_name, n);

    // a) Find out the total number of duplicate elements.
    int num_duplicates = countDuplicates(integers_array, n);
    std::cout << "Total number of duplicate elements: " << num_duplicates << std::endl;

    // b) Find out the most repeating element in the array.
    int most_repeating_element = findMostRepeatingElement(integers_array, n);
    std::cout << "Most repeating element: " << most_repeating_element << std::endl;

    // Free dynamically allocated memory
    delete[] integers_array;

    return 0;
}
