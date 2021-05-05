#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::string;
using std::vector; 
    
namespace checkers {

class GamePiece {
public:
  GamePiece();
  bool GetIsRedColor() const;
  bool GetIsPieceKing() const;
  bool GetCanJumpAgain() const;
  const vector<vec2> GetPossibleMoves() const;
  void SetColor(string set_color);
  void SetIsPieceRed(bool set_is_piece_red_);
  void SetCurrentPosition(vec2& set_position);
  void UpdatePossibleMoves(vec2& possible_position);
  void ClearPossibleMoves();
  void SetIsPieceKing();
  void SetCanJumpAgain();
  
  
private:
  string color_;
  bool can_jump_again_;
  bool is_piece_red_;
  bool is_piece_king_;
  vec2 current_pos_;
  vector<vec2> possible_moves_;
};
}  // namespace checkers
