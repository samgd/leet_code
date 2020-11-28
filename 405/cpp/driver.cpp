#include <iomanip>
#include <iostream>

#include "solution.cpp"

int main()
{
    Solution s;

    for (int i = -9999; i < 9999; i++) {
        std::stringstream act;
        act << std::hex << i;
        if (act.str() != s.toHex(i)) {
            std::cout << "Test failure: expected, actual" << std::endl;
            std::cout << act.str() << ", " << s.toHex(i) << std::endl;
            return 1;
        }
    }

    std::cout << "Tests pass!" << std::endl;
}
