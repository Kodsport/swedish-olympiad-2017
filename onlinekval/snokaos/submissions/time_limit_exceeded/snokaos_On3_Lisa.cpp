#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int > > > save;
vector<vector<int> > travel;
vector<bool> snow;
int n;

int dp(int k, int last, int pos) {
    if(k < 0) return -1e9;
    if(pos == n) return 0;
    if(save[k][last][pos] != -1) return save[k][last][pos];
    int ans = -1e9;
    if(!snow[pos]) {
        ans = travel[last][pos] + dp(k, last, pos+1);
    }
    else {
        ans = travel[last][pos] + dp(k-1, last, pos+1);
        ans = max(ans, travel[pos][last] + dp(k, pos+1, pos+1));
    }
    return save[k][last][pos] = ans;
}

int main() {
    int m, s, p;
    cin >> n >> m >> s >> p;
    vector<vector<int> > resor(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        //det spelar ingen roll åt vilket håll folk åker,
        //så vi antar att de alltid åker från vänster till höger.
        if(a > b) swap(a, b);
        resor[a][b]++;
    }
    snow.assign(n, false);
    for(int i = 0; i < s; i++) {
        int a;
        cin >> a;
        a--;
        snow[a] = true;
    }
    save.assign(p+1, vector<vector<int> >(n, vector<int>(n, -1)));
    travel.assign(n, vector<int>(n, 0));
    for(int last = 0; last < n; last++) {
        int ans = 0;
        for(int pos = last; pos < n; pos++) {
            ans+= resor[last][pos];
            travel[last][pos] = ans;
        }
    }
    cout << dp(p, 0, 0) << endl;
}