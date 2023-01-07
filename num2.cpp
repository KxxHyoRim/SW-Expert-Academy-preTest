#include <iostream>
#include <string>

using namespace std;

string N, X, Y;
string result[1000000];
int n, x, y;

int getNumFromArray(string array[]) {
    int rtn = 0;
    int mul = 1;
    for (int i = (int) N.length() - 1; i >= 0; i--) {
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
        cin >> N >> X >> Y;

        n = stoi(N);
        x = stoi(X);
        y = stoi(Y);

        if (n < x || n < y) {
            cout << "#" << t << " " << -1 << endl;
            continue;
        }

        for (int i = 0; i < N.length(); i++) { result[i] = X; }

        for (int i = 0; i < N.length(); i++) {
            if (i == 0) {
                if (stoi(result[0]) < x) {
                    result[0] = "0";
                    continue;
                }
            }

            result[i] = Y;
            if (n > getNumFromArray(result)) {
                continue;
            } else if (n == getNumFromArray(result)) {
                break;
            } else {
                result[i] = X;
            }
        }

        int rtn = getNumFromArray(result);
        if (rtn == 0)
            cout << "#" << t << " -1\n";
        else
            cout << "#" << t << " " << rtn << "\n";
    }

    return 0;
}