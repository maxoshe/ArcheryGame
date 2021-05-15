//game.h - Moshe Stanylov
//Game class

#ifndef GAME_H
#define GAME_H

class Game {
private:
  int _arrows;
  int _hits;
  int _rounds;
  double _hit_rate;
  double _arrows_per_target;

  //Generate target location between 0 and max meters
  //Used by Round
  int GenerateTarget(int max);

  //Calculate projectile range based on angle
  //Used by Round
  int CalculateRange(double angle);

  //Calculate stats
  //Used by accessors
  void CalcHitRate();
  void CalcArrowsPerTarget();

public:
  //Constructor
  Game();

  //Destructor
  ~Game();

  //Accessors
  int get_arrows();
  int get_hits();
  int get_rounds();
  double get_hit_rate();
  double get_arrows_per_target();

  //A single round of the game
  void Round();
};

#endif