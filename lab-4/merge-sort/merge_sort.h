#include "merge.h"

int merge_sort(int arr[], int left, int right,int ch) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += merge_sort(arr, left, mid,ch);
        comparisons += merge_sort(arr, mid + 1, right,ch);

        comparisons += merge(arr, left, mid, right,ch);
    }
    return comparisons;
}