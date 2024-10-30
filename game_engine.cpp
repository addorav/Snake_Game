#include <iostream>
#include <thread>

#include <windows.h>

#include "game_engine.hpp"
#include "painter.hpp"

GameEngine::GameEngine()
    : _score{0}, _speed{0}
{}

void GameEngine::Init()
{
    _board = Board(40, 20);
    _apple = Apple(_board.GetRandomPosition());
    _snake = Snake(_board.GetRandomPosition());
}

void GameEngine::Run()
{
    Direction direction = Direction::Right;
    while (!GameOver())
    {
        char event = GetEvent();
        switch (event)
        {
        case 'w':
            direction = Direction::Top;
            break;
        case 's':
            direction = Direction::Bottom;
            break;
        case 'a':
            direction = Direction::Left;
            break;
        case 'd':
            direction = Direction::Right;
            break;
        case 'q':
            return;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(MAX_TIME_MS - _speed * DELTA_MS));
        auto oops = _snake.GetTail();
        _snake.Move(direction);
        if (_snake.GetHead() == _apple.GetPosition())
        {
            _snake.Eat(_apple);
            _apple = Apple(_board.GetRandomPosition());
            _score += 10;
            ++_speed;
        }

        UpdateScreen();
        UpdateStatus();
        std::cout << std::endl;
    }
}

bool GameEngine::SnakeKnocksWall() const
{
    Point head = _snake.GetHead();
    return head.x < 0 || head.x >= _board.GetWidth() ||
        head.y < 0 || head.y >= _board.GetHeight();
}

bool GameEngine::GameOver() const
{
    return SnakeKnocksWall() || _snake.IsEatingItself();
}

char GameEngine::GetEvent() const
{
    if (
        (GetAsyncKeyState(VK_UP) & 0x8000) ||
        (GetAsyncKeyState('W') & 0x8000) ||
        (GetAsyncKeyState('w') & 0x8000))
    {
        return 'w';
    }
    if (
        (GetAsyncKeyState(VK_DOWN) & 0x8000) ||
        (GetAsyncKeyState('S') & 0x8000) ||
        (GetAsyncKeyState('s') & 0x8000))
    {
        return 's';
    }
    if (
        (GetAsyncKeyState(VK_LEFT) & 0x8000) ||
        (GetAsyncKeyState('A') & 0x8000) ||
        (GetAsyncKeyState('a') & 0x8000))
    {
        return 'a';
    }
    if (
        (GetAsyncKeyState(VK_RIGHT) & 0x8000) ||
        (GetAsyncKeyState('D') & 0x8000) ||
        (GetAsyncKeyState('d') & 0x8000))
    {
        return 'd';
    }
    if (
        (GetAsyncKeyState(VK_ESCAPE) & 0x8000) ||
        (GetAsyncKeyState('Q') & 0x8000) ||
        (GetAsyncKeyState('q') & 0x8000))
    {
        return 'q';
    }

    return ' ';
}

void GameEngine::UpdateScreen() const
{
    Painter painter;
    DrawBoard(painter);
}

void GameEngine::UpdateStatus() const
{
    Painter painter;
    painter.WriteText({1, _board.GetHeight() + 3}, "Score: " + std::to_string(_score));
}

void GameEngine::DrawBoard(const AbstractPainter &painter) const
{
    std::vector<std::string> img;

    img.insert(
        img.end(), 
        "+" + std::string(_board.GetWidth(), '-') + "+"
    );
    img.insert(
        img.end(), 
        _board.GetHeight(), 
        std::string("|") + std::string(_board.GetWidth(), ' ') + std::string("|")
    );
    img.insert(
        img.end(), 
        "+" + std::string(_board.GetWidth(), '-') + "+"
    );

    for (auto point : _snake.GetSegments())
    {
        img[point.y + 1][point.x + 1] = 'o';
    }

    img[_apple.GetPosition().y + 1][_apple.GetPosition().x + 1] = '@';
    Point topLeft = {1, 1};
    Point bottomRight = {_board.GetWidth(), _board.GetHeight()};

    painter.DrawImage(
        topLeft,
        bottomRight,
        img);
}