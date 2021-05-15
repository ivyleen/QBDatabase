#include "stdafx.h"

#include "DatabaseInterfaceHelperMap.h"

#include <utility>


namespace qbMap
{

const std::string &QBRecord::GetColumn1() const
{
	return m_column1;
}

// ---------------------------------------------------------------------------------------------------------------------------------

long QBRecord::GetColumn2() const
{
	return m_column2;
}

// ---------------------------------------------------------------------------------------------------------------------------------

const std::string &QBRecord::GetColumn3() const
{
	return m_column3;
}

// ---------------------------------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const QBRecord &rec)
{
	os << rec.m_column1 << " " << rec.m_column2 << " " << rec.m_column3;
	return os;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

std::set<double, std::less<>> DatabaseInterfaceHelper::m_times;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PrintStatistics()
{
	std::cout << "Container type: ---- Map" << std::endl;

	double sum = std::accumulate(m_times.begin(), m_times.end(), 0.00);
	std::cout << "Mean avarage: " << static_cast<double>(sum / NUMBER_OF_TEST_LOOPS) << " milliseconds." << std::endl;

	TimeCollectionType::iterator it = m_times.begin();
	std::advance(it, m_times.size() / 2);
	std::cout << "Median avarage: " << *it << " milliseconds." << std::endl;

	std::cout << "Minimum time: " << *m_times.begin() << " milliseconds." << std::endl;

	std::cout << "Maximum time: " << *m_times.rbegin() << " milliseconds." << std::endl;

	std::cout << "Range time: " << *m_times.rbegin() - *m_times.begin() << std::endl;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{
\
	for (uint32_t i = 0; i < static_cast<uint32_t>(numRecords); i++)
	{
		records.insert(std::make_pair(i, QBRecord(prefix + std::to_string(i), i % 100, std::to_string(i) + prefix)));
	}

}

void DatabaseInterfaceHelper::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	const COLUMNS column, const std::string &matchString)
{
	if (resourceRecords.empty())
	{
		assert(true);
	}

	switch (column)
	{
		// Search by key.
		case COLUMNS::COLUMN_0:
		{
			int matchingNumber = std::stoi(matchString);
			auto it = resourceRecords.find(matchingNumber);
			if (it != std::end(resourceRecords))
			{
				returnRecords.insert(std::make_pair(it->first, QBRecord((it->second).GetColumn1(), (it->second).GetColumn2(),
					(it->second).GetColumn3())));
			}

			break;
		}
		// Search by value.
		case COLUMNS::COLUMN_1:
		{
			std::for_each(resourceRecords.begin(), resourceRecords.end(), [&](auto &p)
				{
					if (p.second.GetColumn1() == matchString)
					{
						returnRecords.insert(std::make_pair(p.first, QBRecord((p.second).GetColumn1(), (p.second).GetColumn2(),
							(p.second).GetColumn3())));
					}
				});
			break;
		}

		case COLUMNS::COLUMN_2:
		{
			long matchingNumber = std::stol(matchString);
			std::for_each(resourceRecords.begin(), resourceRecords.end(), [&](auto &p)
				{
					if (p.second.GetColumn2() == matchingNumber)
					{
						returnRecords.insert(std::make_pair(p.first, QBRecord((p.second).GetColumn1(), (p.second).GetColumn2(),
							(p.second).GetColumn3())));
					}
				});
			break;
		}

		case COLUMNS::COLUMN_3:
		{
			std::for_each(resourceRecords.begin(), resourceRecords.end(), [&](auto &p)
				{
					if (p.second.GetColumn3() == matchString)
					{
						returnRecords.insert(std::make_pair(p.first, QBRecord((p.second).GetColumn1(), (p.second).GetColumn2(),
							(p.second).GetColumn3())));
					}
				});
			break;
		}

		default:
		{
			std::cout << "Column id out of range: " << static_cast<int>(column) << std::endl;
			assert(true);
			break;
		}
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::DeleteRecordById(QBRecordCollection &records, uint32_t id)
{
	size_t numDeletedElements = records.erase(id);
	
	if (!numDeletedElements)
	{
		std::cout << "No elements has been deleted. Please try again with valid id." << std::endl;
	}
}

} // namespace qbMap
