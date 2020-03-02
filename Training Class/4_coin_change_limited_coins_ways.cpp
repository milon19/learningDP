#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<climits>
#include<queue>
#include <cstring>
#include<stack>

#define pb                  push_back
#define m_p                 make_pair
#define ALL(x)              x.begin(), x.end()
#define unq(x)              (x).resize(unique(ALL(x)) - x.begin())
#define db(x)               printf("%d\n", x)
#define fast                ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define endl                '\n'
#define mod                 100000007

using namespace std;
typedef pair<int, int>      pii;
typedef long long           ll;

bool cmp(pii f, pii s){
    if(f.first > s.first) return 0;
    if(f.first == s.first){
        if(f.second > s.second) return 0;
        else return 1;
    }else return 1;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int A[51], C[51];
int dp[51][1005];
int n, make;

ll call(int i, int amount)
{
    if(i >= n)
    {
        if(amount == 0) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    ll r1 = 0, r2 = 0;
    for(int j = 1; j <= C[i]; j++)
    {
        if(amount - (A[i]*j) >= 0)
            r1 += call(i+1, amount-(A[i]*j))%mod;
    }
    r2 = call(i+1, amount);
    return dp[i][amount] = (r1+r2)%mod;
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &make);
        for(int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &C[i]);
        int ans = call(0, make);
        printf("Case %d: %d\n", cs++, ans);

    }

    return 0;
}
