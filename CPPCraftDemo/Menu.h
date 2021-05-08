#pragma once

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
};

} // namespace menu
