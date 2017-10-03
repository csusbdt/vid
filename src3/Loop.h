#include <climits>
#include <vector>
#include "Object.h"

using namespace std;

class Loop {
public:
	const double durationInSeconds = 5.0;

	void run();
	void addObject(Object * object);
	void removeObject(Object * object);

private:
	vector<Object *> objects;
};

