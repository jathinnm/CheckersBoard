#include <checker_app.h>

using checkers::visualizer::CheckersApp;

void prepareSettings(CheckersApp::Settings *settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(CheckersApp, ci::app::RendererGl, prepareSettings);
