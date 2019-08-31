// Merge Sort求逆序对
int tmp[N]; 
int cnt;
void mergeSort(int *a, int l, int r)
{
    if(l == r)
        return;
    int mid = (l+r)>>1;

    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);

    int i=l;
    int j=mid+1;
    int k=l;

    while(i<=mid && j<=r)
    {
        if(a[i]<a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=r)
        tmp[k++] = a[j++];

    for(i=l;i<=r;i++)
        a[i]=tmp[i];
}