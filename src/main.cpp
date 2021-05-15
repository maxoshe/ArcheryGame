#include "game.h"
#include "ui.h"

int main()
{
  Game game;
  DisplayStart();
  do {
    game.Round();
    DisplayRoundStats(game);
  } while (UserChoice());
  DisplayOver(game);
  return 0;
}