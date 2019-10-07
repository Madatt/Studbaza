#include <iostream>

void v_alloc_table_add_5(int iSize)
{
  if(iSize <= 0)
    return;

  int *tab = new int[iSize];
  for(int i = 0; i < iSize; i++)
    tab[i] = i + 5;

  for(int i = 0; i < iSize; i++)
    std::cout << tab[i] << " ";

  std::cout << std::endl;

  delete [] tab;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
  if (iSizeX <= 0 or iSizeY <= 0)
    return false;

  int **tab = new int*[iSizeX];
  for(int i = 0; i < iSizeX; ++i)
    tab[i] = new int[iSizeY];

  *piTable = tab;
  return true;
}


bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
  if (iSizeX <= 0 or iSizeY <= 0)
    return false;

  for(int j = 0; j < iSizeX; ++j)
    delete [] (*piTable)[j];

  delete [] (*piTable);
  return true;
}

int main()
{
  v_alloc_table_add_5(10);

  int **test;
  b_alloc_table_2_dim(&test, 5, 2);

  for(int i = 0; i < 5; ++i)
  {
    for(int j = 0; j < 2; ++j)
    {
      test[i][j] = i + j;
      std::cout << test[i][j] << " ";
    }
    std::cout << std::endl;
  }

  b_dealloc_table_2_dim(&test, 5, 2);
}
