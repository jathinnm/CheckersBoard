#include <game_piece.h>
void chess::GamePiece::SetColor(string set_color) {
  color_ = set_color;
}

void chess::GamePiece::SetCurrentPosition(vec2& set_position) {
  current_pos_ = set_position;
}
