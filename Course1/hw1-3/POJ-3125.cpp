#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int t, n, m, tmp;
	scanf("%d", &t);

	for(int i = 0 ; i < t ; i++){
		int task_num = 0;
		priority_queue<int> p;
		vector<int> q, job_num;
		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &tmp);
			q.push_back(tmp);
			p.push(tmp);
			job_num.push_back(i);
		}

		while(q.size()> 0){
			if(q[0] == p.top()){
				task_num++;
				if(job_num[0] == m){
					printf("%d\n", task_num);
					break;
				}
				q.erase(q.begin());
				job_num.erase(job_num.begin());
				p.pop();
			}
			else{
				q.push_back(q[0]);
				q.erase(q.begin());
				job_num.push_back(job_num[0]);
				job_num.erase(job_num.begin());
			}
		}
	}

	return 0;
}
