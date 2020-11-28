#include <vector>
#include <iostream>

#include "solution.cpp"

int main()
{
    using test_case = std::pair<std::vector<int>, int>;

    std::vector<test_case> tests = {
        {{}, 0},
        {{0}, 0},
        {{1}, 0},
        {{0, 1}, 2},
        {{0, 1, 0}, 2},
        {{0, 1, 0, 0, 1}, 4},
        {{0, 0, 0, 0, 0}, 0},
        {{1, 1, 1, 1, 1}, 0},
    };

    Solution s;
    for (auto [v, max_contig] : tests) {
        auto result = s.findMaxLength(v);

        if (max_contig != result) {
            std::cout << "Test failed: "
                      << "\n\tExpected: " << max_contig
                      << "\n\tReturned: " << result
                      << "\n\tvector: <";

            if (v.size() > 0) {
                std::cout << v[0];
                for (auto vi = v.begin() + 1; vi != v.end(); vi++) {
                    std::cout << ", " << *vi;
                }
            }

            std::cout << ">" << std::endl;

            return 1;
        }
    }

    std::cout << "Tests passed!" << std::endl;
}
