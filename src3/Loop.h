#include <climits>
#include <vector>
#include "Object.h"

using namespace std;

class Loop {
public:
	void run();
	void addObject(Object * object); 
	void removeObject(const Object * object);
	int indexOf(const Object * object) const;

private:
	vector<Object *> objects;
};

