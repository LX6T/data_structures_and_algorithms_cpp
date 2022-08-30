//
// Created by alex on 24/08/2022.
//

#pragma once

class fastFib {
public:

    static int run(int n)
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
