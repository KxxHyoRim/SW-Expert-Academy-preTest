#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getNumFromArray(vector<string> array, int size) {
    int rtn = 0;
    int mul = 1;
    for (int i = size - 1; i >= 0; i--) {
        rtn += stoi(array[i]) * mul;
        mul *= 10;
    }
    return rtn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {

        string N, X, Y;
        vector<string> output;
        int n, x, size;

        cin >> N >> X >> Y;

        size = N.length();
        n = stoi(N);
        x = stoi(X);

        if (n == x && x == 0 || n < x) {
            cout << "#" << t << " " << -1 << endl;
            continue;
        }

        for (int i = 0; i < N.length(); i++) {
            output.push_back(X);
            //output[i] = X;
        }

        for (int i = 0; i < N.length(); i++) {
            if (i == 0) {
                int firstNum = stoi(output[0]);
                if (firstNum < x) {
                    output[0] = "0";
                    continue;
                }
            }

            output[i] = Y;
            if (n > getNumFromArray(output, size)) {
                continue;
            } else if (n == getNumFromArray(output, size)) {
                break;
            } else {
                output[i] = X;
            }
        }

        int rtn = getNumFromArray(output, size);
        if (rtn == 0)
            cout << "#" << t << " -1\n";
        else
            cout << "#" << t << " " << rtn << "\n";
    }

    return 0;
}