#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define st string
#define eb emplace_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define maxe(x) *max_element(x.begin(), x.end());
#define mine(x) *min_element(x.begin(), x.end());
#define sum(x) accumulate(x.begin(), x.end(), 0);
#define set_bits __builtin_popcountll
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define v vector<long long>
#define vv vector<v>

vector<ll> fac(n, 0); // only declare in case of inverse
vector<ll> invfac(n, 0); // only declare in case of inverse
vector<bool> is_prime(n+1, true); // only declare in case of sieve

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

ll pow(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll inv(ll a, ll b) {return pow(a, b - 2, b);}
ll nCr(ll a, ll b, ll m) { if (a < b) return 0; if (b == 0) return 1; return ((fac[a] * invfac[b]) % m * invfac[a - b]) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, inv(b, m), m) + m) % m;}

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void inverse() {
    fac[0] = 1; 
    ll i;
    for(i = 1; i < n; i++) {
        fac[i] = (fac[i - 1] * i) % m;
    }
    i--;
    invfac[i] = pow(fac[i], m-2, m);
    for(i--; i >= 0; i--) {
        invfac[i] = (invfac[i + 1] * (i + 1)) % m;
    }
}


int main() {
    fastio

    return 0;
}
