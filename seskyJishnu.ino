
#define stop_pin 0      // brake or move
#define left_pin 1      // move left
#define right_pin 2     // move right
#define fs_pin A0       // forward sensor
#define ls_pin A1       // left sensor
#define rs_pin A2       // right sensor
#define rotation_pin A3 // rotation
#define arrow_pin 11    // arrow area
#define block_pin 12    // block area
#define up_pin 13       // move up in block area
#define main setup

namespace BinaryTree {
  int bias = -90;
  int travelled_id[2048] = {0};
  int count = 0;
  int check_travelled(int id, int low, int high) {
    // check with binary search

    if (high >= low) {
      int mid = low + (high - low) / 2;
      if (travelled_id[mid] == id) {
        return mid;
      }

      if (travelled_id[mid] > id) {
        return check_travelled(id, low, mid - 1);
      } else {
        return check_travelled(id, mid + 1, high);
      }
    } else {
      return -1;
    }
  }

  struct node {
    int item;
    int id;
    struct node *left_child;
    struct node *right_child;
    struct node *parent;
  };

  void traverse_nodes(struct node *root) {
    if (root == NULL)
      return;
    //Serial.println(root->id, root->item);
    traverse_nodes(root->left_child);
    traverse_nodes(root->right_child);
  }

  // Create a new Node
  struct node *createNode(int value, int id, struct node *parent = NULL) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    newNode->id = id;
    if (parent != NULL)
      ;
    newNode->parent = parent;
    travelled_id[count] = newNode->id;
    return newNode;
  }

  // Insert on the left of the node
  struct node *insertLeft(struct node *root, int value) {
    root->left_child = createNode(value, ++count);
    root->parent = root;
    return root->left_child;
  }

  // Insert on the right of the node
  struct node *insertRight(struct node *root, int value) {
    root->right_child = createNode(value, ++count);
    root->parent = root;
    return root->right_child;
  }
  int has_been_travelled(struct node *root, int to_move) {
    if (to_move == -90) {
      return check_travelled(2 + root->id, 0,
                             sizeof(travelled_id) / sizeof(travelled_id[0]) - 1);
    } else if (to_move == 90) {
      return check_travelled(++root->id, 0,
                             sizeof(travelled_id) / sizeof(travelled_id[0]) - 1);
    }
  }
  // todo
  void move(struct node *root, int id) {
    if (id == root->id) {
      // check children, if bias has been travelled go the other root
      int to_move = bias;
      int can_go = has_been_travelled(root, to_move);
      if (can_go != -1) {
        if (has_been_travelled(root, to_move * -1) != -1) {
          return move(root->parent, root->parent->id);
        } else { // do something
        }
      } else {
        // move towards bias
      }
    }
  }
} // namespace BinaryTree


struct BinaryTree::node *root;


  void turn_right(struct BinaryTree::node *root)
  {
    set_speed(80);
    while (analogRead(rotation_pin) >= 270 || analogRead(rotation_pin) == 0)
    {
      digitalWrite(stop_pin, HIGH);
      digitalWrite(right_pin, HIGH);
    }
    digitalWrite(right_pin, LOW);
    
    BinaryTree::insertRight(root,270);
    root = root->right_child;
  }
    
  void setup()
  {
    Serial.begin(115200);
    pinMode(stop_pin, OUTPUT);
    pinMode(left_pin, OUTPUT);
    pinMode(right_pin, OUTPUT);
    pinMode(fs_pin, INPUT);
    pinMode(rs_pin, INPUT);
    pinMode(ls_pin, INPUT);
    pinMode(arrow_pin, INPUT);
    pinMode(block_pin, INPUT);
    pinMode(rotation_pin, INPUT);
    pinMode(up_pin, OUTPUT);
    set_speed(255);  
  }

  void loop() {
    digitalWrite(stop_pin, HIGH);
    BinaryTree::traverse_nodes(root);
  }
  


  void set_speed(byte speed){
    root = BinaryTree::createNode(0,++BinaryTree::count,nullptr);
    int i = 3;
    while (speed > 0) {
      digitalWrite(i, speed % 2 == 1 ? HIGH : LOW);
      speed = speed / 2;
      i++;
    }
    for (;i < 11; i++) digitalWrite(i, LOW);
  }

