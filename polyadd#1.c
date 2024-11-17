//polynomial addition using struct
#include <stdio.h>
struct poly{
    int coeff;
    int expo;
};
struct poly p1[10], p2[10], result[10];

int readPoly(struct poly[]);
int addPoly(struct poly[], struct poly[], int, int, struct poly[]);
void displayPoly(struct poly[], int);

int readPoly(struct poly p[10])
{
    int t1, i;
    printf("enter total no of terms: ");
    scanf("%d", &t1);
    printf("enter coeff and expo in descending order\n");
    for(i=0;i<t1;i++)
    {
        printf("enter coeff: ");
        scanf("%d",&p[i].coeff);
        printf("enter expo: ");
        scanf("%d",&p[i].expo);
    }
    return t1;
}

void displayPoly(struct poly p[10], int t)
{
    int i;
    for(i=0;i<t-1;i++)
    {
        printf("%d(x^%d)+ ",p[i].coeff, p[i].expo);
    }
    printf("%d(x^%d) ",p[t-1].coeff, p[t-1].expo);
}

int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly result[10])
{
    int i=0, j=0, k=0;
    while(i<t1&&j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
        result[k].expo=p1[i].expo;
        result[k].coeff=p1[i].coeff+p2[j].coeff;
        i++;
        j++;
        k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            result[k].expo=p1[i].expo;
            result[k].coeff=p1[i].coeff;
            k++;
            i++;
        }
        else 
        {
            result[k].expo=p2[j].expo;
            result[k].coeff=p2[j].coeff;
            k++;
            j++;
        }
    }
    while (i < t1) 
    {
        result[k].expo = p1[i].expo;
        result[k].coeff = p1[i].coeff;
        i++;
        k++;
    }
    while (j < t2) 
    {
        result[k].expo = p2[j].expo;
        result[k].coeff = p2[j].coeff;
        j++;
        k++;
    }
    return k;
}

void main()
{
    int t1,t2,t3;
    printf("enter details of 1st polynomial\n");
    t1= readPoly(p1);
    displayPoly(p1,t1);
    printf("\nenter details of 2nd polynomial\n");
    t2= readPoly(p2);
    displayPoly(p2,t2);
    t3= addPoly(p1, p2, t1, t2, result);
    printf("\nresultant: \n");
    displayPoly(result,t3);
}
