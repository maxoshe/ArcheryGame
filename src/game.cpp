//game.cpp - Moshe Stanylov
//Game class methods

#include "game.h"
#include "ui.h"
#include <math.h>

int Game::GenerateTarget(int max) {
  srand(time(0));
  int num = rand()%(max+1);
  return num;
}

int Game::CalculateRange(double angle) {
  int velocity = 89;
  double gravity = 9.81;
  double rads = angle*3.14/180;
  double flight_time = (2.0 * velocity * sin(rads)) / gravity;
  double horz_velocity = velocity * cos(rads);
  int range = round(horz_velocity*flight_time);
  return range;
}

void Game::CalcHitRate() {
  _hit_rate = (double)_hits / (double)_arrows * 100;
}

void Game::CalcArrowsPerTarget() {
  _arrows_per_target = (double)_arrows / (double)_rounds;
}

Game::Game() {
}

Game::~Game() {
}

int Game::get_arrows() {
  return _arrows;
}

int Game::get_hits() {
  return _hits;
}

int Game::get_rounds() {
  return _rounds;
}

double Game::get_hit_rate() {
  CalcHitRate();
  return _hit_rate;
}

double Game::get_arrows_per_target() {
  CalcArrowsPerTarget();
  return _arrows_per_target;
}

void Game::Round() {
  //Increment rounds
  _rounds++;
  //Generate random target between 0 and 807
  int target_distance = GenerateTarget(807);
  //Output to User Interface
  DisplayTargetDistance(target_distance);
  //Loop until out of arrows
  for (int i = 1; i <= 10; i++) {
    //Input from User Interface
    double angle = UserAngle(0, 90);
    //Update stats and end round
    if(not angle) {
      _arrows += i;
      return;
    }
    //Calculate range based on angle
    int arrow_range = CalculateRange(angle);
    //Compare range to target
    int difference = target_distance - arrow_range;
    //Output to User Interface
    DisplayShotResult(difference);
    //Update stats and end round
    if(difference == 0) {
      _hits++;
      _arrows += i;
      return;
    }
    //Call User Interface
    DisplayRemArrows(10-i);
  }
  //Update stats
  _arrows += 10;
}