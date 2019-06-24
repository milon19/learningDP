/*
  printing the element of LIS.
  Jane Alam Jaan
  complexity: O(n)
*/
#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;
int n;
int LIS[100];
int seq[100];
int res[100];

int find_LIS_length()
{
    for(int i = 0; i < n; i++)
        LIS[i] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(seq[j] > seq[i])
                LIS[j] = max(LIS[j], LIS[i]+1);
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
        mx = max(LIS[i], mx);
    return mx;
}

void print_LIS(int len)
{
    int pos = 0;
    for(int i = 1; i < n; i++)
        if(LIS[pos] < LIS[i])           //Find the position of max L[i]
            pos = i;
    int top = LIS[pos]-1;
    res[top] = seq[pos];
    top--;
    for(int i = pos-1; i >= 0; i--)
    {
        if(seq[i] < seq[pos] && LIS[i] == LIS[pos]-1)
        {
            pos = i;
            res[top] = seq[i];
            top--;
        }
    }
    printf("Result: ");
    for(int i = 0; i < len; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> seq[i];
    int mx_length = find_LIS_length();
    cout << "LIS Length: " << mx_length << endl;
    print_LIS(mx_length);
    return 0;
}
