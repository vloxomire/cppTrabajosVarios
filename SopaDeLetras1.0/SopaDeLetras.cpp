#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<string>
#include<vector>
#include<array>
#include<fstream>
//#include<conio2.h>
/*
1-array para tablero marcador
*/
class SopaDeLetras
{
private:
	const static short indX{ 15 };
	const static short indY{ 20 };
	char matrizSopa[indX][indY];
	short matrizNumerosGuia[indX][indY];
	std::string tablero[6][3];
	std::array<std::string,6>palabrasBuscadas;
	std::chrono::system_clock::time_point start;
	std::string user;
	bool salir;
	void Init();
	void VerSopa();
	void VerNumeros();
	void VerTablero();
	void AsignarValoresTablero(std::string&, float&);
	void CrearSopa();
	void CrearNumeros();
	void CrearTablero();
	void CrearArchivoTexto();
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
	//Tiempo
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	float sec = (float)duration.count() / 1000;
	std::cout << sec << " seg//" << duration.count() << " miliseg\n";
	AsignarValoresTablero(user, sec);
	VerTablero();
	CrearArchivoTexto();
};

void SopaDeLetras::Init()
{
	StrTiempo t;
	start = std::chrono::system_clock::now();
	salir = false;
	user = "Max";
	short cont(0);
	palabrasBuscadas = {"CASA","VIDEOJUEGO","PROGRAMACION","DESARROLLO", "FAULTAD", "LENGUAJE"};
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
	short contador(0);
	std::ifstream leer("Score.dat");//leer el archivo

	for (size_t f = 0; f < 6; f++)
	{
		for (size_t c = 0; c < 3; c++)
		{
			//Posicion
			if (c == 0)
			{
				if (f==0)
				{
					tablero[f][c] = "Posicion";
				}
				else 
				{
					tablero[f][c] = std::to_string(++contador)+"	";
				}
			}
			//Nombre
			if (c==1)
			{

				if (!leer)
				{
					std::cerr << "Score.dat no existe!!!\n";
				}
				if (f == 0)
				{
					tablero[f][c] = "Usuario";
				}
				else 
				{
					tablero[f][c] = user+"	";
				}
			}
			if(c==2)
			{
				if (f == 0)
				{
					tablero[f][c] = "Tiempo Transcurrido";
				}
				else 
				{
					tablero[f][c] = "sec		";
				}
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
			std::cout << "			"<<palabrasBuscadas[0]<<" ["<<palabrasBuscadas[0].size() << "] ";
			break;
		case 3:
			std::cout << "			" << palabrasBuscadas[1] << " [" << palabrasBuscadas[1].size() << "] ";
			break;
		case 4:
			std::cout << "			" << palabrasBuscadas[2] << " [" << palabrasBuscadas[2].size() << "] ";
			break;
		case 5:
			std::cout << "			" << palabrasBuscadas[3] << " [" << palabrasBuscadas[3].size() << "] ";
			break;
		case 6:
			std::cout << "			" << palabrasBuscadas[4] << " [" << palabrasBuscadas[4].size() << "] ";
			break;
		case 7:
			std::cout << "			" << palabrasBuscadas[5] << " [" << palabrasBuscadas[5].size() << "] ";
			break;
		default:
			break;
		}

		std::cout << '\n';
	}
};

void SopaDeLetras::VerTablero()
{
	for (size_t f = 0; f < 6; f++)
	{
		for (size_t c = 0; c < 3; c++)
		{
			std::cout << tablero[f][c] << "	| ";
		}
		std::cout <<  "\n---------------------------------------------------------\n";
	}
};
void SopaDeLetras::AsignarValoresTablero(std::string& user, float& sec)
{
	for (size_t f = 0; f < 6; f++)
	{
		for (size_t c = 0; c < 3; c++)
		{
			if (c == 2)
			{
				if (f!=0)
				{
					tablero[f][c] = FloatToString(sec)+"	";
				}
			}
		}
	}
};

std::string SopaDeLetras::FloatToString(float& sec)
{
	//Convierte float a string  es una funcion de la libreria string
	std::string aux = std::to_string(sec);
	return aux;
};

void SopaDeLetras::CrearArchivoTexto() 
{
	//Manipulacion de Archivos
	std::ofstream salida{ "Score.dat" };//Escribe el archivo
	//Dibuja en la hoja
	for (size_t f = 0; f < 6; f++)
	{
		for (size_t c = 0; c < 3; c++)
		{
			salida << tablero[f][c] << " || ";
		}
		salida << "\n-------------------\n";
	}
};
