#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>



using namespace sf;

class Bullets
{
private:
	Texture* texture;
	Sprite sprite;

	Vector2f maxVitesse;

public:
	Bullets(Texture* texture, Vector2f position, Vector2f maxVitesse = Vector2f(15.f, 0.f));
	virtual ~Bullets();

	//Accesseurs
	inline FloatRect getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	inline Vector2f getPosition()const { return this->sprite.getPosition(); }
	//Fonstions
	void Movement();

	void Update();
	void Draw(RenderTarget& target);
};
