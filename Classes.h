//Classes defined here

#include <iostream>
#include <string>

using namespace std;

//Enemies
class EnemyData {
public:
	int GetHp(int Lvl);
	int GetDmg();
	void SetName(string name);
	void SetLvl(int Lvl);
private:
	string enemyName;
	int powerLvl;
	int enemyHp;
};
int EnemyData::GetHp(int Lvl){
	enemyHp = Lvl * 10;
	return enemyHp;
}
void EnemyData::SetName(string name){
	enemyName = name;
	return;
}
void EnemyData::SetLvl(int Lvl){
	powerLvl = Lvl;
	return;
}
int EnemyData::GetDmg(){
	return ((rand() % powerLvl) + powerLvl);
}
//Weapons
class WeaponData {
public:
	int GetDmg();
	void SetName(string name);
	void SetLvl(int Lvl);
private:
	string weaponName;
	int weaponLvl;
};
void WeaponData::SetName(string name){
	weaponName = name;
	return;
}
void WeaponData::SetLvl(int Lvl){
	weaponLvl = Lvl;
	return;
}
int WeaponData::GetDmg(){
	return ((rand() % weaponLvl) + weaponLvl);
}
//Potions
class Potion {
public:
	void SetColor(string color);
	int GetRegen();
private:
	string potionColor;
	int regenAmt;
};
void Potion::SetColor(string color){
	potionColor = color;
	return;
}
int Potion::GetRegen(){
	if (potionColor == "Blue"){
		regenAmt = 20;
	}
	if (potionColor == "Red"){
		regenAmt = 50;
	}
	if (potionColor == "Green"){
		regenAmt = 10;
	}
	else{
		regenAmt = 0;
	}
	return regenAmt;
}

