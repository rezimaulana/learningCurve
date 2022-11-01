#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop{
  int startTime;
  int duration;
  int endTime;
};

struct Available_Workshops{
    int n;
    vector<Workshop> vec; // using vector for easier manipulation
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* workshops = new Available_Workshops;
    workshops->n = n;
     
    for(int i = 0; i < n; i++) {
        Workshop temp;
        temp.startTime = start_time[i];
        temp.duration = duration[i];
        temp.endTime = start_time[i] + duration[i];
        
        workshops->vec.push_back(temp);
    }
    
    sort(workshops->vec.begin(), workshops->vec.end(), [](const Workshop& A, const Workshop& B) {
        // vec[0] is workshop with smallest endTime, ascending
        return A.endTime < B.endTime;
    });
    return workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int n = 1; // at worst-case scenario we will be able to visit atleast one workshop 
    int curr = 0; // workshop which we are currently visiting
    
    int count = ptr->n;
    for(int i = 1; i < count; i++) {
        // if the next workshop starts after the first one ends,
        // we update the count and set curr variable to the next workshop, otherwise
        // we skip the next workshop
        if(ptr->vec[i].startTime >= ptr->vec[curr].endTime) {
            ++n;
            curr = i;
        }
    }
    return n;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
