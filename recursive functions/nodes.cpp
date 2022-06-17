#include <iostream>
using namespace std;

class Result{
public:
    int left;
    int right;
    Result(int newLeft = 0, int newRight = 0) : left(newLeft), right(newRight){}
};

template <class T>
class BSTNode{
    T data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
public:
    friend Result childrenCount(BSTNode *root, Result* result, int leftCount = 0, int rightCount = 0){
        if (root == nullptr){
            return *new Result(0,0);
        }

        if (root->left == nullptr && root->right == nullptr){
            //leaf node
            return *result;
        }

        childrenCount(root->left, result, result->left++, result->right);
        childrenCount(root->right, result, result->left, result->right++);

        return *result;
    }

    friend Result childCount_2(BSTNode *root, Result result){
        if (root == nullptr){
            return result;
        }
        else{
            if (root->left != nullptr){
                result.left++;
//            root = root->left;
                return childCount_2(root->left, result);
            }
            if (root->right != nullptr){
                result.right++;
//            root = root->right;
                return childCount_2(root->right, result);
            }
        }


    }

    friend Result findNumberOfChilds(BSTNode* head) {
        int right_child = 0;
        int left_child = 0;
        Result left_result, right_result;
        if ((head->left == nullptr) && (head->right == nullptr)) {
            return Result();
        } else if (head->left == nullptr) {
            right_result = findNumberOfChilds(head->right);
            ++right_child.right;
            return right_result;
        } else if (head->right == nullptr) {
            left_result = findNumberOfChilds(head->left);
            ++left_result.left;
            return left_result;
        } else {
            right_result = findNumberOfChilds(head->right);
            left_result = findNumberOfChilds(head->left);
            int total_left, total_right;
            total_left = right_result.left + left_result.left + 1;
            total_right = right_result.right + left_result.right + 1;
            return Result(total_left, total_right);
        }
    }

    friend Result countChildren(BSTNode *root, Result *result){
        if (root->right != nullptr){
            result->right++;
            countChildren(root->right, result);
        }

        if (root->left != nullptr){
            result->left++;
            countChildren(root->left, result);
        }
        return *result;
    }


};

int main(){



    return 0;
}