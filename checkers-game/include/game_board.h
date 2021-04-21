#pragma once

#include "cinder/gl/gl.h"
#include "game_piece.h"
#include "player.h"
#include "square.h"

using glm::vec2;
using std::vector;

namespace chess {
class GameBoard {
public:
  GameBoard();

  void SelectNextMove(Square& square);

  void MoveToSquare();

private:
  static const size_t kBoardSize;
  bool is_player_one_turn_;
  bool is_piece_selected_;
  Player player_one_;
  Player player_two_;
  Square selected_square_;
  vector<vector<Square>> game_board_;
 

  void UpdatePossiblePositions();
};
} // namespace chess
