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
        for (int d: ans) cout << d << endl;
        return ans;
    }
    
    static string toString(long long n, long long sum) {
        string ans = "{";
        ans += to_string(n);
        ans += ", ";
        ans += to_string(sum);
        ans += "}";
        return ans;
    }
    
public:
    static string listSquared(long long m, long long n) {
        string ans = "{";
        for (long long i = m; i <= n; i++) {
            vector<int> v = divisors(i);
            long long sum = 0;
            for (int i: v) sum += i*i;
            double s = sqrt(sum);
            if ((double) sum / s == s) {
                cout << "eee" << endl;
                ans += toString(i, sum);
                ans += ", ";
            }
        }
        return ans.substr(0, ans.length() - 2) + "}";
    }
};

int main() {
    SumSquaredDivisors s;
    cout << s.listSquared(41,43) << endl;
    return 0;
}
