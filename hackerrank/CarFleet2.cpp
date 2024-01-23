#include <iostream>
#include <vector>

using namespace std;

int main() {
    int target;
    cin >> target;

    int sizePo;
    cin >> sizePo;
    vector<int> pos(sizePo);
    for (int i = 0; i < sizePo; ++i) {
        cin >> pos[i];
    }

    int sizeSp;
    cin >> sizeSp;
    vector<int> speed(sizeSp);
    for (int i = 0; i < sizeSp; ++i) {
        cin >> speed[i];
    }

    int fleet_num = 0;
    for (int i = 0; i < sizePo; ++i) {
        for (int j = i + 1; j < sizePo; ++j) {
            if ((pos[i] < pos[j] && speed[i] > speed[j]) || (pos[j] < pos[i] && speed[j] > speed[i])) {
                double Time_req = static_cast<double>(abs(pos[i] - pos[j])) / abs(speed[i] - speed[j]);
                if (Time_req * speed[i] <= target && Time_req * speed[j] <= target) {
                    fleet_num++;
                }
            }
        }
    }

    cout << fleet_num + 1 << endl;

    return 0;
}
