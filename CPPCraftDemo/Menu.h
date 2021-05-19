#pragma once

#include "stdafx.h"

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
		FindVectorRecords function follows the lookup logic of a std::vector as a data type of QBRecord objects.
	*/
	static void FindVectorRecords();

	/*
		FindMapRecords function follows the lookup logic of a std::map as a data type of QBRecord objects.
	*/
	static void FindMapRecords();

	/*
		FindSetRecords function follows the lookup logic of a std::set as a data type of QBRecord objects.
	*/
	static void FindSetRecords();

#ifdef MULTI_INDEX
	/*
		FindSetRecords function follows the lookup logic of a boost::multi_index as a data type of QBRecord objects.
	*/
	static void FindMultiIndexRecords();
#endif
	/*
		PrintStatistics function prints the mean and medium avarage, minimum and maximum time for every
		data type.
	*/
	static void PrintStatistics();

	/*
		DeleteRecords function deletes records in the already populated data types of QBRecord objects.
	*/
	static void DeleteRecords();

	/*
		PopulateRecordCollections populates the data types of Record objects.
	*/
	static void PopulateRecordCollections();

	/*
		ClearTimes clear the stashed times between the tests.
	*/
	static void ClearTimes();

private:
	/*
		UnitTestFindMatches function.
	*/
	static void UnitTestFindMatches(size_t sizeResult0, size_t sizeResult1, size_t sizeResult2, size_t sizeResult3);

	static VectorHelper::QBRecordCollection m_dataVector;
	static MapHelper::QBRecordCollection m_dataMap;
	static SetHelper::QBRecordCollection m_dataSet;

	static bool m_shouldBeFound;
};

} // namespace menu
