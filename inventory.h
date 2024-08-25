#ifndef Inventory
#define Inventory

class Inventory {
 private:
  int diamonds;

 public:
  Inventory() : diamonds(0) {
  }

  int GetDiamonds() const {
    return diamonds;
  }

  void SetDiamonds(int value) {
    diamonds = value;
  }
};

#endif