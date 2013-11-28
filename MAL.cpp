#include <math.h>
#include <iostream>
#include <cstdarg>

using namespace std;


class basicmatrix
{
	private:
	int matrix[300][300];
	int matrix2[300][300];
	int row2;
	int column2;
	int row;
	int column;
	public:
	void makematrix(int x, int y, int * m);
	void makematrix2(int x, int y, int * m);
	void initmatrix(int x, int y);
	void initmatrix2(int x, int y);
	void addmatrix(basicmatrix m);
	void submatrix(basicmatrix m);
	void mulmatrix(basicmatrix m);
	basicmatrix();
	
};

basicmatrix :: basicmatrix()
{
	cout << "What Opperation Are You Using?" << endl;
	string opp;
	cin >> opp;
	bool opper = false;
	bool mul = false;
	bool sub = false;
	bool add = false;
	while (!opper)
	{
		if(opp == "*") 
		{		mul = true;
				sub = false;
				add = false;
				opper = true;
				
		}else if(opp == "-"){
				mul = false;
				sub = true;
				add = false;
				opper = true;
		}else if(opp ==  "+"){
				mul = false;
				sub = false;
				add = true;
				opper = true;
		}else{
			cout << "Sorry but thats not an opperation" << endl;}
	}
		
	int r1;
	int r2;
	int c1;
	int c2;
	int mat1[300];
	int mat2[300];
	cout << "Enter Rows Of Matrix1:" << endl;
	cin >> r1;
	cout << "Enter Columns Of Matrix1" << endl;
	cin >> c1;
	int iiii = 0;
	for (int i = 0; i<r1; i++)
	{
		for (int ii = 0; ii<c1; ii++)
		{
			cout << "Enter Value For [" << i << " , " << ii<< "]:"<< endl;
			cin >> mat1[iiii];
			iiii++;
		}
		
	}
	cout << "Matrix1 is: "<< endl;
	int om1 = 0;
	for (int i = 0; i<r1; i++)
	{
		for (int ii = 0; ii<c1; ii++)
		{
			cout << mat1[om1] << ", ";
			om1 ++;
		}
		cout << endl;
	}
	
			
	cout << "Enter Rows Of Matrix2" << endl;
	cin >> r2;
	cout << "Enter Columns Of Matrix2" << endl;
	cin >> c2;
	int iii = 0;
	for (int i = 0; i<r2; i++)
	{
		for (int ii = 0; ii<c2; ii++)
		{
			cout << "Enter Value For [" << i << " , " << ii<< "]:"<< endl;
			cin >> mat2[iii];
			iii++;
		}
		
	}
	cout << "Matrix2 is: "<< endl;
	int om2 = 0;
	for (int i = 0; i<r2; i++)
	{
		for (int ii = 0; ii<c2; ii++)
		{
			cout << mat2[om2] << ", ";
			om2 ++;
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	
	makematrix(r1,c1, mat1);
	makematrix2(r2, c2, mat2);
	
	if (opper == true)
	{
		if (mul == true)
		{
			mulmatrix(*this);
		}else if (sub == true)
		{
			submatrix(*this);
		}else if (add == true)
		{
			addmatrix(*this);
		}else{
			cout << "Error: Not an opperation" << endl;
		}
	}
				
	
}

void basicmatrix :: initmatrix(int x, int y)
{
	row = x;
	column = y;
	
	
	
	for (int cx = 0; cx<x; cx++)
	{
		for (int cy = 0; cy<y; cy++)
		{
			matrix[cx][cy] = 0;
		}
	}
	
	
	
	
}

void basicmatrix :: initmatrix2(int x, int y)
{
	row2 = x;
	column2 = y;
	
	
	
	for (int cx = 0; cx<x; cx++)
	{
		for (int cy = 0; cy<y; cy++)
		{
			matrix2[cx][cy] = 0;
		}
	}
	
	
	
	
}


void basicmatrix :: makematrix(int x, int y, int *m)
{
	row = x;
	column = y;
	int con = 0;
	
	for (int cx = 0; cx<x; cx++)
	{
		for (int cy = 0; cy<y; cy++)
		{
			matrix[cx][cy] = m[con];
			con++;
		}
	}
	
	
	
	
}

void basicmatrix :: makematrix2(int x, int y,int *m)
{
	row2 = x;
	column2 = y;
	
	int con = 0;
	
	
	for (int cx = 0; cx<x; cx++)
	{
		for (int cy = 0; cy<y; cy++)
		{
			matrix2[cx][cy] = m[con];
		}
	}
	
	
	
}

void basicmatrix :: addmatrix(basicmatrix m)
{
	int sum[m.row][m.column2];
	for (int x = 0; x<m.row; x++)
	{
		for (int y = 0; y<m.column2; y++)
		{
			sum[x][y] = m.matrix[x][y] + m.matrix2[x][y];
			cout<< sum[x][y] << ", ";
		}
		cout<< "" << endl;
		
	}
	
	
}

void basicmatrix :: submatrix(basicmatrix m)
{
	int sum[m.row][m.column2];
	for (int x = 0; x<m.row; x++)
	{
		for (int y = 0; y<m.column2; y++)
		{
			sum[x][y] = m.matrix[x][y] - m.matrix2[x][y];
			cout<< sum[x][y] << ", ";
		}
		cout<< "" << endl;
		
	}
	
	
}
void basicmatrix :: mulmatrix(basicmatrix m)
{
	if (m.column == m.row2)
	{
		
		int matrix1[m.row][m.column2];
		
		for (int cr = 0; cr<m.row; cr++)
		{
			
			for (int cc = 0; cc<m.column2; cc++)
			{
				int sum = 0;
				for (int y = 0; y<m.row2;y++)
				{
					
					
						sum += m.matrix[cr][y] * m.matrix2[y][cc];
						
						
						
					
				}
				matrix1[cr][cc] = sum;
					
			}
		}
		
		for (int mt = 0; mt < m.row; mt++)
		{
			for(int mti = 0; mti < m.column2; mti++)
			{
				cout << matrix1[mt][mti] << ", ";
			}
			cout << endl;
		}
	
	}else{
		cout<<"Error: The Dimensions are not correct for Multiplication"<<endl;
	}	
}

int main()
{
	
	basicmatrix mine;
	
	
	
	
	return 0;
}
