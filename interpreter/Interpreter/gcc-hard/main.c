//
//  main.c
//  gcc-hard
//
//  Created by Zhirui Dai on 2018/7/8.
//  Copyright © 2018 Zhirui Dai. All rights reserved.
//

#include <stdio.h>

int ackermann(int m, int n)
{
    if (m == 0)
    return n + 1;
    
    if (n == 0)
    return ackermann(m - 1, 1);
    
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    for (int m = 0; m <= 3; m = m + 1)
    {
        for (int n = 0; n < 6 - m; n = n + 1)
        {
            printf("---\n");
            printf("%d\n",m);
            printf("%d\n",n);
            printf("%d\n",ackermann(m, n));
        }
    }
}
