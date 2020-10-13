#include <iostream>
#include <string>
#include <time.h>
//#include <conio2.h>
class Ahorcado
{
private:
	struct EstructAhorcado
	{
		std::string palabraABuscar;
		char arrayRespuesta[5];
		std::string letrasInsertadas;
		char letra;
	};
	EstructAhorcado strAho;
	__time32_t tiempoCrudo;
	struct tm nuevoTiempo;
	char buffer[32];
	errno_t errNum;

public:
	Ahorcado(std::string);
	~Ahorcado();
	void imprimirPantalla();
	void chequeadorLetras(EstructAhorcado &eA);
};

int main()
{
	Ahorcado ahorcado("droga");
	ahorcado.imprimirPantalla();
	return 0;
};

Ahorcado::Ahorcado(std::string buscar)
{
	std::cout << "Construyendo....... \\ \n";
	//Esto es tiempo ch....
	_time32(&tiempoCrudo);//Dame tiempo en seg
	_localtime32_s(&nuevoTiempo, &tiempoCrudo);//Convierta el tiempo en forma estructura tm.
	errNum = asctime_s(buffer, 32, &nuevoTiempo);
	if (errNum)
	{
		std::cout << "Error codigo: "<<(int)errNum<<'\n';
	}
	std::cout << "Tiempo: "<<buffer<<'\n';

	strAho.palabraABuscar=buscar;
	strAho.arrayRespuesta[5]={' '};
}

Ahorcado::~Ahorcado()
{
	std::cout << "Destruyendo......... \\ \n";
	//Tiempo
	_time32(&tiempoCrudo);//Dame tiempo en seg
	_localtime32_s(&nuevoTiempo, &tiempoCrudo);//Convierta el tiempo en forma estructura tm.
	errNum = asctime_s(buffer, 32, &nuevoTiempo);
	if (errNum)
	{
		std::cout << "Error codigo: " << (int)errNum << '\n';
	}
	std::cout << "Tiempo: " << buffer << '\n';
}
void Ahorcado::imprimirPantalla()
{
	
	std::cout << "El tamano de struct eA es " << sizeof(EstructAhorcado) << '\n';
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
		std::cout << "Letras Elegidas: " << strAho.letrasInsertadas <<" caracteres: "
			<< strAho.letrasInsertadas.length() <<'\n';

		std::cout << "La palabra es: ";

		for (size_t k = 0; k < 5; k++)
		{
			std::cout << strAho.arrayRespuesta[k];
			std::cout << ' ';
		}
		
		std::cout << "\nIngrese una letra: ";
		std::cin >> strAho.letra;
		//buscar si ya esta en las letras elegidas
		//preguntar por mejora?
		chequeadorLetras(strAho);
			
		//COMPARA CON EL ARRAY
		for (size_t i = 0; i < strAho.palabraABuscar.length(); i++)
		{
			if (strAho.palabraABuscar[i] == strAho.letra )
			{
				strAho.arrayRespuesta[i] = strAho.palabraABuscar[i];
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
				std::cout << strAho.palabraABuscar[i];
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
				std::cout << strAho.palabraABuscar[i];
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
void Ahorcado::chequeadorLetras(EstructAhorcado &strAho)
{
	for (size_t i = 0; i < strAho.letrasInsertadas.length(); i++)
	{
		if (strAho.letrasInsertadas[i] == strAho.letra)
		{
			do
			{
				std::cout << "Ya lo eligio, elija un nuevo caracter...\n";
				std::cin >> strAho.letra;
			} while (strAho.letra == strAho.letrasInsertadas[i]);
		}
	}
	strAho.letrasInsertadas += strAho.letra;
};
