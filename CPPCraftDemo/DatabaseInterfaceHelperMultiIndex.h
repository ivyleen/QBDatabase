#pragma once
#include "stdafx.h"

#ifdef MULTI_INDEX
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/range.hpp>

namespace qbMultiIndex
{

/**
	Represents a Record Object.
 */
class QBRecord : private boost::noncopyable
{
public:
	QBRecord(const uint32_t column0, const std::string &column1, const long column2, const std::string &column3) :
		m_column0(column0),
		m_column1(column1),
		m_column2(column2),
		m_column3(column3)
	{}

	uint32_t		m_column0;
	std::string		m_column1;
	long			m_column2;
	std::string		m_column3;

}; // QBRecord

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

/**
 *	@brief	The container.
 */
class QBRecordContainer : private boost::noncopyable
{
public:
	class Column0Tag {};
	class Column1Tag {};
	class Column2Tag {};
	class Column3Tag {};

private:
	using QBRecordIndexedBy = boost::multi_index::indexed_by
	<
		boost::multi_index::hashed_unique
		<
			boost::multi_index::tag<Column0Tag>,
			boost::multi_index::member<QBRecord, uint32_t,	&QBRecord::m_column0>
		>,
		boost::multi_index::hashed_non_unique
		<
			boost::multi_index::tag<Column1Tag>,
			boost::multi_index::member<QBRecord, std::string,	&QBRecord::m_column1>
		>,
		boost::multi_index::hashed_non_unique
		<
			boost::multi_index::tag<Column2Tag>,
			boost::multi_index::member<QBRecord, long,		&QBRecord::m_column2>
			>,
		boost::multi_index::hashed_non_unique
		<
			boost::multi_index::tag<Column3Tag>,
			boost::multi_index::member<QBRecord, std::string,	&QBRecord::m_column3>
		>
	>;

public:
	using QBRecordCollection = boost::multi_index::multi_index_container<QBRecord, QBRecordIndexedBy>;

	static QBRecordCollection &Get();

	static void PopulateQBRecordMultiIndex(const std::string &prefix, int numRecords);

private:
	static QBRecordCollection				m_qbRecordMultiIndex;

}; // QBRecordContainer

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

/*
	DatabaseInterfaceHelperMultiIndex represents interface with static functions for working with QBRecordCollection-s.
*/
struct DatabaseInterfaceHelper
{
	using QBRecordCollection = QBRecordContainer::QBRecordCollection;

	enum class COLUMNS { COLUMN_0 = 0, COLUMN_1, COLUMN_2, COLUMN_3, NUMBER_OF_COLUMNS};

	/**
		PopulateDummyData is utility to populate the multi index collection.
		@param prefix			prefix for the string value for every record
		@param numRecords		number of records to populate in the collection
	*/
	static void PopulateDummyData(const std::string &prefix, int numRecords);

	/**
		QBFindMatchingRecords finds matching records in specified column.
		@param returnRecords	the return record collection populated with the matching records
		@param columnName		the column of the search
		@param matchString		the value we are looking for
		*/
	static void QBFindMatchingRecords(QBRecordCollection &returnRecords,
		COLUMNS column, const std::string &matchString);

	/**
		DeleteRecordByID uses erase-remove idiom delete a record in the collection with a given id.
		@param records			the record collection
		@param id				the id of the record we are looking for to delete
	*/
	static void DeleteRecordById(uint32_t id);

}; // DatabaseInterfaceHelperInterface

} // namespace qbMultiIndex

#endif // MULTI_INDEX
