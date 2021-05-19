#include "stdafx.h"

#include "Menu.h"

#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>

namespace menu
{

Menu::VectorHelper::QBRecordCollection Menu::m_dataVector;
Menu::MapHelper::QBRecordCollection Menu::m_dataMap;
Menu::SetHelper::QBRecordCollection Menu::m_dataSet;

bool Menu::m_shouldBeFound = true;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindVectorRecords()
{
	std::cout << "============== VECTOR ========================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < NUMBER_OF_TEST_LOOPS; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		VectorHelper::QBRecordCollection result0;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result0, VectorHelper::COLUMNS::COLUMN_0, "424");

		VectorHelper::QBRecordCollection result1;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result1, VectorHelper::COLUMNS::COLUMN_1, "testdata424");

		VectorHelper::QBRecordCollection result2;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result2, VectorHelper::COLUMNS::COLUMN_2, "24");

		VectorHelper::QBRecordCollection result3;
		VectorHelper::QBFindMatchingRecords(m_dataVector, result3, VectorHelper::COLUMNS::COLUMN_3, "424testdata");

		auto millieconds = (static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den) *
			MULTIPLATOR_BY_MILLISECONDS;

#ifdef _DEBUG_
		std::cout << "std::vector " << millieconds << " seconds." << std::endl;
