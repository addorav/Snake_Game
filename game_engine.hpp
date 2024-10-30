#pragma once
#include "apple.hpp"
#include "snake.hpp"
#include "board.hpp"
#include "abstract_painter.hpp"

class GameEngine {
   Apple _apple;
   Snake _snake;
   Board _board;
   int _score;
   int _speed;
   static const int MAX_TIME_MS = 100000;
   static const int DELTA_MS = 100;


public:
   GameEngine();
   void Init();
   void Run();
private:
   bool SnakeKnocksWall() const;
   bool GameOver() const;
   char GetEvent() const;
   void UpdateScreen() const;
   void UpdateStatus() const;

   void DrawBoard(const AbstractPainter& painter) const;
};