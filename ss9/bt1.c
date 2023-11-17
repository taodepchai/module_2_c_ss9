#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
bool prime(int n){
	int i;
	if ( n < 2) {
		return false;
	} else 
	    if (n==2 || n==5 || n==7 || n==3 || n==11) {
	    	return true;
		} else 
		    if (n%2 == 0 || n%3 == 0 ) {
		    	return false;
			}
    i=-1;
    while (i <= sqrt(n)) {
    	i = i + 6;
    	if ( n%i == 0 || n%(i+2) == 0) {
    		return false;
		}
	}
    return true;   	
}
int main(){
	int n,i,choice,sum,temp;
	int check,count;
	int a[99];
	int max,min;
	int add_index,add_value;
	do {
        printf("\n1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2.In ra cac phan tu dang quan ly\n");
		printf("3.In ra gia tri cac phan tu chan va tinh tong\n");
		printf("4.In ra gia tri lon nhat va nho nhat trong mang\n");
		printf("5.In ra cac phan tu la so nguyen to va tinh tong\n");
		printf("6.Nhap vao 1 so va dem xem co bao nhieu phan tu co gia tri nhu vay\n");
		printf("7.Them mot phan tu vao vi tri chi dinh\n");
		printf("8.Thoat\n");
		printf("Lua chon cua ban: \n");  
		 scanf("%d" , &choice);
		switch (choice) {
			case 1: 
			    temp = 0;
				printf("nhap n ");
	         	 scanf("%d" , &n);
	        	for (i=0;i<n;i++) {
		    	printf("a[%d]= ",temp);
		     	 scanf("%d" ,&a[temp]);
		     	temp++; 
		        }
		        break;
  		    case 2:
  		    	printf("cac phan tu dang co trong mang la ");
  		    	for(i=0;i<temp;i++)
  		    	 printf("%d  ", a[i]);
  		    	printf("\n");
  		        break;
  		    case 3:
  		    	sum = 0;
  		    	printf("cac phan tu chan trong mang la ");
  		    	for(i=0;i<temp;i++) {
  		    		if (a[i]%2 == 0) {
  		    			printf("%d ", a[i]);
  		    			sum += a[i];
					}	
				}
				printf("\n");
				printf("tong cac phan tu chan trong mang la %d\n", sum);
				break;
			case 4:
				max = a[0];
				min = a[0];
				for (i=1;i<temp;i++) {
					if (max < a[i]) max = a[i];
					if (min > a[i]) min = a[i];
				} 
				printf("max trong mang la %d, min trong mang la %d\n", max , min);
				break;
			case 5:
				sum = 0;
				printf("cac phan tu la so nguyen to la ");
				for (i=0;i<temp;i++) {
					if (prime(a[i])) {
						printf("%d ", a[i] );
						sum += a[i];	
					}
				}
				printf("\n");
				printf("tong cac phan tu la so nguyen to la %d\n", sum);
				break;
			case 6:
				printf("nhap 1 so :");
				 scanf("%", &check);
				for (i=0;i<temp;i++) 
					if (temp == a[i]) count++;
				printf("so phan tu giong %d trong mang la %d\n",check,count);
				break;
			case 7:
				printf("nhap so can chen va vi tri chen ");
	 			 scanf("%d%d",&add_value, &add_index);
	 			if (add_index < temp) {
					for (i=temp+1;i>=0;i--){
						a[i] = a[i-1];
						if (i==add_index) {
						 a[i] = add_value;
						 temp++;
						 break;
						}
					}
			 	} else  {
			 		for  (i=temp;i<add_index-1;i++) {
			 			a[i] = 0;
					 }
					a[add_index] = add_value;
					temp = add_index+1;
				 } 
	            for (i=0;i<temp;i++) printf("%d ",a[i]);
	            printf("\n");
	            break;
			case 8:
				printf("thoat\n");
				break;
			default: printf("vui long nhap lai\n");	        
		}
} while (choice != 8);
}

