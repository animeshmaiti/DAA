#include <iostream>
#include <chrono>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include"merge_sort.h"
using namespace std;
using namespace std::chrono;

int main() {
    ifstream inputFile("input.dat");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        inputFile >> arr[i];

    inputFile.close();
    const int N=100;
    int arr2[N];
    srand(time(NULL));

    int ch,comparisons;
    cout<<"1. Ascending Data\n 2. Descending Data\n 3. Random Data\n 4. ERROR (EXIT)\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
        /* Ascending */
        comparisons = merge_sort(arr, 0, n - 1,ch);
        break;
    case 2:
        /* Descending */
        comparisons = merge_sort(arr, 0, n - 1,ch);
        break;
    case 3:
        /* random */
        for (int i = 0; i < 10; i++)
            arr2[i]=rand() % N;
        comparisons = merge_sort(arr2, 0, 9,1);
        break;
    case 4:
        /* exit */
        break;
    
    default:
        cout<<"wrong choice\n";
        break;
    }

    for (int i = 0; i < 10; i++)
    {
        cout<<arr2[i]<<" ";
    }
    

    // ofstream outputFile("output.dat");
    // if (!outputFile.is_open()) {
    //     cerr << "Error creating output file." << endl;
    //     return 1;
    // }
    // if (ch==3)
    // {
    //     for (int i = 0; i < n; i++)
    //         outputFile << arr2[i] << " ";
    // }
    // else{
    //     for (int i = 0; i < n; i++)
    //     outputFile << arr[i] << " ";
    // }
    

    // outputFile.close();

    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
