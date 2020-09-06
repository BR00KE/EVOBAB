#ifndef TREE_EDIT_DISTANCE
#define TREE_EDIT_DISTANCE

#include <vector>
#include <string>

namespace zhang_shasha {

    //Node Class
    class Node;

    class Node{
        public:
            std::string label; //node label
            int cost;
            int index; //preorder index
            std::vector<zhang_shasha::Node> children;
            zhang_shasha::Node leftmost; //used by recursive leftmost() function

            // Node(std::string label,int const){
            //     this->label = label;
            //     this->cost = cost;
            // }
            void addChild(zhang_shasha::Node & child){
                children.push_back(child);
            }
    };
   
   //Tree Class
    class Tree{
        zhang_shasha::Node root;

        std::vector<int> l;
        //list of keyroots. i.e. nodes with a left child and the tree root
        std::vector<int> keyroots;
        std::vector<std::string> labels; //postorder labels of tree nodes

        // Tree(zhang_shasha::Node & root){ //construct the tree by passing a node for the root
        //     this->root = root;
        //     //fill in the postorder list of labels
        //     labels = traverse(root,labels);
        // }

        //get a postorder ordering of the trees labels
        std::vector<std::string> traverse(const zhang_shasha::Node & node, std::vector<std::string> & labels){ 
            for(auto child: node.children){
                labels = traverse(child,labels);
            }
            labels.push_back(node.label);
            return labels;
        }

        
    };
}

#endif