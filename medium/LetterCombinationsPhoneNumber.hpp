#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> lettersCombinations(map<char, string> &nbs, string val, int size)
    {
        if (!size)
        {
            reverse(val.begin(),val.end());
            _res.push_back(val);
            return _res;
        }
        string curr_str = nbs[_digits[size - 1]];
        int curr_size = nbs[_digits[size - 1]].size();
        for (int i = 0; i < curr_size; i++)
            lettersCombinations(nbs, val + curr_str[i], size - 1);
        return _res;
    }
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return _res;
        _digits = digits;
        std::map<char, std::string> nbs
        {
            {'0', ""},
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        return lettersCombinations(nbs, "", _digits.size());
    }
    string _digits;
    vector<string> _res;
};
