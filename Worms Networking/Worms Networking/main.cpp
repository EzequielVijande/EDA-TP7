#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "EventGenerator.h"
#include "Worm.h"
#include "Server.h"
#include "Client.h"
#include "fileHandler.h"
#include "FSM.h"

const float FPS = 50.0;
typedef maquina* p2machine_t;
typedef ALLEGRO_DISPLAY* p2display_t;
typedef ALLEGRO_TIMER* p2timer_t;
typedef ALLEGRO_EVENT_QUEUE* p2ev_queue_t;

//#include "Graphics.h"

#define DEF_PORT 12345
#define DEF_PORT_STR "12345"

int parserCmd(vector <string> & ipsVector, int cantMaquinas, int & maquinaPropia, int argc, char ** argv);

bool tryConection(vector<string> & ipsVector, int maquinaPropia,p2machine_t& p2Mymaquina);

bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& evqueue, ALLEGRO_EVENT ev);

int main(int argc, char ** argv)
{
	//inicilizacion de allegro y boost
	
	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_TIMER * timer = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
	ALLEGRO_EVENT ev;

	if (!initAll(display, timer, event_queue, ev))
	{
		cout << "Failed initialization" << endl;
		return -1;
	}

	graphic_movement Graphics;

	Graphics.init();

	fileHandler ipsHandler("ips.txt", 'r'); // Abro el archivo de las ips en modo escritura
	vector <string> ipsVector;
	ipsHandler.extractLines(ipsVector);
	int maquinaPropia = 0, cantMaquinas = (int)ipsVector.size();

	maquina * p2Mymaquina = nullptr;

	if (parserCmd(ipsVector, cantMaquinas, maquinaPropia, argc, argv)) //luego del parser, ya se que maquina soy
	{

		if (tryConection(ipsVector, maquinaPropia, p2Mymaquina))
		{

		}
		else
		{
			cout << "Error al intentar conexi�n en red, verifique su conexi�n a la red..." << endl;
		}
	}
	else
	{
		getchar();
		exit(-1);
	}

	fsm state_machine;
	Worm worms(maquinaPropia);
	EventGenerator eg(&worms,&Graphics,p2Mymaquina, event_queue); // se le pasan cosas que sobreviven al dispatcher

	al_start_timer(timer);
	do
	{
		eg.searchForEvents();
		if(eg.hayEvento())
		{
			state_machine.dispatch(eg.getNextEvent());
		}
	}while(eg.isNotQuit());

	//destruyo todo lo que cree
	
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	delete p2Mymaquina;
	return 0;
}


int parserCmd(vector <string> & ipsVector, int cantMaquinas, int & maquinaPropia, int argc, char ** argv)
{
	bool maquinaFounded = false;
	if (argc > 1) // L�nea de comandos con otro par�metro adem�s del nombre
	{
		for (int i = 0; (i < cantMaquinas) && (!maquinaFounded); i++)
		{
			if (!strcmp(argv[1], ipsVector[i].c_str())) // Si la ip pasada por par�metro es una ip del archivo
			{
				maquinaFounded = true;
				maquinaPropia = i; // Identifico el numero de m�quina. Es i '+1'  porque las m�quinas comienzan en '1', pero i en '0'.
			}
		}
		if (!maquinaFounded)
		{
			cout << "La IP pasada como parametro no se encuentra en ips.txt" << endl;
			cout << "IP ingresada: " << argv[1] << endl;
		}
		else
		{
			cout << "IP fue encontrada en ips.txt" << endl;
			cout << "Inicializando conexion" << endl;
		}

	}
	else
	{
		cout << "No ha ingresado par�metros" << endl;
	}

	return maquinaFounded;
}

bool tryConection(vector<string> & ipsVector, int maquinaPropia, p2machine_t& p2Mymaquina)
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

bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& ev_queue, ALLEGRO_EVENT ev)
{
	if (!al_init()) {
		return false;
	}

	display = al_create_display(1920, 696);

	if (display == nullptr) {
		return false;
	}

	if (!al_install_keyboard())
	{
		return false;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		return false;
	}

	if (!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes
		return false;
	}
	ev_queue = al_create_event_queue();
	if (!ev_queue)
	{
		return false;
	}
	al_register_event_source(ev_queue, al_get_display_event_source(display));
	al_register_event_source(ev_queue, al_get_timer_event_source(timer));
	al_register_event_source(ev_queue, al_get_keyboard_event_source());
	al_register_event_source(ev_queue, al_get_keyboard_event_source());

	return true;
}