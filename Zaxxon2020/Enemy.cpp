#include "Enemy.h"


enum eType { MOVELEFT = 0, fOLLOW, FOLLOWFAST, FOLLOWSHOOT, FOLLOWFASTSHOOT };

Enemy::Enemy(Texture* texture, Vector2u windowBounds,
	Vector2f position, Vector2f direction,
	Vector2f scale, int type,
	int hpMax, int damageMax, int damageMin)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);
	this->sprite.setScale(scale);

	this->sprite.setPosition(windowBounds.x - 200, rand() % windowBounds.y + this->sprite.getGlobalBounds().height);

	this->type = type;
	this->hpMax = hpMax;
	this->hp = hp;

	this->damageMax = damageMax;
	this->damageMin = damageMin;

}


Enemy::~Enemy()
{
}

void Enemy::takeDamage(int damage=0)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

void Enemy::Update()
{
	switch (this->type)
	{
	case 0:
		this->sprite.move(-1.f, 0.f);
		break;

	default:
		break;

	}
}

void Enemy::Draw(RenderTarget& target)
{
	target.draw(this->sprite);
}