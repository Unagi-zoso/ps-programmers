#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

void parser_op(string s, vector<string> &res)
{
    string temp_str;
    for (auto ch : s)
    {
        if (isdigit(ch))
            temp_str += ch;
        else
        {
            res.emplace_back(temp_str);
            temp_str = ch;
            res.emplace_back(temp_str);
            temp_str.clear();
        }
    }
    if (!temp_str.empty())
        res.emplace_back(temp_str);
}

long long solution(string expression) {
    vector<string> e;
    vector<string> t_e;
    long long answer = 0;
    stack<string> stk;
    vector<unsigned long long> result;
    vector<string> op = { "+", "-", "*" };
    sort(op.begin(), op.end());

    parser_op(expression, e);

    string t;
    string t2;
    do
    {
        t_e = e;
        for (auto o : op)
        {

            for (int i = 0; i < t_e.size(); i++)
            {
                if (!stk.empty() && t_e[i] == o)
                {
                    t = stk.top();
                    t2 = t_e[i + 1];
                    stk.pop();
                    if (o == "*")
                    {
                        stk.push(to_string(stoll(t) * stoll(t2)));
                        i++;
                    }
                    else if (o == "+")
                    {
                        stk.push(to_string(stoll(t) + stoll(t2)));
                        i++;
                    }
                    else if (o == "-")
                    {
                        stk.push(to_string(stoll(t) - stoll(t2)));
                        i++;
                    }
                }
                else stk.push(t_e[i]);
            }
            t = stk.top();
            t_e.clear();
            while (!stk.empty())
            {
                t_e.emplace_back(stk.top());
                stk.pop();
            }
            reverse(t_e.begin(), t_e.end());
            
        }
        
        result.emplace_back(abs(stoll(t)));
        while (!stk.empty()) stk.pop();

    } while (next_permutation(op.begin(), op.end()));

    answer = *max_element(result.begin(), result.end());

    return answer;
}