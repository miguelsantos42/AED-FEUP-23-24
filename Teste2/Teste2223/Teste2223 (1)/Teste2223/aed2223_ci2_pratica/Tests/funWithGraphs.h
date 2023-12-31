// AED 2022/2023 - CI2 - Teste Pratico
// Pedro Ribeiro (DCC/FCUP) [last update: 04/01/2023]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

#include <string>
#include "graph.h"

using namespace std;

class FunWithGraphs {

public:
    // ----- Some example graphs -----
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
    static Graph graph5();
    static Graph graph6();
    static Graph graph7();

    // ----- Functions to implement in this test -----
    static int countLakes(int rows, int cols, const string m[]);
    static int reduceLakes(int rows, int cols, const string m[], int k);
};

#endif
