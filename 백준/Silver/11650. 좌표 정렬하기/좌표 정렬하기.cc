#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator<(const Point& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<Point> points(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end());
    
    for (const auto& p : points) {
        cout << p.x << " " << p.y << '\n';
    }
    
    return 0;
}