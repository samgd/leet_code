#include <cmath>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  const vector<char> base16 = {'0', '1', '2', '3', '4', '5', '6', '7',
                               '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

 private:
  string toBase(int num, int base, vector<char> symbol) {
    string str = "";

    auto val = static_cast<unsigned int>(num);

    while (val != 0) {
      auto rem = val % base;
      str = symbol[rem % base] + str;
      val /= base;
    }
    if (str == "") return string(1, symbol[0]);
    return str;
  }

 public:
  string toHex(int num) { return toBase(num, 16, base16); }
};
