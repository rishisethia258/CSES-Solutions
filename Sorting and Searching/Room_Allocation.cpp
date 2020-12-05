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
 
bool compare(pair<pll,ll> a, pair<pll,ll> b) {
    return a.first.second < b.first.second;
}
 
void solve() {
    ll n;
    cin >> n;
    multiset<ll> s1,s2;
    vector<pair<pll,ll>> p(n);
    fr(i,0,n) {
        ll a,b;
        cin >> a >> b;
        p[i].first.first = a;
        p[i].first.second = b;
        p[i].second = i;
        s1.insert(a);
        s2.insert(b);
    }
    ll ans = 0, c = 0;
    while(!s1.empty()) {
        if(*s1.begin() <= *s2.begin()) {
            s1.erase(s1.begin());
            c++;
        } else {
            s2.erase(s2.begin());
            c--;
        }
        ans = max(ans,c);
    }
    cout << ans << endl;
    sort(all(p));
    ll k = 0;
    vll res(n);
    set<pll> room;
    fr(i,0,ans) {
        room.insert({p[i].first.second,i+1});
        res[p[i].second] = i+1;
    }
    fr(i,ans,n) {
        pll u = *room.begin();
        res[p[i].second] = u.second;
        room.erase(room.begin());
        room.insert({p[i].first.second, u.second});
    }
    errA(res);
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