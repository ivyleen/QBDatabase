#include "stdafx.h"

#include "DatabaseInterfaceHelperMap.h"

#include <utility>
#include <assert.h>
#include <algorithm>

namespace qbMap
{

const std::string &Record::GetColumn1() const
{
	return m_column1;
}

long Record::GetColumn2() const
{
	return m_column2;
}

const std::string &Record::GetColumn3() const
{
	return m_column3;
}


std::ostream &operator<<(std::ostream &os, const Record &rec)
{
	os << rec.m_column1 << " " << rec.m_column2 << " " << rec.m_column3;
	return os;
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelperMap::PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords)
{
\
	for (uint32_t i = 0; i < static_cast<uint32_t>(numRecords); i++)
	{
		records.insert(std::make_pair(i, Record(prefix + std::to_string(i), i % 100, std::to_string(i) + prefix)));
	}

}

void DatabaseInterfaceHelperMap::QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
	COLUMNS column, const std::string &matchString)
{
	switch (column)
	{
		// Search by key.
		case COLUMNS::COLUMN_0:
		{
			int matchingNumber = std::stoi(matchString);
			auto it = resourceRecords.find(matchingNumber);
			if (it != std::end(resourceRecords))
			{
				returnRecords.insert(std::make_pair(it->first, Record((it->second).GetColumn1(), (it->second).GetColumn2(),
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
						returnRecords.insert(std::make_pair(p.first, Record((p.second).GetColumn1(), (p.second).GetColumn2(),
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
						returnRecords.insert(std::make_pair(p.first, Record((p.second).GetColumn1(), (p.second).GetColumn2(),
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
						returnRecords.insert(std::make_pair(p.first, Record((p.second).GetColumn1(), (p.second).GetColumn2(),
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

void DatabaseInterfaceHelperMap::DeleteRecordById(QBRecordCollection &records, uint32_t id)
{

}

} // namespace qbMap
