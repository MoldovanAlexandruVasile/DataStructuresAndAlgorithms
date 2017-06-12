#include <Windows.h>
#include "UI.h"
#include "Tests.h"

int main()
{
	tests();

	UI ui{};

	ui.run();
	
	std::cout << std::endl;

	return 0;
}