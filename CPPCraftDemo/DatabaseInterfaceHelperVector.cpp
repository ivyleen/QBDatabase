#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <assert.h>

#include "DatabaseInterfaceHelperVector.h"



namespace qbVector
{

bool operator==(const QBRecord &qbRecord, const uint32_t column0) {
	return  qbRecord.column0 == column0;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperVector::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{
	records.reserve(records.size() + numRecords);
	for (uint32_t i = 0; i < static_cast<uint32_t>(numRecords); i++)
	{
		QBRecord rec = { i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix };
		records.emplace_back(rec);
	}

	// Sort the vector in increasing order - using column0 as comparant - to increase chances for faster search.
	std::sort(records.begin(), records.end(),
		[&](const qbVector::QBRecord &lhs, const qbVector::QBRecord &rhs)
		{
			return lhs.column0 < rhs.column0;
		}
	);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperVector::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	COLUMNS column, const std::string &matchString)
{
	switch (column)
	{
		case COLUMNS::COLUMN_0:
		{
			unsigned long matchValue = std::stoul(matchString);
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return matchValue == rec.column0;
				});
			break;
		}
		case COLUMNS::COLUMN_1:
		{
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return rec.column1.find(matchString) != std::string::npos;
				});
			break;
		}
		case COLUMNS::COLUMN_2:
		{
			long matchValue = std::stol(matchString);
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return matchValue == rec.column2;
				});
			break;
		}
		case COLUMNS::COLUMN_3:
		{
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return rec.column3.find(matchString) != std::string::npos;
				});
			break;
		}
		default:
			std::cout << "Column id out of range: " << static_cast<int>(column) << std::endl;
			assert(true);
			break;
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperVector::DeleteRecordById(QBRecordCollection &records, uint32_t id)
{
	// Erase-remove idiom: we first mark the elements that need to be erased from the container in single pass through
	// the data range and then start erasing them from the returned iterator of the first of the marked elements until end.
	records.erase(std::remove(records.begin(), records.end(), id), records.end());
}

} // namespace qb
