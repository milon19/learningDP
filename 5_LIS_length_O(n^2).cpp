/*

    LIS from Jane Alam Jaan.
    Length of LIS. O(n^2)
*/

#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n], lis[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lis[i] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                if(lis[j] < lis[i]+1)
                    lis[j] = lis[i] + 1;
            }
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
        mx = max(mx, lis[i]);
    cout << mx << endl;

    return 0;
}
