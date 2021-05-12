#include "stdafx.h"

#include "DatabaseInterfaceHelperSet.h"

namespace qbSet
{

bool operator<(const QBRecord &lhs, const QBRecord &rhs)
{
	return std::tie(lhs.m_column0, lhs.m_column1, lhs.m_column2, lhs.m_column3) <
		std::tie(rhs.m_column0, rhs.m_column1, rhs.m_column2, rhs.m_column3);
}

// ---------------------------------------------------------------------------------------------------------------------------------

bool operator==(const QBRecord &lhs, const QBRecord &rhs)
{
	return std::tie(lhs.m_column0, lhs.m_column1, lhs.m_column2, lhs.m_column3) ==
		std::tie(rhs.m_column0, rhs.m_column1, rhs.m_column2, rhs.m_column3);
}

// ---------------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const QBRecord& rec)
{
	os << "{" << rec.m_column0 << "} {" << rec.m_column1 << "} {" << rec.m_column2 << "} {" << rec.m_column3 << "}";
	return os;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

std::set<double> DatabaseInterfaceHelper::m_times;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PrintStatistics()
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

void DatabaseInterfaceHelper::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{
	for (int i = 0; i < numRecords; ++i)
	{
		records.insert(QBRecord(i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix));
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	const QBRecord& rec)
{
	if (resourceRecords.empty())
	{
		assert(true);
	}

	auto found = resourceRecords.find(rec);
	if (found == resourceRecords.end())
	{
		assert(true);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::DeleteRecordById(QBRecordCollection &records, const QBRecord &rec)
{
	records.erase(rec);
}


} // namespace qb
