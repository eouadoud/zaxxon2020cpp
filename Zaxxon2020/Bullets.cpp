#include "Bullets.h"



Bullets::Bullets(Texture* texture, Vector2f position, Vector2f maxVitesse)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);
	this->maxVitesse = maxVitesse;
	this->sprite.setScale(0.1f, 0.1f);
	this->sprite.setPosition(Vector2f(position.x - this->sprite.getGlobalBounds().width / 2,
		position.y - this->sprite.getGlobalBounds().height / 2));


}


Bullets::~Bullets()
{
}

void Bullets::Movement()
{
	this->sprite.move(this->maxVitesse.x, this->maxVitesse.y);
}

void Bullets::Update()
{
	this->Movement();
}
void Bullets::Draw(RenderTarget& target)
{
	target.draw(this->sprite);
}