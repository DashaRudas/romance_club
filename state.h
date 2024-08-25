#ifndef STATE_H
#define STATE_H

class State {
 private:
  int reputation = 0;
  int diplomacy = 0;
  int strength = 0;

 public:
  State() = default;
  State(int rep, int dip, int str) : reputation(rep), diplomacy(dip), strength(str) {
  }

  int GetReputation() const {
    return reputation;
  }

  void SetReputation(int rep) {
    reputation = rep;
  }

  int GetDiplomacy() const {
    return diplomacy;
  }

  void SetDiplomacy(int dip) {
    diplomacy = dip;
  }

  int GetStrength() const {
    return strength;
  }

  void SetStrength(int str) {
    strength = str;
  }
};

#endif