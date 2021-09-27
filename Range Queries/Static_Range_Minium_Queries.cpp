// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
template <typename T>
using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, 
tree_order_statistics_node_update>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vvbool     vector<vbool>
#define vstr       vector<string>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
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
const ld eps  =    1e-9;

ll test_case = 0;
void google() {
    test_case++;
    cout << "Case #" << test_case << ": ";
}

ll pwr(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
        if (b & 1) res = (res * a);   
        a = (a * a); b >>= 1;
    }
    return res;
}

ll modpwr(ll a, ll b, ll x = mod1) {
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a) % x;
        a = (a * a) % x; b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p = mod1) { 
    return modpwr(n, p - 2, p); 
}

template <typename T, class F = function<T(const T&, const T&)>>
struct sparseTable {
    ll n;
    vector<vector<T>> x;
    F func;

    sparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<ll>(a.size());
        ll max_log = 32 - __builtin_clz(n);
        x.resize(max_log);
        x[0] = a;
        for (ll j = 1; j < max_log; j++) {
            x[j].resize(n - (1 << j) + 1);
            for (ll i = 0; i <= n - (1 << j); i++) {
                x[j][i] = func(x[j - 1][i], x[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(ll u, ll v) const {
        assert(0 <= u && u <= v && v <= n - 1);
        ll lg = 32 - __builtin_clz(v - u + 1) - 1;
        return func(x[lg][u], x[lg][v - (1 << lg) + 1]);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    fr(i, 0, n) {
        cin >> a[i];
    }
    sparseTable<ll> st(a, [&](ll i, ll j) {
        return min(i, j);
    });

    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        cout << st.get(l, r) << endl;
    }
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
