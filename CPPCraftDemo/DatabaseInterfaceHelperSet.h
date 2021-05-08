#pragma once

#include <string>

#include <set>
#include <chrono>


// Encapsulation in namespace
namespace qbSet
{

/**
	Represents a Record Object.
*/
struct QBRecord
{
	uint32_t column0; // unique id column
	std::string column1;
	long column2;
	std::string column3;

	friend bool operator==(const QBRecord &qbRecord, const uint32_t column0);

}; // QBRecord

// ---------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------

/*
	DatabaseInterfaceHelperSet represents interface with static functions for working with QBRecordCollection-s.
*/
struct DatabaseInterfaceHelperSet
{
	enum class COLUMNS { COLUMN_0 = 0, COLUMN_1, COLUMN_2, COLUMN_3, NUMBER_OF_COLUMNS};

	using TimeCollectionType = std::set<double>;

	/**
		All the unique times for the collection.
	*/
	static TimeCollectionType m_times;

	/**
		Represents a Record Collections
	*/
	using QBRecordCollection = std::set<QBRecord>;

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
		COLUMNS column, const std::string &matchString);

	/**
		DeleteRecordByID uses erase-remove idiom delete a record in the collection with a given id.
		@param records			the record collection
		@param id				the id of the record we are looking for to delete
	*/
	static void DeleteRecordById(QBRecordCollection &records, uint32_t id);

}; // DatabaseInterfaceHelperSet

} // namespace qb
