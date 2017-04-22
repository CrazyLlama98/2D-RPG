#pragma once
#include "Entity.h"

class Hero : public Entity
{
public:
	Hero(const int _health, const int _damage, const int _xp);
	
	int GetArmor() const { return armor; };
	void SetArmor(const int _armor){ armor = _armor; };
	void AddArmor(const int _armor) { armor = armor + _armor; };

	void AddDamage(const int _damage){ damage = damage + _damage; };

	void AddHealth(const int _health){ health = health + _haleth; };
	
	void AddXp(const int _xp){ xp = xp + _xp};
    
    void DealDamage();
    void Respawn();
    void Die();
    void Click(oxygine::Event *_event);
private:
	int armor; 
}
