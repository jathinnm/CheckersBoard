#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::string;
using std::vector;

namespace checkers {

class GamePiece {
public:
  /**
   * Initialize game piece and bool values
   */
  GamePiece();

  bool GetIsRedColor() const;

  bool GetIsPieceKing() const;

  vec2 GetCurrentPosition() const;

  const vector<vec2> GetPossibleMoves() const;

  void SetIsPieceRed(bool set_is_piece_red_);

  void SetCurrentPosition(vec2 &set_position);

  /**
   * Add possible move to list
   */
  void UpdatePossibleMoves(vec2 &possible_position);

  /**
   * Empty possible moves list
   */
  void ClearPossibleMoves();
  
  void SetIsPieceKing();

private:
  bool is_piece_red_;
  bool is_piece_king_;
  vec2 current_pos_;
  vector<vec2> possible_moves_;
};
} // namespace checkers
