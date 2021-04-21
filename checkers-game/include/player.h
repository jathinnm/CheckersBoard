#pragma once
#include "game_board.h"

using std::vector;

namespace chess {

class Player {

public:
 void SetIsPlayerOne(bool set_is_player_one);
private:
  vector<GamePiece> collected_pieces_;
  bool is_player_one_;
  
};
}  // namespace idealgas
