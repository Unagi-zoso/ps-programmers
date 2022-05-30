#include <string>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

int solution(string s) { 
    int answer = 0;
    vector<vector<string>> sliced_s_vec(s.size() / 2);  
    string temp_str{};
    stack<string> stk;
    vector<int> sliced_s_lengs;

    
    if (s.size() == 1) return 1;
    // slicing depending on string length, i == string length to slice
    for (int i=1; i <= s.size() / 2; i++)
    {
        for (int j=0; j < s.size(); j++)
        {
            temp_str += s[j];
            if (temp_str.size() == i || j == s.size()-1)
            {
                sliced_s_vec[i-1].push_back(temp_str);
                temp_str = "";
            }
        }
    }


    for (int i=0; i < sliced_s_vec.size(); i++)
    {
        while (!stk.empty()) stk.pop();
        int overlap_cnt = 0;
        int temp_sum = 0;
        
        for (int j=0; j < sliced_s_vec[i].size(); j++)
        {
            if (!stk.empty() && sliced_s_vec[i][j] == stk.top())
            {
                stk.push(sliced_s_vec[i][j]);
                if (overlap_cnt == 1 || overlap_cnt == 9 ||
                    overlap_cnt == 99 || overlap_cnt == 999) { temp_sum += 1; }
                overlap_cnt++;
                
                stk.top();
            }
            else
            {
                stk.push(sliced_s_vec[i][j]);
                overlap_cnt = 1;
                temp_sum += sliced_s_vec[i][j].size();
            }
            

        }
        sliced_s_lengs.push_back(temp_sum);
    }

    answer =  *min_element(sliced_s_lengs.begin(), sliced_s_lengs.end());

    return answer;
}