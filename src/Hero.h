#pragma once
#include "Character.h"
#define CHARACTER_CONSTRUCT const std::string _type, const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale = 1.0f
#define CHARACTER_PARAMS const std::string _type, const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 &_pos, const float _scale

DECLARE_SMART(Hero, spHero)
class Hero : public Character
{
public:
	static spHero getHero(b2World* _world, oxygine::Vector2 size);

	int GetArmor() const { return armor; };
    void SetArmor(const int _armor) { armor = std::min(_armor, maxArmor); }
    void AddArmor(const int _armor) { armor = std::min(_armor + armor, maxArmor); }

    void AddDamage(const int _damage) { damage = std::min(_damage + damage, maxDamage); }

    void AddHealth(const int _health) { health = std::min(_health + health, maxHealth); }

	void SetLevel(const int _level) { level = _level; };

	int GetNextLevelXp() const { return quest; };
	int GetMaxArmor() { return maxArmor; };

    void AddXp(const int _xp)
    {
        xp += _xp;
        //Verify if the current quest was completed
        if(xp >= quest)
        {
            IncreaseLevel();
        }
        
    }
    
    // Anims the hero when attacking and returns a random value between
    // 1 and 'damage'
    int DealDamage();
    void Die(std::string mob_type);

	void setTargetPosition(const oxygine::Vector2 _targetPosition) { targetPosition = _targetPosition; };
	oxygine::Vector2 getTargetPosition() const { return targetPosition; };
    
private:
	//Singleton
	Hero(const int _health, const int _damage, const int _xp, const int _armor, CHARACTER_CONSTRUCT);
    void IncreaseLevel();
    //smart pointer instance
    static spHero hero;
	int armor, maxArmor;
    int quest;
	oxygine::Vector2 targetPosition;
};
