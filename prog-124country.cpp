#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(int n) {
    string answer = "";
    n--;
    while (1)
    {
        if (n < 3) {answer += to_string(n); break;}
        if (n >= 3)
        {   
            answer += to_string(n%3);
            n = n/3;
            n--;
        }        
    }
    reverse(answer.begin(), answer.end());
    answer = regex_replace(answer, regex("2"), "4");
    answer = regex_replace(answer, regex("1"), "2");
    answer = regex_replace(answer, regex("0"), "1");



    return answer;
}