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
#define fi first
#define se second
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define st(a) sort(a.begin(),a.end());
#define s(a) a.size()
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
using namespace __gnu_pbds;
using namespace std;
long long calculate(long long p, 
                    long long q) 
{ 
    long long mod = 998244353, expo; 
    expo = mod - 2; 
    while (expo) { 
        if (expo & 1) { 
            p = (p * q) % mod; 
        } 
        q = (q * q) % mod; 
        expo >>= 1; 
    } 
    return p; 
} 
ll gcd(ll a, ll b)
{
    if(a==0)
    return b;
    else if(b==0)
    return a;
    else if(a>b)
    return gcd(b,a%b);
    else
    return gcd(b%a,a);
} 
vector <int> bfs(vector<int> g[], int N) {
vector<int>a;
queue<int>b;
bool c[N]={false};
b.push(0);
c[0]=true;
while(!b.empty())
{ int p=b.front();

a.push_back(p);
for(int i=0;i<g[p].size();i++)
{ if(c[g[p][i]]==false)
   { b.push(g[p][i]);
       c[g[p][i]]=true;}
   }
    
    b.pop();
}
return a;
}
ll dij(ll x , ll y , vvll a[],ll n)
{
    ll dist[n],c,d;
    fr(i,0,n)
    dist[i]=LONG_MAX;
    dist[x]=0;
    bool b[n]={false};
    multiset<pair<ll,ll>>s;
    pair<ll,ll>p;
    s.insert({x,0});
    while(!s.empty())
    { p=*s.begin();
    s.erase(s.begin());
    c=p.first; d=p.second;
    if(b[c]==true)
    continue;
    fr(j,0,a[c].size())
    {
        if(dist[c]+a[c][j].second< dist[a[c][j].first])
        {
            dist[a[c][j].first]=dist[c]+a[c][j].second;
            s.insert({a[c][j].first,dist[a[c][j].first]});
        }
    }
        
    }
    if(dist[y]==LONG_MAX)
    return -1;
    return dist[y];
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first)
     return (a.second<b.second);
    return (a.first<b.first);
   
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        char b[3];
        int a[3]={0},d;
        if(s.size()==1)
        cout<<"YES"<<endl;
        else if(s[0]==s[s.size()-1])
        cout<<"NO"<<endl;
        else
        {
            a[s[0]-'A']=1;
            a[s[s.size()-1-'A']]=1;
            fr(i,0,3)
            {
                if(a[i]==0)
                d=1;
            }
            vector<char>p,q;
            fr(i,0,s.size())
            {
                if(s[i]==s[0])
               { p.pb('(');q.pb('(');}
                else if(s[i]==s[s.size()-1])
                {
                    if(p.size()>0 && p[p.size()-1]=='(')
                    p.pp();
                    else
                    p.pb(')');
                    
                    if(q.size()>0 && q[q.size()-1]=='(')
                    q.pp();
                    else
                    q.pb(')');
                    
                }
                else
                { if(p.size()>0 && p[p.size()-1]=='(')
                    p.pp();
                    else
                    p.pb(')');
                    q.pb('(');
                    
                }
            } if(q.size()==0 || p.size()==0)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
}