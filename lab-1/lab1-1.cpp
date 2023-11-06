#include <iostream>
#include <fstream>
using namespace std;
// Size of the array is ‘n’ and read ‘n’ number of elements from a disc file
int arr[100];
void readArrayFromFile(int arr[], int n)
{
    ifstream inFile;
    inFile.open("input.txt");
    for (int i = 0; i < n; i++)
    {
        inFile >> arr[i];
    }
    inFile.close();
}

int secondSmall=0,secondLarge=0;
int secondLargest(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    secondSmall=arr[1];
    secondLarge=arr[n-2];
    return arr[n - 2];
}

    int main()
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        readArrayFromFile(arr, n);
        secondLargest(arr, n);
        cout << "Second Largest Element in the array is: " << secondLarge << endl;
        cout << "Second Smallest Element in the array is: " << secondSmall << endl;
        
        return 0;
    }