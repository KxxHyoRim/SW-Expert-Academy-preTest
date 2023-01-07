#include <iostream>
#include <queue>

using namespace std;

int T, R, C;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int result = 0;
char map[21][21];
bool visited[21][21];
bool alphabet['Z' - 'A' + 1];

void resetVisited();

void resetAlphabet();

void resetResult();

void dfs(int x, int y, int num);

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
        dfs(0, 0, 1);
        cout << "#" << t + 1 << " " << result << "\n";

        resetVisited();
        resetAlphabet();
        resetResult();
    }

    return 0;
}

void dfs(int x, int y, int num) {
    if (num > result) {
        result = num;
    }
    visited[y][x] = true;
    char curr = map[y][x];
    alphabet[curr - 'A'] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        curr = map[ny][nx];

        if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
            if (!visited[ny][nx] && !alphabet[map[ny][nx] - 'A']) {
                dfs(nx, ny, num + 1);
                alphabet[curr - 'A'] = false;
                visited[ny][nx] = false;
            }
        }
    }
}


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

void resetResult() {
    result = 0;
}
