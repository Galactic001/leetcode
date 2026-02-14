#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        // 1. Initialize min_freq with counts of the first word
        vector<int> min_freq(26, 0);

        // Count frequencies of the first word
        for (char c : words[0])
        {
            min_freq[c - 'a']++;
        }

        // 2. Iterate through the rest of the words
        for (int i = 1; i < words.size(); i++)
        {
            vector<int> char_count(26, 0);

            // Count frequencies for the current word
            for (char c : words[i])
            {
                char_count[c - 'a']++;
            }

            // 3. Update min_freq to keep the intersection (minimum count)
            for (int j = 0; j < 26; j++)
            {
                min_freq[j] = min(min_freq[j], char_count[j]);
            }
        }

        // 4. Construct the result vector
        vector<string> result;
        for (int i = 0; i < 26; i++)
        {
            // Append the character min_freq[i] times
            while (min_freq[i] > 0)
            {
                // Convert index i back to char ('a' + i) then to string
                result.push_back(string(1, i + 'a'));
                min_freq[i]--;
            }
        }

        return result;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n)
    {
        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        vector<string> result = sol.commonChars(words);

        cout << "Result: ";

        for (const string &s : result)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}