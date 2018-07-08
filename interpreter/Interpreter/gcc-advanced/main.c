//
//  main.c
//  gcc-advanced
//
//  Created by Zhirui Dai on 2018/7/8.
//  Copyright © 2018 Zhirui Dai. All rights reserved.
//

#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
    return n;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    for (int n = 1; n < 30; n = n + 1)
    printf("%d\n", fibonacci(n));
}
