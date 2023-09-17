#pragma once

#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include <string>

enum class WeaponType {
  arcane,
  blade,
  cold,
  fire,
  impact,
  none,
  pierce,
};


class Weapon {
public:
  explicit Weapon(std::string name, uint32_t damage, uint32_t strikes, WeaponType type)
      : name_(name),
        damage_(damage),
        strikes_(strikes),
        type_(type){}
        
  std::string name() const { return name_; }
  uint32_t strikes() const { return strikes_; }
  uint32_t damage() const { return damage_; }
  WeaponType type() const { return type_; }
  virtual bool is_ranged() const { return false; }
  bool is_melee() const { return not is_ranged(); }
  
private:
  std::string name_;
  uint32_t damage_;
  uint32_t strikes_;
  WeaponType type_;
};

class MeleeWeapon : public Weapon {
public:
  explicit MeleeWeapon(std::string name, uint32_t damage, uint32_t strikes, WeaponType type)
    : Weapon(name, damage, strikes, type) {}
};

class RangedWeapon : public Weapon {
public:
  explicit RangedWeapon(std::string name, uint32_t damage, uint32_t strikes, WeaponType type)
    : Weapon(name, damage, strikes, type) {}
  bool is_ranged() const override { return true; }
};

class Unit {
public:
    virtual std::string type_name() const = 0;  // Unit base class is abstract
    std::string name() const { return name_; }
    uint32_t max_health() const { return max_health_; }
    uint32_t moves() const { return moves_; }
    MeleeWeapon melee_weapon() const { return melee_weapon_; }
    RangedWeapon ranged_weapon() const { return ranged_weapon_; }

protected:
  // class is abstract and cannot be instantiated
  // derived classes can delegate to this constructor though
  Unit(std::string name, uint32_t max_health, uint32_t moves,
       MeleeWeapon m, RangedWeapon r)
      : name_(name), max_health_ (max_health), moves_(moves), melee_weapon_(m), ranged_weapon_(r) {}
private:
  std::string name_;
  int32_t health_;
  uint32_t max_health_;
  uint32_t moves_;
  MeleeWeapon melee_weapon_;
  RangedWeapon ranged_weapon_;
};



class DwarvishFighter: public Unit {
public:
    DwarvishFighter(std::string name)
        : Unit(name, 38, 4, MeleeWeapon("Axe", 7, 3, WeaponType::blade), RangedWeapon("None", 0, 0, WeaponType::none)) {}
        std::string type_name() const override { return "Dwarfish Fighter"; };  
};

class ElvishArcher: public Unit {
public:
    ElvishArcher(std::string name)
        : Unit(name, 29, 6, MeleeWeapon("Sword", 5, 2, WeaponType::blade), RangedWeapon("Bow", 5, 4, WeaponType::pierce)) {}
        std::string type_name() const { return "Elvish Archer"; };
};

class DrakeBurner: public Unit {
public:
    DrakeBurner(std::string name)
        : Unit(name, 42, 5, MeleeWeapon("Claws", 7, 2, WeaponType::blade), RangedWeapon("Fire breath", 6, 4, WeaponType::fire)) {}
        std::string type_name() const { return "Drake Burner"; };
};
#endif // UNIT_HPP_INCLUDED
