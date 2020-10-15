#include<iostream>
#include<cstdlib>
#include<ctime>
//#include<conio2.h>
class SopaDeLetras
{
private:
	const static short indX{ 15 };
	const static short indY{ 20 };
	char matrizSopa[indX][indY];
	short matrizNumerosGuia[indX][indY];
	std::string palabrasBuscadas[6];
	bool salir;
	void Init();
	void VerSopa();
	void VerNumeros();
	void CrearSopa();
	void CrearNumeros();
	void Menu();

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

SopaDeLetras::~SopaDeLetras() {};

void SopaDeLetras::Init()
{
	salir = false;
	palabrasBuscadas[6]={"CASA","VIDEOJUEGO","PROGRAMACION","DESARROLLO","FACULTAD","LENGUAJE"};
};

void SopaDeLetras::Juego()
{
	do
	{
		Menu();
		std::cin.get();
		system("cls");
	} while (!salir);
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

