#include <iostream>
#include <queue>

using namespace std;

int T, R, C;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char map[21][21];
bool visited[21][21];
bool alphabet['Z' - 'A' + 1];

void resetVisited() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            visited[j][i] = false;
        }
    }
}

void resetAlphabet() {
    int idx = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        alphabet[idx++] = false;
    }
}

int bfs(int x, int y) {
    int count = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        char curr = map[y][x];
        alphabet[curr - 'A'] = true;
        cout << "(" << x << ", " << y << ")" << map[y][x] << endl;
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
                if (!visited[ny][nx] && !alphabet[map[ny][nx] - 'A']) {
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                    curr = map[ny][nx];
                    alphabet[curr - 'A'] = true;
                }
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> R >> C;

        for (int y = 0; y < R; y++) {
            string oneLine;
            cin >> oneLine;
            for (int x = 0; x < C; x++) {
                map[y][x] = oneLine[x];
            }
        }

        cout << "#" << t + 1 << " " << bfs(0, 0) << "\n";

        resetVisited();
        resetAlphabet();
    }


    return 0;
}
