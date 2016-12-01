#include <bits/stdc++.h>

using namespace std;

struct Contestant {
	string name;
	int year;
	vector<int> scores;
	vector<double> nscores;

	bool operator<(const Contestant& other) const {
		double sc1 = sc();
		double sc2 = other.sc();
		if (sc1 != sc2) return sc1 > sc2;
		return name < other.name;
	}
	double sc() const {
		return accumulate(nscores.begin(), nscores.end(), -*min_element(nscores.begin()+1, nscores.end()));
	}
};

int main() {
	int N;
	cin >> N;
	map<string, Contestant> m;
	vector<vector<int>> allsc(4);
	for (int i = 0; i < N; i++) {
		string name;
		int year;
		cin >> name >> year;
		Contestant& c = m[name];
		c.name = name;
		c.year = year;
		for (int j = 0; j < 4; ++j) {
			int x;
			cin >> x;
			c.scores.push_back(x);
			allsc[j].push_back(x);
		}
	}
	auto norm = [](double med, double mx, double score) {
		if (score < med) return 50 * score / med;
		else return 50 + 50 * (score - med) / (mx - med);
	};
	for (int j = 0; j < 4; ++j) {
		vector<int>& sc = allsc[j];
		sort(sc.begin(), sc.end());
		double mx = sc.back();
		double med = N%2 ? sc[N/2] : (sc[N/2] + sc[N/2-1])/2.0;
		for(auto& it : m) {
			Contestant& c = it.second;
			c.nscores.push_back(norm(med, mx, c.scores[j]));
		}
	}
	set<Contestant> cont;
	for(auto& it : m) {
		Contestant& c = it.second;
		cont.insert(c);
	}
	set<string> ioi;
	set<string> boi;
	
	for(auto& it : cont) {
		if (ioi.size() < 4) {
			ioi.insert(it.name);
		} else if (boi.size() < 2 && it.year != 3) {
			boi.insert(it.name);
		}
	}
	for(auto& it : ioi) {
		cout << it << " ";
	}
	cout << endl;
	for(auto& it : boi) {
		cout << it << " ";
	}
	cout << endl;
}
