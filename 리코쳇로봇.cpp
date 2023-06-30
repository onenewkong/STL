// 프로그래머스 Lv.2 리코쳇로봇

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    pair<int, int> Rpos;

    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'R') {
                Rpos = make_pair(i, j);
                break;
            }
        }
    }

    queue<int> count;
    queue<pair<int, int>> list;

    int map[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    list.push(Rpos);
    count.push(0);

    while (!list.empty()) {
        int x = list.front().first;
        int y = list.front().second;
        int n = count.front();

        for (int i = 0; i < 4; i++) {
            while (x + map[i][0] >= 0 && y + map[i][1] >= 0 && x + map[i][0] < row && y + map[i][1] < col && board[x + map[i][0]][y + map[i][1]] != 'D') {
                x += map[i][0];
                y += map[i][1];
            }

            if (x != list.front().first || y != list.front().second) {
                if (board[x][y] == 'G') {
                    answer = n + 1;
                    return answer;
                }

                if (board[x][y] != 'C') {
                    list.push(make_pair(x, y));
                    count.push(n + 1);
                    board[x][y] = 'C';
                }

                x = list.front().first;
                y = list.front().second;
            }
        }

        list.pop();
        count.pop();
    }

    return answer;
}