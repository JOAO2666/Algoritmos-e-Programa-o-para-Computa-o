#include <stdio.h>

int main()
{
    int i, j, matriz[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ",  matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

float mat[4][3]= {{5.0,10.0,15.0},{20.0,25.0,30.0},
    {35.0,40.0,45.0},{50.0,55.0,60.0}
};

float mat [][3]= {5.0, 10.0, 15.0, 20.0, 25.0, 30.0,
                  35.0,40.0,45.0,50.0,55.0,60.0
                 };

float media(float a[][2], int lin)
{
    int i;
    float avg, sum=0.0;
    for(i=0; i<lin; ++i)
    {
        for(j=0; i<2; ++j)
            sum+=a[i][j];
    }
    avg =(sum/(lin*2));
    return avg;
}


