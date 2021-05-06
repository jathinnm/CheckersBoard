#include <square.h>
namespace checkers {

void checkers::Square::SetSquareColor(string set_color) { color_ = set_color; }

void checkers::Square::SetGamePiece(GamePiece set_piece) { piece_ = set_piece; }

void checkers::Square::SetLocation(size_t row, size_t col) {
  location_.x = row;
  location_.y = col;
}

void checkers::Square::SetContainsGamePiece(bool set_contains_piece) {
  contains_game_piece_ = set_contains_piece;
}

std::string checkers::Square::GetSquareColor() const { return color_; }

const vec2 &checkers::Square::GetLocation() const { return location_; }

bool checkers::Square::GetContainsGamePiece() const {
  return contains_game_piece_;
}

void checkers::Square::UpdateGamePieceMoves(vec2 &possible_move) {
  piece_.UpdatePossibleMoves(possible_move);
}

bool checkers::Square::GetPieceIsRedColor() const {
  return piece_.GetIsRedColor();
}

const vector<vec2> checkers::Square::GetPiecePossibleMoves() const {
  return piece_.GetPossibleMoves();
}

checkers::GamePiece checkers::Square::GetGamePiece() const { return piece_; }

void Square::SetSquareLimits(vec2 &set_x_lim, vec2 &set_y_lim) {
  x_lim_.x = set_x_lim.x;
  x_lim_.y = set_x_lim.y;
  y_lim_.x = set_y_lim.x;
  y_lim_.y = set_y_lim.y;
}

vec2 Square::GetXLim() const { return x_lim_; }
vec2 Square::GetYLim() const { return y_lim_; }
void Square::SetPieceLocation(vec2 &location) {
  piece_.SetCurrentPosition(location);
}
void Square::ClearPossibleMoves() { piece_.ClearPossibleMoves(); }
void Square::SetIsPieceKing() { piece_.SetIsPieceKing(); }

void Square::ToggleCanJumpAgain() { piece_.SetCanJumpAgain(); }

vec2 Square::GetPieceCurrentPos() const { return piece_.GetCurrentPosition(); }

} // namespace checkers