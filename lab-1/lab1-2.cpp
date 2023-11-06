#include <iostream>
using namespace std;

int prefixSumArr[100];
int prefixSum(int arr[], int n)
{
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        prefixSumArr[i] = prefixSum;
    }
    return prefixSum;
}

int main(){
    int arr[100]={3,4,5,1,2};
    int n=5;
    prefixSum(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<prefixSumArr[i]<<" ";
    }
    
    return 0;
}