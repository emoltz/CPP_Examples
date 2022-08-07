#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Result{
public:
    int left;
    int right;
    Result(int newLeft = 0, int newRight = 0) : left(newLeft), right(newRight){}
};

template <class T>
class BSTNode{
private:
    T data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
public:
    friend int numOfChildren(BSTNode<T>* root);
};

/*
 * Your task is to design a function (recursive or iterative) which will determine the total quantity of left and right children in the binary search tree. Your function should return a Result object where left is the number of left pointers which are not pointing to nullptr and right is the number of right pointers which are not pointing to nullptr. Your function will take a pointer to the root node of the tree and, as indicated, is a friend of the BSTNode class.
 *
 *        50
 *          ->
 *          70
 *      65 <- -> 90
 *
 *      Has 1 left pointer (the link from 70 to 65) and 2 right pointers (50 to 70 and 70 to 90).
 */

template <class T>
Result numOfChildren(BSTNode<T>* root){
    Result res = Result();
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return res;
    else {
        Result leftRes = numOfChildren(root->left);
        Result rightRes = numOfChildren(root->right);
        int left = leftRes.left + rightRes.left + 1;
        int right = leftRes.right + rightRes.right + 1;
        if (root->left == nullptr)
            left--;
        if (root->right == nullptr)
            right--;
        res = Result(left, right);
        return res;
    }
}
