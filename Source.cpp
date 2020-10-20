#include "Player.h"

int main()
{
	Player p1;
	p1.get_move(cin);
	cout << static_cast<unsigned short>(p1.move()) << '\n';
	return 0;
}