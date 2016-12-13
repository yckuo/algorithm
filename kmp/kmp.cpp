#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    int kmp(string str1, string str2) {
        int N1 = str1.size(), N2 = str2.size();
        vector<int> p(N1, 0);
        for (int i=1, j=0; i<N1; i++) {
            while (j > 0 && str1[j] != str1[i]) j = p[j-1];
            if (str1[j] == str1[i]) p[i] = ++j;
        }

        for (int i=0, j=0; i<N2; i++) {
            while (j > 0 && str1[j] != str2[i]) j = p[j-1];
            if (str1[j] == str2[i]) if (++j == N1) return i - N1 + 1;
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    Solution sol;
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << sol.kmp(str1, str2) << ";" << str1 << ";" << str2 << endl;
    }

    return 0;
}
