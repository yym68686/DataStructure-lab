#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
using namespace std;


vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ;
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
class BusStationDatabase
{
	private:
		list<string> stations;         // store all stations' name
		int StationNumber;             // the number of stations
		int RouteNumber;               // the number of routes
	public:
		BusStationDatabase()
		{
			StationNumber=0;
			RouteNumber=0;
		}
		void add_station(string str)
		{
			for(list<string>::iterator i=stations.begin();i!=stations.end();++i)
				if(*i==str)
					return;
			++StationNumber;
			stations.push_back(str);
			return;
		}
		bool search_station(string str)
		{
			for(list<string>::iterator i=stations.begin();i!=stations.end();++i)
				if(*i==str)
					return true;
			return false;
		}
		void input_bus_route_file()
		{
			ifstream inputfile("NanjingBusRoute");
			if(inputfile.fail())
			{
				cout<<"Open failed."<<endl;
				inputfile.close();
				return;
			}
			string input_line;
			string tmp;
			while(!inputfile.eof())
			{
				getline(inputfile,input_line);
				// input_line+=',';
                // cout << input_line;

                vector<string> splitarr = split(input_line, "   ");
                for (auto i : splitarr)
                    cout << i << endl;

                vector<string> curBusStation = split(splitarr[1], ",");
                for (auto i : curBusStation){
                    add_station(i);
                    cout << i << endl;
                }
				RouteNumber++;
                return;
                // printf("%s", input_line);
				// must add a ',' at the end of input_line
				// if not, the last station name will not be pushed into stations list
				// if(inputfile.eof())
					// break;
				// int space_number=0;
				// tmp="";
				// for(int i=0;i<input_line.length();++i)
				// {
				// 	if(input_line[i]==' ')
				// 	{
				// 		++space_number;
				// 		continue;
				// 	}
				// 	if(space_number==3 && input_line[i]!=',')
				// 		tmp+=input_line[i];
				// 	if(space_number==3 && input_line[i]==',')
				// 	{
				// 		add_station(tmp);
				// 		tmp="";
				// 	}
				// }
			}
			inputfile.close();
			return;
		}
		int get_StationNumber(){return StationNumber;}
		int get_route_number(){return RouteNumber;}
		list<string>& get_station_name_list(){return stations;}
};
BusStationDatabase lib;

struct bus_route
{
	int station_identifier;  // next station's id
	int bus_route_identifier;// id of the route to the station
};
struct bus_station
{
	string name;
	list<bus_route> next_stations;
};
struct bus_route_list
{
	int id;
	list<int> station_id;
};

class bus_route_map
{
	private:
		bus_station* station_info;
		int StationNumber;
		bool* visited;
		int *path;
		// for least station path
		bus_route_list* route_info;
		bool** route_map;
		int RouteNumber;
		bool* route_used;
		int* route;
		// for least route change path

