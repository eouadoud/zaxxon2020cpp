#pragma once

#include "Bullets.h"



class Warrior
{

private:
	unsigned nbrJoueur;

	Vector2f joueurCentre;

	int shootTimer;
	int shootTimerMax;

	int damageTimer;
	int damageTimerMax;


	//Texture *texture;

	Sprite sprite;
	RectangleShape hitbox;

	//Texture* textureBalles;
	std::vector<Bullets> bullets;
	Texture* textureBalles;

	int actions[5];

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;

public:
	Warrior(std::vector<Texture>& textures, int HAUT = 73, int BAS = 74, int GAUCHE = 71, int DROITE = 72, int TIRER = 57);
	virtual ~Warrior();

	//Accesseur
	inline std::vector<Bullets>& getBalles() { return this->bullets; }


	//Fonctions
	void Combat();
	void Mouvement();
	void Update(Vector2u windowBounds);
	void Draw(RenderTarget& target);

	static unsigned joueurs;

};
