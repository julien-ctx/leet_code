#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> res;
        if (!digits.size())
            return res;
        
        std::map<char, std::string> nbs;
        nbs.insert({'0', ""});
        nbs.insert({'1', ""});
        nbs.insert({'2', "abc"});
        nbs.insert({'3', "def"});
        nbs.insert({'4', "ghi"});
        nbs.insert({'5', "jkl"});
        nbs.insert({'6', "mno"});
        nbs.insert({'7', "pqrs"});
        nbs.insert({'8', "tuv"});
        nbs.insert({'9', "wxyz"});
        
        int digits_size = digits.size();
        for (int i = 0; i < digits_size; i++)
        {
            int len_one = nbs.at(digits[i]).size();
            for (int j = i + 1; j < digits_size; j++)
            {
                int len_two = nbs.at(digits[j]).size();
                for (int k = 0; k < len_one; k++)
                    for (int l = 0; l < len_two; l++)
                        res.push_back(std::string({nbs.at(digits[i])[k], nbs.at(digits[j])[l]}));
            }
            if (digits_size == 1)
                for (int k = 0; k < len_one; k++)
                    res.push_back({nbs.at(digits[i])[k]});
        }
        return res;
    }
};
