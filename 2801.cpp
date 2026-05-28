#include<bits/stdc++.h>
using namespace std;

int h,w,k;//h行，w列，k步
vector<string> grid;//存储网格，每个元素是.或#
vector<vector<bool>> visited;//标记格子是否在当前路径中被访问过
int ans=0;//所有合法路径数量

//方向数组，分别对应上、下、左、右
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x,int y,int step)//深度优先搜索，当前格子坐标(x,y)，已经走过step步
{
	if(step==k)//已经走了k步
	{
		ans++;//计数+1
		return;//结束递归
	}
	for(int d=0;d<4;d++)//尝试向四个方向移动
	{
		int nx=x+dx[d];//下一步行坐标
		int ny=y+dy[d];//下一步列坐标
		if(nx<0||nx>=h||ny<0||ny>=w) continue;//边界检查：不能超出网格范围
		if(grid[nx][ny]=='#') continue;//障碍物检查：不能走到#格子
		if(visited[nx][ny]) continue;//重复访问检查：不能走重复格子
		//满足所有条件
		visited[nx][ny]=true;//标记已访问
		dfs(nx,ny,step+1);//继续递归，步数+1
		visited[nx][ny]=false;//回溯：撤销标记，尝试其他方向
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>h>>w>>k;
	grid.resize(h);//调整grid大小为h行
	visited.assign(h,vector<bool>(w,false));//调整visited大小为h*w，全部初始化为未访问
	for(int i=0;i<h;i++)
	{
		cin>>grid[i];
	}
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)//枚举所有格子作为起点
		{
			if(grid[i][j]=='.')//只有.能作为起点
			{
				visited[i][j]=true;//标记起点已访问
				dfs(i,j,0);//从起点开始dfs，当前步数为0
				visited[i][j]=false;//回溯：清理起点标记
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
