#include "funWithComplexity.h"

//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int count = 0;
    int count_final = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i < k) {
            if (v[i] >= t) {
                count++;
            }
            if (k == i + 1) {
                if (count >= k / 2.0) {
                    count_final++;
                }
            }
        } else {
            if (v[i - k] >= t) {  // eu vou andar uma unidade para a direita então tenho de remover o primeirp
                count--;
            }
            if (v[i] >= t) {
                count++;
            }
            if (count >= k / 2.0) {
                count_final++;
            }
        }
    }
    return count_final;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}