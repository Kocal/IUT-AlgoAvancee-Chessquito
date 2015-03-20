#include <iostream>
#include "Partie.h"

using namespace std;

Partie::Partie() : nbJoueurs(0), nbJoueursMax(2), j1(NULL), j2(NULL) {}

Partie::Partie(string date) : date(date), nbJoueurs(0), nbJoueursMax(2), j1(NULL), j2(NULL) {}

void Partie::setDate(string date) {
    this->date = date;
}

string Partie::getDate() {
    return this->date;
}

bool Partie::setJoueur(Joueur* joueur) {

    this->nbJoueurs++;

    if(!this->j1) {
        joueur->setPartie(this);
        this->j1 = joueur;
    } else if (!this->j2) {
        joueur->setPartie(this);
        this->j2 = joueur;
    } else {
        this->nbJoueurs--;
        cerr << "Impossible d'ajouter le joueur " << joueur->getNom() << " (" << joueur << ")" << endl;
        return false;
    }

    cout << "Ajout du joueur " << joueur->getNom() << " (" << joueur << ")" << " fait avec succès" << endl;
    return true;
}

void Partie::quittePartie(Joueur* j) {
    cout << "Le joueur " << j->getNom() << " a quitté la partie." << endl;
    this->nbJoueurs--;
}

bool Partie::estJouable(void) {
    return this->nbJoueurs == this->nbJoueursMax;
}

Partie::~Partie()
{
    cout << "La partie va s'arrêter." << endl;
    if(this->j1) {
        this->j1->setPartie(NULL);
    }

    if(this->j2) {
        this->j2->setPartie(NULL);
    }
}
