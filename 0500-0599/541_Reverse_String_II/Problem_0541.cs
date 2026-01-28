using System;

namespace Problem_0541
{
    public class Solution
    {
        public string ReverseStr(string s, int k)
        {
            // Convert to char array because C# strings are immutable
            char[] chars = s.ToCharArray();
            int n = chars.Length;

            // Iterate with step 2*k
            for (int i = 0; i < n; i += 2 * k)
            {
                // Determine the end of the section to reverse
                // Math.Min handles the edge case where fewer than k characters remain
                int start = i;
                int end = Math.Min(i + k, n) - 1; // -1 because indices are 0-based

                // Swap characters logic
                while (start < end)
                {
                    char temp = chars[start];
                    chars[start] = chars[end];
                    chars[end] = temp;
                    start++;
                    end--;
                }
            }

            return new string(chars);
        }
    }

    // class Program
    // {
    //     static void Main(string[] args)
    //     {
    //         Console.Write("Enter string: ");
    //         string s = Console.ReadLine();
            
    //         Console.Write("Enter k: ");
    //         if (int.TryParse(Console.ReadLine(), out int k))
    //         {
    //             Solution sol = new Solution();
    //             Console.WriteLine($"Result: {sol.ReverseStr(s, k)}");
    //         }
    //     }
    // }
}