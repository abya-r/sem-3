#include <iostream>
using namespace std;

void printTriplet(int triplet[][3], int nonZeros)
{
    cout << "\nTriplet Representation:\n";
    cout << "Row\tCol\tValue\n";
    cout << "---------------------\n";
    // First row: Total Rows | Total Cols | Total Non-Zero Elements
    for (int i = 0; i <= nonZeros; i++)
    {
        cout << triplet[i][0] << "\t" << triplet[i][1] << "\t" << triplet[i][2] << "\n";
    }
}

void processMatrix(int M, int N)
{
    int matrix[M][N];
    int zeros = 0, nonZeros = 0;

    cout << "Enter elements of the " << M << "x" << N << " matrix:\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
                zeros++;
            else
                nonZeros++;
        }
    }

    // Check if matrix qualifies as sparse
    if (zeros > nonZeros)
    {
        cout << "\nThe matrix is SPARSE.\n";

        // Triplet matrix stores nonZeros + 1 rows and 3 columns
        int triplet[nonZeros + 1][3];

        // First row header: M | N | nonZeros
        triplet[0][0] = M;
        triplet[0][1] = N;
        triplet[0][2] = nonZeros;

        int k = 1;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] != 0)
                {
                    triplet[k][0] = i;            // Row index
                    triplet[k][1] = j;            // Column index
                    triplet[k][2] = matrix[i][j]; // Value
                    k++;
                }
            }
        }

        printTriplet(triplet, nonZeros);
    }
    else
    {
        cout << "\nThe matrix is NOT SPARSE.\n";
        cout << "Displaying original " << M << "x" << N << " matrix:\n";
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main()
{
    int M, N;
    cout << "enter M and N: ";
    cin >> M >> N;

    processMatrix(M, N);

    return 0;
}