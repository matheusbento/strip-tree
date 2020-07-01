#include "node.hpp"

Node::Node(){
}
Node::Node(
            double xb = 0,
            double yb= 0,
            double xe= 0,
            double ye= 0,
            double wl= 0,
            double wr= 0,
            Node* l = nullptr,
            Node* r = nullptr,
            int isParent=0
            )
                        : xb_(xb),
                            isParent_(isParent),
                          yb_(yb),
                          xe_(xe),
                          ye_(ye),
                          wl_(wl),
                          wr_(wr),
                          left_(l),
                          right_(r)
                    {
                    }

void Node::setRight(Node* r){
    right_ = r;
}

void Node::setLeft(Node* l){
    left_ = l;
}

Node* Node::getLeft(){
    return left_;
}
Node* Node::getRight(){
    return right_;
}
