#include<iostream>
#include<cstdlib>
#include<ctime>
class SopaDeLetras
{
private:
	const static short indice{ 10 };
	char matrizSopa[indice][indice];
	short matrizNumerosGuia[indice][indice];
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
};

void SopaDeLetras::Juego()
{

	Menu();


};

void SopaDeLetras::Menu()
{
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

	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			matrizNumerosGuia[f][c] = 65 + rand() % (90 - 65) + 1;
		}
	}
};

void SopaDeLetras::CrearSopa()
{
	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			matrizSopa[f][c] = matrizNumerosGuia[f][c];
		}
	}
};

void SopaDeLetras::VerNumeros()
{
	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			std::cout << matrizNumerosGuia[f][c] << ' ';
		}
		std::cout << '\n';
	}
};

void SopaDeLetras::VerSopa()
{
	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			std::cout << matrizSopa[f][c] << ' ';
		}
		std::cout << '\n';
	}
};

