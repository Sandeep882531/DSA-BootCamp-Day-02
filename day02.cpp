#include <iostream>
#include <queue>
#include <set>

class Lift {
private:
    int currentFloor;
    std::queue<int> requests;
    std::set<int> requestedFloors;

public:
    Lift() : currentFloor(0) {}

    void requestFloor(int floor) {
        if (requestedFloors.find(floor) == requestedFloors.end()) {
            requests.push(floor);
            requestedFloors.insert(floor);
            std::cout << "Request added for floor " << floor << "." << std::endl;
        } else {
            std::cout << "Request for floor " << floor << " already exists." << std::endl;
        }
    }

    void moveToNextFloor() {
        if (!requests.empty()) {
            int nextFloor = requests.front();
            requests.pop();
            requestedFloors.erase(nextFloor);
            std::cout << "Moving from floor " << currentFloor << " to floor " << nextFloor << "." << std::endl;
            currentFloor = nextFloor;
            std::cout << "Arrived at floor " << currentFloor << "." << std::endl;
        } else {
            std::cout << "No pending requests." << std::endl;
        }
    }

    void showRequests() {
        if (!requests.empty()) {
            std::cout << "Current requests: ";
            std::queue<int> tempQueue = requests;
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            std::cout << std::endl;
        } else {
            std::cout << "No current requests." << std::endl;
        }
    }
};

int main() {
    Lift lift;

    lift.requestFloor(2);
    lift.requestFloor(5);
    lift.requestFloor(3);
    lift.showRequests();

    lift.moveToNextFloor();
    lift.moveToNextFloor();
    lift.moveToNextFloor();
    lift.moveToNextFloor();

    return 0;
}
