#include <stdio.h>
#define MAX_N 100
#define MAX_M 100

int n, m, i, j;
int matris[100][100];

int ziyaret_edildi[100][100];

int main()
{

    printf("Lutfen Matrisin boyutunu giriniz:");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("matris[%d][%d]", i, j);
            scanf("%d", &matris[i][j]);
            ziyaret_edildi[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (matris[i][0] != 0 && !ziyaret_edildi[i][0])
        {
            int yol_id = matris[i][0];
            int yol_uzunlugu = 0;
            int yigin[MAX_N * MAX_M][2];
            int ust = 0;
            yigin[ust][0] = i;
            yigin[ust][1] = 0;
            ust++;

            while (ust > 0)
            {
                ust--;
                int x = yigin[ust][0];
                int y = yigin[ust][1];

                if (!(x < 0 || x >= n || y < 0 || y >= m || ziyaret_edildi[x][y] || matris[x][y] != yol_id))
                {
                    ziyaret_edildi[x][y] = 1;
                    yol_uzunlugu++;
                    yigin[ust][0] = x + 1;
                    yigin[ust][1] = y;
                    ust++;
                    yigin[ust][0] = x - 1;
                    yigin[ust][1] = y;
                    ust++;
                    yigin[ust][0] = x;
                    yigin[ust][1] = y + 1;
                    ust++;
                    yigin[ust][0] = x - 1;
                    yigin[ust][1] = y - 1;
                    ust++;
                    yigin[ust][0] = x + 1;
                    yigin[ust][1] = y - 1;
                    ust++;
                    yigin[ust][0] = x - 1;
                    yigin[ust][1] = y + 1;
                    ust++;
                    yigin[ust][0] = x + 1;
                    yigin[ust][1] = y + 1;
                    ust++;
                }
            }

            int son_sutuna_ulasti = 0;
            for (j = 0; j < n && !son_sutuna_ulasti; j++)
            {
                if (ziyaret_edildi[j][m - 1] && matris[j][m - 1] == yol_id)
                {
                    son_sutuna_ulasti = 1;
                }
            }
            if (son_sutuna_ulasti)
            {
                printf("Yol %d --> %d\n", yol_id, yol_uzunlugu);
            }
        }
    }

    return 0;
}
