#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int x, a, y, b, n;
int dp[1005][1005];

// Funktion för att kontrollera om det går att skapa minst n grupper med värde >= T
bool check(long long T) {
    if (T == 0) return true;
    
    // Generera minimala par (u, v) som ger ett värde på minst T
    vector<pair<int, int>> items;
    int last_v = -1;
    for (int u = 0; u <= x; ++u) {
        long long required_val = T - (long long)u * a;
        long long v = 0;
        if (required_val > 0) {
            v = (required_val + b - 1) / b; // Motsvarar takfunktionen (ceil)
        }
        if (v > y) continue;
        if (last_v == -1 || v < last_v) {
            items.push_back({u, v});
            last_v = v;
        }
    }
    
    // Om inga giltiga dator-kombinationer kan bilda värdet T
    if (items.empty()) return false;
    
    // Nollställ DP-tabellen för det aktuella testet
    for (int i = 0; i <= x; ++i) {
        memset(dp[i], 0, (y + 1) * sizeof(int));
    }
    
    // Utför 2D Unbounded Knapsack
    for (auto& item : items) {
        int u = item.first;
        int v = item.second;
        for (int i = u; i <= x; ++i) {
            for (int j = v; j <= y; ++j) {
                if (dp[i - u][j - v] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - u][j - v] + 1;
                }
            }
        }
    }
    
    return dp[x][y] >= n;
}

int main() {
    // Optimera standard-I/O-strömmar för snabbare körning
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> x >> a >> y >> b >> n)) return 0;
    
    long long low = 0;
    // Det absolut maximala genomsnittliga värdet en avdelning kan få
    long long high = ((long long)x * a + (long long)y * b) / n;
    long long ans = 0;
    
    // Binärsök efter det optimala värdet
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1; // Försök hitta ett ännu högre värde
        } else {
            high = mid - 1; // Minska målvärdet
        }
    }
    
    cout << ans << "\n";
    return 0;
}
