#pragma once
#include "Character.h"
#define CHARACTER_CONSTRUCT const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f
#define CHARACTER_PARAMS const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale

DECLARE_SMART(Hero, spHero);
class Hero : public Character
{
public:
    Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_CONSTRUCT);
	
	int GetArmor() const { return armor; };
	void SetArmor(const int _armor) { armor = _armor; }
    void AddArmor(const int _armor) { armor += _armor; }

    void AddDamage(const int _damage) { damage += _damage; }

    void AddHealth(const int _health) { health += _health; }
	
    void AddXp(const int _xp) { xp += _xp; }
    
    int DealDamage();
    void Die();
    
private:
	int armor; 
};
