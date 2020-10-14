#include<iostream>
#include<cstdlib>
#include<ctime>
class SopaDeLetras
{
private:
	const static short indice{ 10 };
	char matrizSopa[indice][indice];
	short matrizNumerosGuia[indice][indice];
	
public:
	SopaDeLetras();
	~SopaDeLetras();
	void Init();
	void VerSopa();
	void VerNumeros();
	void CrearMatrizSopa();
	void CrearNumeros();

};
int main()
{
	SopaDeLetras sp;
	sp.VerSopa();
	return 0;
};

SopaDeLetras::SopaDeLetras()
{
	std::cout << "Construyendo\n";
	srand(time(0));
	Init();
	CrearNumeros();
};

SopaDeLetras::~SopaDeLetras() {};

void SopaDeLetras::Init()
{
	
};

void SopaDeLetras::VerSopa()
{
	std::cout << "		SOPA DE LETRAS\n";
	
	
	VerNumeros();
	std::cout << "F2:Guardar	||F3:Cargar		||	F10 or Esc:	Salir\n";
	std::cout << "Presiones las flechas para mover el cursor.\n";
	std::cout << "Presiones 'Espacio' para seleccionar una letra.\n";
};

void SopaDeLetras::CrearNumeros()
{
	
	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			matrizNumerosGuia[f][c] = 65+ rand()% (90 - 65)+1;
		}
	}
};

void SopaDeLetras::VerNumeros()
{
	for (size_t f = 0; f < indice; f++)
	{
		for (size_t c = 0; c < indice; c++)
		{
			std::cout<<matrizNumerosGuia[f][c]<<' ';
		}
		std::cout <<'\n';
	}
};