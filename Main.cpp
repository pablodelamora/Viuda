#include <iostream>
#include <string>
#include <forward_list>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
#include <time.h>
#include "Carta.h"
#include "Mano.h"
#include <list>
using namespace std;
//const int numJugadores = 3;

//----------------------------------------------------------------------------
template <typename T>
struct input_t
{
	mutable T& n;
	explicit input_t(T& n) : n(n) { }
	input_t(const input_t <T> & i) : n(i.n) { }
};

//----------------------------------------------------------------------------
template <typename T>
inline
input_t <T>
input(T& n)
{
	input_t <T> result(n);
	return result;
}

//----------------------------------------------------------------------------
template <typename T>
istream& operator >> (istream& ins, const input_t <T> & i)
{
	// Read a line (terminated by ENTER|NEWLINE) from the user
	string s;
	getline(ins, s);

	// Get rid of any trailing whitespace
	s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

	// Read it into the target type
	istringstream ss(s);
	ss >> i.n;

	// Check to see that there is nothing left over
	if (!ss.eof())
		ins.setstate(ios::failbit);

	return ins;
}

//-------------------------------------------------------------------------



stack<Carta> crearDeck()
{
	vector<Carta> deckVector = vector<Carta>();

	deckVector.push_back(Carta("A", "Espadas"));
	deckVector.push_back(Carta("2", "Espadas"));
	deckVector.push_back(Carta("3", "Espadas"));
	deckVector.push_back(Carta("4", "Espadas"));
	deckVector.push_back(Carta("5", "Espadas"));
	deckVector.push_back(Carta("6", "Espadas"));
	deckVector.push_back(Carta("7", "Espadas"));
	deckVector.push_back(Carta("8", "Espadas"));
	deckVector.push_back(Carta("9", "Espadas"));
	deckVector.push_back(Carta("10", "Espadas"));
	deckVector.push_back(Carta("J", "Espadas"));
	deckVector.push_back(Carta("Q", "Espadas"));
	deckVector.push_back(Carta("K", "Espadas"));

	deckVector.push_back(Carta("A", "Corazones"));
	deckVector.push_back(Carta("2", "Corazones"));
	deckVector.push_back(Carta("3", "Corazones"));
	deckVector.push_back(Carta("4", "Corazones"));
	deckVector.push_back(Carta("5", "Corazones"));
	deckVector.push_back(Carta("6", "Corazones"));
	deckVector.push_back(Carta("7", "Corazones"));
	deckVector.push_back(Carta("8", "Corazones"));
	deckVector.push_back(Carta("9", "Corazones"));
	deckVector.push_back(Carta("10", "Corazones"));
	deckVector.push_back(Carta("J", "Corazones"));
	deckVector.push_back(Carta("Q", "Corazones"));
	deckVector.push_back(Carta("K", "Corazones"));

	deckVector.push_back(Carta("A", "Diamantes"));
	deckVector.push_back(Carta("2", "Diamantes"));
	deckVector.push_back(Carta("3", "Diamantes"));
	deckVector.push_back(Carta("4", "Diamantes"));
	deckVector.push_back(Carta("5", "Diamantes"));
	deckVector.push_back(Carta("6", "Diamantes"));
	deckVector.push_back(Carta("7", "Diamantes"));
	deckVector.push_back(Carta("8", "Diamantes"));
	deckVector.push_back(Carta("9", "Diamantes"));
	deckVector.push_back(Carta("10", "Diamantes"));
	deckVector.push_back(Carta("J", "Diamantes"));
	deckVector.push_back(Carta("Q", "Diamantes"));
	deckVector.push_back(Carta("K", "Diamantes"));

	deckVector.push_back(Carta("A", "Treboles"));
	deckVector.push_back(Carta("2", "Treboles"));
	deckVector.push_back(Carta("3", "Treboles"));
	deckVector.push_back(Carta("4", "Treboles"));
	deckVector.push_back(Carta("5", "Treboles"));
	deckVector.push_back(Carta("6", "Treboles"));
	deckVector.push_back(Carta("7", "Treboles"));
	deckVector.push_back(Carta("8", "Treboles"));
	deckVector.push_back(Carta("9", "Treboles"));
	deckVector.push_back(Carta("10", "Treboles"));
	deckVector.push_back(Carta("J", "Treboles"));
	deckVector.push_back(Carta("Q", "Treboles"));
	deckVector.push_back(Carta("K", "Treboles"));

	srand(time(0));
	random_shuffle(deckVector.begin(), deckVector.end());

	stack<Carta> deckStack;

	for (auto i = deckVector.begin(); i != deckVector.end(); i++)
	{
		deckStack.push(*i);
	}

	return deckStack;
}


