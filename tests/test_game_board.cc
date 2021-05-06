#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <game_board.h>

TEST_CASE("Test red piece movement diagonally") {
  checkers::GameBoard game_board;
  SECTION("Test possible moves updated") {
    checkers::Square &square = game_board.GetGameBoard()[2][2];
    game_board.SelectNextMove(square);
    vec2 move_one = {3, 3};
    vec2 move_two = {3, 1};
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[0] ==
            move_one);
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[1] ==
            move_two);
  }

  SECTION("Test square updated with piece") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[3][1];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    vec2 new_location = {3, 1};

    REQUIRE(game_board.GetGameBoard()[3][1].GetContainsGamePiece());
    REQUIRE(game_board.GetGameBoard()[3][1].GetPieceIsRedColor());
    REQUIRE(game_board.GetGameBoard()[3][1].GetPieceCurrentPos() ==
            new_location);
  }

  SECTION("Test previous square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[3][1];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[2][2].GetContainsGamePiece());
  }
  SECTION("Test turn changes") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[3][1];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetPlayerTurn());
  }
}

TEST_CASE("Test white piece movement diagonally") {
  checkers::GameBoard game_board;
  checkers::Square &select_first_square = game_board.GetGameBoard()[2][2];
  checkers::Square &move_red_square = game_board.GetGameBoard()[3][1];
  game_board.SelectNextMove(select_first_square);
  game_board.SelectNextMove(move_red_square);
  SECTION("Test possible moves updated") {
    checkers::Square &square = game_board.GetGameBoard()[5][1];
    game_board.SelectNextMove(square);
    vec2 move_one = {4, 2};
    vec2 move_two = {4, 0};
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[0] ==
            move_one);
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[1] ==
            move_two);
  }

  SECTION("Test square updated with piece") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[4][2];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    vec2 new_location = {4, 2};

    REQUIRE(game_board.GetGameBoard()[4][2].GetContainsGamePiece());
    REQUIRE(!game_board.GetGameBoard()[4][2].GetPieceIsRedColor());
    REQUIRE(game_board.GetGameBoard()[4][2].GetPieceCurrentPos() ==
            new_location);
  }

  SECTION("Test previous square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[4][2];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[5][1].GetContainsGamePiece());
  }

  SECTION("Test previous square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[4][2];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(game_board.GetPlayerTurn());
  }
}

TEST_CASE("Test red piece can jump a piece") {
  checkers::GameBoard game_board;
  checkers::GamePiece piece;
  piece.SetIsPieceRed(false);
  vec2 piece_location = {3, 3};
  piece.SetCurrentPosition(piece_location);
  checkers::Square new_square;
  new_square.SetLocation(3, 3);
  new_square.SetSquareColor("black");
  new_square.SetContainsGamePiece(true);
  game_board.GetGameBoard()[3][3] = new_square;
  SECTION("Test possible moves updated") {
    checkers::Square &square = game_board.GetGameBoard()[2][2];
    game_board.SelectNextMove(square);
    vec2 move_one = {3, 3};
    vec2 move_two = {3, 1};
    vec2 move_three = {4, 4};
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[1] ==
            move_three);
  }

  SECTION("Test square updated with piece") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[4][4];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    vec2 new_location = {4, 4};

    REQUIRE(game_board.GetGameBoard()[4][4].GetContainsGamePiece());
    REQUIRE(game_board.GetGameBoard()[4][4].GetPieceIsRedColor());
    REQUIRE(game_board.GetGameBoard()[4][4].GetPieceCurrentPos() ==
            new_location);
  }

  SECTION("Test previous square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[4][4];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[2][2].GetContainsGamePiece());
  }

  SECTION("Test taken piece square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[4][4];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[3][3].GetContainsGamePiece());
  }

  SECTION("Test piece is taken") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[4][4];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);

    REQUIRE(game_board.GetPlayerOne().GetCollectedPieces().size() == 1);
  }

  SECTION("Test turn does not change") {
    checkers::Square &select_square = game_board.GetGameBoard()[2][2];
    checkers::Square &move_square = game_board.GetGameBoard()[4][4];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);

    REQUIRE(game_board.GetPlayerTurn());
  }
}
TEST_CASE("Test white piece can jump a piece") {
  checkers::GameBoard game_board;
  checkers::GamePiece piece;
  piece.SetIsPieceRed(true);
  vec2 piece_location = {4, 2};
  piece.SetCurrentPosition(piece_location);
  checkers::Square new_square;
  new_square.SetLocation(4, 2);
  new_square.SetSquareColor("black");
  new_square.SetContainsGamePiece(true);
  new_square.SetGamePiece(piece);
  game_board.GetGameBoard()[4][2] = new_square;
  checkers::Square &select_first_square = game_board.GetGameBoard()[2][2];
  checkers::Square &move_red_square = game_board.GetGameBoard()[3][1];
  game_board.SelectNextMove(select_first_square);
  game_board.SelectNextMove(move_red_square);
  SECTION("Test possible moves updated") {
    checkers::Square &square = game_board.GetGameBoard()[5][1];
    game_board.SelectNextMove(square);
    vec2 move = {3, 3};
    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[1] == move);
  }

  SECTION("Test square updated with piece") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[3][3];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    vec2 new_location = {3, 3};

    REQUIRE(game_board.GetGameBoard()[3][3].GetContainsGamePiece());
    REQUIRE(!game_board.GetGameBoard()[3][3].GetPieceIsRedColor());
    REQUIRE(game_board.GetGameBoard()[3][3].GetPieceCurrentPos() ==
            new_location);
  }

  SECTION("Test previous square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[3][3];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[5][1].GetContainsGamePiece());
  }

  SECTION("Test taken piece square is cleared") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[3][3];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);
    REQUIRE(!game_board.GetGameBoard()[4][2].GetContainsGamePiece());
  }

  SECTION("Test piece is taken") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[3][3];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);

    REQUIRE(game_board.GetPlayerTwo().GetCollectedPieces().size() == 1);
  }
  SECTION("Test turn does not change") {
    checkers::Square &select_square = game_board.GetGameBoard()[5][1];
    checkers::Square &move_square = game_board.GetGameBoard()[3][3];

    game_board.SelectNextMove(select_square);
    game_board.SelectNextMove(move_square);

    REQUIRE(!game_board.GetPlayerTurn());
  }
}

