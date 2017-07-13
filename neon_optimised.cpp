//
// Created by Harsha K N on 13/07/17.
//
#include <iostream>
#include <sys/time.h>
#include "arm_neon.h"
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}


int main() {

    float* a, *b, *c;
    float32x4_t a_, b_, c_;

    float a_array[100000] = {-1};
    float b_array[100000] = {-1};
    float c_array[100000] = {-1};
    a = a_array;
    b = b_array;
    c = c_array;

    std::cout <<  "Hello..." << std::endl;
    std::cout << "default precision is " << std::cout.precision() << std::endl;

    timestamp_t t0 = get_timestamp();
    for(int i=0;i<100001;i+=4)
    {
        a_ = vld1q_f32( &a[i] ); // load 4 floats from a in a NEON register
        b_ = vld1q_f32( &b[i] );
        c_ = vmulq_f32(a_, b_); // perform 4 float multiplies in parallel
        vst1q_f32( &c[i], c_); // store the four results in c
    }

    timestamp_t t1 = get_timestamp();

    double secs = (t1 - t0) / 1000000.0L;
    std::cout <<  "In ms " << secs * 1000 << std::endl;


    return 0;
}

