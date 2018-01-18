#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M, j, uncovered = 0, set_to_add;
    double best, total_cost = 0;
    string line;
    scanf("%d %d", &N, &M);
    
    vector<double>        weights(M);
    vector< vector<int> > sets(M, vector<int>(M, 0));
    set<int>              solution;
    set<int>              covered;
    
    for (int i = 0; i < M; ++i) {
        j = 0;
        scanf("%lf", &weights[i]);
        getline(cin, line);
        istringstream iss(line);
        while (iss >> sets[i][j++]);
    }

    while (covered.size() < N) {
        best = 999999;
        for (int i = 0; i < M; ++i) {
            if (solution.find(i) != solution.end()) continue;
            uncovered = 0;
            for (j = 0; j < M && sets[i][j] != 0; ++j) {
                if (covered.find(sets[i][j]) == covered.end()) ++uncovered;
            }
            if (uncovered == 0) continue;
            if (weights[i] / uncovered < best) {
                best = weights[i] / uncovered;
                set_to_add = i;
            }
        }
        solution.insert(set_to_add);
        total_cost += weights[set_to_add];
        for (j = 0; j < M && sets[set_to_add][j] != 0; ++j) {
            covered.insert(sets[set_to_add][j]);
        }
    }
    
    for (int i = 0; i < M; ++i) {
        printf("%d: ", i+1);
        if (solution.find(i) != solution.end()) printf("1\n");
        else printf("0\n");
    }
    
    printf("\nTotal cost: %lf\n", total_cost);
    
    return 0;
}
