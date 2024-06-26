#include <stdio.h>
#include <stdlib.h>


struct BSTnode {
    unsigned int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

typedef struct BSTnode BSTnode;


/* < fast implementation of queue > */

struct Queuenode {
    struct BSTnode *data;
    struct Queuenode *link;
};

struct Queue {
    struct Queuenode *front;
    struct Queuenode *rear;
};

typedef struct Queuenode Queuenode;
typedef struct Queue Queue;


void init_queue(Queue *queue) {
    queue->front = NULL;
    queue->rear  = NULL;
}


int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}


void enqueue(BSTnode *root, Queue *queue) {
    Queuenode *temp = (Queuenode *)malloc(sizeof(Queuenode));

    temp->data = root;
    temp->link = NULL;

    if (queue->front == NULL) {
        queue->front = temp;
        queue->rear  = temp;
    }
    else {
        queue->rear->link = temp;
        queue->rear = temp;
    }
}


void dequeue(Queue *queue) {
    /* don't care which data was in queue */
    Queuenode *temp;
    
    if (isQueueEmpty(queue)) {
        return;
    }
    
    temp = queue->front;
    queue->front = queue->front->link;
    free(temp);
}

/* < / fast implementation of queue > */


BSTnode *createBSTnode(unsigned int data) {
    BSTnode *new_node = (BSTnode *)malloc(sizeof(BSTnode));

    (*new_node).data  = data;
    (*new_node).left  = NULL;
    (*new_node).right = NULL;

    return new_node;
}


BSTnode *insertBSTnode(unsigned int data, BSTnode *root) {

    /* empty = parent */
    if (root == NULL) {
        return createBSTnode(data);
    }

    /* left child */
    else if (data <= root->data) {
        root->left = insertBSTnode(data, root->left);
    }

    /* right child */
    else {
        root->right = insertBSTnode(data, root->right);
    }

    return root;
}


BSTnode *searchBST(unsigned int data, BSTnode *root) {
    /* Return pointer to node which contains data */

    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchBST(data, root->left);
    }
    else /* if (data > root->data) */{
        return searchBST(data, root->right);
    }

}


