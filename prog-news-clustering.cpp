#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

void parser_alpha_lower(string& str)
{
    for (char& ch : str)
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
}

vector<string> get_parser_vec(string &str)
{
    vector<string> v;
    string t_str{ "" };
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (isalpha(str[i]) == 1024 && isalpha(str[i+1]) == 1024) // isalpha는 컴파일러마다 반환값 달라 대문자1 소문자2 반환, 대소문자 구분 없이 1024반환
        {
            t_str += str[i]; t_str += str[i+1];
            v.emplace_back(t_str);
            t_str.clear();
        }
    }
    return v;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    parser_alpha_lower(str1);
    parser_alpha_lower(str2);
    v1 = get_parser_vec(str1);
    v2 = get_parser_vec(str2);

    int sum_size = 0;
    int prod_size = 0;
    vector<int> visited(v2.size(), 0);
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (visited[j] == 1) continue;
            if (v1[i] == v2[j])
            {
                visited[j] = 1;
                prod_size++;
                break;
            }
        }
    }
    sum_size = v1.size() + v2.size() - prod_size;

    if (prod_size == 0 && sum_size == 0) return 65536;
    answer = (int)(65536 * ((double)prod_size / (double)sum_size));


    return answer;
}