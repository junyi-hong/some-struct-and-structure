#ifndef SWAP_H
#define SWAP_H
void swapint(int *a, int *b) {
    /* goes in circle - easy to remember */
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
#endif