#include <game_piece.h>

void checkers::GamePiece::SetColor(string set_color) {
  color_ = set_color;
}

void checkers::GamePiece::SetCurrentPosition(vec2& set_position) {
  current_pos_.x = set_position.x;
  current_pos_.y = set_position.y;
}

void checkers::GamePiece::UpdatePossibleMoves(vec2& possible_move) {
  possible_moves_.emplace_back(possible_move);
}

void checkers::GamePiece::SetIsPieceRed(bool set_is_piece_red_) {
  is_piece_red_ = set_is_piece_red_;
}

bool checkers::GamePiece::GetIsRedColor() const {return is_piece_red_;}

const vector<vec2> checkers::GamePiece::GetPossibleMoves() const {
  return possible_moves_;
}

void checkers::GamePiece::ClearPossibleMoves() {
  possible_moves_.clear();
}
