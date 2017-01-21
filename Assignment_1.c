#include<stdio.h>
#include<math.h>

const float pi = 3.1415;

int func1(int a){
	return a*a;
}

int func2(int a,int b){
	return a*b;
}

float func3(int r){
	return 4*pi*r*r*r/3.0;
}

float func4(int r, int h){
	return pi*r*r*h;
}

void func5(int a,int a1,int b,int r,int r1,int h){
  	float avg = (a+a1+b+r+r1+h)/6.0;
 	float sd = sqrt(((a-avg)*(a-avg)+(a1-avg)*(a1-avg)+(b-avg)*(b-avg)+(r-avg)*(r-avg)+(r1-avg)*(r1-avg)+(h-avg)*(h-avg))/5.0);
	printf("Average of the values entered: %0.3f\n",avg);
	printf("Standard deviation of the values entered: %0.3f\n",sd);
}
int main(){
 //1
 	printf("Enter the length of your square's edge: ");
 	int a;
 	scanf("%d",&a);
 	printf("Area of the square: %d\n",func1(a));
 //2
 	printf("Enter the lengths of your rectangles edges: ");
 	int a1,b;
	scanf("%d %d",&a1,&b);
 	printf("Area of the rectangle: %d\n",func2(a1,b));
 //3
 	printf("Enter radius of your sphere: ");
 	int r;
 	scanf("%d",&r);
 	printf("Area of the rectangle: %0.3f\n",func3(r));
  //4
	printf("Enter radius and height of your cylinder: ");
	int r1,h;
	scanf("%d %d",&r1,&h);
	printf("Volume of the cylinder: %0.3f\n",func4(r1,h));
  //5
  	func5(a,a1,b,r,r1,h);
}
