#include <iostream>

using namespace std ;

class Matrix
{
private:
    int row ;
    int col ;
    int* data ;
public :
    Matrix() ; // default constructor
    Matrix (int r, int c, int* num) ; // parameterized constructor
    Matrix (const Matrix& mat) ; // copy constructor to make deep copying
    Matrix& operator= (const Matrix& mat) ; // operator= to make deep copying
    void setRow (int r) ; // set value of row
    void setCol (int c) ; // set value of column
    void setData (int* num) ;// set value of data
    int getRow() ; // get value of row
    int getCol() ; // get value of column
    int* getData() const ; // get value of data
    Matrix operator+  (const Matrix& mat1) ; // operator+ to sum two matrices
    Matrix operator-  (const Matrix& mat1) ; // operator- to subtract 2 matrices
    Matrix operator*  (const Matrix& mat1) ; // operator* to multiply 2 matrices  if mat.col == mat2.row
    Matrix operator+ (int scalar) ; // operator+ to sum matrix with a number
    Matrix operator- (int scalar) ; // operator- to subtract matrix from a number
    Matrix operator* (int scalar) ; // operator* to multiply matrix with a number
    Matrix* operator+=  (Matrix& mat1) ; // mat1 changes & return new matrix with the sum
    Matrix* operator-=  (Matrix& mat1) ; // mat1 changes & return new matrix with the difference
    Matrix* operator+= (int scalar) ; // change mat & return new
    Matrix* operator-= (int scalar) ; // change mat & return new
    void operator++ () ; // Add 1 to each element ++mat
    void operator-- () ; // Sub 1 from each element --mat
    bool operator == ( const Matrix& mat1) ; // True if identical
    bool operator != ( const Matrix& mat1) ; // True if not same
    bool isSquare (const Matrix& mat) ; // True if square matrix
    bool isSymetric (const Matrix& mat) ; // True if square and symmetric
    bool isIdentity (const Matrix& mat) ; // True if square and identity
    Matrix transpose  (const Matrix& mat) ; // Return new matrix with the transpose
    friend istream& operator>> (istream& in, Matrix& mat) ; // Input matrix
    friend ostream& operator<< (ostream& out, const Matrix& mat) ; // output matrix
    ~Matrix () ;
};
