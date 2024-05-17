#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution when all numbers D[i][j] (i != j) are the same

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];        
    }
    vector<vector<int>> D(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    int d0 = D[0][1];
    int minPos = min_element(S.begin(), S.end()) - S.begin();
    int totalSize = S[minPos];
    for (int i = 0; i < N; i++) {
        if (i != minPos) {
            totalSize += min(S[i], d0);
        }
    }
    cout << totalSize << '\n';
    return 0;
}
