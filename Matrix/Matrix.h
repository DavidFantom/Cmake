//класс матрица

#ifndef Matrix_define
#define Matrix_define


class Matrix {
	public:

	float **data;
	int i;
	int j;

	

	Matrix();
	Matrix(bool);
	Matrix(int, int);
	Matrix(float **, int, int);

	int RowCount();
	int ColCount();
	float GetCell(int,int);

	float determinant();
	Matrix transpose();
	float minor(int,int);

    Matrix operator = (Matrix);

	Matrix operator * (float);
	Matrix operator / (float);

	Matrix operator + (Matrix);
	Matrix operator - (Matrix);
	Matrix operator * (Matrix);
	Matrix operator / (Matrix);
};
#endif
