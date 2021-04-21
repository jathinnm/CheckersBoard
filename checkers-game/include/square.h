#pragma once
#include "game_board.h"

using std::vector;

namespace chess {

class Square {
public:
  
  void SetSquareColor(std::string set_color);
  void SetGamePiece(GamePiece& set_piece);
private:
  std::string color_;
  GamePiece piece_;
};
}  // namespace idealgas
