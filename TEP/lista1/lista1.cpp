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

bool b_dealloc_table_2_dim(int **piTable, int iSizeX)
{
  if (iSizeX < 0)
    return false;

  for(int j = 0; j < iSizeX; ++j)
    delete [] (piTable)[j];

  delete [] (piTable);
  return true;
}

int main()
{
  int **piTabTest = NULL;
  int *piTabTest2 = NULL;
  b_alloc_table_2_dim(&piTabTest, 5, 2);
  b_alloc_table_add_5(&piTabTest2, 10);

  v_print_table(piTabTest2, 5);

  piTabTest[1][1] = 22;
  piTabTest[3][1] = 5;
  piTabTest[4][0] = -12;

  std::cout << std::endl;

  v_print_table_2d(piTabTest, 5, 2);

  b_dealloc_table_2_dim(piTabTest, 5);
  delete [] piTabTest2;

  int *piTabTest3 = NULL;

  b_alloc_table_add_5(&piTabTest3, 0);
  delete [] piTabTest3;
}
