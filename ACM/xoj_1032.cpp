// 1032.装配线问题
// Time Limit: 1000 MS         Memory Limit: 65536 K
// Description
// 　　有两条装配线，编号分别为1和2。每一条装配线上有个n装配点，将第i条线上的第个j装配点记为Si,j，设在装配点Si,j的装配时间为Ai,j。假设要装配一辆汽车，将汽车底盘从进厂点送入第i号装配线，需要时间Ei。在装配点Si,j装配后，如果汽车传送到同一号装配线的装配点Si,j+1进行装配，则传送不需要时间。如果汽车完成装配点Si,j的工作后传送到另一号装配线进行下一步的工作，则需要传送时间Ti,j。汽车在装配点Si,n装配后，将汽车成品从装配线上退下来，需要花费时间Xi。装配线调度问题是如何确定每一个装配点的装配需要在哪号线上进行，使得当汽车成品出来时，花费的总时间最少。
// Input
// 输入的第一行包含一个正整数n(1<=n<=1000)
// 第二行包含四个正整数，分别是传入装配线所用时间E1,E2和退出装配线所用时间X1,X2。(0<E1,E2,X1,X2<=1000)
// 接下来的两行每行有n个正整数，分别描述装配时间A1,j和A2,j(0<Ai,j<=1000)(1<=j<=n)。
// 接下来的两行每行有n - 1个正整数，分别描述传送时间T1,j和T2,j(0<=Ti,j<=150)(1<=j<=n-1)。
// Output
// 输出一个正整数表示一辆汽车最快需要多少时间出厂。
// Sample Input
// 4
// 10 20 40 30
// 50 100 1000 50
// 200 200 200 65
// 10 10 10
// 20 20 20
// Sample Output
// 465

#include<stdio.h>

int main()
{
	int n,e1,e2,x1,x2,i,result;
	int a1[1001],a2[1001],t1[1001],t2[1001];
	int f1[1001],f2[1001];
	scanf("%d",&n);
	scanf("%d%d%d%d",&e1,&e2,&x1,&x2);
	for(i=1;i<=n;i++)
		scanf("%d",&a1[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&a2[i]);
	for(i=1;i<n;i++)
		scanf("%d",&t1[i]);
	for(i=1;i<n;i++)
		scanf("%d",&t2[i]);
	f1[1]=e1+a1[1];
	f2[1]=e2+a2[1];
	for(i=2;i<=n;i++){
		if(f1[i-1]+a1[i]<=f2[i-1]+t2[i-1]+a1[i])
			f1[i]=f1[i-1]+a1[i];
		else 
			f1[i]=f2[i-1]+t2[i-1]+a1[i];
		if(f2[i-1]+a2[i]<=f1[i-1]+t1[i-1]+a2[i])
			f2[i]=f2[i-1]+a2[i];
		else 
			f2[i]=f1[i-1]+t1[i-1]+a2[i];		
	}
	if(f1[n]+x1<=f2[n]+x2)
		result=f1[n]+x1;
	else
		result=f2[n]+x2;
	printf("%d",result);
	return 0;
}