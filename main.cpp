#include <iostream>
#include <string>

#include <stdio.h>
#include <string.h>
#include "log/block_queue.h"
using namespace std;
int main() {
    block_queue<int> a(10);
    std::string abc = "abc";
    std::cout << a.size();
    a.clear();

    return 0;
}
