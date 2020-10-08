#include <iostream>
#include <string>
struct EstAhorcado
{
	char palabraABuscar[5]{ 'e','m','i','l','y' };
	char arrayRespuesta[5]{ '_','_','_','_','_' };
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
	std::string dibujoAhorcado[6]
	{
	"\n	|	 @ ",
	"	|    | ",
	"	|   /| ",
	"	|   /|\\",
	"	|    /  ",
	"	|     \\"
	};
	std::string dibujoHorca[6]
	{
	"	╔--╗",
	"	|",
	"	|",
	"	|",
	"	|",
	"	--------"
	};
	bool gano(false);
	bool letraValida(false);
	short intentos{ 0 };
	short victoryPoint(0);
	do
	{

		//DIBUJO
		/*for (size_t i = 0; i < 6; i++)
		{
			if (intentos < i)
			{
				std::cout << dibujoHorca[i] << '\n';
			}
			else
			{
				std::cout << dibujoAhorcado[i] << '\n';
			}
		}*/
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << dibujoHorca[i];
			if (intentos<i)
			{
				dibujoHorca[i]= dibujoAhorcado[i];
			}
			
			std::cout << '\n';
		}


		std::cout << "Intentos: " << intentos << '\n';
		std::cout << "Letras Elegidas: " << eA.letrasElegidas << '\n';

		std::cout << "La palabra es: ";


		for (size_t k = 0; k < 5; k++)
		{
			std::cout << eA.arrayRespuesta[k];
			std::cout << ' ';
		}
		
		std::cout << "\nIngrese una letra: ";
		std::cin >> eA.letra;


		eA.letrasElegidas += eA.letra;

		for (size_t i = 0; i < 5; i++)
		{
			if (eA.palabraABuscar[i] == eA.letra)
			{
				eA.arrayRespuesta[i] = eA.palabraABuscar[i];
				letraValida = true;
				victoryPoint++;
			}
		}
		if (!letraValida)
		{
			intentos++;
		}
		else
		{
			letraValida = false;
		}
		//VIICTORIA
		if (victoryPoint == 5)
		{
			gano = true;
			std::cout << "Has ganado la partida\n";
			std::cout << "La palabra era: \n";
			for (size_t i = 0; i < 5; i++)
			{
				std::cout<<eA.palabraABuscar[i];
			}
			std::cin.get();
			std::cin.get();
		}

		system("cls");
	} while (!gano);


}