#include "stdafx.h"

#include "Menu.h"

int main(int argc, char *argv[])
{
	menu::Menu::FindVectorRecords();
	menu::Menu::FindMapRecords();
	menu::Menu::FindSetRecords();
	menu::Menu::PrintStatistics();

	return 0;
}
