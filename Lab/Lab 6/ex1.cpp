#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
/*Loi giai bai 1: 
PSEUDO CODE:
FUNCTION isOctahedral(x):
    n = 1
    WHILE True:
        octahedral = (2 * n^2 + n) / 3
        IF octahedral == x:
            RETURN True
        ELSE IF octahedral > x:
            RETURN False
        n = n + 1

FUNCTION verifyArray(arr):
    FOR each number in arr:
        IF isOctahedral(number) == False:
            PRINT "Not Octahedral:", number
        ELSE:
            PRINT "Octahedral:", number

Example Implementation (python):
def is_octahedral(x):
    n = 1
    while True:
        octahedral = (2 * n**2 + n) // 3
        if octahedral == x:
            return True
        elif octahedral > x:
            return False
        n += 1

def verify_array(arr):
    for number in arr:
        if is_octahedral(number):
            print(f"Octahedral: {number}")
        else:
            print(f"Not Octahedral: {number}")

# Example usage:
arr = [1, 2, 19, 35, 92]
verify_array(arr)
*/

/* Loi giai bai 2:
PSEUDO CODE:
FUNCTION bfsTraversal(root):
    INIT queue
    ADD root to queue
    WHILE queue is not empty:
        current = POP from queue
        PRINT current.value
        FOR each child of current:
            ADD child to queue

Example in python :
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def bfs_traversal(root):
    if not root:
        return

    queue = [root]
    while queue:
        current = queue.pop(0)
        print(current.value, end=" ")
        for child in current.children:
            queue.append(child)

# Example tree
root = TreeNode(10)
child1 = TreeNode(4)
child2 = TreeNode(8)
child3 = TreeNode(13)
child4 = TreeNode(20)
child5 = TreeNode(90)
child6 = TreeNode(7)

root.children = [child1, child2]
child1.children = [child3, child4]
child2.children = [child5]
child5.children = [child6]

bfs_traversal(root)  # Output: 10 4 8 13 20 90 7

*/


/* Loi giai bai 3:
PSEUDO CODE:
FUNCTION enhancedSelectionSort(arr):
    left = 0
    right = n - 1
    WHILE left < right:
        minIndex = left
        maxIndex = left
        FOR i = left TO right:
            IF arr[i] < arr[minIndex]:
                minIndex = i
            IF arr[i] > arr[maxIndex]:
                maxIndex = i
        SWAP(arr[minIndex], arr[left])
        IF maxIndex == left:
            maxIndex = minIndex
        SWAP(arr[maxIndex], arr[right])
        left = left + 1
        right = right - 1

Implemen example in python : 
def enhanced_selection_sort(arr):
    left = 0
    right = len(arr) - 1

    while left < right:
        min_index = left
        max_index = left

        for i in range(left, right + 1):
            if arr[i] < arr[min_index]:
                min_index = i
            if arr[i] > arr[max_index]:
                max_index = i

        arr[left], arr[min_index] = arr[min_index], arr[left]

        if max_index == left:
            max_index = min_index

        arr[right], arr[max_index] = arr[max_index], arr[right]

        left += 1
        right -= 1

# Example usage
arr = [10, 4, 8, 13, 20, 7, 90]
print("Original Array:", arr)
enhanced_selection_sort(arr)
print("Sorted Array:", arr)

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
/*de 2: */
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
    }}

  /*de 3 ok:*/
        root->left = removeNode(root->left, value, E);
     else if (value > root->value) {
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
