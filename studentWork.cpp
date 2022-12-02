#include <list>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>



bool BinaryTree:is_height_tree(BinaryNode *root){
    if (root != nullptr){
        if (root->left != nullptr && root->right != nullptr){
                if (root.value == root.height){
                    if (root->right != nullptr){
                        return is_height_tree(root->left);
                    }
                    if (root->right != nullptr){
                        return is_height_tree(root->right);
                    }
                }
                else{
                    return false;
                }
        }

        else{
            if (root.value == root.height){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return false;
    }

}