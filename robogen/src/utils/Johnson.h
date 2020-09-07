// Credits to: Soha Hassoun, Tufts University
// Link: https://www.cs.tufts.edu/comp/150GA/homeworks/hw1/FindingCycle%20Code/johnson.cpp

#ifndef _JOHNSON_H_
#define _JOHNSON_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <deque>

namespace robogen{

    //SIGNATURES

    static void displayVecOfVec (std::vector<std::vector<int> >&  A) {
        std::vector< std::vector<int> >::iterator it;  
        int count = 0;
        for (it = A.begin(); 
            it != A.end(); 
            it++, count++) {

            std::vector<int> currentCycle = *it;
            std::cout << "[item " << count << " of size " << currentCycle.size() << "]\t";

            std::vector<int>::iterator nodeIter;

            for (nodeIter = currentCycle.begin(); nodeIter != currentCycle.end() ; nodeIter++) {
            std::cout << *nodeIter << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
        // Unblocks recursivly all blocked nodes, starting with a given node.

    static void unblock(int  node, std::vector<bool> & blocked, std::vector<std::vector<int> > & B_Fruitless)
    {
        // state of B_Fruitless
        blocked[node] = false;
        while (B_Fruitless[node].size() > 0) {
            int w = B_Fruitless[node][0];
            B_Fruitless[node].erase(find (B_Fruitless[node].begin(), B_Fruitless[node].end(), w) ) ;
            if (blocked[w]) {
            unblock(w, blocked, B_Fruitless);
            }
        }
    }

    static bool findCycles(int v, int s, std::vector<std::vector<int> >& adjList,std::vector<bool> & blocked,  std::deque<int>& stackLike,  std::vector<std::vector<int> >& B_Fruitless,std::vector<std::vector<int> > &  cycles) {

        bool f = false;
        stackLike.push_front(v);  // insert like a stack:  so at the front
        blocked[v] = true;
        

        // explore all neighbours -- recursively 
        for (int i = 0; i < adjList[v].size(); i++) {
            int w =  adjList[v][i];
                    
            // found cycle through ANY of my neighbours w.
            if (w == s) {
            std::vector<int>* cycle = new std::vector<int>;
            for (int j = 0; j < stackLike.size(); j++) {
                cycle->push_back( stackLike.at (stackLike.size() - j  - 1) );
            }
            cycles.push_back(*cycle);
            f = true;
            } else if (!blocked[w]) {
            if (findCycles(w, s, adjList, blocked, stackLike, B_Fruitless, cycles)) {
                f = true;
            }
            }
        } // for


        if (f) {
            unblock(v, blocked, B_Fruitless);
        } else {

            // go through all my neighbors w.
            //  v is pushed on B_Fruitless[w].
            // looking at B_Fruitless[w] = [v1, v2, ..] , i know i can get from v1 to w, and v2 to w, etc. 
            // later, whenever i block w, i recursively unblock v1, and v2, and v.. 

            for (int i = 0; i < adjList[v].size(); i++) {
            int w = adjList[v][i];

        // mark B_Fruitless[w] to point to v.  This says that going from v to w lead to an unfruitful search.
        // later when w is found to particiate in a cycle, i'd better get rid of this false assupmtion about
        // w not leading to fruitful cycles.

            std::vector<int>::iterator it;
            it = find(B_Fruitless[w].begin(), B_Fruitless[w].end(), v);
            if (it == B_Fruitless[w].end()) {
                B_Fruitless[w].push_back(v);
            }
            }
        }
        // find v and remove it from stack
        std::deque<int>::iterator it;

        it = find(stackLike.begin(), stackLike.end(), v);
        if (it != stackLike.end() ) {
            stackLike.erase(it);
        } 
        return f;
    } // bool  findCycles

}

#endif /* JOHNSON_H_*/
