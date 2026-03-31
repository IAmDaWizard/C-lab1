#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/dijkstra.h"

void test_dijkstra() {
    char s1[] = "a+a";
    char *r1 = dijkstra(s1, strlen(s1) + 1);
    assert(strcmp(r1, "a a +") == 0);
    free(r1);

    char s2[] = "a+b*c";
    char *r2 = dijkstra(s2, strlen(s2) + 1);
    assert(strcmp(r2, "a b c * +") == 0);
    free(r2);

    char s3[] = "(a+b)*c";
    char *r3 = dijkstra(s3, strlen(s3) + 1);
    assert(strcmp(r3, "a b + c *") == 0);
    free(r3);

    char s4[] = "x^2+1";
    char *r4 = dijkstra(s4, strlen(s4) + 1);
    assert(strcmp(r4, "x 2 ^ 1 +") == 0);
    free(r4);

    char s5[] = "3-1*x^2+2*x^2";
    char *r5 = dijkstra(s5, strlen(s5) + 1);
    assert(strcmp(r5, "3 1 x 2 ^ * - 2 x 2 ^ * +") == 0);
    free(r5);
}
