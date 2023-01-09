#include <iostream>

#define ull unsigned long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {

        string N, X, Y, result = "";
        int x, y;

        cin >> N >> X >> Y;

        x = stoi(X);
        y = stoi(Y);

        bool isFillWithMax = false;
        ull sizeToFillMax = 0;

        for (ull i = 0; i < N.length(); i++) {
            int target = N[i] - '0';

            //  x 보다 작을 떄
            if (target < x) {
                isFillWithMax = true;
                int count = 0;
                while (!result.empty() && result.back() - '0' == x) {
                    count++;
                    result.pop_back();
                }
                if (result.back() - '0' == y) {
                    result.pop_back();
                    result.append(X);
                    sizeToFillMax = N.length() - result.length();
                } else if (result.empty()) {
                    sizeToFillMax = N.length() - 1;
                }
                break;
            }

                // x와 동일할 때
            else if (target == x)
                result.append(X);

                // x 보다크고 y보다 작을 때
            else if (target < y) {
                if (!(i == 0 && x == 0)) { result.append(X); }
                isFillWithMax = true;
                sizeToFillMax = N.length() - (i + 1);
                break;
            }

                // y와 동일할 때
            else if (target == y)
                result.append(Y);

                // y보다 클 때
            else if (target > y) {
                result.append(Y);
                isFillWithMax = true;
                sizeToFillMax = N.length() - (i + 1);
                break;
            }
        }

        if (isFillWithMax) {
            for (ull i = 0; i < sizeToFillMax; i++) {
                result.append(Y);
            }
        }

        if (result == "0" || result.empty())
            cout << "#" << t << " -1\n";
        else
            cout << "#" << t << " " << result << "\n";
    }

    return 0;
}

// 230 2 3 -> 223 나와야 하는데 33나왔음
// 422220324 2 4
// 222220324 2 4
// 2022 1 2 -> 1222
// 1022 1 2 -> 222
// 553 4 5 -> 545 but 55