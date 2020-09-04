def selection(arr,l):
    for i in range(0,l-1):
        imin=i
        for j in range(i+1,l):
            if arr[j]<arr[imin]:
                imin=j
        arr[i],arr[imin]=arr[imin],arr[i]
    


if __name__ == "__main__":
    arr=[2,1,6,5,7,3]
    l=len(arr)
    selection(arr,l)
    print(arr)