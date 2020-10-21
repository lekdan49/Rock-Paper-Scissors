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
		g.comp_move();

		cout << "You played: " << text_move(p.move()) << '\n';
		cout << "Computer Played: " << text_move(g.move()) << '\n';

		if (p.move() == g.move())
		{
			cout << "DRAW! " << '\n';
		}
		else if (outcome(p.move(), g.move()))
		{
			cout << "YOU WIN!" << '\n';
			p.increment_score(1);
		}
		else
		{
			cout << "YOU LOSE!" << '\n';
			g.increment_score(1);
		}
		g.game_end(cout, p.increment_score(0));
	} while (true);

	return 0;
}