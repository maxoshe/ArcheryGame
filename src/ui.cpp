//ui.cpp - Moshe Stanylov
//Command line user interface methods

#include "ui.h"
#include <iostream>

bool UserChoice() {
  char input;
  std::cout << "Try another target? (y/n): ";
  std::cin >> input;
  if (input == 'y') {
    return 1;
  }
  CleanStream();
  return 0;
}

double UserAngle(int min, int max) {
  double angle;
  std::cout << "Angle: ";
  std::cin >> angle;
  if(std::cin.fail() or angle<=min or angle>max) {
    CleanStream();
    std::cout << "Angle is not between "<< min
      << " and " << max << ", you had one job!\n";
    return 0;
  }
  return angle;
}

void DisplayStart() {
  std::cout << "\n\n\n"
    << ":::              <<--{--  ARCHERY  --}-->>              :::\n"
    << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
    << ":::                                                     :::\n"
    << "::: You have 10 Arrows to hit a single target,          :::\n"
    << ":::                                                     :::\n"
    << "::: Shoot an arrow by entering angle between 0 and 90   :::\n"
    << ":::                                                     :::\n\n\n";
  return;
}

void DisplayTargetDistance(int target_distance) {
  std::cout << "\n-}-> Target is " << target_distance << " meters away. \n\n";
  return;
}

void DisplayShotResult(int distance_from_target) {
  if (distance_from_target > 0) {
    std::cout << "Undershot by " << distance_from_target << " meters, ";
  }
  else if (distance_from_target < 0) {
    std::cout << "Overshot by " << -distance_from_target << " meters, ";
  }
  else {
    std::cout << "Hit! \n";
  }
  return;
}

void DisplayRemArrows(int arrows) {
  std::cout << arrows << " arrows left. \n\n";
  return;
}

void DisplayRoundStats(Game game) {
  std::cout << "\n" << game.get_hits()
    << "/" << game.get_rounds() << " target hits\n";
  return;
}

void DisplayOver(Game game) {
  int length = 23;
  //Generate strings from stat variables
  std::string arrows_used = PadString(game.get_arrows(), length, "");
  std::string targets_hit = PadString(game.get_hits(), length, "");
  std::string total_rounds = PadString(game.get_rounds(), length, "");
  std::string hit_rate = PadString(game.get_hit_rate(), length, "%");
  std::string arrow_per_target = PadString(game.get_arrows_per_target(), length, "");
  //Display stats
  std::cout << "\n\n\n"
    << ":::             <<--{--  GAME OVER  --}-->>             :::\n"
    << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
    << ":::                                                     :::\n"
    << "::: Arrows used:                 " << arrows_used << ":::\n"
    << ":::                                                     :::\n"
    << "::: Targets hit:                 " << targets_hit << ":::\n"
    << ":::                              /                      :::\n"
    << ":::                              "<< total_rounds << ":::\n"
    << ":::                                                     :::\n"
    << "::: Arrows per target:           " << arrow_per_target << ":::\n"
    << ":::                                                     :::\n"
    << "::: Hit rate:                    "<< hit_rate << ":::\n"
    << ":::                                                     :::\n";
  return;
}

std::string PadString(int num, int desired_length, std::string apndx) {
  std::string result = std::to_string(num);
  result.append(apndx);
  while(result.length() < desired_length) {
    result.append(" ");
  }
  return result;
}

void CleanStream() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return;
}
