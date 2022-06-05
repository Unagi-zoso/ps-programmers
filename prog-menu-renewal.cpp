#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> food_map[11]; // 다중 해시
vector<int> max_food_cnt (11, 0); 

void dfs(string& order_menu, int pos, string temp_str)
{
    if (pos >= order_menu.size())
    {
        int len = temp_str.size();
        if (len >= 2) 
        {
            sort(temp_str.begin(), temp_str.end());
            food_map[len][temp_str]++;
            max_food_cnt[len] = max(max_food_cnt[len],food_map[len][temp_str]); // max in algorithm lib
        }
        return;
    }
    dfs(order_menu, pos+1, temp_str + order_menu[pos]);
    dfs(order_menu, pos+1, temp_str);
}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    
    for (auto str : orders)
    {
        dfs(str, 0, "");
    }
    for (auto len : course)
    {
        for (auto item : food_map[len])
        {
            if (item.second >= 2 && item.second == max_food_cnt[len])
                answer.emplace_back(item.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}