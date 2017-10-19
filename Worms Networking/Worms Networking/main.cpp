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

#define DEF_PORT 12345
#define DEF_PORT_STR "12345"

int parserCmd(vector <string> & ipsVector, int cantMaquinas, int & maquinaPropia, int argc, char ** argv);

bool tryConection(vector<string> & ipsVector, int maquinaPropia,p2machine_t& p2Mymaquina);

bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& evqueue);

int main(int argc, char ** argv)
{
	//inicilizacion de allegro y boost
	
	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_TIMER * timer = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;

	if (!initAll(display, timer, event_queue))
	{
		cout << "Failed initialization" << endl;
		return -1;
	}

	graphic_movement Graphics;

	Graphics.init();
	Graphics.load_walk_imgs();
	Graphics.load_background();
	Graphics.load_jump_imgs();
	Graphics.load_backgroundwoalpha();

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
			cout << "Error al intentar conexión en red, verifique su conexión a la red..." << endl;
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
	cout << "Timer inicializado" << endl;
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
	if (argc > 1) // Línea de comandos con otro parámetro además del nombre
	{
		for (int i = 0; (i < cantMaquinas) && (!maquinaFounded); i++)
		{
			if (!strcmp(argv[1], ipsVector[i].c_str())) // Si la ip pasada por parámetro es una ip del archivo
			{
				maquinaFounded = true;
				maquinaPropia = i; // Identifico el numero de máquina. Es i '+1'  porque las máquinas comienzan en '1', pero i en '0'.
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
		cout << "No ha ingresado parámetros" << endl;
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

bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& ev_queue)
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