#include <map>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 40000

vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
	return res;
}

class FindKey
{
private:
    int num;
public:
    FindKey(int n) :num(n){}
    bool operator ()(map<string, int>::value_type item){
        return item.second == num;
    }
};

class BusStationDatabase
{
	private:
		typedef struct Pos
		{
			int StationNum;
			int BusNum;
			Pos *last;
		} Pos;

		list<string> stations;
		int StationNumber;
		int RouteNumber;
		int StartStaionNum;
		map<string, int> StationMap;           //站点及其编号的映射
		map<int, vector<string> > BusInfo;     //第几路公交车及其经过站点的映射
		map<string, vector<int> > StationInfo; //每个站点都有哪些公交车经过
		queue<Pos> Queue;

		struct Edge{
			int v;
			int len;
			int next;
		} edge[111111];
		int head[maxn], cnt = 0;
		int from, to;
		string start, end;
		int visit[maxn];
		int dis[maxn], path[maxn];


	public:
		BusStationDatabase(){
			StationNumber = 1;
			RouteNumber = 0;
		}
		void LoadData(){
			ifstream inputfile("NanjingBusRoute");
			if(inputfile.fail()){
				cout<<"Open failed."<<endl;
				inputfile.close();
				return;
			}
			string input_line;
			while(!inputfile.eof()){
				getline(inputfile, input_line);
                vector<string> splitarr = split(input_line, "   ");
				splitarr[0].pop_back();
                vector<string> curBusStation = split(splitarr[1], ",");
				BusInfo[stoi(splitarr[0])] = curBusStation;
                for (auto i : curBusStation){
					auto key = StationMap.find(i);
					if (key == StationMap.end())
						StationMap[i] = StationNumber++;
					StationInfo[i].push_back(stoi(splitarr[0]));
                }
			}
			inputfile.close();
			StationNumber--;
			RouteNumber = BusInfo.size();
			return;
		}
		void BuildGraph(){
			for (auto i : BusInfo) {
				for(int j = 0; j < i.second.size() - 1; j++){
					from = StationMap[i.second[j]];
					to = StationMap[i.second[j + 1]];
					addedge(from, to, 1);
					addedge(to, from, 1);
				}
			}
		}
		void PrintLeastStationRoute(int s){
			if (!s) return;
			PrintLeastStationRoute(path[s]);
			auto it = find_if(StationMap.begin(), StationMap.end(), FindKey(s));
			if (it != StationMap.end())
				if (path[s])
					cout << "->" << (*it).first;
				else
					cout << (*it).first;
		}
		void LeastStationRoute(){
			freopen("StartEndStation", "r", stdin);
			cin >> start >> end;
			memset(path, 0, sizeof(path));
			memset(visit, 0, sizeof(visit));
			int flag = 0;
			auto key = StationMap.find(start);
			if (key == StationMap.end()) flag = 1;
			key = StationMap.find(end);
			if (key == StationMap.end()) flag = 1;
			if (flag) {
				cout << "error!" << endl;
				return;
			}
			dijkstra();
			for (int i = 1; i <= StationNumber; i++)
				if (i == StationMap[end]) {
					cout << "经过站点最少: " << dis[i] << "站" << endl;
					int p = path[i];
					PrintLeastStationRoute(i);
					cout << endl << endl;
				}
		}
		void LeastChangeRoute(){
			memset(path, 0, sizeof(path));
			memset(visit, 0, sizeof(visit));
			Pos *point = new Pos;
			point->BusNum = 0;
			point->last = NULL;
			point->StationNum = StationMap[start];
			Queue.push(*point);
			visit[point->StationNum] = 1;
			while (!Queue.empty()) {
				Pos front = Queue.front();
				Queue.pop();
				Pos *p = new Pos;
				p->StationNum = front.StationNum;
				p->BusNum = front.BusNum;
				p->last = front.last;
				visit[p->StationNum] = 1;
				if (p->StationNum == StationMap[end]) {
					point = ReverseList(p);
					point->BusNum = point->last->BusNum;
					cout << "转车次数最少: " << endl;
					while (point->last){
						int tmp = point->StationNum;
						auto ss = find_if(StationMap.begin(), StationMap.end(), FindKey(tmp));
						auto ee = find_if(StationMap.begin(), StationMap.end(), FindKey(point->last->StationNum));
						auto StartStation = find(BusInfo[point->last->BusNum].begin(), BusInfo[point->last->BusNum].end(), (*ss).first);
						auto EndStation = find(BusInfo[point->last->BusNum].begin(), BusInfo[point->last->BusNum].end(), (*ee).first);
						if (StartStation > EndStation) reverse(BusInfo[point->last->BusNum].begin(), BusInfo[point->last->BusNum].end());
						int flag = 0;
						for (auto i : BusInfo[point->last->BusNum]) {
							if (i == (*ss).first || flag) {
								if (i == (*ee).first){
									cout << i << "(" << point->last->BusNum << "路)";
									break;
								}
								cout << i << "(" << point->last->BusNum << "路)->";
								flag = 1;
							}
						}
						if (point->last->last) cout << endl << "转" << endl;
						point = point->last;
					}
					return;
				}
				auto StationName = find_if(StationMap.begin(), StationMap.end(), FindKey(p->StationNum));
				for (auto i : StationInfo[(*StationName).first]) { //能经过该站点所有公交车的列表
					for (auto j : BusInfo[i]) { // 该公交车经过的所有站点列表
						if (!visit[StationMap[j]]) { //如果这个站点没有被访问过，就加到队列里
							point = new Pos;
							point->StationNum = StationMap[j];
							point->BusNum = i;
							point->last = p;
							Queue.push(*point);
						}
					}
				}
			}
		}
		Pos* ReverseList(Pos *root){
			Pos *p, *temp, *tmp = NULL;
			temp = p = root;
			while(temp){
				temp = p->last;
				p->last = tmp;
				tmp = p;
				p = temp;
			}
			return tmp;
		}
		void addedge(int from, int to, int len){
			edge[++cnt].v = to;
			edge[cnt].len = len;
			edge[cnt].next = head[from];
			head[from] = cnt;
		}
		void dijkstra(){
			for (int i = 1; i <= StationNumber; i++)
				dis[i] = INF;
			int temp = StationMap[start];
			dis[temp] = 0;
			int minn;
			while (!visit[temp]){
				visit[temp] = 1;
				for (int j = head[temp]; j; j = edge[j].next)
					if (!visit[edge[j].v] && dis[edge[j].v] > dis[temp] + edge[j].len)
						dis[edge[j].v] = dis[temp] + edge[j].len, path[edge[j].v] = temp;
				minn = INF;
				for (int j = 1; j <= StationNumber; j++)
					if (!visit[j] && minn > dis[j])
						minn = dis[j], temp = j;
			}
		}
		int get_StationNumber(){return StationNumber;}
		int get_route_number(){return RouteNumber;}
		list<string>& get_station_name_list(){return stations;}
};
BusStationDatabase lib;
int main()
{
	lib.LoadData();
	lib.BuildGraph();
	lib.LeastStationRoute();
	lib.LeastChangeRoute();
	return 0;
}