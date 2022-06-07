#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> v;
    vector<vector<int>> v_v;
    unordered_map<int, int> overlap;
    string temp_str;
    for (auto ch : s)
    {
        if (isdigit(ch)) {temp_str+= ch;}
        else
        {
            
            if(!temp_str.empty()) 
            {
                v.emplace_back(stoi(temp_str));
                overlap.insert(make_pair(stoi(temp_str), 0));
                temp_str.clear();
            }
            if (ch == '}')
            {
                v_v.emplace_back(v);
                v.clear();
            }
        }
    }
    
    sort(v_v.begin(), v_v.end(), [](vector<int> a, vector<int> b) -> bool
                             {if(a.size() < b.size()) return true; else return false;});
    
     for (auto v : v_v)
        for (auto d : v)
        {
            if (overlap[d] == 0) {answer.emplace_back(d); overlap[d] = 1;}
        }
    return answer;
}