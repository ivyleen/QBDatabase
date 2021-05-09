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

qbVector::DatabaseInterfaceHelper::QBRecordCollection Menu::m_dataVector;
qbMap::DatabaseInterfaceHelper::QBRecordCollection Menu::m_dataMap;
qbSet::DatabaseInterfaceHelper::QBRecordCollection Menu::m_dataSet;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindVectorRecords()
{
	std::cout << "============== VECTOR =========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result0;
		qbVector::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataVector, result0, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result1;
		qbVector::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataVector, result1, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result2;
		qbVector::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataVector, result2, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result3;
		qbVector::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataVector, result2, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds = static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::vector " << nseconds << " seconds." << std::endl;
#endif

		qbVector::DatabaseInterfaceHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindMapRecords()
{
	std::cout << "============== UNORDERED MAP =================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result0;
		qbMap::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataMap, result0, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result1;
		qbMap::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataMap, result1, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result2;
		qbMap::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataMap, result2, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result3;
		qbMap::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataMap, result3, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::map " << nseconds << " seconds." << std::endl;
#endif

		qbMap::DatabaseInterfaceHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindSetRecords()
{

	std::cout << "============== SET ===========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result0;
		qbSet::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataSet, result0, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result1;
		qbSet::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataSet, result1, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result2;
		qbSet::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataSet, result2, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result3;
		qbSet::DatabaseInterfaceHelper::QBFindMatchingRecords(m_dataSet, result3, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

#ifdef _DEBUG_
		std::cout << "std::set " << nseconds << " seconds." << std::endl;
#endif

		qbSet::DatabaseInterfaceHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PrintStatistics()
{
	qbVector::DatabaseInterfaceHelper::PrintStatistics();
	qbMap::DatabaseInterfaceHelper::PrintStatistics();
	qbSet::DatabaseInterfaceHelper::PrintStatistics();
}


// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::DeleteRecords()
{
	std::cout << "Size of vector container before deletion: " << m_dataVector.size() << std::endl;
	qbVector::DatabaseInterfaceHelper::DeleteRecordById(m_dataVector, static_cast<uint32_t>(424));
	std::cout << "Size of vector container after deletion: " << m_dataVector.size() << std::endl;

	std::cout << "Size of map container before deletion: " << m_dataMap.size() << std::endl;
	qbMap::DatabaseInterfaceHelper::DeleteRecordById(m_dataMap, static_cast<uint32_t>(424));
	std::cout << "Size of map container after deletion: " << m_dataMap.size() << std::endl;

	std::cout << "Size of set container before deletion: " << m_dataSet.size() << std::endl;
	qbSet::DatabaseInterfaceHelper::DeleteRecordById(m_dataSet, static_cast<uint32_t>(424));
	std::cout << "Size of set container after deletion: " << m_dataSet.size() << std::endl;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PopulateRecordCollections()
{
	qbVector::DatabaseInterfaceHelper::PopulateDummyData(m_dataVector, "testdata", 1000);
	qbMap::DatabaseInterfaceHelper::PopulateDummyData(m_dataMap, "testdata", 1000);
	qbSet::DatabaseInterfaceHelper::PopulateDummyData(m_dataSet, "testdata", 1000);
}

} // namespace menu
