#include <utility>
#include <cmath>
#include <set>
#include "convex_hull.h"

std::set<point > quickhull(const std::set<point > &points) {
    if (points.size() <= 2) {
        return points;
    }

    std::set<point > sorted_points = std::set<point >(points);
    std::set<point > convex_hull;

    // we start by most left and right points (which are first and last in sorted set)
    point most_left = *sorted_points.begin();
    point most_right = *sorted_points.rbegin();

    quickhull_rec(sorted_points, convex_hull, most_left, most_right, true);
    quickhull_rec(sorted_points, convex_hull, most_left, most_right, false);
    return convex_hull;
}

std::set<point > quickhull_rec(const std::set<point > &points, std::set<point > &convex_hull, point p1, point p2, bool is_upper_side) {
    double max_distance = 0;
    point farthest_point;
    for (point p : points) {
        double distance = find_distance(p1, p2, p);
        if (distance > max_distance && find_side(p1, p2, p) == is_upper_side) {
            max_distance = distance;
            farthest_point = p;
        }
    }
    if (max_distance == 0) {
        convex_hull.insert(p1);
        convex_hull.insert(p2);
        return convex_hull;
    }
    quickhull_rec(points, convex_hull, farthest_point, p1, !find_side(farthest_point, p1, p2));
    quickhull_rec(points, convex_hull, farthest_point, p2, !find_side(farthest_point, p2, p1));
    return convex_hull;
}

double find_distance(point line_p1, point line_p2, point p) {
    return std::abs((p.second - line_p1.second) * (line_p2.first - line_p1.first) -
                    (line_p2.second - line_p1.second) * (p.first - line_p1.first));
}

bool find_side(point line_p1, point line_p2, point p) {
    double val = (p.second - line_p1.second) * (line_p2.first - line_p1.first) -
                 (line_p2.second - line_p1.second) * (p.first - line_p1.first);
    if (val > 0) {
        return true;
    }
    if (val < 0) {
        return false;
    }
    return true;
}
