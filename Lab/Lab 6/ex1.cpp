#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

/*Bai giai de 1:
*/
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to initialize an array with n random values
void initializeArray(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % 100); // Adjust the range of random values as needed
    }
}

// Function to build a binary tree with the specified structure
TreeNode* buildBinaryTree(const std::vector<int>& arr, int start, int end, int E) {
    if (start > end) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(E);

    if (start == end) {
        root->value = arr[start];
        return root;
    }

    int mid = (start + end) / 2;
    root->left = buildBinaryTree(arr, start, mid, E);
    root->right = buildBinaryTree(arr, mid + 1, end, E);
    
    return root;
}

// Function to display tree information (in-order traversal)
void displayTree(TreeNode* root) {
/*Bai giai de 2: */
        displayTree(root->left);
        std::cout << root->value << " ";
        displayTree(root->right);
    }


// Function to search for a value in the tree using recursion
TreeNode* searchValue(TreeNode* root, int target) {
    if (!root || root->value == target) {
        return root;
    }

    if (target < root->value) {
        return searchValue(root->left, target);
    } else {
        return searchValue(root->right, target);
    }
}

// Function to insert a new node into the tree
TreeNode* insertNode(TreeNode* root, int value, int E) {
    if (!root) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value, E);
    } else {
        root->right = insertNode(root->right, value, E);
    }

    return root;
}

// Function to remove a node from the tree
TreeNode* removeNode(TreeNode* root, int value, int E) {
    if (!root) {
        return nullptr;
    }
/*Bai giai de 3:*/
    if (value < root->value) {
        root->left = removeNode(root->left, value, E);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value, E);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = removeNode(root->right, temp->value, E);
    }

    return root;
}

int main() {
    int n = 6; // Number of elements in the array
    int E = 42; // Value greater than any element in the array

    std::vector<int> arr;
    initializeArray(arr, n);

    TreeNode* root = buildBinaryTree(arr, 0, n - 1, E);

    std::cout << "Original Tree: ";
    displayTree(root);
    std::cout << std::endl;

    int target = arr[3]; // Example search value
    TreeNode* foundNode = searchValue(root, target);

    if (foundNode) {
        std::cout << "Node with value " << target << " found. Subtree: ";
        displayTree(foundNode);
        std::cout << std::endl;
    } else {
        std::cout << "Node with value " << target << " not found." << std::endl;
    }

    int newValue = 50; // Example value to insert
    root = insertNode(root, newValue, E);

    std::cout << "Tree after inserting " << newValue << ": ";
    displayTree(root);
    std::cout << std::endl;

    int removeValue = arr[1]; // Example value to remove
    root = removeNode(root, removeValue, E);

    std::cout << "Tree after removing " << removeValue << ": ";
    displayTree(root);
    std::cout << std::endl;

    // Remember to free the memory allocated for the tree nodes
    return 0;
}
