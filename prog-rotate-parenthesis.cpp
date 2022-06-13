#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

bool is_corr(stack<char> stk, deque<char> &dq)
{
    for (auto ch : dq)
    {
        if (!stk.empty())
            if ((stk.top() == '{' && ch == '}') || (stk.top() == '[' && ch == ']') || (stk.top() == '(' && ch == ')'))
            {    stk.pop(); continue;}
        
        stk.push(ch);
    }
    if (stk.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    stack<char> stk;
    deque<char> dq;
    
    for (auto ch : s)
        dq.emplace_back(ch);
    
    for (int i = 0; i < dq.size() - 1; i++)
    {
        if (is_corr(stk, dq) == true) answer++;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    
    return answer;
}