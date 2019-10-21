#include <iostream>
#include "constants.h"



bool b_show_table_2_dim(int **piTab, int iSizeX, int iSizeY)
{
  if(iSizeX < 0 or iSizeY < 0)
    return false;

  for(int i = 0; i < iSizeX; i++)
  {
    for(int j = 0; j < iSizeY; j++)
    {
      std::cout << piTab[i][j] << ";";
      if(j != iSizeY - j)
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  return true;
}

bool b_fill_increasing_table_2_dim(int **piTab, int iSizeX, int iSizeY)
{
  if(iSizeX < 0 or iSizeY < 0)
    return false;


  int i_count = 0;
  for(int i = 0; i < iSizeX; i++)
  {
    for(int j = 0; j < iSizeY; j++)
    {
      piTab[i][j] = i_count++;
    }
  }

  return true;
}

bool b_copy_values_table_2_dim(int **piTab1, int iSizeX1, int iSizeY1, int **piTab2, int iSizeX2, int iSizeY2)
{
  if(iSizeX1 < 0 or iSizeY1 < 0 or iSizeX2 < 0 or iSizeY2 < 0)
    return false;

  int i_x = iSizeX1 < iSizeX2 ? iSizeX1 : iSizeX2;
  int i_y = iSizeY1 < iSizeY2 ? iSizeY1 : iSizeY2;
  for(int i = 0; i < i_x; i++)
  {
    for(int j = 0; j < i_y; j++)
    {
      piTab2[i][j] = piTab1[i][j];
    }
  }

  return true;
}

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

  *piTable = new int[iSize];
  for(int i = 0; i < iSize; i++)
    (*piTable)[i] = i + OFFSET;

  return true;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
  if (iSizeX < 0 or iSizeY < 0)
    return false;

  *piTable = new int*[iSizeX];
  for(int i = 0; i < iSizeX; ++i)
    (*piTable)[i] = new int[iSizeY];

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
  int **pi_test = NULL;
  int *pi_test2 = NULL;
  b_alloc_table_2_dim(&pi_test, 5, 2);
  b_alloc_table_add_5(&pi_test2, 10);

  pi_test[1][1] = 22;
  pi_test[3][1] = 5;
  pi_test[4][0] = -12;

  int **pi_test4 = NULL;
  b_alloc_table_2_dim(&pi_test4, 7, 3);
  b_show_table_2_dim(pi_test4, 7, 3);

  b_fill_increasing_table_2_dim(pi_test4, 7, 3);
  b_show_table_2_dim(pi_test, 5, 2);
  std::cout << std::endl;
  b_show_table_2_dim(pi_test4, 7, 3);
  std::cout << std::endl;
  b_copy_values_table_2_dim(pi_test4, 7, 3, pi_test, 5, 2);
  b_show_table_2_dim(pi_test, 5, 2);
  std::cout << std::endl;

  int **pi_test5 = NULL;
  b_alloc_table_2_dim(&pi_test5, 7, 3);

  b_copy_values_table_2_dim(pi_test, 5, 2, pi_test5, 7, 3);
  b_show_table_2_dim(pi_test5, 7, 3);
  std::cout << std::endl;

  b_dealloc_table_2_dim(pi_test4, 7);
  b_dealloc_table_2_dim(pi_test5, 5);



  b_dealloc_table_2_dim(pi_test, 5);
  delete [] pi_test2;

  int *pi_test3 = NULL;

  b_alloc_table_add_5(&pi_test3, 0);
  delete [] pi_test3;

}
