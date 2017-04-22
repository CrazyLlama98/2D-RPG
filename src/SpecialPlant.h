#pragma once
#include "Plant.h"

class SpecialPlant : public Plant
{
public:
	SpecialPlant(oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, 
				 const float _scale = 1.0f);

	void Click(oxygine::Event *_event);

	/* Respawn *
	 ***********
	 * Runs what happens when the hero collects a special plant.
	 * Params: Two arrays of pointers to functions. One that points to Get
	 * functions and one that points to Set functions. Both are used for
	 * RandomDrop function.
	*/
	void Respawn(int (*_get[4])(), void (*_set[4])());

private:
	/* RandomDrop *
	 **************
	 * "Drops" randomly one of the following: Health, Damage, Armor, Xp. Used
	 * internaly in Respawn function.
	*/
	void RandomDrop();
};