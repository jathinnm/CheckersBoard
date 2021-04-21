#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::string;
using std::vector; 
    
namespace chess {

class GamePiece {
public:
  void SetColor(string set_color);
  void SetCurrentPosition(vec2& set_position);
private:
  string color_;
  vec2 current_pos_;
  vector<vec2> possible_moves_;
};
}  // namespace idealgas
