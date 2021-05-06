#include <game_board.h>

namespace checkers {

GameBoard::GameBoard() {
  is_player_one_turn_ = true;
  is_piece_selected_ = false;
  player_one_.SetIsPlayerOne(true);
  player_two_.SetIsPlayerOne(false);
  Square square;
  squares_ =
      vector<vector<Square>>(kBoardSize, vector<Square>(kBoardSize, square));
  for (size_t row = 1; row <= kBoardSize; row++) {
    for (size_t col = 1; col <= kBoardSize; col++) {
      squares_[row - 1][col - 1].SetLocation(row - 1, col - 1);
      squares_[row - 1][col - 1].SetContainsGamePiece(false);
      squares_[row - 1][col - 1].SetSquareColor(kAltSquareColor);
      if (row < 4) {
        if (row % 2 != 0 && col % 2 != 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
          GamePiece piece;
          vec2 pos = {row - 1, col - 1};
          piece.SetCurrentPosition(pos);
          piece.SetIsPieceRed(true);
          squares_[row - 1][col - 1].SetGamePiece(piece);
          squares_[row - 1][col - 1].SetContainsGamePiece(true);
        } else if (row % 2 == 0 && col % 2 == 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
          GamePiece piece;
          vec2 pos = {row - 1, col - 1};
          piece.SetCurrentPosition(pos);
          piece.SetIsPieceRed(true);
          squares_[row - 1][col - 1].SetGamePiece(piece);
          squares_[row - 1][col - 1].SetContainsGamePiece(true);
        }
      } else if (row > 5) {
        if (row % 2 != 0 && col % 2 != 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
          GamePiece piece;
          vec2 pos = {row - 1, col - 1};
          piece.SetCurrentPosition(pos);
          piece.SetIsPieceRed(false);
          squares_[row - 1][col - 1].SetGamePiece(piece);
          squares_[row - 1][col - 1].SetContainsGamePiece(true);
        } else if (row % 2 == 0 && col % 2 == 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
          GamePiece piece;
          vec2 pos = {row - 1, col - 1};
          piece.SetCurrentPosition(pos);
          piece.SetIsPieceRed(false);
          squares_[row - 1][col - 1].SetGamePiece(piece);
          squares_[row - 1][col - 1].SetContainsGamePiece(true);
        }
      } else {
        if (row % 2 != 0 && col % 2 != 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
        } else if (row % 2 == 0 && col % 2 == 0) {
          squares_[row - 1][col - 1].SetSquareColor(kPieceSquareColor);
        }
      }
    }
  }
}

void checkers::GameBoard::SelectNextMove(Square &square) {
  // check if a piece has already been selected or not
  if (!is_piece_selected_) {
    // Check if selected square contains a piece
    if (square.GetContainsGamePiece()) {
      // check if the player selected right piece
      if (is_player_one_turn_ == square.GetPieceIsRedColor()) {
        selected_piece_ = square;
        is_piece_selected_ = true;
        if (selected_piece_.GetPieceIsRedColor()) {
          if (selected_piece_.GetGamePiece().GetIsPieceKing()) {
            UpdateWhiteDiagPos(square);
            UpdateWhiteJumpPos(square, 1);
          }
          UpdateRedDiagonalPos(square);
          UpdateRedJumpPos(square, 1);
        } else {
          if (selected_piece_.GetGamePiece().GetIsPieceKing()) {
            UpdateRedDiagonalPos(square);
            UpdateRedJumpPos(square, 1);
          }
          UpdateWhiteDiagPos(square);
          UpdateWhiteJumpPos(square, 1);
        }
      }
    }
  } else {
    for (size_t i = 0; i < selected_piece_.GetPiecePossibleMoves().size();
         i++) {
      if (square.GetLocation() == selected_piece_.GetPiecePossibleMoves()[i]) {
        MoveToSquare(square);
        break;
      }
    }
    is_piece_selected_ = false;
  }
}

void checkers::GameBoard::MoveToSquare(Square &square) {
  // Clear Game Piece from previous square
  ClearSquare(square);

  // Capturing a piece
  CheckTakePiece(square);
  // CheckTakeDoublePiece(square);

  // Move Game Piece
  selected_piece_.SetLocation(square.GetLocation().x, square.GetLocation().y);
  selected_piece_.SetPieceLocation(const_cast<vec2 &>(square.GetLocation()));
  squares_[square.GetLocation().x][square.GetLocation().y] = selected_piece_;
  squares_[square.GetLocation().x][square.GetLocation().y].ClearPossibleMoves();

  UpdateKingPiece(square);

  // Switch booleans
  is_piece_selected_ = false;
  is_player_one_turn_ = !is_player_one_turn_;
}

void GameBoard::UpdateRedDiagonalPos(Square &square) {
  vec2 location = square.GetLocation();
  if (location.x != kBoardSize - 1 && location.y != kBoardSize - 1) {
    if (!(squares_[location.x + 1][location.y + 1].GetContainsGamePiece())) {
      vec2 move = {location.x + 1, location.y + 1};
      selected_piece_.UpdateGamePieceMoves(move);
    }
  }

  if (location.x != kBoardSize - 1 && location.y != 0) {
    if (!(squares_[location.x + 1][location.y - 1].GetContainsGamePiece())) {
      vec2 move = {location.x + 1, location.y - 1};
      selected_piece_.UpdateGamePieceMoves(move);
    }
  }
}

void GameBoard::UpdateWhiteDiagPos(Square &square) {
  vec2 location = square.GetLocation();
  if (location.x != 0 && location.y != kBoardSize - 1) {
    if (!(squares_[location.x - 1][location.y + 1].GetContainsGamePiece())) {
      vec2 move = {location.x - 1, location.y + 1};
      selected_piece_.UpdateGamePieceMoves(move);
    }
  }

  if (location.x != 0 && location.y != 0) {
    if (!(squares_[location.x - 1][location.y - 1].GetContainsGamePiece())) {
      vec2 move = {location.x - 1, location.y - 1};
      selected_piece_.UpdateGamePieceMoves(move);
    }
  }
}

void GameBoard::UpdateRedJumpPos(Square &square, size_t recur_case) {
  vec2 location = square.GetLocation();
  if (location.x < kBoardSize - 2 && location.y < kBoardSize - 2) {
    if (squares_[location.x + 1][location.y + 1].GetContainsGamePiece() &&
        squares_[location.x + 1][location.y + 1].GetPieceIsRedColor() !=
            is_player_one_turn_) {
      // Check if the diagonal immediately after is empty
      if (!(squares_[location.x + 2][location.y + 2].GetContainsGamePiece())) {
        vec2 move = {location.x + 2, location.y + 2};
        selected_piece_.UpdateGamePieceMoves(move);
        if (recur_case != 0) {
          UpdateRedJumpPos(squares_[move.x][move.y], recur_case - 1);
        }
      }
    }
  }

  if (location.x < kBoardSize - 2 && location.y > 1) {
    if (squares_[location.x + 1][location.y - 1].GetContainsGamePiece() &&
        squares_[location.x + 1][location.y - 1].GetPieceIsRedColor() !=
            is_player_one_turn_) {
      // Check if the diagonal immediately after is empty
      if (!(squares_[location.x + 2][location.y - 2].GetContainsGamePiece())) {
        vec2 move = {location.x + 2, location.y - 2};
        selected_piece_.UpdateGamePieceMoves(move);
        if (recur_case != 0) {
          UpdateRedJumpPos(squares_[move.x][move.y], recur_case - 1);
        }
      }
    }
  }
}

void GameBoard::UpdateWhiteJumpPos(Square &square, size_t recur_case) {
  vec2 location = square.GetLocation();
  if (location.x > 1 && location.y < kBoardSize - 2) {
    if (squares_[location.x - 1][location.y + 1].GetContainsGamePiece() &&
        squares_[location.x - 1][location.y + 1].GetPieceIsRedColor() !=
            is_player_one_turn_) {
      // Check if the diagonal immediately after is empty
      if (!(squares_[location.x - 2][location.y + 2].GetContainsGamePiece())) {
        vec2 move = {location.x - 2, location.y + 2};
        selected_piece_.UpdateGamePieceMoves(move);
        if (recur_case != 0) {
          UpdateWhiteJumpPos(squares_[move.x][move.y], recur_case - 1);
        }
      }
    }
  }

  if (location.x > 1 && location.y > 1) {
    if (squares_[location.x - 1][location.y - 1].GetContainsGamePiece() &&
        squares_[location.x - 1][location.y - 1].GetPieceIsRedColor() !=
            is_player_one_turn_) {
      // Check if the diagonal immediately after is empty
      if (!(squares_[location.x - 2][location.y - 2].GetContainsGamePiece())) {
        vec2 move = {location.x - 2, location.y - 2};
        selected_piece_.UpdateGamePieceMoves(move);
        if (recur_case != 0) {
          UpdateWhiteJumpPos(squares_[move.x][move.y], recur_case - 1);
        }
      }
    }
  }
}

void GameBoard::ClearSquare(Square &square) {
  Square new_square;
  new_square.SetSquareColor(selected_piece_.GetSquareColor());
  new_square.SetLocation(selected_piece_.GetLocation().x,
                         selected_piece_.GetLocation().y);
  squares_[selected_piece_.GetLocation().x][selected_piece_.GetLocation().y] =
      new_square;
}

void GameBoard::CheckTakePiece(Square &square) {
  if (square.GetLocation().x - selected_piece_.GetLocation().x == 2 &&
      square.GetLocation().y - selected_piece_.GetLocation().y == 2) {
    vec2 increment = {-1, -1};
    TakePiece(square, increment);
  } else if (square.GetLocation().x - selected_piece_.GetLocation().x == 2 &&
             square.GetLocation().y - selected_piece_.GetLocation().y == -2) {
    vec2 increment = {-1, 1};
    TakePiece(square, increment);
  } else if (square.GetLocation().x - selected_piece_.GetLocation().x == -2 &&
             square.GetLocation().y - selected_piece_.GetLocation().y == 2) {
    vec2 increment = {1, -1};
    TakePiece(square, increment);
  } else if (square.GetLocation().x - selected_piece_.GetLocation().x == -2 &&
             square.GetLocation().y - selected_piece_.GetLocation().y == -2) {
    vec2 increment = {1, 1};
    TakePiece(square, increment);
  }
}

void GameBoard::TakePiece(Square &square, vec2 &increment) {
  Square blank_square;
  vec2 new_location = squares_[square.GetLocation().x + increment.x]
                              [square.GetLocation().y + increment.y]
                                  .GetLocation();
  blank_square.SetLocation(new_location.x, new_location.y);
  blank_square.SetSquareColor(squares_[square.GetLocation().x + increment.x]
                                      [square.GetLocation().y + increment.y]
                                          .GetSquareColor());
  if (is_player_one_turn_) {
    player_one_.UpdateCollectedPieces(
        squares_[square.GetLocation().x + increment.x]
                [square.GetLocation().y + increment.y]
                    .GetGamePiece());
  } else {
    player_two_.UpdateCollectedPieces(
        squares_[square.GetLocation().x + increment.x]
                [square.GetLocation().y + increment.y]
                    .GetGamePiece());
  }
  squares_[square.GetLocation().x + increment.x]
          [square.GetLocation().y + increment.y] = blank_square;
  is_player_one_turn_ = !is_player_one_turn_;
}

void checkers::GameBoard::UpdateKingPiece(Square &square) {
  if (is_player_one_turn_) {
    if (square.GetLocation().x == kBoardSize - 1) {
      squares_[square.GetLocation().x][square.GetLocation().y].SetIsPieceKing();
    }
  } else {
    if (square.GetLocation().x == 0) {
      squares_[square.GetLocation().x][square.GetLocation().y].SetIsPieceKing();
    }
  }
}

vector<vector<Square>> &GameBoard::GetGameBoard() { return squares_; }

bool GameBoard::GetPlayerTurn() const { return is_player_one_turn_; }

Player GameBoard::GetPlayerOne() const { return player_one_; }

Player GameBoard::GetPlayerTwo() const { return player_two_; }

bool GameBoard::GetIsPieceSelected() const { return is_piece_selected_; }

Square GameBoard::GetSelectedPiece() const { return selected_piece_; }

} // namespace checkers
