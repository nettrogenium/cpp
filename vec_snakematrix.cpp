#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mtx(n, std::vector<int>(m, 0));
    int dx = 0, dy = 1;
    int x = 0, y = 0;
    mtx[0][0] = 1;
    int count = 2;
    while (count <= n * m) {
        if (0 <= x + dx && x + dx <= n - 1 && 0 <= y + dy && y + dy <= m - 1 && mtx[x + dx][y + dy] == 0) {
            mtx[x + dx][y + dy] = count;
            count += 1;
            x += dx;
            y += dy;
        } else {
            if (dy == 1) {
                dy = 0;
                dx = 1;
            } else if (dx == 1) {
                dx = 0;
                dy = -1;
            } else if (dy == -1) {
                dy = 0;
                dx = -1;
            } else if (dx == -1) {
                dy = 1;
                dx = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << mtx[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}
