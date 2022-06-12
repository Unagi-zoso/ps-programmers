#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void parse_info(string &s, string &l, string &p, string &r, string &f, int &score)
{
    l = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    p = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    r = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    f = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    score = stoi(s);
}
// find char만 찾나보네
void parse_query(string &s, string &l, string &p, string &r, string &f, int &score)
{
    l = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' ')); 
                                  s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    p = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
                                  s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    r = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
                                  s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    f = s.substr(0, s.find(' ')); s = s.substr(s.find(' ')+1, s.size()-s.find(' '));
    score = stoi(s);
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> m;
    string lang; string pos; string role; string food; int score;
    for (auto s : info)
    {
        parse_info(s, lang, pos, role, food, score);
        m[lang][pos][role][food].emplace_back(score);
        
        m["-"][pos][role][food].emplace_back(score);
        m[lang]["-"][role][food].emplace_back(score);
        m[lang][pos]["-"][food].emplace_back(score);
        m[lang][pos][role]["-"].emplace_back(score);
        
        m["-"]["-"][role][food].emplace_back(score);
        m["-"][pos]["-"][food].emplace_back(score);
        m["-"][pos][role]["-"].emplace_back(score);
        m[lang]["-"]["-"][food].emplace_back(score);
        m[lang]["-"][role]["-"].emplace_back(score);
        m[lang][pos]["-"]["-"].emplace_back(score);
        
        m["-"]["-"]["-"][food].emplace_back(score);
        m["-"][pos]["-"]["-"].emplace_back(score);
        m["-"]["-"][role]["-"].emplace_back(score);
        m[lang]["-"]["-"]["-"].emplace_back(score);
        
        m["-"]["-"]["-"]["-"].emplace_back(score);        
    }

    int count;
    for (auto q : query)
    {
        count = 0;
        parse_query(q, lang, pos, role, food, score);
        for (auto i : m[lang][pos][role][food])
        {
            if (i >= score) count++;
        }
        answer.emplace_back(count);
    }
    
    
    return answer;
}