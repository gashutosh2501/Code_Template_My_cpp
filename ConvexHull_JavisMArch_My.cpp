#include <bits/stdc++.h>
#define int long long
using namespace std;

class ConvexHull {
private:
    vector<pair<int, int>> points;

    // Orientation of triplet (p, q, r)
    // 0 -> colinear, 1 -> clockwise, 2 -> counterclockwise
    int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
        int val = (q.second - p.second) * (r.first - q.first) -
                  (q.first - p.first) * (r.second - q.second);
        if (val == 0) return 0;          // colinear
        return (val > 0) ? 1 : 2;        // clock or counterclock wise
    }

    // Returns squared distance (used for colinear tiebreaker)
    int distSq(pair<int, int> p1, pair<int, int> p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }

public:
    void addPoint(int x, int y) {
        points.emplace_back(x, y);
    }

    vector<pair<int, int>> getConvexHull() {
        int n = points.size();
        if (n < 3) return points;

        vector<pair<int, int>> hull;

        // Find the leftmost point
        int l = 0;
        for (int i = 1; i < n; i++) {
            if (points[i].first < points[l].first ||
                (points[i].first == points[l].first && points[i].second < points[l].second)) {
                l = i;
            }
        }

        int p = l, q;
        do {
            hull.push_back(points[p]);

            // Start with any point other than p
            q = (p + 1) % n;

            for (int i = 0; i < n; i++) {
                int o = orientation(points[p], points[i], points[q]);

                // If i is more counterclockwise, or colinear but farther
                if (o == 2 || (o == 0 && distSq(points[p], points[i]) > distSq(points[p], points[q]))) {
                    q = i;
                }
            }

            p = q;

        } while (p != l); // While we don't come to first point

        return hull;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ConvexHull hull;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hull.addPoint(x, y);
    }

    vector<pair<int, int>> convex = hull.getConvexHull();

    cout << "Convex Hull has " << convex.size() << " points:\n";
    for (auto p : convex) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
