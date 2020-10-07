#include <iostream>
#include <string>
struct EstAhorcado
{
	char palabraABuscar[5]{ 'e','m','i','l','y' };
	char arrayRespuesta[5]{'_'};
	std::string dibujoAhorcado[6]
	{
	"	╔--╗   ",
	"	|  @   ",
	"	| /|\ ",
	"	| / \  ",
	"	|	   ",
	"		--------"
	};
	std::string letrasElegidas{ " " };
	char letra{ ' ' };
};

void imprimirPantalla(EstAhorcado& estAhorcado);

int main()
{

	EstAhorcado eA;
	imprimirPantalla(eA);
	std::cout << "El tamano de struct eA es " << sizeof(EstAhorcado) << '\n';

	return 0;
};
void imprimirPantalla(EstAhorcado& eA)
{
	bool ganar(false);
	short intentos{ 0 };
	do
	{
		//DIBUJO
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << eA.dibujoAhorcado[i] << '\n';
		}


		std::cout << "Intentos: " << intentos << '\n';
		std::cout << "Letras Elegidas: " << eA.letrasElegidas << '\n';

		std::cout << "La palabra es: ";
		/*for (size_t i = 0; i < 5; i++)
		{
			if (eA.palabraABuscar[i] == eA.letra)
			{
				eA.arrayRespuesta[i] = eA.palabraABuscar[i];
			}
		}*/
		for (size_t k = 0; k < 5; k++)
		{
			std::cout << eA.arrayRespuesta[k];
		}


		std::cout << "\nIngrese una letra: ";
		std::cin >> eA.letra;

		eA.letrasElegidas += eA.letra;

		intentos++;
		system("cls");
	} while (!ganar);


}