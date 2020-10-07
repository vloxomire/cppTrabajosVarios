#include <iostream>
#include <cstdlib>
#include <ctime>

int
main()
{
	short numeroMinimo
	{
	0 };
	short numeroMaximo
	{
	0 };
	short intentos
	{
	0 };
	short ronda{ 0 };
	int respuesta{ 0 };
	int random
	{
	0 };
	int numeroRandom(0);
	srand(time(0));
	bool gano
	{
	false };
	std::cout << "Muy bien humano, vamos a jugar!!!\n";
	std::cout <<
		"Tu adiviniras el numero que estoy pensando, pero para hacerlo mas entretenido me diras el rango y la cantidad de intentos.\n";
	std::cout << "Empecemos...\n";
	std::cout << "Ok ojalata piensa un numero entre ";
	std::cin >> numeroMinimo;
	std::cout << "y ";
	std::cin >> numeroMaximo;
	std::cout << '\n';
	std::cout << "Ademas lo haremo en ";
	std::cin >> intentos;
	std::cout << '\n';
	std::cout << "Que comienze la accion\n";
	random = rand();
	numeroRandom=(random % numeroMaximo) + numeroMinimo;
	std::cout << "Random: " <<numeroRandom<<'\n';

	while (intentos > ronda)
	{
		++ronda;
		std::cout << "Intento:" << ronda << '\n';
		std::cout << "Muy bien el numero es: ";
		std::cin >> respuesta;
		if (numeroRandom == respuesta)
		{
			gano = true;
			std::cout << "\nMuy bien el numero es: " << numeroRandom << '\n';
			gano = true;
			ronda = intentos;
		}
		else 
		{
			std::cout << "Sigue asi, tal vez si te doy una pista\n";
			if (respuesta<numeroRandom)
			{
				std::cout<<"el numero es mayor\n";
			}
			else
			{
				std::cout << "el numero es menor\n";
			}
		}
	}
	if (gano)
	{
		std::cout << "Has tenido suerte esta vez, no lo vuelvas a intentar porque seguro perderas!\n";
	}
	else 
	{
		std::cout << "has perdido\n";
	}
	return 0;
}