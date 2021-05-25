#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

//합격의 조건-> 하나의 성적이라도 누군가보다 반드시 높아야하는 동시에 한 사람에게라도 서류와 면접 둘다 뒤지는 순위여서는 안됨
//서류나 면접 중 하나를 기준으로 오름차순으로 정렬 ->2등부터 다른 사람과 비교해줌

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int get_min(int a, int b) { return a < b ? a : b;}

int main() {

    int t, a, b, i, j, k, n;
    vector<pair<int, int> > v;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        v.clear();

        for (j = 0; j < n; j++) {
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end(), comp);
        int cnt = n;
        int bound = v[0].second; //합격할 수 있는 bound를 두고 이 변수를 계속 업데이트 시키면서 bound보다 낮다면 바로 탈락

        for (k = 1; k < n; k++) {
            if (v[k].second > bound) cnt--;
            bound = get_min(bound, v[k].second);
        }

        printf("%d\n", cnt);
    }

    return 0;
}
