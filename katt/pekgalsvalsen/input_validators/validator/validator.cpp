#include "validator.h"

void run() {
	int n = Int(1, Arg("maxn"));
	Space();
	int k = Int(1, Arg("maxk"));
	Endl();

	if ((bool)Arg("k_2", 0)) assert(k==2);
	
	string in = Line();
	assert(in.size()==n);
	vector<int> seen(256);
	for (int i = 0; i < n; i++)
	{
		assert(in[i]>='a');
		assert(in[i]<=('a'+k-1));
		seen[in[i]]=1;
	}
	int seencnt = 0;
	for (int i = 0; i < 256; i++) seencnt += seen[i];
	assert(seencnt==k);
	

	Eof();
}
