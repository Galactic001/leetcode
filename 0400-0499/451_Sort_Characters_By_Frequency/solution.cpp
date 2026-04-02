#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        // 1. Count frequencies using an ASCII array
        vector<int> count(128, 0);
        for (char c : s)
        {
            count[c]++;
        }

        // 2. Store {frequency, character} pairs
        vector<pair<int, char>> freqList;
        for (int i = 0; i < 128; i++)
        {
            if (count[i] > 0)
            {
                freqList.push_back({count[i], (char)i});
            }
        }

        // 3. Sort in descending order (greater<>() sorts by the first element of the pair)
        sort(freqList.begin(), freqList.end(), greater<pair<int, char>>());

        // 4. Build the final string
        string result = "";
        for (auto p : freqList)
        {
            result.append(p.first, p.second);
        }

        return result;
    }
};

int main()
{
    string x;
    cin >> x;

    Solution solution;
    string val = solution.frequencySort(x);
    cout << endl
         << val;
    return 0;
}