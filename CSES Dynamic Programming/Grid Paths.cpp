#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int 
#define vi vector<int>
#define vl vector<ll>
#define vvll vector<pair<ll,ll>>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pp pop_back
#define mp make_pair
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define st(a) sort(a.begin(),a.end());
#define s(a) a.size()
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;
using namespace std;
set<string>a;

int main()
{   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
int n;
cin>>n;
char a[n][n];
fr(i,0,n)
{
    fr(j,0,n)
    cin>>a[i][j];
}
ll dp[n][n];
fr(i,0,n)
{
    fr(j,0,n)
    {   dp[i][j]=0;
        if(a[i][j]=='.')
        { if(i==0 && j==0)
        dp[i][j]=1;
        else{
            if(i>0)
         dp[i][j]+=dp[i-1][j];
          dp[i][j]%=1000000007;
         if(j>0)
         dp[i][j]+=dp[i][j-1];
        dp[i][j]%=1000000007;
        }
        }
    
    }
} cout<<dp[n-1][n-1]<<endl;
}