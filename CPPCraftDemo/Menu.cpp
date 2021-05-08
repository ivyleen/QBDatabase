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
	qbVector::DatabaseInterfaceHelperVector dbInterface;

	// Populate a bunch of data.
	qbVector::DatabaseInterfaceHelperVector::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== VECTOR =========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		auto startTimer = std::chrono::steady_clock::now();

		qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_0, "424");

		qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_1, "testdata500");

		qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_2, "24");

		qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds = static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::vector " << nseconds << " seconds." << std::endl;

		qbVector::DatabaseInterfaceHelperVector::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindMapRecords()
{
	qbMap::DatabaseInterfaceHelperMap dbInterface;

	// Populate a bunch of data.
	qbMap::DatabaseInterfaceHelperMap::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== UNORDERED MAP =================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbMap::DatabaseInterfaceHelperMap::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbMap::DatabaseInterfaceHelperMap::COLUMNS::COLUMN_0, "424");

		qbMap::DatabaseInterfaceHelperMap::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbMap::DatabaseInterfaceHelperMap::COLUMNS::COLUMN_1, "testdata500");

		qbMap::DatabaseInterfaceHelperMap::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbMap::DatabaseInterfaceHelperMap::COLUMNS::COLUMN_2, "24");

		qbMap::DatabaseInterfaceHelperMap::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result3, qbMap::DatabaseInterfaceHelperMap::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::map " << nseconds << " seconds." << std::endl;

		qbMap::DatabaseInterfaceHelperMap::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::FindSetRecords()
{
	qbSet::DatabaseInterfaceHelperSet dbInterface;

	// Populate a bunch of data.
	qbSet::DatabaseInterfaceHelperSet::QBRecordCollection data;
	dbInterface.PopulateDummyData(data, "testdata", 1000);

	std::cout << "============== SET ===========================================================================" << std::endl;
	// Find a record that contains and measure the performance.
	for (int i = 0; i < 1000; ++i)
	{
		using namespace std::chrono;
		auto startTimer = std::chrono::steady_clock::now();

		qbSet::DatabaseInterfaceHelperSet::QBRecordCollection result0;
		dbInterface.QBFindMatchingRecords(data, result0, qbSet::DatabaseInterfaceHelperSet::COLUMNS::COLUMN_0, "424");

		qbSet::DatabaseInterfaceHelperSet::QBRecordCollection result1;
		dbInterface.QBFindMatchingRecords(data, result1, qbSet::DatabaseInterfaceHelperSet::COLUMNS::COLUMN_1, "testdata500");

		qbSet::DatabaseInterfaceHelperSet::QBRecordCollection result2;
		dbInterface.QBFindMatchingRecords(data, result2, qbSet::DatabaseInterfaceHelperSet::COLUMNS::COLUMN_2, "24");

		qbSet::DatabaseInterfaceHelperSet::QBRecordCollection result3;
		dbInterface.QBFindMatchingRecords(data, result3, qbSet::DatabaseInterfaceHelperSet::COLUMNS::COLUMN_3, "424testdata");

		auto nseconds =  static_cast<double>((std::chrono::steady_clock::now() -
			startTimer).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

		std::cout << "std::set " << nseconds << " seconds." << std::endl;

		qbSet::DatabaseInterfaceHelperSet::m_times.insert(nseconds);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void Menu::PrintStatistics()
{
	qbVector::DatabaseInterfaceHelperVector::PrintStatistics();
	qbMap::DatabaseInterfaceHelperMap::PrintStatistics();
	qbSet::DatabaseInterfaceHelperSet::PrintStatistics();
}

} // namespace menu
