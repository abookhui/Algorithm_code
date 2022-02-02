#include<stdio.h>

struct time {
	int hour;
	int min;
	int sec;
};

struct time plus(struct time a, struct time b){
	struct time ans;
	ans.sec=0;
	ans.min=0;
	ans.hour=0;
	
	ans.sec += a.sec + b.sec;
	if(ans.sec>=60){
		ans.sec-=60;
		ans.min+=1;
	}
	
	ans.min += a.min + b.min;
	if(ans.min>=60){
		ans.min-=60;
		ans.hour+=1;
	}
	
	ans.hour += a.hour + b.hour;
	
	return ans;
}

struct time minus(struct time a, struct time b){
	struct time ans;
	
	ans.sec=a.sec-b.sec;
	ans.min=a.min-b.min;
	ans.hour=a.hour-b.hour;
	
	return ans;
}

struct time input(){
	struct time ans;
	int sec,min,hour;
	
	scanf("%d %d %d",&sec,&min,&hour);
	ans.sec=sec;
	ans.min=min;
	ans.hour=hour;
	return ans;
}

void print(struct time a)
{
	printf("%02d:%02d:%02d\n", a.hour, a.min, a.sec);
}

int main()
{
	struct time a;
	struct time b;

	a = input();
	b = input();

	printf("a: ");
	print(a);
	printf("b: ");
	print(b);
	printf("a + b: ");
	print(plus(a, b));
	printf("a - b: ");
	print(minus(a, b));


	return 0;
}