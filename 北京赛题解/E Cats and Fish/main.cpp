#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct cat {
	int time;//猫吃鱼的时间
	int xtime;//猫吃鱼的剩余时间

	bool operator <(const cat &a) {
		return time < a.time;
	}
};


int main() {
	int flashnum, catnum, time;
	while (cin >> flashnum >> catnum >> time) {
		vector<cat>all;
		cat p;
		for (int i(0); i < catnum; i++) {
			cin >> p.time;
			p.xtime = 0;
			all.push_back(p);
		}//输入猫

		sort(all.begin(), all.end());
		//将猫按照吃鱼速度排序

		for (int i(0); i < time; i++) {
			for (int j(0); j < catnum; j++) {
				if (all[j].xtime == 0&&flashnum!=0) {
					flashnum--;
					all[j].xtime = all[j].time;
				}
				
				if (all[j].xtime != 0)
					all[j].xtime--;
			}
		}
		//模拟吃鱼

		int sum(0);
		for (int i(0); i < catnum; i++) {
			if (all[i].xtime != 0)sum++;
		}
		//统计未吃完的鱼
		cout << flashnum << ' ' << sum << endl;
	}
}