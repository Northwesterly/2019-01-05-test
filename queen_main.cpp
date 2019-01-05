#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
#define edge 15

int eight_queen[edge][edge] = { 0 ,{0} };
bool row[edge] = { false };
bool column[edge] = { 0 };
bool left_inclined[2 * edge - 1] = { 0 };
bool right_inclined[2 * edge - 1] = { 0 };
int total = 0;
//row_id表示行数，column_id表示列数，取值范围[0,7]
//当检查不符合规则时，返回false，检查符合规则时，返回true，并且修改数列。
bool check_queen(int row_id, int column_id)
{
	if ((row[row_id]) || (column[column_id]) || (left_inclined[column_id - row_id + edge - 1]) || right_inclined[column_id + row_id])
		return false;
	else
	{
		row[row_id] = true;
		column[column_id] = true;
		left_inclined[column_id - row_id + edge - 1] = true;
		right_inclined[row_id + column_id] = true;
		return true;
	}
}

void back_queen(int row_id, int column_id)
{
	row[row_id] = false;
	column[column_id] = false;
	left_inclined[column_id - row_id + edge - 1] = false;
	right_inclined[row_id + column_id] = false;
}

void set_zero()
{
	for (int i = 0; i < 2*edge-1; i++)
	{
		left_inclined[i] = false;
		right_inclined[i] = false;
	}
	for (int i = 0; i < edge; i++)
	{
		row[i] = false;
		column[i] = false;
	}
}

void set_queen(int id)
{
	for (int i = 0; i < edge; i++)
	{
		if (check_queen(id, i))
		{
			if (id == edge-1)
			{
				total++;
			}
			else
			{
				set_queen(id + 1);
			}
			back_queen(id, i);
		}
	}
}

int main()
{
	
	clock_t start_time = clock();
	set_queen(0);
	clock_t end_time = clock();
	cout << total << endl<<(double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}