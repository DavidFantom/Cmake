#include "Matrix.h"
#include <math.h>
#include <stdlib.h>


//Конструкторы
Matrix::Matrix(){
}

Matrix::Matrix(bool n){
	if (n==0){
		data = NULL;
		i = 0;
		j = 0;
	}
	else{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;

		data = new float*[i];
		for (int k=0; k < i; k++) {
			data[k] = new float[j];
			for (int h=0; h < j; h++) {
            	data[k][h] = rand() % 101;
            }
		}
	}
}

Matrix::Matrix(int x, int y){
	i = x;
	j = y;

	data = new float*[i];
	for (int k=0; k < i; k++) {
		data[k] = new float[j];
		for (int h=0; h < j; h++) {
			data[k][h] = rand() % 11;
		}
	}
}

Matrix::Matrix(float **m, int r, int c)
{
	i = r;
	j = c;
	data = new float*[i];
	for (int k=0; k < i; k++) {
	data[k] = new float[j];
		for (int h=0; h < j; h++) {
			data[k][h] = m[k][h];
		}
	}
}




//Прикладные свойства
int Matrix::RowCount(){
	return i;
}

int Matrix::ColCount(){
	return j;
}

float Matrix::GetCell(int x, int y){
	return data[x][y];
}


float Matrix::determinant(){
	float res=0;
	if ((i==1)&&(i==j)){
    	res = data[0][0];
	}
	else if ((i==2)&&(i==j)) {
    	res=data[0][0]*data[1][1]-data[0][1]*data[1][0];
	}
	else if ((i>2)&&(i==j)){
    	float **buf;
		buf = new float*[i];
		for (int r=0; r<i; r++) {
			buf[r] = new float[j+2];
			for (int c=0; c<j+2; c++) {
                int cf = c;
				if (c>=j) {
                cf = cf-j;    
				}

				buf[r][c] = data[r][cf];
			}
		}


		for (int d = 0; d < 3; d++) {
			int x = 0;
			int y = d;
			int rx = i-1;
			float diag = 1;
			float r_diag = 1;

			while ((x<i)&&(y<j)){
				diag = diag * buf[x][y];
				r_diag = r_diag * buf[rx][y];
				x++;
				y++;
				rx--;
			}
			res = res + diag - r_diag;
		}
	}
	return res;
}


Matrix Matrix::transpose(){
	if (i==0) {
		return Matrix(0);
	}
	else{
		float **res;

		res = new float*[j];
		for (int r=0; r<j; r++) {
			res[r] = new float[i];
			for (int c=0; c<i; c++) {
				res[r][c] = data[c][r];
			}
		}
		return Matrix(res, j, i);
	}

}


float Matrix::minor(int x,int y){
    float res;
	float **buf;

	if ((this->RowCount() < x) || (this->ColCount() < y) || (x <= 0) || (y <= 0))
	{
		return -32000;
	}

	buf = new float*[i-1];
	for (int r=0; r<i-1; r++) {
		buf[r] = new float[j-1];
		for (int c=0; c<j-1; c++) {
			int rf = r;
			int cf = c;

			if (r>=x) rf++;
			if (c>=y) cf++;
			buf[r][c] = data[cf][rf];
		}
	}

	Matrix min_matr = Matrix(buf, i-1, j-1);
	res = min_matr.determinant();
	return res;
}




//операторы для матриц
Matrix Matrix::operator = (Matrix b){
	float **res;

	res = new float*[b.i];
	for (int r=0; r<b.i; r++) {
		res[r] = new float[b.j];
		for (int c=0; c<b.j; c++) {
			res[r][c] = b.data[r][c];
		}
	}
	this->data = res;
	this->i = b.i;
	this->j = b.j;
	return *this;
}



Matrix Matrix::operator * (float k){
    float **buf = this->data;
	for (int r=0; r<i; r++) {
		for (int c=0; c<j; c++) {
			buf[r][c] = buf[r][c]*k;
		}
	}
	Matrix res = Matrix(buf, i, j);
	return res;
}

Matrix Matrix::operator / (float k){
    float **buf = this->data;
	for (int r=0; r<i; r++) {
		for (int c=0; c<j; c++) {
			buf[r][c] = buf[r][c]/k;
		}
	}
	Matrix res = Matrix(buf, i, j);
	return res;
}



Matrix Matrix::operator + (Matrix b){
	if ((i==0)||(b.i==0)||(i!=b.i)||(j!=b.j)) {
		return Matrix(0);
	}
	else{
		float **res;

		res = new float*[i];
		for (int r=0; r<i; r++) {
			res[r] = new float[j];
			for (int c=0; c<j; c++) {
				res[r][c] = data[r][c] + b.data[r][c];
			}
		}
		return Matrix(res, i, j);
	}
}

Matrix Matrix::operator - (Matrix b){
	if ((i==0)||(b.i==0)||(i!=b.i)||(j!=b.j)) {
		return Matrix(0);
	}
	else{
		float **res;

		res = new float*[i];
		for (int r=0; r<i; r++) {
			res[r] = new float[j];
			for (int c=0; c<j; c++) {
				res[r][c] = data[r][c] - b.data[r][c];
			}
		}
		return Matrix(res, i, j);
	}
}

Matrix Matrix::operator * (Matrix b){
	if ((j!=b.i)||(data==NULL)||(b.data==NULL)) {
		return Matrix(0);
	}
	else{
		float **res;

		res = new float*[i];
		for (int n=0; n <i; n++) {
			res[n] = new float[b.j];
            for (int m=0; m <b.j; m++) {
                float buf =0;

				int c = 0;

				while (c<i){
					buf = buf + data[n][c]*b.data[c][m];
					c++;
				}
				res[n][m] = buf;
			}
		}
		return Matrix(res, i, b.j);
	}
}

Matrix Matrix::operator / (Matrix b){
	float **buf;
	//ShowMessage("gj");
	buf = new float*[b.i];
	for (int r=0; r<b.i; r++) {
		for (int c=0; c<b.j; c++) {
			buf[r] = new float[b.j];

			buf[r][c] = b.minor(r,c);

			if ((r+c)%2!=0) {
            	buf[r][c] = -buf[r][c];
			}

		}
	}
    //ShowMessage("gj");
	Matrix alg_matr = Matrix(buf, b.i ,b.j);
	Matrix t_alg_matr = alg_matr.transpose();


    float det = b.determinant();
	if (det==0) {
    	return Matrix(0);
	}
	float k = 1/det;
	Matrix obr_b = t_alg_matr*k;

	Matrix first = *this;
	Matrix res = first*obr_b;

	return res;
}
