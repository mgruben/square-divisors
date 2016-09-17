#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SumSquaredDivisors
{
private:
    /* A helper function that returns the divisors
     * of the given integer
     */ 
    static vector<int> divisors(long long n) {
        vector<int> ans;
        for (int i = 1; i*i <= n; i++) {
            if ((n % i) == 0) {
                ans.push_back(i);
                if (i != n/i) ans.push_back(n/i);
            }
        }
        return ans;
    }
    
    /* A helper function to format the (n, sum) tuple as
     * the desired array-like string.
     */
    static string toString(long long n, long long sum) {
        string ans = "{";
        ans += to_string(n);
        ans += ", ";
        ans += to_string(sum);
        ans += "}";
        return ans;
    }
    
public:
    /* given a range of m to n, inclusive, returns as an
     * array-like string all of the (n, sum) tuples where
     * the sum of the squared divisors of n is itself a
     * square (e.g. 42,42 ->  {{42, 2500}})
     */
    static string listSquared(long long m, long long n) {
        string ans = "{";
        for (long long i = m; i <= n; i++) {
            vector<int> v = divisors(i);
            long long sum = 0;
            for (int i: v) sum += i*i;
            double s = sqrt(sum);
            if (fmod(sum, s) == 0) {
                ans += toString(i, sum);
                ans += ", ";
            }
        }
        return ans.substr(0, ans.length() - 2) + "}";
    }
};

int main() {
    SumSquaredDivisors s;
    cout << s.listSquared(42,42) << endl;
    return 0;
}
