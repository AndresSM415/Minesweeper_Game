#include "minesweeper.h"
int MI = 10;

int main()
{
    while(1)
    {
    char** mapa;
    int** minas;

    minas = (int**)malloc(sizeof(int*)*MI);
    mapa = (int**)malloc(sizeof(int*)*MI);
    for(int j = 0; j < MI; j++)
    {
        minas[j] = (int*)malloc(sizeof(int)*MI);
        mapa[j] = (int*)malloc(sizeof(int)*MI);
        for(int i = 0; i < MI; i++)
        {
            minas[j][i] = 0;
            mapa[j][i] = '#';
        }
    }
    for(int j = 0; j < MI; j++)
    {
        for(int i = 0; i < MI; i++)
        {
            minas[j][i] = 0;
            mapa[j][i] = '#';
        }
    }

    /*printf("cuantas minas quieres?: \n");
    int c, noMinas = 0;
    while(isdigit(c = getchar()))
        noMinas = noMinas*10 + c - '0';
    for(int i = 0; i <= noMinas; i++)
        minas[rand()%10][rand()%10] = 9;
*/
    minas[0][0] = minas[0][1] = minas[0][2] = minas[0][3] = minas[0][4] = 9;//marca minas
    minas[4][0] = minas[4][1] = minas[4][2] = minas[4][3] = minas[4][4] = 9;
                  minas[1][0] = minas[2][0] = minas[3][0] = 9;
                  minas[1][4] = minas[2][4] = minas[3][4] = 9;
    /////////////////////////////////////////////////////////////////

    cuentaMinas(minas);
    while(1)
    {
    int j, i, estado, coordenadas;
    while((coordenadas =coordenada(&j, &i)) == -1){}
    if((estado = muestraPos(minas, mapa, j, i, coordenadas)) == -1)
    {
        printf("perdiste!\n");
        imprimeMapa(mapa);
        break;
    }
    else if(estado == 1)
    {
        printf("ganaste!\n");
        break;
    }

    imprimeMapa(mapa);
    }
    for(int j = 0; j < MI; j++)
    {
        free(minas[j]);
        free(mapa[j]);
    }
    free(minas);
    free(mapa);
    }
    return 0;
}
