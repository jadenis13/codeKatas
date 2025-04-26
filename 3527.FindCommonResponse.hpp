#include "codeKatas.h"

using namespace std;

// You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.
// Return the most common response across all days after removing duplicate responses within each responses[i].If there is a tie, return the lexicographically smallest response.
// A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
// If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.

class FindCommonResponse {
public:
    string Solution(vector<vector<string>>& responses) {
        vector<vector<string>> uniqued;
        for (auto& response : responses) {
            uniqued.push_back(response);
            sort(uniqued.back().begin(), uniqued.back().end());
            auto it = unique(uniqued.back().begin(), uniqued.back().end());
            uniqued.back().erase(it, uniqued.back().end());
        }
        unordered_map<string, int> freq;
        for (auto& distinct : uniqued) {
            for (auto& response : distinct) {
                if (freq.count(response) > 0) {
                    freq[response]++;
                }
                freq.insert({ response, 1 });
            }
        }
        vector<pair<string, int>> totals;
        for (const auto& pair : freq) {
            totals.push_back(pair);
        }
        sort(totals.begin(), totals.end(), [](const auto& lhs, const auto& rhs) {
            if (lhs.second == rhs.second) {
                return lhs.first < rhs.first;
            }
            return lhs.second > rhs.second;
        });

        return totals[0].first;
    }

    void Test(ostream& out, vector<vector<string>> vvs, string expected) {
        for (auto& vs : vvs) {
            out << "vs = " << vs;
        }
        out << " Expectation: " << expected;
        auto actual = Solution(vvs);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    FindCommonResponse(ostream& out) {
        Test(out, { { "good", "ok", "good", "ok" }, { "ok", "bad", "good", "ok", "ok" }, { "good" }, { "bad" } }, "good");
        Test(out, { { "good", "ok" }, { "ok", "bad" }, { "bad", "notsure" }, { "great", "good" }}, "bad");
    }
};
