#include "codeKatas.h"

using namespace std;

// You are given two arrays, instructions and values, both of size n.
// You need to simulate a process based on the following rules :
//  You start at the first instruction at index i = 0 with an initial score of 0.
//  If instructions[i] is "add" :
//	Add values[i] to your score.
//	Move to the next instruction(i + 1).
//	If instructions[i] is "jump" :
//	Move to the instruction at index(i + values[i]) without modifying your score.
// The process ends when you either :
// Go out of bounds(i.e., i < 0 or i >= n), or
//	Attempt to revisit an instruction that has been previously executed.The revisited instruction is not executed.
//	Return your score at the end of the process.

class CalculateScore {
public:
    long long Solution(vector<string>& instructions, vector<int>& values) {
        const string JMP = "jump";
        const string ADD = "add";

        vector<bool> wasVisited(instructions.size(), false);
        long long score = 0;

        bool inBounds = true;
        int cursor = 0; // signed to account for negative jumps to out of bounds
        while (inBounds) {
            if (wasVisited[cursor]) {
                return score;
            }

            if (instructions[cursor] == JMP) {
                cursor += values[cursor];
            }
            else if (instructions[cursor] == ADD) {
                score += values[cursor];
                cursor++;
            }
            if (cursor < 0 || cursor >= instructions.size()) {
                inBounds = false;
            }

            wasVisited[cursor] = true;
        }

        return score;
    }

    void Test(ostream& out, vector<string> vs, vector<int> vi, long long expected) {
        out << "vs = " << vs << " vi = " << vi << " Expectation: " << expected;
        auto actual = Solution(vs, vi);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    CalculateScore(ostream& out) {
        Test(out, { "jump","add","add","jump","add","jump"}, {2,1,3,1,-2,-3}, 1);
        Test(out, { "jump", "add", "add"}, {3,1,1}, 0);
        Test(out, { "jump" }, { 0 }, 0);
    }
};
