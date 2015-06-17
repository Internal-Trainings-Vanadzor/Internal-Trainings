#include <iostream>

int rec_function(int number) {
	static int tmp = 0;
	if (number == 0) {
		return tmp;
	}
	tmp = tmp * 10 + number % 10;
	return rec_function(number / 10);

}
int main() {
	int var;
	std::cin >> var;
	std::cout << rec_function(var) << std::endl;
	int c = 0;
	std::cin >> c;
	return 0;
}