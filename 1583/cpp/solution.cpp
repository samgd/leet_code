#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using std::pair;
using std::unordered_map;
using std::vector;

class Solution {
 private:
  using prefs = unordered_map<int, unordered_map<int, int>>;
  using pair_map = unordered_map<int, int>;

  prefs get_prefs(vector<vector<int>> &preferences) {
    prefs m;

    int n_people = static_cast<int>(preferences.size());

    for (int i = 0; i < n_people; i++) {
      int pref_idx = n_people - 1;
      for (auto other : preferences[i]) {
        m[i][other] = pref_idx--;
      }
    }
    return m;
  }

  pair_map get_pair_map(vector<vector<int>> &pairs) {
    pair_map m;
    for (auto p : pairs) {
      m[p[0]] = p[1];
      m[p[1]] = p[0];
    }
    return m;
  }

 public:
  int unhappyFriends(int n, vector<vector<int>> &preferences,
                     vector<vector<int>> &pairs) {
    auto pref = get_prefs(preferences);
    auto pair_map = get_pair_map(pairs);
    auto n_unhappy = 0;

    for (int p = 0; p < n; p++) {
      for (int other = 0; other < n; other++) {
        if (p == other) continue;

        if (pref.at(p).at(other) > pref.at(p).at(pair_map.at(p)) &&
            pref.at(other).at(p) > pref.at(other).at(pair_map.at(other))) {
          n_unhappy += 1;
          break;
        }
      }
    }

    return n_unhappy;
  }
};
