#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
list<int> solveMaze(list<int> maze[] ,int start, int finish){
  set<int> visited; // set for visited points
  list<int> path; // path list
  path.push_back(start); // path starting from start
int current =start; // current position is start
  visited.insert(current); // making current (start) point visited
  // loop until last element of path list is the Finish point
  while(path.back() !=finish && path.empty()==false){  
  	// iterator to go through neighbours of current point
  	list<int>::iterator iter =maze[current].begin();
  	// checking deadEnd
  	bool foundOutlet =false;
  	// loop until all neighbours are visited
  	while((iter!=maze[current].end()) && (!foundOutlet)){
  		// if current neighbour is not visited
  		if(visited.count(*iter) ==0)
  		{ foundOutlet=true; // new point found 
           

  		}
  		else{
  			iter++; // leave it and move forward
  		}}
  		// if new point is found
  		if(foundOutlet){
  			// add it to path
  			path.push_back(*iter);
  			// mark it visited
  			visited.insert(*iter);
  		}
  		else{
  			// else remove last point from path as it has deadEnd 
  			path.pop_back();
  		}
  		// change current point to last visited point 
  		current=path.back();
  	}
  	// return the path
 return path;}



int main()
{
   // implementing maze
  list<int> maze[9];
  maze[0].push_back(1);
  maze[0].push_back(3);

  maze[1].push_back(0);
  maze[1].push_back(2);

  maze[2].push_back(1);
  
  maze[3].push_back(0);
  maze[3].push_back(6);
  maze[3].push_back(4);
  
  maze[4].push_back(3);
  maze[4].push_back(5);
  maze[4].push_back(7);

  maze[5].push_back(4);

  maze[6].push_back(3);
 
  maze[7].push_back(4);
  maze[7].push_back(8);

  maze[8].push_back(7);

 list<int> my= solveMaze(maze,0,8);
 for(list<int>::iterator i=my.begin();i!=my.end();i++){
 	cout<<*i;
 }
}
/*     ---------------------------+
    >>>   0           1        2 |
                  --------------+
     | 3            4        5 |
    |     |             ------+
   | 6   |        7        8   >>>>>
  |_________________________      


  */