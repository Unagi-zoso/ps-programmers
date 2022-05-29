#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> temp_map;
    unordered_map<int, int> pass_cnt_table{};
    
    for (int i=1; i <= N + 1; i++)
    {
        pass_cnt_table.insert({i,0});
    }
    
    for (auto user : stages)
    {
        for (int i=1; i <= user; i++)
        {
            pass_cnt_table[i]++;
        }
    }

    for (int i=1; i < pass_cnt_table.size(); i++)
    {
        if (pass_cnt_table[i] != 0) 
        {
            int curr_fail = pass_cnt_table[i]-pass_cnt_table[i+1];
            temp_map.push_back({(double)curr_fail / pass_cnt_table[i], i});
        }
        else {temp_map.push_back({0, i});}
    }
    
    sort(temp_map.begin(),temp_map.end(), compare);

    for (auto sorted : temp_map)
    {
        answer.emplace_back(sorted.second);
    }   
    
    return answer;
}