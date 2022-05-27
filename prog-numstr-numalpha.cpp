 

#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, char> digi_alpha_table
                    { {"zero", '0'}, {"one", '1'}, {"two", '2'},
                    {"three", '3'}, {"four", '4'}, {"five", '5'},
                    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'} };
    string ans_str{};
    string alpha_str{};
    for (auto ch : s)
    {
        if (isalpha(ch)) alpha_str += ch;
        else ans_str.push_back(ch);
        if (digi_alpha_table.find(alpha_str) != digi_alpha_table.end())
        {
            ans_str.push_back(digi_alpha_table[alpha_str]);
            alpha_str.clear();
        }
    }
    return stoi(ans_str);
}