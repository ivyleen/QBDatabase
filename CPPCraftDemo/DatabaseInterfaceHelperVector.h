#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <functional>


// Encapsulation in namespace
namespace qbVector
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
	DatabaseInterfaceHelperVector represents interface with static functions for working with QBRecordCollection-s.
*/
struct DatabaseInterfaceHelperVector
{
	enum class COLUMNS { COLUMN_0 = 0, COLUMN_1, COLUMN_2, COLUMN_3, NUMBER_OF_COLUMNS};

	/**
		Represents a Record Collections
	*/
	using QBRecordCollection = std::vector<QBRecord>;

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
}; // DatabaseInterfaceVector

} // namespace qb
