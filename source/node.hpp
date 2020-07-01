#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

class Node
{
    public:
        Node();
        Node(double xb, double yb, double xe, double ye, double wl, double wr, Node* l, Node* r, int isParent);
        Node* getLeft();
        Node* getRight();
        void setLeft(Node* l);
        void setRight(Node* r);
        double xb_; //x begin
        double yb_; //y begin
        double xe_; //x end
        double ye_; //y end
        double wl_;
        double wr_;
        int isParent_;
        Node* parent_;
        Node* left_;
        Node* right_;

    private:
        friend class bstree;
        friend class utils;



};
#endif // NODE_HPP_INCLUDED
