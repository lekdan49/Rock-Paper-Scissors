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

Move Game::random_move() // probably should use hardware random gen
{
	srand(time(nullptr)); // initialize random seed
	ai_move = static_cast<Move>(rand() % 3 + 1);
	return ai_move;
}

bool outcome(const Move &m1, const Move &m2) // i don't like this, it looks ugly but who cares
{
	if (m1 == m2)
	{
		return false;
	}
	if (m1 == Move::Rock && m2 == Move::Paper)
	{
		return false;
	}

	return true;
}