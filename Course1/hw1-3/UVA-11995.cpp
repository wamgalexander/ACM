#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int n, cmd, num;

	while(scanf("%d", &n)!=EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		int isStack = 1, isQueue = 1, isPriorityQueue = 1;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d", &cmd, &num);
			if(cmd == 1){
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else{
				if(s.empty() || s.top() != num) isStack = 0;
				if(q.empty() || q.front() != num) isQueue = 0;
				if(pq.empty() || pq.top() != num) isPriorityQueue = 0;
				if(!s.empty()) s.pop();
				if(!q.empty()) q.pop();
				if(!pq.empty()) pq.pop();
			}
		}

		if(isStack + isQueue + isPriorityQueue > 1) printf("not sure\n");
		else if(isStack) printf("stack\n");
		else if(isQueue) printf("queue\n");
		else if(isPriorityQueue) printf("priority queue\n");
		else printf("impossible\n");
	}
	return 0;
}
