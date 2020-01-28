#pragma once
  bool hasFins() const;
  bool hasTail() const;
  int legs() const;
  void setHair();
  void setAirborne();
  void setAquatic();
  void setToothed();
  void setFins();
  void setTail();
  void setLegs(int legs);
private:
  bool hair_;
  bool airborne_;
  bool aquatic_;
  bool toothed_;
  bool fins_;
  bool tail_;
  int legs_;
};
