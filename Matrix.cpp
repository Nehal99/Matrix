#include "Matrix.h"
#include <iostream>

using namespace std ;

Matrix::Matrix()
{
    row = 0 ;
    col = 0 ;
}
Matrix:: Matrix (int r, int c, int* num)
{
    row = r ;
    col = c ;
    int* data = new int[row*col] ;
    data = num ;
}
Matrix::Matrix (const Matrix& mat)
{
    row = mat.row ;
    col = mat.col ;
    data = mat.data ;
}
Matrix& Matrix ::operator= (const Matrix& mat)
{
    row = mat.row ;
    col = mat.col ;
    data = mat.data ;
    return* this ;
}
void Matrix :: setRow (int r )
{
    row = r ;
}
void Matrix ::setCol (int  c)
{
    col = c ;
}
void Matrix :: setData (int* num)
{
    data = num ;
}
int Matrix :: getRow ()
{
    return row ;
}
int Matrix :: getCol ()
{
    return col ;
}
int* Matrix :: getData() const
{
    return data ;
}
Matrix Matrix :: operator+  (const Matrix& mat1)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = col ;
    mat.data = new int [row * col] ;

    for (int i = 0 ; i < row * col ; i++)
    {
        mat.data[i] = data[i] + mat1.data[i] ;
    }

    return mat ;
}
Matrix Matrix :: operator-  (const Matrix& mat1)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = col ;
    mat.data = new int [row * col] ;

    for (int i = 0 ; i < row * col ; i++)
    {
        mat.data[i] = data[i] - mat1.data[i] ;
    }

    return mat ;
}
Matrix Matrix  :: operator*  (const Matrix& mat1)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = mat1.col ;
    mat.data = new int [row * mat1.col ] ;

    int** arr = new int* [row] ;

    for (int i = 0 ;  i < row ; i++ )
    {
        arr[i] = new int [col] ;
    }

    int c = 0 ;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            arr[i][j] = data[c] ;
            c++  ;
        }
    }

    int** arr1 = new int* [mat1.row] ;

    for (int i = 0 ;  i < mat1.row ; i++ )
    {
        arr1[i] = new int [mat1.col] ;
    }

    int c1 = 0 ;
    for (int i = 0 ; i < mat1.row ; i++)
    {
        for (int j = 0 ; j < mat1.col ; j++)
        {
            arr1[i][j] = mat1.data[c1] ;
            c1++ ;
        }
    }

    int l = 0, m=0, mult, c2=0, z=0;

    for (int i = 0 ; i < row * mat1.col; i++)
    {
        if ( c2 == mat1.col )
        {
            m++ ;
            l= 0 ;
            c2 = 0;
        }
        mult = 0 ;
        for (int j = 0 ; j < mat1.row ; j++)
        {
            mult +=  (arr[m][j] * arr1[j][l]) ;
        }
        mat.data[z] = mult ;
        l++ ;
        c2++ ;
        z++ ;
    }
    for (int  i = 0 ; i < row ; i++)
    {
        delete [] arr[i] ;
    }

    delete [] arr ;

    for (int  i = 0 ; i < row ; i++)
    {
        delete [] arr1[i] ;
    }
    delete [] arr1 ;

    return mat ;
}
Matrix Matrix :: operator+  (int scalar)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = col ;
    mat.data = new int [row * col] ;
    for (int i=0 ; i < row*col ; i++)
    {
        mat.data[i] = data[i] + scalar ;
    }
    return mat ;
}
Matrix Matrix :: operator-  (int scalar)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = col ;
    mat.data = new int [row * col] ;
    for (int i=0 ; i < row*col ; i++)
    {
        mat.data[i] = data[i] - scalar ;
    }
    return mat ;
}
Matrix Matrix :: operator*  (int scalar)
{
    Matrix mat ;
    mat.row = row ;
    mat.col = col ;
    mat.data = new int [row * col] ;
    for (int i=0 ; i < row*col ; i++)
    {
        mat.data[i] = data[i] * scalar ;
    }
    return mat ;
}
Matrix* Matrix :: operator+= (Matrix& mat1)
{
    for (int i = 0 ; i < row*col ; i++)
    {
        data[i] += mat1.data[i] ;
    }
    return this ;
}
Matrix* Matrix :: operator-= (Matrix& mat1)
{
    for (int i = 0 ; i < row*col ; i++)
    {
        data[i] -= mat1.data[i] ;
    }
    return this ;
}
Matrix* Matrix :: operator+= (int scalar)
{
    for (int i=0 ; i < row*col ; i++)
    {
        data[i] += scalar ;
    }
    return this ;
}
Matrix* Matrix :: operator-= (int scalar)
{
    for (int i=0 ; i < row*col ; i++)
    {
        data[i] -= scalar ;
    }
    return this ;
}
void Matrix ::  operator++ ()
{
    for (int i =0 ; i < row*col ; i++)
    {
        data[i]++ ;
    }
}
void Matrix :: operator-- ()
{
    for (int i =0 ; i < row*col ; i++)
    {
        data[i]-- ;
    }
}
bool Matrix :: operator== (const Matrix& mat1)
{
    if (row != mat1.row || col != mat1.col )
    {
        return false ;
    }
    if (row == mat1.row && col == mat1.col)
    {
        for (int i = 0 ; i < row * col ; i++ )
        {
            if (data[i] != mat1.data[i])
            {
                return false ;
            }
        }
    }
    return true ;
}
bool Matrix :: operator!= (const Matrix& mat1)
{
    if (row == mat1.row && col == mat1.col )
    {
        for (int i = 0 ; i < row * col ; i++ )
        {
            if (data[i] != mat1.data[i])
            {
                return true ;
            }
        }
        return false ;
    }
    return true ;
}
bool Matrix :: isSquare (const Matrix& mat)
{
    if (row == col )
    {
        return true ;
    }
    return false ;
}
bool Matrix :: isSymetric (const Matrix& mat)
{
    int** arr = new int* [row] ;

    for (int i = 0 ;  i < row ; i++ )
    {
        arr[i] = new int [col] ;
    }

    int k = 0 ;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            arr[i][j] = mat.data[k] ;
            k++  ;
        }
    }
    for (int m = 0 ; m < row ; m++)
    {
        for (int n = 0 ; n < col ; n++)
        {
            if (arr[m][n] == arr[n][m])
            {
                continue ;
            }
            else
            {
                for (int  i = 0 ; i < row ; i++)
                {
                    delete [] arr[i] ;
                }
                delete arr ;
                return false ;
            }
        }
    }
    for (int  i = 0 ; i < row ; i++)
    {
        delete arr[i] ;
    }
    delete [] arr ;
    return true ;
}
bool Matrix :: isIdentity (const Matrix& mat)
{
    int index = 0;
    if ( row == col )
    {
        for ( int i = 0; i < (row*col) ; i++ )
        {
            if ( i == index )
            {
                if ( data[ i ] != 1 )
                {
                    return 0;
                }
                index += row + 1 ;
            }
            else
            {
                if ( data[ i ] != 0 )
                    return 0;
            }
        }
        return 1;
    }
}
Matrix Matrix :: transpose  (const Matrix& mat)
{
    Matrix mat1 ;
    mat1.row = row ;
    mat1.col = col ;
    mat1.data = new int [mat1.row * mat1.col] ;

    int** arr = new int* [row] ;

    for (int i = 0 ;  i < row ; i++ )
    {
        arr[i] = new int [col] ;
    }

    int** arr1 = new int* [row] ;

    for (int i = 0 ;  i < row ; i++ )
    {
        arr1[i] = new int [col] ;
    }

    int k = 0, l=0 ;

    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            arr[i][j] = data[k] ;
            k++ ;
        }
    }
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ;  j< col ; j++)
        {
            arr1[i][j] = arr[j][i] ;
            mat1.data[l] = arr1[i][j] ;
            l++ ;
        }
    }

    for (int  i = 0 ; i < row ; i++)
    {
        delete [] arr[i] ;
    }
    delete [] arr ;

    for (int  i = 0 ; i < row ; i++)
    {
        delete [] arr1[i] ;
    }
    delete [] arr1 ;
    return mat1 ;
}
istream& operator>> (istream& in, Matrix& mat)
{
    cout << "Row = " ;
    in >> mat.row ;
    cout << "Column = ";
    in >> mat.col ;

    mat.data=new int[mat.row*mat.col] ;

    for (int i = 0 ; i < (mat.row * mat.col) ; i++)
    {
        in >> mat.data[i] ;
    }

    return in ;
}
ostream& operator<< (ostream& out, const Matrix& mat)
{
    int l=0, k, c1 , c2 ;
    c1 = mat.col ;
    c2 = mat.col ;
    for (int i = 0 ; i < mat.row ; i++ )
    {
        for ( k = l ; k < c2 ; k++)
        {
            out << mat.data[k] << " " ;
        }
        cout << endl ;
        l += c1 ;
        c2 += c1 ;
    }
    return out ;
}
// return type class name :: function name (){}

Matrix :: ~Matrix ()
{
    delete [] data ;
}
