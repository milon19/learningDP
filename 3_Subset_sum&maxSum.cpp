#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;
int N;
int s[100], A[100];
int mx = INT_MIN;

void print()
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i])
        {
            cout << s[i] << " ";
            sum+=s[i];
        }
    }
    cout << "sum" << " " << sum;
    cout << endl;
    mx = max(sum, mx);
}

void subset(int n)
{
    if(n == N)
    {
        print();
        return;
    }
    A[n] = 0;
    subset(n+1);
    A[n] = 1;
    subset(n+1);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> s[i];
    subset(0);
    cout << "Max " << mx << endl;
    return 0;
}
