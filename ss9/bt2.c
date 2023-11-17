#include<stdio.h>
int main() {
	int n,m,i,j,sum = 0;
	int a[n][m];
	int choice;
	int max,min,count,temp;
	do {
    printf("1.nhap cac thong so cua mang\n");
	printf("2.In ra cac phan tu dang quan ly\n");
	printf("3.In ra gia tri cac phan tu le va tinh tong\n");
	printf("4.In ra cac phan tu nam tren duong bien va tinh tong\n");
	printf("5.In ra cac phan tu tren duong cheo chinh va duong cheo phu va tinh tong\n");
	printf("6.max min trong mang\n");
	printf("7.tinh gia tri trung binh cua mang, xem co bao nhieu phan tu bang voi gia tri trung binh\n");
	printf("8.dong co tong phan tu lon nhat\n");
	printf("9.Thoat\n");
	printf("Lua chon cua ban: \n");  
	scanf("%d" , &choice);
	switch (choice) {
    	case 1: 
			printf("nhap n , m");
	 		scanf("%d%d", &n,&m);
			for (i=0;i<n;i++) {
				for (j=0;j<m;j++) {
		   			printf("a[%d,%d] = ",i,j);
	       			scanf("%d",&a[i][j]);
	       		}
	       	}
	       	break;
	    case 2:
	    	for (i=0;i<n;i++) {
				for (j=0;j<m;j++) {
		   			printf("%d ",a[i][j]);
	       		}
	       	printf("\n");
	       	}
	       	break;
	    case 3:
	    	sum = 0;
	    	for (i=0;i<n;i++) {
				for (j=0;j<m;j++) {
					if (a[i][j]%2 !=0) {
						printf("%d ", a[i][j]);
						sum +=a[i][j];
					}
				}
			}
			printf("\n");
			printf("tong cac phan tu le trong mang la %d", sum);
			break;
		case 4:
			sum = 0;
			printf("tong duong bien trai la ");
			for (j=0;j<m;j++) sum +=a[0][j];
			printf("%d\n",sum);
			sum = 0;
			printf("tong duong bien phai la");
			for (j=0;i<m;j++) sum += a[n][0];
			printf("%d\n",sum);
			break;
		case 5:
			sum = 0;
			if (m == n) {
				i = 0;
				j = 0;
				printf("duong cheo chinh la ");
				while (i<n) {
					printf("%d ", a[i][j]);
					sum += a[i][j];
					i++;
					j++;
				}
				printf("\n");
			    printf("tong duong cheo chinh la %d\n", sum);
			    i = 0;
			    j = n-1;
			    sum = 0;
			    printf("duong cheo phu la ");
				while (j>=0) {
					printf("%d ", a[i][j]);
					sum += a[i][j];
					i++;
					j--;
				}
				printf("\n");
			    printf("tong duong cheo phu la %d\n", sum);
			} else printf("khong co duong cheo chinh va phu\n");
			break;
		case 6:
			max = a[0][0]; 
			min = a[0][0];
			for (i=0;i<n;i++) {
				for (j=0;j<n;j++) {
					if (max < a[i][j]) max = a[i][j];
					if (min > a[i][j]) min = a[i][j];
				}
			}
			printf("max trong mang la %d, min trong mang la %d\n",max ,min);
			break;
		case 7:
			count = 0;
			sum = 0;
			for (i=0;i<n;i++) {
				for (j=0;j<n;j++) {
					sum +=a[i][j];
				}
			}
			temp = sum/(n*m);
			printf("gia tri trung binh cua mang la %d\n", temp);
			for (i=0;i<n;i++) {
				for (j=0;j<n;j++) {
					if (a[i][j] == temp)
						count++;
				}
			}
			printf("so phan tu co gia tri trung voi gia tri trung binh la %d",count);
			break;
		case 8:
			max = 0; 
			temp = 0;
			sum = 0;
			for (i=0;i<n;i++) {
				for (j=0;j<m;j++) {
					sum += a[i][j];
				} 
				if (max <sum) {
					max = sum;
					temp = i;
					sum = 0;
				}
			}
			printf("dong co tong lon nhat la dong %d\n", temp);
			break;
		case 9: 
		    printf("thoat\n");
		default: printf("khong hop le\n");
	}
	} while (choice !=9);
}
