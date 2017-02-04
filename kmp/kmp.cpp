#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prefix(string needle) {
        int N = needle.size();
        vector<int> ret(N, 0);
        for (int j=0, i=1; i<N; i++) {
            while (j > 0 && needle[i] != needle[j]) j = ret[j-1];
            if (needle[i] == needle[j]) j++;
            ret[i] = j;
        }
        return ret;
    }

    int kmp(string needle, string haystack) {
        int N1 = needle.size(), N2 = haystack.size();
        vector<int> p = prefix(needle);

        for (int j=0, i=0; i<N2; i++) {
            while (j > 0 && needle[j] != haystack[i]) j = p[j-1];
            if (needle[j] == haystack[i]) j++;
            cout << j << " ";
            if (j == N1) return i - N1 + 1;
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    Solution sol;
    string needle, haystack;
    while (cin >> needle >> haystack) {
        cout << needle << endl;
        cout << haystack << endl;
        cout << "prefix = ";
        vector<int> prefix = sol.prefix(needle);
        for (int i=0; i<prefix.size(); i++) cout << prefix[i] << " ";
        cout << endl;

        int idx = sol.kmp(needle, haystack);
        cout << endl << idx << endl << endl;
    }

    return 0;
}
