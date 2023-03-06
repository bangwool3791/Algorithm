// Solution #1) dfs È°¿ë
#include "pch.h"

using namespace std;

#define MAX 2147483647

struct tHouse
{
    int r;
    int c;
};

struct tChiken
{
    int r;
    int c;
    bool bVistied;
};


vector<tChiken> vecChicken;
vector<tHouse> vecHouse;

int iDistance = 0;
int iChikenDistance = 0;
int iAnswer = MAX;

int n = 0, m = 0;


void calculateDistance() {

    int cityDistance = 0;
    for (int i = 0; i < vecHouse.size(); i++)
    {
        int minHouseDistance = MAX;
        for (int j = 0; j < vecChicken.size(); j++)
        {
            if (vecChicken[j].bVistied)
            {
                int houseDistance = abs(vecHouse[i].r - vecChicken[j].r) + abs(vecHouse[i].c - vecChicken[j].c);
                if (houseDistance < minHouseDistance)
                {
                    minHouseDistance = houseDistance;
                }
            }
        }
        cityDistance += minHouseDistance;
    }
    if (cityDistance < iAnswer) {
        iAnswer = cityDistance;
    }
}

void selectChicken(int index, int count) 
{
    if(m == count)
    {
        calculateDistance();
    }
    else
    {
        for(int i = index ; i < vecChicken.size(); ++i)
        {
            if (!vecChicken[i].bVistied)
            {
                vecChicken[i].bVistied = true;
                selectChicken(i, count + 1);
                vecChicken[i].bVistied = false;
            }
        }
    }
}

int main() 
{
    scanf("%d %d", &n, &m);

    int flag;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &flag);
            if (flag == 1) { vecHouse.push_back({ i, j }); }
            else if (flag == 2) { vecChicken.push_back({ i, j, false }); }
        }
    }

    selectChicken(0, 0);
    printf("%d", iAnswer);

    return 0;
}