# HW1_Problem_13
HW1__Problem_13
By Y.S.

In this problem the goal was to create 2 doubly linked circular lists of workers and jobs 
and then assign a worker from one list to a job from another list.
The biggest challenge in this problem was to create doubly linked list which was also circular. 
I used the list already created from problem 1 and added several features to it. Since the new List 
needed to by doubly linked I accomplished this with adding 2 links to the node class, forwardLink and 
backwardLink, to be able to traverse list backwards and forwards. In addition, I had to make the list
circular, and allow for Iterator to be able to traverse it backwards and forwards. this required for 
adjustments of a few methods such as insertFirst and deleteNode. 

 In a circular list it was important to have first and last node pointers working correctly as most list 
manipulations and traversals required the information on location of the node. 

 I’ve added an Iterator for this class inside the template, as it was easier to access all the necessary variables.
Inside Iterator I’ve added operator ++ and operator — for forwards and backwards iteration.
Inside the main program I’ve created a class Worker that has 2 public variables, name of the worker and name of the job.
 In the main class I’ve used 2 lists, 1 for worker class and 1 for jobs, and 3 iterators, 1 for worker and 2 for jobs list. 
 
 After the list class was created, I used for loop to assign a job to each Worker class, using job iterator to move through the jobs list.
After that I entered the loop which displayed the job to Worker assignment and asked the user if the assignments are ok. If the user 
answers N or n loop continues running, readjusting the assignments, moving 2 circular lists of jobs and workers against each other
on each iteration of loop. I accomplished this with Iterator, I’ve used 2 Iterators from jobs list, 1 to act as a starting point from which
first assignment takes place, and a second jobs Iterator would go through the list backwards to reassign the jobs. And 1 Workers iterator
would move forwards, always starting at the same spot.
