#include "stdafx.h"

#include "Menu.h"

#include <assert.h>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace menu
{

Menu::VectorHelper::QBRecordCollection Menu::m_dataVector;
Menu::MapHelper::QBRecordCollection Menu::m_dataMap;
Menu::SetHelper::QBRecordCollection Menu::m_dataSet;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindVectorRecords()
{
	std::cout << "============== VECTOR =========================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		VectorHelper::QBRecordCollection result0;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result0, VectorHelper::COLUMNS::COLUMN_0, "424");

		VectorHelper::QBRecordCollection result1;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result1, VectorHelper::COLUMNS::COLUMN_1, "testdata500");

		VectorHelper::QBRecordCollection result2;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result2, VectorHelper::COLUMNS::COLUMN_2, "24");

		VectorHelper::QBRecordCollection result3;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result2, VectorHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds = static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::vector " << nseconds << " seconds." << std::endl;
#endif

		VectorHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindMapRecords()
{
	std::cout << "============== UNORDERED MAP =================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		MapHelper::QBRecordCollection result0;
		MapHelper::QBFindMatchingRecords(m_dataMap, result0, MapHelper::COLUMNS::COLUMN_0, "424");

		MapHelper::QBRecordCollection result1;
		MapHelper::QBFindMatchingRecords(m_dataMap, result1, MapHelper::COLUMNS::COLUMN_1, "testdata500");

		MapHelper::QBRecordCollection result2;
		MapHelper::QBFindMatchingRecords(m_dataMap, result2, MapHelper::COLUMNS::COLUMN_2, "24");

		MapHelper::QBRecordCollection result3;
		MapHelper::QBFindMatchingRecords(m_dataMap, result3, MapHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::map " << nseconds << " seconds." << std::endl;
#endif

		MapHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindSetRecords()
{
	std::cout << "============== SET ===========================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		SetHelper::QBRecordCollection result0;
		SetHelper::QBFindMatchingRecords(m_dataSet, result0, SetHelper::COLUMNS::COLUMN_0, "424");

		SetHelper::QBRecordCollection result1;
		SetHelper::QBFindMatchingRecords(m_dataSet, result1, SetHelper::COLUMNS::COLUMN_1, "testdata500");

		SetHelper::QBRecordCollection result2;
		SetHelper::QBFindMatchingRecords(m_dataSet, result2, SetHelper::COLUMNS::COLUMN_2, "24");

		SetHelper::QBRecordCollection result3;
		SetHelper::QBFindMatchingRecords(m_dataSet, result3, SetHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::set " << nseconds << " seconds." << std::endl;
#endif

		SetHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

#ifdef MULTI_INDEX
void Menu::FindMultiIndexRecords()
{
	std::cout << "============== MULTI INDEX ==================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		MultiIndexHelper::QBRecordCollection result0;
		MultiIndexHelper::QBFindMatchingRecords(result0, MultiIndexHelper::COLUMNS::COLUMN_0, "424");

		MultiIndexHelper::QBRecordCollection result1;
		MultiIndexHelper::QBFindMatchingRecords(result1, MultiIndexHelper::COLUMNS::COLUMN_1, "testdata500");

		MultiIndexHelper::QBRecordCollection result2;
		MultiIndexHelper::QBFindMatchingRecords(result2, MultiIndexHelper::COLUMNS::COLUMN_2, "24");

		MultiIndexHelper::QBRecordCollection result3;
		MultiIndexHelper::QBFindMatchingRecords(result3, MultiIndexHelper::COLUMNS::COLUMN_3, "424testdata");

		std::cout << "multi_index: " <<
			double((std::chrono::steady_clock::now() - startTimer).count()) * std::chrono::steady_clock::period::num /
			std::chrono::steady_clock::period::den << std::endl;
	}
}
#endif // MULTI_INDEX

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PrintStatistics()
{
	VectorHelper::PrintStatistics();
	MapHelper::PrintStatistics();
	SetHelper::PrintStatistics();
}


// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::DeleteRecords()
{
	std::cout << "Size of vector container before deletion: " << m_dataVector.size() << std::endl;
	VectorHelper::DeleteRecordById(m_dataVector, static_cast<uint32_t>(424));
	std::cout << "Size of vector container after deletion: " << m_dataVector.size() << std::endl;

	std::cout << "Size of map container before deletion: " << m_dataMap.size() << std::endl;
	MapHelper::DeleteRecordById(m_dataMap, static_cast<uint32_t>(424));
	std::cout << "Size of map container after deletion: " << m_dataMap.size() << std::endl;

	std::cout << "Size of set container before deletion: " << m_dataSet.size() << std::endl;
	SetHelper::DeleteRecordById(m_dataSet, static_cast<uint32_t>(424));
	std::cout << "Size of set container after deletion: " << m_dataSet.size() << std::endl;

#ifdef MULTI_INDEX
	std::cout << "Size of set container before deletion: " << m_dataSet.size() << std::endl;
	qbMultiIndex::DatabaseInterfaceHelper::DeleteRecordById(static_cast<uint32_t>(424));
	std::cout << "Size of set container after deletion: " << m_dataSet.size() << std::endl;
#endif
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PopulateRecordCollections()
{
	VectorHelper::PopulateDummyData(m_dataVector, "testdata", 1000);
	MapHelper::PopulateDummyData(m_dataMap, "testdata", 1000);
	SetHelper::PopulateDummyData(m_dataSet, "testdata", 1000);

#ifdef MULTI_INDEX
	MultiIndexHelper::PopulateDummyData("testdata", 1000);
#endif
}

} // namespace menu
