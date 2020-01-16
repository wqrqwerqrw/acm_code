#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;
using Maze = vector<string>;
using coor = pair<int, int>;

void showMaze(const Maze& maze) {
	for (auto str : maze) {
		for (auto ch : str) {
			cout << ch;
		}
		cout << endl;
	}
}
void syncShowMaze(const Maze& maze) {
	system("cls");
	showMaze(maze);
}
void makeMaze(Maze& maze) {
	cout << "输入迷宫的尺寸" << endl;
	int wide, length;
	cout << "输入迷宫的长度 : ";
	cin >> length;
	cout << "输入迷宫的宽度 : ";
	cin >> wide;

	string tmp = "";
	for (int i = 0; i < length; i++) {
		tmp += ".";
	}
	for (int i = 0; i < wide; i++) {
		maze.push_back(tmp);
	}

	syncShowMaze(maze);

	int x, y;
	cout << "起始位置(x, y, x 指向下, y 指向右) : ";
	cin >> x >> y;
	maze[--x][--y] = 'S';

	syncShowMaze(maze);

	cout << "结束位置(x, y, x 指向下, y指向右) : ";
	cin >> x >> y;
	maze[--x][--y] = 'E';

	syncShowMaze(maze);

	cout << "输入障碍物的位置(x, y, x 指向下, y指向右, 输入\"-1 -1\"停止) : ";
	while (cin >> x >> y) {
		if (x == -1 && y == -1) {
			break;
		}
		maze[--x][--y] = '#';
		syncShowMaze(maze);
		cout << "输入障碍物的位置(x, y, x 指向下, y指向右, 输入\"-1 -1\"停止) : ";
	}
}

template<class T>
class queue {
private:
	class node {
	public:
		T val;
		node* next;
	};
	node* head = new node;
	node* tail = head;
public:
	T front() {
		return head->next->val;
	}
	void pop() {
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
	void push(T in) {
		node* toin = new node;
		toin->val = in;
		tail->next = toin;
		tail = toin;
	}
	bool empty() {
		return tail == head;
	}
};


/*
class node {
public:
	coor cur;
	int step;
};
*/
map<coor, coor> per;

bool getpath(Maze maze) {
	map<coor, bool> book;
	coor beg, end;
	int mx[] = {0, 0, 1, -1};
	int my[] = {1, -1, 0, 0};
	int tmp = 0;
	//找起点以及终点
	for (int i = 0; i < (int)maze.size(); i++) {
		for (int j = 0; j < (int)maze[i].size(); j++) {
			if (maze[i][j] == 'S') {
				beg.first = i;
				beg.second = j;
				tmp++;
			}
			if (maze[i][j] == 'E') {
				end.first = i;
				end.second = j;
				tmp++;
			}
			if (tmp == 2) break;
		}
		if (tmp == 2) break;
	}
	queue<coor> q;
	q.push(beg);
	book[beg] = 1;
	int n = maze.size();
	int m = maze[0].size();
	while (!q.empty()) {
		coor nowCoor = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nowCoor.first + mx[i];
			int ny = nowCoor.second + my[i];
			coor nextCoor = make_pair(nx, ny);
			if (nextCoor == end) {
				book[nextCoor] = 1;
				per[nextCoor] = nowCoor;
				return true;
			}
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (book[nextCoor]) continue;
			q.push(nextCoor);
			per[nextCoor] = nowCoor;
		}
	}
	return false;
}

void showpath(Maze maze) {
	coor end = per.rbegin()->first;
	coor beg = per.begin()->first;
	coor tmp = per[end];
	maze[tmp.first][tmp.second] = '@';
	while (tmp != beg) {
		tmp = per[tmp];
		maze[tmp.first][tmp.second] = '@';
	}
	showMaze(maze);
}

int main() {
	Maze maze1 = {
		"S....#....",
		".#...#....",
		".#..#.....",
		"........#.",
		".......#.E",
	};
	Maze maze2 = {
		"S.#..#....",
		"..#..#....",
		"##..#.....",
		"........#.",
		".......#.E",
	};
	Maze customMaze;
	cout << "maze1 : " << endl;
	showMaze(maze1);
	cout << "----------" << endl;
	cout << "maze2 : " << endl;
	showMaze(maze2);
	cout << "----------" << endl;
	int ope;
	cout << "输入你想运行的迷宫(1/2/3<代表自定义>) : ";
	cin >> ope;
	if (ope == 1) customMaze = maze1;
	if (ope == 2) customMaze = maze2;
	if (ope == 3) {
		system("cls");
		makeMaze(customMaze);
	}
	syncShowMaze(customMaze);
	cout << "输入任何字符来展示最短路径 : " << endl;
	string in;
	cin >> in;
	system("cls");
	if (getpath(customMaze)) {
		cout << "成功找到路径, 路径用\'@\'表示" << endl;
		showpath(customMaze);
	}
	else {
		cout << "失败, 无法到达终点" << endl;
	}
	return 0;
}