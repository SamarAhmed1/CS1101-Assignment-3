template <class Type> // template class
class Queue {
private:
  Type *arr; // To create a dynnamic array of type Type
  int rear;
  int front;
  int numberOfItems;

public:
  Queue() {
    arr = new Type[50]; // initialze array
    rear = -1;
    front = 0;
    numberOfItems = 0;
  }
  void push(Type x) {
    if (rear == 50)
      rear = 0;
    else
      rear++;
    arr[rear] = x;

    numberOfItems++;
  }
  Type pop() {
    Type x = arr[front];
    if (front == 50)
      front = 0;
    else
      front++;

    numberOfItems--;

    return x;
  }
  bool isEmpty() {
    if (numberOfItems == 0)
      return true;
    else
      return false;
  }
  int length() { return numberOfItems; }
};