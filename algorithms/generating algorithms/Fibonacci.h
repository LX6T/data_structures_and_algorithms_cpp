//
// Created by alex on 24/08/2022.
//

#pragma once

class Fibonacci {
public:

    static int slowFib(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return slowFib(n-1) + slowFib(n-2);
    }

    static int fastFib(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int a = 0;
        int b = 1;
        int c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

};
