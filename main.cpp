// "Chekhov's gun" as published at https://youtu.be/HHgyH3WNTok?t=888

#include <iostream>

int evil() {
	std::cout << "All your bit are belongs to us\n";
	return 0;
}

static int (*fire)();

void load_gun() {
	fire = evil;
}

int main() {
	fire();
}
