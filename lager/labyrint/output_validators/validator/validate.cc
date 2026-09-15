#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

struct UF {
    vi par;
    UF(int n) : par(n) {iota(all(par),0);}
    int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
    int merge(int a, int b) {
        par[a=find(a)] = b=find(b);
        return a!=b;
    }
};

int main(int argc, char **argv) {
    init_io(argc, argv);

    string s;
    judge_in >> s;
    int maxn = 2*sz(s);
    for (char& c : s) {
        if (c=='R') c = 0;
        if (c=='G') c = 1;
        if (c=='B') c = 2;
    }

    auto check = [&](istream& sol, feedback_function feedback) {
        int n, start, goal;
        if (!(sol >> n >> start >> goal)) feedback("Expected more output");
        if (n <= 1 || n > maxn) feedback("Invalid size");
        if (start < 0 || goal < 0 || start >= n || goal >= n) feedback("Invalid index for start or goal");
        if (start == goal) feedback("Start = goal");

        UF uf(n);
        int ncomps = n;
        array<vector<int>, 3> ed;
        rep(i,0,3) ed[i] = vector<int>(n);
        rep(i,0,n) rep(j,0,3) {
            if (!(sol >> ed[j][i])) feedback("Expected more output");
            if (ed[j][i] < 0 || ed[j][i] >= n) feedback("Edge index out of range");
            if (ed[j][i] == i) feedback("Self loop");
            ncomps -= uf.merge(i, ed[j][i]);
        }

        rep(i,0,n) rep(j,0,3) {
            if (ed[j][ed[j][i]] != i) feedback("Graph is not undirected");
        }

        if (ncomps != 1) feedback("Disconnected graph");

        // Every component is a cycle. No need for hare/tortoiste
        int pos=start,ind=0;
        const int MAX_STEPS = 1e9;
        int i = 0;
        for (; i < MAX_STEPS; i++) {
            pos = ed[s[ind]][pos];
            ind++;
            ind = (ind==sz(s) ? 0 : ind);
            if (pos == goal) feedback("WA: reaches goal");
            if (pos == start && ind == 0) break;
        }

        if (i == MAX_STEPS) {
            // The previous loop timed out: instead try all rooms at the same time
            // You can show that test case 2's period is bounded by 2|S|, and will thus never reach here
            // Test case 1 is big, but will finish fast enough in this loop
            // All other test cases are sufficiently small that we don't need to worry
            vector<int> positions(n);
            vector<char> saw_goal(n);
            saw_goal[goal] = 1;
            rep(i,0,n) positions[i]=i;

            for (int j = 0; j < sz(s); j++) {
                vector<int>& edg = ed[s[j]];

                for (int k = 0; k < n; k++) {
                    positions[k] = edg[positions[k]];
                    saw_goal[k] |= positions[k] == goal;
                }
            }

            // positions[i] = where do i end up if i walk sz(s) steps forward
            // saw_goal[i] = do i see goal if i walk sz(s) steps forward
            int pos = start;
            vi seen(n);
            while (true) {
                if (saw_goal[pos]) feedback("WA: reaches goal");
                if (seen[pos]) break;
                seen[pos] = 1;
                pos = positions[pos];
            }
        }
        

        string trailing;
        if(sol >> trailing) feedback("Trailing output");
        return n;
    };

    int judge_n = check(judge_ans, judge_error);
    int author_n = check(author_out, wrong_answer);

    if (judge_n == maxn) judge_error("Bad judge solution. Score is undefined if n==2|S|");

    double rat1 = max(author_n / (double)judge_n, 1.0);
	double rat2 = maxn / (double)judge_n;
	double rat = log(rat1) / log(rat2);
	double score = 10 * (1 - rat);
	if (sz(s)==3) accept_with_score(0); // sample never gives score
	accept_with_score(min(10.0,score));
}
