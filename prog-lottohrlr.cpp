#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int counter_zero = 0;
    int counter_match = 0;
    unordered_map<int, int> win_hash_table;
    array<int,7> rank_table{6,6,5,4,3,2,1};
    
    for (int i = 1; i <= 45; i++)
    {
        win_hash_table.insert({ i,0 });
    }
    for (auto num : win_nums)
    {
        win_hash_table.find(num)->second++;
    }
    for (auto num : lottos)
    {
        if (num == 0) counter_zero++;
        else if (win_hash_table.find(num)->second != 0) counter_match++;
    }


    answer.emplace_back(rank_table[counter_match + counter_zero]);
    answer.emplace_back(rank_table[counter_match]);
    return answer;
}