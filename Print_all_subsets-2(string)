#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
string str;
int A[100];
int N;

void print()
{
    for(int i = 0; i < N; i++)
    {
        if(A[i])
            cout << str[i];
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
    cin >> str;
    N = str.size();
    subset(0);
    return 0;
}

