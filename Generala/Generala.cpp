#include<iostream>
#include<cstdlib>
#include<ctime>
int main()
{
	enum TipoDeJuego {NOJUEGO,DOBLE,ESCALERA,FULL,POKER,GENERALA};
	bool gano(false);
	bool boolHayJuego(false);
	const short indice(5);
	//short arrayDados[indice]{0};
	short arrayDados[indice]{ 2,2,3,3,3 };
	short arrayContaNum[6]{ 0 };
	short arrayHayJuego[2]{ 0 };
	TipoDeJuego arrayTipoDeJuego[6]{};
	short arrayContaTipoJuego[5]{ 0 };
	short aux(0);
	srand(time(NULL));
	
	std::cout << "Hacemos una tirada de Generala? [Presiona una tecla]\n";
	std::cin.get();
	std::cout << "********************************************************\n";
	std::cout << '\n';
	do
	{

		std::cout << "Tirando dados....\n";
		//GENERANDO LA TIRADA
		/*for (size_t i = 0; i < 5; i++)
		{
			arrayDados[i] = rand() % 6 + 1;
			std::cout << arrayDados[i] << ',';
		}
		std::cout << '\n';
		std::cout << "********************************************************\n";
		std::cout << '\n';
		std::cout << "Ordenar dados....\n";
		//ORDENAR LOS NUMEROS
		for (size_t i = 0; i < indice-1; i++)
		{
			for (size_t k = 0; k < indice-1; k++)
			{
				if (arrayDados[k]> arrayDados[k+1])
				{
					aux = arrayDados[k];
					arrayDados[k] = arrayDados[k + 1];
					arrayDados[k + 1] = aux;
				}
			}
		}*/
		//MOSTRAR
		for (size_t i = 0; i < indice; i++)
		{
			std::cout << arrayDados[i] << ',';
		}
		std::cout << '\n';
		std::cout << "********************************************************\n";
		std::cout << '\n';
		std::cout << "Valores repetidos:\n";
		//valores repetidos
		for (size_t i = 0; i < indice; i++)
		{
			switch (arrayDados[i])
			{
			case 1:
				arrayContaNum[0]++;
				break;
			case 2:
				arrayContaNum[1]++;
				break;
			case 3:
				arrayContaNum[2]++;
				break;
			case 4:
				arrayContaNum[3]++;
				
				break;
			case 5:
				arrayContaNum[4]++;
				
				break;
			case 6:
				arrayContaNum[5]++;
				
				break;
			default:
				break;
			}
		}
		std::cout << "Valor 1:	" << arrayContaNum[0] << '\n';
		std::cout << "Valor 2:	" << arrayContaNum[1] << '\n';
		std::cout << "Valor 3:	" << arrayContaNum[2] << '\n';
		std::cout << "Valor 4:	" << arrayContaNum[3] << '\n';
		std::cout << "Valor 5:	" << arrayContaNum[4] << '\n';
		std::cout << "Valor 6:	" << arrayContaNum[5] << '\n';

		std::cout << "********************************************************\n";
		//CLASIFICAR TIRADAS
		//LOGICA ESCALERA
		aux = 0;
		for (size_t i = 0; i < 4; i++)
		{
			//ESCALERA CHEQUEO
			if (arrayDados[i]< arrayDados[i+1])
			{
				aux++;
			}
			else 
			{
				aux--;
			}
		}
		if (aux>=4)
		{
			arrayTipoDeJuego[2] = ESCALERA;
		}
		aux = 0;
		//logica Full
		for (size_t i = 0; i < 6; i++)
		{
			if (arrayContaNum[i] ==2)
			{
				aux++;
			}
			else if (arrayContaNum[i] == 3) 
			{
				aux +=2;
			}
			
		}
		if (aux==3)
		{
			arrayTipoDeJuego[2] = FULL;

		}


		//RECORRO EL ARRAY TIPO DE JUEGO
		//si no hay
		aux = 0;
		for (size_t i = 0; i < 6; i++)
		{
			if (arrayTipoDeJuego[i] != NOJUEGO)
			{
				arrayHayJuego[1] +=1;
				boolHayJuego = true;
				switch (arrayTipoDeJuego[i]) 
				{
				case DOBLE:
					arrayContaTipoJuego[0] += 1;
					break;
				case ESCALERA:
					arrayContaTipoJuego[1] += 1;
					break;
				case FULL:
					arrayContaTipoJuego[2] += 1;
					break;
				case POKER:
					arrayContaTipoJuego[3] += 1;
					break;
				case GENERALA:
					arrayContaTipoJuego[4] += 1;
					break;
				default:
					break;
				}
			}
		}
		std::cout << "Juegos de la tirada ([" << arrayHayJuego[0] 
			<< "] No hay juego | ["<<arrayHayJuego[1]<<"] hay un juego):\n";
		std::cout << '\n';
		std::cout << "Doble: " << arrayContaTipoJuego[0] << '\n';
		std::cout << "Escalera: " << arrayContaTipoJuego[1] << '\n';
		std::cout << "Full: " << arrayContaTipoJuego[2] << '\n';
		std::cout << "Poker: " << arrayContaTipoJuego[3] << '\n';
		std::cout << "generala: " << arrayContaTipoJuego[4] << '\n';

		std::cout << "********************************************************\n";
		std::cout << '\n';
		std::cout << "Presione una tecla para continuar...\n";
		std::cin.get();
		system("cls");
		//LIMPIAR ARRAYS
		for (size_t i = 0; i < 6; i++)
		{
			arrayContaNum[i] = 0;
		}
		
	} while (!gano);

	return 0;
};
