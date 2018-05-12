#define NUM_OF_PROJECTS 4

struct Project {
  String name;
  int angle;
};  

Project projects[NUM_OF_PROJECTS] = {
  {"televator", 180},
  {"poetry", 130},
  {"cardboard", 70},
  {"park", 30}
};

Project randomProject(){
  int i = random(0,NUM_OF_PROJECTS);
  return projects[i];
}
