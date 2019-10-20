#include <iostream>
#include "constants.h"

void v_print_table(int *piTab, int iSize)
{
  for(int i = 0; i < iSize; i++)
    std::cout << piTab[i] << " ";

  std::cout << std::endl;
}

void v_print_table_2d(int **piTab, int iSizeX, int iSizeY)
{
  for(int i = 0; i < iSizeX; i++)
  {
    for(int j = 0; j < iSizeY; j++)
    {
      std::cout << piTab[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


bool b_alloc_table_add_5(int **piTable, int iSize)
{
  if(iSize < 0)
    return false;

  int *piTab = new int[iSize];
  for(int i = 0; i < iSize; i++)
    piTab[i] = i + OFFSET;

  *piTable = piTab;
  return true;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
  if (iSizeX < 0 or iSizeY < 0)
    return false;

  int **piTab = new int*[iSizeX];
  for(int i = 0; i < iSizeX; ++i)
    piTab[i] = new int[iSizeY];

  *piTable = piTab;
  return true;
}

bool b_dealloc_table_1_dim(int *piTable, int iSize)
{
  if(iSize < 0) return false;
  delete [] (piTable);
  return true;
}


bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
  if (iSizeX < 0 or iSizeY < 0)
    return false;

  for(int j = 0; j < iSizeX; ++j)
    delete [] (piTable)[j];

  delete [] (piTable);
  return true;
}

int main()
{
  int **test = NULL;
  int *test2 = NULL;
  b_alloc_table_2_dim(&test, 5, 2);
  b_alloc_table_add_5(&test2, 10);

  v_print_table(test2, 5);

  test[1][1] = 22;
  test[3][1] = 5;
  test[4][0] = -12;

  v_print_table_2d(test, 5, 2);

  b_dealloc_table_2_dim(test, 5, 2);
  b_dealloc_table_1_dim(test2, 10);

  int *test3 = NULL;

  b_alloc_table_add_5(&test3, 0);
  b_dealloc_table_1_dim(test3, 0);
}
