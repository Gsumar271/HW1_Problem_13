/*
By Yev Sumaryev
3/20/21
*/
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "DBLList.h"
#include "DBLList.cpp"
using namespace std;


//Worker class
class Worker
{ 
    public: 
        string name; 
        string job;

    //constructor and destructor 
    Worker(){}
    ~Worker(){}
    // //getters and setters
    // void setName(string name){ (*this).name = name; }
    // void setJob(string job) { this->job = job; }
};

int main()
{
    int x;

    DBLList<string> jobs;
    DBLList<Worker> workers;
    string jName;
    Worker xWorker[27];
    DBLList<string>:: DBLL_iterator it;
    DBLList<string>:: DBLL_iterator itJob;
    DBLList<Worker>:: DBLL_iterator itWorker;
    char answer;
    bool keepGoing = true;

    //create a circular double list of jobs
    for (int i = 25; i >= 1; i--)
	{
        jName = "job Name_" + to_string(i);
		jobs.insertFirst(jName);
	}



    //assign jobs to workers
    it = jobs.begin();
    for (int i = 1; i <= 25 ; i++)
	{
		xWorker[i].name = "Worker name_ " + to_string(i);
        xWorker[i].job = *it;
        ++it;
       // cout << xWorker[i].name << " " << xWorker[i].job << endl;
		workers.insertFirst(xWorker[i]);

	}

    // //print all the assignments
    // itWorker = workers.begin();
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << (*itWorker).name << " ";
    //     cout << (*itWorker).job << endl;
    //     ++itWorker;
    // }
    
    //ask user if the arrangement is ok
    //if not, shift jobs iterator backwards by 1
    //and reassign
    it = jobs.begin();
    --it;
    //enter a loop until user is happy with assignment
    while(keepGoing){
        //print all the assignments
        itWorker = workers.begin();
        for (int i = 1; i <= 25; i++)
        {
            cout << (*itWorker).name << " ";
            cout << (*itWorker).job << endl;
            ++itWorker;
        }

        //ask user if the arrangement is good this time
        cout<<"Is this a good arrangement? Y/N: "<<endl;
        cin>>answer;
        //if yes stop, otherwise
        //reassign jobs to workers 
        if(answer == 'Y' || answer == 'y'){
            keepGoing = false;
        }
        else{
            --it;
            itJob = it;
            //by using an Iterator from jobs list that is moving backwards 
            //with using -- decrement operator and using Iterator from workers list
            //which is moving forwards with ++ operator, the two circular lists
            //are moving against each other to assign jobs to workers
            itWorker = workers.begin();
            for (int i = 0; i <= 25; i++)
            {
                //assign job to a worker class
                (*itWorker).job = *itJob;

                //move worker iterator forwards
                ++itWorker;
                //mvoe jobs iterator backwards
                --itJob;
            }
            

            
        }
    }


}
