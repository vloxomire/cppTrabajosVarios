#include <iostream>
#include <string>
//#include <conio2.h>
class Ahorcado
{
private:
public:
	Ahorcado();
	~Ahorcado();
};
struct EstAhorcado
{
	char palabraABuscar[5]{ 'd', 'r', 'o', 'g', 'a' };
	char arrayRespuesta[5]{ '_', '_', '_', '_', '_' };
	std::string letrasElegidas{ " " };
	char letra{ ' ' };
};

void imprimirPantalla(EstAhorcado& estAhorcado);

int main()
{
	Ahorcado ahorcado();

	EstAhorcado eA;
	imprimirPantalla(eA);
	std::cout << "El tamano de struct eA es " << sizeof(EstAhorcado) << '\n';

	return 0;
};
void imprimirPantalla(EstAhorcado& eA)
{
	std::string dibujoAhorcado[6]{
		"\n	|	 @ ",
		"	|    | ",
		"	|   /| ",
		"	|   /|\\",
		"	|    /  ",
		"	|     \\" };
	std::string dibujoHorca[6]{
		" ╔--╗",
		" |",
		" |",
		" |",
		" |",
		"--------" };
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
			if (intentos > i)
			{
				switch (intentos)
				{
				case 1:
					dibujoHorca[1] = " |   @";
					break;
				case 2:
					dibujoHorca[2] = " |   |";
					break;
				case 3:
					dibujoHorca[2] = " |  /|";
					break;
				case 4:
					dibujoHorca[2] = " |  /|]";
					break;
				case 5:
					dibujoHorca[3] = " |   /";
					break;
				case 6:
					dibujoHorca[3] = " |   /]";
					break;
				default:
					break;
				}
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
				std::cout << eA.palabraABuscar[i];
			}
			std::cin.get();
			std::cin.get();
		}
		else if (intentos > 6)
		{
			std::cout << "Has perdido la partida\n";
			std::cout << "La palabra era: \n";
			gano = true;
			for (size_t i = 0; i < 5; i++)
			{
				std::cout << eA.palabraABuscar[i];
			}
			std::cin.get();
			std::cin.get();
		}
		/*gotoxy(4, 3);
		std::cout << char(201) << char(205) << char(205) << char(205) << char(187) << std::endl;
		gotoxy(4, 4);
		std::cout << char(186) << std::endl;
		gotoxy(4, 5);
		std::cout << char(186) << std::endl;
		gotoxy(4, 6);
		std::cout << char(186) << std::endl;
		gotoxy(4, 7);
		std::cout << char(186) << std::endl;
		gotoxy(2, 8);*/

		system("cls");
	} while (!gano);
}
Ahorcado::Ahorcado()
{
	std::cout << "Construyendo \\ \n";
}