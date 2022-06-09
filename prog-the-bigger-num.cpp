#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_nums;
    int sum = 0;
    for (auto n : numbers)
    {
        str_nums.emplace_back(to_string(n));
        sum += n;
    }
    if (sum == 0) return "0";
    
    sort(str_nums.begin(), str_nums.end(), [] (string s1, string s2) -> bool
                                           { return (s1 + s2) > (s2 + s1); });
    for (auto num : str_nums)
        answer += num;
    
    return answer;
}