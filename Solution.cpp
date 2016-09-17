#include <iostream>
#include <vector>
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

public:
    static string listSquared(long long m, long long n) {
        vector<int> ems = divisors(m);
        vector<int> ens = divisors(n);
        cout << "Factors of m:" << endl;
        for (int i: ems) cout << i << endl;
        cout << "Factors of n:" << endl;
        for (int i: ens) cout << i << endl;
        return "";
    }
};

int main() {
    SumSquaredDivisors s;
    s.listSquared(42,42);
    return 0;
}
