#include <bits/stdc++.h>
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/

graphNode *makeCopy(graphNode *node, unordered_map<int, graphNode *> &vis)
{
    graphNode *copyNode = new graphNode(node->data);
    vis[node->data] = copyNode;
    for (auto &a : node->neighbours)
    {
        if (!vis[a->data])
            copyNode->neighbours.push_back(makeCopy(a, vis));
        else
            copyNode->neighbours.push_back(vis[a->data]);
    }
    return copyNode;
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    unordered_map<int, graphNode *> vis;
    return makeCopy(node, vis);
}