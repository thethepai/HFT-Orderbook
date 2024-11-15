#include <iostream>
#include <memory>

class TreeNode {
public:
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    std::shared_ptr<TreeNode> root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inorder() const {
        inorderRec(root);
        std::cout << std::endl;
    }

private:
    std::shared_ptr<TreeNode> insertRec(std::shared_ptr<TreeNode> node, int value) {
        if (!node) {
            return std::make_shared<TreeNode>(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void inorderRec(std::shared_ptr<TreeNode> node) const {
        if (node) {
            inorderRec(node->left);
            std::cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.inorder(); // Output: 2 3 4 5 6 7 8

    return 0;
}