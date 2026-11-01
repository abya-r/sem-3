#include <iostream>
using namespace std;

void analyzeTriplet(int triplet[][3], int numNonZero)
{
    int totalRows = triplet[0][0];

    // Array to store count of non-zero elements for each original row
    int rowCounts[totalRows] = {0};

    // Step 1: Count non-zeros per row directly from triplet
    for (int i = 1; i <= numNonZero; i++)
    {
        int rowIdx = triplet[i][0];
        rowCounts[rowIdx]++;
    }

    // Step 2: Find row with maximum non-zero count
    int maxRow = 0;
    int maxCount = rowCounts[0];

    for (int r = 1; r < totalRows; r++)
    {
        if (rowCounts[r] > maxCount)
        {
            maxCount = rowCounts[r];
            maxRow = r;
        }
    }

    // Step 3: Display results
    cout << "\n--- Result ---\n";
    cout << "Row number with max non-zero elements: " << maxRow << endl;
    cout << "Number of non-zero elements in row " << maxRow << ": " << maxCount << endl;
    cout << "Non-zero elements (Column, Value):\n";

    for (int i = 1; i <= numNonZero; i++)
    {
        if (triplet[i][0] == maxRow)
        {
            cout << "Col: " << triplet[i][1] << " | Value: " << triplet[i][2] << endl;
        }
    }
}

int main()
{
    int totalRows, totalCols, numNonZero;
    cout << "Enter total rows, total cols, and number of non-zero elements: ";
    cin >> totalRows >> totalCols >> numNonZero;

    int triplet[numNonZero + 1][3];

    // Header row
    triplet[0][0] = totalRows;
    triplet[0][1] = totalCols;
    triplet[0][2] = numNonZero;

    cout << "Enter triplet rows (row col value):\n";
    for (int i = 1; i <= numNonZero; i++)
    {
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }

    analyzeTriplet(triplet, numNonZero);

    return 0;
}