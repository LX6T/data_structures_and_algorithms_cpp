//
// Created by alex on 24/08/2022.
//

#pragma once

class slowFib {
public:
    static int run(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return run(n-1) + run(n-2);
    }

    static std::string getName() {
        return "slowFib";
    }
};
