#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> bit_sum_vec;
    
    for (string& s : answer)
    {
        for (auto cnt = 0; cnt < n; cnt++)
        {
            s += " ";
        }
    }

    for (int i = 0; i < arr1.size(); i++)
    {
        bit_sum_vec.emplace_back(arr1[i] | arr2[i]);
    }
    
    int v_idx = 0;
    for (auto b_sum : bit_sum_vec)
    {
        
        int s_idx = 0;
        while (b_sum > 0)
        {
            if (b_sum % 2 == 1)
            {
                // (answer[v_idx])[n-1-s_idx] = {'#'}; success 
                answer[v_idx].replace(n-1-s_idx, 1, "#");  // success using replace()
                // .replace(answer[v_idx].rbegin(), answer[v_idx].rend(), "#"); fail
            }
            b_sum /= 2;
            s_idx++;
        }
        v_idx++;
    }
    return answer;
}