#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=(b); a <(c); a++)
#define sz(a) int(a)

string text;

int section(int p){
	char type = text[p];
	int len = 0;
	while(p+len < int(text.size()) && text[p+len] == type)
		len ++;
	return len;
}

int main(){
	unordered_map<string, char> mp;
	mp[" "] = ' ';
	rep(i, 0, 26){
		char c;
		string s;
		cin >> c >> s;
		mp[s] = c;
	}

	int s, p, t, b, m, n;
	cin >> s >> p >> t >> b >> m >> n >> text;

	// add letter break in the end
	rep(i, 0, b)
		text.push_back('0');

	int pos = 0;
	string cur = "";
	vector<string> v;
	while(pos < int(text.size())){
		int len = section(pos);
		if (text[pos] == '1'){
			if (len == p)
				cur.push_back('.');
			else if (len == s)
				cur.push_back('-');
			else assert(0);
		} else {
			if (len == t)
				;
			else if (len == b)
				v.push_back(cur), cur = "";
			else if (len == m)
				v.push_back(cur), v.push_back(" "), cur = "";
			else assert(0);
		}

		pos += len;
	}

	for(string str : v)
		cout << mp[str];
	cout << endl;
}