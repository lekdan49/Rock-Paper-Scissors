#include "Player.h"

istream &Player::get_move(istream &is)
{
	unsigned short mv;
	is >> mv;
	current_move = static_cast<Move>(mv);
	return is;
}