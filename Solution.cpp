#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SumSquaredDivisors
{
private:
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

    static bool sumIsSquare(long long n) {
        vector<int> v = divisors(n);
        long long sum = 0;
        for (int i: v) sum += i;
        long long s = sqrt(sum);
        if (sum / s == s) return true;
        else return false;
    }
public:
    static string listSquared(long long m, long long n) {
        for int i = m; i <= n; i++) {
            if (sumIsSquare(i));
        }
    }
};

int main() {
    SumSquaredDivisors s;
    s.listSquared(42,42);
    return 0;
}
