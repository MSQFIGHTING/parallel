#include <iostream>
using namespace std;
int main()
{
    // 获取输入：
    int dimension;
    cin >> dimension;
    double **matrix = new double *[dimension];
    for (int i = 0; i < dimension; i++)
    {
        matrix[i] = new double[dimension];
    }
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // 基础的算法：
    for (int i = 1; i <= dimension; i++)
    {
        for (int j = i + 1; j <= dimension; j++)
        {
            matrix[i - 1][j - 1] = matrix[i - 1][j - 1] / matrix[i - 1][i - 1];
        }
        matrix[i - 1][i - 1] = 1.0;
        for (int j = i + 1; j <= dimension; j++)
        {
            for (int k = i + 1; k <= dimension; k++)
            {
                matrix[j - 1][k - 1] = matrix[j - 1][k - 1] - matrix[j - 1][i - 1] * matrix[i - 1][k - 1];
            }
            matrix[j - 1][i - 1] = 0;
        }
    }
}