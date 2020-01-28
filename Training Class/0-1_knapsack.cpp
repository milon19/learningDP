#include<bits/stdc++.h>

using namespace std;


int dp[1001][31];
int cap, n, wt[1001], val[1001];

int knap(int i, int w)
{
    if(i == n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int profit1, profit2;
    if(w + wt[i] <= cap)
        profit1 = val[i] + knap(i+1, w+wt[i]);
    else
        profit1 = 0;
    profit2 = knap(i+1, w);
    dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> cap;
    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];
    cout << knap(0, 0) << endl;

    return 0;
}
