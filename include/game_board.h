#pragma once

#include "cinder/gl/gl.h"
#include "game_piece.h"
#include "player.h"
#include "square.h"

using glm::vec2;
using std::vector;

namespace checkers {
class GameBoard {
public:
  GameBoard();

  void SelectNextMove(Square& square);

  void MoveToSquare(Square& square);

  vector<vector<Square>> &GetGameBoard();
  
  Player GetPlayerOne() const; 
  
  Player GetPlayerTwo() const;
  
  bool GetPlayerTurn() const;
  
  bool GetIsPieceSelected() const;
  
  Square GetSelectedPiece() const;


private:
  const size_t kBoardSize = 8;
  const vec2 kLeftUpMove = {-1, 1};
  const vec2 kRightUpMove = {1, 1};
//  const vec2 kRightDownMove = {1, -1};
//  const vec2 kLeftDownMove = {-1, -1};
  vector<vector<Square>> squares_;
  bool can_jump_again_;
  bool is_player_one_turn_;
  bool is_piece_selected_;
  Player player_one_;
  Player player_two_;
  Square selected_piece_;
  
  void UpdateRedDiagonalPos(Square& square);
  void UpdateWhiteDiagPos(Square& square);
  void UpdateRedJumpPos(Square& square);
  void UpdateWhiteJumpPos(Square& square);
  void UpdateWhiteDoubleJumpPos(Square& square);
  void ClearSquare(Square& square);
  void TakePiece(Square& square, vec2& increment);
  void CheckTakePiece(Square& square);
  void UpdateKingPiece(Square& square);
};
} // namespace checkers
