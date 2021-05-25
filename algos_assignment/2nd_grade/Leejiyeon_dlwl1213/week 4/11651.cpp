#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return (a.first < b.first);
    return (a.second < b.second);
}

int main() {
    int N, i, j, k;  //점의 개수를 입력받는 변수 N
    vector< pair<int, int> > v;  //pair를 사용해 한 쌍의 두 정수를 한 요소를 기준삼아 정렬

    scanf("%d ", &N);

    for(i = 0; i < N; i++) {
        scanf("%d %d", &j, &k); 
        v.push_back(pair<int, int>(j, k));
    }
    sort(v.begin(), v.end(), sortbysec);  //두번째 요소로 정렬하고 두번째 요소가 같을 경우에는 첫번째로 정렬해주기 위해 sort()함수를 조금 고쳐줌

    for(i = 0; i < N; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}
