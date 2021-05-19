#include "stdafx.h"

#include "Menu.h"

int main(int argc, char *argv[])
{
	using namespace menu;

	Menu::PopulateRecordCollections();

	Menu::FindVectorRecords();
	Menu::FindMapRecords();
	Menu::FindSetRecords();
#ifdef MULTI_INDEX
	Menu::FindMultiIndexRecords();
#endif

	Menu::PrintStatistics();

	Menu::DumpTimesIntoFile("DumpedTimes.txt");
	Menu::ClearTimes();

	Menu::DeleteRecords();

	Menu::FindVectorRecords();
	Menu::FindMapRecords();
	Menu::FindSetRecords();
#ifdef MULTI_INDEX
	Menu::FindMultiIndexRecords();
#endif

	Menu::PrintStatistics();

	return 0;
}
