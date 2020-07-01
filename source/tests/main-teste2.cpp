

#include <cstdlib>
#include <iostream>

#include "bstree.cpp"
#include "bstree.hpp"

#include "node.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    int resolution = 20; // you should set your resolution here if you want to display;

    Node* root = new Node(-20,400,19,361,50,350);

    Node* node1 = new Node(-20,400,-17,289,0,0);
    Node* node2 = new Node(-17,289,-17,361,72,288);

    Node* node3 = new Node(-17,289,-14,1,0,0);
    Node* node4 = new Node(-14,196,-14,361,165,195);

    Node* node5 = new Node(-14,196,-11,121,0,0);
    Node* node6 = new Node(-8,64,19,361,240,120);

    Node* node7 = new Node(-11,121,-8,64,0,0);
    Node* node8 = new Node(-11,121,19,361,297,63);

    Node* node9 = new Node(-8,64,-5,25,0,0);
    Node* node10 = new Node(-5,25,19,361,336,24);

    Node* node11 = new Node(-5,25,-2,4,0,0);
    Node* node12 = new Node(-2,4,19,361,357,3);

    Node* node13 = new Node(-2,4,1,1,0,0);
    Node* node14 = new Node(1,1,19,361,360,0);

    Node* node15 = new Node(1,1,4,16,0,0);
    Node* node16 = new Node(4,16,19,361,345,0);

    Node* node17 = new Node(4,16,7,49,0,0);
    Node* node18 = new Node(7,49,19,361,312,0);

    Node* node19 = new Node(7,49,10,100,0,0);
    Node* node20 = new Node(10,100,19,361,261,0);

    Node* node21 = new Node(10,100,13,169,0,0);
    Node* node22 = new Node(13,169,19,361,192,0);

    Node* node23 = new Node(13,169,16,256,0,0);
    Node* node24 = new Node(16,256,19,361,105,0);

    bstree t;

    t.insert(root);
    t.insert(node1);
    t.insert(node2);
    t.insert(node3);
    t.insert(node4);
    t.insert(node5);
    t.insert(node6);
    t.insert(node7);
    t.insert(node8);
    t.insert(node9);
    t.insert(node10);
    t.insert(node11);
    t.insert(node12);
    t.insert(node13);
    t.insert(node14);
    t.insert(node15);
    t.insert(node16);
    t.insert(node17);
    t.insert(node18);
    t.insert(node19);
    t.insert(node20);
    t.insert(node21);
    t.insert(node22);
    t.insert(node23);
    t.insert(node24);


    cout << "Pontos na resolucao -> " << resolution << endl;
    cout << "[" << endl;
    t.displayWithResolution(root,resolution);
    cout << "]" << endl;

    //cout << "Area da Raiz: " << t.area(root) << endl;

    //Point * p = t.intersection(root, rr);
    //cout << "Se intersecta em : (" << p->getX() << "," << p->getY() <<")" << endl;

    //std::cout << "Smallest Distance:" << t.calcDistance(t.smallestReactangle()) << std::endl;

    std::cout << "Length: " << t.length(root) << std::endl;

    return EXIT_SUCCESS;
}
