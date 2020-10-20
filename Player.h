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

bool outcome(const Move &m1, const Move &m2);

class Game {
public:
	// constructors
	Game() = default;

	// methods
	ostream &game_start(ostream &os) const;
	ostream &game_end(ostream &os) const;
	Move random_move();
	Move move() const { return ai_move; }
	void increment() { score++; }

private:
	Move ai_move{ Move::None };
	int score{ 0 };
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
	int score() const { return player_score; }


private:
	int player_score{ 0 };
	Move current_move{ Move::None };
};

