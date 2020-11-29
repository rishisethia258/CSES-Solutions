// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define RB rb_tree_tag
#define TSNU tree_order_statistics_node_update
template <typename T>
using oset = tree<T,null_type,less<T>,RB,TSNU>;
template <typename T>
using omultiset = tree<T,null_type,less_equal<T>,RB,TSNU>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vpair      vector<pll>
#define fi         first
#define se         second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define mx(a)      *max_element(all(a))
#define mn(a)      *min_element(all(a))
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define yes()      cout<<"YES"<<endl
#define no()       cout<<"NO"<<endl
#define err()      cout<<"===========\n";
#define errA(A)    for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)    cout<<#a<<" "<<a<<"\n"
#define err2(a,b)  cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;


void solve() {
    ll n,m;
    cin >> n >> m;
    vll x(n);
    fr(i,0,n) {
        cin >> x[i];
    }
    vll a(m+1);
    if(x[0] == 0) {
        fr(i,1,m+1) {
            a[i] = 1;
        }
    } else {
        a[x[0]] = 1;
    }

    fr(i,1,n) {
        vll b(m+1,0);
        if(x[i] == 0) {
            fr(j,1,m+1) {
                (b[j] += a[j]) %= mod1;
                if(j != 1) {
                    (b[j] += a[j-1]) %= mod1;
                } 
                if(j != m) {
                    (b[j] += a[j+1]) %= mod1;
                }
            }
        } else {
            (b[x[i]] += a[x[i]]) %= mod1;
            if(x[i] != 1) {
                (b[x[i]] += a[x[i]-1]) %= mod1;
            }
            if(x[i] != m) {
                (b[x[i]] += a[x[i]+1]) %= mod1;
            }
        }
        a = b;
    }

    ll ans = 0;
    fr(i,1,m+1) (ans += a[i]) %= mod1;
    cout << ans << endl;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}