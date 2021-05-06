#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace checkers {

namespace visualizer {
using glm::vec2;
class CheckersApp : public ci::app::App {

public:
  CheckersApp();
  /**
   * Draw whole window including background, header, and game board
   */
  void draw() override;

  /**
   * Handles players clicks on board to select
   * @param event
   */
  void mouseDown(ci::app::MouseEvent event) override;

  const double kWindowSize = 1000;
  const double kMargin = 150;
  const size_t kBoardSize = 8;
  const size_t kHeaderHeight = 100;

private:
  Sketchpad sketchpad_;
  GameBoard game_board_;
};
} // namespace visualizer
} // namespace checkers
