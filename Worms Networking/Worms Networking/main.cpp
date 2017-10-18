#include <iostream>
#include "EventGenerator.h"
#include "Worm.h"
#include "Server.h"
#include "Client.h"
#include "fileHandler.h"
//#include "fsm.h"
//#include "Graphics.h"

#define DEF_PORT 12345
#define DEF_PORT_STR "12345"

int parserCmd(vector <string> & ipsVector, int cantMaquinas, int & maquinaPropia, int argc, char ** argv);

bool tryConection(vector<string> & ipsVector, int maquinaPropia, maquina * p2Mymaquina);

int main(int argc, char ** argv)
{
	//inicilizacion de allegro y boost

	fileHandler ipsHandler("ips.txt", 'r'); // Abro el archivo de las ips en modo escritura
	vector <string> ipsVector;
	ipsHandler.extractLines(ipsVector);
	int maquinaPropia = 0, cantMaquinas = (int)ipsVector.size();

	if (parserCmd(ipsVector, cantMaquinas, maquinaPropia, argc, argv)) //luego del parser, ya se que maquina soy
	{
		maquina * p2Mymaquina = nullptr;

		if (tryConection(ipsVector, maquinaPropia, p2Mymaquina))
		{

		}
		else
		{
			cout << "Error al intentar conexión en red, verifique su conexión a la red..." << endl;
		}
	}

/*
	fsm state_machine;
	Worm worms;
	EventGenerator eg(worms,Graphics); // se le pasan cosas que sobreviven al dispatcher

	do
	{
		eg.searchForEvents();
		if(eg.hayEvento())
		{
			state_machine.dispatch(eg.getNextEvent());
		}
	}while(eg.isNotQuit);
*/
	//destruyo todo lo que cree
	return 0;
}


int parserCmd(vector <string> & ipsVector, int cantMaquinas, int & maquinaPropia, int argc, char ** argv)
{
	bool ret = false;
	bool maquinaFounded = false;
	if (argc > 1) // Línea de comandos con otro parámetro además del nombre
	{
		for (int i = 0; (i < cantMaquinas) && (!maquinaFounded); i++)
		{
			if (!strcmp(argv[1], ipsVector[i].c_str())) // Si la ip pasada por parámetro es una ip del archivo
			{
				maquinaFounded = true;
				maquinaPropia = i + 1; // Identifico el numero de máquina. Es i '+1'  porque las máquinas comienzan en '1', pero i en '0'.
			}
		}
		if (maquinaFounded)
		{
			ret = false;
			cout << "el parámetro que se ingresó es erróneo" << endl;
		}

	}
	else
	{
		ret = false;
		cout << "No ha ingresado parámetros" << endl;
	}

	return ret;
}

bool tryConection(vector<string> & ipsVector, int maquinaPropia, maquina * p2Mymaquina)
{
	bool ret = false;
	bool alreadyConected = false;
	if (maquinaPropia == 0)
	{
		p2Mymaquina = new server(DEF_PORT);
		p2Mymaquina->conect_to_port();
	}
	else
	{
		p2Mymaquina = new client;
		p2Mymaquina->conect_to_host((ipsVector[0]).c_str(), DEF_PORT_STR);
	}
	ret = true;
	return ret;
}