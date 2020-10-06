#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	short numMin{ 0 };
	short numMax{ 0 };
	short intentos{0};
	int numeroRandom{0};
	
	numeroRandom = rand();
	std::cout << numeroRandom;

	srand(time(0));
	
	return 0;
};