TEST_CASE("Test red piece cannot move on edges") {
  checkers::GameBoard game_board;

  SECTION("Test cannot move left on edge") {
    checkers::Square &square = game_board.GetGameBoard()[0][0];
    game_board.SelectNextMove(square);

    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves().size() == 0);
  }

  SECTION("Test cannot move back if king") {
    checkers::Square &square = game_board.GetGameBoard()[0][0];
    game_board.SelectNextMove(square);

    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves().size() == 0);
  }

  SECTION("Test cannot move right on right edge") {
    checkers::Square &square = game_board.GetGameBoard()[1][7];
    game_board.SelectNextMove(square);

    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves().size() == 0);
  }
}

TEST_CASE("Test can king red piece") {
  checkers::GameBoard game_board;
  checkers::GamePiece piece;
  piece.SetIsPieceRed(true);
  vec2 piece_location = {6, 2};
  piece.SetCurrentPosition(piece_location);
  checkers::Square new_square;
  new_square.SetLocation(6, 2);
  new_square.SetSquareColor("black");
  new_square.SetContainsGamePiece(true);
  new_square.SetGamePiece(piece);
  game_board.GetGameBoard()[6][2] = new_square;
  game_board.GetGameBoard()[7][1].SetContainsGamePiece(false);
  checkers::Square &select_first_square = game_board.GetGameBoard()[6][2];
  checkers::Square &move_red_square = game_board.GetGameBoard()[7][1];
  game_board.SelectNextMove(select_first_square);
  game_board.SelectNextMove(move_red_square);
  checkers::Square &select_second_square = game_board.GetGameBoard()[5][1];
  checkers::Square &move_white_square = game_board.GetGameBoard()[4][2];
  game_board.SelectNextMove(select_second_square);
  game_board.SelectNextMove(move_white_square);

  SECTION("Test piece is king") {
    checkers::Square &select_square = game_board.GetGameBoard()[7][1];
    game_board.SelectNextMove(select_square);

    REQUIRE(game_board.GetSelectedPiece().GetGamePiece().GetIsPieceKing());
  }
  SECTION("Test king piece possible moves") {
    checkers::Square &select_square = game_board.GetGameBoard()[7][1];
    game_board.SelectNextMove(select_square);

    vec2 move = {6, 2};
    ;

    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[0] == move);
  }
}

TEST_CASE("Test can king white piece") {
  checkers::GameBoard game_board;
  checkers::GamePiece piece;
  piece.SetIsPieceRed(false);
  vec2 piece_location = {1, 1};
  piece.SetCurrentPosition(piece_location);
  checkers::Square new_square;
  new_square.SetLocation(1, 1);
  new_square.SetSquareColor("black");
  new_square.SetContainsGamePiece(true);
  new_square.SetGamePiece(piece);
  game_board.GetGameBoard()[1][1] = new_square;
  game_board.GetGameBoard()[0][2].SetContainsGamePiece(false);
  checkers::Square &select_first_square = game_board.GetGameBoard()[2][2];
  checkers::Square &move_red_square = game_board.GetGameBoard()[3][3];
  game_board.SelectNextMove(select_first_square);
  game_board.SelectNextMove(move_red_square);
  checkers::Square &select_second_square = game_board.GetGameBoard()[1][1];
  checkers::Square &move_white_square = game_board.GetGameBoard()[0][2];
  game_board.SelectNextMove(select_second_square);
  game_board.SelectNextMove(move_white_square);

  SECTION("Test piece is king") {
    checkers::Square &select_square = game_board.GetGameBoard()[0][2];
    game_board.SelectNextMove(select_square);

    REQUIRE(!game_board.GetSelectedPiece().GetGamePiece().GetIsPieceKing());
  }

  SECTION("Test king piece possible moves") {
    checkers::Square &select_square = game_board.GetGameBoard()[0][2];
    game_board.SelectNextMove(select_square);

    vec2 move = {0, 2};
    ;

    REQUIRE(game_board.GetSelectedPiece().GetPiecePossibleMoves()[0] == move);
  }
}