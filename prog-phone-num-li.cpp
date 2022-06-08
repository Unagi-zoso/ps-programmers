#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> p) {
    bool answer = true;  
    unordered_set<string> h_s;
    for (auto s : p)
    {
        h_s.insert(s);
    }
    for (auto s : p)
    {
        for (int i=1; i<s.size(); i++)
        {
            if (h_s.find(s.substr(0,i)) != h_s.end()) {answer = false; break;}
        }
        if (answer == false) break;
    }
    
    return answer;
}