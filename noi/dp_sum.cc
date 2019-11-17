/*
demonstrate dynamic programming to find maximal sum problem from input array

*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int dpSolver(vector<int> *inmat, int nrow, int ncol);

int dpSolver(vector<int> *inmat, int nrow, int ncol) {
    int sum = 0;

    //initialization
    vector<int> v1(ncol), v2(ncol);
    vector<int> *pv1, *pv2;
    for(int i = 0; i < ncol; i++)
        v1[i] = inmat[0][i];
    //bottom-up method
    for(int r = 1; r < nrow; r++) {
        for(int c = 0; c < ncol; c++) {
            //at current state (r, c), it is from states ((r-1)-th row, column: c-1, c, c+1), get maximal 
            int mxv = -numeric_limits<int>::infinity();
            for(int c0 = c - 1; c0 <= c + 1; c0++) {
                if(c0 >= 0 && c0 < ncol) {
                    if(v1[c0] > mxv) {
                        mxv = v1[c0];
                    }
                }
            }
            v2[c] = mxv + inmat[r][c];
            //cout<<mxv<<" "<<inmat[r][c]<<" "<<v2[c]<<endl;
        }
        //exchange pointer, pv1 always point to previous sum, and pv2: latest 
        v1.assign(v2.begin(), v2.end());
        v2.assign(ncol, 0);
    }
    //get result
    int mxv = -numeric_limits<int>::infinity();
    for(int c0 = 0; c0 < ncol; c0++) {
        if(v1[c0] > mxv) {
            mxv = v1[c0];
        }
    }

    return mxv;

}

int main() {
    int nRow, nCol;
    cout << "input size of array: row, column" << endl;
    cin >> nRow >> nCol;
    vector<vector<int>> inMat;
    cout << "input array" << endl;
    for(int i = 0; i < nRow; i++) {
        vector<int> tmpv;
        int vv;
        for(int j = 0; j < nCol; j++) {
            cin >> vv;
            tmpv.push_back(vv);
        }
        inMat.push_back(tmpv);
    }
    int sum = dpSolver(&inMat[0], nRow, nCol);

    cout<<sum<<endl;
}