#include <game_board.h>

namespace chess {
GameBoard::GameBoard() {
  is_player_one_turn_ = true;
  player_one_.SetIsPlayerOne(true);
  player_two_.SetIsPlayerOne(false);
  Square square;
  game_board_ =
      vector<vector<Square>>(kBoardSize, vector<Square>(kBoardSize, square));
  for (size_t row = 1; row <= kBoardSize; row++) {
    for (size_t col = 1; col <= kBoardSize; col++) {
      if (row < 4 || row > 5) {
        if (row % 2 != 0) {
          game_board_[row][col].SetSquareColor("brown");
          if (col % 2 != 0) {
            GamePiece piece;
            vec2 pos = {row, col};
            piece.SetCurrentPosition(pos);
            piece.SetColor("red");
            square.SetGamePiece(piece);
          }
        } else if (row % 2 == 0) {
          game_board_[row][col].SetSquareColor("white");
          if (col % 2 == 0) {
            GamePiece piece;
            vec2 pos = {row, col};
            piece.SetCurrentPosition(pos);
            piece.SetColor("black");
            square.SetGamePiece(piece);
          }
        }
      }
    }
  }
}

void chess::GameBoard::SelectNextMove(Square &square) {
  // TODO: Check to see if player clicked their own piece by using bool value;
  // TODO: If the piece is not selected, find the possible places to move from
  // that selected piece and update selected_square member. Also update bool to
  // true;
  // TODO: If piece is selected and player clicks on square that is a
  // possible square to move, call MoveToSquare, and pass in the square player
  // wants to move to.
  // */
}
void chess::GameBoard::MoveToSquare() {
  // TODO: Clear game piece from selected square member, add piece to the passed
  // in square parameter, change bool to false.
}

void chess::GameBoard::UpdatePossiblePositions() {
  // TODO: Check which directions are free to move
  // TODO: Check if player can take a piece
  // TODO: Check if player can double jump
}

} // namespace chess
