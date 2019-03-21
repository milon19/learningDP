/*
    Milon Mahato
    Largest Sum Contiguous Subarray
    Kadane’s Algorithm
    Ref: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

#include<iostream>
#include<cstdio>
#include<climits>
#define sz 10001

using namespace std;

int findMax(int a[], int n)
{
    int cur_mx = 0, mx_sum = 0;
    for(int i = 0; i < n; i++)
    {
        cur_mx = max(a[i], cur_mx+a[i]);
        mx_sum = max(mx_sum, cur_mx);
    }
    return mx_sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int mx_sum = findMax(a, n);
    printf("Maximum sum %d\n", mx_sum);

    return 0;
}
