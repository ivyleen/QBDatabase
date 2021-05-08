#include "stdafx.h"

#include "DatabaseInterfaceHelperSet.h"



namespace qbSet
{

bool operator==(const QBRecord &qbRecord, const uint32_t column0) {
	return  qbRecord.column0 == column0;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

std::set<double> DatabaseInterfaceHelperSet::m_times;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperSet::PrintStatistics()
{
	std::cout << "Container type: ---- Set" << std::endl;

	TimeCollectionType::iterator it = m_times.begin();
	std::advance(it, m_times.size() / 2);
	std::cout << "Mean avarage: " << *it << std::endl;

	double sum = std::accumulate(m_times.begin(), m_times.end(), 0.0);
	std::cout << "Medium avarage: " << static_cast<double>(sum/2) << std::endl;

	std::cout << "Minimum time: " << *m_times.begin() << std::endl;

	std::cout << "Maximum time: " << *m_times.end() << std::endl;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperSet::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{

}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperSet::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	COLUMNS column, const std::string &matchString)
{
	switch (column)
	{
		case COLUMNS::COLUMN_0:
		{
			int matchingNumber = std::stoi(matchString);
			break;
		}
		case COLUMNS::COLUMN_1:
		{
			break;
		}
		case COLUMNS::COLUMN_2:
		{
			long matchingNumber = std::stol(matchString);
			break;
		}
		case COLUMNS::COLUMN_3:
		{

			break;
		}
		default:
			std::cout << "Column id out of range: " << static_cast<int>(column) << std::endl;
			assert(true);
			break;
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperSet::DeleteRecordById(QBRecordCollection &records, uint32_t id)
{
}


} // namespace qb
