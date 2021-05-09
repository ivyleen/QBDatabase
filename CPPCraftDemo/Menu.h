#pragma once

#include "DatabaseInterfaceHelperVector.h"
#include "DatabaseInterfaceHelperMap.h"
#include "DatabaseInterfaceHelperSet.h"

namespace menu
{

struct Menu
{

	/*
		PrintStatistics function prints the mean and medium avarage, minimum and maximum time for every
		data type.
	*/
	static void PrintStatistics();

	/*
		FindVectorRecords function follows the lookup logic of a std::vector as a data type of Record objects.
	*/
	static void FindVectorRecords();

	/*
		FindMapRecords function follows the lookup logic of a std::map as a data type of Record objects.
	*/
	static void FindMapRecords();

	/*
		FindSetRecords function follows the lookup logic of a std::set as a data type of Record objects.
	*/
	static void FindSetRecords();

	/*
		DeleteRecords function deletes records in the already populated data types of Record objects.
	*/
	static void DeleteRecords();

	/*
		PopulateRecordCollections populates the data types of Record objects.
	*/
	static void PopulateRecordCollections();

private:
	static qbVector::DatabaseInterfaceHelper::QBRecordCollection m_dataVector;
	static qbMap::DatabaseInterfaceHelper::QBRecordCollection m_dataMap;
	static qbSet::DatabaseInterfaceHelper::QBRecordCollection m_dataSet;
};

} // namespace menu
