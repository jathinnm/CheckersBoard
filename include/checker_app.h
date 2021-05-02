#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace checkers {

namespace visualizer {

class CheckersApp : public ci::app::App {
  
public:
  CheckersApp();
  
  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;

//  void mouseDrag(ci::app::MouseEvent event) override;
//  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 1000;
  const double kMargin = 100;
  const size_t kBoardSize = 8;

private:
  Sketchpad sketchpad_;
  GameBoard game_board_;
};

} // namespace visualizer

} // namespace naivebayes
