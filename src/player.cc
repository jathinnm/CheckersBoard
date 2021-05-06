#include <player.h>

void checkers::Player::UpdateCollectedPieces(GamePiece game_piece) {
  collected_pieces_.emplace_back(game_piece);
}

vector<checkers::GamePiece> checkers::Player::GetCollectedPieces() {
  return collected_pieces_;
}
