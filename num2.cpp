#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, x, y;
        cin >> N >> x >> y;
        cout << "#" << t << " ";

        if (N < x || N < y) {
            cout << -1 << endl;
            continue;
        }

        int result;

        for (int i = 0; i <= N; i++) {
            int n = i;
            while (n > 0) {
                int d = n % 10;
                if (d != x && d != y) {
                    goto next;
                }
                n /= 10;
            }
            result = i;
            next:;
        }
        cout << result << endl;
    }


    return 0;
}
