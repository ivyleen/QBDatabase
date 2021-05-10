#pragma once

#include "DatabaseInterfaceHelperVector.h"
#include "DatabaseInterfaceHelperMap.h"
#include "DatabaseInterfaceHelperSet.h"

#ifdef MULTI_INDEX
#include "DatabaseInterfaceHelperMultiIndex.h"
#endif

namespace menu
{

struct Menu
{
	using VectorHelper		=	qbVector::DatabaseInterfaceHelper;
	using MapHelper			=	qbMap::DatabaseInterfaceHelper;
	using SetHelper			=	qbSet::DatabaseInterfaceHelper;

#ifdef MULTI_INDEX
	using MultiIndexHelper	=	qbMultiIndex::DatabaseInterfaceHelper;
#endif

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
	static VectorHelper::QBRecordCollection m_dataVector;
	static MapHelper::QBRecordCollection m_dataMap;
	static SetHelper::QBRecordCollection m_dataSet;
};

} // namespace menu
