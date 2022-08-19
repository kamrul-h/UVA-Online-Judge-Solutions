/*
10327 - Flip Sort
*/

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;

    int i = left; /* i is index for left subarray*/
    int j = mid; /* i is index for right subarray*/
    int k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i=left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}
int countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}
int main()
{
    int test;

    while(scanf("%d",&test)!=EOF)
    {
        int arr[test];
        for(int i=0; i<test; i++)
            cin>>arr[i];
        printf("Minimum exchange operations : %d\n", countSwaps(arr, test));
    }
    return 0;
}

/*
Sample Input
3
1 2 3
3
2 3 1

Sample Output
Minimum exchange operations : 0
Minimum exchange operations : 2
*/
