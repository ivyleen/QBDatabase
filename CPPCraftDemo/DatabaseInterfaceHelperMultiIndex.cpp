#include "stdafx.h"

#ifdef MULTI_INDEX

#include "DatabaseInterfaceHelperMultiIndex.h"


namespace qbMultiIndex
{

// Initialize static variable
QBRecordContainer::QBRecordCollection QBRecordContainer::m_qbRecordMultiIndex;

// ---------------------------------------------------------------------------------------------------------------------------------

QBRecordContainer::QBRecordCollection &QBRecordContainer::Get()
{
	return m_qbRecordMultiIndex;
}

// ---------------------------------------------------------------------------------------------------------------------------------

void QBRecordContainer::PopulateQBRecordMultiIndex(const std::string &prefix, int numRecords)
{
	for (int i = 0; i < numRecords; ++i)
	{
		m_qbRecordMultiIndex.emplace(i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix);
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

std::set<double> DatabaseInterfaceHelper::m_times;

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PopulateDummyData(const std::string &prefix, int numRecords)
{
	QBRecordContainer::PopulateQBRecordMultiIndex(prefix, numRecords);
}

// ---------------------------------------------------------------------------------------------------------------------------------

void DatabaseInterfaceHelper::PrintStatistics()
{
	std::cout << "Container type: ---- boost::multi_index" << std::endl;

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

void DatabaseInterfaceHelper::QBFindMatchingRecords(QBRecordCollection &returnRecords, const COLUMNS column,
	const std::string &matchString)
{
	switch (column)
	{
		case COLUMNS::COLUMN_0:
		{
			int matchingNumber = std::stoi(matchString);
			auto &indexColumn0 = qbMultiIndex::QBRecordContainer::Get().get<qbMultiIndex::QBRecordContainer::Column0Tag>();
			auto iterColumn0 = indexColumn0.equal_range(matchingNumber);
			while (iterColumn0.first != iterColumn0.second)
			{
				returnRecords.emplace(iterColumn0.first->m_column0, iterColumn0.first->m_column1,
					iterColumn0.first->m_column2, iterColumn0.first->m_column3);
				++iterColumn0.first;
			}
			break;
		}
		case COLUMNS::COLUMN_1:
		{
			auto &indexColumn1 = qbMultiIndex::QBRecordContainer::Get().get<qbMultiIndex::QBRecordContainer::Column1Tag>();
			auto iterColumn1 = indexColumn1.equal_range(matchString);
			while (iterColumn1.first != iterColumn1.second)
			{
				returnRecords.emplace(iterColumn1.first->m_column0, iterColumn1.first->m_column1,
					iterColumn1.first->m_column2, iterColumn1.first->m_column3);
				++iterColumn1.first;
			}
			break;
		}
		case COLUMNS::COLUMN_2:
		{
			long matchingNumber = std::stol(matchString);
			auto &indexColumn2 = qbMultiIndex::QBRecordContainer::Get().get<qbMultiIndex::QBRecordContainer::Column2Tag>();
			auto iterColumn2 = indexColumn2.equal_range(matchingNumber);
			while (iterColumn2.first != iterColumn2.second)
			{
				returnRecords.emplace(iterColumn2.first->m_column0, iterColumn2.first->m_column1,
					iterColumn2.first->m_column2, iterColumn2.first->m_column3);
				++iterColumn2.first;
			}
			break;
		}
		case COLUMNS::COLUMN_3:
		{
			auto &indexColumn3 = qbMultiIndex::QBRecordContainer::Get().get<qbMultiIndex::QBRecordContainer::Column3Tag>();
			auto iterColumn3 = indexColumn3.equal_range(matchString);
			while (iterColumn3.first != iterColumn3.second)
			{
				returnRecords.emplace(iterColumn3.first->m_column0, iterColumn3.first->m_column1,
					iterColumn3.first->m_column2, iterColumn3.first->m_column3);
				++iterColumn3.first;
			}
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

void DatabaseInterfaceHelper::DeleteRecordById(uint32_t id)
{
	auto &index = qbMultiIndex::QBRecordContainer::Get().get<qbMultiIndex::QBRecordContainer::Column0Tag>();
	auto iter = index.equal_range(id);
	index.erase(iter.first, iter.second);
}

} // namespace qbMultiIndex

#endif // MULTI_INDEX
