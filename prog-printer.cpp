#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    deque<int> q;
    for (auto i : p)
        q.push_back(i);
    while (!q.empty())
    {
        for (auto i = q.begin(); i < max_element(q.begin(),q.end()); i++)
        {
            cout << q.front();
            q.push_back(q.front());
            q.pop_front();
            if (location == 0) location = q.size()-1;
            else location--;
        }
        
        answer++;
        if (location == 0) break;
        q.pop_front();
        if (location == 0) location = q.size()-1;
        else location--;
    }
    return answer;
}