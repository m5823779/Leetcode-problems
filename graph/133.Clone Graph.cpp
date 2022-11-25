/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // method 1.1: DFS
        // 1. create hash map, to record which node has been visited
        // 2. deep copy (use new operator) node
        // 3. mapping old node, and new node (which just created in step2) into hash map
        // 4. iterate old node's neighbors
        // 5. if neighbors (node) already exsit in hash map, append to new node's neighbors
        // 6. if not already exsit in hash map, do recursive
        // 7. return new node
        
        if (!node) return nullptr;
        return dfs(node);
    }
    
private:
    unordered_map<Node*, Node*> old2new;
    
    Node* dfs(Node* cur) {
        Node* clone = new Node(cur->val);
        old2new[cur] = clone;
        
        for (Node* it : cur->neighbors) {  
            // neighbor have already been cloned
            if (old2new.find(it) != old2new.end())  
                clone->neighbors.push_back(old2new[it]);
            
            // neighbor have not been cloned
            else                        
                clone->neighbors.push_back(dfs(it));
        }
        return clone;
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        // method 1.2: DFS
        if (!node) return NULL;
        if (visited.count(node))
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        for (Node* n : node->neighbors) {
            cloned->neighbors.push_back(cloneGraph(n));
        }
        
        return cloned;
    }
    
private: 
    unordered_map<Node*, Node*> visited;
    
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};