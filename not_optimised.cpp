#include <iostream>
#include <sys/time.h>
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

    float a_array[100000] = {-1};
    float b_array[100000] = {-1};
    float c_array[100000] = {-1};
    a = a_array;
    b = b_array;
    c = c_array;

    std::cout <<  "Hello..." << std::endl;
    std::cout << "default precision is " << std::cout.precision() << std::endl;

    timestamp_t t0 = get_timestamp();
    // init a and b to 1000001 elements
    for(int i=0;i<100001;i++)
        c[i] = a[i]*b[i];

    timestamp_t t1 = get_timestamp();

    double secs = (t1 - t0) / 1000000.0L;
    std::cout <<  "In ms " << secs * 1000 << std::endl;


    return 0;
}