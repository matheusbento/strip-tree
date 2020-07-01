#include "bstree.hpp"
#include <iostream>
#include "node.cpp"
#include "node.hpp"
#include "point.cpp"
#include <stdexcept>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>

bstree::bstree()
    : root_(nullptr)
{
}

bstree::bstree(std::initializer_list<Node*> values)
    : root_(nullptr)
{
    for(auto v : values)
        insert(v);
}

bstree::~bstree()
{
    // TODO!
}

Node*
bstree::insert(Node* val)
{
    Node* n = root_;
    Node* parent = nullptr;

    while(n != nullptr)
    {
        if(n == val)
            throw std::logic_error("Chave duplicada");

        parent = n;

        if(n->getLeft() == nullptr && n->getRight() == nullptr){
            n = n->getLeft();
        }else if(n->getLeft() != nullptr && n->getRight() == nullptr){
            n = n->getRight();
        }else if(n->getLeft() == nullptr && n->getRight() != nullptr){
            n = n->getLeft();
        }else{
            n = n->getRight();
        }
    }

    Node* nn = val;

    if(parent == nullptr){
        root_ = nn;
    }else if(parent->getLeft() == nullptr){
        parent->isParent_ = 1;
        parent->setLeft(nn);
    }else{ // val > parent->data_
        parent->isParent_ = 1;
        parent->setRight(nn);
    }

    nn->parent_ = parent;
    return nn;
}

Node* bstree::find(Node* val)
{
    return find(root_, val);
}

Node*
bstree::find(Node* n, Node* val)
{
    if(n == nullptr)
        return nullptr;

    if(val == n)
        return n;

    if(n->getLeft() != nullptr)
        return find(n->getLeft(), val);
    else
        return find(n->getRight(), val);
}

void bstree::display(Node* n)
{
    if(n->getLeft() != nullptr)
        display(n->getLeft());

    std::cout << "{" << n->xb_ << "," << n->yb_ << "," << n->xe_ << "," << n->ye_ << "," << n->wl_ << "," << n->wr_ << "," << "}" << std::endl;

    if(n->getRight() != nullptr)
        display(n->getRight());
}

Node* bstree::smallestReactangle(Node *n = nullptr){
    if(n == nullptr){
        n = root_;
    }

    double distance = calcDistance(n);

    if(n->getLeft() != nullptr){
        Node* auxNode = smallestReactangle(n->getLeft());
        double aux = calcDistance(auxNode);
        return  aux < distance ? auxNode : n;
    }

    if(n->getRight() != nullptr){
        Node* auxNode = smallestReactangle(n->getRight());
        double aux = calcDistance(auxNode);
        return  aux < distance ? auxNode : n;
    }

    return n;
}

double bstree::calcDistance(Node* n){
    return sqrt(pow(n->xe_ - n->xb_, 2) + pow(n->ye_ - n->yb_, 2) * 1.0);
}

double bstree::length(Node* n){
    if(n == nullptr){
        return 0;
    }

    if(n->getLeft() == nullptr && n->getRight() == nullptr){
        return calcDistance(n);
    }else{
        return length(n->getLeft()) + length(n->getRight());
    }
}

double bstree::area(Node* n){
    if(n == nullptr){
        return 0;
    }
    return (n->wr_+n->wl_)*calcDistance(n);
}

Point* bstree::intersection(Node* x, Node* v){
    Point *A = new Point(x->xb_, x->yb_);
    Point *B = new Point(x->xe_, x->ye_);
    Point *C = new Point(v->xb_, v->yb_);
    Point *D = new Point(v->xe_, v->ye_);
    double a1 = B->y_ - A->y_;
    double b1 = A->x_ - B->x_;
    double c1 = a1*(A->x_) + b1*(A->y_);

    double a2 = D->y_ - C->y_;
    double b2 = C->x_ - D->x_;
    double c2 = a2*(C->x_)+ b2*(C->y_);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        return NULL;
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
         return new Point(x, y);
    }
}

void bstree::displayWithResolution(Node*n, int resolution){
    if (n == nullptr){
        return ;
    }

    resolution--;

    if(resolution >= 0) {
        if (n->left_ != nullptr) {
            displayWithResolution(n->left_, resolution);
        }

        if (n->right_ != nullptr) {
            displayWithResolution(n->right_, resolution);
        }
    }

    if(
       resolution >= -1 && !n->isParent_ ||
       resolution == -1 && n->isParent_
       ){
        std::cout << "\t" << n->xb_ << "," << n->yb_ << "," << n->xe_ << "," << n->ye_ << ","<< n->wl_ << ","<< n->wr_ << "" << std::endl;
    }

    return ;
}

Node* bstree::getRoot(){
    return root_;
}
