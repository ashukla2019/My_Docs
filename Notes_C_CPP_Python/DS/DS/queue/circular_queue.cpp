#include<iostream>
#define MAX 5
using namespace std;

class CircularQueue 
{
  private:
	int front;
	int rear;
	int arr[MAX];
	int itemCount;

  public:
	CircularQueue() 
	{
      itemCount = 0;
      front = -1;
      rear = -1;
      for (int i = 0; i < MAX; i++) 
	  {
        arr[i] = 0;
      }
    }
	void enqueue(int val)
	{
		if ((rear + 1) % MAX == front) 
		{
			cout << "Queue full" << endl;
			return;
		} 
		else if (front == -1 && rear == -1) 
		{
			rear = 0;
			front = 0;
			arr[rear] = val;

		} 
		else 
		{
			rear = (rear + 1) % MAX;
			arr[rear] = val;

		}
		itemCount++;

  }

  int dequeue() 
  {
    int x = 0;
    if (front == -1 && rear == -1) 
	{
      cout << "Queue is Empty" << endl;
      return x;
    } 
	else if (rear == front) 
	{
      x = arr[rear];
      rear = -1;
      front = -1;
      itemCount--;
      return x;
    } 
	else 
	{
      x = arr[front];
      arr[front] = 0;
      front = (front + 1) % 5;
      itemCount--;
      return x;
    }
  }

  int count() {
    return (itemCount);
  }

  void display() 
  {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) 
	{
      cout << arr[i] << "  ";
    }
  }

};

int main() {
  CircularQueue q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.display();
  q1.dequeue();
  q1.display();
  return 0;
}