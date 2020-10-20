#include "Player.h"

string text_move(const Move &mv)
{
	switch (mv)
	{
	case Move::Rock:
		return "Rock";
	case Move::Paper:
		return "Paper";
	case Move::Scissors:
		return "Scissors";
	default:
		return "Not in Enum";
	}
}

int main()
{
	Player p;
	Game g;
	do
	{
		g.game_start(cout);
		p.get_move(cin);
		g.random_move();
		cout << "You played: " << text_move(p.move()) << '\n';
		cout << "Computer Played: " << text_move(g.move()) << '\n';
		if (outcome(p.move(), g.move()))
		{

		}
	} while (true);

	return 0;
}