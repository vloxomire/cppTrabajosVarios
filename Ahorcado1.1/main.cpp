#include <iostream>
#include <string>
#include <time.h>
//#include <conio2.h>
class Ahorcado
{
private:

	std::string m_palabraABuscar;
	char m_arrayRespuesta[5]{' '};
	std::string m_letrasInsertadas;
	char m_letra;

	struct StructTiempo
	{
		__time32_t tiempoCrudo;
		struct tm nuevoTiempo;
		char buffer[32];
		errno_t errNum;
	}st;


public:
	Ahorcado(std::string);
	~Ahorcado();
	void imprimirPantalla();
	void chequeadorLetras();
	std::string GetPalabraBuscar();
	char GetArrayRespuesta();
	char GetLetra();
};

int main()
{
	Ahorcado ahorcado("droga");
	ahorcado.imprimirPantalla();
	return 0;
};

Ahorcado::Ahorcado(std::string buscar) :m_palabraABuscar{ buscar }
{
	std::cout << "Construyendo....... \\ \n";
	//Esto es tiempo ch....
	_time32(&st.tiempoCrudo);//Dame tiempo en seg
	_localtime32_s(&st.nuevoTiempo, &st.tiempoCrudo);//Convierta el tiempo en forma estructura tm.
	st.errNum = asctime_s(st.buffer, 32, &st.nuevoTiempo);
	if (st.errNum)
	{
		std::cout << "Error codigo: " << (int)st.errNum << '\n';
	}
	std::cout << "Tiempo: " << st.buffer << '\n';
}

Ahorcado::~Ahorcado()
{
	std::cout << "Destruyendo......... \\ \n";
	//Tiempo
	_time32(&st.tiempoCrudo);//Dame tiempo en seg
	_localtime32_s(&st.nuevoTiempo, &st.tiempoCrudo);//Convierta el tiempo en forma estructura tm.
	st.errNum = asctime_s(st.buffer, 32, &st.nuevoTiempo);
	if (st.errNum)
	{
		std::cout << "Error codigo: " << (int)st.errNum << '\n';
	}
	std::cout << "Tiempo: " << st.buffer << '\n';
}
void Ahorcado::imprimirPantalla()
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
		std::cout << "Letras Elegidas: " << m_letrasInsertadas << " caracteres: "
			<< m_letrasInsertadas.length() << '\n';

		std::cout << "La palabra es: ";

		for (size_t k = 0; k < 5; k++)
		{
			std::cout << m_arrayRespuesta[k];
			std::cout << ' ';
		}

		std::cout << "\nIngrese una letra: ";
		std::cin >> m_letra;
		//buscar si ya esta en las letras elegidas
		//preguntar por mejora?
		chequeadorLetras();

		//COMPARA CON EL ARRAY
		for (size_t i = 0; i < m_palabraABuscar.length(); i++)
		{
			if (m_palabraABuscar[i] == m_letra)
			{
				m_arrayRespuesta[i] = m_palabraABuscar[i];
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
				std::cout << m_palabraABuscar[i];
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
				std::cout << m_palabraABuscar[i];
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
void Ahorcado::chequeadorLetras()
{
	for (size_t i = 0; i < m_letrasInsertadas.length(); i++)
	{
		if (m_letrasInsertadas[i] == m_letra)
		{
			do
			{
				std::cout << "Ya lo eligio, elija un nuevo caracter...\n";
				std::cin >> m_letra;
			} while (m_letra == m_letrasInsertadas[i]);
		}
	}
	m_letrasInsertadas += m_letra;
};

std::string Ahorcado::GetPalabraBuscar()
{
	return m_palabraABuscar;
};
char Ahorcado::GetArrayRespuesta() 
{
	return m_arrayRespuesta[4];
};
char Ahorcado::GetLetra() 
{
	return m_letra;
};
