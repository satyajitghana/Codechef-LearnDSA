// '12345'
// '54321'

#include <algorithm>
#include <iostream>

int main() {
    // std::string number{"12345"};
    // std::reverse(std::begin(number), std::end(number));
    // std::cout << number << '\n';

    int T;
    std::cin >> T;

    while (T--) {
        std::string num;
        std::cin >> num;

        std::reverse(num.begin(), num.end());

        std::cout << std::stoi(num) << '\n';
    }

    return 0;
}
