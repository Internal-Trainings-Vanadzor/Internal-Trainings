#include <iostream>

void rec_function(int number) {
	int tmp = 0;
	tmp = number;
	int arch = 0;
	arch = number % 10;
	tmp = (tmp - arch) / 10;
	std::cout << arch;
	if (tmp != 0) {
		rec_function(tmp);
	}

}

int main() {
	int a = 12345;
	rec_function(a);
	return 0;
}