//despliega menu de la primera ronda
int menuPrimeraRonda(Mano jugador)
{

	int opcion= 0;
	cout << "1.- Cambiar mano completa" << endl;
	cout << "2.- Pasar" << endl;
	cout << endl;
	cout << "Dame tu opcion: ";
	cin >> input(opcion);
	cout << endl<< endl;

	while (!cin || (opcion<1 || opcion>2))
	{
		cin.clear();
		cout << "Porfavor entrar un numero valido  " << flush << endl << endl;
		cin >> input(opcion);

	}

	
	cout << endl;
	return opcion;
}


//despliega menu de la rona normal
int menuRondaNormal(Mano jugador){

	int opcion=0;
	cout << "1.- Cambiar una carta" << endl;
	cout << "2.- Cambiar toda la mano" << endl;
	cout << "3.- Tocar" << endl << endl;

	cout << "Dame tu opcion: ";
	cin >> input(opcion);
	cout << endl << endl;

	while (!cin || (opcion<1 || opcion>3))
	{
		cin.clear();
		cout << "Porfavor entrar un numero valido " << flush << endl;
		cin >> input(opcion);
	}

	
	cout << endl;
	return opcion;
}

//Menu para seleccionar la carta de tu mano
int menuSeleccionCarta(Mano jugador){

	int opcion= 0;
	cout << "Dame el numero de carta que deseas cambiar: ";
	cin >> input(opcion);
	cout << endl << endl;

	while (!cin || (opcion<1 || opcion>5))
	{
		cin.clear();
		cout << "Porfavor entrar un numero valido " << flush << endl;
		cin >> input(opcion);
	}

	return opcion;

}

//Menu para la seleccion de la carta de la viuda
int menuSeleccionCartaViuda(Mano centro){

	int opcion= 0;
	cout << "Dame el numero de carta que deseas recoger de la mano de la viuda: ";
	cin >> input(opcion);
	cout << endl << endl;

	while (!cin || (opcion<1 || opcion>5))
	{
		cin.clear();
		cout << "Porfavor entrar un numero valido " << flush << endl;
		cin >> input(opcion);
	}

	cout << endl;
	return opcion;

}

//Menu ronda final
int menuRondaFinal(Mano jugador){
	int opcion = 0;
	cout << "1.- Cambiar una carta" << endl;
	cout << "2.- Cambiar toda la mano" << endl;
	cout << "3.- Pasar" << endl<< endl;
	cout << "Dame tu opcion: ";
	cin >> input(opcion);

	while (!cin || (opcion<1 || opcion>3))
	{
		cin.clear();
		cout << "Porfavor entrar un numero valido " << flush << endl;
		cin >> input(opcion);
	}

	cout << endl;
	return opcion;
}

