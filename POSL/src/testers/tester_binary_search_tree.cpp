#include "tester_binary_search_tree.h"
#include "../tools/binary_search_tree.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_BinarySearchTree::Tester_BinarySearchTree(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_BinarySearchTree::test()
{
    vector<int> v ({25, 23, 24, 28, 26, 29, 21, 30, 27});
    int z = v.size(); //9
    shared_ptr<BinarySearchTree<int>> b(make_shared<BinarySearchTree<int>>(v[0],v[0]));
    for (int i = 1; i < z; i++)
        b->insert(v[i], v[i]);
    vector<int> r;
    for (int i = 1; i <= z; i++)
        r.push_back(b->get_value_in_position(i));
    //cout << Tools::configurationToString(r) << endl;
    sort(v.begin(), v.end());
    //cout << Tools::configurationToString(v) << endl;
    return (Tools::equals_vectors(v, r)) ? "BinarySearchTree: OK !" : "BinarySearchTree: Fail :/";
}
