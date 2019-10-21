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
  int **piTest = NULL;
  int *piTest2 = NULL;
  b_alloc_table_2_dim(&piTest, 5, 2);
  b_alloc_table_add_5(&piTest2, 10);

  v_print_table(piTest2, 5);

  piTest[1][1] = 22;
  piTest[3][1] = 5;
  piTest[4][0] = -12;

  v_print_table_2d(piTest, 5, 2);

  b_dealloc_table_2_dim(piTest, 5, 2);
  delete [] piTest2;

  int *piTest3 = NULL;

  b_alloc_table_add_5(&piTest3, 0);
  delete [] piTest3;
}
