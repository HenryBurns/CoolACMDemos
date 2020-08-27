#include <limits>
#include <iostream>

int main() {
	std::cout << std::numeric_limits<int64_t>::min() << std::endl;
	// This prints -9223372036854775808

	auto min = -9223372036854775808;
	int64_t min2 = -9223372036854775808;

	// Only 1 of these print statements will compile. Which one?
	// std::cout << -9223372036854775808 << std::endl;
	// std::cout << min << std::endl;
	// std::cout << min2 << std::endl;

	// The next line gets us a compiler error telling us the type of all 3 values.
	// decltype(min)::foo = 0xFULL;
	// decltype(min2)::foo = 0xFULL;
	// decltype(-9223372036854775808)::foo = 0xFULL;
}
