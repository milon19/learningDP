#include<iostream>
#include<cstdio>

using namespace std;
int s[100], A[100];
int N;

void print()
{
    for(int i = 0; i < N; i++)
    {
        if(A[i])
            cout << s[i] << " ";
    }
    cout << endl;
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
        scanf("%d", &s[i]);
    subset(0);
    return 0;
}
