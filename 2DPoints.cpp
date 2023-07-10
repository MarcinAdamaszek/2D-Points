#include <iostream>

class Point {
public:
	int x;
	int y;
	int num;

	Point(int x, int y) : x(x), y(y) {}
	Point() {};
};



int main() {
	int corners = 1;

	while (corners) {
		std::cin >> corners;
		Point* points = new Point[corners];
		Point* lesserPoint = NULL;
		Point* greaterPoint = NULL;
		Point* currentPoint = NULL;
		Point temp = Point(10001, -10001);
		Point* startPoint = &temp;

		char* directions = new char[corners];
		int lesserCount, greaterCount;
		bool vertical = false;

		for (int i = 0; i < corners; i++) {
			int x, y;
			std::cin >> x;
			std::cin >> y;
			points[i] = Point(x, y);
		}
		
		for (int i = 0; i < corners; i++) {
			if (points[i].y >= startPoint->y) {
				if (points[i].x <= startPoint->x)
					startPoint = &points[i];
			}
		}

		currentPoint = startPoint;

		for (int j = 0; j < corners; j++) {
			lesserPoint = NULL;
			greaterPoint = NULL;
			lesserCount = 0;
			greaterCount = 0;

			if (vertical) {

				for (int i = 0; i < corners; i++) {
					if (points[i].x == currentPoint->x) {
						if ((points[i].y - currentPoint->y) < 0) {
							lesserCount++;
							if (lesserPoint == NULL || points[i].y > lesserPoint->y) {
								lesserPoint = &points[i];
							}
						}
						else if ((points[i].y - currentPoint->y) > 0) {
							greaterCount++;
							if (greaterPoint == NULL || points[i].y < greaterPoint->y) {
								greaterPoint = &points[i];
							}
						}
					}
				}

				if (lesserCount % 2 == 1) {
					directions[j] = 'S';
					currentPoint = lesserPoint;
					currentPoint->num = j;
				}
				else {
					directions[j] = 'N';
					currentPoint = greaterPoint;
					currentPoint->num = j;
				}
				vertical = false;

			}
			else {

				for (int i = 0; i < corners; i++) {
					if (points[i].y == currentPoint->y) {
						if ((points[i].x - currentPoint->x) < 0) {
							lesserCount++;
							if (lesserPoint == NULL || points[i].x > lesserPoint->x) {
								lesserPoint = &points[i];
							}
						}
						else if ((points[i].x - currentPoint->x) > 0) {
							greaterCount++;
							if (greaterPoint == NULL || points[i].x < greaterPoint->x) {
								greaterPoint = &points[i];
							}
						}
					}
				}

				if (lesserCount % 2 == 1) {
					directions[j] = 'W';
					currentPoint = lesserPoint;
					currentPoint->num = j;
				}
				else {
					directions[j] = 'E';
					currentPoint = greaterPoint;
					currentPoint->num = j;
				}
				vertical = true;

			}
		}

		int pos = points[0].num + 1;

		for (int i = 0; i < corners; i++) {
			if (pos == corners)
				pos = 0;

			std::cout << char(directions[pos++]);
		}

		std::cout << std::endl;

		delete[] points;
		delete[] directions;
	}
}


