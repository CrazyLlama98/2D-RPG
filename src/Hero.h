#pragma once
#include "Entity"
#define ENTITY_CONSTRUCT b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f

class Hero : public Entity
{
public:
    Hero(const oxygine::ResAnim *_res, const int _health, const int _damage, const int _xp, const int _armor, ENTITY_CONSTRUCT);
	
	int GetArmor() const { return armor; };
	void SetArmor(const int _armor){ armor = _armor; };
    void AddArmor(const int _armor);

    void AddDamage(const int _damage);

    void AddHealth(const int _health);
	
    void AddXp(const int _xp);
    
    void DealDamage();
    void Respawn();
    void Die();
    void Click(oxygine::Event *_event);
private:
	int armor; 
}
