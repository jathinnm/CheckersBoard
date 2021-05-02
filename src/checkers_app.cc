#include <checker_app.h>

namespace checkers {

namespace visualizer {

CheckersApp::CheckersApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kBoardSize,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void CheckersApp::draw() {
  ci::Color8u background_color(150, 75, 0);  // brown
  ci::gl::clear(background_color);
  
  sketchpad_.Draw(game_board_);
  
  ci::gl::drawStringCentered(
      "Welcome to Checkers",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"), ci::Font("Arial", 50.0f) );
  if (game_board_.GetPlayerTurn()) {
    ci::gl::drawStringCentered(
        "Red's Turn",
        glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("Red"),  ci::Font("Arial", 50.0f));
  } else {
    ci::gl::drawStringCentered(
        "White's Turn",
        glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("White"),  ci::Font("Arial", 50.0f));
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

//
//void CheckersApp::mouseDrag(ci::app::MouseEvent event) {
//  sketchpad_.HandleBrush(event.getPos());
//}

//void CheckersApp::keyDown(ci::app::KeyEvent event) {
//  switch (event.getCode()) {
//  case ci::app::KeyEvent::KEY_RETURN:
//    image.SetPixels(sketchpad_.GetPixels());
//    current_prediction_ = classifier.ClassifyImage(trained_model_, image);
//    break;
//
//  case ci::app::KeyEvent::KEY_BACKSPACE:
//    sketchpad_.Clear();
//    break;
//  }
//}
}  // namespace visualizer
}  // namespace checkers