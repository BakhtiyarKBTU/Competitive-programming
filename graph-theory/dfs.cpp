#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int MAX_LEN = 200200;

int n, m;
vector<pii> bridges;
vector<int> g[MAX_LEN];
int cnt = 1, used[MAX_LEN], c[MAX_LEN], tin[MAX_LEN], fup[MAX_LEN], timer = 1;

/*dfs by Sabo */
void dfs(int from){
    used[from] = cnt;
    for(int i = 0; i < sz(g[from]); i++){
        int to = g[from][i];
        if(used[to] != cnt) dfs(to);
    }
}

/* find cycle */
int cycle(int from){
    c[from] = 1;
    for(int i = 0; i < sz(g[from]); i++){
        int to = g[from][i];
        if(c[to] == 0){ 
            if(dfs(to)) return 1;
        }
        else if(c[to] == 1) return 1;
    }
    c[from] = 2;
    return 0;
}

/* find bridges */
map < pair <int, int>, bool > was;
void bridge(int from, int parent){
    tin[from] = fup[from] = timer++;
    for(int i = 0; i < sz(g[from]); i++){
        int to = g[from][i];
        if(to != parent){
            dfs(to, from);
            if(fup[to] == tin[to]) {
                int x = min(to, from);
                int y = max(to, from);
                if(m[mp(x, y)] == 0){
                    m[mp(x, y)] = 1;
                    bridges.pb(mp(from, to));
                }
                fup[from] = min(fup[from], fup[to]);
            }
            else{
                fup[from] = min(fup[from], tin[to]);
            }
        }
    }
}

int main(){
    return 0;
}
