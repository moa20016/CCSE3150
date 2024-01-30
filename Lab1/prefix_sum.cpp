#include <iostream>
#include "prefix_sum.h"
//build a function non_neg_prefix_sum for checking to see if the prefix sums of an int
//array of +1 and -1 never go below zero

int prefix_sum(int ary[], int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += ary[i];
    }
    return sum;
}

bool non_neg_prefix_sum(int ary[], int length){
    bool no_negative_found = true;
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += ary[i];
        if (sum < 0){
            no_negative_found= false;
            break; 
        }
    }
    return no_negative_found;
}

bool non_pos_prefix_sum(int ary[], int length){
    bool no_positive_found = true;
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += ary[i];
        if (sum > 0){
            no_positive_found = false;
            break;
        }
    }
    return no_positive_found;  
}