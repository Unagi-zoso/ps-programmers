#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // stack<char> stk;
    string s = std::move(new_id);
    string temp_str;

    transform(s.begin(), s.end(), s.begin(),  [](unsigned char c) -> 
                   unsigned char { return std::tolower(c); });
    
    for (auto ch : s)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
            || ch == '-' || ch == '_' || ch == '.')
        {
            
            temp_str.push_back(ch);
        }
    } 
    s = move(temp_str);
    temp_str.clear();
    
    /** lv3 using stack
    stk.push('.');
    for (auto ch : s)
    {
        if (stk.top() == '.' && ch == '.') stk.pop();
        stk.push(ch);
    }
    while (!stk.empty())
    {
        temp_str.push_back(stk.top());
        stk.pop();
    }
    s = move(temp_str);
    reverse(s.begin(), s.end()); **/
    
    /** lv3 using for-each **/
    for (auto ch : s)
    {
        if (temp_str.back() == '.' && ch == '.') continue;
        temp_str.push_back(ch);
    }
    s = move(temp_str); 
    
    if (s.front() == '.') s.erase(s.begin());
    if (s.back() == '.') s.erase(s.end() - 1);
    if (s.empty()) s.push_back('a');
    if (s.size() >= 16) s.erase(s.begin() + 15, s.end());
    if (s.back() == '.') s.erase(s.end() - 1);
    
    if (s.size() <= 2)
    {
        for (; s.size() < 3;)
        {

            s += *(s.end() - 1);
        }
    }

    answer = std::move(s);
    return answer;
}