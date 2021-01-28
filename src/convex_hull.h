#ifndef CONVEX_HULL_CONVEX_HULL_H
#define CONVEX_HULL_CONVEX_HULL_H

#define point std::pair<double, double>

std::set<point> quickhull(const std::set<point> &points);

std::set<point> quickhull_rec(const std::set<point> &points, std::set<point> &convex_hull, point p1, point p2, bool is_upper_side);

double find_distance(point line_p1, point line_p2, point p);

bool find_side(point line_p1, point line_p2, point p);

#endif //CONVEX_HULL_CONVEX_HULL_H
