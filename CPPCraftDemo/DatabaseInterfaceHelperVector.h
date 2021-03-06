#pragma once

#include <vector>
#include <set>

// Encapsulation in namespace
namespace qbVector
{

/**
	Represents a Record Object.
*/
struct QBRecord
{
	QBRecord(const uint32_t column0, const std::string &column1, const long column2, const std::string &column3) :
		m_column0(column0),
		m_column1(column1),
		m_column2(column2),
		m_column3(column3)
	{}

	friend bool operator==(const QBRecord &qbRecord, const uint32_t column0);
	friend std::ostream& operator<<(std::ostream& os, const QBRecord& rec);

	uint32_t m_column0; // unique id column
	std::string m_column1;
	long m_column2;
	std::string m_column3;

}; // QBRecord

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

/*
	DatabaseInterfaceHelperVector represents interface with static functions for working with QBRecordCollection-s.
*/
struct DatabaseInterfaceHelper
{
	enum class COLUMNS { COLUMN_0 = 0, COLUMN_1, COLUMN_2, COLUMN_3, NUMBER_OF_COLUMNS};

	using TimeCollectionType = std::vector<double>;

	/**
		All the unique times for the collection.
	*/
	static TimeCollectionType m_times;

	/**
		Represents a Record Collections
	*/
	using QBRecordCollection = std::vector<QBRecord>;

	/**
		PrintStatistics prints the mean and medium avarage, minimum and maximum time for every data type.
	*/
	static void PrintStatistics();

	/**
		PopulateDummyData is utility to populate a record collection.
		@param records			the record collection we are going to populate
		@param prefix			prefix for the string value for every record
		@param numRecords		number of records to populate in the collection
	*/
	static void PopulateDummyData(QBRecordCollection &records, const std::string &prefix, int numRecords);

	/**
		QBFindMatchingRecords finds matching records in specified column.
		@param resourceRecords	the resource record collection we are searching in
		@param returnRecords	the return record collection populated with the matching records
		@param columnName		the column of the search
		@param matchString		the value we are looking for
		*/
	static void QBFindMatchingRecords(const QBRecordCollection &resourceRecords, QBRecordCollection &returnRecords,
		const COLUMNS column, const std::string &matchString);

	/**
		DeleteRecordByID uses erase-remove idiom delete a record in the collection with a given id.
		@param records			the record collection
		@param id				the id of the record we are looking for to delete
	*/
	static void DeleteRecordById(QBRecordCollection &records, uint32_t id);

}; // DatabaseInterfaceHelper

} // namespace qb