int main()
{
	//Definir cuantos jugadores
	cout << "Definir numero de jugadores: " << endl;
	int numJugadores = 0;
	cin >> input(numJugadores);
	cout << endl;
	while (!cin || (numJugadores<2 || numJugadores>9))
	{
		cin.clear();
		cout << "Porfavor entre 2 y 9 " << flush << endl;
		cin >> input(numJugadores);
		//cout << "Porfavor entre 1 y 9 " << flush << endl;
	}

	//Inscribir Jugadores
	list<Mano> listaDeJugadores;
	char nombreJugador[300];
	for (int i = 0; i < numJugadores; i++)
	{
		cout << "Nombre del jugador virtual " << i+1 << ": "; 
		cin.getline (nombreJugador,300); 
		cout << endl;
		while (!cin){
			cin.clear();
			cin >> input(nombreJugador);
			cout << "Porfavor entrar un nombre valido  " << flush << endl << endl;
		}
		listaDeJugadores.push_back(Mano(nombreJugador));
	}

	//Generar Deck
	stack<Carta> deck = crearDeck();

	//Repartir cartas
	Mano viuda=Mano("Viuda");

	for (int i = 0; i < 5; i++)//(auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)
	{
		for (auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)//(int i = 0; i < 5; i++)
		{
			(*it).recibirCarta(deck.top()); deck.pop();
		}
		viuda.recibirCarta(deck.top()); deck.pop();
	}
	/*for (int i = 0; i < 5; i++)
	{
		viuda.recibirCarta(deck.top()); deck.pop();
	}*/



	//Primera Ronda
	bool deckVolteado = false;
	auto it = listaDeJugadores.begin();

	cout << "En la primera ronda solo se puede cambiar toda la mano, sin ver la viuda." << endl << endl;

	while (it != listaDeJugadores.end() && !deckVolteado)
	{
		cout << (*it);
		int opcion = menuPrimeraRonda(*it);
		if (opcion == 1)
		{
			deckVolteado = true;
			list<Carta> aux = (*it).entregarLista();
			(*it).recibirLista(viuda.entregarLista());
			viuda.recibirLista(aux);
			cout << "Se han cambiado las cartas." << endl << endl;
		}
		it++;
	}
	if (it == listaDeJugadores.end())
	{
		it = listaDeJugadores.begin();
	}



	//Rondas normales
	cout << "Ahora podras cambiar cartas hasta que uno de los jugadores toque" << endl << endl;
	bool tocar = false;
	while (!tocar)
	{
		cout << (*it);
		cout << viuda;
		int opcion = menuRondaNormal(*it);

		if (opcion == 1)
		{
			
			int seleccionCarta = menuSeleccionCarta(*it);
			int seleccionCartaViuda = menuSeleccionCartaViuda(viuda);
			Carta aux1 = (*it).entregarCarta(seleccionCarta);
			(*it).recibirCarta(viuda.entregarCarta(seleccionCartaViuda));
			viuda.recibirCarta(aux1);
		}
		//cambia todas las cartas
		if (opcion == 2)
		{
			list<Carta> aux = (*it).entregarLista();
			(*it).recibirLista(viuda.entregarLista());
			viuda.recibirLista(aux);
		}

		if (opcion == 3){
		
			tocar = true;

		}



		it++;
		if (it == listaDeJugadores.end())
		{
			it = listaDeJugadores.begin();
		}
	}


	

	//Ronda final
	cout << "Ultima ronda para todos menos para el que toco" << endl << endl;
	int turnos = 0;

	while (turnos < numJugadores - 1){

		cout << (*it);
		cout << viuda;
		int opcion = menuRondaFinal(*it);
		if (opcion == 1)
		{

			int seleccionCarta = menuSeleccionCarta(*it);
			int seleccionCartaViuda = menuSeleccionCartaViuda(viuda);
			Carta aux1 = (*it).entregarCarta(seleccionCarta);
			(*it).recibirCarta(viuda.entregarCarta(seleccionCartaViuda));
			viuda.recibirCarta(aux1);
		}
		//cambia todas las cartas
		if (opcion == 2)
		{
			list<Carta> aux = (*it).entregarLista();
			(*it).recibirLista(viuda.entregarLista());
			viuda.recibirLista(aux);
		}




		turnos++;
		it++;
		if (it == listaDeJugadores.end())
		{
			it = listaDeJugadores.begin();
		}


	}
	


	//Elegir ganador
	Mano ganador = Mano("");
	for (auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)
	{
		(*it).HacerJugada();
	}
	for (auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)
	{
		if ((*it).getJugada() > ganador.getJugada())
		{
			ganador = (*it);
		}
		else if ((*it).getJugada() == ganador.getJugada())
		{
			if ((*it).getPeso() > ganador.getPeso())
			{
				ganador = (*it);
			}
			else
			{
				void;
			}
		}
	}
	cout << "El gandor es: " << endl << ganador.getNombreJugador() << endl << ganador << endl;




	

	system("pause");
	return 0;
}

