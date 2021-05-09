#include "stdafx.h"

#include "Menu.h"

#include <assert.h>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "DatabaseInterfaceHelperVector.h"
#include "DatabaseInterfaceHelperMap.h"
#include "DatabaseInterfaceHelperSet.h"

namespace menu
{

void Menu::FindVectorRecords()
{
	qbVector::DatabaseInterfaceHelper dbInterface;

	// Populate a bunch of data.
	qbVector::DatabaseInterfaceHelper::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== VECTOR =========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbVector::DatabaseInterfaceHelper::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds = static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::vector " << nseconds << " seconds." << std::endl;

		qbVector::DatabaseInterfaceHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindMapRecords()
{
	qbMap::DatabaseInterfaceHelper dbInterface;

	// Populate a bunch of data.
	qbMap::DatabaseInterfaceHelper::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== UNORDERED MAP =================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbMap::DatabaseInterfaceHelper::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result3, qbMap::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::map " << nseconds << " seconds." << std::endl;

		qbMap::DatabaseInterfaceHelper::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindSetRecords()
{
	qbSet::DatabaseInterfaceHelper dbInterface;

	// Populate a bunch of data.
	qbSet::DatabaseInterfaceHelper::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== SET ===========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_0, "424");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_1, "testdata500");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_2, "24");

		qbSet::DatabaseInterfaceHelper::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result3, qbSet::DatabaseInterfaceHelper::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::set " << nseconds << " seconds." << std::endl;

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

} // namespace menu
