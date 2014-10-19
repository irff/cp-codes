/*
 * Copyright (c) Jonee Ryan Ty <vampire_janus@yahoo.com> BSD Type license
 *
 * This is free software. Permission to use, modify and redistribute 
 * are granted provided that this copyright 
 * is retained. If you modify this source make it known that you did modify
 * it by adding an entry in the revision history so that modified versions
 * would not be mistaken with the original (ie so that if you introduce (more) 
 * bugs it should not be blamed on me). Though not required, I would 
 * appreciate it if you send me back your modifications through email.
 *
 * This program comes with no warranty whatsoever. Use it at your own risk.
 * The author would not in anyway be held responsible from any damage resulting
 * from the use of this software.
 *
 */

/* 
 * Revision history
 * <date>               <changed by>        <summary of changes>
 * 01 September 2004    Jonee Ryan Ty       First documented history
 *
 */

#include <stdio.h>
#include <stdlib.h>     // calloc

#define ARRANGE 5
#define TRUE 1
#define FALSE 0

void    permut(int), process(), nextPermut();

int fctrl(int), find(int),
    len, myK,
    *availableNums, // placeholder for available numbers, availableNums[x] is -1 
            // when x is already used in the permutation (see function permut)
    *perm,  // the current permutation, in 0123...
    a, b, c, d, curCount, indx, tmp,
    count = 0,
    i, j, foundIndx;

int main(int argc, char **argv) {

    printf("This program demonstrates two algorithms: the kth permutation and the next permutation.\n");
    printf("Enter the length (2 - 9): ");
    scanf("%d", &len);

    if ((len > 9) || (len < 2)) {
        fprintf(stderr, "length should be between 2 to 9\n");
        exit(1);
    }

    int load = fctrl(len);

    printf("Enter the value of k (1 - %d): ", load);
    scanf("%d", &myK);

    if ((myK < 1) || (myK > load)) {
        fprintf(stderr, "k should be between 1 to %d\n", load);
        exit(1);
    }

    availableNums = (int *)calloc(len, sizeof(int));
    perm = (int *)calloc(len, sizeof(int));

    for (a = 0; a < len; a++)
        availableNums[a] = a + 1;

    printf("The %dth permutation is: ", myK);
    permut(myK - 1);
    process();
    printf("\n");

    printf("The next permutation is: ");

    if (myK == load)   // some cheat
		printf("na");	
    
    else {
        nextPermut();
	process();
    }

    printf("\n");

    free(availableNums);
    free(perm);
    scanf("\n");
    return 0;
}

/**
 * finds the (k + 1)th perm and writes it in tmp
 */
void permut(int k) {
    for(a = 0; a < len; a++) {
        tmp = fctrl(len - 1 - a);
        indx = find(k / tmp);
        perm[a] = availableNums[indx];
        availableNums[indx] = -1;
        k %= tmp;
    }
}

/**
 * finds the ith available number in availableNums
 */
int find(int i) {

    curCount = -1;

    for(b = 0; b < len; b++)
        if(availableNums[b] != -1) {
            curCount++;

            if(curCount == i) {
                indx = b;
                b = len; //to terminate
            }
        }

    return indx;
}

/**
 * returns n!
 */
int fctrl(int n) {

    curCount = 1;

    for(c = n; c > 1; c--)
        curCount *= c;

    return curCount;
}

/**
 * prints the current perm
 */
void process() {

    for(d = 0; d < len; d++)
        printf("%d", perm[d]);

    printf(" ");
    count++;

    if(count == ARRANGE) {
        count = 0;
        printf("\n");
    }
}

/**
 * finds the next permutation of the current perm
 * known limitation: cannot get the next permutation of the last permutation
 */
void nextPermut() {

    foundIndx = FALSE;
    i = len - 2;

    do {
        if(perm[i] < perm[i + 1])
            foundIndx = TRUE;
        else
            i--;

    } while(!foundIndx);

    foundIndx = FALSE;
    j = len - 1;

    do {
        if(perm[j] > perm[i])
            foundIndx = TRUE;

        else
            j--;
    } while(!foundIndx);

    tmp = perm[j];          //swap
    perm[j] = perm[i];
    perm[i] = tmp;

    i++;
    j = len - 1;

    while(i < j) {
        tmp = perm[j];      //swap
        perm[j] = perm[i];
        perm[i] = tmp;

        i++;            //move pointers
        j--;
    }
}
