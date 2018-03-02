#include<stdio.h>
void divide(int a[],int srt,int end);
void merge(int a[],int strt,int mid,int end);
int main(void)
{
int a[50];
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
divide(a,0,n-1);
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}
void divide(int a[],int strt,int end)
{
int mid;
if(strt<end)
{
mid=(strt+end)/2;
divide(a,strt,mid);
divide(a,mid+1,end);
merge(a,strt,mid,end);
}
}
void merge(int a[],int strt,int mid,int end)
{
int i, mi, k, s, temp[50];
s = strt;
i = strt;
mi = mid + 1;
while ((s<= mid) && (mi <= end))
{
if (a[s] <= a[mi])
{
temp[i] = a[s];
s++;
}
else
{
temp[i] = a[mi];
mi++;
}
i++;
}
if (s > mid)
{
for (k = mi; k <= end; k++)
{
temp[i] = a[k];
i++;
}
}
else
{
for (k = s; k <= mid; k++)
{
temp[i] = a[k];
i++;
}
}
for (k = strt; k <= end; k++)
{
a[k] = temp[k];
}
}
