#include <Windows.h>
#include "UI.h"
#include "Tests.h"

int main()
{
	UI ui{};

	tests();

	ui.run();
	
	std::cout << std::endl;
	system("pause");
	return 0;
}