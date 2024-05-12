#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;

bool valid(int N, char c){
    return 'A' <= c < 'A' + N; 
}

void run() {
    int maxN = Arg("maxN", 15);

    int N = Int(2, maxN);
    Space();
    int K = Int(1, N);
    Endl();
    
    vector<string> data;
    for (int i = 0; i < K; i++){
        string s = Line();
        data.push_back(s);
    }
    
    
    if (data.size() != K){
        die("There are not enough rows of input.");
    }

    set<pair<char,char> > seen;

    for (int i = 0; i < K; i++){
        string line = data[i];
        char ch = line[0];
        char form = line[1];

        assert(valid(N, ch));
        assert(seen.count({ch, form}) == 0);

        seen.insert({ch, form});

        if (form == '@'){
            // # exempel: C@01,05,12
            for (int j = 4; j < line.size(); j += 3){
                assert(line[j] == ',');
            }

            // line.split(",")
            string str = line.substr(2,line.size()-2);
            vector<string> nums;
            set<string> set_nums;
            stringstream ss(str);
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                nums.push_back(substr);
                set_nums.insert(substr);
            }

            // Check if the nums are unique
            assert(nums.size() == set_nums.size());

            for (int j = 0; j < nums.size(); j++){
                int num = stoi(nums[j]);
                assert(0 < num && num <= N);
            }

        }
        else{
            //  # exempel: B:DEF
            assert(form == ':');

            string chars = line.substr(2,line.size()-2);

            vector<char> characters;
            set<char> set_chars;
            for (int j = 0; j < chars.size(); j++){
                characters.push_back(chars[j]);
                set_chars.insert(chars[j]);
                assert(valid(N,chars[j]));
            }

            // Check if the characters are unique
            assert(set_chars.size() == characters.size());

        }

    }


    Eof();
}