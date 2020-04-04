#include <bits/stdc++.h>

using namespace std;

int sqr[60][60], n, k, t;
bool rowsafe[60][60], colsafe[60][60], solve;

void solver_fun(int row, int col, int m) {
    if (row == n && col == n + 1 && m == k && !solve) {
        solve = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << sqr[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (row > n) {
        return;
    } else if (col > n) {
        solver_fun(row + 1, 1, m);
    }
    for (int i = 1; i <= n && !solve; ++i) {
        if (!rowsafe[row][i] && !colsafe[col][i]) {
            rowsafe[row][i] = colsafe[col][i] = true;
            if (row == col) {
                m += i;
            }
            sqr[row][col] = i;

            solver_fun(row, col + 1, m);

            rowsafe[row][i] = colsafe[col][i] = false;
            if (row == col) {
                m -= i;
            }
            sqr[row][col] = 0;
        }
    }
}

int main() {
    int T1;
    scanf(" %d", &T1);
    for (t = 1; t <= T1; ++t) {
        scanf(" %d %d", &n, &k);
        solver_fun(1, 1, 0);
        if (!solve) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        solve = false;
    }
    return 0;
}
