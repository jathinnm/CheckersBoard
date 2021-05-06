#include <checker_app.h>

namespace checkers {

namespace visualizer {

CheckersApp::CheckersApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kBoardSize,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}

void CheckersApp::draw() {
  ci::Color8u background_color(150, 75, 0); // brown
  ci::gl::clear(background_color);

  sketchpad_.Draw(game_board_);

  ci::gl::color(0, 0, 0);
  ci::gl::drawSolidRect(ci::Rectf(0, 0, kWindowSize, kHeaderHeight));
  ci::gl::drawStringCentered(kTitle, glm::vec2(kWindowSize / 2, kMargin / 2.5),
                             ci::Color("white"), ci::Font("Arial", 40.0f));
  ci::gl::drawStringCentered(
      kP1ScoreLabel,
      glm::vec2(kWindowSize - (kWindowSize - 100), kMargin / 2.5),
      ci::Color("white"), ci::Font("Arial", 40.0f));

  ci::gl::drawStringCentered(
      std::to_string(game_board_.GetPlayerOne().GetCollectedPieces().size()),
      glm::vec2(kWindowSize - (kWindowSize - 210), kMargin / 2.5),
      ci::Color("white"), ci::Font("Arial", 40.0f));

  ci::gl::drawStringCentered(kP2ScoreLabel,
                             glm::vec2(kWindowSize / 1.15, kMargin / 2.5),
                             ci::Color("white"), ci::Font("Arial", 40.0f));

  ci::gl::drawStringCentered(
      std::to_string(game_board_.GetPlayerTwo().GetCollectedPieces().size()),
      glm::vec2(kWindowSize - 20, kMargin / 2.5), ci::Color("white"),
      ci::Font("Arial", 40.0f));
  if (game_board_.GetPlayerTurn()) {
    ci::gl::drawStringCentered(
        kRedTurnLabel, glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2),
        ci::Color("Red"), ci::Font("Arial", 50.0f));
  } else {
    ci::gl::drawStringCentered(
        kWhiteTurnLabel, glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2),
        ci::Color("White"), ci::Font("Arial", 50.0f));
  }
}

void CheckersApp::mouseDown(ci::app::MouseEvent event) {
  bool is_square_found = false;
  for (size_t row = 0; row <= kBoardSize; row++) {
    for (size_t col = 0; col <= kBoardSize; col++) {
      vec2 x_lim = game_board_.GetGameBoard()[row][col].GetXLim();
      vec2 y_lim = game_board_.GetGameBoard()[row][col].GetYLim();
      if (event.getPos().x > x_lim.x && event.getPos().x < x_lim.y) {
        if (event.getPos().y < y_lim.x && event.getPos().y > y_lim.y) {
          game_board_.SelectNextMove(game_board_.GetGameBoard()[row][col]);
          is_square_found = true;
          break;
        }
      }
    }
    if (is_square_found) {
      break;
    }
  }
}
} // namespace visualizer
} // namespace checkers
