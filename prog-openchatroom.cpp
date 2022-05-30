#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void parse_string(string &s, string &s1, string &s2, string &s3)
{
        string temp_s;
        s1 = s.substr(0, s.find(" "));
        temp_s = s.substr(s.find(" ")+1, s.size()-1);
        s2 = temp_s.substr(0, temp_s.find(" "));
        s3 = temp_s.substr(temp_s.find(" ")+1, temp_s.size()-1); 
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string com_str, id_str, nname_str;
    unordered_map<string, string> user_nname_tb;
    
    for (auto s : record)
    {        
        parse_string(s, com_str, id_str, nname_str);
        
        if (com_str == "Enter")
        {
            user_nname_tb[id_str] = nname_str;   
        }
        else if (com_str == "Change")
        {
            user_nname_tb[id_str] = nname_str;    
        }
    }
    
    for (auto s : record)
    {        
        string temp_str = "";
        parse_string(s, com_str, id_str, nname_str);
        if (com_str == "Enter")
        {
            temp_str = user_nname_tb[id_str] + "님이 들어왔습니다.";
            answer.emplace_back(temp_str);   
        }
        else if (com_str == "Leave")
        {
            temp_str = user_nname_tb[id_str] + "님이 나갔습니다.";
            answer.emplace_back(temp_str);
        }
    }

    return answer;
}