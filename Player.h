#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::istream;
using std::ostream;

enum class Move // enum class is better than plain enum
{
	None,
	Rock,
	Paper,
	Scissors
};

class Player
{
public:
	// contructors
	Player() = default;
	Player(const Move &c_m) : current_move(c_m) {}

	//methods
	istream &get_move(istream &is);
	Move move() const { return current_move; }
	int score() const { return current_score; }

private:
	int current_score{ 0 };
	Move current_move{ Move::None };
};

class Game {
public:
	Game() = default;

private:
	Move ai_move{ Move::None };
};