// C++ program to merger three sorted arrays
// by merging three simultaneously.
#include <iostream>
#include <vector>
using namespace std;

using Vector = vector<int>;

void printVector(const Vector &a)
{
    cout << "[";
    for (auto e : a)
    {
        cout << e << " ";
    }
    cout << "]" << endl;
}

Vector mergeThree(Vector &A, Vector &B,
                  Vector &C)
{
    int m, n, o, i, j, k;
    // Get Sizes of three vectors
    m = A.size();
    n = B.size();
    o = C.size();

    // Vector for storing output
    Vector D;
    D.reserve(m + n + o);

    i = j = k = 0;

    while (i < m && j < n && k < o)
    {

        // Get minimum of a, b, c
        int mn = min(min(A[i], B[j]), C[k]);

        // Put m in D
        D.push_back(mn);

        // Increment i, j, k
        if (mn == A[i])
            i++;
        else if (mn == B[j])
            j++;
        else
            k++;
    }

    // C has exhausted
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(B[j]);
            j++;
        }
    }

    // B has exhausted
    while (i < m && k < 0)
    {
        if (A[i] <= C[j])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(C[j]);
            k++;
        }
    }

    // A has exhausted
    while (j < n && k < 0)
    {
        if (B[j] <= C[k])
        {
            D.push_back(B[j]);
            j++;
        }
        else
        {
            D.push_back(C[j]);
            k++;
        }
    }

    // A and B have exhausted
    while (k < o)
        D.push_back(C[k++]);

    // B and C have exhausted
    while (i < m)
        D.push_back(A[i++]);

    // A and C have exhausted
    while (j < n)
        D.push_back(B[j++]);

    return D;
}

int main()
{
    Vector A = {1, 2, 3, 4};
    Vector B = {1, 2, 3, 4, 5};
    Vector C = {1, 2, 3, 4, 5, 6};

    // Print Result
    printVector(mergeThree(A, B, C));
    return 0;
}
