#include "Warrior.h"

unsigned Warrior::joueurs = 0;

enum actions { TOP = 0, BOTTOM = 1, LEFT = 2, RIGHT = 3, FIRE = 4 };

Warrior::Warrior(std::vector<Texture>& textures,
	int TOP, int BOTTOM,
	int LEFT, int RIGHT,
	int FIRE)
	:level(1), exp(0), expNext(100),
	hp(10), hpMax(10),
	damage(1), damageMax(2),
	score(0)
{


	this->sprite.setTexture(textures[0]);
	this->sprite.setScale(0.12f, 0.12f);

	this->textureBalles = &textures[1];

	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;

	this->damageTimerMax = 10;
	this->damageTimer = this->damageTimerMax;

	this->actions[actions::TOP] = TOP;
	this->actions[actions::BOTTOM] = BOTTOM;
	this->actions[actions::LEFT] = LEFT;
	this->actions[actions::RIGHT] = RIGHT;
	this->actions[actions::FIRE] = FIRE;

	this->nbrJoueur = Warrior::joueurs;
	Warrior::joueurs++;

	std::cout << this->nbrJoueur << "\n";



}


Warrior::~Warrior()
{

}

void Warrior::Mouvement()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->actions[actions::TOP])))
		this->sprite.move(0.f, -5.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->actions[actions::BOTTOM])))
		this->sprite.move(0.f, 5.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->actions[actions::RIGHT])))
		this->sprite.move(5.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Key(this->actions[actions::LEFT])))
		this->sprite.move(-5.f, 0.f);


}

void Warrior::Combat()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->actions[actions::FIRE])) && this->shootTimer >= this->shootTimerMax)
	{
		this->bullets.push_back(Bullets(textureBalles, this->joueurCentre));

		this->shootTimer = 0; //Reset Temps pour tirer
	}
}

void Warrior::Update(Vector2u windowBounds)
{
	//Update timers
	if (this->shootTimer < this->shootTimerMax)
	{
		this->shootTimer++;
	}

	if (this->damageTimer < this->damageTimerMax)
	{
		this->damageTimer++;
	}

	//Update position
	this->joueurCentre.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
	this->joueurCentre.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2;

	this->Mouvement();
	this->Combat();


}
void Warrior::Draw(RenderTarget& target)
{
	target.draw(this->sprite);

	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}
}