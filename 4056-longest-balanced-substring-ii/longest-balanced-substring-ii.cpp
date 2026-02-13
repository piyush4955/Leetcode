#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        int currentBlock = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) currentBlock++;
            else currentBlock = 1;
            maxLen = max(maxLen, currentBlock);
        }

        char pairs[3][2] = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};
        for (int p = 0; p < 3; p++) {
            char c1 = pairs[p][0];
            char c2 = pairs[p][1];
            map<int, int> seen;
            seen[0] = -1;
            int diff = 0;
            int start = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                    seen.clear();
                    seen[0] = i;
                    diff = 0;
                    start = i + 1;
                    continue;
                }
                diff += (s[i] == c1 ? 1 : -1);
                if (seen.count(diff)) {
                    maxLen = max(maxLen, i - seen[diff]);
                } else {
                    seen[diff] = i;
                }
            }
        }

        map<pair<int, int>, int> seen3;
        seen3[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else if (s[i] == 'c') c++;

            pair<int, int> key = {a - b, b - c};
            if (seen3.count(key)) {
                maxLen = max(maxLen, i - seen3[key]);
            } else {
                seen3[key] = i;
            }
        }

        return maxLen;
    }
};