int findLevel(unsigned int data, BSTnode *root) {
    /**
     * Find on which level is data,
     * otherwise return -1
     * 
     * NOTE:
     *  Count from 1, not 0
     * */

    int level = 1;

    while (root != NULL && root->data != data) {
        level++;

        if (data < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return (root == NULL) ? -1 : level;
}


BSTnode *findMinimum(BSTnode *root) {

    while (root != NULL && root->left != NULL) {
        root = root->left;
    }

    return root;
}


BSTnode *findMinimumRecursively(BSTnode *root) {

    if (root == NULL || root->left == NULL) {
        return root;
    }
    else {
        return findMinimumRecursively(root->left);
    }
}


BSTnode *findMaximum(BSTnode *root) {

    while (root != NULL && root->right != NULL) {
        root = root->right;
    }

    return root;
}


BSTnode *findMaximumRecursively(BSTnode *root) {

    if (root == NULL || root->right == NULL) {
        return root;
    }
    else {
        return findMaximumRecursively(root->right);
    }
}


int getHeight(BSTnode *root) {
    /* max depth of tree */
    int left_branch, right_branch;

    if (root == NULL) {
        return -1;  /* bcs max + 1: -1 + 1 = 0 which is height */
    }

    left_branch  = getHeight(root->left);
    right_branch = getHeight(root->right);

    return (left_branch > right_branch) ? left_branch + 1 : right_branch + 1;
}


int getNumberOfNodesLevelOrder(BSTnode *root) {
    /* via level order method */
    int count = 0;
    Queue q;

    if (root == NULL) {
        return 0;
    }

    init_queue(&q);
    enqueue(root, &q);

    while (!isQueueEmpty(&q)) {
        count++;

        if (q.front->data->left != NULL) {
            enqueue(q.front->data->left, &q);
        }

        if (q.front->data->right != NULL) {
            enqueue(q.front->data->right, &q);
        }

        dequeue(&q);
    }

    return count;
}


int getNumberOfNodesPreorder(BSTnode *root) {
    /* via preorder method, using recursion */
    int count;

    if (root == NULL) {
        return 0;
    }
    else {
        count = 1;
    }

    count += getNumberOfNodesPreorder(root->left);
    count += getNumberOfNodesLevelOrder(root->right);

    return count;
}


int getNumberOfNodesOnLevel(BSTnode *root, int level) {

    if (root == NULL || level <= 0) {
        return 0;
    }
    else if (level == 1) {
        return 1;
    }
    else {
        return getNumberOfNodesOnLevel(root->left, level-1) + getNumberOfNodesOnLevel(root->right, level-1);
    }
}


int hasPathSum(BSTnode *root, int sum) {
    /**
     *  Return true if there is a path from root to leaf,
     *  such that adding all the values equals the given sum.
     * */
    int sub_sum;

    if (root == NULL) {
        return sum == 0;
    }

    sub_sum = sum - root->data;

    return (hasPathSum(root->left, sub_sum) || hasPathSum(root->right, sub_sum));
}


/* < tree travel > */

void travelLevelOrder(BSTnode *root) {
    Queue q;

    if (root == NULL) {
        return;
    }

    init_queue(&q);
    enqueue(root, &q);

    while (!isQueueEmpty(&q)) {
        printf("%c\t", q.front->data->data);

        if (q.front->data->left != NULL) {
            enqueue(q.front->data->left, &q);
        }

        if (q.front->data->right != NULL) {
            enqueue(q.front->data->right, &q);
        }

        dequeue(&q);
    }
}


void travelPreorder(BSTnode *root) {
    /**
     * NOTE:
     *  1. data
     *  2. left
     *  3. right
     * */

    if (root == NULL) {
        return;
    }

    printf("%c\t", root->data);
    travelPreorder(root->left);
    travelPreorder(root->right);
}


void travelInorder(BSTnode *root) {
    /**
     * NOTE:
     *  1. left
     *  2. data
     *  3. right
     * */

    if (root == NULL) {
        return;
    }

    travelInorder(root->left);
    printf("%c\t", root->data);
    travelInorder(root->right);
}


void travelPostorder(BSTnode *root) {
    /**
     * NOTE:
     *  1. left
     *  2. right
     *  3. data
     * */

    if (root == NULL) {
        return;
    }

    travelPostorder(root->left);
    travelPostorder(root->right);
    printf("%c\t", root->data);
}


void mirror(BSTnode *root) {
    BSTnode *temp;

    if (root == NULL) {
        return;
    }

    mirror(root->left);
    mirror(root->right);

    temp        = root->left;
    root->left  = root->right;
    root->right = temp;
}

/* < / tree travel > */


/* < tree validity > */

int isSubBSTLesser(unsigned int data, BSTnode *root) {
    if (root == NULL) {
        return 1;
    }
    else if (root->data <= data && isSubBSTLesser(data, root->left) && isSubBSTLesser(data, root->right)) {
        return 1;
    }
    else {
        return 0;
    }
}


int isSubBSTGreater(unsigned int data, BSTnode *root) {
    if (root == NULL) {
        return 1;
    }
    else if (root->data > data && isSubBSTGreater(data, root->left) && isSubBSTGreater(data, root->right)) {
        return 1;   
    }
    else {
        return 0;
    }
}


int isBST(BSTnode *root) {
    if (root == NULL) {
        return 1;
    }
    else if (isSubBSTLesser(root->data, root->left) && isSubBSTGreater(root->data, root->right) && isBST(root->left) && isBST(root->right)) {
        return 1;
    }
    else {
        return 0;
    }
}


int isBSTnotEfficientMethod(BSTnode* root) {
    
    if (root == NULL) {
        return 1;
    }

    /* max on the left must be < than this */
    if (root->left != NULL && findMaximum(root->left)->data > root->data) {
        return 0;
    }

    /* min of the right must be > than this */
    if (root->right != NULL && findMinimum(root->right)->data < root->data) {
        return 0;
    }

    /* false if left or right side not BST */
    if (!isBSTnotEfficientMethod(root->left) || !isBSTnotEfficientMethod(root->right)) {
        return 0;
    }

    return 1;
}


int isTheSameBST(BSTnode *root1, BSTnode *root2) {
    /**
     * Return true if two trees are structurally identical.
     * */

    /* both empty */
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    /* both not empty */
    else if (root1 != NULL && root2 != NULL) {
        return root1->data == root2->data && isTheSameBST(root1->left, root2->left) && isTheSameBST(root1->right, root2->right);
    }

    /* one empty, other one not */
    else {
        return 0;
    }
}

/* < / tree validity > */


void doubleBST(BSTnode *root) {
    /**
     * For each node create a new duplicate node and
     * insert it as the left child of the original node.
     * */
    BSTnode *old_root;

    if (root == NULL) {
        return;
    }

    doubleBST(root->left);
    doubleBST(root->right);

    old_root = root->left;
    root->left = createBSTnode(root->data);
    root->left->left = old_root;
}


BSTnode *deleteBSTnode(unsigned int data, BSTnode *root) {
    /* Return pointer to tree root */
    BSTnode *temp;

    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = deleteBSTnode(data, root->left);
    }
    else if (data > root->data) {
        root->right = deleteBSTnode(data, root->right);
    }
    else {
        /* leaf (no children) */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }

        /* one child */
        else if (root->left == NULL) {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            temp = root;
            root = root->left;
            free(temp);
        }

        /* two children */
        else {
            temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteBSTnode(temp->data, root->right);
        }

    }

    return root;
}


void deleteBST(BSTnode *root) {

    if (root == NULL) {
        return;
    }

    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}



