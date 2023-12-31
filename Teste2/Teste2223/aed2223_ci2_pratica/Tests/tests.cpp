// AED 2022/2023 - CI2 - Teste Pratico
// Pedro Ribeiro (DCC/FCUP) [last update: 04/01/2023]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithGraphs.h"
#include "graph.h"

#include <algorithm>

using testing::Eq;

// ----------------------------------------------------------
// Exercise 1
// ----------------------------------------------------------
TEST(test_1, disconnected) {
    cout << "Testing 'disconnected'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_TRUE(g1.disconnected(1,4));
    EXPECT_TRUE(g1.disconnected(1,5));
    EXPECT_TRUE(g1.disconnected(1,6));
    EXPECT_TRUE(g1.disconnected(1,9));
    EXPECT_TRUE(g1.disconnected(6, 4));
    EXPECT_TRUE(g1.disconnected(9, 8));
    EXPECT_FALSE(g1.disconnected(1,2));
    EXPECT_FALSE(g1.disconnected(3,1));
    EXPECT_FALSE(g1.disconnected(4,5));
    EXPECT_FALSE(g1.disconnected(6,5));
    EXPECT_FALSE(g1.disconnected(7,5));
    EXPECT_FALSE(g1.disconnected(6,9));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_TRUE(g2.disconnected(1,4));
    EXPECT_TRUE(g2.disconnected(1,5));
    EXPECT_TRUE(g2.disconnected(4,6));
    EXPECT_TRUE(g2.disconnected(5,7));
    EXPECT_TRUE(g2.disconnected(9, 3));
    EXPECT_FALSE(g2.disconnected(1,2));
    EXPECT_FALSE(g2.disconnected(3,1));
    EXPECT_FALSE(g2.disconnected(4,5));
    EXPECT_FALSE(g2.disconnected(9,6));
    EXPECT_FALSE(g2.disconnected(7,8));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_TRUE(g4.disconnected(2,1));
    EXPECT_TRUE(g4.disconnected(4,2));
    EXPECT_TRUE(g4.disconnected(6,5));
    EXPECT_TRUE(g4.disconnected(7, 8));
    EXPECT_FALSE(g4.disconnected(1,2));
    EXPECT_FALSE(g4.disconnected(2,4));
    EXPECT_FALSE(g4.disconnected(5,6));
    EXPECT_FALSE(g4.disconnected(8,7));

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_FALSE(g7.disconnected(1,2));
    EXPECT_FALSE(g7.disconnected(2,1));
    EXPECT_FALSE(g7.disconnected(1,3));
    EXPECT_FALSE(g7.disconnected(3,1));
    EXPECT_FALSE(g7.disconnected(2,3));
    EXPECT_FALSE(g7.disconnected(3,2));
}

// ----------------------------------------------------------
// Exercise 2
// ----------------------------------------------------------
TEST(test_2, largestDegree) {
    cout << "Testing 'largestDegree'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    vector<int> nodes1 = g1.largestDegree();
    sort(nodes1.begin(), nodes1.end());
    vector<int> answer1 = {4,5};
    EXPECT_EQ(nodes1, answer1);

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    vector<int> nodes2 = g2.largestDegree();
    sort(nodes2.begin(), nodes2.end());
    vector<int> answer2 = {1,2,3,6,7,8,9};
    EXPECT_EQ(nodes2, answer2);

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    vector<int> nodes3 = g3.largestDegree();
    sort(nodes3.begin(), nodes3.end());
    vector<int> answer3 = {11};
    EXPECT_EQ(nodes3, answer3);

}

// ----------------------------------------------------------
// Exercise 3
// ----------------------------------------------------------
TEST(test_3, connected) {
    cout << "Testing 'connected'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_TRUE(g1.connected());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_FALSE(g2.connected());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_FALSE(g3.connected());
}

// ----------------------------------------------------------
// Exercise 4
// ----------------------------------------------------------
TEST(test_4, countNodes) {
    cout << "Testing 'countNodes'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(3, g1.countNodes(5, 1));
    EXPECT_EQ(2, g1.countNodes(6, 2));
    EXPECT_EQ(1, g1.countNodes(1, 3));
    EXPECT_EQ(1, g1.countNodes(4, 0));
    EXPECT_EQ(3, g1.countNodes(4, 1));
    EXPECT_EQ(3, g1.countNodes(4, 2));
    EXPECT_EQ(2, g1.countNodes(4, 3));
    EXPECT_EQ(0, g1.countNodes(4, 4));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(2, g3.countNodes(1, 1));
    EXPECT_EQ(2, g3.countNodes(1, 2));
    EXPECT_EQ(2, g3.countNodes(1, 3));
    EXPECT_EQ(1, g3.countNodes(6, 0));
    EXPECT_EQ(3, g3.countNodes(6, 1));
    EXPECT_EQ(1, g3.countNodes(6, 2));
    EXPECT_EQ(0, g3.countNodes(6, 3));

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_EQ(2, g5.countNodes(1, 1));
    EXPECT_EQ(1, g5.countNodes(1, 2));
    EXPECT_EQ(0, g5.countNodes(1, 3));
    EXPECT_EQ(0, g5.countNodes(4, 1));

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    EXPECT_EQ(1, g6.countNodes(4, 0));
    EXPECT_EQ(2, g6.countNodes(4, 1));
    EXPECT_EQ(3, g6.countNodes(4, 2));
    EXPECT_EQ(2, g6.countNodes(4, 3));
    EXPECT_EQ(0, g6.countNodes(4, 4));
    EXPECT_EQ(1, g6.countNodes(7, 1));
    EXPECT_EQ(1, g6.countNodes(7, 2));
    EXPECT_EQ(1, g6.countNodes(7, 3));
    EXPECT_EQ(1, g6.countNodes(7, 4));
    EXPECT_EQ(1, g6.countNodes(7, 5));
    EXPECT_EQ(1, g6.countNodes(7, 6));
    EXPECT_EQ(1, g6.countNodes(7, 7));
}

