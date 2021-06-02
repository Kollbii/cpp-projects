// https://csacademy.com/contest/archive/task/matrix_exploration/submissions/
/*
Test input:
6 6 2
.....#
.###.#
...#.#
.#####
.....#
######
3 5
5 3
*/

#include <iostream>
#include <queue>

using namespace std;

struct specialCell{
    int x;
    int y;
    int val;
};

int main(void){
    int N, M, K, sum = 0;
    string line;

    cin >> N >> M >> K;

    int **maze = (int **)malloc(sizeof(int*)*N);
    for (int i = 0; i < M; i ++){
        maze[i] = (int *)malloc(sizeof(int)*M);
    }

    for (int i = 0; i < N; i++){
        cin >> line;
        for (int j = 0; j < M; j++){
            if (line[j] == '#') maze[i][j] = -1;
            else maze[i][j] = 0;
        }
    }

    queue <specialCell> Q;

    for (int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        maze[x - 1][y - 1] = -1;
        Q.push({x-1, y-1, 1});
    }

    while (!Q.empty()){
        int moves[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < 4; i++){
            int x, y, val;

            x = Q.front().x + moves[i][0];
            y = Q.front().y + moves[i][1];
            val = Q.front().val;

            if (x >= 0 && x < N && y >= 0 && y < M){
                if (maze[x][y] == 0){
                    maze[x][y] = val;
                    sum += val;
                    Q.push({x,y,val + 1});
                }
            }
        }
        // cout << Q.size() << endl;
        Q.pop();
    }
    cout << sum;

}