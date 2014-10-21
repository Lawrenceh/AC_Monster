Algo:	
1.	Take two variable ptr1 and ptr2. Initialized both of them to zero 
2.	Take 3rd variable diff initialized with INT_MAX 
3.	While (ptr1 < arr1.length || ptr2 < arr1.length){ 
    If(diff > abs(arr[ptr1]  arr[ptr2])){ 
        Diff = abs(arr[ptr1]  arr[ptr2]) 
    } 
    If(arr[ptr1] > arr[ptr2]) 
        Ptr2++; 
    Else 
        Ptr1++; 

} 
