#ifndef TREE_EDIT_DISTANCE
#define TREE_EDIT_DISTANCE

#include <vector>
#include <string>
#include <boost>
namespace zhang_shasha {

    //Node Class
    class Node;

    class Node{
        public:
            std::string label; //node label
            int index; //preorder index
            std::vector<zhang_shasha::Node> children;
            zhang_shasha::Node leftmost; //used by recursive leftmost() function
    };
   
   //Tree Class
    class Tree{
        zhang_shasha::Node root;

        std::vector<int> l;
        //list of keyroots. i.e. nodes with a left child and the tree root
        std::vector<int> keyroots;
        std::vector<std::string> labels;

        Tree(zhang_shasha::Node & root){ //construct the tree by passing a node for the root
            this.root = root;
        }

        
    };
}

#endif