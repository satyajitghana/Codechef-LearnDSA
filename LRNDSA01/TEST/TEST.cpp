#include <iostream>

int main() {
    while (true) {
        int x;
        std::cin >> x;

        if (x == 42)
            break;

        std::cout << x << '\n';
    }

    return 0;
}