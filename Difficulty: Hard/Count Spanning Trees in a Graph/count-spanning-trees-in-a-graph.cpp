class Solution {
  public:
  
    // Function to calculate determinant using Gaussian Elimination
    long long determinant(vector<vector<double>> mat, int n) {
        double det = 1;

        for (int i = 0; i < n; i++) {
            int pivot = i;

            // Find pivot row
            for (int j = i + 1; j < n; j++) {
                if (abs(mat[j][i]) > abs(mat[pivot][i])) {
                    pivot = j;
                }
            }

            // If pivot element is 0
            if (abs(mat[pivot][i]) < 1e-9)
                return 0;

            // Swap rows if needed
            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            // Eliminate below rows
            for (int j = i + 1; j < n; j++) {
                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {

        // Special case
        if (n == 1) return 1;

        // Step 1: Create Laplacian Matrix
        vector<vector<double>> lap(n, vector<double>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Step 2: Create Cofactor Matrix
        vector<vector<double>> cofactor(n - 1, vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cofactor[i][j] = lap[i][j];
            }
        }

        // Step 3: Determinant of cofactor matrix
        return determinant(cofactor, n - 1);
    }
};

