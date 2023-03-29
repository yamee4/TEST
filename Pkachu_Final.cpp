#include"struct.h"
#include"console.h"
#include"Normal.h"
#include "Menu.h"
using namespace std;

int main()
{
	initWindow(1000, 500);
	int status;
	player p;
	while ((status = Menu()) != 3)
	{
		switch (status) 
		{
		case 0:
			initNormalMode(p);
			break;

		case 1:
			cout << "Difficult mode" << endl;
			break;

		case 2:
			cout << "Leader board" << endl;
			break;

		default:
			break;
		
		}
	}
	return 0;
}