#endif
		VectorHelper::m_times.emplace_back(millieconds);

		UnitTestFindMatches(result0.size(), result1.size(), result2.size(), result3.size());
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindMapRecords()
{
	std::cout << "============== UNORDERED MAP =================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < NUMBER_OF_TEST_LOOPS; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		MapHelper::QBRecordCollection result0;
		MapHelper::QBFindMatchingRecords(m_dataMap, result0, MapHelper::COLUMNS::COLUMN_0, "424");

		MapHelper::QBRecordCollection result1;
		MapHelper::QBFindMatchingRecords(m_dataMap, result1, MapHelper::COLUMNS::COLUMN_1, "testdata424");

		MapHelper::QBRecordCollection result2;
		MapHelper::QBFindMatchingRecords(m_dataMap, result2, MapHelper::COLUMNS::COLUMN_2, "24");

		MapHelper::QBRecordCollection result3;
		MapHelper::QBFindMatchingRecords(m_dataMap, result3, MapHelper::COLUMNS::COLUMN_3, "424testdata");

		auto millieconds =  (static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den) *
			MULTIPLATOR_BY_MILLISECONDS;

#ifdef _DEBUG_
		std::cout << "std::map " << millieconds << " seconds." << std::endl;
#endif
		MapHelper::m_times.emplace_back(millieconds);

		UnitTestFindMatches(result0.size(), result1.size(), result2.size(), result3.size());
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindSetRecords()
{
	std::cout << "============== SET ===========================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < NUMBER_OF_TEST_LOOPS; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		SetHelper::QBRecordCollection result0;
		qbSet::QBRecord rec0(424, "testdata424", 24, "424testdata");
		SetHelper::QBFindMatchingRecords(m_dataSet, result0, rec0);

		SetHelper::QBRecordCollection result1;
		qbSet::QBRecord rec1(424, "testdata424", 24, "424testdata");
		SetHelper::QBFindMatchingRecords(m_dataSet, result1, rec1);

		SetHelper::QBRecordCollection result2;
		qbSet::QBRecord rec2(424, "testdata424", 24, "424testdata");
		SetHelper::QBFindMatchingRecords(m_dataSet, result2, rec2);

		SetHelper::QBRecordCollection result3;
		qbSet::QBRecord rec3(424, "testdata424", 24, "424testdata");
		SetHelper::QBFindMatchingRecords(m_dataSet, result3, rec3);

		auto millieconds =  (static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den) *
			MULTIPLATOR_BY_MILLISECONDS;

#ifdef _DEBUG_
		std::cout << "std::set " << millieconds << " seconds." << std::endl;
#endif
		SetHelper::m_times.emplace_back(millieconds);

		if (m_shouldBeFound)
		{
			assert((result0.size() > 0) && (result1.size() > 0) && (result2.size() > 0) && (result3.size() > 0));
		}
		else
		{
			assert((result0.size() == 0) && (result1.size() == 0) && (result2.size() == 0) && (result3.size() == 0));
		}
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

#ifdef MULTI_INDEX
void Menu::FindMultiIndexRecords()
{
	std::cout << "============== MULTI INDEX ===================================================================" << std::endl;

	// Find a record that contains and measure the performance.
	for (int i = 0; i < NUMBER_OF_TEST_LOOPS; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		MultiIndexHelper::QBRecordCollection result0;
		MultiIndexHelper::QBFindMatchingRecords(result0, MultiIndexHelper::COLUMNS::COLUMN_0, "424");

		MultiIndexHelper::QBRecordCollection result1;
		MultiIndexHelper::QBFindMatchingRecords(result1, MultiIndexHelper::COLUMNS::COLUMN_1, "testdata424");

		MultiIndexHelper::QBRecordCollection result2;
		MultiIndexHelper::QBFindMatchingRecords(result2, MultiIndexHelper::COLUMNS::COLUMN_2, "24");

		MultiIndexHelper::QBRecordCollection result3;
		MultiIndexHelper::QBFindMatchingRecords(result3, MultiIndexHelper::COLUMNS::COLUMN_3, "424testdata");

		auto millieconds =  (static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den) *
			MULTIPLATOR_BY_MILLISECONDS;

#ifdef _DEBUG_
		std::cout << "multi_index: " << millieconds << std::endl;
#endif
		MultiIndexHelper::m_times.emplace_back(millieconds);

		UnitTestFindMatches(result0.size(), result1.size(), result2.size(), result3.size());
	}
}
#endif // MULTI_INDEX

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PrintStatistics()
{
	VectorHelper::PrintStatistics();
	MapHelper::PrintStatistics();
	SetHelper::PrintStatistics();

#ifdef MULTI_INDEX
	MultiIndexHelper::PrintStatistics();
#endif
}


// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::DeleteRecords()
{
	size_t originalSize = m_dataVector.size();
	std::cout << "Size of vector container before deletion: " << originalSize << std::endl;
	VectorHelper::DeleteRecordById(m_dataVector, static_cast<uint32_t>(424));
	std::cout << "Size of vector container after deletion: " << m_dataVector.size() << std::endl;
	assert(originalSize != m_dataVector.size());

	originalSize = m_dataMap.size();
	std::cout << "Size of map container before deletion: " << originalSize << std::endl;
	MapHelper::DeleteRecordById(m_dataMap, static_cast<uint32_t>(424));
	std::cout << "Size of map container after deletion: " << m_dataMap.size() << std::endl;
	assert(originalSize != m_dataMap.size());

	originalSize = m_dataSet.size();
	std::cout << "Size of set container before deletion: " << originalSize << std::endl;
	SetHelper::DeleteRecordById(m_dataSet, qbSet::QBRecord(424, "testdata424", 24, "424testdata"));
	std::cout << "Size of set container after deletion: " << m_dataSet.size() << std::endl;
	assert(originalSize != m_dataSet.size());

#ifdef MULTI_INDEX
	originalSize = qbMultiIndex::QBRecordContainer::Get().size();
	std::cout << "Size of multi_index container before deletion: " << originalSize << std::endl;
	qbMultiIndex::DatabaseInterfaceHelper::DeleteRecordById(static_cast<uint32_t>(424));
	std::cout << "Size of multi_index container after deletion: " << qbMultiIndex::QBRecordContainer::Get().size() << std::endl;
	assert(originalSize != qbMultiIndex::QBRecordContainer::Get().size());
#endif

	// When searching for the elements we should not find them.
	m_shouldBeFound = false;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PopulateRecordCollections()
{
	VectorHelper::PopulateDummyData(m_dataVector, "testdata", NUMBER_OF_ELEMENTS);
	assert(m_dataVector.size() == NUMBER_OF_ELEMENTS);

	MapHelper::PopulateDummyData(m_dataMap, "testdata", NUMBER_OF_ELEMENTS);
	assert(m_dataMap.size() == NUMBER_OF_ELEMENTS);

	SetHelper::PopulateDummyData(m_dataSet, "testdata", NUMBER_OF_ELEMENTS);
	assert(m_dataSet.size() == NUMBER_OF_ELEMENTS);

#ifdef MULTI_INDEX
	MultiIndexHelper::PopulateDummyData("testdata", NUMBER_OF_ELEMENTS);
	assert(qbMultiIndex::QBRecordContainer::Get().size() == NUMBER_OF_ELEMENTS);
#endif
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::ClearTimes()
{
	VectorHelper::m_times.clear();
	MapHelper::m_times.clear();
	SetHelper::m_times.clear();

#ifdef MULTI_INDEX
	MultiIndexHelper::m_times.clear();
#endif
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::UnitTestFindMatches(size_t sizeResult0, size_t sizeResult1, size_t sizeResult2, size_t sizeResult3)
{
	if (m_shouldBeFound)
	{
		assert(sizeResult0 == 1);
		assert(sizeResult1 == 1);
		assert(sizeResult2 == 10);
		assert(sizeResult3 == 1);
	}
	else
	{
		assert(sizeResult0 == 0);
		assert(sizeResult1 == 0);
		assert(sizeResult2 == 9);
		assert(sizeResult3 == 0);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::DumpTimesIntoFile(std::string file)
{
	std::ofstream outputFile(file);

	VectorHelper::TimeCollectionType::iterator vecIt = VectorHelper::m_times.begin();
	outputFile << "================= VECTOR =================\n";
	while(vecIt != VectorHelper::m_times.end())
	{
		outputFile << *vecIt << "\n";
		++vecIt;
	}

	outputFile << "\n";

	MapHelper::TimeCollectionType::iterator mapIt = MapHelper::m_times.begin();
	outputFile << "================= MAP ====================\n";
	while (mapIt != MapHelper::m_times.end())
	{
		outputFile << *mapIt << "\n";
		++mapIt;
	}

	outputFile << "\n";

	SetHelper::TimeCollectionType::iterator setIt = SetHelper::m_times.begin();
	outputFile << "================= SET ====================\n";
	while (setIt != SetHelper::m_times.end())
	{
		outputFile << *setIt << "\n";
		++setIt;
	}
}

} // namespace menu
