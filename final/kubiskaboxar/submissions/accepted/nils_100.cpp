#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> L;
    vector<char> C;

    cin >> n;

    for(int c1 = 0; c1 < n; c1++){
        char ch;
        int a;
        cin >> a >> ch;
        L.push_back(a);
        C.push_back(ch);
    }
    string rgb = "RGB";
    int ans = n+1;
    string ans2 = rgb;

    for(int c1 = 0; c1 < 6; c1++){
        vector<int> B1;
        vector<int> B2;
        vector<int> B3;

        for(int c2 = 0; c2 < n; c2++){
            if(C[c2] == rgb[0]){
                B1.push_back(L[c2]);
            }
            if(C[c2] == rgb[1]){
                B2.push_back(L[c2]);
            }
            if(C[c2] == rgb[2]){
                B3.push_back(L[c2]);
            }
        }

        sort(B1.begin() , B1.end());
        sort(B2.begin() , B2.end());
        sort(B3.begin() , B3.end());
        int tempans = n;

        //Small in middle
        for(int c2 = 0; c2 < B2.size(); c2++){
            int ma = -1;
            int ml = -1;
            for(int c3 = 0; c3 < B3.size(); c3++){
                if(B3[c3] < B2[c2] && B3[c3] > ml){
                    ma = c3;
                    ml = B3[c3];
                }
            }
            if(ma != -1){
                tempans--;
                B3[ma] = 13333333337;
            }
        }

        //Middle in big
        for(int c2 = 0; c2 < B1.size(); c2++){
            int ma = -1;
            int ml = -1;
            for(int c3 = 0; c3 < B2.size(); c3++){
                if(B2[c3] < B1[c2] && B2[c3] > ml){
                    ma = c3;
                    ml = B2[c3];
                }
            }
            if(ma != -1){
                tempans--;
                B2[ma] = 13333333337;
            }
        }

        if(tempans < ans){
            ans = tempans;
            ans2 = rgb;
        }

        next_permutation(rgb.begin() , rgb.end());
    }

    cout << ans2[2] << " i " << ans2[1] << "\n" << ans2[1] <<  " i " << ans2[0] << "\n" << ans << "\n";

    return 0;
}
