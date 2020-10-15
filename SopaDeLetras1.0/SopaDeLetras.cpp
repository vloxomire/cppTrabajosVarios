#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<string>
#include<vector>
//#include<conio2.h>
/*
1-array para tablero marcador
2-array palabras buscadas
*/
class SopaDeLetras
{
private:
	enum EnumPalabras { CASA, VIDEOJUEGO, PROGRAMACION, DESARROLLO, FACULTAD, LENGUAJE };
	const static short indX{ 15 };
	const static short indY{ 20 };
	char matrizSopa[indX][indY];
	short matrizNumerosGuia[indX][indY];
	std::string tablero[5][2];
	std::vector<EnumPalabras> palabrasBuscadas[6];
	std::chrono::system_clock::time_point start;
	std::string user;
	bool salir;
	void Init();
	void VerSopa();
	void VerNumeros();
	void VerTablero(std::string&, float&);
	void CrearSopa();
	void CrearNumeros();
	void CrearTablero();
	void Menu();
	std::string FloatToString(float&);

	struct StrTiempo
	{
		std::chrono::system_clock::time_point m_inicioTiempo;
		StrTiempo()
		{
			m_inicioTiempo = std::chrono::system_clock::now();
		}
		~StrTiempo()
		{
			auto finTiempo = std::chrono::system_clock::now();
			std::chrono::duration<float, std::milli> duracion = finTiempo - m_inicioTiempo;
			std::cout << duracion.count() << "miliseg\n";
		}
	};

public:
	SopaDeLetras();
	~SopaDeLetras();
	void Juego();
};

int main()
{
	SopaDeLetras sp;
	sp.Juego();
	return 0;
};

SopaDeLetras::SopaDeLetras()
{
	std::cout << "Construyendo\n";
	srand(time(0));
	CrearNumeros();
	CrearSopa();
	Init();

};

SopaDeLetras::~SopaDeLetras()
{
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	float sec = (float)duration.count() / 1000;
	std::cout << sec << " seg//" << duration.count() << " miliseg\n";
	VerTablero(user, sec);
};

void SopaDeLetras::Init()
{
	StrTiempo t;
	start = std::chrono::system_clock::now();
	salir = false;
	user = "Max";
	short cont(0);
	for (auto it = std::begin(palabrasBuscadas); it != std::end(palabrasBuscadas); ++it)
		palabrasBuscadas.push_back(cont++);
	
	
	CrearTablero();
};

void SopaDeLetras::Juego()
{
	do
	{
		Menu();
		std::cin.get();
		system("cls");
	} while (salir);
};

void SopaDeLetras::Menu()
{
	//textcolor(GREEN);
	std::cout << "		SOPA DE LETRAS\n";
	std::cout << '\n';
	std::cout << "F2:Guardar	||F3:Cargar		||	F10 or Esc:	Salir\n";
	std::cout << '\n';
	VerSopa();
	std::cout << '\n';
	std::cout << "Presiones las flechas para mover el cursor.\n";
	std::cout << "Presiones 'Espacio' para seleccionar una letra.\n";
};

void SopaDeLetras::CrearNumeros()
{

	for (size_t f = 0; f < indX; f++)
	{
		for (size_t c = 0; c < indY; c++)
		{
			matrizNumerosGuia[f][c] = 65 + rand() % (90 - 65) + 1;
		}
	}
};

void SopaDeLetras::CrearSopa()
{
	for (size_t f = 0; f < indX; f++)
	{
		for (size_t c = 0; c < indY; c++)
		{
			matrizSopa[f][c] = matrizNumerosGuia[f][c];
		}
	}
};

void SopaDeLetras::CrearTablero()
{
	for (size_t f = 0; f < 5; f++)
	{
		for (size_t c = 0; c < 2; c++)
		{
			if (c == 0)
			{
				tablero[f][c] = user;
			}
			else
			{
				tablero[f][c] = "sec";
			}
		}
	}
};

void SopaDeLetras::VerNumeros()
{
	for (size_t f = 0; f < indX; f++)
	{
		for (size_t c = 0; c < indY; c++)
		{
			std::cout << matrizNumerosGuia[f][c] << ' ';
		}
		std::cout << '\n';
	}
};

void SopaDeLetras::VerSopa()
{
	//textcolor(WHITE);
	//COLORS aux;
	for (size_t f = 0; f < indX; f++)
	{
		for (size_t c = 0; c < indY; c++)
		{
			std::cout << matrizSopa[f][c] << ' ';
		}
		switch (f)
		{
		case 0:
			//textcolor(LIGHTMAGENTA);
			//aux = COLORS::LIGHTMAGENTA;
			std::cout << "			PALABRAS";
			//textcolor(WHITE);
			break;
		case 2:
			std::cout << "			CASA";
			break;
		case 3:
			std::cout << "			VIDEOJUEGO";
			break;
		case 4:
			std::cout << "			PRORAMACION";
			break;
		case 5:
			std::cout << "			DESARROLLO";
			break;
		case 6:
			std::cout << "			FACULTAD";
			break;
		case 7:
			std::cout << "			LENGUAJE";
			break;
		default:
			break;
		}

		std::cout << '\n';
	}
};

void SopaDeLetras::VerTablero(std::string& user, float& sec)
{
	for (size_t f = 0; f < 5; f++)
	{
		for (size_t c = 0; c < 2; c++)
		{
			if (c == 1)
			{
				tablero[f][c] = FloatToString(sec);
			}
			std::cout << tablero[f][c] << " | ";
		}
		std::cout << '\n';
	}
};

std::string SopaDeLetras::FloatToString(float& sec)
{
	//Convierte float a string  es una funcion de la libreria string
	std::string aux = std::to_string(sec);
	return aux;
};

