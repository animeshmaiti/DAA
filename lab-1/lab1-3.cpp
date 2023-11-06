#include <iostream>
using namespace std;
int noOfduplicate=0,duplicateEle[100];

void duplicate(int arr[])
{
    int element,flag;
    for (int i = 0; i < 1; i++)
    {
        element=arr[i];
        // cout<< element <<" ";
        for (int j = 1; j < 5; j++)
        {
            cout<< arr[j]<< " ";
            if (arr[j]==element)
            {
                // cout<<arr[j]<<" ";
                duplicateEle[i]=element;
                noOfduplicate=flag++;
            }
        }           
    }
}

int main(){
    int arr[5]={12,45,56,76,56};
    duplicate(arr);
    cout<<noOfduplicate<<" ";
    for (int i = 0; i <5; i++)
    {
        cout<<duplicateEle[i]<<" ";
    }

    // noOfduplicate[0]
    
    return 0;
}