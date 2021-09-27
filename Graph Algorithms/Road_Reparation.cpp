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

struct dsu {
    ll n;
    vll p, r;
    dsu(ll _n) : n(_n) {
        r.resize(n + 1, 0);
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    inline ll get(ll x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline bool unite(ll x, ll y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (r[x] < r[y]) {
                swap(x, y);
            }
            p[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
            return true;
        }
        return false;
    }
};

template <typename T>
struct graph {
    struct edge {
        ll from, to;
        T cost;
    };
    ll n;
    bool directed;
    vector<edge> edges;
    vector<vector<ll>> g;
    graph(ll _n, bool d = false) {
        n = _n;
        directed = d;
        g.resize(n + 1);
    }
    ll add(ll u, ll v, T c = 1) {
        ll id = (ll)edges.size();
        g[u].pb(id);
        if(!directed) {
            g[v].pb(id);
        }
        edges.push_back({u, v, c});
        return id;
    }
};

template <typename T>
vector<int> find_mst(const graph<T> &g, T &ans) {
	vector<int> order(g.edges.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&g](int a, int b) {
		return g.edges[a].cost < g.edges[b].cost;
	});
	dsu d(g.n);
	vector<int> ans_list;
	ans = 0;
	for (int id : order) {
		auto &e = g.edges[id];
		if (d.get(e.from) != d.get(e.to)) {
			d.unite(e.from, e.to);
			ans_list.push_back(id);
			ans += e.cost;
		}
	}
	return ans_list;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    graph<ll> g(n);
    dsu d(n);
    fr(i, 0, m) {
    	ll a, b, c;
    	cin >> a >> b >> c;
    	d.unite(a, b);
    	g.add(a, b, c);
    }
    set<ll> s;
    fr(i, 1, n + 1) {
    	s.insert(d.get(i));
    }
    if(s.size() != 1) {
    	cout << "IMPOSSIBLE" << endl;
    	return;
    }
    ll ans = 0;
    find_mst<ll>(g, ans);
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
