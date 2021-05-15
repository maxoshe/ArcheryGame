//ui.h - Moshe Stanylov
//Command line user interface methods

#ifndef UI_H
#define UI_H

#include <string>
#include "game.h"

//Prompt user continue or quit
//Return 1 if input is 'y'
//Return 0 otherwise
bool UserChoice();

//Get input angle between min and max from user
//Return angle if between min and max
//Return 0 otherwise
double UserAngle(int min, int max);

//Display welcome Message and game rules
void DisplayStart();

//Display the target distance in meters
void DisplayTargetDistance(int target_distance);

//Display Hit or Miss messeges
void DisplayShotResult(int distance_from_target);

//Display remaining arrows
void DisplayRemArrows(int arrows);

//Display hit/tries statistic, used after each round
void DisplayRoundStats(Game game);

//Display end game Statistics
void DisplayOver(Game game);

//Helpers

//Used by DisplayOverto format strings
//Returns a string starting with num, appended by apndx
//and padded with whitespace to achieve desired_length
std::string PadString(int num, int desired_length, std::string apndx);

//Clean input stream, used by methods if cin failed
void CleanStream();

#endif