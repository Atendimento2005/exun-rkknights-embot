# define stop_pin 0 //brake or move
# define left_pin 1 //move left
# define right_pin 2 //move right
# define fs_pin A0 //forward sensor
# define ls_pin A1 //left sensor
# define rs_pin A2 //right sensor
# define rotation_pin A3 //rotation
# define arrow_pin 11 //arrow area
# define block_pin 12 //block area
# define up_pin 13 //move up in block area



struct node
{
    int item;
    struct node *left_child;
    struct node *right_child;
};

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left_child);
    inorderTraversal(root->right_child);
}

// Preorder traversal
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    preorderTraversal(root->left_child);
    preorderTraversal(root->right_child);
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left_child);
    postorderTraversal(root->right_child);
}

// Create a new Node
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left_child = NULL;
    newNode->right_child = NULL;

    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root,int value)
{
    root->left_child = createNode(value);
    return root->left_child;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
    root->right_child = createNode(value);
    return root->right_child;
}

void setup() {
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
  for (int i = 3; i < 11; i++)
    pinMode(i, OUTPUT);
  set_speed(255);
  delay(1000);
  
  struct node *root = createNode(0);
  insertLeft(root->left_child, );
  insertRight(root->right_child, 90);
  int x = root->left_child->item;
  
  Serial.println(x);
}

void loop() {
    while (analogRead(fs_pin) >= 200)
    {
        digitalWrite(stop_pin, HIGH);
    }
    digitalWrite(stop_pin, LOW);
    set_speed(100);
    while (analogRead(rotation_pin)!=270)
    {
        digitalWrite(stop_pin, HIGH);
        digitalWrite(ls_pin, HIGH);
    }
    digitalWrite(ls_pin, LOW);
    set_speed(255);
}

void set_speed(byte speed){
  int i = 3;
  while (speed > 0) {
    digitalWrite(i, speed % 2 == 1 ? HIGH : LOW);
    speed = speed / 2;
    i++;
  }
  for (;i < 11; i++) digitalWrite(i, LOW);
}