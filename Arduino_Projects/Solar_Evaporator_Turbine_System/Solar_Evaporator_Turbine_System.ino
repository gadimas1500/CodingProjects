//temperature sensor
//presssure sensor
//valve control

typedef struct Node{
  int val;
  struct Node *next; 
} Node;
typedef struct LinkedList{
  Node *top;  
} LinkedList;



void setup() {
  //pinmode for the analog
  //pinmode for the pressure sensor
  //pinmode for the valve control
  //set up a serial port to display all info
  //pinmode for some lights to be set up
  Serial.begin(9600);
  
}

void loop() {
  //output to the screen (with some delay) the temperature reading
  //output to the screen (with some delay) the pressure reading
  //output to the screen (with some delay) the valve reading
  //add lights to do some readings too
  LinkedList *thelist;
  add_num(thelist, 4);
  printList(thelist);
  
  
}

void add_num(LinkedList *list, int num){
  Node *newnode = (Node *)calloc(1, sizeof(int));
  if(list == NULL){
    list->top = newnode;
    newnode->val = num;
    return;
  }
  newnode->val = num;
  newnode->next = list->top;
  list->top = newnode;
  return;
}

void printList(LinkedList *list){
  Node *ptr = list->top;
  while(ptr != NULL){
    Serial.println(ptr->val);
    ptr = ptr->next;
  }
  
}

  
