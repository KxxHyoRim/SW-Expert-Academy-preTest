#include <iostream>

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
        long long sizeToFillMax = 0;

        for (long long i = 0; i < N.length(); i++) {
            int target = N[i] - '0';

            if (target < x){
                isFillWithMax = true;
                sizeToFillMax = N.length() - (i + 1);
                break;
            } else if (target == x )
                result.append(X);
            else if (target < y){
                result.append(X);
                isFillWithMax = true;
                sizeToFillMax = N.length() - (i + 1);
                break;
            }
            else if (target == y)
                result.append(Y);
            else if (target > y) {
                result.append(Y);
                isFillWithMax = true;
                sizeToFillMax = N.length() - (i + 1);
                break;
            }
        }

        if (isFillWithMax){
            for (long long i = 0; i < sizeToFillMax; i++){
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