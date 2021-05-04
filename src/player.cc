#include <player.h>

void checkers::Player::SetIsPlayerOne(bool set_is_player_one) {
  is_player_one_ = set_is_player_one;
}
void checkers::Player::UpdateCollectedPieces(GamePiece game_piece) {
  collected_pieces_.emplace_back(game_piece);
}
vector<checkers::GamePiece> checkers::Player::GetCollectedPieces() {
  return collected_pieces_;
}
