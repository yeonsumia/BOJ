#include<iostream>
#include<vector>

using namespace std;

class tree_node{
public:
    tree_node(char value, char left, char right){
        this->value = value;
        this->left = left;
        this->right = right;
    }
    char value;
    char left;
    char right;
};

void preorder(tree_node root, const vector<tree_node>& tree){
    cout << root.value;
    if(root.left != '.') preorder(tree[root.left - 'A'], tree);
    if(root.right != '.') preorder(tree[root.right - 'A'], tree);
}

void inorder(tree_node root, const vector<tree_node>& tree){
    if(root.left != '.') inorder(tree[root.left - 'A'], tree);
    cout << root.value;
    if(root.right != '.') inorder(tree[root.right - 'A'], tree);
}

void postorder(tree_node root, const vector<tree_node>& tree){
    if(root.left != '.') postorder(tree[root.left - 'A'], tree);
    if(root.right != '.') postorder(tree[root.right - 'A'], tree);
    cout << root.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char value;
    char left, right;
    cin >> N;
    int i;
    vector<tree_node> tree;
    for(i=0;i<N;i++)
        tree.emplace_back('A'+i, NULL, NULL);
    for(i=0;i<N;i++){
        cin >> value >> left >> right;
        tree[value-'A'].left = left;
        tree[value-'A'].right = right;
    }
    // root node is 'A'
    preorder(tree[0], tree); cout << "\n";
    inorder(tree[0], tree); cout << "\n";
    postorder(tree[0], tree); cout << "\n";

    return 0;
}