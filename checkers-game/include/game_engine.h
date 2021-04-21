#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_board.h"

using glm::vec2;

namespace chess {

class GameEngine : public ci::app::App {

public:
  GameEngine();

  void draw() override;
  
  void update() override;

  const int kWindowSize = 1100;
  const int kMargin = 100;

  private:
    GameBoard game_board_;
    
};
}  // namespace chess
