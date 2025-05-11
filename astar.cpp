#include <bits/stdc++.h>
using namespace std;

int sizeN = 9;

int heuristic(vector<int>& current, vector<int>& goal) {
    int h = 0;
    for (int i = 0; i < sizeN; i++) {
        if (current[i] == -1) continue;
        for (int j = 0; j < sizeN; j++) {
            if (goal[j] == current[i]) {
                h += abs(i / 3 - j / 3) + abs(i % 3 - j % 3);
                break;
            }
        }
    }
    return h;
}

void printPuzzle(vector<int>& puzzle) {
    for (int i = 0; i < sizeN; i++) {
        if (i % 3 == 0) cout << endl;
        if (puzzle[i] == -1) cout << "_ ";
        else cout << puzzle[i] << " ";
    }
    cout << endl;
}

vector<vector<int>> getNextStates(vector<int>& current) {
    int blankIndex;
    for (int i = 0; i < sizeN; i++) {
        if (current[i] == -1) {
            blankIndex = i;
            break;
        }
    }
    int row = blankIndex / 3;
    int col = blankIndex % 3;

    vector<vector<int>> nextStates;

    if (col > 0) {
        vector<int> left = current;
        swap(left[blankIndex], left[blankIndex - 1]);
        nextStates.push_back(left);
    }
    if (col < 2) {
        vector<int> right = current;
        swap(right[blankIndex], right[blankIndex + 1]);
        nextStates.push_back(right);
    }
    if (row > 0) {
        vector<int> up = current;
        swap(up[blankIndex], up[blankIndex - 3]);
        nextStates.push_back(up);
    }
    if (row < 2) {
        vector<int> down = current;
        swap(down[blankIndex], down[blankIndex + 3]);
        nextStates.push_back(down);
    }

    return nextStates;
}

string vectorToString(vector<int>& v) {
    string s = "";
    for (int x : v) s += to_string(x) + ",";
    return s;
}

int countInversions(vector<int> puzzle) {
    int inv = 0;
    for (int i = 0; i < sizeN; i++) {
        for (int j = i + 1; j < sizeN; j++) {
            if (puzzle[i] > 0 && puzzle[j] > 0 && puzzle[i] > puzzle[j]) {
                inv++;
            }
        }
    }
    return inv;
}

bool isSolvable(vector<int>& start, vector<int>& goal) {
    int invStart = countInversions(start);
    int invGoal = countInversions(goal);
    return (invStart % 2) == (invGoal % 2);
}

void astar(vector<int>& start, vector<int>& goal) {
    if (!isSolvable(start, goal)) {
        cout << "This puzzle configuration is unsolvable.\n";
        return;
    }

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    unordered_map<string, int> g;
    unordered_set<string> visited;

    int h = heuristic(start, goal);
    pq.push({h, start});
    g[vectorToString(start)] = 0;

    while (!pq.empty()) {
        vector<int> current = pq.top().second;
        pq.pop();
        string currentKey = vectorToString(current);

        if (visited.count(currentKey)) continue;
        visited.insert(currentKey);

        printPuzzle(current);
        cout << "--------" << endl;

        if (current == goal) {
            cout << "Solved!\n";
            return;
        }

        int currentG = g[currentKey];
        vector<vector<int>> neighbors = getNextStates(current);
        for (auto& neighbor : neighbors) {
            string neighborKey = vectorToString(neighbor);
            if (visited.count(neighborKey)) continue;

            int tentativeG = currentG + 1;

            if (!g.count(neighborKey) || tentativeG < g[neighborKey]) {
                g[neighborKey] = tentativeG;
                int f = tentativeG + heuristic(neighbor, goal);
                pq.push({f, neighbor});
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    vector<int> start(sizeN), goal(sizeN);
    cout << "Enter start state (use -1 for blank):\n";
    for (int i = 0; i < sizeN; i++) cin >> start[i];
    cout << "Enter goal state (use -1 for blank):\n";
    for (int i = 0; i < sizeN; i++) cin >> goal[i];

    astar(start, goal);
    return 0;
}
