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
    string s;
    cin >> s;
    ll n = s.size();
    vll cnt(26);
    fr(i,0,n) {
        cnt[s[i] - 'A']++;
    }
    ll oc = 0;
    fr(i,0,26) {
        if(cnt[i] & 1) {
            oc++;
        }
    }
    if(n & 1) {
        if(oc != 1) {
            cout << "NO SOLUTION" << endl;
            return;
        }
        fr(i,0,26) {
            if(cnt[i] % 2 == 0){
                fr(j,0,cnt[i]/2) {
                    cout << char(i + 'A');
                }
            }   
        }
        fr(i,0,26) {
            if(cnt[i] % 2 == 1){
                fr(j,0,cnt[i]) {
                    cout << char(i + 'A');
                }
            }   
        }
        rf(i,25,0) {
            if(cnt[i] % 2 == 0){
                fr(j,0,cnt[i]/2) {
                    cout << char(i + 'A');
                }
            }   
        }
    } else {
        if(oc != 0) {
            cout << "NO SOLUTION" << endl;
            return;
        }
        fr(i,0,26) {
            if(cnt[i] % 2 == 0){
                fr(j,0,cnt[i]/2) {
                    cout << char(i + 'A');
                }
            }   
        }
        rf(i,25,0) {
            if(cnt[i] % 2 == 0){
                fr(j,0,cnt[i]/2) {
                    cout << char(i + 'A');
                }
            }   
        }
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