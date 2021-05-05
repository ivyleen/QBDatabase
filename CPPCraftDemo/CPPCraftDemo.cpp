#include "stdafx.h"

#include "DatabaseInterfaceHelperVector.h"

int main(int argc, _TCHAR* argv[])
{
    std::cout << "============== VECTOR =========================================================================" << std::endl;
    {
        qbVector::DatabaseInterfaceHelperVector dbInterface;

        // Populate a bunch of data.
        qbVector::DatabaseInterfaceHelperVector::QBRecordCollection data;
        dbInterface.PopulateDummyData(data, "testdata", 1000);

        // Find a record that contains and measure the performance.
        for (int i = 0; i < 1000; ++i)
        {
            auto startTimer = std::chrono::steady_clock::now();

            qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result0;
            dbInterface.QBFindMatchingRecords(data, result0, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_0, "424");

            qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result1;
            dbInterface.QBFindMatchingRecords(data, result1, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_1, "testdata500");

            qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result2;
            dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_2, "24");

            qbVector::DatabaseInterfaceHelperVector::QBRecordCollection result3;
            dbInterface.QBFindMatchingRecords(data, result2, qbVector::DatabaseInterfaceHelperVector::COLUMNS::COLUMN_3, "424testdata");

            std::cout << "vector: " <<
                double((std::chrono::steady_clock::now() - startTimer).count()) * std::chrono::steady_clock::period::num /
                std::chrono::steady_clock::period::den << std::endl;
        }
    }
	return 0;
}

