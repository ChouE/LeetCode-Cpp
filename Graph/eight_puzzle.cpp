#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

const int SIZE = 3;
const array<pair<int, int>, 4> DIRECTIONS = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

struct Matrix {
    array<array<int, SIZE>, SIZE> a;

    bool operator<(const Matrix& other) const {
        return a < other.a;
    }
};

int heuristic(const Matrix& matrix) {
    Matrix goal{{1, 2, 3, 8, 0, 4, 7, 6, 5}};
    int mismatch = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix.a[i][j] && matrix.a[i][j] != goal.a[i][j]) {
                mismatch++;
            }
        }
    }
    return mismatch;
}

struct Node {
    Matrix matrix;
    int cost;

    bool operator>(const Node& other) const {
        return cost + heuristic(matrix) > other.cost + heuristic(other.matrix);
    }
};



bool isGoal(const Matrix& matrix) {
    Matrix goal{{1, 2, 3, 8, 0, 4, 7, 6, 5}};
    return matrix.a == goal.a;
}

priority_queue<Node, vector<Node>, greater<Node>> pq;
set<Matrix> visited;

void addToQueueIfUnvisited(const Matrix& matrix, int cost) {
    if (!visited.count(matrix)) {
        visited.insert(matrix);
        pq.push({matrix, cost});
    }
}

int solve(const Matrix& start) {
    pq.push({start, 0});
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (isGoal(current.matrix)) {
            return current.cost;
        }

        pair<int, int> zero_pos;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (current.matrix.a[i][j] == 0) {
                    zero_pos = {i, j};
                }
            }
        }

        for (const auto& dir : DIRECTIONS) {
            pair<int, int> next_pos = {zero_pos.first + dir.first, zero_pos.second + dir.second};
            if (next_pos.first >= 0 && next_pos.first < SIZE &&
                next_pos.second >= 0 && next_pos.second < SIZE) {
                Matrix next_matrix = current.matrix;
                swap(next_matrix.a[zero_pos.first][zero_pos.second], next_matrix.a[next_pos.first][next_pos.second]);
                addToQueueIfUnvisited(next_matrix, current.cost + 1);
            }
        }
    }
    return -1;
}

int main() {
    Matrix start;
    char ch;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //cin >> start.a[i][j];
            scanf(" %c", &ch);
            start.a[i][j] = ch - '0';
        }
    }

    int result = solve(start);
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}