#pragma once
#include "game_piece.h"

using std::vector;

namespace checkers {

class Player {

public:
  /**
   * Add opponent's captured piece to list
   * @param game_piece The captured piece
   */
  void UpdateCollectedPieces(GamePiece game_piece);

  vector<GamePiece> GetCollectedPieces();

private:
  vector<GamePiece> collected_pieces_;
};
} // namespace checkers
