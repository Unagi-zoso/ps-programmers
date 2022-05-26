#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> report_log;
    map<string, int> id_idx;
    vector<int> answer;
    
    for (auto just_count : id_list)
    {
        answer.emplace_back(0);
    }
    
    //id set idx
    for (int i = 0; i < id_list.size(); i++)
    {
        id_idx[id_list[i]] = i;
    }
    
    //report parsing
    for (int i = 0; i < report.size(); i++)
    {
        int blank = report[i].find(" ");
        report_log[report[i].substr(blank, report[i].size() - 1)].insert(
                   report[i].substr(0, blank));
    }
    
    for (auto reportees : report_log)
    {
        auto reporters = reportees.second;
        if (reporters.size() >= k)
        {
            for (auto r : reporters)
                answer[id_idx[r]]++;
        }
    }

    return answer;
}