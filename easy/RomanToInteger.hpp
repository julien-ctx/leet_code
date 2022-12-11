#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector< pair<char, int> > source;

public:
    void getSource()
    {
        source.push_back(pair<char, int>('I', 1));
        source.push_back(pair<char, int>('V', 5));
        source.push_back(pair<char, int>('X', 10));
        source.push_back(pair<char, int>('L', 50));
        source.push_back(pair<char, int>('C', 100));
        source.push_back(pair<char, int>('D', 500));
        source.push_back(pair<char, int>('M', 1000));
    }

    int romanToInt(string s)
	{
        getSource();
        int res = 0;

        for (int i = 0; s[i]; i++)
        {
            int i1 = -1; int i2 = -1;
            for (vector< pair<char, int> >::iterator it = source.begin(); it != source.end(); it++)
            {
                if (it->first == s[i])
                    i1 = distance(source.begin(), it);
                if (s[i + 1])
                    if (it->first == s[i + 1])
                        i2 = distance(source.begin(), it);
            }
            if (!(i1 % 2) && (s[i] != 'M') && i2 > 0)
            {
                int diff = i2 - i1;
                if (diff == 2 || diff == 1)
                {
                    res += (source[i2].second - source[i1].second);
                    i++;
                    continue;
                }
            }
            res += source[i1].second;
        }
        return res;
    }
};
