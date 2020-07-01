#ifndef __BSTREE__HPP__
#define __BSTREE__HPP__
#include "node.hpp"
#include "point.h"
#include <initializer_list>

class bstree
{

    public:

        bstree();

        bstree(std::initializer_list<Node*> values);

        ~bstree();

        Node* insert(Node * n);

        Node* find(Node * n);

        void display(Node * n);

        Node* smallestReactangle(Node* n);

        double calcDistance(Node* n);

        double length(Node* n );

        double area(Node* n );

        Point* intersection(Node * x, Node* v);

        void displayWithResolution(Node*n, int resolution);

        Node* getRoot();

    private:

        Node* find(Node* n, Node* val);

    private:

        Node* root_;

};

#endif
