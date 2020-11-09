#include"bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;

#define INF INT_MAX
#define _INF INT_MIN
#define M 1000000007
#define endl '\n'
#define fi(a,n) for(ll i=a;i<n;i++)
#define fj(a,n) for(ll j=a;j<n;j++)
#define fauto(a) for(auto it:a)
#define pb(n) push_back(n)
#define pf(n) push_front(n)
#define mp(a,b) make_pair(a,b)
#define xx first
#define yy second
#define debug(x) cerr << #x << " = " << x << endl;

//Parity of n __builtin_parity(n)
//Number of set bits __builtin_popcount(n)

ll power(ll a, ll n)
{
    ll f=1;
    for(ll i=1;i<=n;i++)
        f*=a;
    return f;
}

inline bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.second < b.second);
}


inline bool PoT(ll x)
{
   return (x && !(x & (x-1)));
}


ll XNOR(ll a, ll b)
{
    ll x=log2(max(a,b))+1;
    ll tmp=(1<<x)-1;
    return tmp-(a^b);
}

int main()
{
    #ifdef HOME 
        freopen("ip.txt", "r", stdin); 
        freopen("op.txt", "w", stdout); 
    #endif 

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    clock_t clk_start,clk_end; 
    clk_start=clock();
    ll t=1;
    cin>>t;
    for(ll _=0;_<t;_++)
    {
        ll n;
        cin>>n;
        ll a[n+1]={0};
        fi(0,n)
            cin>>a[i+1];
        ll pan=0,ans[n+1]={0};

        ll i=1;
        while(i<n){
            ans[i]=max(pan+a[i],ans[i-1]);
            pan+=a[i]-(a[i]%2);
            if(a[i]==1){
                ll tmp=a[i-1]%2;
                if(tmp==0){
                    for (ll j=1;a[i]==1 && i<n;j++,i++){
                        pan-=(j%2);
                        pan+=2*(j%2==0);
                        ans[i+1]=max(ans[i],pan+a[i+1]);
                    }
                }
                else{
                    for (ll j=1;a[i]==1 && i<n;j++,i++){
                        pan+=(j%2==1);
                        ans[i+1]=max(ans[i],pan+a[i+1]);
                    }   
                }
                i--;
            }

            i++;
        }
        ans[i]=max(a[i-1],pan+a[i]);
        pan+=a[i]-(a[i]%2==0);
        debug(pan);
        fauto(ans)
            cout<<it<<" ";cout<<endl;

        ll q;
        cin>>q;
        while(q--){
            ll r,mastr;
            cin>>r;
            mastr=(r/n)*pan;
            if(r%n!=0)
                mastr+=ans[r%n];
            else{
                mastr-=pan;
                mastr+=ans[n];
            }
            cout<<mastr<<endl;
        }

    }
    clk_end=clock();

    #ifdef HOME 
        cerr<<fixed << double(clk_end-clk_start)/double(CLOCKS_PER_SEC)<< setprecision(5)<<endl; 
    #endif 

    return 0;

}