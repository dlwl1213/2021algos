#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <set>

using namespace std;

int N;
vector<int> input_list;

//temp와 다른 수들과 차이들의 합을 구해주는 함수 Calc
int Calc(int temp) {
	int ret = 0;

	for (int i = 0; i < input_list.size(); i++)
	{
		ret += abs(input_list[i] - temp);
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int input;
	set<int> number;
	set<int>::iterator it;
	int min_value = 987654321;
	int result;

	cin >> N; //자연수의 개수를 입력받음

	for (int i = 0; i < N; i++) {
		cin >> input;
		input_list.push_back(input);
		number.insert(input);  //set에 넣어 중복된 수는 넣지 않도록 하여 입력된 숫자를 저장해줌
	}

	//대표 자연수를 구해줌(for문으로 수들을 확인하며 진행)
	for (it = number.begin(); it != number.end(); it++) {
		int this_value = Calc(*it);

		if (min_value > this_value) //지금까지 구한 차이들의 합 보다 더 작은 차이들의 합을 구했을때 min_value값을 변경해줌
		{
			min_value = this_value;
			result = (*it);
		}
	}

	cout << result;

	return 0;
}
