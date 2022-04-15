#include <string.h>

void rightshiftarr(char *arr,int n){
	for(int i=n;i>0;i--){
		arr[i] = arr[i-1];
	}
	return;
}

/* reverses an array of n elements*/
void revarr(char *arr,int n){
	int temp;
	for(int i=0;i<=((n-1)/2);i++){
		temp = arr[i];
		arr[i] = arr[(n-1)-i];
		arr[(n-1)-i] = temp;
	}
}

int my_strlen(const char *str){
	int len;
	for(len = 0;str[len] != '\0';len++){}
	return len;
}

char * multvli(char *a,char *b,char *c,int csize){
	
	memset(c,0,csize);
	
	int a1sign = 1;
	int b1sign = 1;
	
	if(a[0] == '-'){a1sign = -1;a = &a[1];}
	if(b[0] == '-'){b1sign = -1;b = &b[1];}
	
	int alen = my_strlen(a);
	int blen = my_strlen(b);
	
	int carry = 0;
	int base_index = 0;
	int current_index = 0;
	char prev = 0;
	
	for(int i=alen-1;i>=0;i--){
		current_index = base_index;
		carry = 0;
		for(int j=blen-1;j>=0;j--){
			if(c[current_index] == '\0'){prev = 0;}
			else{prev = c[current_index]-48;}
			c[current_index] = ((((a[i]-48)*(b[j]-48))+prev+carry)%10) + 48;
			carry = ((((a[i]-48)*(b[j]-48))+prev+carry)/10);
			current_index++;
		}
		if(carry>0){c[current_index] = carry +48;}
		base_index++;
	}
	
	int clen = my_strlen(c);
	revarr(c,clen);
	if(a1sign*b1sign == -1){rightshiftarr(c,clen);c[0] = '-';}
	
	return c;
}

/*finds which argument is greater, returns n if nth argument is greatest, returns 0 if both are same*/
int greater(const char *int1,const char *int2){
	if(my_strlen(int1) > my_strlen(int2)){return 1;}
	else if(my_strlen(int1) < my_strlen(int2)){return 2;}
	else{
		for(int i=0;int1[i] != '\0';i++){
			if((int1[i] - int2[i]) > 0 ){return 1;}
			else if((int1[i] - int2[i]) < 0 ){return 2;}
		}
	}
	return 0;
}

/*adds 2 positive numbers*/
void addp(char *int1,char *int2,char *int3){
	int carry = 0;
	int i = (my_strlen(int1) - 1);
	for(int j = (my_strlen(int2) - 1);j>=0;j--){
		int3[i+1] = ((((int1[i] - 48) + (int2[j] - 48) + carry) % 10) + 48);
		carry = (((int1[i] - 48) + (int2[j] - 48) + carry) / 10);
		i--;
	}
	while(i>=0){
		int3[i+1] = ((((int1[i] - 48) + carry) % 10) + 48);
		carry = (((int1[i] - 48) + carry) / 10);
		i--;
	}
	int3[0] = carry + 48;
	int3[(my_strlen(int1) + 1)] = '\0';
	return;
}

/*adds 2 negative numbers*/
void addn(char *int1,char *int2,char *int3){
	int carry = 0;
	int i = (my_strlen(int1) - 1);
	for(int j = (my_strlen(int2) - 1);j>=1;j--){
		int3[i+1] = ((((int1[i] - 48) + (int2[j] - 48) + carry) % 10) + 48);
		carry = (((int1[i] - 48) + (int2[j] - 48) + carry) / 10);
		i--;
	}
	while(i>=1){
		int3[i+1] = ((((int1[i] - 48) + carry) % 10) + 48);
		carry = (((int1[i] - 48) + carry) / 10);
		i--;
	}
	int3[1] = carry + 48;
	int3[0] = '-';
	int3[(my_strlen(int1) + 1)] = '\0';
	return;
}

/*subtracts int2 from int1*/
void subtract(char *int1,char *int2,char *int3){
	int borrow = 0;
	int borrowed = 0;
	int i = (my_strlen(int1) - 1);
	for(int j = (my_strlen(int2) - 1);j>=0;j--){
		if(((int1[i] - int2[j]) - borrowed) < 0){borrow = 1;}
		else{borrow = 0;}
		int3[i] = (((((int1[i] - 48) + (borrow * 10)) - borrowed) - (int2[j] - 48)) + 48);
		if(borrow == 1){borrowed = 1;}
		else{borrowed = 0;}
		i--;
	}
	while(i>=0){
		if(((int1[i] - 48) - borrowed) < 0){borrow = 1;}
		else{borrow = 0;}
		int3[i] = ((((int1[i] - 48) + (borrow * 10)) - borrowed) + 48);
		if(borrow == 1){borrowed = 1;}
		else{borrowed = 0;}
		i--;
	}
	int3[my_strlen(int1)] = '\0';
	return;
}

/*swaps values of 2 pointers*/
void swap_ptr(char **ptr1,char **ptr2){
	char *temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	return;
}

/*counts number of preceeding zeroes*/
int count0s(const char *arr){
	int zeroes;
	for(zeroes=0;arr[zeroes] == '0';zeroes++){}
	return zeroes;
} 

char * addvli(char *int1,char *int2,char *int3,int int3size) {
	memset(int3,0,int3size);

	if((int1[0] != '-') && (int2[0] != '-')){
		if(my_strlen(int1) < my_strlen(int2)){swap_ptr(&int1,&int2);}
		addp(int1,int2,int3);
		if(int3[0] == 48){sprintf(int3,"%s\n",int3+1);}
		else{sprintf(int3,"%s\n",int3);}
	}
	else if((int1[0] == '-') && (int2[0] == '-')){
		if(my_strlen(int1) < my_strlen(int2)){swap_ptr(&int1,&int2);}
		addn(int1,int2,int3);
		if(int3[1] == 48){sprintf(int3,"-%s\n",int3+2);}
		else{sprintf(int3,"%s\n",int3);}
	}
	else{
		if((int1[0] == '-')&&(greater(int1+1,int2) == 1)){subtract(int1+1,int2,int3);sprintf(int3,"-%s\n",int3+count0s(int3));}
		else if ((int1[0] == '-')&&(greater(int1+1,int2) == 2)){swap_ptr(&int1,&int2);subtract(int1,int2+1,int3);sprintf(int3,"%s\n",int3+count0s(int3));}
		else if ((int2[0] == '-')&&(greater(int1,int2+1) == 2)){swap_ptr(&int1,&int2);subtract(int1+1,int2,int3);sprintf(int3,"-%s\n",int3+count0s(int3));}
		else if ((int2[0] == '-')&&(greater(int1,int2+1) == 1)){subtract(int1,int2+1,int3);sprintf(int3,"%s\n",int3+count0s(int3));}
		else{sprintf(int3,"0\n");}
	}
	
	return int3;
}