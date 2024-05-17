#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,c,h,sh;

vector<vector<int> > C(3 , vector<int>());
vector<bool> mark;
ll TWO[30] = {0};

int ctn(char ch){
    if(ch == 'R')return 0;
    if(ch == 'G')return 1;
    if(ch == 'B')return 2;
    return -1;
}

void addedge(int i, int j, int col){
    C[col][i] = j;
    C[col][j] = i;
}

void addnode(){
    C[0].push_back(-1);
    C[1].push_back(-1);
    C[2].push_back(-1);
    mark.push_back(0);
}

int notc(int i, int j){
    if(i+j == 1)return 2;
    if(i+j == 2)return 1;
    if(i+j == 3)return 0;
    return -1;
}

pair<string,string> cyclify(string s){
    string ans = "";
    for(int c1 = 0; c1 < s.length(); c1++){
        if(ans.length() == 0){
            ans += s[c1];
        }
        else{
            if(ans[ans.length()-1] == s[c1]){
                ans.pop_back();
            }
            else{
                ans += s[c1];
            }
        }
    }

    string ans2 = "";
    if(ans.length() > 0){
        while(ans[0] == ans[ans.length()-1]){
            ans2 += ans[0];
            ans.erase(0,1);
            if(ans.length() == 0)break;
            ans.pop_back();
            if(ans.length() == 0)break;
        }
    }
    return {ans , ans2};
}

void make_tree(int leftc , int rightc , int height, int root){
    if(height == 0)return;
    addnode();
    int ro = C[0].size()-1;
    int nc = notc(leftc , rightc);
    addedge(root , ro , nc);
    if(height == 1)return;
    make_tree(leftc , nc , height-1 , ro);
    make_tree(nc , rightc , height-1, ro);
    addedge(ro + TWO[height-1] - 1 , ro + TWO[height-1] + height - 2 , nc);
}

int get_start(string s){
    int i = 0;
    for(int c1 = s.length()-1; c1 >= 0; c1--){
        i = C[ctn(s[c1])][i];
    }
    return i;
}

int get_end(int start, string s){
    mark[start] = 1;
    int i = start;
    for(int c1 = 0; c1 < n; c1++){
        i = C[ctn(s[c1])][i];
        mark[i] = 1;
    }
    for(int c1 = 0; c1 < C[0].size(); c1++){
        if(mark[c1] == 0)return c1;
    }
    return -1;
}

int main()
{
    int c1,c2,c3,c4;

    ll t = 1;
    for(c1 = 0; c1 < 30; c1++){
        TWO[c1] = t;
        t *= 2;
    }

    string s;
    cin >> s;
    n = s.length();
    pair<string,string> P = cyclify(s);
    string cyc = P.first;
    string piece = P.second;
    c = cyc.length();

    if(c == 0){
        h = 1;
        sh = 2;
        while(3*sh-2 <= n){
            h++;
            sh *= 2;
        }
        sh--;
        addnode();
        make_tree(2,0,h,0);
        make_tree(0,1,h,0);
        make_tree(1,2,h,0);
        addedge(sh,sh+h,0);
        addedge(2*sh,2*sh+h,1);
        addedge(3*sh,h,2);
    }
    else{
        h = 1;
        sh = 2;
        while(sh*c <= n){
            h++;
            sh *= 2;
        }
        sh--;

        for(c1 = 0; c1 < c; c1++)addnode();

        for(c1 = 0; c1 < c; c1++){
            addedge(c1 , (c1+1)%c , ctn(cyc[c1]));
        }

        for(c1 = 0; c1 < c; c1++){
            make_tree(ctn(cyc[(c1-1+c)%c]) , ctn(cyc[c1]) , h , c1);
        }

        for(c1 = 0; c1 < c; c1++){
            int i = c1;
            int j = (c1+1)%c;
            addedge(c+(i+1)*sh-1 , c+j*sh+h-1 , ctn(cyc[c1]));
        }
    }

    int start = get_start(piece);
    int goal = get_end(start , s);
    cout << C[0].size() << " " << start << " " << goal << "\n";
    for(c1 = 0; c1 < C[0].size(); c1++){
            for(c2 = 0; c2 < 3; c2++){
                cout << C[c2][c1] << " ";
            }
            cout << "\n";
        }

    return 0;
}
