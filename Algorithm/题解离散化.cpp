#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll cmax=310000;
ll sqt[cmax];
ll a[cmax],a1[cmax];
ll m;
ll l[cmax],r[cmax];
void read(ll &x)
{
    x=0;
    ll f;
    f=1;
    char c;
    c=getchar();
    while((c<'0'||c>'9')&&(c!='-'))
    {
        c=getchar();
    }
    if(c=='-')
    {
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    x=x*f;
}
inline ll lowbit(ll x)
{
    return x&(-x);
}
void add(ll x,ll val)
{
    while(x<=cmax)
    {
        sqt[x]+=val;
        x+=lowbit(x);
    }
}
ll query(ll x)
{
    ll ans;
    ans=0;
    while(x>0)
    {
        ans+=sqt[x];
        x-=lowbit(x);
    }
    return ans;
}
inline ll Q(ll val)
{
    return lower_bound(a1+1,a1+1+m,val)-a1;
}
int main()
{
    ll n,i;
    read(n);
    for(i=1;i<=n;i++)
    {
        read(a[i]);
        a1[i]=a[i];
    }
    sort(a1+1,a1+1+n);
    m=unique(a1+1,a1+1+n)-(a1+1);
    for (int i = 1; i <= n; i++) {
        printf("%d ",  Q(a[i]));
    }
}
