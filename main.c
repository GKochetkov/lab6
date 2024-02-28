#include <stdio.h>
#include <malloc.h>
#include "avl_tree.h"


int main()
{
    NODE* root;
    int count, value, n;

    scanf("%d", &count);

    if (count == 0) {
        printf("0");
        return 0;
    }

    //getting the root node
    scanf("%d", &value);
    root = Create(value);

    //getting rest of nodes
    for (int i = 1; i < count; i++) {
        scanf("%d", &value);
        root = Add(root, Create(value));
    }

    printf("%d\n", CalcHeight(root));
    printf("Elements: ");
    InOrder(root);
    printf("\nWhich element do you want to search?\n");
    scanf("%d", &n);
    printf("%d", Search(n, root));

    Clear(root);

    return 0;
}
