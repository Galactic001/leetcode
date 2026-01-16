using System;

namespace Problem_0509
{
    public class Solution
    {
        public int Fib(int n)
        {
            // Base cases: F(0) = 0, F(1) = 1
            if (n <= 1) return n;

            // Iterative approach (more efficient than recursion)
            int t1 = 0; // Represents F(i-2)
            int t2 = 1; // Represents F(i-1)
            int nextTerm = 0;

            for (int i = 2; i <= n; i++)
            {
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
            }

            return nextTerm;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number (n): ");
            
            // specific input parsing
            string input = Console.ReadLine();
            if (int.TryParse(input, out int n))
            {
                Solution solution = new Solution();
                int answer = solution.Fib(n);
                
                Console.WriteLine($"Fibonacci({n}) = {answer}");
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter an integer.");
            }

            // Keep console open if running directly
            // Console.ReadKey(); 
        }
    }
}