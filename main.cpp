// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 1
// Program: CS213-2018-A11-T1-P1
// Purpose: Make operations on matrices
// Author:  Nouran Qassem & Nehal Akram
// Date:    18 September  2018
// Version: 1.0

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix mat1, mat2 , mat3 , mat4 ;
    int x, r , c , r1  ,c1  ;

    cout << " Row = " ;
    cin >> r ;
    cout << " Columns = " ;
    cin >> c ;

    mat1.setRow(r) ;
    mat1.setCol(c) ;

    int* data1 = new int [ r * c ] ;

    for (int i = 0 ; i < r*c ; i++ )
    {
        cin >> data1[i] ;
    }
    mat1.setData(data1) ;

    cout << " Row = " ;
    cin >> r1 ;
    cout << " Columns = " ;
    cin >> c1 ;

    mat2.setRow(r1) ;
    mat2.setCol(c1) ;

    int* data2 = new int [ r1 * c1 ] ;

    for (int i = 0 ; i < r1*c1 ; i++ )
    {
        cin >> data2[i] ;
    }
    mat2.setData(data2) ;

    if (r == r1 && c == c1)
    {
        cout << "mat1 + mat2 =  " << endl << mat1 + mat2 << endl ;
    }
    else
    {
        cout << " Not the same dimensions can't be added " << endl ;
    }

    if (r == r1 && c == c1)
    {
        cout << "mat1 - mat2 =  " << endl << mat1 - mat2 << endl ;
    }
    else
    {
        cout << " Not the same dimensions can't be added " << endl ;
    }

    if (c == r1)
    {
        cout << "mat1 * mat2 =  " << endl << mat1 * mat2 << endl ;
    }
    else
    {
        cout << " Not the same dimensions can't be added " << endl ;
    }

    cout << "Enter a number to be added " ;
    cin >> x ;
    cout << " mat1 + " << x << " = " << endl << mat1 + x  << endl ;

    cout << "Enter a number to subtracted " ;
    cin >> x ;
    cout << " mat2 - " << x << " = " << endl << mat2-x << endl  ;

    cout << " Enter a number to be multiplied " ;
    cin >> x ;
    cout << "mat1 * " << x << " = " << endl << mat1*x << endl ;

    if (r == r1 && c == c1)
    {
        mat1 += mat2 ;
        cout << " mat1 += mat2 " << endl << mat1 << endl  ;
    }
    else
    {
        cout << "two matrices are not the same dimensions " << endl ;
    }

    if (r== r1 && c==c1)
    {
        mat1 -= mat2 ;
        cout << " mat1 -= mat2 " << endl << mat1 << endl  ;
    }
    else
    {
        cout << "two matrices are not the same dimensions " << endl ;
    }

    cout << "Enter a number to be added " ;
    cin >> x ;
    mat1 += x ;
    cout << " mat1 += " << x << " = " << endl << mat1  << endl ;

    cout << "Enter a number to subtracted " ;
    cin >> x ;
    mat2 -= x ;
    cout << " mat2 -= " << x << " = " << endl << mat2 << endl  ;

    ++mat1 ;
    cout << "++mat1" << endl << mat1 << endl  ;

    --mat2 ;
    cout << " --mat2 " << endl << mat2 << endl ;

    if (mat1 == mat2)
    {
        cout << " two matrices are equal " << endl;
    }
    else
    {
        cout << " two matrices are not equal " << endl ;
    }

    if (mat1 != mat2)
    {
        cout << " two matrices are not equal " << endl;
    }
    else
    {
        cout << " two matrices are equal " << endl ;
    }

    if (mat1.isSquare(mat1))
    {
        cout << " mat1 is square "<< endl ;
    }
    else
    {
        cout << " mat1 is not a square " << endl ;
    }

    if (mat2.isSymetric(mat2))
    {
        cout << " mat2 is symmetric " << endl ;
    }
    else
    {
        cout << " mat2 is not symmetric " << endl ;
    }

    if (mat1.isIdentity(mat1))
    {
        cout << " mat1 is Identity "<< endl ;
    }
    else
    {
        cout << " mat1 is not Identity " << endl ;
    }

    cout <<  mat2.transpose(mat2)  ;

    delete[] data1 ;
    delete[] data2 ;
}