	public:
		bus_route_map()
		{
			StationNumber=0;
			station_info=NULL;
			route_info=NULL;
			visited=NULL;
			path=NULL;
			route_map=NULL;
			route_used=NULL;
			route=NULL;
			return;
		}
		~bus_route_map()
		{
			if(station_info)
				delete []station_info;
			if(route_info)
				delete []route_info;
			if(visited)
				delete []visited;
			if(path)
				delete []path;
			if(route_map)
			{
				for(int i=0;i<RouteNumber;++i)
					delete []route_map[i];
				delete []route_map;
			}
			if(route_used)
				delete []route_used;
			if(route)
				delete []route;
			return;
		}
		bool check_route_intersect(int route_id1,int route_id2)
		{
			// check if two routes have public stations
			for(list<int>::iterator i=route_info[route_id1].station_id.begin();i!=route_info[route_id1].station_id.end();++i)
				for(list<int>::iterator j=route_info[route_id2].station_id.begin();j!=route_info[route_id2].station_id.end();++j)
					if(*j==*i)
						return true;
			return false;
		}
		void create_station_info_lib()
		{
			// initializing
			StationNumber=lib.get_StationNumber();
			RouteNumber=lib.get_route_number();
			station_info=new bus_station[StationNumber];
			route_info=new bus_route_list[RouteNumber];
			visited=new bool[StationNumber];
			path=new int[StationNumber];
			route_used=new bool[RouteNumber];
			route=new int[RouteNumber];
			int identifier=0;
			for(list<string>::iterator i=lib.get_station_name_list().begin();i!=lib.get_station_name_list().end();++i,++identifier)
				station_info[identifier].name=*i;
			for(int i=0;i<RouteNumber;++i)
				route_info[i].id=i;
			route_map=new bool*[RouteNumber];
			for(int i=0;i<RouteNumber;++i)
				route_map[i]=new bool[RouteNumber];
			return;
		}
		int get_bus_station_identifier(string str)
		{
			static int cnt=1;
			for(int i=0;i<StationNumber;++i)
				if(station_info[i].name==str)
					return i;
			return -1;
		}
		void generate_bus_station_map()
		{
			ifstream inputfile("NanjingBusRoute");
			if(inputfile.fail())
			{
				cout<<"lack file \'NanjingBusRoute\'."<<endl;
				inputfile.close();
				return;
			}
			string input_line;
			string tmp;
			int route_count=-1;
			list<string> route_stations;

			while(!inputfile.eof())
			{
				// initializing
				route_stations.clear();
				getline(inputfile,input_line);
				input_line+=',';
				if(inputfile.eof())
					break;
				++route_count;
				route_info[route_count].id=0;
				int space_number=0;
				tmp="";
				// get id of each route
				for(int i=0;i<input_line.length();++i)
				{
					if('0'<=input_line[i] && input_line[i]<='9')
						route_info[route_count].id=route_info[route_count].id*10+(int)(input_line[i]-'0');
					else
						break;
				}
				for(int i=0;i<input_line.length();++i)
				{
					if(input_line[i]==' ')
						++space_number;
					else if(space_number==3 && input_line[i]!=',')
						tmp+=input_line[i];
					else if(space_number==3 && input_line[i]==',')
					{
						route_stations.push_back(tmp);
						tmp="";
					}
				}
				// update station_info::next_stations
				for(list<string>::iterator i=route_stations.begin();i!=route_stations.end();++i)
				{
					list<string>::iterator next_iter=i;
					++next_iter;
					route_info[route_count].station_id.push_back(get_bus_station_identifier(*i));

					if(next_iter==route_stations.end())// if don't add this check,next_iter will point to (string) tmp
						continue;
					int this_station_identifier=get_bus_station_identifier(*i);
					int next_station_identifier=get_bus_station_identifier(*next_iter);

					if(this_station_identifier>=0 && next_station_identifier>=0)
					{
						bus_route t;
						t.bus_route_identifier=route_count;
						t.station_identifier=next_station_identifier;
						station_info[this_station_identifier].next_stations.push_back(t);
						t.station_identifier=this_station_identifier;
						station_info[next_station_identifier].next_stations.push_back(t);
					}
				}
			}
			inputfile.close();
			// generate route map
			for(int i=0;i<RouteNumber;++i)
				for(int j=0;j<=i;++j)
						route_map[i][j]=route_map[j][i]=check_route_intersect(i,j);
			return;
		}
		void least_station_route(string start_station,string end_station)
		{
			int beg_id=get_bus_station_identifier(start_station);
			int end_id=get_bus_station_identifier(end_station);

			if(beg_id<0)
			{
				cout<<start_station<<" does not exist."<<endl;
				return;
			}
			if(end_id<0)
			{
				cout<<end_station<<" does not exist."<<endl;
				return;
			}
			list<string> generated_route;
			int min_StationNumber=0;
			for(int i=0;i<StationNumber;++i)
				visited[i]=false;
			for(int i=0;i<StationNumber;++i)
				path[i]=-1;
			list<int> que;
			// begin dijkstra with queue
			que.push_back(beg_id);
			visited[beg_id]=true;
			path[beg_id]=-1;
			while(!que.empty())
			{
				int tmp=que.front();
				// reach the end_station then quit the loop
				if(tmp==end_id)
					break;
				que.pop_front();
				for(list<bus_route>::iterator i=station_info[tmp].next_stations.begin();i!=station_info[tmp].next_stations.end();++i)
					if(!visited[i->station_identifier])
					{
						visited[i->station_identifier]=true;
						que.push_back(i->station_identifier);
						path[i->station_identifier]=tmp;
					}
			}
			int node=end_id;
			++min_StationNumber;
			// generate route
			generated_route.push_back(station_info[end_id].name);
			while(path[node]>=0)
			{
				++min_StationNumber;
				generated_route.push_front(station_info[path[node]].name);
				node=path[node];
			}

			cout<<endl<<min_StationNumber<<" stations: ";
			for(list<string>::iterator i=generated_route.begin();i!=generated_route.end();++i)
			{
				cout<<*i;
				++i;
				if(i!=generated_route.end())
					cout<<" -> ";
				--i;
			}
			cout<<endl;
			return;
		}
		bool check_station_in_route(int route_id,int station_id)
		{
			for(list<int>::iterator i=route_info[route_id].station_id.begin();i!=route_info[route_id].station_id.end();++i)
				if(station_id==*i)
					return true;
			return false;
		}
		void least_route_change(string start_station,string end_station)
		{
			int beg_id=get_bus_station_identifier(start_station);
			int end_id=get_bus_station_identifier(end_station);

			if(beg_id<0)
			{
				cout<<start_station<<" does not exist."<<endl;
				return;
			}
			if(end_id<0)
			{
				cout<<end_station<<" does not exist."<<endl;
				return;
			}
			list<int> generated_route;
			int min_route_change=5000;
			list<int> beg_station_routes;
			list<int> end_station_routes;
			for(int i=0;i<RouteNumber;++i)
			{
				if(check_station_in_route(i,beg_id))
					beg_station_routes.push_back(i);
				if(check_station_in_route(i,end_id))
					end_station_routes.push_back(i);
			}

			for(list<int>::iterator i=beg_station_routes.begin();i!=beg_station_routes.end();++i)
			{
				list<int> que;
				list<int> cntque;
				que.push_back(*i);
				cntque.push_back(1);
				for(int j=0;j<RouteNumber;++j)
					route_used[j]=false;
				route_used[*i]=true;
				route[*i]=-1;

				int found=-1;
				int temp_cnt;// store the number of route changes
				while(!que.empty())
				{
					int tmp=que.front();
					temp_cnt=cntque.front();
					que.pop_front();
					cntque.pop_front();
					// check if tmp route includes the end station
					for(list<int>::iterator j=end_station_routes.begin();j!=end_station_routes.end();++j)
						if(tmp==*j)
						{
							found=tmp;
							break;
						}
					if(found>=0)
						break;
					// add routes that have public station with tmp route to queue
					for(int j=0;j<RouteNumber;++j)
						if(!route_used[j] && route_map[tmp][j])
						{
							route_used[j]=true;
							route[j]=tmp;
							que.push_back(j);
							cntque.push_back(temp_cnt+1);
						}
				}
				// update new least route change path
				int node=found;
				if(temp_cnt<min_route_change && node>=0)
				{
					min_route_change=temp_cnt;
					generated_route.clear();
					generated_route.push_front(node);
					while(route[node]>=0)
					{
						generated_route.push_front(route[node]);
						node=route[node];
					}
				}
			}
			cout<<endl<<min_route_change<<" routes: ";
			for(list<int>::iterator i=generated_route.begin();i!=generated_route.end();++i)
			{
				cout<<route_info[*i].id<<" route";
				++i;
				if(i!=generated_route.end())
					cout<<" -> ";
				--i;
			}
			cout<<endl;
			return;
		}
		bool check_route(string start_station,string end_station)
		{
			int beg_id=get_bus_station_identifier(start_station);
			int end_id=get_bus_station_identifier(end_station);
			if(beg_id<0 || end_id<0)
			{
				cout<<start_station<<" or "<<end_station<<" don't exist."<<endl;
				return false;
			}
			list<int> que;
			for(int i=0;i<StationNumber;++i)
				visited[i]=false;
			que.push_back(beg_id);
			visited[beg_id]=true;
			while(!que.empty())
			{
				int tmp=que.front();
				if(tmp==end_id)
				{
					que.clear();
					return true;
				}
				que.pop_front();
				for(list<bus_route>::iterator i=station_info[tmp].next_stations.begin();i!=station_info[tmp].next_stations.end();++i)
					if(!visited[i->station_identifier])
					{
						visited[i->station_identifier]=true;
						que.push_back(i->station_identifier);
					}
			}
			return false;
		}
};
bus_route_map nanjing_bus_route;

string start_station;
string end_station;
int main()
{
	lib.input_bus_route_file();
	nanjing_bus_route.create_station_info_lib();
	nanjing_bus_route.generate_bus_station_map();
	while(1)
	{
		cout<<"start at: ";
		cin>>start_station;
		cout<<"end at: ";
		cin>>end_station;
		if(nanjing_bus_route.check_route(start_station,end_station))
		{
			cout<<"least stations route: ";
			nanjing_bus_route.least_station_route(start_station,end_station);
			cout<<"least route change: ";
			nanjing_bus_route.least_route_change(start_station,end_station);
		}
		else
			cout<<"cannot take a bus from "<<start_station<<" to "<<end_station<<endl;
	}
	return 0;
}