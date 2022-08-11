//Add it to the original vector code.    
void Vector::shift_right(int s=0){
    int j,i=0 ,shift=s%size , *new_arr=new int[capacity]{};
    j=i+shift;
    for(i;i<size;i++){
        if(j==size)j=0;
        new_arr[j]=arr[i];
        j++;
    }
    swap(new_arr,arr);
    delete [] new_arr;
    }

void Vector::shift_left(int s=0){
    int j,i=size-1 ,shift=s%size , *new_arr=new int[capacity]{};
    j=i-shift;
    for(i;i>=0;i--){
        if(j==-1) j=size-1;
        new_arr[j]=arr[i];
        j--;
    }
    swap(new_arr,arr);
    delete [] new_arr;
    }
