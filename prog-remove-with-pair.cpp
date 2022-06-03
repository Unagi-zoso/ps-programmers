#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    for (auto ch : s)
    {
        if (!stk.empty() && stk.top() == ch)
            stk.pop();
        else stk.push(ch);        
    }
    if (stk.empty()) return 1;
    return 0;
}