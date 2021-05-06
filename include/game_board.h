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
  /**
   * Initialize game board  with proper size, squares, and pieces with the right
   * locations and colors
   */
  GameBoard();

  /**
   * Handle finding possible moves and determining if piece can move to square
   * @param square The square usere selected
   */
  void SelectNextMove(Square &square);

  /**
   * Move the selected piece to the square.
   * @param square The square user wants to move to.
   */
  void MoveToSquare(Square &square);

  vector<vector<Square>> &GetGameBoard();

  Player GetPlayerOne() const;

  Player GetPlayerTwo() const;

  bool GetPlayerTurn() const;

  bool GetIsPieceSelected() const;

  Square GetSelectedPiece() const;

private:
  const size_t kBoardSize = 8;
  const size_t kMoveIncrement = 1;
  const size_t kJumpDifference = 2;
  const std::string kPieceSquareColor = "black";
  const std::string kAltSquareColor = "white";
  vector<vector<Square>> squares_;
  bool is_player_one_turn_;
  bool is_piece_selected_;
  Player player_one_;
  Player player_two_;
  Square selected_piece_;

  /**
   * Checks if red piece can move one square diagonally and updates list
   * @param square The piece the user selected
   */
  void UpdateRedDiagonalPos(Square &square);

  /**
   * Checks if white piece can move one square diagonally and updates list
   * @param square The piece the user selected
   */
  void UpdateWhiteDiagPos(Square &square);

  /**
   * Checks if red piece can jump a piece and updates possible moves
   * @param square The piece the user selected
   */
  void UpdateRedJumpPos(Square &square, size_t recur_case);

  /**
   * Checks if white piece can jump a piece and updates possible moves
   * @param square The piece the user selected
   */
  void UpdateWhiteJumpPos(Square &square, size_t recur_case);

  /**
   * Clear the square of the piece user moved
   * @param square The square user wants to clear
   */
  void ClearSquare(Square &square);

  /**
   * Adds the piece to respective players score
   * @param square The square user is trying to move to
   * @param increment The difference of the square moved to and the square of
   * the captured piece
   */
  void TakePiece(Square &square, vec2 &increment);

  /**
   * Checks if a jump made is on that can capture a piece
   * @param square
   */
  void CheckTakePiece(Square &square);

  /**
   * Turns a piece into a king piece
   * @param square
   */
  void UpdateKingPiece(Square &square);
};
} // namespace checkers
