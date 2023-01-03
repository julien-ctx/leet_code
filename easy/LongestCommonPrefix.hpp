#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int size = strs.size();
        string pref;
        if (size)
        {
            for (int i = 0; strs[0][i]; i++)
            {
                for (int j = 1; j < size; j++)
                    if (strs[j][i] != strs[0][i])
                        return pref;
                pref += strs[0][i];
            }
        }
        return pref;
    }
},
