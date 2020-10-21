#include "Player.h"
#include <time.h>

istream &Player::get_move(istream &is)
{
	unsigned short mv;
	is >> mv;
	current_move = static_cast<Move>(mv);
	return is;
}

ostream &Game::game_start(ostream &os) const
{
	os << "Rock Paper Scissors\n" << "Coded by Dan\n"
		<< "1. Rock\n" << "2. Paper\n" << "3. Scissors\n";
	return os;
}

ostream &Game::game_end(ostream &os, const int &player_score) const
{
	os << "Player Score: " << player_score << '\n'
		<< "Computer Score: " << score << '\n';
	return os;
}

Move Game::comp_move() // probably should use hardware random gen
{
	srand(time(nullptr)); // initialize random seed
	ai_move = static_cast<Move>(rand() % 3 + 1);
	return ai_move;
}

bool outcome(const Move &m1, const Move &m2) // i don't like this, it looks ugly
{
	if (m1 == Move::Rock)
	{
		if (m2 == Move::Paper)
			return false;
		if (m2 == Move::Scissors)
			return true;
	}
	if (m1 == Move::Paper)
	{
		if (m2 == Move::Scissors)
			return false;
		if (m2 == Move::Rock)
			return true;
	}
	if (m1 == Move::Scissors)
	{
		if (m2 == Move::Rock)
			return false;
		if (m2 == Move::Paper)
			return true;
	}
	return true;
}