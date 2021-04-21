#include <square.h>
void chess::Square::SetSquareColor(string set_color) {
  color_ = set_color;
}

void chess::Square::SetGamePiece(chess::GamePiece &set_piece) {
  piece_ = set_piece;
}
