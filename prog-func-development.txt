#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> p = move(progresses);
    vector<int> s = move(speeds);
    vector<multiset<int>>  v_s;
    multiset<int> t_s;
    int x  = 0;
    
    while(x < p.size())
    {
        for (int i = x; i < p.size(); i++)
        {
            p[i] += s[i];
        }
        for (int i = x; i < p.size(); i++)
        {
            
            if (p[x] >= 100) 
            {
                t_s.insert(x);
                x++;
            }
            else
            {
                if (!t_s.empty())
                {
                    v_s.emplace_back(t_s);
                    t_s.clear();
                }
            }
        }
        if (!t_s.empty())
        {
            v_s.emplace_back(t_s);
            x++;
        }
    }
    for (auto i : v_s)
    {
        answer.emplace_back(i.size());        
    }
    
    return answer;
}