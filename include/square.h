#pragma once
#include "game_piece.h"

using std::vector;
using glm::vec2;

namespace checkers {

class Square {
public:
  std::string GetSquareColor() const;
  const vec2& GetLocation() const;
  bool GetContainsGamePiece() const;
  bool GetPieceIsRedColor() const;
  GamePiece GetGamePiece() const;
  vec2 GetXLim() const;
  vec2 GetYLim() const;
  const vector<vec2> GetPiecePossibleMoves() const;
  void UpdateGamePieceMoves(vec2& possible_move); 
  void SetContainsGamePiece(bool set_contains_piece);
  void SetSquareColor(std::string set_color);
  void SetGamePiece(GamePiece set_piece);
  void SetLocation(size_t row, size_t col);
  void SetSquareLimits(vec2& set_x_lim, vec2& set_y_lim);
  void SetPieceLocation(vec2& location);
  void ClearPossibleMoves();
  void SetIsPieceKing();
  void ToggleCanJumpAgain();

private:
  std::string color_;
  GamePiece piece_;
  vec2 location_;
  vec2 x_lim_;
  vec2 y_lim_;
  bool contains_game_piece_;
};
}  // namespace checkers
