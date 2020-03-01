#include <iostream>
#include <string>
#include <vector>
#include <utility>

//This will not work as inner is a copy 
void reverseString(std::string &word){
    if (word.size() < 2) {
        return;
    }
    std::swap(word[0], word[word.size()-1]);
    std::string inner = word.substr(1, word.size()-2);
    reverseString(inner);
}

void _reverseVector(std::vector<char>::iterator start, std::vector<char>::iterator end){
    if (end - start > 0) {
        char i = *start;
        *start = *end;
        *end = i;
        _reverseVector(start+1, end-1);
    }

}

void reverseVector(std::vector<char>& v){
    _reverseVector(v.begin(), v.end()-1);
}

void reverseArray(char s[]) {
    if (strlen(s) > 1) {
        char i = s[0];
        s[0] = s[strlen(s) -1];
        s[strlen(s) - 1] = i
        reverseArray()

    }
}

int factorial(const int nu)
{
    if (nu == 1) {
        return 1;
    }else{
        return nu + factorial(nu-1);
    }
}

struct ListNode{
    int value;
    ListNode* next;
};

void createLinkedList(ListNode* head, std::vector<int> values, int index){
    if (head == NULL){
        return;
    }
    head->next = new ListNode({values[index]});
    if (index+1 < values.size()){
        createLinkedList(head->next, values, index+1);
    }
}

void printLinkedList(ListNode* head){
    std::cout << head->value;
    if (head->next != NULL){
        printLinkedList(head->next);
    }else{
        std::cout << std::endl;
    }
}

ListNode* swapPairsLinkedList(ListNode* head){
    if (head != NULL && head->next != NULL) {
        ListNode* s0 = head;
        ListNode* s1 = s0->next;
        ListNode* s2 = s1->next;
        head = s1;
        head->next = s0;
        head->next->next = swapPairsLinkedList(s2);
    }
    return head;
}

ListNode* reverseLinkedListI(ListNode* head){
    ListNode* prevNode = NULL;
    ListNode *currNode, *nextNode;
    currNode = nextNode = head;
    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

ListNode* reverseLinkedListR(ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    ListNode* temp = reverseLinkedListR(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

struct TreeNode{
    int value;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

public:
    TreeNode(int v){
        this->value = v;
    }
    TreeNode(int v, TreeNode* l, TreeNode* r){
        this->value = v;
        this->left = l;
        this->right = r;
    }
};

TreeNode* searchBST(TreeNode* root, int value){
    if (root == NULL){
        return NULL;
    }else if (value == root->value){
        return root;
    }else if (value < root->value){
        return searchBST(root->left, value);
    }else if (value > root->value){
        return searchBST(root->right, value);
    }else{
        return NULL;
    }
}

std::vector<int> getPascalTriangleRow(int rowIndex){
    if (rowIndex == 0){
        return std::vector<int>{1};
    }
    if (rowIndex == 1){
        return std::vector<int>{1,1};
    }
    std::vector<int> curr = getPascalTriangleRow(rowIndex-1);
    int prev = 1; 
    for (int i = 1; i < curr.size(); i++){
        int sum = curr[i] + prev;
        prev = curr[i];
        curr[i] = sum;
    }
    curr.push_back(1);
    return curr;
}

 int main(int argc, char** argv){
    // reverseString
    std::string word = "hello";
    reverseString(word);
    std::cout << "Reversed string : " << word << "\n";

/*
    //Linked lists
    ListNode* linkedList = new ListNode({1});
    createLinkedList(linkedList, std::vector<int>{2,3,4,5}, 0);
    std::cout << "Original Linked list: ";
    printLinkedList(linkedList);
    ListNode* sLinkedList = swapPairsLinkedList(linkedList);
    std::cout << "Swapped pairs Linked list: ";
    printLinkedList(sLinkedList);
    ListNode* rILinkedList = reverseLinkedListI(sLinkedList);
    std::cout << "Iteratively reversed linked list: ";
    printLinkedList(rILinkedList);

    // ListNode* rRLinkedList = reverseLinkedListR(sLinkedList);
    // std::cout << "Recursive        currNode->next = prevNode;
    // if (word.size() == 1) {
    //     std::cout << word[word.size() -1];
    //     reverseString(word.substr(0, word.size()-1));
    // }
ode({4});
    root->left = new TreeNode({2});
    root->right = new TreeNode({7});
    root->left->left = new TreeNode({1});
    root->left->right = new TreeNode({3});
    TreeNode* found = searchBST(root, 5);
*/
    //Pascal's triangle
    // std::vector<int> row = getPascalTriangleRow(15);
    // for (int i = 0; i < row.size(); i++){std::cout<<row[i]<< " ";}
    // std::cout<<"\n";
    
}
