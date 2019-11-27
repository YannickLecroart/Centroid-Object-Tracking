/*
Created by pratheek on 2019-11-27.
*/
#include "centroidtracker.h"

using namespace std;

CentroidTracker::CentroidTracker(int maxDisappeared) {
    this->nextObjectID = 0;

    // ordered dicts "objects" and "disappeared"
    this->objects;
    this->disappeared;
//    disappeared.insert(pair<int, int>(5, 4));

    this->maxDisappeared = maxDisappeared;
}


void CentroidTracker::register_Object(double centroid) {

}

void CentroidTracker::deregister_Object(int objectID) {
    cout << "REACHED DEREGISTER" << endl;

    this->objects.erase(objectID);
    this->disappeared.erase(objectID);
}

std::map<int, std::pair<int, int>> CentroidTracker::update(vector<vector<int>> boxes) {
    // checking
//    if (!boxes.empty()) {
//        cout << boxes[0].at(0) << " " << boxes.size() << endl;
//    }

    if (boxes.empty()) {
        cout << "NO BOXES BROOOO" << endl;

        for (auto i : disappeared) {
            this->disappeared[i.second] += 1;

            if (this->disappeared[i.second] > this->maxDisappeared) {
                this->deregister_Object(i.first);
            }
        }
        return this->objects;
    }

    // initialize an array of input centroids for the current frame
    vector<vector<int>> inputCentroids;
    for (auto i : boxes){
        inputCentroids.insert(inputCentroids.end(), {0,0});
//        cout << inputCentroids.front().size() << endl;
    }

    // loop over the bounding box rectangles


    return this->objects;
}
