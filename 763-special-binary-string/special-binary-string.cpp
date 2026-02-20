class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";

        vector<string> substrings;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                substrings.push_back("1" + makeLargestSpecial(inside) + "0");
                start = i + 1;
            }
        }

        sort(substrings.begin(), substrings.end(), greater<string>());

        string res = "";
        for (const string& sub : substrings) {
            res += sub;
        }
        
        return res;
    }
};