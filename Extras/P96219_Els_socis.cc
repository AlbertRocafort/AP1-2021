#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int dia;
    int mes;
    int any;
};

void llegir_data(Data& data) {
    
    cin >> data.dia >> data.mes >> data.any;
}

struct Persona {
    string nom;
    int dni;
    Data naixament;
    string municipi;
};

void llegir_persona(Persona& persona)
{
    cin >> persona.nom;
    cin >> persona.dni;
    llegir_data(persona.naixament);
    cin >> persona.municipi;
}

struct Soci {
    int dni;
    bool junta;
    Data inscripcio;
};

void llegir_soci(Soci& soci)
{
    cin >> soci.dni;

    char aux;
    cin >> aux;
    if (aux == 'S') soci.junta = true;
    else soci.junta = false;

    llegir_data(soci.inscripcio);
}

//using Persones = vector<Persona>;
typedef vector<Persona> Persones;

//using Socis = vector<Soci>;
typedef vector<Soci> Socis;

// Retorna el nombre de socis que siguin a la junta i
// visquin en un municipi donat i hagin nascut a
// l'any donat o més tard.
//
// Precondició: persones i socis ordenats per dni
//
int nombre_de_socis_joves_a_la_junta_en_un_municipi(const Persones& persones, const Socis& socis, int any, const string& municipi)
{
    
    int i = 0, j = 0;
    int contador = 0;

    // Iterem pels dos vectors buscant les persones que son socis
    while (i < persones.size() and j < socis.size()) {

        // Com que els dos vectors estan ordenats, anem buscant les coincidencies

        // Si el dni de la persona i es mes petit que el del soci j, avancem i
        if (persones[i].dni < socis[j].dni) i++;

        // Si el dni de la persona i es mes gran que el del soci j, avancem j
        else if (persones[i].dni > socis[j].dni) j++;

        // Si coincideixen, mirem si es compleixen les demes condicions
        else {

            if (socis[j].junta and persones[i].municipi == municipi and persones[i].naixament.any >= any) {
            	contador++;
            	cout << persones[j].dni << endl;
			}
                

            // Avancem els dos indexs
            i++;
            j++;
        }

    }

    return contador;
}

int main()
{
    // llegir persones
    int np;
    cin >> np;
    Persones persones(np);
//    for (Persona& persona : persones) {
//        llegir_persona(persona);
//    }

	for (int i = 0; i < persones.size(); i++) {
		llegir_persona(persones[i]);
	}

    // llegir socis
    int ns;
    cin >> ns;
    Socis socis(ns);
//    for (Soci& soci : socis) {
//        llegir_soci(soci);
//    }

	for (int i = 0; i < socis.size(); i++) {
		llegir_soci(socis[i]);
	}

    // llegir paràmetres
    int any;
    cin >> any;
    string municipi;
    cin >> municipi;

    // escriure el resultat
    cout << nombre_de_socis_joves_a_la_junta_en_un_municipi(persones, socis, any, municipi);
}
