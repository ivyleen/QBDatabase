#include "stdafx.h"

#include "Menu.h"

int main(int argc, char *argv[])
{
	using namespace menu;

	Menu::PopulateRecordCollections();

	Menu::FindVectorRecords();
	Menu::FindMapRecords();
	Menu::FindSetRecords();

	Menu::PrintStatistics();

	Menu::DeleteRecords();

	Menu::FindVectorRecords();
	Menu::FindMapRecords();
	Menu::FindSetRecords();
	
	Menu::PrintStatistics();

	return 0;
}
