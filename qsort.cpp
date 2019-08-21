void qsort(int *a,int l,int r)
{
    int temp,i=l,j=r,mid=a[(l+r)/2];

    do
    {
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;j--;
        }
    } while(i<=j);

    if(j>l) qsort(a,l,j);
    if(i<r) qsort(a,i,r);

}