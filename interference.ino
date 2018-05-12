#define NUM_OF_PROJECTS 4

struct Project {
  String name;
  int angle;
};  

Project projects[NUM_OF_PROJECTS] = {
  {"televator", 140},
  {"poetry", 90},
  {"non", 70},
  {"park", 80}
};

Project randomProject(){
  int i = random(0,NUM_OF_PROJECTS);
  return projects[i];
}
