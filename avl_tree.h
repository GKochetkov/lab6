#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include <malloc.h>

#define NODE struct node


NODE {
    int value;
    NODE* left;
    NODE* right;
};

//create a node
NODE* Create(int value) {
    NODE* res;
    res = (NODE*)malloc(sizeof(NODE));
    res -> value = value;
    res -> left = NULL;
    res -> right = NULL;
    return res;
}

int maxI(int arg1, int arg2) {
    if (arg1 >= arg2)
        return arg1;
    return arg2;
}

//calculate height of node after changes in it's subtree
int CalcHeight(NODE* n) {
    int left = 0, right = 0;

    if (n -> left != NULL)
        left = CalcHeight(n -> left);
    if (n -> right != NULL)
        right = CalcHeight(n -> right);

    return maxI(left, right) + 1;
}

//calculate angle of node's subtree
int Angle(NODE* n) {
    int left = 0, right = 0;

    if (n -> left != NULL)
        left = CalcHeight(n -> left);
    if (n -> right != NULL)
        right = CalcHeight(n -> right);

    return (right - left);
}

//simple rotates
NODE* RightRot(NODE* n) {
    NODE* nNew = n -> left;
    n -> left = nNew -> right;
    nNew -> right = n;

    CalcHeight(n);
    CalcHeight(nNew);
    return nNew;
}

NODE* LeftRot(NODE* n) {
    NODE* nNew = n -> right;
    n -> right = nNew -> left;
    nNew -> left = n;

    CalcHeight(n);
    CalcHeight(nNew);
    return nNew;
}

//big rotates
NODE* BigLeftRot(NODE* n) {
    n -> right = RightRot(n -> right);
    return LeftRot(n);
}

NODE* BigRightRot(NODE* n) {
    n -> left = LeftRot(n -> left);
    return RightRot(n);
}

//rebalancing subtree after adding new node
NODE* Rebalancing(NODE* root)
{
	if (Angle(root) == 2)
	{
		if (Angle(root -> right) < 0)
			return BigLeftRot(root);
        else
            return LeftRot(root);
	}

	if (Angle(root) == -2)
	{
		if (Angle(root -> left) > 0)
			return BigRightRot(root);
        else
            return RightRot(root);
	}
	return root;
}

//adding a new node in the tree
NODE* Add(NODE* root, NODE* elem) {
    if (elem -> value > root -> value) {
        if (root -> right == NULL)
            root -> right = elem;
        else
            Add(root -> right, elem);

    }
    else {
        if (root -> left == NULL)
            root -> left = elem;
        else
            Add(root -> left, elem);
    }

    return Rebalancing(root);
}

void InOrder(NODE *n) {
    if (n -> left != NULL)
        InOrder(n -> left);

    printf("%d ", n -> value);

    if (n -> right != NULL)
        InOrder(n -> right);
}

//delete the tree after the program is completed
void Clear(NODE *root) {
    if (root -> left != NULL)
        Clear(root -> left);
    if (root -> right != NULL)
        Clear(root -> right);

    free(root);
}

int Search(int value, NODE *cur) {
    if (cur -> value == value)
        return 1;

    if (cur -> value > value)
        if (cur -> left == NULL)
            return 0;
        else
            Search(value, cur -> left);
    else
        if (cur -> right == NULL)
            return 0;
        else
            Search(value, cur -> right);
}

#endif // AVL_TREE_H_INCLUDED