// ----------------------------------------------------------
// Exercise 5
// ----------------------------------------------------------
TEST(test_5, pathExists) {
    cout << "Testing 'pathExists'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_TRUE(g1.pathExists(1, 5, {2}));
    EXPECT_FALSE(g1.pathExists(1, 5, {2,3}));
    EXPECT_TRUE(g1.pathExists(2, 6, {9,8}));
    EXPECT_FALSE(g1.pathExists(2, 5, {4}));
    EXPECT_TRUE(g1.pathExists(1, 9, {}));
    EXPECT_TRUE(g1.pathExists(1, 9, {7,8}));
    EXPECT_TRUE(g1.pathExists(1, 9, {2,7}));
    EXPECT_TRUE(g1.pathExists(1, 9, {3,8}));
    EXPECT_FALSE(g1.pathExists(1, 9, {1}));
    EXPECT_FALSE(g1.pathExists(1, 9, {9}));
    EXPECT_FALSE(g1.pathExists(1, 9, {2,3}));
    EXPECT_FALSE(g1.pathExists(1, 9, {4}));
    EXPECT_FALSE(g1.pathExists(1, 9, {5}));
    EXPECT_FALSE(g1.pathExists(1, 9, {6}));
    EXPECT_FALSE(g1.pathExists(1, 9, {1,2,3,4,5,6,7,8,9}));

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    EXPECT_TRUE(g6.pathExists(1, 3, {5}));
    EXPECT_TRUE(g6.pathExists(1, 3, {7}));
    EXPECT_TRUE(g6.pathExists(1, 3, {5,7}));
    EXPECT_TRUE(g6.pathExists(2, 1, {5,6,7,8}));
    EXPECT_FALSE(g6.pathExists(2, 1, {3}));
    EXPECT_FALSE(g6.pathExists(4, 8, {7,6,2}));

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_TRUE(g7.pathExists(1, 2, {3}));
    EXPECT_TRUE(g7.pathExists(2, 1, {3}));
    EXPECT_TRUE(g7.pathExists(1, 3, {2}));
    EXPECT_TRUE(g7.pathExists(3, 1, {2}));
    EXPECT_TRUE(g7.pathExists(2, 3, {1}));
    EXPECT_TRUE(g7.pathExists(3, 2, {1}));
}

// ----------------------------------------------------------
// Exercise 6
// ----------------------------------------------------------
TEST(test_6, countLakes) {
    cout << "Testing 'countLakes'" << endl;

    cout << "  . example map" << endl;
    string m1[] = {"###############",
                   "#..##...####..#",
                   "#..###.#.###..#",
                   "############..#",
                   "####...###....#",
                   "#..##...#######"};
    EXPECT_EQ(5, FunWithGraphs::countLakes(6, 15, m1));

    cout << "  . other maps" << endl;
    string m2[] = {"####",
                   "####",
                   "####",
                   "####"};
    EXPECT_EQ(0, FunWithGraphs::countLakes(4, 4, m2));

    string m3[] = {".###.###",
                   "#.###.##",
                   ".#.#.#.#",
                   "#.#.###."};
    EXPECT_EQ(1, FunWithGraphs::countLakes(4, 8, m3));

    string m4[] = {".#..#..#",
                   "##..####",
                   ".######.",
                   "#..#..#."};
    EXPECT_EQ(6, FunWithGraphs::countLakes(4, 8, m4));
}

// ----------------------------------------------------------
// Exercise 7
// ----------------------------------------------------------
TEST(test_7, reduceLakes) {
    cout << "Testing 'reduceLakes'" << endl;

    cout << "  . example map" << endl;
    string m1[] = {"###############",
                   "#..##...####..#",
                   "#..###.#.###..#",
                   "############..#",
                   "####...###....#",
                   "#..##...#######"};
    EXPECT_EQ(6, FunWithGraphs::reduceLakes(6, 15, m1, 3));
    EXPECT_EQ(2, FunWithGraphs::reduceLakes(6, 15, m1, 4));
    EXPECT_EQ(27, FunWithGraphs::reduceLakes(6, 15, m1, 0));

    cout << "  . other maps" << endl;
    string m2[] = {"..#..",
                   "#.#.#",
                   "#.#.#",
                   "###.."};
    EXPECT_EQ(4, FunWithGraphs::reduceLakes(4, 5, m2, 1));

    string m3[] = {".#..#..#",
                   "##..####",
                   ".######.",
                   "#..#..#."};
    EXPECT_EQ(1, FunWithGraphs::reduceLakes(4, 8, m3, 5));
    EXPECT_EQ(3, FunWithGraphs::reduceLakes(4, 8, m3, 4));
    EXPECT_EQ(5, FunWithGraphs::reduceLakes(4, 8, m3, 3));
}