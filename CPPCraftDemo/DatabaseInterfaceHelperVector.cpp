#include "stdafx.h"

#include "DatabaseInterfaceHelperVector.h"


namespace qbVector
{

bool operator==(const QBRecord &qbRecord, const uint32_t column0)
{
	return  qbRecord.m_column0 == column0;
}

// ---------------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const QBRecord& rec)
{
	os << "{" << rec.m_column0 << "} {" << rec.m_column1 << "} {" << rec.m_column2 << "} {" << rec.m_column0 << "}\n";
	return os;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

std::set<double> DatabaseInterfaceHelper::m_times;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PrintStatistics()
{
	std::cout << "Container type: ---- Vector" << std::endl;

	TimeCollectionType::iterator it = m_times.begin();
	std::advance(it, m_times.size() / 2);
	std::cout << "Mean avarage: " << *it << std::endl;

	double sum = std::accumulate(m_times.begin(), m_times.end(), 0.0);
	std::cout << "Medium avarage: " << static_cast<double>(sum/2) << std::endl;

	std::cout << "Minimum time: " << *m_times.begin() << std::endl;

	std::cout << "Maximum time: " << *m_times.end() << std::endl;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{
	records.reserve(records.size() + numRecords);
	for (uint32_t i = 0; i < static_cast<uint32_t>(numRecords); i++)
	{
		records.emplace_back(i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix);
	}

	// Sort the vector in increasing order - using m_column0 as comparant - to increase chances for faster search.
	std::sort(records.begin(), records.end(),
		[&](const qbVector::QBRecord &lhs, const qbVector::QBRecord &rhs)
		{
			return lhs.m_column0 < rhs.m_column0;
		}
	);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	COLUMNS m_column, const std::string &matchString)
{
	switch (m_column)
	{
		case COLUMNS::COLUMN_0:
		{
			unsigned long matchValue = std::stoul(matchString);
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return matchValue == rec.m_column0;
				});
			break;
		}
		case COLUMNS::COLUMN_1:
		{
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return rec.m_column1.find(matchString) != std::string::npos;
				});
			break;
		}
		case COLUMNS::COLUMN_2:
		{
			long matchValue = std::stol(matchString);
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return matchValue == rec.m_column2;
				});
			break;
		}
		case COLUMNS::COLUMN_3:
		{
			std::copy_if(resourceRecords.begin(), resourceRecords.end(), std::back_inserter(returnRecords),
				[&](const QBRecord &rec) {
					return rec.m_column3.find(matchString) != std::string::npos;
				});
			break;
		}
		default:
			std::cout << "m_column id out of range: " << static_cast<int>(m_column) << std::endl;
			assert(true);
			break;
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::DeleteRecordById(QBRecordCollection &records, uint32_t id)
{
	// Erase-remove idiom: we first mark the elements that need to be erased from the container in single pass through
	// the data range and then start erasing them from the returned iterator of the first of the marked elements until end.
	records.erase(std::remove(records.begin(), records.end(), id), records.end());
}

} // namespace qb
