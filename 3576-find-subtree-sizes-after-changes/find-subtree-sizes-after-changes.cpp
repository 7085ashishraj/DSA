class Solution {
public:
    vector<vector<int>> tree;
    vector<vector<int>> charNodes;
    vector<int> newParent;
    string s;

    void findNewParents(int u) {
        int c = s[u] - 'a';

        if (u != 0 && !charNodes[c].empty()) {
            newParent[u] = charNodes[c].back();
        }

        charNodes[c].push_back(u);

        for (int v : tree[u]) {
            findNewParents(v);
        }

        charNodes[c].pop_back();
    }

    int calcSize(int u, vector<vector<int>>& finalTree,vector<int>& ans) {
        int size = 1;

        for (int v : finalTree[u]) {
            size += calcSize(v, finalTree, ans);
        }

        return ans[u] = size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        tree.assign(n, {});
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        newParent = parent;
        charNodes.assign(26, {});

        findNewParents(0);

        vector<vector<int>> finalTree(n);
        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n);
        calcSize(0, finalTree, ans);

        return ans;
    }
};