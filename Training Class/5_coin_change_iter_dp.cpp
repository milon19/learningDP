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

int dp[101][10005];
int n, make;
int A[101];


int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &n, &make);
        for(int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= make; j++)
            {
                if(j-A[i] >= 0)
                    dp[i][j] = (dp[i-1][j] + dp[i][j-A[i]])%mod;
                else
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        printf("Case %d: %d\n", cs++, dp[n][make]);
    }

    return 0;
}
