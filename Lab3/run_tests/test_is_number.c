#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/add.h"

void test_is_number_token() {
    assert(is_number_token("123") == 1);
    assert(is_number_token("-45") == 1);
    assert(is_number_token("0") == 1);
    assert(is_number_token("a") == 0);
    assert(is_number_token("12a") == 0);
    assert(is_number_token("") == 0);
}

