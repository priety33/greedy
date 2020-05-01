/*
optimal solution : that uses each Fibonacci number at most once and never uses two consecutive Fibonacci numbers.

1. It cannot use two consecutive numbers because such a solution would not be optimal 
(instead of F_n and F_{n+1} take just F_{n+2}) => f(n)+f(n+1) = f(n+2) , saving one number.

2. It cannot use any bigger Fibonacci number twice
instead of F_n + F_n you can have F_{n+1} + F_{n-2} which gives you a lexicographically bigger solution with the same number of coins.
If we have two same number,
we can always transfor to two different number.

3. Hence, we must take the biggest available

fibo[0] + fibo[2] + fibo[4] + ... + fibo[2n] = fibo[2n + 1] - 1
fibo[1] + fibo[3] + fibo[5] + .... + fibo[2n-1] = fibo[2n] - 1 => So if k >= fibo[2n], and we don't take fibo[2n]
                                                  the rest sum of every two Fibo numbers can only reach a maximum fibo[2n] - 1

Each number has exactly one representation that uses each Fibonacci number at most once
and never uses two consecutive Fibonacci numbers. The greedy algorithm constructs this representation and therefore its output is always optimal.
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int f1=0, f2=1;
        while(f2<=k)
        {
            swap(f1,f2);
            f2+=f1;
        }
         return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));
    }
};
