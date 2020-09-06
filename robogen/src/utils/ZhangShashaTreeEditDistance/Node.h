//Node for TreeEditDistance 
#ifndef ZHANG_SHASHA_NODE_
#define ZHANG_SHASHA_NODE_

#include <vector>
#include <string>

namespace zhang_shasha {

    struct Node{
            std::string label; //node label
            int index; //preorder index

            std::vector<Node> children;
            zhang_shasha::Node leftmost; //used by recursive 
    };
}


#endif