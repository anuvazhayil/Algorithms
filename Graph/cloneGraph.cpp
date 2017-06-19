/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>copy_table;
        queue<UndirectedGraphNode*>q;
        UndirectedGraphNode *curr;

        if(!node)
            return NULL;
        //making copy
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        copy_table[node] = copy;
        q.push(node);

        while(!q.empty()){
            curr = q.front();
            q.pop();
            for(auto neibr: curr->neighbors){
                //Check if copy already exist
                if(!copy_table.count(neibr)){
                    UndirectedGraphNode *copy_n = new UndirectedGraphNode(neibr->label);
                    copy_table[neibr] = copy_n;
                    q.push(neibr);
                }
                copy_table[curr]->neighbors.push_back(copy_table[neibr]);
            }
        }
        return copy;
    }
};
