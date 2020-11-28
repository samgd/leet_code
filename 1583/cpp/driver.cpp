#include <iostream>
#include <fstream>
#include <vector>

#include "solution.cpp"

using std::ifstream;
using std::vector;


struct TestCase {
    int n;
    vector<vector<int>> preferences;
    vector<vector<int>> pairs;
};

int main()
{
    ifstream inputs {"test_cases.txt"};

    vector<TestCase> test_cases {
        {
            4,
            {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}},
            {{0, 1}, {2, 3}}
        },
        {
            2,
            {{1}, {0}},
            {{1, 0}}
        },
        {
            4,
            {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}},
            {{1, 3}, {0, 2}}
        }
    };

    Solution s;

    for (auto test_case : test_cases) {
        auto result = s.unhappyFriends(
            test_case.n,
            test_case.preferences,
            test_case.pairs
        );
        std::cout << result << std::endl;
    }
}
